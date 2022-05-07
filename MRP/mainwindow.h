#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QInputDialog>
#include <qfiledialog.h>
#include <iostream>
#include <list>
using namespace std;
using std::stoi;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Salir_clicked();

    void on_pushButton_clicked();

    void on_Ejecutar_clicked();

    void PCTE();

    void EOQ();

    void POQ();

    void PF();

    /*void MCU();

    void MCT();

    void SM();*/

    void actualizarui(int lotes);
private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
};
#endif // MAINWINDOW_H
