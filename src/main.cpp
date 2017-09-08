// Headers
#include <string>

// Namespace std para tipo string
using std::string;

// Declaração de funções
int SomaString(string);

// Função que
int SomaString(string entry){
    int sum = 0, countPerLine = 0;
    char limit = ',';

    for(int index = 0; index < entry.size(); index++){
        if(index == 0 && entry.size() > 3){
            if(entry[index] == '/' && entry[index + 1] == '/'){
                limit = entry[index + 2];
                index = 3;
            }
        }
        
        if(countPerLine > 2){
            return 0;
        }
        if(isDigit(entry[index])){
            sum += (int) entry[index];
        }
        if(entry[index] == limit && isDigit(entry[index + 1])){
            countPerLine++;
            continue;
        }
        if(entry[index] == '\n' && isDigit(entry[index - 1])){
            continue;
        }
    }
}

int main(int argc, int argv**){
    if(argc < 2){
		printf("Falha ao receber argumentos.\n");
		exit(1);
	}
    
    return 0;
}