// Error cases
typedef enum {
    ERROR_ARG,
    ERROR_FILE,
    ERROR_MEMORY
}errorState_t;

void errorHandler(errorState_t _ErrorState);