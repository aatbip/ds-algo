class LRUCache {
  int capacity;
  int size;
  LRUCache *tail;
  LRUCache *head;

public:
  LRUCache(int c) : capacity{c}, size{0}, head{nullptr}, tail{nullptr} {}
};

int main(void) {
  LRUCache *head = new LRUCache(20);
  return 0;
}
