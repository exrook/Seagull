#include "Board.h"
#include <iostream>

int Board::print() {
  for(int i = 0; i < sizeY; i++) {
    for(int j = 0; j < sizeX; j++) {
      std::cout << (data[i*sizeX+j] == 1 ? '#' : '-') << ' ';
      //std::cout << int(data[i*sizeX+j]) << ' ';
    }
    std::cout << "\n";
  }
  return 0;
}

int Board::run(Rule *r) {
  data = r->compute(sizeX ,sizeY, data);
  return 0;
}
