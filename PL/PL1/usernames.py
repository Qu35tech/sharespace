# -- Problema: Alien username
import re 

f = open("usernames.txt", "r")

print("««« Search »»»")

for linha in f:
  print(linha)
  y = re.search(r'^(\_|\.)(\d+[A-Za-z]{3,})(\.|\_|[A-Za-z])$', linha)
  if y:
    print("----------inic match------------------")
    print(y)
    print(y.string)
    print(y.span())
    print(y.groups())
    print(y.group())
    print("-----------fim match-------------------")

print("««« Search »»»")
