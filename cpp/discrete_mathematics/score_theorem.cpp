#include <iostream>
#include <vector>

using namespace std;
using T = int;
using V = vector<T>;

void f(const V &v)
{
  auto last = v.back();

  for (const auto &u : v)
  {
    std::cout << u << ",";
  }
  std::cout << std::endl;

  T n = v.size() - 1;
  V y(n - 1);
  T count = 0;
  y.push_back(1);

  for (size_t i = 0; i < n; i++)
  {
    auto x = v[i];
    if (i < n - last)
    {
      y.push_back(x);
    }
    else
    {
      y.push_back(x - 1);
    }

    if (x % 2 != 0)
    {
      ++count;
    }
  }

  if (count % 2 != 0)
  {
    return;
  }
  else
  {
    f(y);
  }
}

int main()
{
  V data{1, 1, 2, 2, 2, 3, 3};
  f(data);
}