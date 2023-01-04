#!/usr/bin/env python3
import smtplib

def main():
	with open('password.txt', 'r') as f:
		file_contents = f.read()

	server = smtplib.SMTP('smtp.office365.com', 587)
	server.starttls()
	server.login('SENDER@gmail.com', file_contents)

	from_mail = 'SENDER@gmail.com'
	to_email = 'DUMMY@gmail.com' #fill mail adress to send
	subject = 'You Won 1,000,000$ FREE!!'
	body = 'CLICK HERE!!'
	msg = f'Subject: {subject}\n\n{body}'
	server.sendmail('SENDER@gmail.com', to_email, msg)


	server.quit()
if __name__ == "__main__":
    main() 
       
