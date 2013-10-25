#ifndef _BOARD_H_
#define _BOARD_H_

#include "Rule.h"

class Board {
  private:
    bool *data;
    int sizeX;
    int sizeY;
  public:
    int run(Rule *r);
    Board(const int x,const int y) {
      sizeX = x;
      sizeY = y;
      data = new bool[x*y];
    }
    int print();
};

#endif
