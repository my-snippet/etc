import requests
import os


def send_simple_message():
    return requests.post(
        os.environ["MAILGUN_SENDBOX_DOMAIN"],
        # it's secret api key, never upload, (or conceal this into env)
        auth=("api", os.environ["MAIL_SECRET_KEY"]),
        data={"from": os.environ["FROM_EMAIL"],
              "to": [os.environ["FROM_EMAIL"]],
              "subject": "Hello",
              "text": "Testing some Mailgun awesomness!"})
