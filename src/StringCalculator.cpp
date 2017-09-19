#include "StringCalculator.hpp"
#include <cctype>

int StringCalculator(string entry){
    int finalSum = 0, countLimiters = 0;
    char limiter = ',';
    int readyToFinish = FALSE;

    // Lê a entrada
    for(uint index = 0; index < entry.size(); index++){

        // // Verifica se foi definido um novo delimitador
        // if(index == 0 && entry.size() > 5){
        //     if(entry[index] == '/' && entry[index + 1] == '/' && entry[index + 2] == '['){
        //         index = 3;

        //         limiter = "";

        //         while(entry[index] == ']'){
        //             limiter += entry[index];
        //             index++;
        //         }
        //     }
        // }
        
        // Se há mais de 2 delimitadores por linha, dá erro
        if(countLimiters > 2){
            return FALSE;
        }

        // Se o valor lido for um dígito, soma-o
        if(isdigit(entry[index])){
            finalSum += (int) entry[index];
            readyToFinish = FALSE;
        }

        // Se o número lido for um dígito e o próximo um delimitador, incrementa o contador de delimitadores
        if(entry[index] == limiter && isdigit(entry[index + 1])){
            countLimiters++;
            readyToFinish = FALSE;
            continue;
        }

        // Verifica quebras de linha
        if(entry[index] == '\\' && entry[index + 1] == 'n' && isdigit(entry[index - 1])){
            readyToFinish = TRUE;
            break;
        }
    }

    printf("\n%d\n", finalSum);

    return readyToFinish;
}