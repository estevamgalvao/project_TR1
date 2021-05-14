#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <bitset>

#define BYTE_LENGTH 8
#define BYTE_FLAG std::bitset<BYTE_LENGTH>{"11001000"} //ASCII 200
#define BYTE_ESC std::bitset<BYTE_LENGTH>{"10110000"} //ASCII 176
// #define BYTE_ESC std::bitset<BYTE_LENGTH>{"01100001"}

#define BIT_8 (uint8_t) 0b10000000
#define BIT_1 (uint8_t) 0x01
#define CRC_POLYNOMIAL 0xEDB88320
#define CRC_SIZE 32

/*!< Tipo de dado vetor de bitset (BitStream)  */
typedef std::vector<std::bitset<BYTE_LENGTH>> BITSET_VECTOR; 

#endif