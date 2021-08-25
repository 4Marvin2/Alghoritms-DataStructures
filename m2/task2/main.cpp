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
  BinaryTree() : root(nullptr), comp(DefaultComparator<T>()) {}
  explicit BinaryTree(Comparator _comp) : root(nullptr), comp(_comp) {}
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

  void insert(T key) {
    Node* temp = nullptr;

    if (root == nullptr) {
      root = new Node(key);
      return;
    }

    temp = root;
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

  void level_order(void (BinaryTree<T, Comparator>::*callback)(Node*)) {
    if (root == nullptr) {
      return;
    }

    std::queue<Node*> temp_queue;
    temp_queue.push(root);
    while (!temp_queue.empty()) {
      Node* temp = temp_queue.front();
      temp_queue.pop();
      (this->*callback)(temp);

      if (temp->left != nullptr) {
        temp_queue.push(temp->left);
      }
      if (temp->right != nullptr) {
        temp_queue.push(temp->right);
      }
    }
  }

  void print(Node* current_node) { std::cout << current_node->key << " "; }

  int min_height() {
    if (root == nullptr) {
      return 0;
    }

    int height = 1;
    int count_on_level = 0;
    std::queue<Node*> temp_queue;
    temp_queue.push(root);
    while (!temp_queue.empty()) {
      Node* temp = temp_queue.front();
      temp_queue.pop();

      if (temp->left != nullptr) {
        count_on_level++;
        temp_queue.push(temp->left);
      }
      if (temp->right != nullptr) {
        count_on_level++;
        temp_queue.push(temp->right);
      }

      int next_level_count = 0;
      while (count_on_level != 0) {
        temp = temp_queue.front();
        temp_queue.pop();
        if (temp->left != nullptr) {
          next_level_count++;
          temp_queue.push(temp->left);
        }
        if (temp->right != nullptr) {
          next_level_count++;
          temp_queue.push(temp->right);
        }
        count_on_level--;
      }
      count_on_level = next_level_count;
      height++;
      if ((temp->right == nullptr) && (temp->left == nullptr)) {
        return height;
      }
    }
  }

 private:
  Node* root;
  Comparator comp;
};

int main() {
  int n;
  std::cin >> n;
  BinaryTree<int> tree;
  //  for (int i = 0; i < n; i++) {
  //    int current_key;
  //    std::cin >> current_key;
  //    tree.insert(current_key);
  //  }
  //  tree.level_order(&BinaryTree<int>::print);
  for (int i = 0; i < n; i++) {
    int current_key;
    std::cin >> current_key;
    tree.insert(current_key);
  }
  std::cout << tree.min_height();

  return 0;
}
