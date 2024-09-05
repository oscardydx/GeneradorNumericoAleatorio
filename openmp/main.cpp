#include <iostream>
#include <omp.h>

int main() {
    int num_threads = 1;  // Número de hilos a utilizar

    // Establece el número de hilos
    omp_set_num_threads(num_threads);

    // Parallel for: los hilos se repartirán el trabajo del bucle
    #pragma omp parallel for
    for (int i = 0; i < 38; i++) {
        int thread_id = omp_get_thread_num();
        std::cout << "Iteración " << i << " realizada por el hilo " << thread_id << std::endl;
    }

    return 0;
}