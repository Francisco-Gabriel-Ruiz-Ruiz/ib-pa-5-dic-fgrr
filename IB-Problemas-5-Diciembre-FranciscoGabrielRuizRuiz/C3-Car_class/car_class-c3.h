/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief This is the header file for the programs car_class-c3
  * @bug There are no known bugs
  * @see Hoja 4 Classes ULL
  *      (Exercise C3)
  * @contact alu0101618586@ull.edu.es
  */

#include <iostream>
#include <vector>

#ifndef CAR_CLASS_C3_H
#define CAR_CLASS_C3_H

class Car {
 public:
  Car(std::string brand_of_car, std::string model_of_car,
      std::string type_of_car, double price_of_car);
  std::string GetBrandOfCar() const {
    return brand_of_car_;
  }
  std::string GetModelOfCar() const {
    return model_of_car_;
  }
  std::string GetTypeOfCar() const {
    return type_of_car_;
  }
  double GetPriceOfCar() const {
    return price_of_car_;
  }
  friend std::ostream& operator<<(std::ostream &out, const Car &point);
 private:
  const std::string brand_of_car_;
  const std::string model_of_car_;
  const std::string type_of_car_;
  const double price_of_car_;
};

void PrintProgramPurpose();
void ReadUserCarData(int number_of_user_cars, std::vector<Car>& list_of_user_cars);
void PrintCars(std::vector<Car>& list_of_user_cars);

#endif