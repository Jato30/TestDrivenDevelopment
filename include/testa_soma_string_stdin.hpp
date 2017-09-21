// Define para impedir include circular
#ifndef __TESTA_SOMA_STRING_STDIN__
#define __TESTA_SOMA_STRING_STDIN__

#include <string>
#include <iostream>
#include <fstream>

typedef unsigned int uint;

/**
    \brief Leitura do arquivo de entrada.
    \return String contendo o conteúdo do arquivo lido.
    \param Caminho do arquivo contendo a string de entrada a ser lida. Este parâmetro é fornecido pelo sistema.

    Função que lê o arquivo com a string de entrada e a retorna.
*/
std::string ReadFile(const std::string);
/**
    \brief Escrita do arquivo de saída.
    \return Tipo bool referente ao sucesso da função.
    \param int Resultado da soma realizada.
    \param std::string Caminho para o arquivo de saída.

    Função que escreve o resultado da calculadora no arquivo de saída.
*/
bool WriteFile(int, std::string = "./resources/OutputString.txt");

#endif // __TESTA_SOMA_STRING_STDIN__
