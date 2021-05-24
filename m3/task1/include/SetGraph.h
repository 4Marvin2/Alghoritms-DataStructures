//
// Created by marvin on 24.05.2021.
//

#include <unordered_map>
#include <vector>

#include "IGraph.h"

#ifndef TASK1_SETGRAPH_H
#define TASK1_SETGRAPH_H

class SetGraph : public IGraph {
 public:
  explicit SetGraph(size_t _verticesCount);
  explicit SetGraph(const IGraph& _graph);

  ~SetGraph() override = default;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::unordered_map<int, int>> graph;
  size_t verticesCount;
};

#endif  // TASK1_SETGRAPH_H
