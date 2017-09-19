// Headers
#include "FileManager.hpp"
#include "StringCalculator.hpp"

int main(int argc, char** argv){
  // Verifica se há argumentos recebidos
  if(argc < 2){
    std::cout << "Falha ao receber argumentos.\n";
    std::cout << "Abrindo arquivo padrao: './resources/EntryString.txt'\n" << std::endl;
    argv[1] = "./resources/EntryString.txt";
  }

  // Executa a calculadora enviando o conteúdo do arquivo recebido pelo sistema como parâmetro.
  if(StringCalculator(ReadFile(argv[1]) != "" ? argv[1] : "./resources/EntryString.txt") != 1){
    std::cout << "\nErro na funcao 'StringCalculator'" << std::endl;
  }

  return 0;
}