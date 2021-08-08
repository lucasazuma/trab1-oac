//
// Created by lucas on 07/08/2021.
//

#include <stdio.h>
#include "memory.h"
#include "validations.h"
#include "binary.h"

int32_t mem[MEM_SIZE];

int32_t* get_memory() {
    return mem;
}

void reset_memory() {
    int i = 0;
    for(i = 0; i <= MEM_SIZE; i++)
        mem[i] = 0;
}

int32_t lw(uint32_t address, int32_t kte){
    int32_t adr = address + kte;
    if(validates_word_address(adr)){
        int32_t true_adr = adr/4;
        return mem[true_adr];
    }else{
        return 0;
    }
}

void sw(uint32_t address, int32_t kte, int32_t dado){
    int32_t adr = address + kte;
    if(validates_word_address(adr)){
        int32_t true_adr = adr/4;
        mem[true_adr] = dado;
        return;
    }
}

int32_t lb(uint32_t address, int32_t kte) {
    int32_t adr = address + kte;

    if(validates_byte_address(adr)){
        uint8_t byte_index = adr % 4;
        int32_t finalAddress = (adr - byte_index) / 4;
        int32_t mask = extraction_mask(byte_index);
        uint32_t shiftedByte = int_from_byte(mem[finalAddress], mask) >> (byte_index  * 8);
        int32_t signedByte = shiftedByte;

        if(shiftedByte & 0b10000000)
            signedByte |= 0xFFFFFF00;

        return signedByte;
    }else{
        return 0;
    }
}

void sb(uint32_t address, int32_t kte, int8_t dado) {
    int32_t adr = address + kte;

    if(validates_byte_address(adr)){
        uint8_t byte_index = adr % 4;
        int32_t finalAddress = adr - byte_index;
        int32_t extendedValue = (dado << (byte_index * 8) & extraction_mask(byte_index));
        uint32_t clearByteInPositionMask = ~extraction_mask(byte_index);
        int32_t current_word = lw(finalAddress, 0);
        int32_t dataToBeStored = (current_word & clearByteInPositionMask) | extendedValue;
        sw(finalAddress, 0, dataToBeStored);
    }else{
        return;
    }
}

int32_t lbu(uint32_t address, int32_t kte) {
    int32_t tempAddress = address + kte;

    if(validates_byte_address(tempAddress)){
        uint8_t byte_index = tempAddress % 4;
        int32_t finalAddress = (tempAddress - byte_index) / 4;
        int32_t mask = extraction_mask(byte_index);
        int32_t shiftedByte = int_from_byte(mem[finalAddress], mask);

        return (int32_t)((uint32_t)shiftedByte >> (byte_index * 8));
    }else{
        return 0;
    }
}

