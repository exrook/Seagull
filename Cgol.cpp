#include "Cgol.h"

char* Cgol::compute(const int sizeX, const int sizeY, char data[]) {
  int po = 0;
  int nc = 0;
  char *out = new char[sizeX*sizeY];
  for(int i = 0; i < (sizeY); i++) {
    for(int j = 0; j < (sizeX); j++) {
      po = i*sizeX+j; // current cell
      nc = 0; // neighbor count
      
      if (i) // if this is not the first row, then count neighbors above current cell
        nc = (j ? data[(po-1)-sizeX] : 0) + data[po-sizeX] + (j < (sizeY-1) ? data[(po+1)-sizeX] : 0);
      nc += (j ? data[po-1] : 0) + (j < (sizeY-1) ? data[po+1] : 0);
      if (i < (sizeY-1)) // if this is not the last row, count neighbors below us
        nc += (j ? data[(po-1)+sizeX] : 0) + data[po+sizeX] + (j < (sizeY-1) ? data[(po+1)+sizeX] : 0);
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
