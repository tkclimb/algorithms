#include <chrono>
#include <cstdio>
#include <functional>
#include <list>
#include <vector>

using T = int;
using S = std::list<T>;
using Time = double;
namespace ch = std::chrono;
using F = std::function<void()>;

T count = 0;
T res = 0;

void comb(S& s, T i, T n, T k)
{
  T r = i + k;

  if (k <= 0) {
    ++res;
    return;
  } else {
    for (size_t j = i; j < n - k + 1; ++j) {
      ++count;
      s.push_back(j + 1); // this index should start from 1
      comb(s, j + 1, n, k - 1);
      s.pop_back();
    }
  }
}

Time measure_time(F f)
{
  ch::system_clock::time_point start, end;
  start = ch::system_clock::now();
  f();
  end = ch::system_clock::now();
  return ch::duration_cast<ch::milliseconds>(end - start).count();
}

int main(int argc, char const* argv[])
{
  T n, k;
  S s;
  scanf("%d %d", &n, &k);
  printf("-----\n");
  auto t = measure_time([&]() { comb(s, 0, n, k); });
  printf("count: %d, res: %d, time: %lf [msec]\n", count, res, t);
  return 0;
}