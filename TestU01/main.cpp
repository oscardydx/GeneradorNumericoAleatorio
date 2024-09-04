#include <iostream>
#include <random>
#include <cstdlib>

extern "C" {
    #include "unif01.h"
    #include "bbattery.h"
}

// Función generadora que devuelve números aleatorios normalizados a [0, 1]
double generarAleatorio() {
    static std::random_device rd;
    static std::mt19937_64 generador(rd());
    static std::uniform_real_distribution<double> distribucion(0.0, 1.0);
    return generador();
}

int main() {
    // Crear un generador para TestU01
    // Se convierte la cadena constante a char* de forma explícita
    char* nombre = const_cast<char*>("MT19937_64");
    unif01_Gen* gen = unif01_CreateExternGen01(nombre, generarAleatorio);

    // Ejecutar pruebas con TestU01
    std::cout << "Ejecutando prueba SmallCrush..." << std::endl;
    bbattery_SmallCrush(gen);

    std::cout << "Ejecutando prueba Crush..." << std::endl;
    bbattery_Crush(gen);

    std::cout << "Ejecutando prueba BigCrush..." << std::endl;
    bbattery_BigCrush(gen);

    // Limpiar recursos
    unif01_DeleteGen(gen);

    return 0;
}