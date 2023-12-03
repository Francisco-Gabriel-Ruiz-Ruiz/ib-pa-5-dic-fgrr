/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief The program
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

Car::Car(std::string brand_of_car, std::string model_of_car,
    std::string type_of_car, double price_of_car) : brand_of_car_{brand_of_car},
    model_of_car_{model_of_car}, type_of_car_{type_of_car},
    price_of_car_{price_of_car} { }

void PrintProgramPurpose() {
  std::cerr << "Introduzca el número de coches que desee detallar " <<
               "posteriormente en el programa:" << '\n' <<
               "./car_class <número_entero_de_coches>" << '\n' <<
               "Se le pedirá el nombre del coche, su tipo, modelo y precio " <<
               "más adelante en el programa." << '\n';
}

void ReadUserCarTypes(int number_of_user_cars, std::vector<Car>& list_of_user_cars) {
  std::string brand_of_car;
  std::string model_of_car;
  std::string type_of_car;
  double price_of_car;
  for (int counter{0}; counter < number_of_user_cars; ++counter) {
    std::cout << "Introduzca los detalles de su coche número " << counter + 1 <<
                 ":" << '\n';
    std::cout << "Marca del coche: ";
    std::cin >> brand_of_car;
    std::cout << "Modelo del coche: ";
    std::cin >> model_of_car;
    std::cout << "Tipo de coche: ";
    std::cin >> type_of_car;
    std::cout << "Precio del coche: ";
    std::cin >> price_of_car;
    Car user_car{brand_of_car, model_of_car, type_of_car, price_of_car};
    list_of_user_cars.emplace_back(user_car);
  }
}

std::ostream& operator<<(std::ostream& out, const Car& user_car) {
  out << user_car.brand_of_car_ << ", " << user_car.model_of_car_ << ", " <<
         user_car.type_of_car_ << ", " << user_car.price_of_car_;
  return out;
}

void PrintCars(std::vector<Car>& list_of_user_cars) {
  std::cout << "==============" << '\n';
  std::vector<std::string> unique_car_types;
  for (Car current_car : list_of_user_cars) {
    auto evaluated_car_type = std::find(unique_car_types.begin(), unique_car_types.end(), current_car.GetTypeOfCar());
    // No match found; it has to be a new type
    if (evaluated_car_type == unique_car_types.end()) {
      unique_car_types.emplace_back(current_car.GetTypeOfCar());
    }
  }
  int type_counter{0};
  for (std::string current_type : unique_car_types) {
    std::cout << "Cars of type '" << current_type << "':" << '\n';
    double max_price{0.0};
    bool found_type = false;
    for (Car current_car : list_of_user_cars) {
      if (current_car.GetTypeOfCar() == current_type) {
        std::cout << current_car << '\n';
        max_price = std::max(max_price, current_car.GetPriceOfCar());
        found_type = true;
      }
    }
    if (found_type) {
      std::cout << "The most expensive car costs " << max_price << '\n';
    }
    ++type_counter;
    if (type_counter < unique_car_types.size()) {
      std::cout << '\n';
    }
  }
}