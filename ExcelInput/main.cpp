#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
int main()
{
    string fname;

    vector<vector<string>> content;

    vector<string> NN;
    vector<string> D;
    vector<string> RP;
    vector<string> SS;
    vector<string> Ts;
    vector<string> S;
    vector<string> H;

    vector<string> row;

    string line, word;

    fstream file ("C:\\Datos.csv", ios::in);
    if(file.is_open())
    {
        while(getline(file, line))  // Guardar una linea entera en line
        {
            row.clear();
            stringstream str(line);

            while(getline(str, word, ','))  // Guardar cada elemento de linea en vector row
                row.push_back(word);

            if (row[0]=="NN")       NN=row;
            if (row[0]=="D")        D=row;
            if (row[0]=="RP")       RP=row;
            if (row[0]=="SS")       SS=row;
            if (row[0]=="T")       Ts=row;
            if (row[0]=="S")        S=row;
            if (row[0]=="H")        H=row;

            content.push_back(row); // Para vector de vectores
        }
    }
    else
        cout<<"Could not open the file\n";

    for(unsigned i=0;i<NN.size();i++) cout<<NN[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<D.size();i++) cout<<D[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<RP.size();i++) cout<<RP[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<SS.size();i++) cout<<SS[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<Ts.size();i++) cout<<Ts[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<S.size();i++) cout<<S[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<H.size();i++) cout<<H[i]<<" ";
    cout << endl;



    // Vector de vectores
    /*
    for(unsigned int i=0;i<content.size();i++)
    {
        for(unsigned int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<" ";
        }
        cout<<"\n";
    }
    */


    return 0;
}
