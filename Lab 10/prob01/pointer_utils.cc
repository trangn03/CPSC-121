#include "pointer_utils.h"

#include <iostream>
#include <string>
#include <vector>

void Negate(bool* value) { *value = !(*value); }

void Increment(int* number) { *number += 1; }

double ComputeSum(double* first, double* second) { return *first + *second; }

void Swap(int* first, int* second) {
  int swap = *first;
  *first = *second;
  *second = swap;
}

void MakeSus(std::string* player) { *player = *player + " is sus"; }

std::string* GetLongestString(std::vector<std::string>* strings) {
  std::string* ptr = &(strings->front());
  for (auto& string : *strings) {
    if (string.size() > ptr->size()) {
      ptr = &(string);
    }
  }
  return ptr;
}
