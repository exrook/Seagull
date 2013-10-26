#ifndef _RULE_H_
#define _RULE_H_

class Rule {
  public:
    virtual char* compute(const int sizeX, const int sizeY, char data[])=0;
};
#endif
