#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

struct Node;
using NP = Node*;
using V = std::vector<Node*>;
using T = int;
constexpr T NIL = -1;
constexpr T MAX_N = 26;

struct Node
{
  T id = NIL;
  NP l = nullptr;
  NP r = nullptr;
  NP p = nullptr;
};

static Node Tree[MAX_N];
static T Dep[MAX_N];
static T Dig[MAX_N];
static T H[MAX_N];
static NP S[MAX_N];

void tree_walk(Node* n, V& pre_tree, V& in_tree, V& post_tree)
{
  pre_tree.push_back(n);
  if (n->l != nullptr) {
    tree_walk(n->l, pre_tree, in_tree, post_tree);
  }
  in_tree.push_back(n);
  if (n->r != nullptr) {
    tree_walk(n->r, pre_tree, in_tree, post_tree);
  }
  post_tree.push_back(n);
}

int main(int argc, char const* argv[])
{
  T n;
  scanf("%d", &n);

  for (T i = 0; i < n; ++i) {
    T id, l, r;
    scanf("%d %d %d", &id, &l, &r);
    auto& x = Tree[id];
    x.id = id;

    if (l != NIL) {
      auto& nl = Tree[l];
      x.l = &nl;
      nl.p = &x;
    }

    if (r != NIL) {
      auto& nr = Tree[r];
      x.r = &nr;
      nr.p = &x;
    }
  }

  V pre_tree;
  V in_tree;
  V post_tree;

  auto* root =
    std::find_if(Tree, Tree + n, [](Node& n) { return n.p == nullptr; });
  tree_walk(root, pre_tree, in_tree, post_tree);

  int i = 0;

  printf("Preorder\n ");
  for (auto* x : pre_tree) {
    printf("%d", x->id);
    if (i != n - 1) {
      printf(" ");
    }
    ++i;
  }
  printf("\n");
  i = 0;

  printf("Inorder\n ");
  for (auto* x : in_tree) {
    printf("%d", x->id);
    if (i != n - 1) {
      printf(" ");
    }
    ++i;
  }
  printf("\n");
  i = 0;

  printf("Postorder\n ");
  for (auto* x : post_tree) {
    printf("%d", x->id);
    if (i != n - 1) {
      printf(" ");
    }
    ++i;
  }
  printf("\n");

  return 0;
}