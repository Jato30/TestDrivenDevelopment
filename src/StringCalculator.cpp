#include "StringCalculator.hpp"
#include "FileManager.hpp"
#include <cctype>
#include <cmath>
#include <vector>

using namespace std;

int StringCalculator(string entry){
    int finalSum = 0, countLimiters = 0, limiterSize = 1;
    string limiter = ",";
    int readyToFinish = FALSE;
    vector<int> lineDigits; // Quantos dígitos entre cada delimitador

    // Lê a entrada
    for(uint index = 0; index < entry.size(); index++){
        
        if(isdigit(entry[index])){
        	int tenPower = -1; // Expoente da base 10 para multiplicar o número, transformando em centena, dezena, unidade, etc.
        	for(uint i = index; isdigit(entry[i]) != 0 && i < entry.size(); i++){
	  		tenPower++;
        		lineDigits.push_back(atoi(&entry[index]));
        	}
        	for(int i = tenPower; i >= 0; i--){
        		finalSum += lineDigits[tenPower - i] * (int)pow(10.0, (float)tenPower);
        	}
        	
        	index += tenPower;
        	continue;
        }

    }

    printf("\n%d\n", finalSum);

    WriteFile(finalSum);
    return readyToFinish;
}
