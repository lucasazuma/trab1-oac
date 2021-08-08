
#include <stdio.h>
#include "validations.h"
#include "binary.h"

int32_t extraction_mask(uint8_t byteIndexInInt) {
    int32_t mask = 0xFF << (byteIndexInInt * 8);

    return mask;
}

int32_t int_from_byte(int32_t fullInt, int32_t mask) {
    return mask & fullInt;
}


