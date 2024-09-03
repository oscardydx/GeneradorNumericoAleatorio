#include <iostream>
#include <random>  // Necesario para mt19937
#include <fstream>
#include <chrono>
#include <cstdlib>  // Para usar la función std::atoi

int main(int argc, char* argv[]) {

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
    std::mt19937 generador(rd());

  // Crear o abrir el archivo "datos.txt"
    std::ofstream archivo("datos.txt");

    // Tiempo de inicio
    auto start = std::chrono::high_resolution_clock::now();

    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    for (int i=0; i<NDatos; i++) {
   
        int numero_aleatorio = generador();
        archivo << i << " " << numero_aleatorio<< std::endl;

    }

    

     // Tiempo de fin
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout <<NDatos<<" Datos " << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";
    archivo <<NDatos<<" " << elapsed.count() << std::endl;

    // Cerrar el archivo
    archivo.close();

    std::cout << "Datos escritos en datos.txt" << std::endl;

    return 0;
}



