// Define para impedir include circular
#ifndef __STRINGCALCULATOR__
#define __STRINGCALCULATOR__

#include <string>

// Namespace std para tipo string
using std::string;

#define TRUE 1
#define FALSE 0

typedef unsigned int uint;

/**
    \brief Soma inteiros numa string.
    \return Tipo int referente ao sucesso da função, ou cumprimento dos requisitos. 0 para falso e 1 para verdadeiro.
    \param String de entrada a ser lida.

    Função de calculadora que recebe uma string para fazer a soma dos termos separados por um delimitador.

    REQUISITOS:
        A string poderá conter qualquer quantidade de números. Em cada linha se pode ter 0, 1, 2 ou 3 números.
        Os números são separados por exatamente um delimitador que no caso é a vírgula.
        Qualquer separador diferente é considerado erro a menos que tenha sido adicionado como delimitador.
        Números negativos são proibidos. Se houver um número negativo retorna -1 e os números maiores que 1000 são ignorados.
        Pode-se especificar um novo delimitador na primeira linha, desde que esteja entre colchetes, sozinho na primeira linha e começando por um "//".
        Pode haver qualquer número de delimitadores especificados e de qualquer tamanho.
*/
int StringCalculator(string);

#endif // __STRINGCALCULATOR__