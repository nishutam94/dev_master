#!/bin/bash

set -e

# Variables for versions
PROM_VERSION="2.46.0"
NODE_EXPORTER_VERSION="1.7.0"

echo "Updating system..."
sudo yum update -y

echo "Installing dependencies..."
sudo yum install -y curl wget tar

# 1. Setup Prometheus
echo "Installing Prometheus..."

sudo useradd --no-create-home --shell /bin/false prometheus || true

cd /tmp
curl -LO https://github.com/prometheus/prometheus/releases/download/v${PROM_VERSION}/prometheus-${PROM_VERSION}.linux-amd64.tar.gz

tar xvf prometheus-${PROM_VERSION}.linux-amd64.tar.gz
sudo mv prometheus-${PROM_VERSION}.linux-amd64 /usr/local/prometheus

sudo chown -R prometheus:prometheus /usr/local/prometheus

# Create Prometheus service file
sudo tee /etc/systemd/system/prometheus.service > /dev/null <<EOF
[Unit]
Description=Prometheus
Wants=network-online.target
After=network-online.target

[Service]
User=prometheus
Group=prometheus
Type=simple
ExecStart=/usr/local/prometheus/prometheus \\
  --config.file=/usr/local/prometheus/prometheus.yml \\
  --storage.tsdb.path=/usr/local/prometheus/data

[Install]
WantedBy=multi-user.target
EOF

# Setup Prometheus config with Node Exporter scrape config
sudo tee /usr/local/prometheus/prometheus.yml > /dev/null <<EOF
global:
  scrape_interval: 15s

scrape_configs:
  - job_name: 'prometheus'
    static_configs:
      - targets: ['localhost:9090']

  - job_name: 'node_exporter'
    static_configs:
      - targets: ['localhost:9100']
EOF

sudo mkdir -p /usr/local/prometheus/data
sudo chown -R prometheus:prometheus /usr/local/prometheus/data

# 2. Setup Node Exporter
echo "Installing Node Exporter..."

sudo useradd -rs /bin/false node_exporter || true

curl -LO https://github.com/prometheus/node_exporter/releases/download/v${NODE_EXPORTER_VERSION}/node_exporter-${NODE_EXPORTER_VERSION}.linux-amd64.tar.gz
tar xvf node_exporter-${NODE_EXPORTER_VERSION}.linux-amd64.tar.gz
sudo mv node_exporter-${NODE_EXPORTER_VERSION}.linux-amd64/node_exporter /usr/local/bin/
sudo chown node_exporter:node_exporter /usr/local/bin/node_exporter

# Create Node Exporter service
sudo tee /etc/systemd/system/node_exporter.service > /dev/null <<EOF
[Unit]
Description=Node Exporter
After=network.target

[Service]
User=node_exporter
Group=node_exporter
Type=simple
ExecStart=/usr/local/bin/node_exporter

[Install]
WantedBy=multi-user.target
EOF

# 3. Install Grafana
echo "Installing Grafana..."

sudo tee /etc/yum.repos.d/grafana.repo > /dev/null <<EOF
[grafana]
name=grafana
baseurl=https://packages.grafana.com/oss/rpm
repo_gpgcheck=1
enabled=1
gpgcheck=1
gpgkey=https://packages.grafana.com/gpg.key
EOF

sudo yum install -y grafana

# Enable and start all services
echo "Enabling and starting services..."

sudo systemctl daemon-reload
sudo systemctl enable prometheus
sudo systemctl start prometheus

sudo systemctl enable node_exporter
sudo systemctl start node_exporter

sudo systemctl enable grafana-server
sudo systemctl start grafana-server

echo "Setup complete!"
echo "Access Grafana at http://<your-server-ip>:3000 (default login: admin/admin)"
echo "Prometheus running at http://localhost:9090"
echo "Node Exporter running on port 9100"
