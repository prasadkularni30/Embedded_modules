import paho.mqtt.client as mqtt
import json
import random
import time
import config
import logging

# Set up logging
logging.basicConfig(level=logging.INFO)

# MQTT Callbacks
def on_connect(client, userdata, flags, reason_code,properties):
    if reason_code == 0:
        logging.info("Connected to MQTT Broker successfully")
    else:
        logging.error(f"Failed to connect, return code {reason_code}")

def on_publish(client, userdata, mid, reason_code, properties):
    logging.info(f"Message {mid} published.")

# Initialize MQTT Client
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2,client_id=config.MQTT_CLIENT_ID_PUBLISHER)
client.username_pw_set(config.MQTT_USERNAME, config.MQTT_PASSWORD)
client.on_connect = on_connect
client.on_publish = on_publish

# Connect to MQTT Broker
try:
    logging.info(f"Connecting to MQTT Broker at {config.MQTT_BROKER}:{config.MQTT_PORT}")
    client.connect(config.MQTT_BROKER, config.MQTT_PORT, 60)
except Exception as e:
    logging.error(f"Failed to connect to MQTT Broker: {e}")
    exit(1)

# Start the MQTT loop in a separate thread
client.loop_start()

try:
    while True:
        try:
            # Generate random sensor data
            temperature = round(random.uniform(-10, 50), 2)
            humidity = round(random.uniform(0, 100), 2)

            # Create a payload in JSON format
            payload = {
                "temperature": temperature,
                "humidity": humidity
            }

            # Publish the payload to the MQTT topic
            result = client.publish(config.MQTT_TOPIC, json.dumps(payload))
            status = result.rc
            if status == 0:
                logging.info(f"Published: {payload}")
            else:
                logging.error(f"Failed to send message to topic {config.MQTT_TOPIC}")

            # Wait for 5 seconds before publishing the next message
            time.sleep(5)
        except Exception as e:
            logging.error(f"Error in publishing loop: {e}")
            time.sleep(5)
except KeyboardInterrupt:
    logging.info("Publishing stopped.")
finally:
    client.loop_stop()
    client.disconnect()
    logging.info("Disconnected from MQTT Broker.")