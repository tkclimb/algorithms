#include <cstdlib>
#include <iostream>
#include <vector>

bool is_num(const char c) { return c >= '0' && c <= '9'; }

bool is_alpha(const char c) { return c >= 'A' && c <= 'Z'; }

bool is_valid(const char c) { return is_num(c) || is_alpha(c); }

int c2num(const char c)
{
  assert(is_num(c));
  return c - '0';
}

int num = 0;

std::vector<char> decode_runlength(const char* input)
{
  std::vector<char> output;
  char last = '0';
  char current = '\0';

  for (int i = 0; input[i] != '\0'; ++i) {
    current = input[i];
    assert(is_valid(current));

    if (i == 0) {
      last = current;
      continue;
    }

    if (is_alpha(last)) {
      // alpha -> alpha
      if (is_alpha(current)) {
        output.push_back(last);
        // alpha -> num
      } else if (is_num(current)) {
        output.push_back(last);
      }

    } else if (is_num(last)) {
      // num -> alpha
      if (is_alpha(current)) { // repeat current and reset num and num_cout
        num = 10 * num + c2num(last);
        assert(num > 2);
        for (int i = 0; i < num - 1; ++i) { output.push_back(current); }
        num = 0;
        // alpha -> alpha
      } else if (is_num(current)) { // increment num
        num = 10 * num + c2num(last);
      }
    }

    last = current;
  }

  if (is_alpha(current)) {
    output.push_back(current);
  }

  return output;
}

int main()
{
  // const char* input = "3C";
  const char* input = "3AB12CDD";
  printf("input:  ");
  for (int i = 0; input[i] != '\0'; ++i) { printf("%c", input[i]); }
  printf("\n");
  printf("output: ");
  auto output = decode_runlength(input);
  for (const auto& c : output) { printf("%c", c); }
  return 0;
}
