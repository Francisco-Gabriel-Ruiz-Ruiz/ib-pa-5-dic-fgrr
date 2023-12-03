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
#include <cstdlib>
#include <vector>
#include <algorithm> // std::find

#include "car_class-c3.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    PrintProgramPurpose();
    return 1;
  }
  int number_of_user_cars{std::atoi(argv[1])};
  std::vector<Car> list_of_user_cars;
  ReadUserCarData(number_of_user_cars, list_of_user_cars);
  PrintCars(list_of_user_cars);
  return 0;
}