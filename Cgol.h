#ifndef _CGOL_H_
#define _CGOL_H_

#include "Rule.h"

class Cgol: public Rule {
  public:
     virtual bool* compute(const int sizeX, const int sizeY, bool **data);

};

#endif
