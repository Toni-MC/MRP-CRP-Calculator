#ifndef CRP_H
#define CRP_H

#include <QDialog>
#include <QInputDialog>
#include <QFileDialog>
#include <iostream>
#include <list>
#include <vector>
#include <QFile>

using namespace std;
using std::stoi;

namespace Ui {
class CRP;
}

class CRP : public QDialog
{
    Q_OBJECT

public:
    explicit CRP(int Ts,vector<int> &vec,int Qej, QWidget *parent = nullptr);
    ~CRP();

    /*
    vector<int> CT,te,PPA,tmp,a,PPB,tc,ACT1,ACT2,BCT1,BCT2,Total1,Total2;
    int Aa=1,Ab=1,tsa,tsb,QA,QB,TCA1,TCA2,TCB1,TCB2;
    float A1,A2,B1,B2;
    */

private slots:
    void on_SALIR_clicked();

    void on_Ejecutar_clicked();

    void actualizarui();

    void on_pushButton_ExcelA_clicked();

    void on_pushButton_ExcelB_clicked();

    void on_pushButton_ExcelComun_clicked();

private:
    Ui::CRP *ui;
};

#endif // CRP_H
