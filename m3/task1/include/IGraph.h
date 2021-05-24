//
// Created by marvin on 24.05.2021.
//

#include <vector>

#ifndef TASK1_IGRAPH_H
#define TASK1_IGRAPH_H

struct IGraph {
  virtual ~IGraph() {}

  // Добавление ребра от from к to.
  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const = 0;

  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif  // TASK1_IGRAPH_H
