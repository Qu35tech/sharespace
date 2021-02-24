# -- Problema: Matrículas de outro mundo
import re

f = open("spaceplates.txt", "r")

for linha in f:
    y = re.search(r'^(\d{2}(\.\.\.|\:|\-))(\d{2}\2)(\d{2}\2)(\d{2})$',linha)
    if y:
        print("Válido")
    else :
        print("Inválido")