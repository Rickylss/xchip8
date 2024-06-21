#pragma once

#include <vector>

typedef unsigned char BYTE;
typedef unsigned short int WORD;

BYTE m_GameMemory[0xFFF];
BYTE m_Registers[16];
WORD m_AddressI;
WORD m_ProgramCounter;
std::vector<WORD> m_Stack;

BYTE m_ScreenData[64][32];