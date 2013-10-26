#include "Cgol.h"

char* Cgol::compute(const int sizeX, const int sizeY, char data[]) {
  int po = 0;
  int nc = 0;
  char *out = new char[sizeX*sizeY];
  for(int i = 1; i < (sizeX-1); i++) {
    for(int j = 1; j < (sizeY-1); j++) {
      po = i*sizeY+j;
      nc = data[(po-1)-sizeY] + data[po-sizeY] + data[(po+1)-sizeY]\
        + data[po-1] + data[po+1]\
        + data[(po-1)+sizeY] + data[po+sizeY] + data[(po+1)+sizeY];
      if (nc < 2)
        out[po] = 0;
      else if ((nc <= 3) && (data[po] != 0))
        out[po] = 1;
      else if (nc != 3)
        out[po] = 0;
      else
        out[po] = 1;
      //out[po] = nc;
    }
  }
  return out;
}
