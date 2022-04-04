#include <iomanip>
#include <iostream>
#ifndef UTENSILS_H
#define UTENSILS_H
class Food {
  std::string name_;
  double mass_;

 public:
  Food() : Food("Apple Pie", 0) {}
  Food(std::string name, double mass) : name_(name), mass_(mass) {}
  void set_name(const std::string name) { name_ = name; }
  void set_mass(double mass) { mass_ = mass; }
  std::string name() { return name_; }
  double mass() { return mass_; }
  void eat(double bite);
  void print();
};
class Utensil {
  double size_;
  std::string color_;

 public:
  Utensil() : Utensil(0, "silver") {}
  Utensil(double size, std::string color) : size_(size), color_(color) {}
  void set_size(double size) { size_ = size; }
  void set_color(std::string color) { color_ = color; }
  double size() { return size_; }
  std::string color() { return color_; }
  void use(Food &food) {}
};
class Spoon : public Utensil {
  double bite_size_;

 public:
  Spoon() : Spoon(0, "silver", 0) {}
  Spoon(double size, std::string color, double bite_size)
      : Utensil(size, color) {
    set_size(size);
    set_color(color);
    bite_size_ = bite_size;
  }
  void set_bite_size(double bite_size) { bite_size_ = bite_size; }
  double bite_size() { return bite_size_; }
  void use(Food &food) { food.eat(bite_size_); }
};
#endif
