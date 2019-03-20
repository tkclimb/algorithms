#include <cmath>
#include <cstdio>

using T = int;
using F = double;

constexpr T MIN_N = 0;
constexpr T MAX_N = 6;
constexpr F XS = 0;
constexpr F XE = 100;
constexpr F YS = 0;
constexpr F YE = YS;

typedef struct Point
{
  F x;
  F y;
} P;

inline void pprint(const P& p) { printf("%.8f %.8f\n", p.x, p.y); }

void koch(const T n, const P& a, const P& b)
{
  if (n == 0) {
    return;
  }

  constexpr F th = M_PI / 3.0;

  P s, t, u;

  s.x = (2.0 / 3.0) * a.x + (1.0 / 3.0) * b.x;
  s.y = (2.0 / 3.0) * a.y + (1.0 / 3.0) * b.y;
  t.x = (1.0 / 3.0) * a.x + (2.0 / 3.0) * b.x;
  t.y = (1.0 / 3.0) * a.y + (2.0 / 3.0) * b.y;

  F x = t.x - s.x;
  F y = t.y - s.y;
  u.x = std::cos(th) * x - std::sin(th) * y + s.x;
  u.y = std::sin(th) * x + std::cos(th) * y + s.y;

  koch(n - 1, a, s);
  pprint(s);
  koch(n - 1, s, u);
  pprint(u);
  koch(n - 1, u, t);
  pprint(t);
  koch(n - 1, t, b);
}

int main(int argc, char const* argv[])
{
  P a, b;
  T n;

  scanf("%d", &n);

  a.x = XS;
  a.y = YS;
  b.x = XE;
  b.y = YE;

  pprint(a);
  koch(n, a, b);
  pprint(b);

  return 0;
}
