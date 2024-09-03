import numpy as np
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt2


# Leer los datos de la segunda columna
columna = np.loadtxt('tiempos.txt', usecols=0)
columna2 = np.loadtxt('tiempos.txt', usecols=1)

# Opción 2: Gráfica de línea
plt2.plot(columna2, columna, color='blue', linestyle='-', marker='o')


plt2.title('Tiempo ejecución  versus Número de datos mt64 ' )
plt2.xlabel('Tiempo')
plt2.ylabel('Numero de Datos')

# Guardar la imagen en formato PNG
plt2.savefig('tiempoEjecucion.png')



