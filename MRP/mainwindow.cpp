#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Salir_clicked()
{
    close();
}


void MainWindow::on_pushButton_clicked()
{
    QString Archivo = QFileDialog::getOpenFileName(this,tr("Selecciona la base de Datos"), "",tr("Base de Datos (*.xlsx);;All Files (*)"));
    m_db.setDatabaseName(Archivo);
}

list<int> NN,RPPL,LPPL;

void MainWindow::on_Ejecutar_clicked()
{
    QStringList metodo;
    metodo << "Lote a Lote";
    metodo << "Periodo Fijo";
    metodo << "EOQ";
    metodo << "POQ";
    metodo << "Minimo Coste Unitario";
    metodo << "Minimo Coste Total";
    metodo << "Silver-Meal";
    QString N = QInputDialog::getItem(this,"Dimensionamiento","Elija el método de dimensionamiento",metodo);
    QString dato1 = ui->NN1->text(); string numero1 = dato1.toStdString();
    QString dato2 = ui->NN2->text(); string numero2 = dato2.toStdString();
    QString dato3 = ui->NN3->text(); string numero3 = dato3.toStdString();
    QString dato4 = ui->NN4->text(); string numero4 = dato4.toStdString();
    QString dato5 = ui->NN5->text(); string numero5 = dato5.toStdString();
    QString dato6 = ui->NN6->text(); string numero6 = dato6.toStdString();
    QString dato7 = ui->NN7->text(); string numero7 = dato7.toStdString();
    QString dato8 = ui->NN8->text(); string numero8 = dato8.toStdString();
    NN = {stoi(numero1),stoi(numero2),stoi(numero3),stoi(numero4),stoi(numero5),stoi(numero6),stoi(numero7),stoi(numero8)};
    if (N == "Periodo Fijo")
        PF();
}

void MainWindow::PF(){
    int n = QInputDialog::getInt(this,"Número de periodos","Introduce un número entre 2 y 8",2,2,8);
    int cont = 0, suma = 0, casilla = 1, i, a = 0;
    list<int> prueba, prueba2;
    list<int>::iterator it;
    for (it = NN.begin(); it != NN.end(); it++){
        while (*it == 0 && it == NN.begin()){
            if (casilla == 1){
                RPPL.push_back(0);
                casilla++;
                it++;
                cont++;
            }
            else{
                RPPL.push_back(0);
                LPPL.push_back(0);
                it++;
                cont++;
            }
        }
        cont++;
        suma += *it;
        prueba = LPPL;
        prueba2 = RPPL;
        if (cont == n || it == --NN.end()){
            RPPL.push_back(suma);
            LPPL.push_back(suma);
            for (i = 1; i != n; i++){
                if(RPPL.size() > 0 && RPPL.size() < n && a == 0){
                    i += RPPL.size()-1;
                    a++;
                }
                if(n-RPPL.size() == 0){
                }
                else{
                    RPPL.push_back(0);
                    LPPL.push_back(0);
                }
            }
            prueba = LPPL;
            prueba2 = RPPL;
            suma = 0;
            casilla += cont;
            cont = 0;
        }
    }
    while (RPPL.size() != 8){
        if( RPPL.size() < 8)
            RPPL.push_back(0);
        else
            RPPL.pop_back();
    }
    while (LPPL.size() != 8){
        if( LPPL.size() < 8)
            LPPL.push_back(0);
        else
            LPPL.pop_back();
    }
    list<int>::iterator j;
    cont = 0;
    prueba = LPPL;
    prueba2 = RPPL;
    j = LPPL.begin();
    for (it = RPPL.begin(); it != RPPL.end(); it++){
        if (cont == 0){
            ui->RPPL1->setText(QString::number(*it));
            ui->LPPL1->setText(QString::number(*j));
            j++;    cont++;
        }
        else if(cont == 1){
            ui->RPPL2->setText(QString::number(*it));
            ui->LPPL2->setText(QString::number(*j));
            j++;    cont++;
        }
        else if(cont == 2){
            ui->RPPL3->setText(QString::number(*it));
            ui->LPPL3->setText(QString::number(*j));
            j++;    cont++;
        }
        else if(cont == 3){
            ui->RPPL4->setText(QString::number(*it));
            ui->LPPL4->setText(QString::number(*j));
            j++;    cont++;
        }
        else if(cont == 4){
            ui->RPPL5->setText(QString::number(*it));
            ui->LPPL5->setText(QString::number(*j));
            j++;    cont++;
        }
        else if(cont == 5){
            ui->RPPL6->setText(QString::number(*it));
            ui->LPPL6->setText(QString::number(*j));
            j++;    cont++;
        }
        else if(cont == 6){
            ui->RPPL7->setText(QString::number(*it));
            ui->LPPL7->setText(QString::number(*j));
            j++;    cont++;
        }
        else{
            ui->RPPL8->setText(QString::number(*it));
            ui->LPPL8->setText(QString::number(*j));
            cont++;
        }
    }
}
