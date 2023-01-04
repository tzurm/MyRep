#!/usr/bin/env python3

import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText # add hyprelink
from email import encoders

def main():
    
    with open('password.txt', 'r') as f:
        file_contents = f.read()
    
    # Open the file to be attached
    with open('ISO_639-1.txt', 'rb') as f:
        # Create the email message
        from_mail = 'sender@gmail.com'
        to_email = 'user2@gmail.com' 
        msg = MIMEMultipart()
        msg['Subject'] = 'You Won 2,000,000$ FREE!!'
        msg['From'] = from_mail
        msg['To'] = to_email
        body = '<a href="http://i.ytimg.com/vi/0vxCFIGCqnI/maxresdefault.jpg">to confrim click here.</a>' 
        msg.attach(MIMEText(body, 'html'))
        attachment = MIMEBase('application', 'octet-stream')
        attachment.set_payload((f).read())
        encoders.encode_base64(attachment)
        attachment.add_header('Content-Disposition', "attachment; filename=ISO_639-1.txt")
        msg.attach(attachment)

    # Connect to the server and send the email
    server = smtplib.SMTP('smtp.office365.com', 587)
    server.starttls()
    server.login(from_mail, file_contents)
    server.sendmail(from_mail, to_email, msg.as_string())
    server.quit()
    
if __name__ == "__main__":
    main() 




