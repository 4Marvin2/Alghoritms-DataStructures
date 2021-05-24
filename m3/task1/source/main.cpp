//
// Created by marvin on 24.05.2021.
//

#include <cassert>
#include <vector>

#include "../include/ArcGraph.h"
#include "../include/ListGraph.h"
#include "../include/MatrixGraph.h"
#include "../include/SetGraph.h"

bool TestListGraph() {
  ListGraph lg(6);
  lg.AddEdge(0, 1);
  lg.AddEdge(1, 2);
  lg.AddEdge(2, 3);
  lg.AddEdge(3, 4);
  lg.AddEdge(4, 2);
  lg.AddEdge(4, 5);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = lg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestMatrixGraph() {
  MatrixGraph mg(6);
  mg.AddEdge(0, 1);
  mg.AddEdge(1, 2);
  mg.AddEdge(2, 3);
  mg.AddEdge(3, 4);
  mg.AddEdge(4, 2);
  mg.AddEdge(4, 5);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = mg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestSetGraph() {
  SetGraph sg(6);
  sg.AddEdge(0, 1);
  sg.AddEdge(1, 2);
  sg.AddEdge(2, 3);
  sg.AddEdge(3, 4);
  sg.AddEdge(4, 2);
  sg.AddEdge(4, 5);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = sg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestArcGraph() {
  ArcGraph arg(6);
  arg.AddEdge(0, 1);
  arg.AddEdge(1, 2);
  arg.AddEdge(2, 3);
  arg.AddEdge(3, 4);
  arg.AddEdge(4, 2);
  arg.AddEdge(4, 5);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = arg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestListGraphFromMatrixGraph() {
  MatrixGraph mg(6);
  mg.AddEdge(0, 1);
  mg.AddEdge(1, 2);
  mg.AddEdge(2, 3);
  mg.AddEdge(3, 4);
  mg.AddEdge(4, 2);
  mg.AddEdge(4, 5);
  ListGraph lg(mg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = lg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestListGraphFromSetGraph() {
  SetGraph sg(6);
  sg.AddEdge(0, 1);
  sg.AddEdge(1, 2);
  sg.AddEdge(2, 3);
  sg.AddEdge(3, 4);
  sg.AddEdge(4, 2);
  sg.AddEdge(4, 5);
  ListGraph lg(sg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = lg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestListGraphFromArcGraph() {
  SetGraph arg(6);
  arg.AddEdge(0, 1);
  arg.AddEdge(1, 2);
  arg.AddEdge(2, 3);
  arg.AddEdge(3, 4);
  arg.AddEdge(4, 2);
  arg.AddEdge(4, 5);
  ListGraph lg(arg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = lg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestMatrixGraphFromListGraph() {
  ListGraph lg(6);
  lg.AddEdge(0, 1);
  lg.AddEdge(1, 2);
  lg.AddEdge(2, 3);
  lg.AddEdge(3, 4);
  lg.AddEdge(4, 2);
  lg.AddEdge(4, 5);
  MatrixGraph mg(lg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = mg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestMatrixGraphFromSetGraph() {
  SetGraph sg(6);
  sg.AddEdge(0, 1);
  sg.AddEdge(1, 2);
  sg.AddEdge(2, 3);
  sg.AddEdge(3, 4);
  sg.AddEdge(4, 2);
  sg.AddEdge(4, 5);
  MatrixGraph mg(sg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = mg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestMatrixGraphFromArcGraph() {
  ArcGraph arg(6);
  arg.AddEdge(0, 1);
  arg.AddEdge(1, 2);
  arg.AddEdge(2, 3);
  arg.AddEdge(3, 4);
  arg.AddEdge(4, 2);
  arg.AddEdge(4, 5);
  MatrixGraph mg(arg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = mg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestSetGraphFromListGraph() {
  ListGraph lg(6);
  lg.AddEdge(0, 1);
  lg.AddEdge(1, 2);
  lg.AddEdge(2, 3);
  lg.AddEdge(3, 4);
  lg.AddEdge(4, 2);
  lg.AddEdge(4, 5);
  SetGraph sg(lg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = sg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestSetGraphFromMatrixGraph() {
  MatrixGraph mg(6);
  mg.AddEdge(0, 1);
  mg.AddEdge(1, 2);
  mg.AddEdge(2, 3);
  mg.AddEdge(3, 4);
  mg.AddEdge(4, 2);
  mg.AddEdge(4, 5);
  SetGraph sg(mg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = sg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestSetGraphFromArcGraph() {
  ArcGraph arg(6);
  arg.AddEdge(0, 1);
  arg.AddEdge(1, 2);
  arg.AddEdge(2, 3);
  arg.AddEdge(3, 4);
  arg.AddEdge(4, 2);
  arg.AddEdge(4, 5);
  SetGraph sg(arg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = sg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestArcGraphFromListGraph() {
  ListGraph lg(6);
  lg.AddEdge(0, 1);
  lg.AddEdge(1, 2);
  lg.AddEdge(2, 3);
  lg.AddEdge(3, 4);
  lg.AddEdge(4, 2);
  lg.AddEdge(4, 5);
  ArcGraph arg(lg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = arg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestArcGraphFromMatrixGraph() {
  MatrixGraph mg(6);
  mg.AddEdge(0, 1);
  mg.AddEdge(1, 2);
  mg.AddEdge(2, 3);
  mg.AddEdge(3, 4);
  mg.AddEdge(4, 2);
  mg.AddEdge(4, 5);
  ArcGraph arg(mg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(2);
  correctGraph[4].push_back(5);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = arg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool TestArcGraphFromSetGraph() {
  SetGraph sg(6);
  sg.AddEdge(0, 1);
  sg.AddEdge(1, 2);
  sg.AddEdge(2, 3);
  sg.AddEdge(3, 4);
  sg.AddEdge(4, 2);
  sg.AddEdge(4, 5);
  ArcGraph arg(sg);
  std::vector<std::vector<int>> correctGraph(6);
  correctGraph[0].push_back(1);
  correctGraph[1].push_back(2);
  correctGraph[2].push_back(3);
  correctGraph[3].push_back(4);
  correctGraph[4].push_back(5);
  correctGraph[4].push_back(2);
  for (int i = 0; i < 6; ++i) {
    std::vector<int> currentVertices = arg.GetNextVertices(i);
    if (currentVertices.size() != correctGraph[i].size()) {
      return false;
    }
    for (int j = 0; j < currentVertices.size(); ++j) {
      if (currentVertices[j] != correctGraph[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  assert(TestListGraph() != false);
  assert(TestMatrixGraph() != false);
  assert(TestSetGraph() != false);
  assert(TestArcGraph() != false);

  assert(TestListGraphFromMatrixGraph() != false);
  assert(TestListGraphFromSetGraph() != false);
  assert(TestListGraphFromArcGraph() != false);

  assert(TestMatrixGraphFromListGraph() != false);
  assert(TestMatrixGraphFromSetGraph() != false);
  assert(TestMatrixGraphFromArcGraph() != false);

  assert(TestSetGraphFromListGraph() != false);
  assert(TestSetGraphFromMatrixGraph() != false);
  assert(TestSetGraphFromArcGraph() != false);

  assert(TestArcGraphFromListGraph() != false);
  assert(TestArcGraphFromMatrixGraph() != false);
  assert(TestArcGraphFromSetGraph() != false);

  return 0;
}
