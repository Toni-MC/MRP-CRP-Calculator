#include "nb.h"

NBP::NBP(){
    Nbp = MRP::Extraer_NB();
}

vector<QString> NBP::getValor(){
    return Nbp;
}
