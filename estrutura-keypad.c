#include "pico/stdlib.h"

// Definição dos pinos do teclado matricial
#define ROWS 4
#define COLS 4

// Atualização dos pinos de acordo com as novas conexões
const uint8_t row_pins[ROWS] = {8, 7, 6, 5}; // Pinos conectados às linhas R1, R2, R3, R4 
const uint8_t col_pins[COLS] = {4, 3, 2, 28}; // Pinos conectados às colunas C1, C2, C3, C4

// Mapa de teclas do teclado matricial
const char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}

};

