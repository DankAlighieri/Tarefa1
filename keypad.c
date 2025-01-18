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

// Definição do pino do LED vermelho
const uint LED_PIN = 13; 

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


void inicializarKeypad() {
    // Inicializar os pinos das linhas (ROWS) como saída
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1);  // Definir o valor inicial como alto
    }

    // Inicializar os pinos das colunas (COLS) como entrada com pull-down
    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_down(col_pins[i]);  // Habilitar o pull-down nas colunas
    }
}

char lerKeypad() {
    // Verificar a pressão das teclas
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 0);  // Definir a linha atual como baixo

        for (int col = 0; col < COLS; col++) {
            // Se houver uma tecla pressionada (linha baixa e coluna alta)
            if (gpio_get(col_pins[col]) == 1) {
                // A tecla foi pressionada, retornar o valor
                gpio_put(row_pins[row], 1);  // Voltar a linha para alto
                return key_map[row][col];     // Retornar a tecla pressionada
            }
        }

        gpio_put(row_pins[row], 1);  // Voltar a linha para alto
    }

    return '\0';  // Retornar nulo se nenhuma tecla foi pressionada
}

int main()
{
    stdio_init_all();

   // Inicializar os componentes (LEDs, buzzer)
    inicializarComponentes(11, 12, 13, 21);

    inicializarKeypad();

    while (true) {
        char tecla = lerKeypad();  // Ler a tecla pressionada

        if (tecla != '\0') {  // Verifica se há uma tecla pressionada
            printf("Tecla pressionada: %c\n", tecla);

            // Acende o LED vermelho quando uma tecla é pressionada
            gpio_put(LED_PIN, 1);  // Acende o LED
            sleep_ms(500);         // Mantém o LED aceso por 500ms
            gpio_put(LED_PIN, 0);  // Apaga o LED
        }

        sleep_ms(100);  // Aguarda 100ms antes de ler novamente
    }
}
