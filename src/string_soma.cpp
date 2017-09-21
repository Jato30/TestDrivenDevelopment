#include "string_soma.hpp"
#include "testa_soma_string_stdin.hpp"
#include <cctype>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int string_soma(string string_entrada){
    vector<string> limiter;/**< Vetor de delimitadores*/
    vector<uint> limiterSize;/**< Vetor de tamanhos dos delimitadores (um tamanho para cada)*/
    uint countLimiters = 1;/**< Contador de delimitadores*/
    int finalSum = 0;/**< Soma final da calculadora*/
    int readyToFinish = FALSO;/**< Valor de retorno. Setada VERDADEIRO quando aparecer um número e, em seguida, uma quebra de linha*/
    bool canBeLimiter = false;/**< Flag que determina, pela sintaxe, pode haver um delimitador no momento*/

    limiter.clear();
    limiter.push_back(","); // Define o delimitador padrão
    limiterSize.push_back(1); // Define tamanho do delimitador padrão

    // Lê a entrada
    for(uint index = 0; index < string_entrada.size(); index++){

        // Se for número, somar-se-á
        {
            if(isdigit(string_entrada[index])){

                // Não podem existir números negativos
                if(atoi(&string_entrada[index]) < 0){
                    return FALSO;
                }

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
                canBeLimiter = true;
                continue;
            }
        }



        // Se for um caractere não-número
        {
            if(isdigit(string_entrada[index]) == 0){ // Se NÃO for número


                // Quebras de linha podem vir a qualquer momento
                if(string_entrada[index] == '\n'){
                    if(canBeLimiter){
                        readyToFinish = VERDADEIRO;
                    }
                    continue;
                }


                // Definição de novo delimitador
                {
                    if(index == 0){
                        // Se a sintaxe estiver correta
                        if(string_entrada[index] == '/' && string_entrada[index + 1] == '/' && string_entrada[index + 2] == '['){
                            index += 3;
                            // Delimitadores não podem ser dígitos ou espaçamentos e nem ser vazios
                            if(isdigit(string_entrada[index]) || isspace(string_entrada[index]) || string_entrada[index] == ']'){
                                return FALSO;
                            }

                            // Reseta informações de delimitadores
                            limiter[0].clear(); // Limpa o delimitador
                            countLimiters = 0; // Reseta a quantidade de delimitadores
                            limiterSize.clear(); // Reseta vetor de tamanhos dos delimitadores
                            limiterSize.push_back(0); // Zera tamanho do primeiro delimitador que será acrescido

                            limiter[countLimiters].push_back(string_entrada[index]); // Acrescenta o novo delimitador
                            limiterSize[countLimiters]++; // Incrementa tamanho do primeiro delimitador

                            do{
                                for(uint i = index + 1; i < string_entrada.size() && string_entrada[i] != ']'; i++){
                                    // Delimitadores não podem ser dígitos ou espaçamentos
                                    if(isdigit(string_entrada[i]) || isspace(string_entrada[i])){
                                        return FALSO;
                                    }

                                    limiter[countLimiters] += string_entrada[i];
                                    limiterSize[countLimiters]++;
                                }
                                index += limiterSize[countLimiters];
                                countLimiters++; // Incrementa o contador de delimitadores
                                // limiter[countLimiters].clear(); // Limpa a posição do próximo delimitador para caso haja um

                                if(string_entrada[index] == '['){
                                    index++;
                                }
                                else if(string_entrada[index] != '\n' && string_entrada[index] != ']'){
                                    return FALSO;
                                }
                            }
                            while(string_entrada[index] != ']' && string_entrada[index + 1] != '\n');

                            canBeLimiter = false;
                        }
                        // Se a sintaxe estiver errada
                        else{
                            return FALSO;
                        }

                        continue;
                    }
                }



                // Delimitador entre números
                {
                    if(canBeLimiter){

                        // Verifica se existe algum delimitador na base igual ao caractere lido
                        for(uint i = 0; i < countLimiters; i++){

                            // Se encontrar algum primeiro dígito igual
                            if(string_entrada[index] == limiter[i][0]){
                                
                                // Percorre esse delimitador compatível para ver se é completamente igual
                                for(uint j = 0; j < limiterSize[i]; j++){
                                    if(string_entrada[index + j] != limiter[i][j]){
                                        return FALSO;
                                    }
                                }
                                canBeLimiter = false; // Não pode ter um delimitador após o outro
                                readyToFinish = FALSO; // Não pode encerrar com delimitador
                            }
                        }
                        continue;
                    }
                    // Se for um não-número, mas não puder ser no momento
                    else{
                        return FALSO;
                    }
                }

            }
        }



        // Se houve uma quebra de linha após um número
        {
            if(isspace(string_entrada[index]) && index != 0){
                if(string_entrada[index] == '\n' && canBeLimiter){
                    readyToFinish = VERDADEIRO;
                }
            }
        }
    }



    if(readyToFinish != FALSO){
        printf("\n%d\n", finalSum);
    
        WriteFile(finalSum);
    }

    return readyToFinish;
}
