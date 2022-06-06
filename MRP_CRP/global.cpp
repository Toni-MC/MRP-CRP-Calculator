#include "global.h"

GLOBAL::GLOBAL(vector<QString> NB, vector<QString> D, vector<QString> RP, vector<QString> NN, vector<QString> RPPL, vector<QString> LPPL, vector<QString> CT, vector<QString> Ts,vector<QString> Qej)
{
    global["NB"] = NB;
    global["D"] = D;
    global["RP"] = RP;
    global["NN"] = NN;
    global["RPPL"] = RPPL;
    global["LPPL"] = LPPL;
    global["CT"] = CT;
    global["T"] = Ts;
    global["Qej"] = Qej;
}

map<string, vector<QString>> GLOBAL::get_Valor(){
    return global;
}
