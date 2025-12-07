import paho.mqtt.client as mqtt

BROKER = "localhost"
TEMP_TOPIC = "esatic/temp"
ALERT_TOPIC = "esatic/ia-alert-temp"

def on_connect(client, userdata, flags, rc):
    print("Connecté")
    client.subscribe(TEMP_TOPIC)

def on_message(client, userdata, msg):
    try:
        temp = float(msg.payload.decode())
        print("Température:", temp)

        if temp > 38:
            alert = "Température très élevée !"
        elif temp > 30:
            alert = "Température élevée"
        else:
            alert = "Température normale"

        client.publish(ALERT_TOPIC, alert)
        print("Alerte envoyée:", alert)

    except:
        print("Erreur de format")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(BROKER, 1883, 60)
client.loop_forever()
