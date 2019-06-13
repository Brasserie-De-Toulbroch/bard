#pragma once

#include <string>

namespace bard {
class GPIO {
 public:
  enum Direction { IN, OUT };

  GPIO(int number, const std::string &path = "/sys/class/gpio/");

  void set_value(bool value) const;

  bool value() const;

  void set_direction(Direction direction);

  Direction direction() const;

 private:
  void export_gpio();

  // void unexport();

  std::string _path;
  const int _number;
};
}  // namespace bard
