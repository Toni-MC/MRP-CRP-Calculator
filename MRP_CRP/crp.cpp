#include "crp.h"
#include "ui_crp.h"

CRP::CRP(int Ts, vector<int> &vec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRP)
{
    ui->setupUi(this);
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

vector<int> CT(6),te(6),PPA(8),tmp(6),a(6),PPB(8),tc(6),ACT1(8),ACT2(8),BCT1(8),BCT2(8),Total1(8),Total2(8);
int Aa=1,Ab=1,tsa,tsb,QA,QB,TCA1,TCA2,TCB1,TCB2;
float A1,A2,B1,B2;

void CRP::on_Ejecutar_clicked()
{
    /* Crashea
     *
    QString _CT1 = ui->CT1->text(); string CT1=_CT1.toStdString();
    QString _CT2 = ui->CT1->text(); string CT2=_CT2.toStdString();
    QString _CT3 = ui->CT1->text(); string CT3=_CT3.toStdString();
    QString _CT4 = ui->CT1->text(); string CT4=_CT4.toStdString();
    QString _CT5 = ui->CT1->text(); string CT5=_CT5.toStdString();
    QString _CT6 = ui->CT1->text(); string CT6=_CT6.toStdString();

    CT={stoi(CT1),stoi(CT2),stoi(CT3),stoi(CT4),stoi(CT5),stoi(CT6)};


    QString _te1 = ui->te1->text(); string te1=_te1.toStdString();
    QString _te2 = ui->te1->text(); string te2=_te2.toStdString();
    QString _te3 = ui->te1->text(); string te3=_te3.toStdString();
    QString _te4 = ui->te1->text(); string te4=_te4.toStdString();
    QString _te5 = ui->te1->text(); string te5=_te5.toStdString();
    QString _te6 = ui->te1->text(); string te6=_te6.toStdString();

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

    a= {stoi(a1),stoi(a2),stoi(a3),stoi(a4),stoi(a5),stoi(a6)};

    QString _PPA_1 = ui->PPA_1->text(); string PPA_1=_PPA_1.toStdString();
    QString _PPA_2 = ui->PPA_2->text(); string PPA_2=_PPA_2.toStdString();
    QString _PPA_3 = ui->PPA_3->text(); string PPA_3=_PPA_3.toStdString();
    QString _PPA_4 = ui->PPA_4->text(); string PPA_4=_PPA_4.toStdString();
    QString _PPA_5 = ui->PPA_5->text(); string PPA_5=_PPA_5.toStdString();
    QString _PPA_6 = ui->PPA_6->text(); string PPA_6=_PPA_6.toStdString();
    QString _PPA_7 = ui->PPA_7->text(); string PPA_7=_PPA_7.toStdString();
    QString _PPA_8 = ui->PPA_8->text(); string PPA_8=_PPA_8.toStdString();

    PPA={stoi(PPA_1),stoi(PPA_2),stoi(PPA_3),stoi(PPA_4),stoi(PPA_5),stoi(PPA_6),stoi(PPA_7),stoi(PPA_8)};

    QString _PPB_1 = ui->PPB_1->text(); string PPB_1=_PPA_1.toStdString();
    QString _PPB_2 = ui->PPB_2->text(); string PPB_2=_PPA_2.toStdString();
    QString _PPB_3 = ui->PPB_3->text(); string PPB_3=_PPA_3.toStdString();
    QString _PPB_4 = ui->PPB_4->text(); string PPB_4=_PPA_4.toStdString();
    QString _PPB_5 = ui->PPB_5->text(); string PPB_5=_PPA_5.toStdString();
    QString _PPB_6 = ui->PPB_6->text(); string PPB_6=_PPA_6.toStdString();
    QString _PPB_7 = ui->PPB_7->text(); string PPB_7=_PPA_7.toStdString();
    QString _PPB_8 = ui->PPB_8->text(); string PPB_8=_PPA_8.toStdString();

    PPB={stoi(PPB_1),stoi(PPB_2),stoi(PPB_3),stoi(PPB_4),stoi(PPB_5),stoi(PPB_6),stoi(PPB_7),stoi(PPB_8)};

    QString _QA1 = ui->QeA->text(); string QA1=_QA1.toStdString(); QA=stoi(QA1);
    QString _QB1 = ui->QeB->text(); string QB1=_QB1.toStdString(); QB=stoi(QB1);

    QString _TsA = ui->TsA->text(); string TsA=_TsA.toStdString();
    QString _TsB = ui->TsB->text(); string TsB=_TsB.toStdString();
    tsa= stoi(TsA);
    tsb= stoi(TsB);

    for(unsigned int i=0;i<a.size();i++){
        if(i<3){

            //Cálculo de tc
            tc.at(i)=(te.at(i)/60)+(tmp.at(i)/QA);

            //Cálculo de TC
            if(CT.at(i)==1){
                TCA1=TCA1+tc.at(i)/a.at(i);
            }
            else{
                TCA2=TCA2+tc.at(i)/a.at(i);
            }
            //Cálculo de Aj
            Aa= Aa*a.at(i);
        }
        else{

            //Cálculo de tc
            tc.at(i)=(te.at(i)/60)+(tmp.at(i)/QB);

            //Cálculo de tc
            if(CT.at(i)==1){
                TCB1=TCB1+tc.at(i)/a.at(i);
            }
            else{
                TCB2=TCB2+tc.at(i)/a.at(i);
            }
            //Cálculo de Aj
            Ab= Ab*a.at(i);
        }

    }

    //Cálculo del valor del lote
    A1= (TCA1*QA*Aa)/tsa;
    A2= (TCA2*QA*Aa)/tsa;
    B1= (TCB1*QB*Ab)/tsb;
    B2= (TCB2*QB*Ab)/tsb;

    //Emisión de lotes para cada CT para cada producto
    for (int j=0; j<8; j++){
        //Producto A
        if (PPA.at(j)!=0){
            for (int k=0; k<tsa; k++){
                ACT1.at(k+j)=ACT1.at(k+j)+A1;
                ACT2.at(k+j)=ACT2.at(k+j)+A2;
            }
        }
        //Producto B
        if (PPB.at(j)!=0){
            for (int k=0; k<tsb; k++){
                BCT1.at(k+j)=BCT1.at(k+j)+B1;
                BCT2.at(k+j)=BCT2.at(k+j)+B2;
            }
        }
    }
    for (int i=0;i<8;i++){
        Total1.at(i)=ACT1.at(i)+BCT1.at(i);
    }
    actualizarui();
    */
}

void CRP::actualizarui(){
    //tcijk
    ui->tc1->setText(QString::number(tc.at(0)));
    ui->tc2->setText(QString::number(tc.at(1)));
    ui->tc3->setText(QString::number(tc.at(2)));
    ui->tc4->setText(QString::number(tc.at(3)));
    ui->tc5->setText(QString::number(tc.at(4)));
    ui->tc6->setText(QString::number(tc.at(5)));

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
    ui->CT2A_1->setText(QString::number(ACT2.at(0)));
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
    vector<QString> row;

    string line, word;

    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QString line = file.readLine();
        row= line.split(',').toVector().toStdVector();

        if (row[0]=="Ts")       Ts=row;
        if (row[0]=="Qej")      Qej=row;
        if (row[0]=="PPL")      PPL=row;

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
    vector<QString> row;

    string line, word;

    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QString line = file.readLine();
        row= line.split(',').toVector().toStdVector();

        if (row[0]=="Ts")       Ts=row;
        if (row[0]=="Qej")      Qej=row;
        if (row[0]=="PPL")      PPL=row;

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
    vector<QString> tmp;
    vector<QString> ai;
    vector<QString> PPL;
    vector<QString> row;

    string line, word;

    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QString line = file.readLine();
        row= line.split(',').toVector().toStdVector();

        if (row[0]=="CTk")      CTk=row;
        if (row[0]=="tei")      tei=row;
        if (row[0]=="tmp")      tmp=row;
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
    ui->tmp1->setText(tmp[1]);
    ui->tmp2->setText(tmp[2]);
    ui->tmp3->setText(tmp[3]);
    ui->tmp4->setText(tmp[4]);
    ui->tmp5->setText(tmp[5]);
    ui->tmp6->setText(tmp[6]);

    // ai
    ui->a1->setText(ai[1]);
    ui->a2->setText(ai[2]);
    ui->a3->setText(ai[3]);
    ui->a4->setText(ai[4]);
    ui->a5->setText(ai[5]);
    ui->a6->setText(ai[6]);


    file.close();
}

