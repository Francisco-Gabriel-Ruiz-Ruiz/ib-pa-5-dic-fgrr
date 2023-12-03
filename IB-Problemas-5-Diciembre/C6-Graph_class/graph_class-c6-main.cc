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
#include<vector>
#include <unordered_set> // To keep track of unique numbers in a vertex
class Graph {
 public:
  Graph(int vertex_number, int edge_number) : vertex_number_{vertex_number}, edge_number_{edge_number} { }
  friend std::ostream& operator<<(std::ostream& out, const Graph& user_graph);
  int GetVertexNumber() const {
    return vertex_number_;
  }
  int GetEdgeNumber() const {
    return edge_number_;
  }
  std::vector<int> GetStartingGraphValues() const {
    return starting_graph_values_;
  }
  std::vector<int> GetEndingGraphValues() const {
    return ending_graph_values_;
  }
  void InsertPairOfVertexes(int starting_value, int ending_value) {
    starting_graph_values_.emplace_back(starting_value);
    ending_graph_values_.emplace_back(ending_value);
  }
  void PrintPairOfVertexes() const {
    for (std::size_t counter{0}; counter < starting_graph_values_.size(); ++counter) {
      std::cout << starting_graph_values_[counter] << " " <<
                   ending_graph_values_[counter];
      if (counter + 1 != starting_graph_values_.size()) {
        std::cout << '\n';
      }
    }
  }
 private:
  int vertex_number_;
  int edge_number_;
  std::vector<int> starting_graph_values_;
  std::vector<int> ending_graph_values_;
};

void ReadUserInitialGraphData(int& graph_vertexes, int& graph_edges) {
  std::cout << "Introduzca la cantidad de vértices de su grafo: ";
  std::cin >> graph_vertexes;
  std::cout << "Introduzca la cantidad de aristas de su grafo: ";
  std::cin >> graph_edges;
}

std::ostream& operator<<(std::ostream& out, const Graph& user_graph) {
  out << user_graph.vertex_number_ << " " << user_graph.edge_number_ << '\n';
  user_graph.PrintPairOfVertexes();
  return out;
}

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
  std::vector<int> amount_of_pairs{user_graph.GetStartingGraphValues()};
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
  if (number_of_different_vertexes != user_graph.GetVertexNumber()) {
    std::cerr << "Introduzca unos pares de vértices válidos." << '\n';
  }
  int amount_of_pairs{ObtainAmountOfPairs(user_graph)};
  if (amount_of_pairs != user_graph.GetEdgeNumber()) {
    std::cerr << "Introduzca unos pares de vértices válidos." << '\n';
  }
  std::vector<int> infraction_numbers;
  if (!ValuesOfPairsInRange(unique_pair_values, user_graph, infraction_numbers)) {
    std::cerr << "Ha introducido al menos un número en un par que no " <<
                 "es válido: ";
    PrintInfractionNumbers(infraction_numbers);
  }
  return (number_of_different_vertexes == user_graph.GetVertexNumber()) &&
         (amount_of_pairs == user_graph.GetEdgeNumber()) &&
         ValuesOfPairsInRange(unique_pair_values, user_graph, infraction_numbers);
}

int main() {
  int graph_vertexes;
  int graph_edges;
  ReadUserInitialGraphData(graph_vertexes, graph_edges);
  if (!ValidInitialGraphData(graph_vertexes, graph_edges)) {
    return 1;
  }
  Graph user_graph{graph_vertexes, graph_edges};
  ReadUserPairOfVertexes(user_graph);
  if (!ValidPairs(user_graph)) {
    return 2;
  }
  std::cout << user_graph << '\n' << "Su grafo es válido." << '\n';
  return 0;
}