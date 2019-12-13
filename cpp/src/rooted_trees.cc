#include <algorithm>
#include <cstdio>
#include <list>
#include <vector>

struct Node;

using T = int;
using L = std::list<T>;
using Tree = std::vector<Node>;
constexpr T NIL = -1;

struct Node
{
  L children;
  T parent;
  T depth;
};

void calc_depth(Node& n, Tree& t, T depth)
{
  n.depth = depth;
  for (auto c : n.children) { calc_depth(t[c], t, depth + 1); }
}

int main(int argc, char const* argv[])
{
  T n;
  scanf("%d", &n);
  Tree t(n);
  for (auto& x : t) {
    x.parent = NIL;
    x.depth = 0;
  }

  for (T i = 0; i < n; ++i) {
    T id, k;
    scanf("%d %d", &id, &k);
    auto& x = t[id];

    for (T j = 0; j < k; ++j) {
      T id_c;
      scanf("%d", &id_c);
      auto& c = t[id_c];
      c.parent = id;
      x.children.push_back(id_c);
    }
  }

  Node* root;
  for (auto& x : t) {
    if (x.parent == NIL) {
      root = &x;
      break;
    }
  }
  calc_depth(*root, t, 0);

  for (T i = 0; i < n; ++i) {
    auto& x = t[i];
    printf("node %d: parent = %d, depth = %d, ", i, x.parent, x.depth);

    if (x.parent == NIL) {
      printf("root, ");
    } else if (x.children.size() == 0) {
      printf("leaf, ");
    } else {
      printf("internal node, ");
    }

    printf("[");
    auto it = x.children.begin();
    for (T j = 0; j < x.children.size(); ++j) {
      printf("%d", *it);
      if (j != x.children.size() - 1) {
        printf(", ");
      }
      ++it;
    }
    printf("]\n");
  }

  return 0;
}
