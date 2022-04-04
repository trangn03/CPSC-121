#include "minimum.h"

int IndexOfMinWithVector(std::vector<double> input) {
  // TODO
  if (input.size() == 0) {
    return -1;
  }
  double min = input[0];
  int track = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] < min) {
      min = input[i];
      track = i;
    }
  }
  return track;
}

int IndexOfMinWithArray(double input[], int size) {
  // TODO
  if (size == 0) {
    return -1;
  }
  double min = input[0];
  int track = 0;
  for (int i = 0; i < size; i++) {
    if (input[i] < min) {
      min = input[i];
      track = i;
    }
  }
  return track;
}

int IndexOfMinWithPointer(double* input, int size) {
  // TODO
  if (size == 0) {
    return -1;
  }
  double* min = input;
  int track = 0;
  for (int i = 1; i < size; i++) {
    if (*(input + i) < *min) {
      *min = *(input + i);
      track = i;
    }
  }
  return track;
}
