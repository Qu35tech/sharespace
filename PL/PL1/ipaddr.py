# -- Problema: Endereços IP
import re

f = open("ipaddr.txt", "r")

for linha in f:
    #Filtro IPv4 deixa passar endereços com um '.' no fim. Pode ser melhorado
    y = re.search(r'^(([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.?){4}$',linha)
    z = re.search(r'^[0-9a-f]{4}\:[0-9a-f]{4}\:[0-9a-f]{4}\:[0-9a-f]{4}\:[0-9a-f]{4}\:[0-9a-f]{4}\:[0-9a-f]{4}\:[0-9a-f]{4}$',linha)
    if y:
        print("IPv4")
    elif z: 
        print("IPv6")
    else:
        print("Erro")