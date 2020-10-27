import smtplib
 
def gmail(from_email, to_email, cc_mail_list,
              subject, message,
              login, password,
              smtpserver='smtp.gmail.com:587'):
    header  = 'From: %s
' % from_addr
    header += 'To: %s
' % ','.join(to_email)
    header += 'Cc: %s
' % ','.join(cc_mail_list)
    header += 'Subject: %s

' % subject
    message = header + message
 
    server = smtplib.SMTP(smtpserver)
    server.starttls()
    server.login(login,password)
    problems = server.sendmail(from_email, to_email, message)
    server.quit()
