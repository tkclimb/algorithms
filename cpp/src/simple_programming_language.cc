#include <bits/stdc++.h>

#include <cstdlib>
#include <string>

bool is_num(const char c) { return '0' < c && c < '9'; }

bool is_op(const char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct Char
{
  float num;
  char op;
  bool is_op_;

  Char(const float x, bool is_op) : is_op_{is_op}
  {
    if (is_op) {
      op = static_cast<char>(x);
    } else {
      num = x;
    }
  }

  bool is_op() const { return is_op_; }
  bool is_num() const { return !is_op(); }
  std::string str() const
  {
    std::stringstream ss;
    if (is_op()) {
      ss << "Op(" << op << ")";
    } else {
      ss << "Num(" << num << ")";
    }
    return ss.str();
  }

  static Char Num(const float num) { return Char(num, false); }
  static Char Op(const char op) { return Char(static_cast<float>(op), true); }
};

Char eval(const Char op, const Char a, const Char b)
{
  float lhs = a.num;
  float rhs = b.num;
  float res;

  if (op.op == '+')
    res = lhs + rhs;
  else if (op.op == '-')
    res = lhs - rhs;
  else if (op.op == '*')
    res = lhs * rhs;
  else if (op.op == '/')
    res = lhs / rhs;
  else {
    std::cout << "invalid op: " << op.op << std::endl;
    std::exit(1);
  }

  return Char::Num(res);
}

int main()
{
  // const char* src = "+ 3 * 4 / 2 - 1 5";
  const char* src = "- 3 2";
  // std::cout << src << std::endl;
  // Program prog(src);

  std::stack<const Char> stack;

  int i = 0;
  while (const char c = src[i]) {
    if (c != ' ') {
      if (is_op(c)) {
        stack.push(Char::Op(c));
      } else if (is_num(c)) {
        float num = c - '0';
        stack.push(Char::Num(num));
      }
      printf("%c ", c);
    }
    ++i;
  }
  printf("\n");

  assert(!stack.empty()); // empty program given.

  while (stack.size() > 1) {
    Char first = stack.top();
    stack.pop();
    printf("pop(%s)\n", first.str().c_str());
    assert(first.is_num());

    Char second = stack.top();
    stack.pop();
    printf("pop(%s)\n", second.str().c_str());
    assert(second.is_num());

    Char op = stack.top();
    stack.pop();
    printf("pop(%s)\n", op.str().c_str());
    assert(op.is_op());

    Char ret = eval(op, second, first);
    stack.push(ret);
    printf("push(%s)\n", ret.str().c_str());
  }

  std::cout << "result: " << stack.top().num << std::endl;
  return 0;
}
