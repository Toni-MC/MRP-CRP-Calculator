#include "crp.h"
#include "ui_crp.h"

CRP::CRP(int Ts, vector<int> &vec, int Qej, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRP)
{
    ui->setupUi(this);

    ui->QeA->setText(QString::number(Qej));
    ui->TsA->setText(QString::number(Ts));
    ui->PPA_1->setText(QString::number(vec[0]));
    ui->PPA_2->setText(QString::number(vec[1]));
    ui->PPA_3->setText(QString::number(vec[2]));
    ui->PPA_4->setText(QString::number(vec[3]));
    ui->PPA_5->setText(QString::number(vec[4]));
    ui->PPA_6->setText(QString::number(vec[5]));
    ui->PPA_7->setText(QString::number(vec[6]));
    ui->PPA_8->setText(QString::number(vec[7]));

}

CRP::~CRP()
{
    delete ui;
}

void CRP::on_SALIR_clicked()
{
    close();
}

vector<int> CT(6),te(6),tmp(6);
vector<float> tc,a(6),PPB(15),PPA(15),ACT1(15),ACT2(15),BCT1(15),BCT2(15),Total1(15),Total2(15);
int tsa,tsb,QA,QB;
float A1,A2,B1,B2,TCA1,TCA2,TCB1,TCB2, Aa=1,Ab=1;

void CRP::on_Ejecutar_clicked()
{
    //Primero se guardan todos los datos del ui en los vectores y variables
    QString _CT1 = ui->CT1->text(); string CT1=_CT1.toStdString();
    QString _CT2 = ui->CT2->text(); string CT2=_CT2.toStdString();
    QString _CT3 = ui->CT3->text(); string CT3=_CT3.toStdString();
    QString _CT4 = ui->CT4->text(); string CT4=_CT4.toStdString();
    QString _CT5 = ui->CT5->text(); string CT5=_CT5.toStdString();
    QString _CT6 = ui->CT6->text(); string CT6=_CT6.toStdString();

    CT={stoi(CT1),stoi(CT2),stoi(CT3),stoi(CT4),stoi(CT5),stoi(CT6)};


    QString _te1 = ui->te1->text(); string te1=_te1.toStdString();
    QString _te2 = ui->te2->text(); string te2=_te2.toStdString();
    QString _te3 = ui->te3->text(); string te3=_te3.toStdString();
    QString _te4 = ui->te4->text(); string te4=_te4.toStdString();
    QString _te5 = ui->te5->text(); string te5=_te5.toStdString();
    QString _te6 = ui->te6->text(); string te6=_te6.toStdString();

    te={stoi(te1),stoi(te2),stoi(te3),stoi(te4),stoi(te5),stoi(te6)};

    QString _tmp1 = ui->tmp1->text(); string tmp1= _tmp1.toStdString();
    QString _tmp2 = ui->tmp2->text(); string tmp2= _tmp2.toStdString();
    QString _tmp3 = ui->tmp3->text(); string tmp3= _tmp3.toStdString();
    QString _tmp4 = ui->tmp4->text(); string tmp4= _tmp4.toStdString();
    QString _tmp5 = ui->tmp5->text(); string tmp5= _tmp5.toStdString();
    QString _tmp6 = ui->tmp6->text(); string tmp6= _tmp6.toStdString();

    tmp= {stoi(tmp1),stoi(tmp2),stoi(tmp3),stoi(tmp4),stoi(tmp5),stoi(tmp6)};

    QString _a1 = ui->a1->text(); string a1= _a1.toStdString();
    QString _a2 = ui->a2->text(); string a2= _a2.toStdString();
    QString _a3 = ui->a3->text(); string a3= _a3.toStdString();
    QString _a4 = ui->a4->text(); string a4= _a4.toStdString();
    QString _a5 = ui->a5->text(); string a5= _a5.toStdString();
    QString _a6 = ui->a6->text(); string a6= _a6.toStdString();

    a= {stof(a1),stof(a2),stof(a3),stof(a4),stof(a5),stof(a6)};

    QString _PPA_1 = ui->PPA_1->text(); string PPA_1=_PPA_1.toStdString();
    QString _PPA_2 = ui->PPA_2->text(); string PPA_2=_PPA_2.toStdString();
    QString _PPA_3 = ui->PPA_3->text(); string PPA_3=_PPA_3.toStdString();
    QString _PPA_4 = ui->PPA_4->text(); string PPA_4=_PPA_4.toStdString();
    QString _PPA_5 = ui->PPA_5->text(); string PPA_5=_PPA_5.toStdString();
    QString _PPA_6 = ui->PPA_6->text(); string PPA_6=_PPA_6.toStdString();
    QString _PPA_7 = ui->PPA_7->text(); string PPA_7=_PPA_7.toStdString();
    QString _PPA_8 = ui->PPA_8->text(); string PPA_8=_PPA_8.toStdString();

    PPA={stof(PPA_1),stof(PPA_2),stof(PPA_3),stof(PPA_4),stof(PPA_5),stof(PPA_6),stof(PPA_7),stof(PPA_8)};

    QString _PPB_1 = ui->PPB_1->text(); string PPB_1=_PPB_1.toStdString();
    QString _PPB_2 = ui->PPB_2->text(); string PPB_2=_PPB_2.toStdString();
    QString _PPB_3 = ui->PPB_3->text(); string PPB_3=_PPB_3.toStdString();
    QString _PPB_4 = ui->PPB_4->text(); string PPB_4=_PPB_4.toStdString();
    QString _PPB_5 = ui->PPB_5->text(); string PPB_5=_PPB_5.toStdString();
    QString _PPB_6 = ui->PPB_6->text(); string PPB_6=_PPB_6.toStdString();
    QString _PPB_7 = ui->PPB_7->text(); string PPB_7=_PPB_7.toStdString();
    QString _PPB_8 = ui->PPB_8->text(); string PPB_8=_PPB_8.toStdString();

    PPB={stof(PPB_1),stof(PPB_2),stof(PPB_3),stof(PPB_4),stof(PPB_5),stof(PPB_6),stof(PPB_7),stof(PPB_8)};

    QString _QA1 = ui->QeA->text(); string QA1=_QA1.toStdString(); QA=stoi(QA1);
    QString _QB1 = ui->QeB->text(); string QB1=_QB1.toStdString(); QB=stoi(QB1);

    QString _TsA = ui->TsA->text(); string TsA=_TsA.toStdString();
    QString _TsB = ui->TsB->text(); string TsB=_TsB.toStdString();
    tsa= stoi(TsA);
    tsb= stoi(TsB);
/*
    for(unsigned int i=0;i<6;i++){
        if(i<3){

            //Cálculo de tciAk
            tc.at(i)=(te.at(i)/60)+(tmp.at(i)/QA);

            //Cálculo de TCAk
            if(CT.at(i)==1){
                TCA1=TCA1+tc.at(i)/a.at(i);
            }
            else{
                TCA2=TCA2+tc.at(i)/a.at(i);
            }
            //Cálculo de Aa
            Aa= Aa*a.at(i);
        }
        else{

            //Cálculo de tciBk
            tc.at(i)=(te.at(i)/60)+(tmp.at(i)/QB);

            //Cálculo de TCBk
            if(CT.at(i)==1){
                TCB1=TCB1+tc.at(i)/a.at(i);
            }
            else{
                TCB2=TCB2+tc.at(i)/a.at(i);
            }
            //Cálculo de Ab
            Ab= Ab*a.at(i);
        }

    }
*/
    //Método con sólo iteradores y sin .at()
    vector<int>::iterator e,p,t;
    vector<float>::iterator it;
    vector<float> vi={a.at(0)*a.at(1)*a.at(2),a.at(1)*a.at(2),a.at(2),a.at(3)*a.at(4)*a.at(5),a.at(4)*a.at(5),a.at(5)};
    p= tmp.begin(); t= CT.begin();  it= vi.begin();
    int i= 0;
    float num= 0;



    for(e= te.begin(); e!= te.end(); e++){
        if(i<3){

            //Cálculo de tciAk
            tc.push_back(((float)*e/60)+((float)*p/(float)QA));
            num= ((float)*e/60)+((float)*p/(float)QA);

            //Cálculo de TCAk
            if(*t==1){
                TCA1=TCA1+num/(*it);
            }
            else{
                TCA2=TCA2+num/(*it);
            }
            i++;
            p++;
            t++;
            it++;
        }
        else{

            //Cálculo de tciBk
            tc.push_back(((float)*e/60)+((float)*p/(float)QA));
            num= ((float)*e/60)+((float)*p/(float)QA);

            //Cálculo de TCBk
            if(*t==1){
                TCB1=TCB1+num/(*it);
            }
            else{
                TCB2=TCB2+num/(*it);
            }         
            i++;
            p++;
            t++;
            it++;
        }

    }
    //Cálculo de Aa
    Aa= vi.at(0);
    //Cálculo de Ab
    Ab= vi.at(3);

    //Cálculo del valor del lote
    A1= (TCA1*QA*Aa)/(float)tsa;
    A2= (TCA2*QA*Aa)/(float)tsa;
    B1= (TCB1*QB*Ab)/(float)tsb;
    B2= (TCB2*QB*Ab)/(float)tsb;

    //Emisión de lotes para cada CT para cada producto
    for (int j=0; j<8; j++){
        //Producto A
        if (PPA.at(j)!=0){
            for (int k=0; k<tsa; k++){
                ACT1.at(k+j+1)=ACT1.at(k+j+1)+A1;
                ACT2.at(k+j+1)=ACT2.at(k+j+1)+A2;
            }
        }
        //Producto B
        if (PPB.at(j)!=0){
            for (int k=0; k<tsb; k++){
                BCT1.at(k+j+1)=BCT1.at(k+j+1)+B1;
                BCT2.at(k+j+1)=BCT2.at(k+j+1)+B2;
            }
        }
    }
    for (int i=0;i<8;i++){
        Total1.at(i)=ACT1.at(i)+BCT1.at(i);
        Total2.at(i)=ACT2.at(i)+BCT2.at(i);
    }
    actualizarui();
    //Vaciar vectores
    TCA1=0;
    TCB1=0;
    TCA2=0;
    TCB2=0;
    for(int i=0;i<15;i++){
        ACT1.at(i)=0;
        ACT2.at(i)=0;
        BCT1.at(i)=0;
        BCT2.at(i)=0;
    }




}
void CRP::actualizarui(){
    //tcijk
    ui->tc1->setText(QString::number(tc.at(0)));
    ui->tc2->setText(QString::number(tc.at(1)));
    ui->tc3->setText(QString::number(tc.at(2)));
    ui->tc4->setText(QString::number(tc.at(3)));
    ui->tc5->setText(QString::number(tc.at(4)));
    ui->tc6->setText(QString::number(tc.at(5)));

    //TC
    ui->TC1A->setText(QString::number(TCA1));
    ui->TCB1->setText(QString::number(TCB1));
    ui->TC2A->setText(QString::number(TCA2));
    ui->TC2B->setText(QString::number(TCB2));

    //Aj
    ui->AJA1->setText(QString::number(Aa));
    ui->AJA2->setText(QString::number(Aa));
    ui->AJB1->setText(QString::number(Ab));
    ui->AJB2->setText(QString::number(Ab));

    //Qj
    ui->QA1->setText(QString::number(QA));
    ui->QA2->setText(QString::number(QA));
    ui->QB1->setText(QString::number(QB));
    ui->QB2->setText(QString::number(QB));

    //CT1
    ui->CT1A_1->setText(QString::number(ACT1.at(0)));
    ui->T1_1->setText(QString::number(Total1.at(0)));
    ui->CT1B_1->setText(QString::number(BCT1.at(0)));
    ui->CT1A_2->setText(QString::number(ACT1.at(1)));
    ui->CT1B_2->setText(QString::number(BCT1.at(1)));
    ui->T1_2->setText(QString::number(Total1.at(1)));
    ui->CT1A_3->setText(QString::number(ACT1.at(2)));
    ui->CT1B_3->setText(QString::number(BCT1.at(2)));
    ui->T1_3->setText(QString::number(Total1.at(2)));
    ui->CT1A_4->setText(QString::number(ACT1.at(3)));
    ui->CT1B_4->setText(QString::number(BCT1.at(3)));
    ui->T1_4->setText(QString::number(Total1.at(3)));
    ui->CT1A_5->setText(QString::number(ACT1.at(4)));
    ui->CT1B_5->setText(QString::number(BCT1.at(4)));
    ui->T1_5->setText(QString::number(Total1.at(4)));
    ui->CT1A_6->setText(QString::number(ACT1.at(5)));
    ui->CT1B_6->setText(QString::number(BCT1.at(5)));
    ui->T1_6->setText(QString::number(Total1.at(5)));
    ui->CT1A_7->setText(QString::number(ACT1.at(6)));
    ui->CT1B_7->setText(QString::number(BCT1.at(6)));
    ui->T1_7->setText(QString::number(Total1.at(6)));
    ui->CT1A_8->setText(QString::number(ACT1.at(7)));
    ui->CT1B_8->setText(QString::number(BCT1.at(7)));
    ui->T1_8->setText(QString::number(Total1.at(7)));

    //CT2
    ui->CT2A_1->setText(QString::number(ACT2.at(0)));
    ui->CT2A_2->setText(QString::number(ACT2.at(1)));
    ui->CT2A_3->setText(QString::number(ACT2.at(2)));
    ui->CT2A_4->setText(QString::number(ACT2.at(3)));
    ui->CT2A_5->setText(QString::number(ACT2.at(4)));
    ui->CT2A_6->setText(QString::number(ACT2.at(5)));
    ui->CT2A_7->setText(QString::number(ACT2.at(6)));
    ui->CT2A_8->setText(QString::number(ACT2.at(7)));
    ui->CT2B_1->setText(QString::number(BCT2.at(0)));
    ui->CT2B_2->setText(QString::number(BCT2.at(1)));
    ui->CT2B_3->setText(QString::number(BCT2.at(2)));
    ui->CT2B_4->setText(QString::number(BCT2.at(3)));
    ui->CT2B_5->setText(QString::number(BCT2.at(4)));
    ui->CT2B_6->setText(QString::number(BCT2.at(5)));
    ui->CT2B_7->setText(QString::number(BCT2.at(6)));
    ui->CT2B_8->setText(QString::number(BCT2.at(7)));
    ui->T2_1->setText(QString::number(Total2.at(0)));
    ui->T2_2->setText(QString::number(Total2.at(1)));
    ui->T2_3->setText(QString::number(Total2.at(2)));
    ui->T2_4->setText(QString::number(Total2.at(3)));
    ui->T2_5->setText(QString::number(Total2.at(4)));
    ui->T2_6->setText(QString::number(Total2.at(5)));
    ui->T2_7->setText(QString::number(Total2.at(6)));
    ui->T2_8->setText(QString::number(Total2.at(7)));



}

void CRP::on_pushButton_ExcelA_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona la base de Datos"), "",tr("Archivo .csv (*.csv)"));

    vector<QString> Ts;
    vector<QString> Qej;
    vector<QString> PPL;
    vector<QString> row(9);

    int k;
    string line, word;

    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QString line = file.readLine();

        // Sólo valido para Qt 5.12.12 y anteriores
        // la función de Qvector, toStdVector no está disponible
        // a partir de Qt.6
        // row= line.split(',').toVector().toStdVector();

        QVector<QString> rowaux=line.split(',').toVector();
        //cout << rowaux.size()<< endl;

        if (rowaux.size()==9) k=0;
        if (rowaux.size()==10) k=1;

        for (int i=0; i<rowaux.size()-k;i++) {
            row[i]=rowaux[i];
            //cout << i << ": ";
            //cout << row[i].toStdString() << endl;
        }
        //cout << row[0].toStdString() << endl;

        if (row[0]=="Ts")       Ts=row;
        if (row[0]=="Qej")      Qej=row;
        if (row[0]=="LPPL")     PPL=row;

    }
    // Ts
    ui->TsA->setText(Ts[1]);

    // Qej
    ui->QeA->setText(Qej[1]);

    // PPL
    ui->PPA_1->setText(PPL[1]);
    ui->PPA_2->setText(PPL[2]);
    ui->PPA_3->setText(PPL[3]);
    ui->PPA_4->setText(PPL[4]);
    ui->PPA_5->setText(PPL[5]);
    ui->PPA_6->setText(PPL[6]);
    ui->PPA_7->setText(PPL[7]);
    ui->PPA_8->setText(PPL[8]);

    file.close();
}


void CRP::on_pushButton_ExcelB_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona la base de Datos"), "",tr("Archivo .csv (*.csv)"));

    vector<QString> Ts;
    vector<QString> Qej;
    vector<QString> PPL;
    vector<QString> row(9);
    int k;

    string line, word;

    QFile file (filename);


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QString line = file.readLine();

        // Sólo valido para Qt 5.12.12 y anteriores
        // la función de Qvector, toStdVector no está disponible
        // a partir de Qt.6
        // row= line.split(',').toVector().toStdVector();

        QVector<QString> rowaux=line.split(',').toVector();
        //cout << rowaux.size()<< endl;
        if (rowaux.size()==9) k=0;
        if (rowaux.size()==10) k=1;

        cout << endl;
        for (int i=0; i<rowaux.size()-k;i++) {
            row[i]=rowaux[i];
            //cout << i << ": ";
            //cout << row[i].toStdString() << endl;
        }
        //cout << row[0].toStdString() << endl;

        if (row[0]=="Ts")       Ts=row;
        if (row[0]=="Qej")      Qej=row;
        if (row[0]=="LPPL")     PPL=row;

    }
    // Ts
    ui->TsB->setText(Ts[1]);

    // Qej
    ui->QeB->setText(Qej[1]);

    // PPL
    ui->PPB_1->setText(PPL[1]);
    ui->PPB_2->setText(PPL[2]);
    ui->PPB_3->setText(PPL[3]);
    ui->PPB_4->setText(PPL[4]);
    ui->PPB_5->setText(PPL[5]);
    ui->PPB_6->setText(PPL[6]);
    ui->PPB_7->setText(PPL[7]);
    ui->PPB_8->setText(PPL[8]);

    file.close();
}


void CRP::on_pushButton_ExcelComun_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona la base de Datos"), "",tr("Archivo .csv (*.csv)"));

    vector<QString> Ts;
    vector<QString> Qej;
    vector<QString> CTk;
    vector<QString> tei;
    vector<QString> tmpp;
    vector<QString> ai;
    vector<QString> PPL;
    vector<QString> row(9);

    string line, word;

    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QString line = file.readLine();

        // Sólo valido para Qt 5.12.12 y anteriores
        // la función de Qvector, toStdVector no está disponible
        // a partir de Qt.6
        // row= line.split(',').toVector().toStdVector();

        QVector<QString> rowaux=line.split(',').toVector();
        for (int i=0; i<rowaux.size();i++) row[i]=rowaux[i];

        if (row[0]=="CTk")      CTk=row;
        if (row[0]=="tei")      tei=row;
        if (row[0]=="tmp")      tmpp=row;
        if (row[0]=="ai")       ai=row;

    }

    // CTk
    ui->CT1->setText(CTk[1]);
    ui->CT2->setText(CTk[2]);
    ui->CT3->setText(CTk[3]);
    ui->CT4->setText(CTk[4]);
    ui->CT5->setText(CTk[5]);
    ui->CT6->setText(CTk[6]);

    // tei
    ui->te1->setText(tei[1]);
    ui->te2->setText(tei[2]);
    ui->te3->setText(tei[3]);
    ui->te4->setText(tei[4]);
    ui->te5->setText(tei[5]);
    ui->te6->setText(tei[6]);

    // tmp
    ui->tmp1->setText(tmpp[1]);
    ui->tmp2->setText(tmpp[2]);
    ui->tmp3->setText(tmpp[3]);
    ui->tmp4->setText(tmpp[4]);
    ui->tmp5->setText(tmpp[5]);
    ui->tmp6->setText(tmpp[6]);

    // ai
    ui->a1->setText(ai[1]);
    ui->a2->setText(ai[2]);
    ui->a3->setText(ai[3]);
    ui->a4->setText(ai[4]);
    ui->a5->setText(ai[5]);
    ui->a6->setText(ai[6]);


    file.close();
}

