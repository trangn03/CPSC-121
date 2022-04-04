#include <string>

#ifndef KANGAROO_H
#define KANGAROO_H

// Kangaroo class here.
class Kangaroo {
 private:
  std::string value_name;
  int value_count = 0;

 public:
  Kangaroo();
  explicit Kangaroo(std::string k);
  std::string GetName();
  void SetName(std::string n);
  void Bounce();
  int GetBounceCount();

 protected:
  void SetBounceCount(int s);
};

#endif  // KANGAROO_H
