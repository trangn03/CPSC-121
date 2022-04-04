#include "kangaroo.h"

#ifndef JOEY_H
#define JOEY_H

// Joey class here
class Joey : public Kangaroo {
 private:
  std::string value_name;

 public:
  Joey();
  explicit Joey(std::string y);
};

#endif  // JOEY_H
