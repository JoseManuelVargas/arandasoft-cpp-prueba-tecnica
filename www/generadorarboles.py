import random


class Nodo:
    def __init__(self, valor): 
        self.valor =  valor 
        self.izquierda = None
        self.derecha = None

    def insertar(self, valor):
        q = []
        q.append(self)
        while (len(q)):
            temp = q[0]
            q.pop(0)

            if not temp.izquierda:
                temp.izquierda = Nodo(valor)
                break
            else:
                q.append(temp.izquierda)

            if not temp.derecha:
                temp.derecha = Nodo(valor)
                break
            else:
                q.append(temp.derecha)
  
    def encontrar_camino(self, camino, valor):
        camino.append(self.valor)
        
        if self.valor == valor: 
            return True
        if (self.izquierda is not None and self.izquierda.encontrar_camino(camino, valor)) or (self.derecha is not None and self.derecha.encontrar_camino(camino, valor)): 
            return True 
        camino.pop() 
        return False

    def calcular_ancestro(self, n1, n2):
        camino1 = [] 
        camino2 = [] 
        if not self.encontrar_camino(camino1, n1) or not self.encontrar_camino(camino2, n2): 
            return -1 
        i = 0 
        while i < len(camino1) and i < len(camino2): 
            if camino1[i] != camino2[i]: 
                break
            i += 1
        return camino1[i-1]


if __name__ == "__main__":
    texto = ""
    for i in range(500):
        longitud = random.randint(3, 60)
        valores = set()
        for i in range(longitud):
            valores.add(random.randint(1, 1000))
        valores = list(valores)
        arbol = Nodo(valores[0])
        for valor in valores[1:]:
            arbol.insertar(valor)
        texto += "a\n"
        texto += ",".join(str(x) for x in valores) + "\n"
        ancestros = random.randint(5, 10)
        for i in range(ancestros):
            nodo1 = random.choice(valores)
            nodo2 = random.choice(valores)
            ancestro = arbol.calcular_ancestro(nodo1, nodo2)
            texto += f"{nodo1},{nodo2},{ancestro}\n"
    with open("conjuntoarboles.dat", "w") as archivo:
        archivo.write(texto)


