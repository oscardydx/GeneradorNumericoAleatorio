import matplotlib.pyplot as plt
import numpy as np

# Cargar los datos de "metrics.txt" (suponiendo que tiene columnas de datos separadas por espacios)

data_mt = np.loadtxt('metrics_mt.txt')
data_mt64 = np.loadtxt('metrics_mt64.txt')
data_pcg = np.loadtxt('metrics_pcg.txt')

nThreads = data_mt[:, 0]
speedup_mt = data_mt[:, 1]
speedup_mt64 = data_mt64[:, 1]
speedup_pcg = data_pcg[:, 1]


# --- Primer gráfico: Speedup ---
plt.plot(nThreads, nThreads, markersize=5, label='Teorico')  # Línea x
plt.plot(nThreads, speedup_mt, 'b^-', markersize=5, label='speedup_mt')
plt.plot(nThreads, speedup_mt64, 'r^-', markersize=5, label='speedup_mt64')  # Eficiencia con puntos verdes
plt.plot(nThreads, speedup_pcg, 'b^-', markersize=5, label='speedup_pcg')


plt.xlabel('nThreads', fontsize=10)
plt.ylabel('Parallel SpeedUp', fontsize=10)
plt.title('RNG  Maquina con 8-Cores/16-Threads', fontsize=10)
plt.legend(loc='upper left')
plt.grid(True)

# Guardar el gráfico en un archivo PDF
plt.savefig('speedup.pdf', format='pdf')


plt.show()
