#include "FileManager.hpp"

using namespace std;

string ReadFile(const string path){
    string entry;

    FILE *filePtr= fopen(path.c_str(), "r");
	if(NULL == filePtr){
		cout << "\tNão foi possivel abrir o arquivo: " << path << endl;
	}

    while(fscanf(filePtr, "%s", entry) == 1);
	fclose(filePtr);

    return entry;
}

const bool WriteFile(const int sum) const{
    
    
    return true;
}