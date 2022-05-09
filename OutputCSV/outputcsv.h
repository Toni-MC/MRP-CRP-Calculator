#ifndef OUTPUTCSV_H
#define OUTPUTCSV_H

#include <QFile>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <QString>
#include <QTextStream>

using namespace std;

class OutputCSV
{
public:
    OutputCSV();
    void crearCSV();

    map<string,vector<QString>> Valores;

};

#endif // OUTPUTCSV_H
