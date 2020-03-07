/* Given an array, finds the integer that appears an odd number of times (there will always be only one).*/

#include <vector>
#include <iostream>

int findOdd(const std::vector<int>& numbers)
{
  int x = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    x = x ^ numbers[i];
  }
  return x;
}
