#ifndef NNP_H
#define NNP_H

#include "mrp.h"
#include <vector>

class NNP:public MRP{
    vector<QString> Nnp;
public:
    NNP();
    vector<QString> getValor();
};

#endif // NNP_H
