/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief The program reads from a file a graph, checks if it is a valid one
  *        and prints it.
  * @bug There are no known bugs
  * @see Hoja 4 Classes ULL
  *      (Exercise C6)
  * @contact alu0101618586@ull.edu.es
  */

#include <iostream>
#include <fstream>

#include "graph_class-c6-fichero.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    PrintFileHelp();
    return 1;
  }
  std::string user_input_file_name{argv[1]};
  std::ifstream user_input_file{user_input_file_name};
  if (!CanOpenFile(user_input_file_name, user_input_file)) {
    return 2;
  }
  std::string output_file_name{argv[2]};
  std::ofstream output_file{output_file_name};

  int graph_vertexes;
  int graph_edges;
  ReadUserInitialGraphData(graph_vertexes, graph_edges, user_input_file);
  if (!ValidInitialGraphData(graph_vertexes, graph_edges)) {
    PrintProgramPurpose();
    return 3;
  }
  Graph user_graph{graph_vertexes, graph_edges};
  ReadUserPairOfVertexes(user_graph, user_input_file);
  if (!ValidPairs(user_graph)) {
    return 4;
  }
  user_graph.PrintPairOfVertexes(output_file);
  std::cout << "Su grafo es válido y se ha copiado con éxito en el fichero " <<
               output_file_name << '\n';
  user_input_file.close();
  output_file.close();
  return 0;
}

/**
 * @brief Prints the program purpose
 **/
void PrintProgramPurpose() {
  std::cout << "Introduzca un fichero con los datos de un grafo en el "
               "programa, y este le indicará si es válido o no. " << '\n' <<
               "Para introducir los pares de vértices, hágalo separando " <<
               "los números con un espacio. Cuando el programa lea -1, " <<
               "este concluirá la lectura de los pares de vértices." << '\n'
               << '\n';
  PrintFileHelp();
}

/**
 * @brief Prints how to execute its command
 **/
void PrintFileHelp() {
  std::cout << "Método de uso del programa con ficheros:" << '\n' <<
               "./graph_class-c6-fichero <fichero_de_entrada> " <<
               "<fichero_de_salida>" << '\n' << "El programa reescribirá el " <<
               "fichero de salida si este ya existe." << '\n' << "No se " <<
               "olvide de incluir las extensiones de su archivo." << '\n' <<
               "Se propone el uso de los archivos incluidos con el programa." <<
               '\n' << "Para más información, consulte el README.md" << '\n';
}