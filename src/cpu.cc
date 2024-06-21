#include <cstdio>
#include <cstring>

#include "hw.h"

void CPUReset() {
  m_AddressI = 0x200;
  m_ProgramCounter = 0x200;
  memset(m_Registers, 0, sizeof(m_Registers));

  FILE *in;
  in = fopen("/home/rickylss/code/chip8/bin/INVADERS", "rb");
  fread(&m_GameMemory[0x200], 0xCA0, 1, in);
  fclose(in);
}

WORD GetNextOpcode() {
  WORD res = 0;
  res = m_GameMemory[m_ProgramCounter] << 8 | m_GameMemory[m_ProgramCounter++];
  m_ProgramCounter++;
  return res;
}

void ProcessOpCode() {
  WORD opcode = GetNextOpcode();

  switch (opcode & 0xF000) {
    case 0x0000: {
      switch (opcode & 0x00FF) {
        case 0x00E0:
          Opcode00E0(opcode);
          return;
        case 0x00EE:
          Opcode00EE(opcode);
          return;
      }
      Opcode0NNN(opcode);
    } break;
    case 0x1000:
      Opcode1NNN(opcode);
      break;
    case 0x2000:
      break;
    case 0x3000:
      break;
    case 0x4000:
      break;
    default:
      break;
  }
}