#include "outputcsv.h"

OutputCSV::OutputCSV()
{

}


void OutputCSV::crearCSV(GLOBAL Datos){

    Valores = Datos.get_Valor();
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
