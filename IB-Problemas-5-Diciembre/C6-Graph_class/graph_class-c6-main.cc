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
    for (int counter{0}; counter < starting_graph_values_.size(); ++counter) {
      std::cout << starting_graph_values_[counter] << " " <<
                   ending_graph_values_[counter] << '\n';
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
  out << user_graph.vertex_number_ << " " << user_graph.edge_number_;
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
  return (graph_vertexes < 1 || graph_edges < 1 || graph_vertexes <= graph_edges);
}

void ReadUserPairOfVertexes(Graph& user_graph) {
  for (int counter{1}; counter < (user_graph.GetVertexNumber()); ++counter) {
    int starting_value;
    std::cin >> starting_value;
    int ending_value;
    std::cin >> ending_value;
    user_graph.InsertPairOfVertexes(starting_value, ending_value);
  }
}

int NumberOfDifferentVertexes(const Graph& user_graph) {
  std::vector<int> starting_graph_values{user_graph.GetStartingGraphValues()};
  std::vector<int> ending_graph_values{user_graph.GetEndingGraphValues()};
  std::vector<int> unique_values
  for (int extracted_vertex : starting_graph_values) {

  }
}

bool ValidPairs(const Graph& user_graph) {
  int number_of_different_vertexes{NumberOfDifferentVertexes(user_graph)};
  if (number_of_different_vertexes != user_graph.GetVertexNumber()) {
    std::cerr << "Introduzca unos pares de vértices válidos." << '\n';
  }
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
  std::cout << user_graph << '\n';
  return 0;
}