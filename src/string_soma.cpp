#include "string_soma.hpp"
#include "testa_soma_string_stdin.hpp"
#include <cctype>
#include <cmath>
#include <vector>

using namespace std;

int string_soma(string string_entrada){
    int finalSum = 0, countLimiters = 0, limiterSize = 1;
    string limiter = ",";
    int readyToFinish = FALSE;
    vector<int> lineDigits; // Quantos dígitos entre cada delimitador

    // Lê a entrada
    for(uint index = 0; index < string_entrada.size(); index++){

        if(isdigit(string_entrada[index])){
            // int tenPower = -1; // Expoente da base 10 para multiplicar o número, transformando em centena, dezena, unidade, etc.
            // for(uint i = index; isdigit(string_entrada[i]) != 0 && i < string_entrada.size(); i++){
            //     tenPower++;
            //     lineDigits.push_back(atoi(&string_entrada[index]));
            // }
            // for(int i = tenPower; i >= 0; i--){
            //     finalSum += lineDigits[tenPower - i] * (int)pow(10.0, (float)i);
            // }

            // lineDigits.clear();
            //index += tenPower;
            if(atoi(&string_entrada[index]) > 0 && atoi(&string_entrada[index]) <= 1000){
                finalSum += atoi(&string_entrada[index]);
            }

            int countDigits = 0;
            int value = atoi(&string_entrada[index]);
            while(value > 9){
                countDigits++;
                value /= 10;
            }

            index += countDigits;
            continue;
        }

    }

    printf("\n%d\n", finalSum);

    WriteFile(finalSum);
    return readyToFinish;
}
