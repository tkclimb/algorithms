#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> nums = {3, 4, 5, 1, 2};

  if (nums.size() == 0) {
    cout << "here" << endl;
    return 0;
  }

  int l = 0;
  int u = nums.size() - 1;
  int y;

  while (u > l + 1) {
    int m = (l + u) / 2;
    if (nums[l] < nums[m]) {
      y = nums[m];
      l = m;
    } else {
      y = nums[m];
      u = m;
    }
  }
  cout << "y: " << y << endl;
}