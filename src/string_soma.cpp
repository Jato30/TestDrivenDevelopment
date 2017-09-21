#include "string_soma.hpp"
#include "testa_soma_string_stdin.hpp"
#include <cctype>
#include <cmath>
#include <vector>

using namespace std;

int string_soma(string string_entrada){
    uint countLimiters = 0, limiterSize = 1;
    string limiter = ",";
    int finalSum = 0, readyToFinish = FALSO;
    vector<int> lineDigits; // Quantos dígitos entre cada delimitador

    // Lê a entrada
    for(uint index = 0; index < string_entrada.size(); index++){

        // Se for número, some
        if(isdigit(string_entrada[index])){

            // Só some se for entre 1 e 1000
            if(atoi(&string_entrada[index]) > 0 && atoi(&string_entrada[index]) <= 1000){
                finalSum += atoi(&string_entrada[index]);
            }

            // Conte quantos dígitos o número lido tem para poder avançar o loop a quantidade de casas lidas simultaneamente
            uint countDigits = -1;
            for(uint i = index; i < string_entrada.size(); i++){
                if(isdigit(string_entrada[i])){
                    countDigits++;
                }
                else{
                    break;
                }
            }

            // Avance no loop a quantidade de dígitos - 1 do número lido
            index += countDigits;
            readyToFinish = FALSO;
            continue;
        }


        // Se for um caractere não-número
        if(isdigit(string_entrada[index]) == 0){
            // Sintaxe de definição de novo delimitador
            if(index == 0){
                // Se a sintaxe estiver correta
                if(string_entrada[index] == '/' && string_entrada[index + 1] == '/' && string_entrada[index + 2] == '['){
                    index += 3;

                    limiter.clear();
                    limiter.push_back(string_entrada[index]);
                    for(uint i = index + 1; i < string_entrada.size() && string_entrada[i] != ']'; i++){
                        limiter += string_entrada[i];
                        limiterSize++;
                    }
                    index += limiterSize;
                }
                // Se a sintaxe estiver errada
                else{
                    return FALSO;
                }
            
                { // Se não for número e não for definição de novo caratere, Se for um delimitador
                    string supposedLimiter;
                    supposedLimiter.clear();
                    supposedLimiter.push_back(string_entrada[index - limiterSize]);
                    for(uint i = index - limiterSize + 1; i < limiterSize; i++){
                        supposedLimiter += string_entrada[i];
                    }
                    if(supposedLimiter != limiter){
                        return FALSO;
                    }
                    else{
                        continue;
                    }
                }
            }
            if(string_entrada[index] == limiter[0]){
                for(uint i = index; i < limiterSize + index; i++){
                    if(string_entrada[i] != limiter[i - index]){
                        return FALSO;
                    }
                }
                index += limiterSize - 1;
                continue;
            }
            else if(string_entrada[index] != '\n'){
                return FALSO;
            }
        }

        // Se houve uma quebra de linha após um número
        if(isspace(string_entrada[index]) && index != 0){
            if(string_entrada[index] == '\n'){
                if(isdigit(string_entrada[index - 1])){
                    readyToFinish = VERDADEIRO;
                }
            }
            else{
                return FALSO;
            }
        }
    }

    printf("\n%d\n", finalSum);

    WriteFile(finalSum);
    return readyToFinish;
}
