#include "rpp.h"

RPP::RPP(){
    Rpp = MRP::Extraer_RP();
}

vector<QString> RPP::getValor(){
    return Rpp;
}
