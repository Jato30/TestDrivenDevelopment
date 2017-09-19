Universidade de Brasília
Departamento de Ciência da Computação
Disciplina: Métodos de Programação
Código da Disciplina: 201600
Nome: Daniel Marcos Botelho Barbosa
Matrícula: 17/0052427

	O objetivo deste trabalho é utilizar o desenvolvimento orientado a testes (TDD) para fazer uma calculadora que utiliza uma string como entrada para fazer a soma dos termos separados por um delimitador.


	VERSÕES, ARQUIVOS E REQUISITOS DO PROJETO:

	1) O programa está dividido em módulos e desenvolvido em C++;
	2) Makefile próprio:
		Comandos:
		2.1) Compilação em LINUX.
			2.1.1) make release
			2.1.2) make debug
			2.1.3) make test
			2.1.4) make docs
			2.1.5) make clean
			2.1.6) make clean-doc
		2.2) Compilação em Windows.
			2.2.1) mingw32-make release
			2.2.2) mingw32-make debug
			2.2.3) mingw32-make test
			2.2.4) mingw32-make docs
			2.2.5) mingw32-make clean
			2.2.6) mingw32-make clean-doc
		2.3) Gera executável CALC.exe
	3) Documento TestExplanation.txt dizendo quais testes foram feitos a cada passo e o que passar neste teste significa;
	4) Framework de teste: Catch v1.10.0;
	5) Instrumentação do código pelo gcov v7.2.0;
	6) Análise estática do programa: cppcheck v1.80;
	7) Documentação do código: DoxyGen v1.8.13
	9) Debug: GDB v8.0
	10) Compilador: g++ MinGW
	11) ReadMe.txt


20/09/2017