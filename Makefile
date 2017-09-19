FILES = src/StringCalculator.cpp src/FileManager.cpp

FLAGS= -std=c++11 -Wall -pedantic -Wextra -fmax-errors=5 -Wno-unused-parameter -Werror=init-self -fdiagnostics-color

EXEC = CALC

COMPILER = g++

#comando para remover pastas
RMDIR = rm -rf
#comando para remover arquivos
RM = rm -f
CD = cd

ifeq ($(OS),Windows_NT)

EXEC := $(EXEC).exe

#comando para remover um diretório recursivamente
RMDIR= rd /s /q
#comando para deletar um único arquivo
RM = del

endif

release: src/main.cpp $(FILES)
	$(COMPILER) $(FILES) src/main.cpp -Iinclude -o $(EXEC) $(FLAGS)

debug: src/main.cpp $(FILES)
	$(COMPILER) $(FILES) src/main.cpp -Iinclude -o $(EXEC) $(FLAGS) -O0 -ggdb

test: src/TestCalculator.cpp $(FILES)
	$(COMPILER) $(FILES) src/TestCalculator.cpp -Iinclude -o CALC.exe $(FLAGS) -O0 -ggdb -ftest-coverage -fprofile-arcs

docs:
	doxygen Doxyfile

clean:
	$(RM) $(EXEC)

clean-doc:
	$(RMDIR) docs