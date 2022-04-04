#include <iostream>
#include <string>

#include "progress_bar.h"

int main() {
  ProgressBar p;
  int s;
  std::cout << "Enter a progress bar speed: ";
  std::cin >> s;
  p.Initialize(s);
  // start the progress bar
  p.Start();
}
