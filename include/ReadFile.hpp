// Define para impedir include circular
#ifndef __READFILE__
#define __READFILE__

#include <string>

// Namespace std para tipo string
using std::string;

/**
    \brief Leitura do arquivo de entrada.
    \return String contendo o conteúdo do arquivo lido.
    \param Caminho do arquivo contendo a string de entrada a ser lida. Este parâmetro é fornecido pelo sistema.

    Função que lê o arquivo com a string de entrada e a retorna.
*/
string ReadFile(const string);

#endif // __READFILE__