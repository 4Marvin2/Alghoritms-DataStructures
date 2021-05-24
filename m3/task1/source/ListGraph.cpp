#include "../include/ListGraph.h"

#include <algorithm>
#include <iostream>

ListGraph::ListGraph(size_t _verticesCount) : verticesCount(_verticesCount) {
  graph.resize(verticesCount);
}

ListGraph::ListGraph(const IGraph &_graph) : ListGraph(_graph.VerticesCount()) {
  for (int i = 0; i < graph.size(); i++) {
    std::vector<int> current = _graph.GetNextVertices(i);
    for (int j : current) {
      graph[i].push_back(j);
    }
  }
}

void ListGraph::AddEdge(int from, int to) { graph[from].push_back(to); }

int ListGraph::VerticesCount() const { return verticesCount; }

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;
  result.resize(graph[vertex].size());
  std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
  return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;
  for (int parent = 0; parent < graph.size(); ++parent) {
    for (int child : graph[parent]) {
      if (child == vertex) {
        result.push_back(parent);
      }
    }
  }
  return result;
}
