#include <bits/stdc++.h>

#include <cstdlib>
#include <string>

bool is_num(const char c) { return '0' < c && c < '9'; }

bool is_op(const char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::tuple<float, int> eval(const std::vector<char>& src, const int loc)
{
  char c = src[loc];

  if (is_num(c)) {
    // skip number
    return {float(c - '0'), loc + 1};

  } else if (is_op(c)) {
    const auto& [lhs, lhs_loc] = eval(src, loc + 1); // skip op
    const auto& [rhs, rhs_loc] = eval(src, lhs_loc);

    float res;
    if (c == '+')
      res = lhs + rhs;
    else if (c == '-')
      res = lhs - rhs;
    else if (c == '*')
      res = lhs * rhs;
    else if (c == '/')
      res = lhs / rhs;

    return {res, rhs_loc};

  } else {
    std::exit(1);
  }
}

int main()
{
  const char* src = "+ 3 / * 4 2 - 1 5";
  // const char* src = "+ 3 * 4 / 2 - 1 5";

  std::vector<char> input;

  for (int i = 0; src[i] != '\0'; ++i) {
    char c = src[i];
    if (c != ' ') {
      input.push_back(c);
      printf("%c ", c);
    }
  }
  printf("\n");

  const auto& [res, loc] = eval(input, 0);
  std::cout << "result: " << res << std::endl;

  return 0;
}
