#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

struct Node;
using NP = Node*;
using V = std::vector<Node*>;
using T = int;
constexpr T NIL = -1;
constexpr T MAX_N = 500010;

struct Node
{
  T id = NIL;
  NP l = nullptr;
  NP r = nullptr;
  NP p = nullptr;
};

static Node* root = nullptr;

void insert(T id)
{
  Node* p = nullptr;
  Node* x = root;
  Node* n = new Node;
  n->id = id;

  while (x != nullptr) {
    p = x;
    if (id < x->id) {
      x = x->l;
    } else {
      x = x->r;
    }
  }

  n->p = p;
  if (p == nullptr) {
    root = n;
  } else {
    if (n->id < p->id) {
      p->l = n;
    } else {
      p->r = n;
    }
  }
}

void tree_walk_in(Node* n)
{
  if (n == nullptr) {
    return;
  }

  if (n->l != nullptr) {
    tree_walk_in(n->l);
  }
  printf(" %d", n->id);
  if (n->r != nullptr) {
    tree_walk_in(n->r);
  }
}

void tree_walk_pre(Node* n)
{
  if (n == nullptr) {
    return;
  }

  printf(" %d", n->id);
  if (n->l != nullptr) {
    tree_walk_pre(n->l);
  }
  if (n->r != nullptr) {
    tree_walk_pre(n->r);
  }
}

int main(int argc, char const* argv[])
{
  T n;
  scanf("%d", &n);

  for (T i = 0; i < n; ++i) {
    char cmd[20];
    scanf("%s", cmd);

    if (!std::strcmp(cmd, "insert")) {
      T id;
      scanf("%d", &id);
      insert(id);
    } else {
      tree_walk_in(root);
      printf("\n");
      tree_walk_pre(root);
      printf("\n");
    }
  }

  return 0;
}