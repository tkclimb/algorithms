#include <cstdio>
#include <vector>

constexpr const unsigned MAX_N = 20;
constexpr const unsigned MAX_Q = 200;
constexpr const unsigned MAX_AN = 2000;
constexpr const unsigned MAX_M = 2000;

using T = int;
using VT = std::vector<T>;

T N;
T M;
VT V;

bool exhaustive_search(const T i, const T m)
{
  if (m == 0) {
    return true;
  } else if (i >= N) {
    return false;
  } else {
    return exhaustive_search(i + 1, m) || exhaustive_search(i + 1, m - V[i]);
  }
}

int main(int argc, char const* argv[])
{
  scanf("%d", &N);
  // printf("-- N = %d --\n", N);
  V = VT(N);

  for (auto& x : V) { scanf("%d", &x); }
  // for (auto& x : v) { printf("%d\n", x); }

  scanf("%d", &M);
  // printf("-- M = %d --\n", M);

  for (size_t i = 0; i < M; i++) {
    T d;
    scanf("%d", &d);
    bool res = exhaustive_search(0, d);
    if (res) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
