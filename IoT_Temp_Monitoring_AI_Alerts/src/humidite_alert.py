import paho.mqtt.client as mqtt

BROKER = "localhost"
HUMIDITE_TOPIC = "esatic/humidite"
ALERT_TOPIC = "esatic/ia-alert-humidite"

def on_connect(client, userdata, flags, rc):
    print("Connecté")
    client.subscribe(HUMIDITE_TOPIC)

def on_message(client, userdata, msg):
    try:
        humidite = float(msg.payload.decode())
        print("Humidité:", humidite)

        if humidite > 90:
            alert = "Humidité très élevée !"
        elif humidite > 50:
            alert = "Humidité élevée"
        else:
            alert = "Humidité normale"

        client.publish(ALERT_TOPIC, alert)
        print("Alerte envoyée:", alert)

    except:
        print("Erreur de format")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(BROKER, 1883, 60)
client.loop_forever()
