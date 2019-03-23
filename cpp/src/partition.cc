#include <cstdio>
#include <vector>

using T = int;
using V = std::vector<T>;

T partition(V& v, const T p, const T r)
{
  T b = v[r];
  T j = p;

  for (int i = p; i < r; ++i) {
    if (v[i] <= b) {
      // printf("swap [%d](%d) and [%d](%d)\n", i, v[i], j, v[j]);
      std::swap(v[i], v[j]);
      ++j;
    }
  }
  std::swap(v[j], v[r]);

  return j;
}

int main(int argc, char const* argv[])
{
  T n;
  scanf("%d", &n);
  V v(n);
  for (auto& x : v) { scanf("%d", &x); }

  T j = partition(v, 0, n - 1);

  for (int i = 0; i < v.size(); ++i) {
    if (i == j) {
      printf("[%d]", v[i]);
    } else {
      printf("%d", v[i]);
    }

    if (i != v.size() - 1) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}
