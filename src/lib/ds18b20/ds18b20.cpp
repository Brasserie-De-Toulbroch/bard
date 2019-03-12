#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <ds18b20/ds18b20.h>

using namespace bard;

DS18B20::DS18B20(const std::string &id, const std::string &path) {
  std::ostringstream ss;
  ss << path << "/" << id << "/w1_slave";
  _path = ss.str();
}

float DS18B20::temperature() const {
  float temperature = -1.0;

  std::ifstream infile;
  infile.open(_path);
  if (infile) {
    std::string line;
    while (std::getline(infile, line)) {
      const std::size_t idx = line.find("t=");
      if (idx != std::string::npos) {
        const std::string temp = line.substr(idx + 2, 5);
        temperature = std::stof(temp.c_str()) / 1000;
        break;
      }
    }
    infile.close();
  }

  return temperature;
}
