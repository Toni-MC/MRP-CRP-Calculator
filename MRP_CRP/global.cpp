#include "global.h"

GLOBAL::GLOBAL(vector<QString> NB, vector<QString> D, vector<QString> RP, vector<QString> NN, vector<QString> RPPL, vector<QString> LPPL, vector<QString> CT)
{
    global["NB"] = NB;
    global["D"] = D;
    global["RP"] = RP;
    global["NN"] = NN;
    global["RPPL"] = RPPL;
    global["LPPL"] = LPPL;
    global["CT"] = CT;
}
