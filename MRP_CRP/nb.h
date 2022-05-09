#ifndef NB_H
#define NB_H

#include "mrp.h"
#include <vector>

class NBP:public MRP{
    vector<QString> Nbp;
public:
    NBP();

    vector<QString> getValor();
};

#endif // NB_H
