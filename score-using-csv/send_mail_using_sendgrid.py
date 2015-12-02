# using SendGrid's Python Library - https://github.com/sendgrid/sendgrid-python
import sendgrid
import os


SENDGRID_API_KEY = os.environ["SENDGRID_API_KEY"]
FROM_EMAIL = os.environ["FROM_EMAIL"]
DEFAULT_TO = os.environ["DEFAULT_TO"]

sg = sendgrid.SendGridClient(SENDGRID_API_KEY)

message = sendgrid.Mail()
message.add_to([DEFAULT_TO])
message.set_subject('Example')
message.set_html('Body')
message.set_text('Body')
message.set_from(FROM_EMAIL)
status, msg = sg.send(message)
