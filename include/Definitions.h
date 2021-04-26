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


/*!< Tipo de dado vetor de bitset (BitStream)  */
typedef std::vector<std::bitset<BYTE_LENGTH>> BITSET_VECTOR; 

#endif