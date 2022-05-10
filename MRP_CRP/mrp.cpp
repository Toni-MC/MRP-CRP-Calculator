#include "mrp.h"
#include "ui_mrp.h"
#include "crp.h"
#include "nb.h"
#include "nnp.h"
#include "dp.h"
#include "rpp.h"
#include "rpplp.h"
#include "lpplp.h"
#include "global.h"
#include "outputcsv.h"

MRP::MRP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MRP)
{
    ui->setupUi(this);
    ui->pushButton_CRP->show();
}

MRP::~MRP()
{
    delete ui;
}

void MRP::on_Salir_clicked()
{
    close();
}

void MRP::on_pushButton_Excel_clicked(){
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona la base de Datos"), "",tr("Archivo .csv (*.csv)"));

    vector<QString> NB;
    vector<QString> D;
    vector<QString> RP;
    vector<QString> SS;
    vector<QString> Ts;
    vector<QString> S;
    vector<QString> H;
    vector<QString> row(9);

    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    file.readLine(); // read first line and ignore

    while (!file.atEnd()) {
        QString line = file.readLine();

        // Sólo valido para Qt 5.12.12 y anteriores
        // la función de Qvector, toStdVector no está disponible
        // a partir de Qt.6
        // row= line.split(',').toVector().toStdVector();

        QVector<QString> rowaux=line.split(',').toVector();
        for (int i=0; i<rowaux.size();i++) row[i]=rowaux[i];

        if (row[0]=="NB")       NB=row;
        if (row[0]=="D")        D=row;
        if (row[0]=="RP")       RP=row;
        if (row[0]=="SS")       SS=row;
        if (row[0]=="T")        Ts=row;
        if (row[0]=="S")        S=row;
        if (row[0]=="H")        H=row;

    }

    file.close();

    // Necesidades Brutas
    ui->NB1->setText(NB[1]);
    ui->NB2->setText(NB[2]);
    ui->NB3->setText(NB[3]);
    ui->NB4->setText(NB[4]);
    ui->NB5->setText(NB[5]);
    ui->NB6->setText(NB[6]);
    ui->NB7->setText(NB[7]);
    ui->NB8->setText(NB[8]);

    // Disponibilidad
    ui->D1->setText(D[1]);

    // Recepciones Programadas
    ui->RP1->setText(RP[1]);
    ui->RP2->setText(RP[2]);
    ui->RP3->setText(RP[3]);
    ui->RP4->setText(RP[4]);
    ui->RP5->setText(RP[5]);
    ui->RP6->setText(RP[6]);
    ui->RP7->setText(RP[7]);
    ui->RP8->setText(RP[8]);

    // Tiempo de suministro
    ui->Ts->setText(Ts[1]);

    // Stock de seguridad
    ui->SS->setText(SS[1]);

    // S, Coste de emisión
    ui->ValorS->setText(S[1]);

    // H, Coste de alamacenamiento
    ui->ValorH->setText(H[1]);

    // Limpiar NN de ejemplo
    ui->NN1->clear();
    ui->NN2->clear();
    ui->NN3->clear();
    ui->NN4->clear();
    ui->NN5->clear();
    ui->NN6->clear();
    ui->NN7->clear();
    ui->NN8->clear();
}

vector<QString> MRP::Extraer_NB(){
    vector<QString> Nb;
    QString dato1 = ui->NB1->text();
    QString dato2 = ui->NB2->text();
    QString dato3 = ui->NB3->text();
    QString dato4 = ui->NB4->text();
    QString dato5 = ui->NB5->text();
    QString dato6 = ui->NB6->text();
    QString dato7 = ui->NB7->text();
    QString dato8 = ui->NB8->text();
    Nb = {dato1, dato2, dato3, dato4, dato5, dato6, dato7, dato8};
    return Nb;
}

vector<QString> MRP::Extraer_NN(){
    vector<QString> Nn;
    QString dato1 = ui->NN1->text();
    QString dato2 = ui->NN2->text();
    QString dato3 = ui->NN3->text();
    QString dato4 = ui->NN4->text();
    QString dato5 = ui->NN5->text();
    QString dato6 = ui->NN6->text();
    QString dato7 = ui->NN7->text();
    QString dato8 = ui->NN8->text();
    Nn = {dato1, dato2, dato3, dato4, dato5, dato6, dato7, dato8};
    return Nn;
}

vector<QString> MRP::Extraer_D(){
    vector<QString> D;

    QString dato1 = ui->D1->text();
    QString dato2 = ui->D2->text();
    QString dato3 = ui->D3->text();
    QString dato4 = ui->D4->text();
    QString dato5 = ui->D5->text();
    QString dato6 = ui->D6->text();
    QString dato7 = ui->D7->text();
    QString dato8 = ui->D8->text();
    D = {dato1, dato2, dato3, dato4, dato5, dato6, dato7, dato8};
    return D;
}

vector<QString> MRP::Extraer_RP(){
    vector<QString> Rp;
    QString dato1 = ui->RP1->text();
    QString dato2 = ui->RP2->text();
    QString dato3 = ui->RP3->text();
    QString dato4 = ui->RP4->text();
    QString dato5 = ui->RP5->text();
    QString dato6 = ui->RP6->text();
    QString dato7 = ui->RP7->text();
    QString dato8 = ui->RP8->text();
    Rp = {dato1, dato2, dato3, dato4, dato5, dato6, dato7, dato8};
    return Rp;
}

vector<QString> MRP::Extraer_RPPL(){
    vector<QString> Lppl;
    QString dato1 = ui->LPPL1->text();
    QString dato2 = ui->LPPL2->text();
    QString dato3 = ui->LPPL3->text();
    QString dato4 = ui->LPPL4->text();
    QString dato5 = ui->LPPL5->text();
    QString dato6 = ui->LPPL6->text();
    QString dato7 = ui->LPPL7->text();
    QString dato8 = ui->LPPL8->text();
    Lppl = {dato1, dato2, dato3, dato4, dato5, dato6, dato7, dato8};
    return Lppl;
}

vector<QString> MRP::Extraer_LPPL(){
    vector<QString> Rppl;
    QString dato1 = ui->RPPL1->text();
    QString dato2 = ui->RPPL2->text();
    QString dato3 = ui->RPPL3->text();
    QString dato4 = ui->RPPL4->text();
    QString dato5 = ui->RPPL5->text();
    QString dato6 = ui->RPPL6->text();
    QString dato7 = ui->RPPL7->text();
    QString dato8 = ui->RPPL8->text();
    Rppl = {dato1, dato2, dato3, dato4, dato5, dato6, dato7, dato8};
    return Rppl;
}

void MRP::on_Ejecutar_clicked()
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
    //NN = {stoi(numero1),stoi(numero2),stoi(numero3),stoi(numero4),stoi(numero5),stoi(numero6),stoi(numero7),stoi(numero8)};

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
    if (N == "Lote a Lote")
        LaL(0);
    else if (N == "Periodo Constante"){
        LaL(1);
    }
    else if(N == "EOQ"){
        LaL(2);
    }
    else if(N == "POQ"){
        LaL(3);
    }
    else if(N == "Periodo Fijo"){
        LaL(4);
    }
    else if(N == "Minimo Coste Unitario"){
        LaL(5);
    }
    else if(N == "Minimo Coste Total"){
        LaL(6);
    }
    else if(N == "Silver-Meal"){
        LaL(7);
    }
}

void MRP::LaL(int a){
    int nni= 0, rppli= 0, dis= 0, lotes= 0;
    list<int>::iterator nb,d,rp,nn,rppl,lppl, it, j;
    nn= NN.begin();    d= D.begin();    rp= RP.begin();    rppl= RPPL.begin();      lppl= LPPL.begin();

    //En caso de hacer un cálculo de nuevo sin cerrar la aplicación es necesario limpiar las listas
    j = RPPL.begin();
    it = RPPL.end();
    RPPL.erase(j,it);

    j = LPPL.begin();
    it = LPPL.end();
    LPPL.erase(j,it);

    j = D.begin();  j++;
    it = D.end();
    D.erase(j,it);

    j = NN.begin();
    it = NN.end();
    NN.erase(j,it);

    //Calculamos las necesidades netas
    for (nb= NB.begin(); nb!= NB.end(); nb++){
        nni= *nb-*d-*rp+SS;
        if (nni>0){
            rppli= nni;
            lotes++;
        }
        else{
            nni= 0;
            rppli= 0;
        }
        //Las disponibilidades necesitan el valor del periodo siguiente
        dis= *d+*rp+rppli-*nb;
        NN.push_back(nni);
        D.push_back(dis);
        RPPL.push_back(rppli);
        nn++;
        d++;
        rp++;
        rppl++;
    }
    //Actualizamos el lanzamiento de los pedidos planificados
    int periodo= 1;
    for (rppl= RPPL.begin(); rppl!= RPPL.end(); rppl++){
        if (periodo==1){
            for (int i=0; i<Ts; i++)
                rppl++;
        }
        //El resto de valores serán cero            MAAAAAAAAAAAAAAAAL
        if (periodo > 8-Ts){
            LPPL.push_back(0);
        }
        else {
            LPPL.push_back(*rppl);
        }
        periodo++;
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
    actualizarui(lotes,a);
}

void MRP::PCTE(){
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

    actualizarui(lotes, 0);
}

void MRP::EOQ(){
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
    actualizarui(lotes, 0);
}

void MRP::actualizarui(int lotes, int a){
    //Se procede a crear una función encargada de actualizar la interfaz visual
    list<int>::iterator j, k, d, it, t;
    int comp = 0, cont = 0, CP = 0, CT;
    j = LPPL.begin();
    d = D.begin();
    k = RPPL.begin();
    t = NN.begin();
    for (it = RPPL.begin(); it != RPPL.end(); it++){
        if (cont == 0){
            ui->RPPL1->setText(QString::number(*it));
            ui->LPPL1->setText(QString::number(*j));
            ui->D1->setText(QString::number(*d));
            ui->NN1->setText(QString::number(*t));
            j++;    cont++; d++; t++;
        }
        else if(cont == 1){
            ui->RPPL2->setText(QString::number(*it));
            ui->LPPL2->setText(QString::number(*j));
            ui->D2->setText(QString::number(*d));
            ui->NN2->setText(QString::number(*t));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;  t++;
        }
        else if(cont == 2){
            ui->RPPL3->setText(QString::number(*it));
            ui->LPPL3->setText(QString::number(*j));
            ui->D3->setText(QString::number(*d));
            ui->NN3->setText(QString::number(*t));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;  t++;
        }
        else if(cont == 3){
            ui->RPPL4->setText(QString::number(*it));
            ui->LPPL4->setText(QString::number(*j));
            ui->D4->setText(QString::number(*d));
            ui->NN4->setText(QString::number(*t));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;  t++;
        }
        else if(cont == 4){
            ui->RPPL5->setText(QString::number(*it));
            ui->LPPL5->setText(QString::number(*j));
            ui->D5->setText(QString::number(*d));
            ui->NN5->setText(QString::number(*t));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;  t++;
        }
        else if(cont == 5){
            ui->RPPL6->setText(QString::number(*it));
            ui->LPPL6->setText(QString::number(*j));
            ui->D6->setText(QString::number(*d));
            ui->NN6->setText(QString::number(*t));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;  t++;
        }
        else if(cont == 6){
            ui->RPPL7->setText(QString::number(*it));
            ui->LPPL7->setText(QString::number(*j));
            ui->D7->setText(QString::number(*d));
            ui->NN7->setText(QString::number(*t));
            if(*d <= *k)
                comp = 1;
            if (comp == 1){
                CP = CP+(*d-SS)*H;
            }
            j++;    cont++; d++;    k++;  t++;
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
            ui->NN8->setText(QString::number(*t));
            cont++;
        }
    }
    CT = lotes*S+CP;
    ui->CosteTotal->setText(QString::number(CT));

    j = LPPL.begin();
    while (*j==0) {
        Lote=*j;    j++;
    };


    //Vaciamos los vectores RPPL y LPPL para reescribirlos en el proceso que corresponda
    j = RPPL.begin();
    it = RPPL.end();
    RPPL.erase(j,it);

    j = LPPL.begin();
    it = LPPL.end();
    LPPL.erase(j,it);

    j = D.begin();  j++;
    it = D.end();
    D.erase(j,it);

    if (a == 1){
        PCTE();
    }
    else if(a == 2){
        EOQ();
    }
    else if(a == 3){
        POQ();
    }
    else if(a == 4){
        PF();
    }
    else if(a == 5){
        MCU();
    }
    else if(a == 6){
        MCT();
    }
    else if(a == 7){
        SM();
    }
}

void MRP::POQ(){
    //Primero es necesario pedir el valor de p y d
    double d = QInputDialog::getDouble(this,"Valor de d: Tasa de demanda","Introduce la tasa de demanda");
    double p = QInputDialog::getDouble(this,"Valor de p: Tasa de producción","Introduce la tasa de producción");

    int Q, disp = 0, casilla = 1, lotes = 0;
    list<int>::iterator it, rp, nb, r, di;
    rp = RP.begin();    nb = NB.begin();

    //Para el POQ lo primero es hacer el cálculo del lote a emitir
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
    actualizarui(lotes, 0);
}

void MRP::PF(){
    int n, cont = 0, suma = 0, casilla = 1, i, lotes = 0, disp=0;
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

    actualizarui(lotes, 0);
}

void MRP::MCU(){
    int disp = 0, casilla = 1, lotes = 0, Q = 0, Q1, cont = 1, i;
    float CTu, CTu1, CPu = 0, CP = 0, CP1;
    list<int>::iterator it, rp, nb, r, di;
    rp = RP.begin();    nb = NB.begin();

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

        // Se exluyen lo 0 en las NN que no sean iniciales
        if (*it == 0 && cont != 2){
            it++;
            cont++;
        }

        //Hacemos los cálculos de tamaño de lote y coste total unitario para cada caso, además almacenamos el cálculo anterior para poder hacer una comparación
        if(Q == 0){
            Q = *it;
            CP1 = CP;
            CTu = CPu + (float)S/Q;
            CTu1 = CTu;
            cont++;
        }
        else{
            Q1 = Q;
            CTu1 = CTu;
            Q += *it;
            CP = CP1 + (Q-Q1)*H*(cont - 1);
            CP1 = CP;
            CPu = (float)CP/Q;
            CTu = CPu + (float)S/Q;
            cont++;
        }

        //Cuando el nuevo coste unitario sea mayor que el anterior introducimos los datos calculados con anterioridad y comenzamos el cálculo del nuevo lote
        if (CTu > CTu1){
            lotes++;
            cont--;
            di = D.end();    di--;
            r = RPPL.end(); r--;
            disp = *di+*rp+*r-*nb;
            D.push_back(disp);
            RPPL.push_back(Q1);
            LPPL.push_back(Q1);
            nb++;
            rp++;
            Q -= Q1;
            CPu = 0;
            CP = 0;
            CP1 = 0;
            CTu = CPu + (float)S/Q;
            CTu1 = CTu;
            for (i = 0; i != cont-2; i++){
                di = D.end();    di--;
                r = RPPL.end(); r--;
                disp = *di+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
            }
            cont = 2;
        }

    }
    lotes++;
    di = D.end();    di--;
    r = RPPL.end(); r--;
    disp = *di+*rp+*r-*nb;
    D.push_back(disp);
    RPPL.push_back(Q);
    LPPL.push_back(Q);

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
    while (D.size() < 8){
        D.push_back(disp);
    }

    actualizarui(lotes, 0);
}

void MRP::MCT(){
    int disp = 0, casilla = 1, lotes = 0, Q = 0, Q1, cont = 1, i, a = 0, CP = 0, CP1, Desv, Desv1;
    list<int>::iterator it, rp, nb, r, di;
    rp = RP.begin();    nb = NB.begin();

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

        // Se exluyen lo 0 en las NN que no sean iniciales
        if (*it == 0 && cont != 2){
            it++;
            cont++;
        }

        //Hacemos los cálculos de tamaño de lote y coste total unitario para cada caso, además almacenamos el cálculo anterior para poder hacer una comparación
        if(Q == 0){
            Q = *it;
            CP1 = CP;
            Desv = abs(CP - S);
            Desv1 = Desv;
            cont++;
        }
        else{
            Q1 = Q;
            Desv1 = Desv;
            Q += *it;
            CP = CP1 + (Q-Q1)*H*(cont - a);
            CP1 = CP;
            Desv = abs(CP - S);
            cont++;
        }

        //Cuando el nuevo coste unitario sea mayor que el anterior introducimos los datos calculados con anterioridad y comenzamos el cálculo del nuevo lote
        if (Desv > Desv1){
            lotes++;
            cont--;
            di = D.end();    di--;
            r = RPPL.end(); r--;
            disp = *di+*rp+*r-*nb;
            D.push_back(disp);
            RPPL.push_back(Q1);
            LPPL.push_back(Q1);
            nb++;
            rp++;
            Q -= Q1;
            CP = 0;
            CP1 = 0;
            Desv = abs(CP - S);
            Desv1 = Desv;
            for (i = 0; i != cont-2; i++){
                di = D.end();    di--;
                r = RPPL.end(); r--;
                disp = *di+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
            }
            cont = 2;
            a = 1;
        }

    }
    lotes++;
    di = D.end();    di--;
    r = RPPL.end(); r--;
    disp = *di+*rp+*r-*nb;
    D.push_back(disp);
    RPPL.push_back(Q);
    LPPL.push_back(Q);
    nb++;
    rp++;
    di = D.end();    di--;
    r = RPPL.end(); r--;
    disp = *di+*rp+*r-*nb;

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
    while (D.size() < 8){
        D.push_back(disp);
    }

    actualizarui(lotes, 0);
}

void MRP::SM(){
    int disp = 0, casilla = 1, lotes = 0, Q = 0, Q1, cont = 1, i, a = 0, CP = 0, CP1, Desv, Desv1;
    list<int>::iterator it, rp, nb, r, di;
    rp = RP.begin();    nb = NB.begin();

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

        // Se exluyen lo 0 en las NN que no sean iniciales
        if (*it == 0 && cont != 2){
            it++;
            cont++;
        }

        //Hacemos los cálculos de tamaño de lote y coste total unitario para cada caso, además almacenamos el cálculo anterior para poder hacer una comparación
        if(Q == 0){
            Q = *it;
            CP1 = CP;
            Desv = (CP + S)/(cont-a);
            Desv1 = Desv;
            cont++;
        }
        else{
            Q1 = Q;
            Desv1 = Desv;
            Q += *it;
            CP = CP1 + (Q-Q1)*H*(cont -1 - a);
            CP1 = CP;
            Desv = (CP + S)/(cont-a);
            cont++;
        }

        //Cuando el nuevo coste unitario sea mayor que el anterior introducimos los datos calculados con anterioridad y comenzamos el cálculo del nuevo lote
        if (Desv > Desv1){
            lotes++;
            cont--;
            di = D.end();    di--;
            r = RPPL.end(); r--;
            disp = *di+*rp+*r-*nb;
            D.push_back(disp);
            RPPL.push_back(Q1);
            LPPL.push_back(Q1);
            nb++;
            rp++;
            Q -= Q1;
            CP = 0;
            CP1 = 0;
            Desv = (CP + S)/(cont-a);
            Desv1 = Desv;
            for (i = 0; i != cont-2; i++){
                di = D.end();    di--;
                r = RPPL.end(); r--;
                disp = *di+*rp+*r-*nb;
                D.push_back(disp);
                RPPL.push_back(0);
                LPPL.push_back(0);
                nb++;
                rp++;
            }
            cont = 2;
            a = 1;
        }

    }
    lotes++;
    di = D.end();    di--;
    r = RPPL.end(); r--;
    disp = *di+*rp+*r-*nb;
    D.push_back(disp);
    RPPL.push_back(Q);
    LPPL.push_back(Q);
    nb++;
    rp++;
    di = D.end();    di--;
    r = RPPL.end(); r--;
    disp = *di+*rp+*r-*nb;

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
    while (D.size() < 8){
        D.push_back(disp);
    }

    actualizarui(lotes, 0);
}

void MRP::on_pushButton_CRP_clicked()
{
    int Ts = ui->Ts->text().toInt();
    int Qej,i=0;

    vector<int> LPP(8,0);
    LPP[0]=ui->LPPL1->text().toInt();
    LPP[1]=ui->LPPL2->text().toInt();
    LPP[2]=ui->LPPL3->text().toInt();
    LPP[3]=ui->LPPL4->text().toInt();
    LPP[4]=ui->LPPL5->text().toInt();
    LPP[5]=ui->LPPL6->text().toInt();
    LPP[6]=ui->LPPL7->text().toInt();
    LPP[7]=ui->LPPL8->text().toInt();

    //for (int i=0; i<=8; i++) if (LPP[i]!=0) Qej=LPP[i];
    while (LPP[i]==0) i++;
    Qej=LPP[i];

    CRP m(Ts,LPP,Qej,this);
    m.setModal(true);
    m.exec();
}


void MRP::on_Exportar_clicked()
{
    NBP Nbp;
    NNP Nnp;
    DP Dp;
    RPP Rpp;
    RPPLP Rpplp;
    LPPLP Lpplp;
    vector<QString> Ctp = {ui->CosteTotal->text()};
    GLOBAL csv(Nbp.getValor(),Dp.getValor(),Rpp.getValor(),Nnp.getValor(),Rpplp.getValor(),Lpplp.getValor(),Ctp);

    OutputCSV Salida;
    QString filename= QFileDialog::getSaveFileName(this, tr("Guardar como"),"",tr("Archivo .csv (*.csv);;"));
    Salida.crearCSV(csv,filename);

}

