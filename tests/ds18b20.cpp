#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "dev/ds18b20/ds18b20.h"

void test_basic() {
  const std::string slaveid("ds18b20_slaveid");

  const std::string directory("/tmp/ds18b20_slaveid");
  const int dir_err =
      mkdir(directory.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  std::ostringstream oss;
  oss << directory << "/w1_slave";
  const std::string filename = oss.str();

  std::ofstream os;
  os.open(filename);
  os << "7c 01 4b 46 7f ff 04 10 09 : crc=09 YES" << std::endl;
  os << "7c 01 4b 46 7f ff 04 10 09 t=23750[/bash]" << std::endl;
  os.close();

  DS18B20 ds18b20(slaveid, "/tmp");
  assert(ds18b20.temperature() == 23.75);
}

int main(int, char**) { test_basic(); }
