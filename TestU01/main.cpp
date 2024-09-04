#include <iostream>
#include <random>
#include <cstdlib>
#include "pcg_random.hpp"

extern "C" {
    #include "unif01.h"
    #include "bbattery.h"
}

double generarAleatorioMt64() {
    static std::random_device rd;
    static std::mt19937_64 generador(rd());
    //static std::uniform_real_distribution<double> distribucion(0.0, 1.0);
    return generador();
}

double generarAleatorioPCG() {
       // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg32 rng(seed_source);

    return rng();
}


int main() {
    // Crear un generador para TestU01
    // Se convierte la cadena constante a char* de forma explícita
    char* nombre = const_cast<char*>("MT19937_64");
    unif01_Gen* gen = unif01_CreateExternGen01(nombre, generarAleatorioMt64);

    // Ejecutar pruebas con TestU01
    std::cout << "Ejecutando prueba SmallCrush para Mt64..." << std::endl;
    bbattery_SmallCrush(gen);



    //std::cout << "Ejecutando prueba Crush..." << std::endl;
    //bbattery_Crush(gen);

    //std::cout << "Ejecutando prueba BigCrush..." << std::endl;
    //bbattery_BigCrush(gen);

    // Limpiar recursos
    unif01_DeleteGen(gen);

    // Crear un generador para TestU01
    // Se convierte la cadena constante a char* de forma explícita
    char* nombre2 = const_cast<char*>("PCG");
    unif01_Gen* gen2 = unif01_CreateExternGen01(nombre2, generarAleatorioPCG);
    std::cout << "Ejecutando prueba SmallCrush para PCG..." << std::endl;
    bbattery_SmallCrush(gen2);

    return 0;
}