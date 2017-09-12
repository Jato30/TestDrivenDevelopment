#include "StringCalculator.hpp"

bool StringCalculator(string entry){
    int finalSum = 0, countLimiters = 0;
    char limiter = ',';
    bool readyToFinish = false;

    for(int index = 0; index < entry.size(); index++){ // Lê a entrada
        if(index == 0 && entry.size() > 3){ // Verifica se foi definido um novo delimitador
            if(entry[index] == '/' && entry[index + 1] == '/'){
                limiter = entry[index + 2];
                index = 3;
            }
        }
        
        if(countLimiters > 2){ // Se há mais de 2 delimitadores por linha, dá erro
            return -1;
        }
        if(isDigit(entry[index])){ // Se o valor lido for um dígito, soma-o
            finalSum += (int) entry[index];
            readyToFinish = false;
        }
        if(entry[index] == limiter && isDigit(entry[index + 1])){ // Se o numero lido for um dígito e o próximo um delimitador, incrementa o contador de delimitadores
            countLimiters++;
            readyToFinish = false;
            continue;
        }
        if(entry[index] == '\n' && isDigit(entry[index - 1])){ // verifica quebras de linha
            readyToFinish = true;
            continue;
        }
    }

    return true;
}