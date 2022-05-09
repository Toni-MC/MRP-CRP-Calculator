#ifndef LPPLP_H
#define LPPLP_H

#include "mrp.h"
#include <vector>

class LPPLP:public MRP{
    vector<QString> Lpplp;
public:
    LPPLP();
    vector<QString> getValor();
};

#endif // LPPLP_H
