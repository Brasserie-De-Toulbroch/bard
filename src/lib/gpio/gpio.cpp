#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <gpio/gpio.h>

using namespace bard;

GPIO::GPIO(const int number, const std::string &path)
    : _number(number), _path(path) {
  export_gpio();
}

void GPIO::export_gpio() {
  std::ostringstream ss;
  ss << _path << "/export";

  FILE *export_file = fopen(ss.str().c_str(), "w");

  if (export_file != NULL) {
    fprintf(export_file, "%d", _number);
  }

  fclose(export_file);
}

void GPIO::set_value(const bool value) const {
  std::ostringstream ss;
  ss << _path << "/gpio" << _number << "/value";

  FILE *value_file = fopen(ss.str().c_str(), "w");

  if (value_file != NULL) {
    fprintf(value_file, "%d", value);
  }

  fclose(value_file);
}

bool GPIO::value() const {
  std::ostringstream ss;
  ss << _path << "/gpio" << _number << "/value";

  std::ifstream is;
  is.open(ss.str());
  bool value;
  if (is) {
    is >> value;
  }
  is.close();

  return value;
}

void GPIO::set_direction(const Direction direction) {
  std::ostringstream ss;
  ss << _path << "/gpio" << _number << "/direction";

  std::string value = "in";
  if (direction == Direction::OUT) {
    value = "out";
  }

  FILE *file = fopen(ss.str().c_str(), "w");

  if (file != NULL) {
    fprintf(file, "%s", value.c_str());
  }

  fclose(file);
}

GPIO::Direction GPIO::direction() const {
  std::ostringstream ss;
  ss << _path << "/gpio" << _number << "/direction";

  std::ifstream is;
  is.open(ss.str());
  std::string value;
  if (is) {
    is >> value;
  }
  is.close();

  GPIO::Direction direction = Direction::IN;
  if (value == "out") {
    direction = Direction::OUT;
  }

  return direction;
}
