#include "StringCalculator.hpp"
#include "FileManager.hpp"
#include <cctype>

using namespace std;

int StringCalculator(string entry){
    int finalSum = 0, countLimiters = 0, limiterSize = 1;
    char limiter = ',';
    int readyToFinish = FALSE;

    // Lê a entrada
    for(uint index = 0; index < entry.size(); index++){
        

        if(isdigit(entry[index])){
            finalSum += atoi(&entry[index]);
        }

    }

    printf("\n%d\n", finalSum);

    WriteFile(finalSum);
    return readyToFinish;
}
