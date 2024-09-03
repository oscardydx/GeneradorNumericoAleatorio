#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include "pcg_random.hpp"
#include <fstream>
#include <chrono>
#include <cstdlib>  // Para usar la función std::atoi

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int numero = std::atoi(argv[1]);

    std::cout << "La cantidad de numeros aleatorios a crear es: " << numero << std::endl;


    int NDatos=numero;

    // Crear o abrir el archivo "datos.txt"
    std::ofstream archivo("datos.txt");



    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

        // Tiempo de inicio
    auto start = std::chrono::high_resolution_clock::now();




    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg32 rng(seed_source);


    for (int i=0; i<NDatos; i++) {
   
        int numero_aleatorio = rng();
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



