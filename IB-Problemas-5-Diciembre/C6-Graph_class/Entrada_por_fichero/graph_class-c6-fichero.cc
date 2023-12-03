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
  *      (Exercise C6)
  * @contact alu0101618586@ull.edu.es
  */

#include <iostream>
#include <vector>
#include <unordered_set> // To keep track of unique numbers in a vertex
#include <fstream>

#include "graph_class-c6-fichero.h"

Graph::Graph(int vertex_number, int edge_number) : vertex_number_{vertex_number}, edge_number_{edge_number} { }

void Graph::InsertPairOfVertexes(int starting_value, int ending_value) {
  starting_graph_values_.emplace_back(starting_value);
  ending_graph_values_.emplace_back(ending_value);
}

void Graph::PrintPairOfVertexes(std::ofstream& output_file) const {
  output_file << vertex_number_ << " " << edge_number_ << '\n';
  for (std::size_t counter{0}; counter < starting_graph_values_.size(); ++counter) {
    
    output_file << starting_graph_values_[counter] << " " <<
                   ending_graph_values_[counter];
    if (counter + 1 != starting_graph_values_.size()) {
      output_file << '\n';
    }
  }
}

void ReadUserInitialGraphData(int& graph_vertexes, int& graph_edges,
                              std::ifstream& user_input_file) {
  user_input_file >> graph_vertexes;
  user_input_file >> graph_edges;
}

bool ValidInitialGraphData(int graph_vertexes, int graph_edges) {
  if (graph_vertexes < 1) {
    std::cerr << "No hay un número de vértices válido" << '\n';
  } else if (graph_edges < 1) {
    std::cerr << "No hay un número de aristas válido" << '\n';
  } else if (graph_vertexes - 1 != graph_edges) {
    std::cerr << "Su grafo no puede contener un mismo o mayor número de " <<
                 "aristas que de vértices." << '\n';
  }
  return (graph_vertexes > 1 && graph_edges > 1 && graph_vertexes > graph_edges);
}

// In this function the first two values should not be read
void ReadUserPairOfVertexes(Graph& user_graph, std::ifstream& user_input_file) {
  int starting_value;
  while (user_input_file >> starting_value) {
    if (starting_value == -1) {
      break;
    }
    int ending_value;
    user_input_file >> ending_value;
    user_graph.InsertPairOfVertexes(starting_value, ending_value);
  }
}

std::unordered_set<int> ObtainUniqueValuesFromPairs(const Graph& user_graph) {
  std::vector<int> starting_graph_values{user_graph.GetStartingGraphValues()};
  std::vector<int> ending_graph_values{user_graph.GetEndingGraphValues()};
  std::unordered_set<int> unique_values;
  for (int extracted_vertex : starting_graph_values) {
    unique_values.insert(extracted_vertex);
  }
  for (int extracted_vertex : ending_graph_values) {
    unique_values.insert(extracted_vertex);
  }
  return unique_values;
}

int ObtainAmountOfPairs(const Graph& user_graph) {
  std::vector<int> amount_of_pairs{user_graph.GetEndingGraphValues()};
  return static_cast<int>(amount_of_pairs.size());
}

bool ValuesOfPairsInRange(std::unordered_set<int> unique_pair_values,
                          const Graph& user_graph,
                          std::vector<int>& infraction_numbers) {
  int maximum_possible_value{user_graph.GetEdgeNumber()};
  bool is_clean{true};
  for (int extracted_value : unique_pair_values) {
    if (extracted_value > maximum_possible_value) {
      infraction_numbers.emplace_back(extracted_value);
      is_clean = false;
    }
  }
  return is_clean;
}

void PrintInfractionNumbers(const std::vector<int>& infraction_numbers) {
  for (std::size_t counter{0}; counter < infraction_numbers.size(); ++counter) {
    std::cerr << infraction_numbers[counter];
    if (counter + 1 != infraction_numbers.size()) {
      std::cerr << ", ";
    }
  }
  std::cerr << '\n';
}

bool ValidPairs(const Graph& user_graph) {
  std::unordered_set<int> unique_pair_values{ObtainUniqueValuesFromPairs(user_graph)};
  int number_of_different_vertexes{static_cast<int>(unique_pair_values.size())};
  int amount_of_pairs{ObtainAmountOfPairs(user_graph)};
  if ((number_of_different_vertexes != user_graph.GetVertexNumber()) || 
      (amount_of_pairs != user_graph.GetEdgeNumber())) {
    std::cerr << "Existen unos pares de vértices no válidos." << '\n';
  }
  std::vector<int> infraction_numbers;
  if (!ValuesOfPairsInRange(unique_pair_values, user_graph, infraction_numbers)) {
    std::cerr << "Existe al menos un número en un par que no " <<
                 "es válido (por ser mayor que el número de aristas): ";
    PrintInfractionNumbers(infraction_numbers);
  }
  return (number_of_different_vertexes == user_graph.GetVertexNumber()) &&
         (amount_of_pairs == user_graph.GetEdgeNumber()) &&
         ValuesOfPairsInRange(unique_pair_values, user_graph, infraction_numbers);
}

void PrintProgramPurpose() {
  std::cout << "Introduzca un fichero con los datos de un grafo en el "
               "programa, y este le indicará si es válido o no. " << '\n' <<
               "Para introducir los pares de vértices, hágalo separando " <<
               "los números con un espacio. Cuando el programa lea -1, " <<
               "este concluirá la lectura de los pares de vértices." << '\n'
               << '\n';
  PrintFileHelp();
}

void PrintFileHelp() {
  std::cout << "Método de uso del programa con ficheros:" << '\n' <<
               "./graph_class-c6-fichero <fichero_de_entrada> " <<
               "<fichero_de_salida>" << '\n' << "El programa reescribirá el " <<
               "fichero de salida si este ya existe." << '\n' << "No se " <<
               "olvide de incluir las extensiones de su archivo." << '\n' <<
               "Se propone el uso de los archivos incluidos con el programa." <<
               '\n' << "Para más información, consulte el README.md" << '\n';
}

bool CanOpenFile(const std::string& user_file_name, std::ifstream& user_file) {
  bool can_open_file{true};
  if (!user_file) {
    std::cerr << "El archivo " << user_file_name << " no se pudo abrir." <<
                 '\n';
    can_open_file = false;
  }
  return can_open_file;
}