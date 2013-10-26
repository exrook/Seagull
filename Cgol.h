#ifndef _CGOL_H_
#define _CGOL_H_

#include "Rule.h"

class Cgol: public Rule {
  public:
     virtual char* compute(const int sizeX, const int sizeY, char data[]);

};

#endif
