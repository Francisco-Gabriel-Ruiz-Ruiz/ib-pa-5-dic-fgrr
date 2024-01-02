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
#include <algorithm>

#ifndef CAR_CLASS_C3_H
#define CAR_CLASS_C3_H

class Car {
 public:
  Car(const std::string& brand_of_car, const std::string& model_of_car, const std::string& type_of_car, const double& price_of_car) {
    brand_of_car_ = brand_of_car;
    model_of_car_ = model_of_car;
    type_of_car_ = type_of_car;
    price_of_car_ = price_of_car;
  }

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
  std::string brand_of_car_ = "";
  std::string model_of_car_ = "";
  std::string type_of_car_ = "";
  double price_of_car_ = 0;
};

void PrintProgramPurpose();
void ReadUserCarData(const int&, std::vector<Car>&);
void PrintCars(const std::vector<Car>&);

#endif
