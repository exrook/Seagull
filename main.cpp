#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Rule.h"
#include "Board.h"
#include "Cgol.h"

char init[10][10] = \
{{0,1,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,0,1,0},
{1,1,1,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}};

int main(int argc, char *argv[]) {
  bool pretty = false;
  int loop = 10;
  int prettyt = 1000;
  for(int i=1; i < argc; i++) {
    if (std::string(argv[i]) == "-p") {
      pretty = true;
      try {
        prettyt = std::stoi(argv[i+1]);
      } catch (...) {}
    } else if (std::string(argv[i]) == "-c") {
      try {
        loop = std::stoi(argv[i+1]);
      } catch (...) {
        std::cout << "Invalid Options\n";
        return 0;
      }
    }
  }
  
  Board lol(10,10,(char**)&init);
  if (pretty) lol.print();
  Rule *sd = new Cgol();
  for(int i = 0; i < loop; i++) {
    lol.run(sd);
    if (pretty) {
      std::cout << "Generation " << i << '\n';
      lol.print();
      std::this_thread::sleep_for( std::chrono::milliseconds(prettyt));
    }
  }
  if (!pretty) lol.print();
}
