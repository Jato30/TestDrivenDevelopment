// Headers
#include "testa_soma_string_stdin.hpp"
#include "string_soma.hpp"

int main(int argc, char** argv){
  // Verifica se há argumentos recebidos
  if(argc < 2){
    std::cout << "Falha ao receber argumentos.\n";
    std::cout << "Abrindo arquivo padrao: './resources/EntryString.txt'\n" << std::endl;
    argv[1] = "./resources/EntryString.txt";
  }

  // Executa a calculadora enviando o conteúdo do arquivo recebido pelo sistema como parâmetro.
  string entry = ReadFile(argv[1] != "" ? argv[1] : "./resources/EntryString.txt");
  if(string_soma(entry) == -1){
    std::cout << "\nErro na funcao 'string_soma'" << std::endl;
  }

  return 0;
}
