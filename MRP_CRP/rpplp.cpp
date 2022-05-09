#include "rpplp.h"

RPPLP::RPPLP(){
    Rpplp = MRP::Extraer_RPPL();
}

vector<QString> RPPLP::getValor(){
    return Rpplp;
}
