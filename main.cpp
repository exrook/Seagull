#include <iostream>
#include "Rule.h"
#include "Board.h"
#include "Cgol.h"

int main(int argc, char *argv[]) {
  Board lol(5,5);
  lol.print();
  lol.run(new Cgol());
}
