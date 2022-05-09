#ifndef RPP_H
#define RPP_H

#include "mrp.h"
#include <vector>

class RPP:public MRP{
    vector<QString> Rpp;
public:
    RPP();
    vector<QString> getValor();
};

#endif // RPP_H
