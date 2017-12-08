import smtplib
fromaddr = 'djkah11@gmail.com'
toaddrs  = 'akapust1n@mail.ru'
msg = 'Why,Oh why!'
username = 'djkah11'
password = 'password_networks'
keywords = ["one", "two", "three"]

server = smtplib.SMTP("smtp.gmail.com", 587)
server.ehlo()
server.starttls()
server.login(username, password)
server.ehlo()

text = {}
F1 = open("file1","r")
text[0] = F1.read()
F2 = open("file2","r")
text[1] = F2.read()
F3 = open("file3","r")
text[2] = F3.read()

counters = [0,0,0]

for i in range(0,3):
    for index in range(len(keywords)):
        counters[i] += text[i].count(keywords[index])


for index in range(len(text)):
    if counters[index]:
        print(index)
        server.sendmail(fromaddr, toaddrs, text[index])


server.quit()