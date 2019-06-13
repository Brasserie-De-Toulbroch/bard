#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "gpio/gpio.h"

void test_basic() {
  const int gpio_number = 9;

  // create directory
  std::string directory("/tmp/gpio/");
  mkdir(directory.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  // create export file
  std::ostringstream oss;
  oss << directory << "/export";
  std::string filename = oss.str();

  std::ofstream os;
  os.open(filename);
  os.close();

  // init gpio
  bard::GPIO gpio(gpio_number, "/tmp/gpio");

  // check export file content
  std::ifstream is;
  is.open(filename);
  int number;
  if (is) {
    is >> number;
  }
  is.close();

  assert(number == 9);

  // create gpio 9 directory
  directory = "/tmp/gpio/gpio9/";
  mkdir(directory.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  // create value file
  oss.str("");
  oss.clear();
  oss << directory << "/value";
  filename = oss.str();

  os.open(filename);
  os.close();

  // create direction file
  oss.str("");
  oss.clear();
  oss << directory << "/direction";
  filename = oss.str();

  os.open(filename);
  os.close();

  // test low value
  gpio.set_value(false);

  oss.str("");
  oss.clear();
  oss << directory << "/value";
  filename = oss.str();

  is.open(filename);
  if (is) {
    is >> number;
  }
  assert(number == 0);
  is.close();

  assert(gpio.value() == false);

  // test high value
  gpio.set_value(true);

  oss.str("");
  oss.clear();
  oss << directory << "/value";
  filename = oss.str();

  is.open(filename);
  if (is) {
    is >> number;
  }
  assert(number == 1);
  is.close();

  assert(gpio.value() == true);

  // test in direction
  gpio.set_direction(bard::GPIO::IN);

  oss.str("");
  oss.clear();
  oss << directory << "/direction";
  filename = oss.str();

  is.open(filename);
  std::string direction;
  if (is) {
    is >> direction;
  }
  assert(direction == "in");
  is.close();

  assert(gpio.direction() == bard::GPIO::IN);

  // test out direction
  gpio.set_direction(bard::GPIO::OUT);

  oss.str("");
  oss.clear();
  oss << directory << "/direction";
  filename = oss.str();

  is.open(filename);
  if (is) {
    is >> direction;
  }
  assert(direction == "out");
  is.close();

  assert(gpio.direction() == bard::GPIO::OUT);
}

int main(int, char**) { test_basic(); }
