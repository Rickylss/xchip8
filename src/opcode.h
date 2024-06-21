#pragma once

#include <cstring>
#include <random>

#include "hw.h"

void Opcode0NNN(WORD opcode) {}

void Opcode00E0(WORD opcode) { memset(m_ScreenData, 0, sizeof(m_ScreenData)); }

void Opcode00EE(WORD opcode) {
  m_ProgramCounter = m_Stack.back();
  m_Stack.pop_back();
}

void Opcode1NNN(WORD opcode) { m_ProgramCounter = opcode & 0x0FFF; }

void Opcode2NNN(WORD opcode) {
  m_Stack.push_back(m_ProgramCounter);
  m_ProgramCounter = opcode & 0x0FFF;
}

void Opcode3XNN(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  if (m_Registers[x] == (opcode & 0x00FF)) {
    m_ProgramCounter += 2;
  }
}

void Opcode4XNN(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  if (m_Registers[x] != (opcode & 0x00FF)) {
    m_ProgramCounter += 2;
  }
}

void Opcode5XY0(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  if (m_Registers[x] == m_Registers[y]) {
    m_ProgramCounter += 2;
  }
}

void Opcode6XNN(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  m_Registers[x] = opcode & 0x00FF;
}

void Opcode7XNN(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  m_Registers[x] += opcode & 0x00FF;
}

void Opcode8XY0(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] = m_Registers[y];
}

void Opcode8XY1(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] |= m_Registers[y];
}

void Opcode8XY2(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] &= m_Registers[y];
}

void Opcode8XY3(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] ^= m_Registers[y];
}

void Opcode8XY4(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] += m_Registers[y];
}
void Opcode8XY5(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  int xval = m_Registers[x];
  int yval = m_Registers[y];

  if (yval > xval)
    m_Registers[0xF] = 0;

  m_Registers[x] = xval - yval;
}

void Opcode8XY6(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] >>= m_Registers[y];
}

void Opcode8XY7(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  int xval = m_Registers[x];
  int yval = m_Registers[y];

  if (yval > xval)
    m_Registers[0xF] = 0;

  m_Registers[x] = yval - xval;
}

void Opcode8XYE(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  m_Registers[x] <<= m_Registers[y];
}

void Opcode9XY0(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;

  if (m_Registers[x] != m_Registers[y]) {
    m_ProgramCounter += 2;
  }
}

void OpcodeANNN(WORD opcode) { m_AddressI = opcode & 0x0FFF; }

void OpcodeBNNN(WORD opcode) {
  m_ProgramCounter = m_Registers[0] + (opcode & 0x0FFF);
}

void OpcodeCXNN(WORD opcode) {
  std::uniform_int_distribution<unsigned> u(0, 255);
  std::default_random_engine e;
  int x = (opcode & 0x0F00) >> 8;

  m_Registers[x] = u(e) & (opcode & 0x0FFF);
}

void OpcodeDXYN(WORD opcode) {
  int x = (opcode & 0x0F00) >> 8;
  int y = (opcode & 0x00F0) >> 4;
  BYTE n = opcode & 0x000F;

  m_ScreenData[x][y];
}

void OpcodeEX9E(WORD opcode) {}

void OpcodeEXA1(WORD opcode) {}
void OpcodeFX07(WORD opcode) {}
void OpcodeFX0A(WORD opcode) {}
void OpcodeFX15(WORD opcode) {}
void OpcodeFX18(WORD opcode) {}
void OpcodeFX1E(WORD opcode) {}
void OpcodeFX29(WORD opcode) {}

void OpcodeFX33(WORD opcode) {}

void OpcodeFX55(WORD opcode) {}
void OpcodeFX65(WORD opcode) {}