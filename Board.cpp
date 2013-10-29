#include "Board.h"
#include <iostream>

int Board::print() {
  for(int i = 0; i < sizeY; i++) {
    for(int j = 0; j < sizeX; j++) {
      #ifdef DEBUG
      std::cout << int(data[i*sizeX+j]) << ' ';
      #else
      std::cout << (data[i*sizeX+j] == 1 ? '#' : '-') << ' ';
      #endif
    }
    std::cout << "\n";
  }
  return 0;
}

int Board::run(Rule *r) {
  memcpy(data, r->compute(sizeX ,sizeY, data),sizeX*sizeY);
  return 0;
}
