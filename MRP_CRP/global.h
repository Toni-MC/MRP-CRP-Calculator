#ifndef GLOBAL_H
#define GLOBAL_H

#include <map>
#include <QString>
#include <string>
#include <vector>
using namespace std;

class GLOBAL{
    map<string, vector<QString>> global;
public:
    GLOBAL(vector<QString> NB, vector<QString> D, vector<QString> RP, vector<QString> NN, vector<QString> RPPL, vector<QString> LPPL, vector<QString> CT, vector<QString> Ts,vector<QString> Qej);
    map<string, vector<QString>> get_Valor();
};

#endif // GLOBAL_H
