#include "lpplp.h"

LPPLP::LPPLP(){
    Lpplp = MRP::Extraer_LPPL();
}

vector<QString> LPPLP::getValor(){
    return Lpplp;
}
