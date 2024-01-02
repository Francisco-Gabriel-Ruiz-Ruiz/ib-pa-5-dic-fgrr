/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief The program reads car data, later printing it whilst grouping the
  *        cars by type and indicating the highest price.
  * @bug There are no known bugs
  * @see Hoja 4 Classes ULL
  *      (Exercise C3)
  * @contact alu0101618586@ull.edu.es
  */

#include <iostream>
#include <vector>

#include "car_class-c3.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    PrintProgramPurpose();
    return 1;
  }
  const int number_of_user_cars{std::atoi(argv[1])};
  std::vector<Car> list_of_user_cars;
  ReadUserCarData(number_of_user_cars, list_of_user_cars);
  PrintCars(list_of_user_cars);
  return 0;
}

/**
 * @brief Prints the program purpose and how to execute its command
 **/
void PrintProgramPurpose() {
  std::cerr << "Introduzca el número de coches que desee detallar " <<
               "posteriormente en el programa:" << '\n' <<
               "./car_class <número_entero_de_coches>" << '\n' <<
               "Se le pedirá el nombre del coche, su tipo, modelo y precio " <<
               "más adelante en el programa." << '\n';
}