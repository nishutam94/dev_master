from flask import Flask, request
import subprocess
from prometheus_flask_exporter import PrometheusMetrics  # 🔥 Add this

app = Flask(__name__)
metrics = PrometheusMetrics(app)  # 🔥 Initialize metrics collection

@app.route("/")
def health_check():
    return "Stress-ng microservice is running", 200

@app.route("/start", methods=["GET"])
def run_stress():
    cpu = request.args.get("cpu", "2")
    timeout = request.args.get("timeout", "10")
    try:
        result = subprocess.run(
            ["stress-ng", "--cpu", cpu, "--timeout", f"{timeout}s"],
            capture_output=True,
            text=True,
            check=True
        )
        return f"<pre>{result.stdout}</pre>", 200
    except subprocess.CalledProcessError as e:
        return f"<pre>Error:\n{e.stderr}</pre>", 500
    except Exception as e:
        return f"Unexpected error: {str(e)}", 500

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
