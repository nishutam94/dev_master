FROM python:3.9-slim

# Set proxy environment variables for build-time
ENV http_proxy=http://proxy.ch.intel.com:911
ENV https_proxy=http://proxy.ch.intel.com:912
ENV no_proxy=.intel.com,10.0.0.0/8,192.168.0.0/16,localhost,127.0.0.0/8

# Install stress-ng and Python dependencies
RUN apt-get update && \
    apt-get install -y stress-ng && \
    pip install flask prometheus_flask_exporter

WORKDIR /app
COPY app.py .

CMD ["python", "app.py"]
