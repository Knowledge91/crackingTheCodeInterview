const int kTableSize = 10;

template <typename K, typename V>
class HashNode {
 public:
  HashNode(const K &key, const V &value)
      : key_(key), value_(value), next_(nullptr) {}

  K getKey() const { return key_; }

  V getValue() const { return value_; }

  void setValue(V value) { value_ = value; }

  HashNode *getNext() const { return next_; }

  void setNext(HashNode *next) { next_ = next; }

 private:
  K key_;
  V value_;
  HashNode *next_;
};

template <typename K>
struct KeyHash {
  unsigned long operator()(K key) {
    return reinterpret_cast<unsigned long>(key) % kTableSize;
  }
};

template <typename K, typename V, typename F = KeyHash<K> >
class HashTable {
 public:
  HashTable() { table_ = new HashNode<K, V> *[kTableSize](); }

  ~HashTable() {
    for (int i = 0; i < kTableSize; ++i) {
      HashNode<K, V> *entry = table_[i];
      while (entry != nullptr) {
        HashNode<K, V> *prev = entry;
        entry = entry->getNext();
        delete prev;
      }
    }

    delete[] table_;
  }

  bool get(const K &key, V &value) const {
    HashNode<K, V> *entry = table_[hashFunc_(key)];
    while (entry != nullptr) {
      if (entry->getKey() == key) {
        value = entry->getValue();
        return true;
      }
      entry = entry->getNext();
    }
    return false;
  }

  void put(const K &key, const V &value) {
    unsigned long hashValue = hashFunc_(key);
    HashNode<K, V> *prev = nullptr;
    HashNode<K, V> *entry = table_[hashValue];

    while (entry != nullptr && entry->getKey() != key) {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == nullptr) {
      entry = new HashNode<K, V>(key, value);
      if (prev == nullptr) {
        // insert as first bucket
        table_[hashValue] = entry;
      } else {
        prev->setNext(entry);
      }
    } else {
      // just update the value
      entry->setValue(value);
    }
  }

  void remove(const K &key) {
    unsigned long hashValue = hashFunc(key);
    HashNode<K, V> *prev = nullptr;
    HashNode<K, V> *entry = table_[hashValue];

    while (entry != nullptr && entry->getKey() != key) {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == nullptr) {
      // key not found
      return;
    } else {
      if (prev == nullptr) {
        // remove first bucket of the list
        table_[hashValue] = entry->getNext();
      } else {
        prev->setNext(entry->getNext());
      }
      delete entry;
    }
  }

 private:
  HashNode<K, V> **table_;
  F hashFunc_;
};