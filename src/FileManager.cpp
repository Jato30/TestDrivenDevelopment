#include "FileManager.hpp"

using namespace std;

string ReadFile(const string path){
    string entry;
    ifstream myfile(path);

    if(myfile.is_open()){
        while(getline(myfile, entry)){
            cout << entry;
        }
        myfile.close();
    }

    else{
        cout << "Erro ao abrir o arquivo";
    }

    return entry;
}

bool WriteFile(int sum){
    
    
    return true;
}