#include <iostream>
#include <random>  // Necesario para mt19937
#include <fstream>
#include <chrono>
#include <cstdlib>  // Para usar la función std::atoi
#include <omp.h>

int main(int argc, char* argv[]) {
    int num_threads = 16;  // Número de hilos a utilizar

    // Establece el número de hilos
    omp_set_num_threads(num_threads);
    
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int numero = std::atoi(argv[1]);

    std::cout << "La cantidad de numeros aleatorios a crear es: " << numero << std::endl;


    int NDatos=numero;
    // Crear un objeto random_device para obtener una semilla aleatoria
    std::random_device rd;

    // Usar la semilla aleatoria para inicializar el generador MT19937
    std::mt19937_64 generador(rd());

  // Crear o abrir el archivo "datos.txt"
    std::ofstream archivo("datos.txt");

    std::ofstream archivoTiempo("tiempos.txt",std::ios::app);

    // Tiempo de inicio
    auto start = std::chrono::high_resolution_clock::now();

    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    // Parallel for: los hilos se repartirán el trabajo del bucle
    #pragma omp parallel for
    for (int i=0; i<NDatos; i++) {
   
        int numero_aleatorio = generador();
        archivo << i << " " << numero_aleatorio<< std::endl;
        

    }

     // Tiempo de fin
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout<<NDatos<<" Datos " << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";
    //Agregar los tiempos en el archivo

    archivoTiempo <<NDatos<<" " << elapsed.count() << std::endl;
    archivo <<NDatos<<" " << elapsed.count() << std::endl;

    // Cerrar el archivo
    archivo.close();
    archivoTiempo.close();

    std::cout << "Datos escritos en datos.txt" << std::endl;

    return 0;
}



