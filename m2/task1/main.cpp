// Для разрешения коллизий используйте двойное хеширование.

#include <iostream>
#include <vector>

#define EMPTY 1
#define KEY 2
#define DELETE 3

class Hash1 {
 public:
  uint32_t operator()(const std::string& str) {
    uint32_t hash = 0;
    for (char i : str) {
      hash = hash * 13 + i;
    }
    return hash;
  }
};

class Hash2 {
 public:
  uint32_t operator()(const std::string& str) {
    uint32_t hash = 0;
    for (char i : str) {
      hash = hash * 31 + i;
    }
    return hash;
  }
};

template <class Key, class Hash1, class Hash2>
class HashTable {
  static const size_t initial_size = 8;

  struct Node {
    Key key;
    int state;

    explicit Node() : state(EMPTY) {}
  };

 public:
  HashTable(Hash1 _h1, Hash2 _h2)
      : table(0), items_count(0), hasher1(_h1), hasher2(_h2) {}
  HashTable(size_t _size, Hash1 _h1, Hash2 _h2)
      : table(_size), items_count(0), hasher1(_h1), hasher2(_h2) {}
  ~HashTable() = default;

  HashTable(const HashTable&) = delete;
  HashTable(HashTable&&) = delete;

  HashTable& operator=(const HashTable&) = delete;
  HashTable& operator=(HashTable&&) = delete;

  bool add(const Key& key) {
    if (items_count * 4 >= table.size() * 3) {
      resize();
    }
    uint32_t h1 = hasher1(key);
    uint32_t h2 = 2 * hasher2(key) + 1;
    int first_deleted = -1;
    int i = 0;
    int j = (h1 + i * h2) % table.size();
    while ((table[j].state != EMPTY) && (i < table.size())) {
      if ((table[j].key == key) && (table[j].state == KEY)) {
        return false;
      }
      if ((table[j].state == DELETE) && (first_deleted == -1)) {
        first_deleted = j;
      }
      i++;
      j = (h1 + i * h2) % table.size();
    }
    if (first_deleted == -1) {
      table[j].key = key;
      table[j].state = KEY;
    } else {
      table[first_deleted].key = key;
      table[first_deleted].state = KEY;
    }
    items_count++;
    return true;
  }

  bool find(const Key& key) {
    uint32_t h1 = hasher1(key);
    uint32_t h2 = 2 * hasher2(key) + 1;
    for (int i = 0; i < table.size(); i++) {
      int j = (h1 + i * h2) % table.size();
      if (table[j].state == EMPTY) {
        return false;
      }
      if ((table[j].key == key) && (table[j].state == KEY)) {
        return true;
      }
    }
    return false;
  }

  bool remove(const Key& key) {
    uint32_t h1 = hasher1(key);
    uint32_t h2 = 2 * hasher2(key) + 1;
    for (int i = 0; i < table.size(); i++) {
      int j = (h1 + i * h2) % table.size();
      if (table[j].state == EMPTY) {
        return false;
      }
      if ((table[j].key == key) && (table[j].state == KEY)) {
        table[j].state = DELETE;
        items_count--;
        return true;
      }
    }
    return false;
  }

 private:
  void resize() {
    size_t new_size = (table.empty()) ? initial_size : table.size() * 2;
    HashTable<Key, Hash1, Hash2> temp_hash_table(new_size, hasher1, hasher2);
    for (int i = 0; i < table.size(); i++) {
      if (table[i].state == KEY) {
        temp_hash_table.add(table[i].key);
      }
    }
    table.resize(new_size);
    for (int i = 0; i < table.size(); i++) {
      table[i].state = temp_hash_table.table[i].state;
      if (table[i].state == KEY) {
        table[i].key = temp_hash_table.table[i].key;
      }
    }
  }

  void rehash() {
    size_t current_size = table.size();
    HashTable<Key, Hash1, Hash2> temp_hash_table(current_size, hasher1,
                                                 hasher2);
    for (int i = 0; i < table.size(); i++) {
      if (table[i].state == KEY) {
        temp_hash_table.add(table[i].key);
      }
    }
    for (int i = 0; i < table.size(); i++) {
      table[i].state = temp_hash_table.table[i].state;
      if (table[i].state == KEY) {
        table[i].key = temp_hash_table.table[i].key;
      }
    }
  }

  std::vector<Node> table;
  size_t items_count;
  Hash1 hasher1;
  Hash2 hasher2;
};

int main() {
  Hash1 hasher1;
  Hash2 hasher2;
  HashTable<std::string, Hash1, Hash2> hash_table(hasher1, hasher2);
  char command;
  std::string key;
  bool result = false;
  while (std::cin >> command >> key) {
    switch (command) {
      case '+':
        result = hash_table.add(key);
        break;
      case '-':
        result = hash_table.remove(key);
        break;
      case '?':
        result = hash_table.find(key);
        break;
      default:
        return 0;
    }
    if (result) {
      std::cout << "OK\n";
    } else {
      std::cout << "FAIL\n";
    }
  }

  return 0;
}
