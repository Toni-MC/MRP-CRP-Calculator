#include <QCoreApplication>
#include <outputcsv.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    OutputCSV Salida;
    Salida.crearCSV();



    return a.exec();
}
