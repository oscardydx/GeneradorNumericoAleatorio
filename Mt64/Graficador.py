import numpy as np
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt2
# Leer los datos de la segunda columna
columna_2 = np.loadtxt('datos.txt', usecols=1)


tiempo=columna_2[-1]
columna_2 = columna_2[:-1]
NDatos=columna_2.size
# Crear el histograma

plt.hist(columna_2, bins=100, edgecolor='black')
plt.title('Histograma mt64 con '+str(NDatos)+' de datos t='+ str(tiempo) )
plt.xlabel('Valores')
plt.ylabel('Frecuencia')

# Guardar la imagen en formato PNG
plt.savefig('histograma'+str(NDatos)+'.png')



