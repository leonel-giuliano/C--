#include <iostream>
using namespace std;

#include "error.h"

void errorHandler(errorState_t error) {
    string errorMsg;

    switch(error) {
        case ERROR_ARG:
            errorMsg = "Usage: main.exe [file.csv](Optional).";

            break;

        case ERROR_FILE:
            errorMsg = "The file couldn't been open.";

            break;

        case ERROR_MEMORY:
            errorMsg = "There was a problem allocating";

            break;

        default:
            errorMsg = "Unkown error.";

            break;
    }

    cout << "[ERROR] " << errorMsg << endl;

    exit(EXIT_FAILURE);
}