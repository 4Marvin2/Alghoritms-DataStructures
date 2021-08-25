#include <iostream>
#include <queue>
#include <stack>

template <class T>
struct DefaultComparator {
  int operator()(const T& l, const T& r) const {
    if (l < r) {
      return -1;
    } else if (l > r) {
      return 1;
    }
    return 0;
  }
};

template <class T, class Comparator = DefaultComparator<T>>
class BinaryTree {
  struct Node {
    T key;

    Node* left;
    Node* right;

    explicit Node(const T& _key) : key(_key), left(nullptr), right(nullptr) {}
  };

 public:
  BinaryTree() : root(nullptr), height(0), comp(DefaultComparator<T>()) {}
  explicit BinaryTree(Comparator _comp)
      : root(nullptr), height(0), comp(_comp) {}
  ~BinaryTree() {
    if (root == nullptr) {
      return;
    }
    std::stack<Node*> temp_stack;
    std::stack<Node*> revers_stack;
    temp_stack.push(root);
    while (!temp_stack.empty()) {
      Node* temp = temp_stack.top();
      temp_stack.pop();
      revers_stack.push(temp);
      if (temp->left != nullptr) {
        temp_stack.push(temp->left);
      }
      if (temp->right != nullptr) {
        temp_stack.push(temp->right);
      }
    }
    while (!revers_stack.empty()) {
      Node* current_node = revers_stack.top();
      delete current_node;
      revers_stack.pop();
    }
  }

  BinaryTree(const BinaryTree&) = delete;
  BinaryTree(BinaryTree&&) = delete;

  BinaryTree& operator=(const BinaryTree&) = delete;
  BinaryTree& operator=(BinaryTree&&) = delete;

  void insert(const T& key) {
    if (root == nullptr) {
      root = new Node(key);
      return;
    }

    Node* temp = root;
    while (temp) {
      if (comp(key, temp->key) == 1) {
        if (temp->right) {
          temp = temp->right;
          continue;
        } else {
          temp->right = new Node(key);
          return;
        }
      } else if (comp(key, temp->key) == -1) {
        if (temp->left) {
          temp = temp->left;
          continue;
        } else {
          temp->left = new Node(key);
          return;
        }
      }
    }
  }

  uint32_t get_height() {
    height = find_height();
    return height;
  }

 private:
  uint32_t find_height() {
    if (root == nullptr) {
      return 0;
    }

    std::queue<Node*> nodes;
    nodes.push(root);
    uint32_t current_height = 0;

    while (true) {
      uint32_t nodes_count = nodes.size();
      if (nodes_count == 0) {
        return current_height;
      }

      current_height++;

      while (nodes_count > 0) {
        Node* temp = nodes.front();
        nodes.pop();
        if (temp->left != nullptr) {
          nodes.push(temp->left);
        }
        if (temp->right != nullptr) {
          nodes.push(temp->right);
        }
        nodes_count--;
      }
    }
  }

  Node* root;
  uint32_t height;

  Comparator comp;
};

template <class T, class Comparator = DefaultComparator<T>>
class Treap {
  struct Node {
    T key;
    int prior;

    Node* left;
    Node* right;

    explicit Node(const T& _key, const int& _prior)
        : key(_key), prior(_prior), left(nullptr), right(nullptr) {}
  };

 public:
  Treap() : root(nullptr), height(0), comp(DefaultComparator<T>()) {}
  explicit Treap(Comparator _comp) : root(nullptr), height(0), comp(_comp) {}
  ~Treap() {
    if (root == nullptr) {
      return;
    }
    std::stack<Node*> temp_stack;
    std::stack<Node*> revers_stack;
    temp_stack.push(root);
    while (!temp_stack.empty()) {
      Node* temp = temp_stack.top();
      temp_stack.pop();
      revers_stack.push(temp);
      if (temp->left != nullptr) {
        temp_stack.push(temp->left);
      }
      if (temp->right != nullptr) {
        temp_stack.push(temp->right);
      }
    }
    while (!revers_stack.empty()) {
      Node* current_node = revers_stack.top();
      delete current_node;
      revers_stack.pop();
    }
  }

  Treap(const Treap&) = delete;
  Treap(Treap&&) = delete;

  Treap& operator=(const Treap&) = delete;
  Treap& operator=(Treap&&) = delete;

  void insert(const T& key, const int& prior) {
    if (root == nullptr) {
      root = new Node(key, prior);
      return;
    }

    Node* new_node = new Node(key, prior);
    Node* parent = nullptr;
    Node* temp = root;
    while ((temp != nullptr) && (temp->prior > prior)) {
      parent = temp;
      if (comp(key, temp->key) == 1) {
        temp = temp->right;
      } else if (comp(key, temp->key) == -1) {
        temp = temp->left;
      }
    }
    split(temp, key, new_node->left, new_node->right);

    if (root->prior < prior) {
      root = new_node;
      return;
    }

    if (parent->left == temp) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  }

  uint32_t get_height() {
    height = find_height();
    return height;
  }

 private:
  void split(Node* node, const T& key, Node*& left, Node*& right) {
    if (node == nullptr) {
      left = nullptr;
      right = nullptr;
      return;
    }

    if (key < node->key) {
      split(node->left, key, left, node->left);
      right = node;
    } else {
      split(node->right, key, node->right, right);
      left = node;
    }
  }

  uint32_t find_height() {
    if (root == nullptr) {
      return 0;
    }

    std::queue<Node*> nodes;
    nodes.push(root);
    uint32_t current_height = 0;

    while (true) {
      uint32_t nodes_count = nodes.size();
      if (nodes_count == 0) {
        return current_height;
      }

      current_height++;

      while (nodes_count > 0) {
        Node* temp = nodes.front();
        nodes.pop();
        if (temp->left != nullptr) {
          nodes.push(temp->left);
        }
        if (temp->right != nullptr) {
          nodes.push(temp->right);
        }
        nodes_count--;
      }
    }
  }

  Node* root;
  uint32_t height;

  Comparator comp;
};

int main() {
  BinaryTree<int> binary_tree;
  Treap<int> cartesian_tree;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int current_key, current_prior;
    std::cin >> current_key >> current_prior;
    cartesian_tree.insert(current_key, current_prior);
    binary_tree.insert(current_key);
  }

  std::cout << abs((int32_t)(binary_tree.get_height()) -
                   (int32_t)(cartesian_tree.get_height()));

  return 0;
}
