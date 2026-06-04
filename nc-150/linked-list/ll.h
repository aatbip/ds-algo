#ifndef LL_H
#define LL_H

typedef struct ll {
  int key;
  struct ll *next;
} ll;

ll *create_list(int key);
void insert_node(ll *list, int key);
void download_ll(ll *list);

#endif /* ifndef LL_H */
