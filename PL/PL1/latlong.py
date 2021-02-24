# -- Problema: Latitude e Longitude
import re

f = open("latlong.txt", "r")

for linha in f:
    #A RegEx em vigor funciona de acordo com os exemplos, mas é bastante extensa. Ainda em investigação.
    #Aquela que está em comentário, é uma versão mais curta, mas que deixa passar 90s e 180s com casas decimais
    #diferentes de 0. 
    #y = re.search(r'^\([+\-]?(\d|[1-8][0-9]|90)(\.\d{1,})?\,( )[+\-]?(\d|[1-9]\d|1[0-7]\d|180)(\.\d{1,})?\)$',linha)
    y = re.search(r'^\([+\-]?(\d(\.\d{1,})?|[1-8][0-9](\.\d{1,})?|90(\.0{1,})?)(\.\d{1,})?\,( )[+\-]?(\d(\.\d{1,})?|[1-9]\d(\.\d{1,})?|1[0-7]\d(\.\d{1,})?|180(\.0{1,})?)\)$',linha)
    if y:
        print("Válido")
    else :
        print("Inválido")