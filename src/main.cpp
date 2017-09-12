// Headers
#include <string>
#include "string_soma.hpp"

int main(int argc, char** argv){
    if(argc < 2){
		printf("Falha ao receber argumentos.\n");
		exit(1);
    }
    
    StringCalculator(ReadFile(argv));
    
    return 0;
}