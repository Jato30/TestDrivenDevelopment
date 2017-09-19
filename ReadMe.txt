Universidade de Bras�lia
Departamento de Ci�ncia da Computa��o
Disciplina: M�todos de Programa��o
C�digo da Disciplina: 201600
Nome: Daniel Marcos Botelho Barbosa
Matr�cula: 17/0052427

	O objetivo deste trabalho � utilizar o desenvolvimento orientado a testes (TDD) para fazer uma calculadora que utiliza uma string como entrada para fazer a soma dos termos separados por um delimitador.


	VERS�ES, ARQUIVOS E REQUISITOS DO PROJETO:

	1) O programa est� dividido em m�dulos e desenvolvido em C++;
	2) Makefile pr�prio:
		Comandos:
		2.1) Compila��o em LINUX.
			2.1.1) make release
			2.1.2) make debug
			2.1.3) make test
			2.1.4) make docs
			2.1.5) make clean
			2.1.6) make clean-doc
		2.2) Compila��o em Windows.
			2.2.1) mingw32-make release
			2.2.2) mingw32-make debug
			2.2.3) mingw32-make test
			2.2.4) mingw32-make docs
			2.2.5) mingw32-make clean
			2.2.6) mingw32-make clean-doc
		2.3) Gera execut�vel CALC.exe
	3) Documento TestExplanation.txt dizendo quais testes foram feitos a cada passo e o que passar neste teste significa;
	4) Framework de teste: Catch v1.10.0;
	5) Instrumenta��o do c�digo pelo gcov v7.2.0;
	6) An�lise est�tica do programa: cppcheck v1.80;
	7) Documenta��o do c�digo: DoxyGen v1.8.13
	9) Debug: GDB v8.0
	10) Compilador: g++ MinGW
	11) ReadMe.txt


20/09/2017