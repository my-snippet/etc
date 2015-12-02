import requests
import os


def send_simple_message():
    return requests.post(
        os.environ.get("MAILGUN_SENDBOX_DOMAIN"),
        # it's secret api key, never upload, (or conceal this into env)
        auth=("api", os.environ.get("MAIL_SECRET_KEY")),
        data={"from": os.environ.get("FROM_EMAIL"),
              "to": [os.environ.get("FROM_EMAIL")],
              "subject": "Hello",
              "text": "Testing some Mailgun awesomness!"})
