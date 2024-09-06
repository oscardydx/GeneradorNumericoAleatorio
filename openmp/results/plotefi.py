import matplotlib.pyplot as plt
import numpy as np

# Cargar los datos de "metrics.txt" (suponiendo que tiene columnas de datos separadas por espacios)
data_mt = np.loadtxt('metrics_mt.txt')
data_mt64 = np.loadtxt('metrics_mt64.txt')
data_pcg = np.loadtxt('metrics_pcg.txt')

nThreads = data_mt[:, 0]
eficiencia_mt = data_mt[:, 2]
eficiencia_mt64 = data_mt64[:, 2]
eficiencia_pcg = data_pcg[:, 2]

# --- Segundo gráfico: Eficiencia ---
plt.plot(nThreads, eficiencia_mt, 'g^-', markersize=5, label='Eficiencia_mt')
plt.plot(nThreads, eficiencia_mt64, 'r^-', markersize=5, label='Eficiencia_mt64')  # Eficiencia con puntos verdes
plt.plot(nThreads, eficiencia_pcg, 'b^-', markersize=5, label='Eficiencia_pcg')

plt.xlabel('nThreads', fontsize=10)
plt.ylabel('Eficiencia Paralela', fontsize=10)
plt.title('RNG Maquina con 8-Cores/16-Threads', fontsize=10)
plt.legend(loc='upper right')
plt.grid(True)

# Guardar el gráfico en un archivo PDF
plt.savefig('eficiencia.pdf', format='pdf')

plt.show()
