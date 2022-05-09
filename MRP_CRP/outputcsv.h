#ifndef OUTPUTCSV_H
#define OUTPUTCSV_H

#include <QFile>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <QString>
#include <QTextStream>
#include "global.h"
#include <QFileDialog>
#include <QInputDialog>
#include "mrp.h"

using namespace std;

class OutputCSV{
    map<string,vector<QString>> Valores;
public:
    OutputCSV();

    void crearCSV(GLOBAL Datos, QString filename);

};

#endif // OUTPUTCSV_H
