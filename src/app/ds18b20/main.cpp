#include <getopt.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include <ds18b20/ds18b20.h>

int again = 1;

void signals_handler(int signal_number) { again = 0; }

int main(int argc, char** argv) {
  // init signal handler
  struct sigaction action;

  action.sa_handler = signals_handler;
  sigemptyset(&(action.sa_mask));
  sigaction(SIGQUIT, &action, NULL);
  sigaction(SIGINT, &action, NULL);

  // parse command line options
  int opt = 0;
  std::string slaveid;

  static struct option long_options[] = {{"slaveid", required_argument, 0, 'i'},
                                         {0, 0, 0, 0}};

  int long_index = 0;
  while ((opt = getopt_long(argc, argv, "i:", long_options, &long_index)) !=
         -1) {
    switch (opt) {
      case 'i':
        slaveid = std::string(optarg);
        break;
      default:
        exit(EXIT_FAILURE);
    }
  }

  if (slaveid.empty()) {
    return 1;
  }

  // init device
  bard::DS18B20 device(slaveid);

  // print data
  while (again) {
    std::cout << "Temperature: " << device.temperature() << std::endl;
    sleep(1);
  }

  return 0;
}
