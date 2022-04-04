#ifndef CAT_H
#define CAT_H

// TODO: Place your Cat class and CreateKitty function here.
#include <memory>

class Cat {
 private:
  int track;
  std::string name_;

 public:
  ~Cat();
  void SetName(std::string name);
  std::string GetName() const;
};
std::unique_ptr<Cat> CreateKitty(std::string k);
#endif  // CAT_H
