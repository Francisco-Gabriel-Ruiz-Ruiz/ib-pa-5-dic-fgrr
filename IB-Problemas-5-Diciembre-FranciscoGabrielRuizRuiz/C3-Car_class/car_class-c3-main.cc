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
**/

#include "car_class-c3.h"

std::string kMsgHelp = "ESTO ES UN MENSAJE QUE EXPLICA LO QUE HACE EL PROGRAMA, coge del usuario el coche blablabla";
std::string kMsgProg = "ESTO ES UN MENSAJE QUE SUSTITUYE PRINTPROGRAMPURPOSE, hay que poner lo de ./program arg1 blablabla";

/**
 * @brief blablabla
**/
void Usage(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      std::cerr << "Faltan argumentos\n" << kMsgProg << "\n";
      exit (EXIT_FAILURE);
      break;
    case 2: {
      std::string param = argv[1];
      if (param == "--help" || param == "-h") {
        std::cout << kMsgHelp << std::endl;
        exit(EXIT_SUCCESS);
      }
      break;
    }
    default:
      std::cerr << "Sobran argumentos \n" << kMsgProg << "\n";
      exit (EXIT_FAILURE);
      break;
  }
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  int number_of_user_cars{std::atoi(argv[1])};
  std::vector<Car> list_of_user_cars;
  ReadUserCarData(number_of_user_cars, list_of_user_cars);
  PrintCars(list_of_user_cars);
  return 0;
}
