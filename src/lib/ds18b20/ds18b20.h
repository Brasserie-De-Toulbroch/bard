#pragma once

#include <string>

namespace bard {
class DS18B20 {
 public:
  DS18B20(const std::string &id,
          const std::string &path = "/sys/bus/w1/devices/");

  float temperature() const;

 private:
  std::string _path;
};
}
