#include <stdio.h>
#include <stdlib.h>

typedef struct _bst_node {
  int key;
  struct _bst_node *l;
  struct _bst_node *r;
  int n; // number of nodes in the sub tree of any node
} bst_node_t;

typedef struct _bst_ctx {
  int count; // number of nodes
} bst_ctx_t;

static bst_ctx_t bst_ctx;

/*init() create a dummy root*/
bst_node_t *bst_init() {
  // initialize bst_ctx
  bst_ctx.count = 0;

  return NULL;
}

bst_node_t *int_insert(bst_node_t *node, bst_node_t *parent) {
  if (parent == NULL) {
    return node;
  }
  if (node->key > parent->key) {
    parent->r = int_insert(node, parent->r);
  } else {
    parent->l = int_insert(node, parent->l);
  }
  parent->n++;
  return parent;
}

bst_node_t *bst_insert(bst_node_t *root, int key) {
  bst_node_t *node = malloc(sizeof(bst_node_t));
  node->key = key;
  node->l = node->r = NULL;
  node->n = 1;
  bst_ctx.count++;

  if (root == NULL) {
    return node;
  }

  return int_insert(node, root);
}

bst_node_t *bst_nonrecurs_insert(bst_node_t *root, int key) {
  bst_node_t *node = malloc(sizeof(bst_node_t));
  node->key = key;
  node->l = node->r = NULL;
  bst_ctx.count++;

  if (root == NULL)
    return node;

  bst_node_t *cur = root;
  bst_node_t *parent = NULL;

  while (1) {
    if (!cur) {
      if (key < parent->key) {
        parent->l = node;
      } else {
        parent->r = node;
      }
      break;
    }
    parent = cur;
    if (key < cur->key) {
      cur = cur->l;
    } else {
      cur = cur->r;
    }
  }
  return root;
}

bst_node_t *bst_search(bst_node_t *node, int key) {
  if (!node)
    return NULL;
  if (node->key == key)
    return node;
  if (key < node->key)
    return bst_search(node->l, key);
  return bst_search(node->r, key);
}

bst_node_t *bst_nonrecurs_search(bst_node_t *node, int key) {
  if (!node)
    return NULL;
  if (node->key == key)
    return node;

  bst_node_t *cur = node;
  while (cur) {
    if (cur->key == key)
      return cur;
    if (key < cur->key) {
      cur = cur->l;
    } else {
      cur = cur->r;
    }
  }
  return NULL;
}

// preorder traversal (DFS)
void pre_traverse(bst_node_t *node) {
  if (!node)
    return;
  printf("%d %d\n", node->key, node->n);
  pre_traverse(node->l);
  pre_traverse(node->r);
}

static inline int node_size(bst_node_t *node) { return node ? node->n : 0; }

/*In right rotation-
 * old root goes to the right
 * new root becomes the left node of old root*/
bst_node_t *bst_right_rot(bst_node_t *root) {
  bst_node_t *new_root = root->l;
  root->l = new_root->r;
  new_root->n = root->n;
  root->n = 1 + node_size(root->l) + node_size(root->r);
  new_root->r = root;
  return new_root;
}

/*In left rotation-
 * old root goes to the left
 * new root becomes right node of the old root*/
bst_node_t *bst_left_rot(bst_node_t *root) {
  bst_node_t *new_root = root->r;
  root->r = new_root->l;
  new_root->n = root->n;
  root->n = 1 + node_size(root->l) + node_size(root->r);
  new_root->l = root;
  return new_root;
}

/*Insert in the root of the tree. It requires rotation in every recursive iteration.*/
bst_node_t *bst_insert_root(bst_node_t *root, int key) {
  if (!root) {
    bst_node_t *node = malloc(sizeof(bst_node_t));
    node->key = key;
    node->l = node->r = NULL;
    return node;
  }
  if (key < root->key) {
    root->l = bst_insert_root(root->l, key);
    root = bst_right_rot(root);
  } else {
    root->r = bst_insert_root(root->r, key);
    root = bst_left_rot(root);
  }
  bst_ctx.count++;
  return root;
}

/*Select the kth smallest/largest*/
typedef enum tt { smallest, largest } bst_select_type;
bst_node_t *bst_select(bst_node_t *node, int k, bst_select_type type) {
  int t;
  if (!node)
    return NULL;
  t = (node->l == NULL) ? 0 : node->l->n;
  if (t > k)
    return bst_select((type == smallest ? node->l : node->r), k, type);
  if (t < k)
    return bst_select((type == smallest ? node->r : node->l), k - t - 1, type);
  return node;
}

/*Places the selected node on the root.*/
bst_node_t *bst_part(bst_node_t *node, int k) {
  int t;
  if (!node)
    return NULL;
  t = (node->l == NULL) ? 0 : node->l->n;
  if (t > k) {
    node->l = bst_part(node->l, k);
    node = bst_right_rot(node);
  }
  if (t < k) {
    node->r = bst_part(node->r, k - t - 1);
    node = bst_left_rot(node);
  }
  return node;
}

int main(void) {
  bst_node_t *root = bst_init();
  // root = bst_nonrecurs_insert(root, 20);
  // root = bst_nonrecurs_insert(root, 19);
  // root = bst_nonrecurs_insert(root, 25);
  // root = bst_nonrecurs_insert(root, 30);
  // root = bst_nonrecurs_insert(root, 5);
  // root = bst_nonrecurs_insert(root, 9);

  // root = bst_insert_root(root, 25);
  // root = bst_insert_root(root, 30);
  // root = bst_insert_root(root, 13);

  root = bst_insert(root, 20);
  root = bst_insert(root, 18);
  root = bst_insert(root, 25);
  root = bst_insert(root, 7);
  root = bst_insert(root, 22);
  root = bst_insert(root, 30);
  root = bst_insert(root, 6);
  root = bst_insert(root, 9);
  root = bst_insert(root, 19);
  //
  // int arr[100000];
  // for (int i = 0; i < 100000; i++)
  //   arr[i] = i;
  // for (int i = 99999; i > 0; i--) {
  //   int j = rand() % (i + 1);
  //   int temp = arr[i];
  //   arr[i] = arr[j];
  //   arr[j] = temp;
  // }
  // for (int i = 0; i < 100000; i++) {
  //   root = bst_nonrecurs_insert(root, arr[i]);
  // }

  pre_traverse(root);
  // root = bst_left_rot(root);
  // root = bst_right_rot(root);
  printf("\n");
  // pre_traverse(root);

  // printf("%d\n", bst_ctx.count);

  // bst_node_t *tar = bst_nonrecurs_search(root, 1248);
  // printf("\ntar: %d\n", tar->key);

  // root = bst_part(root, 3);
  // pre_traverse(root);

  bst_select_type select = largest;
  printf("select: %d\n", bst_select(root, 0, select)->key);

  return 0;
}
