#ifndef DP_H
#define DP_H

#include "mrp.h"
#include <vector>

class DP:public MRP{
    vector<QString> Dp;
public:
    DP();
    vector<QString> getValor();
};

#endif // DP_H
