#include "Cgol.h"

bool* Cgol::compute(const int sizeX, const int sizeY, bool **data) {
  int po = 0;
  int nb = 0;
  bool *out = new bool[sizeX*sizeY];
  for(int i = 1; i < (sizeX-1); i++) {
    for(int j = 1; j < (sizeY-1); j++) {
      po = i*sizeY+j;
      nb = (int)data[po+1] + (int)data[po-1] + (int)data[po+sizeY] + (int)data[po-sizeY];
      out[po] = (nb & 2);
    }
  }
  return out;
}
