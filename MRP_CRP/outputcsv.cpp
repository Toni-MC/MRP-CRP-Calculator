#include "outputcsv.h"

OutputCSV::OutputCSV()
{

}


void OutputCSV::crearCSV(GLOBAL Datos,QString filename){

    Valores = Datos.get_Valor();

    QFile file(filename);


    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {
    QTextStream stream(&file);

    // Primera linea
    stream << " " << ",";
    for (int i=1; i<=8; i++) stream << i << ",";
    stream << "\n";

    // Segunda linea
    stream << "NB" <<",";
    for (unsigned i=0; i<8; i++) stream << Valores["NB"][i] << ",";
    stream << "\n";

    // Tercera
    stream << "D" <<",";
    for (unsigned i=0; i<8; i++) stream << Valores["D"][i] << ",";
    stream << "\n";

    // Cuarta
    stream << "RP" <<",";
    for (unsigned i=0; i<8; i++) stream << Valores["RP"][i] << ",";
    stream << "\n";

    // Quinta
    stream << "NN" <<",";
    for (unsigned i=0; i<8; i++) stream << Valores["NN"][i] << ",";
    stream << "\n";

    // Sexta
    stream << "RPPL" <<",";
    for (unsigned i=0; i<8; i++) stream << Valores["RPPL"][i] << ",";
    stream << "\n";

    // Septima
    stream << "LPPL" <<",";
    for (unsigned i=0; i<8; i++) stream << Valores["LPPL"][i] << ",";
    stream << "\n";


    // Octava
    stream << "CT" <<",";
    stream << Valores["CT"][0] << ",";
    stream << "\n";


    file.close();
    }



}
