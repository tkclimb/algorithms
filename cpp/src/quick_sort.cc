#include <cstdio>
#include <string>
#include <vector>

using T = int;
using V = std::vector<T>;
constexpr T MAX_S = 1000000000 + 1;

struct Card
{
  char s;
  T v;
};
using CS = std::vector<Card>;

void merge(CS& cs, const T left, const T mid, const T right)
{
  const T n1 = mid - left;
  const T n2 = right - mid;
  Card L[n1 + 1];
  Card R[n2 + 1];

  for (size_t i = 0; i < n1; ++i) {
    L[i].s = cs[left + i].s;
    L[i].v = cs[left + i].v;
  }
  for (size_t i = 0; i < n2; ++i) {
    R[i].s = cs[mid + i].s;
    R[i].v = cs[mid + i].v;
  }
  L[n1] = Card{' ', MAX_S};
  R[n2] = Card{' ', MAX_S};

  T il = 0;
  T ir = 0;
  for (size_t i = left; i < right; i++) {
    if (L[il].v <= R[ir].v) {
      cs[i] = L[il++];
    } else {
      cs[i] = R[ir++];
    }
  }
}

void merge_sort(CS& cs, const T left, const T right)
{
  if (right - left > 1) {
    T mid = (left + right) / 2;
    merge_sort(cs, left, mid);
    merge_sort(cs, mid, right);
    merge(cs, left, mid, right);
  }
}

T partition(CS& cs, const T p, const T r)
{
  T b = cs[r].v;
  T j = p;

  for (int i = p; i < r; ++i) {
    if (cs[i].v <= b) {
      std::swap(cs[i], cs[j]);
      ++j;
    }
  }
  std::swap(cs[j], cs[r]);

  return j;
}

void quick_sort(CS& cs, const T l, const T r)
{
  if (l < r) {
    T piv = partition(cs, l, r);
    quick_sort(cs, l, piv - 1);
    quick_sort(cs, piv + 1, r);
  }
}

int main(int argc, char const* argv[])
{
  T n;
  scanf("%d", &n);
  CS cs(n);

  for (size_t i = 0; i < n; ++i) {
    T v;
    char s[5];
    scanf("%s %d", s, &v);
    cs[i] = Card{s[0], v};
  }
  CS cs2 = cs;

  quick_sort(cs, 0, n - 1);
  merge_sort(cs2, 0, n);

  bool match = true;
  for (size_t i = 0; i < n; ++i) {
    if (cs[i].s != cs2[i].s || cs[i].v != cs2[i].v) {
      match = false;
    }
  }

  if (match) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  for (size_t i = 0; i < n; ++i) {
    auto& c = cs[i];
    printf("%c %d\n", c.s, c.v);
  }

  return 0;
}