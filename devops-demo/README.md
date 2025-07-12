# 🔧 DevOps Monitoring Demo with `stress-ng`, Prometheus & Grafana (Minikube)

This project demonstrates a simple Flask-based `stress-ng` microservice running on Kubernetes with monitoring and visualization using **Prometheus** and **Grafana**, all within **Minikube**.

---

## 🧱 Prerequisites

- [Docker](https://www.docker.com/)
- [Helm](https://helm.sh/)

### 🔨 Install Minikube & kubectl (Linux)

```bash
# Install kubectl
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
sudo install -o root -g root -m 0755 kubectl /usr/local/bin/kubectl

# Install Minikube
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube
```

> For Windows/macOS, refer to: [https://minikube.sigs.k8s.io/docs/start/](https://minikube.sigs.k8s.io/docs/start/)

---

## 📦 Step-by-Step Setup

### 🚀 1. Start Minikube & Enable Docker Env

```bash
minikube start --driver=docker
eval $(minikube docker-env)
```

---

### 🐳 2. Build & Deploy `stress-ng-service`

```bash
docker build -t stress-ng-service ./microservices/stress-ng-service
kubectl apply -f k8s-manifests/stress-ng-deploy.yaml
kubectl rollout restart deployment stress-ng-deployment
```

Check pods and service:

```bash
kubectl get pods
kubectl get svc
```

---

### 🧪 3. Test the `stress-ng` Service

```bash
minikube service stress-ng-service
curl http://<minikube-ip>:<nodePort>/
curl "http://<minikube-ip>:<nodePort>/start?cpu=2&timeout=10"
```

Logs:

```bash
kubectl logs deployment/stress-ng-deployment
```

---

## 📊 4. Setup Monitoring: Prometheus

### Create Namespace & Apply Config

```bash
kubectl create namespace monitoring
kubectl apply -f monitoring/prometheus.yaml
```

Check:

```bash
kubectl get pods -n monitoring
kubectl get svc -n monitoring
minikube service -n monitoring prometheus
```

---

### ✅ 5. Confirm Prometheus is Scraping `/metrics`

```bash
kubectl port-forward svc/stress-ng-service 5000:5000
curl http://localhost:5000/metrics
```

You should see Prometheus-format metrics such as:

```
# HELP flask_http_request_total Total HTTP requests
# TYPE flask_http_request_total counter
flask_http_request_total{method="GET",status="200",endpoint="/start"} 3.0
```

Logs should show:

```
"GET /metrics HTTP/1.1" 200 -
```

---

### 🔁 (Optional) Reload Prometheus Config

```bash
kubectl delete configmap prometheus-config -n monitoring
kubectl apply -f monitoring/prometheus.yaml
kubectl rollout restart deployment prometheus -n monitoring
```

---

## 📈 6. Setup Grafana via Helm

### Install Helm (if not already)

```bash
curl https://raw.githubusercontent.com/helm/helm/master/scripts/get-helm-3 | bash
helm version
```

### Install Grafana

```bash
helm repo add grafana https://grafana.github.io/helm-charts
helm repo update

helm install grafana grafana/grafana \
  --namespace monitoring \
  --create-namespace \
  --set adminPassword='admin' \
  --set service.type=NodePort
```

Access Grafana:

```bash
minikube service -n monitoring grafana
```

Login:

- **Username:** `admin`
- **Password:** `admin`

---

### 🔌 7. Connect Prometheus in Grafana

1. Go to ⚙️ **Settings > Data Sources**
2. Click **Add data source**
3. Choose **Prometheus**
4. Set the URL to:
   ```
   http://prometheus.monitoring.svc.cluster.local:9090
   ```
5. Click **Save & Test**

---

### 📥 8. Import `stress-ng` Dashboard

1. In Grafana UI: Click **+ > Import**
2. Upload or paste dashboard JSON (see below)
3. Select Prometheus as data source
4. Click **Import**

👉 Use [this dashboard JSON](#custom-dashboard-json)

---

## 📄 Custom Dashboard JSON

Save the following as `stress-ng-dashboard.json` and import it:

```json
{
  "title": "Stress-NG Flask Metrics",
  "timezone": "browser",
  "schemaVersion": 37,
  "version": 1,
  "refresh": "10s",
  "panels": [
    {
      "type": "stat",
      "title": "Total Requests",
      "gridPos": { "x": 0, "y": 0, "w": 6, "h": 3 },
      "targets": [{ "expr": "sum(flask_http_request_total)", "refId": "A" }]
    },
    {
      "type": "stat",
      "title": "Stress-ng Runs",
      "gridPos": { "x": 6, "y": 0, "w": 6, "h": 3 },
      "targets": [{ "expr": "stress_ng_runs_total", "refId": "A" }]
    },
    {
      "type": "graph",
      "title": "Requests by Endpoint",
      "gridPos": { "x": 0, "y": 3, "w": 12, "h": 6 },
      "targets": [
        {
          "expr": "sum by (endpoint) (rate(flask_http_request_total[1m]))",
          "legendFormat": "{{endpoint}}",
          "refId": "A"
        }
      ]
    },
    {
      "type": "graph",
      "title": "HTTP Request Duration",
      "gridPos": { "x": 0, "y": 9, "w": 12, "h": 6 },
      "targets": [
        {
          "expr": "histogram_quantile(0.95, sum(rate(flask_http_request_duration_seconds_bucket[1m])) by (le, endpoint))",
          "legendFormat": "{{endpoint}} (p95)",
          "refId": "A"
        }
      ]
    },
    {
      "type": "graph",
      "title": "HTTP Error Rate",
      "gridPos": { "x": 0, "y": 15, "w": 12, "h": 6 },
      "targets": [
        {
          "expr": "sum(rate(flask_http_request_total{status=~\"5..\"}[1m]))",
          "legendFormat": "5xx errors",
          "refId": "A"
        }
      ]
    }
  ]
}
```

---

## ✅ You're Done!

You now have:

- A Flask microservice running `stress-ng`
- Prometheus scraping performance metrics
- Grafana visualizing it with dashboards

---

## 📌 Useful Commands Recap

```bash
kubectl get pods
kubectl get svc
kubectl logs deploy/stress-ng-deployment
kubectl rollout restart deployment stress-ng-deployment
kubectl port-forward svc/stress-ng-service 5000:5000
curl http://localhost:5000/metrics
```

---

## 🔜 Next Steps (Optional)

- Add `sysbench` or `fio` services
- Create alerting rules
- Export logs via Loki
- Automate setup with Helmfile or Skaffold

---

## 📧 Questions?

Feel free to open an issue or ping me for improvements.

