#include "Cgol.h"

char* Cgol::compute(const int sizeX, const int sizeY, char data[]) {
  int po = 0;
  int nb = 0;
  char *out = new char[sizeX*sizeY];
  for(int i = 1; i < (sizeX-1); i++) {
    for(int j = 1; j < (sizeY-1); j++) {
      po = i*sizeY+j;
      nb = data[po+1] + data[po-1] + data[po+sizeY] + data[po-sizeY];
      out[po] = (nb & 2);
    }
  }
  return out;
}
