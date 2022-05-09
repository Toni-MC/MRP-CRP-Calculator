#include "lpplp.h"

LPPLP::LPPLP(MRP mrp){
    Lpplp = mrp.Extraer_LPPL();
}

vector<QString> LPPLP::getValor(){
    return Lpplp;
}
