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
    vector<string> RecProg;
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
            if (row[0]=="R.Prog")   RecProg=row;

            content.push_back(row); // Para vector de vectores
        }
    }
    else
        cout<<"Could not open the file\n";

    for(unsigned i=0;i<NN.size();i++) cout<<NN[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<D.size();i++) cout<<D[i]<<" ";
    cout << endl;

    for(unsigned i=0;i<RecProg.size();i++) cout<<RecProg[i]<<" ";
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
