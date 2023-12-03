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

#include "graph_class-c6-teclado.h"

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
 * @brief Prints all the pair of vertexes the object Graph has
 **/
void Graph::PrintPairOfVertexes() const {
  for (std::size_t counter{0}; counter < starting_graph_values_.size(); ++counter) {
    std::cout << starting_graph_values_[counter] << " " <<
               ending_graph_values_[counter];
    if (counter + 1 != starting_graph_values_.size()) {
      std::cout << '\n';
    }
  }
}

/**
 * @brief Overloads the << operator by printing all the Graph object data
 * @param out Necessary for the overload
 * @param user_graph The Graph object that will be printed
 * @return Prints the Graph object data; first the vertex and edge total,
 *         then all the pair of vertexes provided by the user
 **/
std::ostream& operator<<(std::ostream& out, const Graph& user_graph) {
  out << user_graph.vertex_number_ << " " << user_graph.edge_number_ << '\n';
  user_graph.PrintPairOfVertexes();
  return out;
}

/**
 * @brief Reads the user input that corresponds to the total amount of vertexes
 *        and edges the graph will have
 * @param graph_vertexes The total amount of vertexes (passed by reference)
 *                        the graph will have
 * @param graph_edges The total amount of edges (passed by reference)
 *                    the graph will have
 **/
void ReadUserInitialGraphData(int& graph_vertexes, int& graph_edges) {
  std::cout << "Introduzca la cantidad de vértices de su grafo: ";
  std::cin >> graph_vertexes;
  std::cout << "Introduzca la cantidad de aristas de su grafo: ";
  std::cin >> graph_edges;
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
    std::cerr << "Introduzca un número de vértices válido" << '\n';
  } else if (graph_edges < 1) {
    std::cerr << "Introduzca un número de aristas válido" << '\n';
  } else if (graph_vertexes - 1 != graph_edges) {
    std::cerr << "Su grafo no puede contener un mismo o mayor número de " <<
                 "aristas que de vértices." << '\n';
  }
  return (graph_vertexes > 1 && graph_edges > 1 && graph_vertexes > graph_edges);
}

/**
 * @brief The function reads as many pairs of vertexes as the user desires
 * @param user_graph The object Graph that will store all pairs of vertexes
 **/
void ReadUserPairOfVertexes(Graph& user_graph) {
  while (true) {
    std::cout << "Introduzca su par de vértices (-1 para finalizar): ";
    int starting_value;
    std::cin >> starting_value;
    if (starting_value == -1) {
      break;
    }
    int ending_value;
    std::cin >> ending_value;
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
  std::vector<int> amount_of_pairs{user_graph.GetStartingGraphValues()};
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
    std::cerr << "Introduzca unos pares de vértices válidos." << '\n';
  }
  std::vector<int> infraction_numbers;
  if (!ValuesOfPairsInRange(unique_pair_values, user_graph, infraction_numbers)) {
    std::cerr << "Ha introducido al menos un número en un par que no " <<
                 "es válido (por ser mayor que el número de aristas): ";
    PrintInfractionNumbers(infraction_numbers);
  }
  return (number_of_different_vertexes == user_graph.GetVertexNumber()) &&
         (amount_of_pairs == user_graph.GetEdgeNumber()) &&
         ValuesOfPairsInRange(unique_pair_values, user_graph, infraction_numbers);
}

/**
 * @brief Prints the program purpose and how to execute its command
 **/
void PrintProgramPurpose() {
  std::cout << "Introduzca los datos de un grafo en el programa, y este le " <<
               "indicará si es válido o no. " << '\n' << "Para introducir " <<
               "los pares de vértices, hágalo separando los números con un " <<
               "espacio." << '\n' << "Para más información, consulte el " <<
               "README.md" << '\n';
}