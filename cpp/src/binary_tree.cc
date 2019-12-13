#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

struct Node;
using NP = Node*;
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

T update_tree_(Node& n, T dep)
{
  T hl = 0, hr = 0;
  T dig = 0;
  if (n.l != nullptr) {
    S[n.l->id] = n.r;
    hl = update_tree_(*n.l, dep + 1) + 1;
    ++dig;
  }

  if (n.r != nullptr) {
    S[n.r->id] = n.l;
    hr = update_tree_(*n.r, dep + 1) + 1;
    ++dig;
  }

  Dep[n.id] = dep;
  Dig[n.id] = dig;
  return H[n.id] = (hl > hr) ? hl : hr;
}

NP update_tree(T n)
{
  auto* root =
    std::find_if(Tree, Tree + n, [](Node& n) { return n.p == nullptr; });
  update_tree_(*root, 0);
  return root;
}

inline T get_id(NP n) { return (n != nullptr) ? n->id : NIL; }

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

  update_tree(n);

  for (T i = 0; i < n; ++i) {
    auto& x = Tree[i];
    printf(
      "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = "
      "%d, ",
      i, get_id(x.p), get_id(S[i]), Dig[i], Dep[i], H[i]);

    if (x.p == nullptr) {
      printf("root");
    } else if (x.l == nullptr && x.r == nullptr) {
      printf("leaf");
    } else {
      printf("internal node");
    }

    // if (i != n - 1) {
    printf("\n");
    // }
  }

  return 0;
}
