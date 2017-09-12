// Headers
#include "FileManager.hpp"

int main(int argc, char** argv){
  // Verifica se há argumentos recebidos
  if(argc < 2){
    std::cout << "Falha ao receber argumentos.\n";
    exit(1);
  }

  // Executa a calculadora enviando o conteúdo do arquivo recebido pelo sistema como parâmetro.
  if(StringCalculator(ReadFile(argv))){
    std::cout << "Erro na função 'StringCalculator'" << std::endl;
  }

  return 0;
}