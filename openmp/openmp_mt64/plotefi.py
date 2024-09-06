import matplotlib.pyplot as plt
import numpy as np

# Cargar los datos de "metrics.txt" (suponiendo que tiene columnas de datos separadas por espacios)
data = np.loadtxt('metrics.txt')

nThreads = data[:, 0]
eficiencia = data[:, 2]

# --- Segundo gráfico: Eficiencia ---
plt.plot(nThreads, np.ones_like(nThreads), color='red', label='1')  # Línea roja en 1
plt.plot(nThreads, np.full_like(nThreads, 0.972447), color='blue', label='0.972447')  # Línea azul en 0.6
plt.plot(nThreads, eficiencia, 'g^-', markersize=5, label='Eficiencia')  # Eficiencia con puntos verdes
plt.xlabel('nThreads', fontsize=10)
plt.ylabel('Eficiencia Paralela', fontsize=10)
plt.title('RNG MT64 Maquina con 8-Cores/16-Threads', fontsize=10)
plt.legend(loc='upper right')
plt.grid(True)

# Guardar el gráfico en un archivo PDF
plt.savefig('eficiencia.pdf', format='pdf')

plt.show()
