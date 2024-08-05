# config.py

# MQTT Configuration
MQTT_BROKER = "192.168.76.172"
MQTT_PORT = 2000
MQTT_TOPIC = "cdac/test/telemetry"
MQTT_CLIENT_ID_PUBLISHER = "mqtt_publisher"
MQTT_CLIENT_ID_SUBSCRIBER = "mqtt_subscriber"

# MQTT Broker Credentials
MQTT_USERNAME = "desd"
MQTT_PASSWORD = "desd123"

# Excel Configuration (only needed for the subscriber)
EXCEL_FILE = "mqtt_data.xlsx"
