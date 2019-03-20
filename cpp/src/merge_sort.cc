#include <cstdio>
#include <limits>
#include <vector>

using T = int;
using VT = std::vector<T>;

constexpr T MAX_N = 500000;
constexpr T MAX_S = 1000000000 + 1;

T count = 0;

void merge(VT& S, const T left, const T mid, const T right)
{
  const T n1 = mid - left;
  const T n2 = right - mid;
  T L[n1 + 1];
  T R[n2 + 1];

  for (size_t i = 0; i < n1; ++i) { L[i] = S[left + i]; }
  for (size_t i = 0; i < n2; ++i) { R[i] = S[mid + i]; }
  L[n1] = MAX_S;
  R[n2] = MAX_S;

  T il = 0;
  T ir = 0;
  for (size_t i = left; i < right; i++) {
    ++count;
    if (L[il] <= R[ir]) {
      S[i] = L[il++];
    } else {
      S[i] = R[ir++];
    }
  }
}

void merge_sort(VT& S, const T left, const T right)
{
  if (right - left > 1) {
    T mid = (left + right) / 2;
    merge_sort(S, left, mid);
    merge_sort(S, mid, right);
    merge(S, left, mid, right);
  }
}

int main(int argc, char const* argv[])
{
  int n;
  scanf("%d", &n);

  VT S(n);
  for (auto& x : S) { scanf("%d", &x); }

  merge_sort(S, 0, n);
  for (size_t i = 0; i < S.size(); ++i) {
    printf("%d", S[i]);
    if (i != S.size() - 1) {
      printf(" ");
    }
  }

  printf("\n%d\n", count);
  return 0;
}
