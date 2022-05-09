#include "nnp.h"

NNP::NNP(){
    Nnp = MRP::Extraer_NN();
}

vector<QString> NNP::getValor(){
    return Nnp;
}
