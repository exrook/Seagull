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
        nc = (j ? data[(po-1)-sizeX]:data[(po-1)]) + data[po-sizeX] \
           + (j < (sizeX-1) ? data[(po+1)-sizeX] : data[po+1-(2*sizeX)]);
      else //if this is first row, loop back around
        nc = (j ? data[(sizeY-1)*sizeX+po-1] : data[(sizeY)*sizeX-1])\
           + data[(sizeY-1)*sizeX+po]\
           + (j < sizeX-1 ? data[(sizeY-1)*sizeX+po+1] : data[(sizeY-1)*sizeX]);
           
      nc += (j ? data[po-1] : data[(i*sizeX)+sizeX-1]) + (j < sizeX-1 ? data[po+1] : data[(i*sizeX)+1]);
      if (i < (sizeY-1)) // if this is not the last row, count neighbors below us
        nc += (j ? data[(po-1)+sizeX] : data[po-1+(2*sizeX)]) + data[po+sizeX]\
           + (j < (sizeX-1) ? data[(po+1)+sizeX] : data[po+1]);
      else // if this is the last row, loop around
        nc += (j ? data[j-1] : data[sizeX-1])\
           + data[j]\
           + (j < sizeX-1 ? data[j+1] : data[0]);

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
