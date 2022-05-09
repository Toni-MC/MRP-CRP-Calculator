#include "dp.h"

DP::DP(){
    Dp = MRP::Extraer_D();
}

vector<QString> DP::getValor(){
    return Dp;
}
