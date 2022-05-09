#ifndef RPPLP_H
#define RPPLP_H

#include "mrp.h"
#include <vector>

class RPPLP:public MRP{
    vector<QString> Rpplp;
public:
    RPPLP();
    vector<QString> getValor();
};

#endif // RPPLP_H
