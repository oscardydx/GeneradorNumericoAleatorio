#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <omp.h> // Incluye OpenMP

void generate_random_numbers(const int NDatos, double &wtime, double &ctime);
void stats(const int size, const int reps,
           double &mean_wtime, double &sigma_wtime,
           double &mean_ctime, double &sigma_ctime);

int main(int argc, char **argv) {
    const int M = std::atoi(argv[1]); // Número de datos aleatorios a generar
    const int R = std::atoi(argv[2]); // Repeticiones

    double mean_wtime, sigma_wtime;
    double mean_ctime, sigma_ctime;
    stats(M, R, mean_wtime, sigma_wtime, mean_ctime, sigma_ctime);
    std::cout << M
              << "\t" << mean_wtime << "\t" << sigma_wtime
              << "\t" << mean_ctime << "\t" << sigma_ctime
              << std::endl;

    return 0;
}

void stats(const int size, const int reps,
           double &mean_wtime, double &sigma_wtime,
           double &mean_ctime, double &sigma_ctime) {
    double wsum = 0, wsum2 = 0, csum = 0, csum2 = 0;
    double wtime = 0, ctime = 0;
    for (int rep = 0; rep < reps; ++rep) {
        srand(rep + 1); // Cambiar semilla en cada repetición
        generate_random_numbers(size, wtime, ctime);
        wsum  += wtime;
        wsum2 += wtime * wtime;
        csum  += ctime;
        csum2 += ctime * ctime;
    }
    mean_wtime = wsum / reps;
    sigma_wtime = std::sqrt(reps * (wsum2 / reps - mean_wtime * mean_wtime) / (reps - 1));
    mean_ctime = csum / reps;
    sigma_ctime = std::sqrt(reps * (csum2 / reps - mean_ctime * mean_ctime) / (reps - 1));
}

void generate_random_numbers(const int NDatos, double &wtime, double &ctime) {
    // Crear el generador de números aleatorios
    std::random_device rd;

    // Medir tiempos
    auto start = std::chrono::system_clock::now(); // Tiempo de pared
    std::clock_t c1 = std::clock(); // Tiempo de CPU

    // Paralelizar el bucle usando OpenMP
    #pragma omp parallel
    {
        std::mt19937_64 generador(rd()); // Generador por cada hilo

        #pragma omp for
        for (int i = 0; i < NDatos; ++i) {
            int numero_aleatorio = generador();
            // Simular uso del número generado
            (void)numero_aleatorio;
        }
    }

    auto end = std::chrono::system_clock::now(); // Tiempo de pared
    std::clock_t c2 = std::clock(); // Tiempo de CPU

    // Calcular tiempos
    ctime = 1.0 * (c2 - c1) / CLOCKS_PER_SEC;
    std::chrono::duration<double> elapsed_seconds = end - start;
    wtime = elapsed_seconds.count();
}

