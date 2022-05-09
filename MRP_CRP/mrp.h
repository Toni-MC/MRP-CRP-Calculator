#ifndef MRP_H
#define MRP_H

#include <QMainWindow>
#include <QtSql>
#include <QInputDialog>
#include <QFileDialog>
#include <iostream>
#include <list>
#include <QFile>

// .csv in/out
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using std::stoi;


QT_BEGIN_NAMESPACE
namespace Ui { class MRP; }
QT_END_NAMESPACE

class MRP : public QMainWindow
{
    Q_OBJECT

public:
    MRP(QWidget *parent = nullptr);
    ~MRP();

    list<int> NN,RPPL,LPPL,D,RP,NB;
    int Ts, SS, S, H;

private slots:
    void on_Salir_clicked();

    void on_pushButton_Excel_clicked();

    void on_Ejecutar_clicked();

    void LaL(int a);

    void PCTE();

    void EOQ();

    void POQ();

    void PF();

    void MCU();

    void MCT();

    void SM();

    void actualizarui(int lotes, int a);

    void on_pushButton_CRP_clicked();

private:
    Ui::MRP *ui;
};
#endif // MRP_H