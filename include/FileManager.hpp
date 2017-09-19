// Define para impedir include circular
#ifndef __FILEMANAGER__
#define __FILEMANAGER__

#include <string>
#include <iostream>
#include <fstream>

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
    \param Resultado da soma realizada.

    Função que escreve o resultado da calculadora no arquivo de saída.
*/
bool WriteFile(int);

#endif // __FILEMANAGER__