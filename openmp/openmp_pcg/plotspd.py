import matplotlib.pyplot as plt
import numpy as np

# Cargar los datos de "metrics.txt" (suponiendo que tiene columnas de datos separadas por espacios)
data = np.loadtxt('metrics.txt')

nThreads = data[:, 0]
speedup = data[:, 1]

# --- Primer gráfico: Speedup ---
plt.plot(nThreads, nThreads, label='Teorico')  # Línea x
plt.plot(nThreads, speedup, 'g^-', markersize=5, label='Speedup')  # Línea de Speedup con puntos verdes
plt.xlabel('nThreads', fontsize=10)
plt.ylabel('Parallel SpeedUp', fontsize=10)
plt.title('RNG PCG  Maquina con 8-Cores/16-Threads', fontsize=10)
plt.legend(loc='upper left')
plt.grid(True)

# Guardar el gráfico en un archivo PDF
plt.savefig('speedup.pdf', format='pdf')


plt.show()
