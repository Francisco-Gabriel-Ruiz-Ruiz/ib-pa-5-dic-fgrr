/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief The main program reads from a file a graph, checks if it is a valid
  *        one and prints it.
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

/**
 * @brief The constructor for the Graph class
 * @param vertex_number The total vertexes of the user graph
 * @param edge_number The total edges of the user graph
 **/
Graph::Graph(int vertex_number, int edge_number) : vertex_number_{vertex_number}, edge_number_{edge_number} { }

/**
 * @brief The function inserts a pair of vertexes into the object's vector
 * @param starting_value The starting point of the node
 * @param ending_value The desination point of the starting value
*/
void Graph::InsertPairOfVertexes(int starting_value, int ending_value) {
  starting_graph_values_.emplace_back(starting_value);
  ending_graph_values_.emplace_back(ending_value);
}

/**
 * @brief Writes all the pair of vertexes the object Graph has to the output
 *        file set by the user
 * @param output_file The file that the program will write to
 **/
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

/**
 * @brief Reads the user file that has the total amount of vertexes
 *        and edges the graph will have
 * @param graph_vertexes The total amount of vertexes (passed by reference)
 *                        the graph will have
 * @param graph_edges The total amount of edges (passed by reference)
 *                    the graph will have
 * @param user_input_file The file that the program will read
 **/
void ReadUserInitialGraphData(int& graph_vertexes, int& graph_edges,
                              std::ifstream& user_input_file) {
  user_input_file >> graph_vertexes;
  user_input_file >> graph_edges;
}

/**
 * @brief The function checks whether the total amount of vertexes and edges
 *        is valid for a graph
 * @param graph_vertexes The total amount of vertexes (passed by reference)
 *                        the graph should have
 * @param graph_edges The total amount of edges (passed by reference)
 *                    the graph should have
 * @return The function returns by a boolean value if both inputs are correct
 **/
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

/**
 * @brief The function reads as many pairs of vertexes as the user desires
 * @param user_graph The object Graph that will store all pairs of vertexes
 * @param user_input_file The file that the program will read
 **/
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

/**
 * @brief The function obtains a list of all the distinct values the pairs of
 *        vertexes have
 * @param user_graph The object Graph that stores all pairs of vertexes
 * @return The function returns an unordered_set of integers of all the
 *         different values that the pairs have
 **/
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

/**
 * @brief The function gets the total amount of pairs of vertexes the user
 *        has inputted.
 * @param user_graph The object Graph that stores all pairs of vertexes
 * @return The function returns as an integer the total amount of pairs of
 *         vertexes stored in the object Graph
 **/
int ObtainAmountOfPairs(const Graph& user_graph) {
  std::vector<int> amount_of_pairs{user_graph.GetEndingGraphValues()};
  return static_cast<int>(amount_of_pairs.size());
}

/**
 * @brief The function checks whether all digits of the pairs of vertexes are
 *        inside the allowed range (equal to the total amount of edges or less)
 * @param unique_pair_values A list of all the distinct values the pairs of
 *                           vertexes have
 * @param user_graph The object Graph that stores all pairs of vertexes and
 *                   total amount of vertexes and edges
 * @param infraction_numbers A list that will store the numbers that are out
 *                           of the valid range (if any)
 * @return The function returns in a boolean value of any number is out of the
 *         allowed range
 **/
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

/**
 * @brief The function prints all of the numbers (if any) that are out of the
 *        allowed range (equal to the total amount of edges or less) from the
 *        pairs of vertexes provided by the user
 * @param infraction_numbers A list with all of the numbers that are out of
 *                           the allowed range
 **/
void PrintInfractionNumbers(const std::vector<int>& infraction_numbers) {
  for (std::size_t counter{0}; counter < infraction_numbers.size(); ++counter) {
    std::cerr << infraction_numbers[counter];
    if (counter + 1 != infraction_numbers.size()) {
      std::cerr << ", ";
    }
  }
  std::cerr << '\n';
}

/**
 * @brief The function checks whether any of the pairs of vertexes is valid or
 *        not
 * @param user_graph The object Graph that stores all pairs of vertexes
 * @return The function returns in a boolean value if any pair of vertexes
 *         violates the rules set for a graph to be correct
 **/
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

/**
 * @brief The function checks whether the user file that will be opened can be
 *        actually opened or not.
 * @param user_file_name The user file name that will be checked now.
 * @param user_file The user file that will be later read and checked now.
 * @return The function returns in a bool value if the file was openend
 *         successfully or not, in which case it notifies the user.
 **/
bool CanOpenFile(const std::string& user_file_name, std::ifstream& user_file) {
  bool can_open_file{true};
  if (!user_file) {
    std::cerr << "El archivo " << user_file_name << " no se pudo abrir." <<
                 '\n';
    can_open_file = false;
  }
  return can_open_file;
}