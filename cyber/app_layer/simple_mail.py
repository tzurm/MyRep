#!/usr/bin/env python3
import smtplib

def main():
    
	with open('password.txt', 'r') as f:
		file_contents = f.read()
	from_mail = 'sender@gmail.com'
	server = smtplib.SMTP('smtp.office365.com', 587)
	server.starttls()
	server.login(from_mail, file_contents)

	to_email = 'user2@gmail.com' 
	subject = 'You Won 1,000,000$ FREE!!'
	body = 'CLICK HERE!!'
	msg = f'Subject: {subject}\n\n{body}'
	server.sendmail(from_mail, to_email, msg)
	server.quit()
 
if __name__ == "__main__":
    main() 
       
