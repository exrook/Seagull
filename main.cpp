#include <iostream>
#include "Rule.h"
#include "Board.h"
#include "Cgol.h"

char init[10][10] = \
{{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}};

int main(int argc, char *argv[]) {
  Board lol(10,10,(char**)&init);
  lol.print();
  for(int i = 0; i < 5; i++) {
    lol.run(new Cgol());
    std::cout << "Generation " << i << '\n';
    lol.print();
  }
}
