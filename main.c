#include <stdio.h>
#include "memory.h"
#include "test.h"

/*
 * IDE: Clion
 * Sistema Operacional: Linux
 * Para rodar o programa:
 * compilar com gcc
 * rodar com ./a.out
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
