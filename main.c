#include <stdio.h>
#include "./test.h"

/*
 * Sistema Operacional: Linux
 * IDE: Clion
 * compilador: gcc
 * para compilar e rodar:
 *  -compilar:  make compile
 *  -rodar: make run
 */

int main() {
    reset_memory();
    printf("======================\n");
    printf("|| testes principais||\n");
    printf("======================\n\n");
    run_required_tests();

    printf("======================\n");
    printf("|| testes extras||\n");
    printf("======================\n\n");

    extra_tests();
    return 0;
}
