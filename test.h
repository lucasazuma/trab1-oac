//
// Created by lucas on 08/08/2021.
//

#ifndef OAC_TEST_H
#define OAC_TEST_H
#include "memory.h"

void test_sb(uint32_t address, int32_t kte, int8_t dado, int32_t valor_esperado);

void test_sw(uint32_t address, int32_t kte, int8_t dado, int32_t valor_esperado);

void run_required_tests();

void extra_tests();

#endif //OAC_TEST_H
