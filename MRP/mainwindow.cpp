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

list<int> NN,RPPL,LPPL,D,RP,NB;
int Ts, SS, S, H;

void MainWindow::on_Ejecutar_clicked()
{
    //Con una ventana emergente pedimos al usuario el método de dimensionado de lote que quiere utilizar
    QStringList metodo;
    metodo << "Lote a Lote";
    metodo << "Periodo Constante";
    metodo << "EOQ";
    metodo << "POQ";
    metodo << "Periodo Fijo";
    metodo << "Minimo Coste Unitario";
    metodo << "Minimo Coste Total";
    metodo << "Silver-Meal";
    QString N = QInputDialog::getItem(this,"Dimensionamiento","Elija el método de dimensionamiento",metodo);

    //Creamos una lista con las necesidades netas
    //Primero extraemos de la pantalla los datos y los convertimos en un string
    QString dato1 = ui->NN1->text(); string numero1 = dato1.toStdString();
    QString dato2 = ui->NN2->text(); string numero2 = dato2.toStdString();
    QString dato3 = ui->NN3->text(); string numero3 = dato3.toStdString();
    QString dato4 = ui->NN4->text(); string numero4 = dato4.toStdString();
    QString dato5 = ui->NN5->text(); string numero5 = dato5.toStdString();
    QString dato6 = ui->NN6->text(); string numero6 = dato6.toStdString();
    QString dato7 = ui->NN7->text(); string numero7 = dato7.toStdString();
    QString dato8 = ui->NN8->text(); string numero8 = dato8.toStdString();
    //A continuación se transforma ese string en un int y se introduce en la lista
    NN = {stoi(numero1),stoi(numero2),stoi(numero3),stoi(numero4),stoi(numero5),stoi(numero6),stoi(numero7),stoi(numero8)};

    //Inicializamos la lista de diponibilidad con solo la disponibilidad inicial
    QString Disp = ui->D1->text(); string disp = Disp.toStdString();
    D.push_back(stoi(disp));

    //Creamos tambien la lista de recepciones programadas y de Necesidades Brutas
    QString Rp1 = ui->RP1->text(); string rp1 = Rp1.toStdString();
    QString Rp2 = ui->RP2->text(); string rp2 = Rp2.toStdString();
    QString Rp3 = ui->RP3->text(); string rp3 = Rp3.toStdString();
    QString Rp4 = ui->RP4->text(); string rp4 = Rp4.toStdString();
    QString Rp5 = ui->RP5->text(); string rp5 = Rp5.toStdString();
    QString Rp6 = ui->RP6->text(); string rp6 = Rp6.toStdString();
    QString Rp7 = ui->RP7->text(); string rp7 = Rp7.toStdString();
    QString Rp8 = ui->RP8->text(); string rp8 = Rp8.toStdString();
    RP = {stoi(rp1),stoi(rp2),stoi(rp3),stoi(rp4),stoi(rp5),stoi(rp6),stoi(rp7),stoi(rp8)};

    QString Nb1 = ui->NB1->text(); string nb1 = Nb1.toStdString();
    QString Nb2 = ui->NB2->text(); string nb2 = Nb2.toStdString();
    QString Nb3 = ui->NB3->text(); string nb3 = Nb3.toStdString();
    QString Nb4 = ui->NB4->text(); string nb4 = Nb4.toStdString();
    QString Nb5 = ui->NB5->text(); string nb5 = Nb5.toStdString();
    QString Nb6 = ui->NB6->text(); string nb6 = Nb6.toStdString();
    QString Nb7 = ui->NB7->text(); string nb7 = Nb7.toStdString();
    QString Nb8 = ui->NB8->text(); string nb8 = Nb8.toStdString();
    NB = {stoi(nb1),stoi(nb2),stoi(nb3),stoi(nb4),stoi(nb5),stoi(nb6),stoi(nb7),stoi(nb8)};

    //Tambien inicializamos las variables Tiempo de Suministro y Stock de Seguridad
    QString TS = ui->Ts->text(); string ts = TS.toStdString();
    Ts = stoi(ts);
    QString Ss = ui->SS->text(); string ss = Ss.toStdString();
    SS = stoi(ss);

    //Adicionalmente inicializamos el valor de emisión de un lote y el coste de posesión por unidad y periodo
    QString Svalor = ui->ValorS->text(); string s = Svalor.toStdString();
    S = stoi(s);
    QString Hvalor = ui->ValorH->text(); string h = Hvalor.toStdString();
    H = stoi(h);

    //A continuación presentamos los diferentes métodos de dimensionamientos en función de la elección del usuario
    if (N == "Periodo Constante")
        PCTE();
    else if(N == "EOQ")
        EOQ();
    else if(N == "POQ")
        POQ();
    else if(N == "Periodo Fijo")
        PF();
}

void MainWindow::PCTE(){
    //Primero es necesario pedir el tamaño del periodo a considerar
    int n = QInputDialog::getInt(this,"Número de periodos","Introduce un número entre 2 y 8",2,2,8);

    //Inicializamos las variables a utilizar
    int cont = 0, suma = 0, casilla = 1, i, lotes = 0, disp=0;
    list<int>::iterator it,rp,nb,d,r;
    rp = RP.begin();    nb = NB.begin();

    //Leemos la lista de necesidades netas
    for (it = NN.begin(); it != NN.end(); it++){

        //Si el primer valor de estas es un 0 entonces no lanzamos el pedido hasta que no sea necesario
        while (*it == 0 && it == NN.begin()){
            if (casilla == 1){
                RPPL.push_back(0);
                casilla++;
                it++;
                cont++;
            }
            else if (casilla <= Ts){
                d = D.end();    d--;
                r = RPPL.end(); r--;
                disp = *d+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                nb++;
                rp++;
                casilla++;
                it++;
                cont++;
            }
            else{
                d = D.end();    d--;
                r = RPPL.end(); r--;
                disp = *d+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
                it++;
                cont++;
            }
        }

        //Cada vez que hacemos el cálculo del número de periodos seleccionado se actualizan los datos
        cont++;
        suma += *it;
        if (cont == n || it == --NN.end()){

            // Primero añadimos el lote a pedir en la RPPL y el LPPL, ademas actualizamos la disponibilidad y añadimos un lote si el lote a pedir no es nulo
            d = D.end();    d--;
            r = RPPL.end(); r--;
            disp = *d+*rp+*r-*nb;
            D.push_back(disp);
            RPPL.push_back(suma);
            LPPL.push_back(suma);
            if (suma > 0)
                lotes++;
            nb++;
            rp++;

            //Despues añadimos 0 hasta que el numero de periodos que ha sido seleccionado se complete
            for (i = 1; i != n; i++){
                if(n-RPPL.size() == 0){
                }
                else{
                    d = D.end();    d--;
                    r = RPPL.end(); r--;
                    disp = *d+*rp+*r-*nb;
                    D.push_back(disp);
                    RPPL.push_back(0);
                    LPPL.push_back(0);
                    nb++;
                    rp++;
                }
            }
            suma = 0;
            casilla += cont;
            cont = 0;
        }
    }

    //Al final se eliminan los ceros adicionales o se añaden en caso de necesidad
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

    actualizarui(lotes);
}

void MainWindow::EOQ(){
    int Q, disp = 0, casilla = 1, lotes = 0;
    list<int>::iterator it, rp, nb, r, d;
    rp = RP.begin();    nb = NB.begin();

    //Para el EOQ lo primero es hacer el cálculo del lote a emitir
    for (it = NN.begin(); it != NN.end(); it++)
        disp += *it;
    Q = round(sqrt((2*disp*S)/(H*8)));

    for (it = NN.begin(); it != NN.end(); it++){

        //Si el primer valor de estas es un 0 entonces no lanzamos el pedido hasta que no sea necesario
        while (*it == 0 && it == NN.begin()){
            if (casilla == 1){
                RPPL.push_back(0);
                casilla++;
                it++;
            }
            else if (casilla <= Ts){
                d = D.end();    d--;
                r = RPPL.end(); r--;
                disp = *d+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                nb++;
                rp++;
                it++;
            }
            else{
                d = D.end();    d--;
                r = RPPL.end(); r--;
                disp = *d+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
                it++;
            }
        }

        //Actualizamos la disponibilidad
        d = D.end();    d--;
        r = RPPL.end(); r--;
        disp = *d+*rp+*r-*nb;
        D.push_back(disp);
        nb++;   rp++;

        //Despues comprobamos si las NN son mayores a la D y si es asi añadimos el valor que corresponde a la RPPL
        d = D.end();    d--;
        if (*d < *it){
            RPPL.push_back(Q);
            LPPL.push_back(Q);
            lotes++;
        }
        //Si no se cumple la condición se añade un 0 a la RPPL y el LPPL
        else{
            RPPL.push_back(0);
            LPPL.push_back(0);
        }
    }
    //Al final se eliminan los ceros adicionales o se añaden en caso de necesidad
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
    actualizarui(lotes);
}

void MainWindow::actualizarui(int lotes){
    //Se procede a crear una función encargada de actualizar la interfaz visual
    list<int>::iterator j, k, d, it;
    int comp = 0, cont = 0, CP = 0, CT;
    j = LPPL.begin();
    d = D.begin();
    k = RPPL.begin();
    for (it = RPPL.begin(); it != RPPL.end(); it++){
        if (cont == 0){
            ui->RPPL1->setText(QString::number(*it));
            ui->LPPL1->setText(QString::number(*j));
            ui->D1->setText(QString::number(*d));
            j++;    cont++; d++;
        }
        else if(cont == 1){
            ui->RPPL2->setText(QString::number(*it));
            ui->LPPL2->setText(QString::number(*j));
            ui->D2->setText(QString::number(*d));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;
        }
        else if(cont == 2){
            ui->RPPL3->setText(QString::number(*it));
            ui->LPPL3->setText(QString::number(*j));
            ui->D3->setText(QString::number(*d));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;
        }
        else if(cont == 3){
            ui->RPPL4->setText(QString::number(*it));
            ui->LPPL4->setText(QString::number(*j));
            ui->D4->setText(QString::number(*d));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;
        }
        else if(cont == 4){
            ui->RPPL5->setText(QString::number(*it));
            ui->LPPL5->setText(QString::number(*j));
            ui->D5->setText(QString::number(*d));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;
        }
        else if(cont == 5){
            ui->RPPL6->setText(QString::number(*it));
            ui->LPPL6->setText(QString::number(*j));
            ui->D6->setText(QString::number(*d));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;
        }
        else if(cont == 6){
            ui->RPPL7->setText(QString::number(*it));
            ui->LPPL7->setText(QString::number(*j));
            ui->D7->setText(QString::number(*d));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
        }
        else{
            ui->RPPL8->setText(QString::number(*it));
            ui->LPPL8->setText(QString::number(*j));
            ui->D8->setText(QString::number(*d));
            cont++;
        }
    }
    CT = lotes*S+CP;
    ui->CosteTotal->setText(QString::number(CT));
}

void MainWindow::POQ(){
    //Primero es necesario pedir el valor de p y d
    double d = QInputDialog::getDouble(this,"Valor de d: Tasa de demanda","Introduce la tasa de demanda");
    double p = QInputDialog::getDouble(this,"Valor de p: Tasa de producción","Introduce la tasa de producción");

    int Q, disp = 0, casilla = 1, lotes = 0;
    list<int>::iterator it, rp, nb, r, di;
    rp = RP.begin();    nb = NB.begin();

    //Para el EOQ lo primero es hacer el cálculo del lote a emitir
    for (it = NN.begin(); it != NN.end(); it++)
        disp += *it;
    Q = round(sqrt((2*disp*S)/(H*8*(1-d/p))));

    for (it = NN.begin(); it != NN.end(); it++){

        //Si el primer valor de estas es un 0 entonces no lanzamos el pedido hasta que no sea necesario
        while (*it == 0 && it == NN.begin()){
            if (casilla == 1){
                RPPL.push_back(0);
                casilla++;
                it++;
            }
            else if (casilla <= Ts){
                di = D.end();    di--;
                r = RPPL.end(); r--;
                disp = *di+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                nb++;
                rp++;
                it++;
            }
            else{
                di = D.end();    di--;
                r = RPPL.end(); r--;
                disp = *di+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
                it++;
            }
        }
        //Actualizamos la disponibilidad
        di = D.end();    di--;
        r = RPPL.end(); r--;
        disp = *di+*rp+*r-*nb;
        D.push_back(disp);
        nb++;   rp++;

        //Despues comprobamos si las NN son mayores a la D y si es asi añadimos el valor que corresponde a la RPPL
        di = D.end();    di--;
        if (*di < *it){
            RPPL.push_back(Q);
            LPPL.push_back(Q);
            lotes++;
        }
        //Si no se cumple la condición se añade un 0 a la RPPL y el LPPL
        else{
            RPPL.push_back(0);
            LPPL.push_back(0);
        }
    }
    //Al final se eliminan los ceros adicionales o se añaden en caso de necesidad
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
    actualizarui(lotes);
}

void MainWindow::PF(){
    int n, cont = 0, suma = 0, casilla = 1, i, lotes = 0, disp=0, num, den, a;
    float div;
    list<int>::iterator it, rp, nb, r, d;
    rp = RP.begin();    nb = NB.begin();

    //Primero calculamos el tamaño de periodo óptimo
    for (it = NN.begin(); it != NN.end(); it++)
        disp += *it;
    div = 8*sqrt((float)(2*S)/(float)(disp*H*8));
    n = round(div);

    //Leemos la lista de necesidades netas
    for (it = NN.begin(); it != NN.end(); it++){

        //Si el primer valor de estas es un 0 entonces no lanzamos el pedido hasta que no sea necesario
        while (*it == 0 && it == NN.begin()){
            if (casilla == 1){
                RPPL.push_back(0);
                casilla++;
                it++;
                cont++;
            }
            else if (casilla <= Ts){
                d = D.end();    d--;
                r = RPPL.end(); r--;
                disp = *d+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                nb++;
                rp++;
                casilla++;
                it++;
                cont++;
            }
            else{
                d = D.end();    d--;
                r = RPPL.end(); r--;
                disp = *d+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
                it++;
                cont++;
            }
        }

        //Cada vez que hacemos el cálculo del número de periodos seleccionado se actualizan los datos
        cont++;
        suma += *it;
        if (cont == n || it == --NN.end()){

            // Primero añadimos el lote a pedir en la RPPL y el LPPL, ademas actualizamos la disponibilidad y añadimos un lote si el lote a pedir no es nulo
            d = D.end();    d--;
            r = RPPL.end(); r--;
            disp = *d+*rp+*r-*nb;
            D.push_back(disp);
            RPPL.push_back(suma);
            LPPL.push_back(suma);
            if (suma > 0)
                lotes++;
            nb++;
            rp++;

            //Despues añadimos 0 hasta que el numero de periodos que ha sido seleccionado se complete
            for (i = 1; i != n; i++){
                if(n-RPPL.size() == 0){
                }
                else{
                    d = D.end();    d--;
                    r = RPPL.end(); r--;
                    disp = *d+*rp+*r-*nb;
                    D.push_back(disp);
                    RPPL.push_back(0);
                    LPPL.push_back(0);
                    nb++;
                    rp++;
                }
            }
            suma = 0;
            casilla += cont;
            cont = 0;
        }
    }

    //Al final se eliminan los ceros adicionales o se añaden en caso de necesidad
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

    actualizarui(lotes);
}
