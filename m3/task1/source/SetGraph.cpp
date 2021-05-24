//
// Created by marvin on 24.05.2021.
//

#include "../include/SetGraph.h"

#include <algorithm>
#include <iostream>

SetGraph::SetGraph(size_t _verticesCount) : verticesCount(_verticesCount) {
  graph.resize(verticesCount);
}

SetGraph::SetGraph(const IGraph &_graph) : SetGraph(_graph.VerticesCount()) {
  for (int i = 0; i < graph.size(); i++) {
    std::vector<int> current = _graph.GetNextVertices(i);
    for (int j : current) {
      graph[i][j] = j;
    }
  }
}

void SetGraph::AddEdge(int from, int to) { graph[from][to] = to; }

int SetGraph::VerticesCount() const { return verticesCount; }

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;
  for (auto x : graph[vertex]) {
    result.push_back(x.first);
  }
  return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;
  for (int i = 0; i < graph.size(); ++i) {
    auto element = graph[i].find(vertex);
    if (element != graph[i].end()) {
      result.push_back(i);
    }
  }
  return result;
}
