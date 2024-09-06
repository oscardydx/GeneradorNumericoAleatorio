Aquí tienes un posible contenido para el archivo **README** del repositorio **GeneradorNumericoAleatorio**:

---

# Generador Numérico Aleatorio

Este proyecto es un generador de números aleatorios implementado en C++, utilizando la biblioteca PCG (Permuted Congruential Generator). El objetivo del proyecto es generar secuencias de números aleatorios con distribución uniforme, probando diferentes configuraciones de los generadores de números y evaluando su rendimiento mediante la biblioteca **TestU01**.

## Características

- Implementación de generación de números aleatorios utilizando el algoritmo **PCG**.
- Pruebas y análisis de los generadores con **TestU01** para evaluar su calidad y aleatoriedad.
- Código optimizado para ejecutar en entornos de desarrollo en C++.

## Requisitos

- **C++17** o superior.
- Biblioteca **PCG**.
- Biblioteca **TestU01** para pruebas estadísticas de los generadores.
  
## Instalación y Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/oscardydx/GeneradorNumericoAleatorio.git
   ```
   
2. Dirígete al directorio del proyecto:
   ```bash
   cd GeneradorNumericoAleatorio
   ```

3. Instala las dependencias necesarias (PCG y TestU01).
  
```bash
   sudo apt update
  sudo apt install -y gcc make libgmp-dev libgmp10
  wget http://simul.iro.umontreal.ca/testu01/TestU01.zip
  unzip TestU01.zip
  cd TestU01-1.2.3 # Cambia al directorio descomprimido
  ./configure
  make
  sudo make install
   ```
5. Compila los test de la carpeta TestU01:
   ```bash
   $ g++ -o exe main.cpp -ltestu01 -lmylib -lprobdist -lgsl -lgslcblas -lm
   LD_LIBRARY_PATH=./TestU01-1.2.3/testu01/.libs ./exe
   ```
6.para compilar los generadores en las carpetar mt, mt64 y pcg
```bash
   g++ -O3  -o exe main.cpp
  ./exe NumeroDeDatosAGenerar
```


## Pruebas

El proyecto incluye pruebas estadísticas con la biblioteca **TestU01**. Puedes ejecutarlas para analizar la aleatoriedad de las secuencias generadas por el generador de números aleatorios.

##Video 
https://drive.google.com/drive/folders/1SPdCxVRmuuzyBgMH02QspwVP533FEaOF

## Contribuciones

Las contribuciones son bienvenidas. Si deseas contribuir, sigue estos pasos:

1. Haz un fork del proyecto.
2. Crea una rama para tu funcionalidad (`git checkout -b nueva-funcionalidad`).
3. Haz commit de tus cambios (`git commit -m 'Agrega nueva funcionalidad'`).
4. Haz push a la rama (`git push origin nueva-funcionalidad`).
5. Crea un pull request.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo [LICENSE](LICENSE) para más detalles.

---

Este archivo README proporciona una descripción básica del proyecto, sus características, cómo instalarlo, ejecutarlo y contribuir al mismo. Puedes ajustarlo según sea necesario.
