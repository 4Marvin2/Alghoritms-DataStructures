#include <cassert>
#include <iostream>
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

template <class Key, class Comparator = DefaultComparator<Key>>
class AvlTree {
  struct Node {
    Key key;

    Node* left;
    Node* right;

    uint8_t height;
    int subtree_elements_count;

    explicit Node(const Key& _key)
        : key(_key),
          left(nullptr),
          right(nullptr),
          height(1),
          subtree_elements_count(1) {}
  };

 public:
  AvlTree() : root(nullptr), items_count(0), comp(DefaultComparator<Key>()) {}
  explicit AvlTree(Comparator _comp)
      : root(nullptr), items_count(0), comp(_comp) {}
  ~AvlTree() {
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

  AvlTree(const AvlTree&) = delete;
  AvlTree(AvlTree&&) = delete;

  AvlTree& operator=(const AvlTree&) = delete;
  AvlTree& operator=(AvlTree&&) = delete;

  Key* find(const Key& key) { return find_aux(key, root); }

  void insert(const Key& key) { root = insert_aux(key, root); }

  void erase(const Key& key) { root = erase_aux(key, root); }

  Key* order_statistics(int k) {
    assert(root != nullptr);

    int needed_element_counts = k + 1;

    if ((root->left == nullptr) && (root->right == nullptr)) {
      return &root->key;
    }
    return order_statistics_aux(needed_element_counts, root);
  }

  size_t size() const { return items_count; }

  bool is_empty() const { return items_count == 0; }

 private:
  Key* find_aux(const Key& key, Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    int comp_res = comp(key, node->key);
    if (comp_res == -1) {
      return find_aux(key, node->left);
    } else if (comp_res == 1) {
      return find_aux(key, node->right);
    }
    return &node->key;
  }

  Node* insert_aux(const Key& key, Node* node) {
    if (node == nullptr) {
      items_count++;
      return new Node(key);
    }

    int comp_res = comp(key, node->key);
    if (comp_res == -1) {
      node->left = insert_aux(key, node->left);
    } else if (comp_res == 1) {
      node->right = insert_aux(key, node->right);
    }

    return balance(node);
  }

  Node* erase_aux(const Key& key, Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    int comp_res = comp(key, node->key);
    if (comp_res == -1) {
      node->left = erase_aux(key, node->left);
    } else if (comp_res == 1) {
      node->right = erase_aux(key, node->right);
    } else {
      Node* left = node->left;
      Node* right = node->right;

      items_count--;
      delete node;

      if (right == nullptr) {
        return left;
      }

      Node* min_node = find_and_remove_min(right);
      min_node->left = left;

      return balance(min_node);
    }

    return balance(node);
  }

  Node* find_and_remove_min(Node* node) {
    Node* parent = nullptr;
    Node* min_node = node;
    std::stack<Node*> reverse_nodes;
    while (min_node->left != nullptr) {
      parent = min_node;
      min_node = min_node->left;
      reverse_nodes.push(parent);
    }

    if (parent == nullptr) {
      return min_node;
    }

    parent->left = min_node->right;
    min_node->right = node;
    Node* current = reverse_nodes.top();
    reverse_nodes.pop();
    while (!reverse_nodes.empty()) {
      Node* previous = reverse_nodes.top();
      reverse_nodes.pop();
      previous->left = balance(current);
      current = previous;
    }
    min_node->right = balance(min_node->right);

    return min_node;
  }

  Node* balance(Node* node) {
    fix_height(node);
    fix_rank(node);
    int balance_factor = bfactor(node);
    if (balance_factor == 2) {
      if (bfactor(node->right) < 0) {
        node->right = rotate_right(node->right);
      }
      return rotate_left(node);
    }
    if (balance_factor == -2) {
      if (bfactor(node->left) > 0) {
        node->left = rotate_left(node->left);
      }
      return rotate_right(node);
    }
    return node;
  }

  Node* rotate_right(Node* node) {
    Node* left = node->left;
    node->left = left->right;
    left->right = node;
    fix_height(node);
    fix_height(left);

    fix_rank(node);
    fix_rank(left);

    return left;
  }

  Node* rotate_left(Node* node) {
    Node* right = node->right;
    node->right = right->left;
    right->left = node;
    fix_height(node);
    fix_height(right);

    fix_rank(node);
    fix_rank(right);

    return right;
  }

  int bfactor(Node* node) { return height(node->right) - height(node->left); }

  uint8_t height(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  void fix_height(Node* node) {
    if (node == nullptr) {
      return;
    }
    node->height = std::max(height(node->left), height(node->right)) + 1;
  }

  int rank(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->subtree_elements_count;
  }

  void fix_rank(Node* node) {
    if (node == nullptr) {
      return;
    }
    node->subtree_elements_count = rank(node->left) + rank(node->right) + 1;
  }

  Key* order_statistics_aux(int k, Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    int left_subtree_elements_count = 0;
    if (node->left != nullptr) {
      left_subtree_elements_count = node->left->subtree_elements_count;
    }
    int comp_res = comp(k, left_subtree_elements_count + 1);
    if (comp_res == -1) {
      return order_statistics_aux(k, node->left);
    } else if (comp_res == 1) {
      k -= left_subtree_elements_count + 1;
      return order_statistics_aux(k, node->right);
    }
    return &node->key;
  }

  Node* root;
  size_t items_count;
  Comparator comp;
};

int main() {
  int n;
  std::cin >> n;
  AvlTree<int> tree;
  for (int i = 0; i < n; i++) {
    int value, k;
    std::cin >> value >> k;
    if (value >= 0) {
      tree.insert(value);
    } else {
      tree.erase(-value);
    }
    std::cout << (*tree.order_statistics(k)) << "\n";
  }
  return 0;
}
