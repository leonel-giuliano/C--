#include <iostream>
using namespace std;

#include "main.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if(argc > ARGC_FILE) errorHandler(ERROR_ARG);
}