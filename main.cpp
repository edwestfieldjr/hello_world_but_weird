#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
// required for usleep()

int main() {

  std::srand(std::time(nullptr));
  std::string target = "Hello world!";
  bool isRunning{true};
  char c;
  std::string ipt;
  unsigned int max_iterations;
  unsigned int total_cycles = 0;

  while (isRunning) {

    std::cout << std::string(255, '\n');
    // clear screen n both Windows and Mac/Linus sytems

    for (size_t i{}; i < target.size(); i++) {
      max_iterations = (std::rand() % 30) + 5;
      do {
        c = (std::rand() % 94) + 32;
        std::cout << "\b";
        usleep(50000);
        if (--max_iterations == 0) {
          std::cout << target[i] << std::flush;
          break;
        } else {
          std::cout << c << std::flush;
        }
        total_cycles++;
      } while (c != target[i]); //
      std::cout << char(32);
    }

    usleep(500000);
    std::cout << "\t\t (" << total_cycles << " cycles)..." << std::flush;
    usleep(1000000);
    std::cout << " replay? (y/N): ";
    std::getline(std::cin, ipt);

    if (!(ipt[0] == 'Y' || ipt[0] == 'y')) {
      isRunning = false;
    }

    ipt = "";
  }
  std::cout << std::endl;
  return 0;
}
