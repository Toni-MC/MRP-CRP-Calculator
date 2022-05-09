#include "outputcsv.h"

OutputCSV::OutputCSV(class global global){

    vector<QString> NB(9,"1");
    NB[0]="NB";
    vector<QString> D(9,"2");
    D[0]="D";
    vector<QString> RP(9,"3");
    RP[0]="RP";
    vector<QString> NN(9,"4");
    NN[0]="NN";
    vector<QString> RPP(9,"5");
    RPP[0]="RPP";
    vector<QString> LPP(9,"6");
    LPP[0]="LPP";
    vector<QString> CT(9,"7");
    CT[0]="CT";

    Valores["NB"]=NB;
    Valores["D"]=D;
    Valores["RP"]=RP;
    Valores["NN"]=NN;
    Valores["RPP"]=RPP;
    Valores["LPP"]=LPP;
    Valores["CT"]=CT;


}


void OutputCSV::crearCSV(class global global)
{

    QFile file("./file.csv");
    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {
    QTextStream stream(&file);

    // Primera linea
    stream << " " << ",";
    for (int i=0; i<=7; i++) stream << i << ",";
    stream << "\n";

    // Segunda linea
    for (unsigned i=0; i<=8; i++) stream << Valores["NB"][i] << ",";
    stream << "\n";

    // Tercera
    for (unsigned i=0; i<=8; i++) stream << Valores["D"][i] << ",";
    stream << "\n";

    // Cuarta
    for (unsigned i=0; i<=8; i++) stream << Valores["RP"][i] << ",";
    stream << "\n";

    // Quinta
    for (unsigned i=0; i<=8; i++) stream << Valores["NN"][i] << ",";
    stream << "\n";

    // Sexta
    for (unsigned i=0; i<=8; i++) stream << Valores["RPP"][i] << ",";
    stream << "\n";

    // Septima
    for (unsigned i=0; i<=8; i++) stream << Valores["LPP"][i] << ",";
    stream << "\n";

    // Octava
    for (unsigned i=0; i<=8; i++) stream << Valores["CT"][i] << ",";
    stream << "\n";


    file.close();
    }



}
