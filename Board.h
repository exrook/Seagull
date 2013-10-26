#ifndef _BOARD_H_
#define _BOARD_H_

#include "Rule.h"
#include <cstring>

class Board {
  private:
    char *data;
    int sizeX;
    int sizeY;
  public:
    int run(Rule *r);
    Board(const int x,const int y) {
      sizeX = x;
      sizeY = y;
      data = new char[x*y];
    }
    Board(const int x,const int y, char **init): Board(x,y) {
      memcpy(data, init, x*y);
    }
    int print();
};

#endif
