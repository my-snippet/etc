# using SendGrid's Python Library - https://github.com/sendgrid/sendgrid-python
import sendgrid
import os


SENDGRID_API_KEY = os.environ["SENDGRID_API_KEY"]
FROM_EMAIL = os.environ["FROM_EMAIL"]
DEFAULT_TO = os.environ["DEFAULT_TO"]
SUBJECT = os.environ["SUBJECT"]


def send_email(body, to=DEFAULT_TO):
    sg = sendgrid.SendGridClient(SENDGRID_API_KEY)

    message = sendgrid.Mail()
    message.add_to(to)
    message.set_subject(SUBJECT)
    message.set_html(body)
    message.set_from(FROM_EMAIL)
    return sg.send(message)
