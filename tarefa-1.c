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

#define pinoDoBuzzer 21
#define pinoDoPrimeiroLed 11
#define pinoDoSegundoLed 12
#define pinoDoTerceiroLed 13

void inicializar_componentes() {

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

void inicializar_keypad() {
    // Inicializar os pinos das linhas (ROWS) como saída
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 0);  // Definir o valor inicial como baixo
    }

    // Inicializar os pinos das colunas (COLS) como entrada com pull-down
    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_down(col_pins[i]);  // Habilitar o pull-down nas colunas
    }
}

char ler_keypad() {
    // Verificar a pressão das teclas
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 1);  // Definir a linha atual como nível alto
        for (int col = 0; col < COLS; col++) {
            // Se houver uma tecla pressionada
            if (gpio_get(col_pins[col])) {
                // A tecla foi pressionada, retornar o valor
                gpio_put(row_pins[row], 0);  // Retornar ao estado baixo
                sleep_ms(20);  // Aguardar um tempo para evitar a leitura incorreta
                return key_map[row][col];     // Retornar a tecla pressionada
            }
        }
        gpio_put(row_pins[row], 0);  // Retorna ao estado baixo após iteração
    }
    return '\0';  // Retornar nulo se nenhuma tecla foi pressionada
}

// Função para emitir um beep
void Beep(){
    for (int i = 0; i < 100; i++) {
        gpio_put(pinoDoBuzzer, 1);
        sleep_us(500);
        gpio_put(pinoDoBuzzer, 0);
        sleep_us(500);
    }
}

// Função para emitir um som com uma frequência e duração específicas
void buzz(int freq, int duration) {
    int period = 1000000 / freq;
    int pulse = period / 2;
    int cycles = freq * duration / 1000;

    for (int i = 0; i < cycles; i++) {
        gpio_put(pinoDoBuzzer, 1);
        sleep_us(pulse);
        gpio_put(pinoDoBuzzer, 0);
        sleep_us(pulse);
    }
}

// Função para colorir os LEDs
void colorir(uint r, uint g, uint b){
    gpio_put(pinoDoPrimeiroLed, r);
    gpio_put(pinoDoSegundoLed, g);
    gpio_put(pinoDoTerceiroLed, b);
}

int main() {
    char key;
    stdio_init_all();
    inicializar_keypad();
    inicializar_componentes();       
    while (true) {
        key = ler_keypad();
        while (key != '\0') {  // Se uma tecla for pressionada
            switch (key) {
                case '1':
                    colorir(1, 0, 0); // Acende o led verde
                    printf("\nTecla pressionada: 1. Led verde ligado. \n");
                    break;
                case '2':
                    colorir(0, 1, 0); // Acende o led azul
                    printf("\nTecla pressionada: 2. Led azul ligado. \n");
                    break;
                case '3':
                    colorir(0, 0, 1); // Acende o led vermelho
                    printf("\nTecla pressionada: 3. Led vermelho ligado. \n");
                    break;
                case 'A':
                    printf("\nTecla pressionada A. \n");
                    // Acende os leds em sequência
                    gpio_put(pinoDoPrimeiroLed, 1);
                    sleep_ms(200);
                    gpio_put(pinoDoPrimeiroLed, 0);
                    gpio_put(pinoDoSegundoLed, 1);
                    sleep_ms(200);
                    gpio_put(pinoDoSegundoLed, 0);
                    gpio_put(pinoDoTerceiroLed, 1);
                    sleep_ms(200);
                    gpio_put(pinoDoTerceiroLed, 0);
                    break;
                case 'B':
                    colorir(1, 1, 1); // Acende os 3 leds emitindo uma luz branca
                    printf("\nTecla pressionada: B. Leds ligados. \n");
                    sleep_ms(200);
                    break;
                case 'C':
                    colorir(1, 0, 1); // Acende o led verde e o led vermelho
                    printf("\nTecla pressionada: C. 2 Leds ligados. \n");
                    sleep_ms(200);
                    break;
                case 'D':
                    colorir(1, 1, 0); // Acende o led verde e o led azul
                    printf("\nTecla pressionada: D. 2 Leds ligados. \n");
                    sleep_ms(200);
                    break;
                case '*':
                    Beep();
                    Beep();
                    printf("\nTecla pressionada: *. Beep acionado. \n");
                    sleep_ms(200);
                    break;
                case '#':
                    buzz(1000, 500);
                    printf("\nTecla pressionada: #. Buzzer acionado. \n");
                    sleep_ms(200);
                    break;
                case '0':
                    colorir(0, 0, 0); // Desliga todos os leds
                    printf("\nTecla pressionada: 0. Leds desligados. \n");
                    sleep_ms(200);
                    break;
                default:
                    break;
            }
            sleep_ms(100);
            key = ler_keypad();
        }
    }
    return 0;
}