#ifndef _RULE_H_
#define _RULE_H_

class Rule {
  public:
    virtual bool* compute(const int sizeX, const int sizeY, bool **data);
};
#endif
