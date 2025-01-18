#include <stdio.h>
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

void inicializarComponentes(int pinoDoPrimeiroLed, int pinoDoSegundoLed, int pinoDoTerceiroLed, int pinoDoBuzzer) {

    // Inicializar o Buzzer
    gpio_init(pinoDoBuzzer);                      // inicializando o pino Gpio 21 do buzzer
    gpio_set_dir(pinoDoBuzzer, GPIO_OUT);         // Definindo o pino do 21 do buzzer como sa�da

    // Inicializar os 3 LEDs em sequ�ncia
    gpio_init(pinoDoPrimeiroLed);                 // inicializando o pino Gpio 11 do led verde
    gpio_set_dir(pinoDoPrimeiroLed, GPIO_OUT);    // Definindo o pino gpio 11 como sa�da

    gpio_init(pinoDoSegundoLed);                  // inicializando o pino Gpio 12 do led azul
    gpio_set_dir(pinoDoSegundoLed, GPIO_OUT);     // Definindo o pino gpio 12 como sa�da

    gpio_init(pinoDoTerceiroLed);                 // inicializando o pino Gpio 13 do led vermelho
    gpio_set_dir(pinoDoTerceiroLed, GPIO_OUT);    // Definindo o pino gpio 13 como sa�da
}

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
