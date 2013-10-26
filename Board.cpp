#include "Board.h"
#include <iostream>

int Board::print() {
  for(int i = 0; i < sizeX; i++) {
    for(int j = 0; j < sizeY; j++) {
      printf("%d ",data[i*sizeY+j]);
    }
    std::cout << "\n";
  }
  return 0;
}

int Board::run(Rule *r) {
  data = r->compute(sizeX ,sizeY, data);
}
