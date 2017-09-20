#include "FileManager.hpp"
#include <cstdio>
#include <vector>

using namespace std;

string ReadFile(const string path){
    vector<string> entry;
    string line;

    ifstream file;
    file.open(path.c_str());

    while(!file.eof()){
        file >> line;
        entry.push_back(line);
    }

    file.close();

    string toReturn = "";
    for(uint index = 1; index < entry.size(); ++index){
        toReturn += entry[index];
        toReturn += "\n";
    }

    return toReturn;
}

bool WriteFile(int sum, string path){
    ofstream myfile(path);
    
    if(myfile.is_open()){
        myfile << sum;
        myfile.close();
    }
    else{
        cout << "Impossivel abrir arquivo" << endl;
        return false;
    }

    return true;
}
