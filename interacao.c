#include <stdio.h>
#include "pico/stdlib.h"

#define pinoDoBuzzer 21
#define pinoDoPrimeiroLed 11
#define pinoDoSegundoLed 12
#define pinoDoTerceiroLed 13

void Beep(){
    for (int i = 0; i < 100; i++) {
        gpio_put(pinoDoBuzzer, 1);
        sleep_us(500);
        gpio_put(pinoDoBuzzer, 0);
        sleep_us(500);
    }
}

int main() {
    stdio_init_all();
    keypad_init();
    inicializarComponentes();       // Definindo o pino do 21 do buzzer como sa�da
        while (true) {
            char key = read_keypad();
             if (key == '0') {  // Se uma tecla for pressionada
                    gpio_put(pinoDoBuzzer, 1);
                    sleep_ms(200);
                    Beep();
            }
            else if (key=='1'){
                gpio_put(pinoDoPrimeiroLed,1);
                printf("\nTecla pressionada: 1. 1 Led ligado. \n");
                sleep_ms(200);
            }
            else if (key=='2'){
                gpio_put(pinoDoSegundoLed,1);
                printf("\nTecla pressionada: 2. 1 Led ligado. \n");
                sleep_ms(200);
            }
            else if (key=='3'){
                gpio_put(pinoDoTerceiroLed,1);
                printf("\nTecla pressionada: 3. 1 Led ligado. \n");
                sleep_ms(200);
            }
            else if (key=='A'){
                printf("\nTecla pressionada A. \n");
                gpio_put(pinoDoPrimeiroLed,1);
                sleep_ms(200);
                gpio_put(pinoDoPrimeiroLed,0);
                gpio_put(pinoDoSegundoLed,1);
                sleep_ms(200);
                gpio_put(pinoDoSegundoLed,0);
                gpio_put(pinoDoTerceiroLed,1);
                sleep_ms(200);
                gpio_put(pinoDoTerceiroLed,0);
                sleep_ms(200);
           }
            else if(key=='B'){
                gpio_put(pinoDoPrimeiroLed,1);
                gpio_put(pinoDoSegundoLed,1);
                gpio_put(pinoDoTerceiroLed,1);
                printf("\nTecla pressionada: B. Leds ligados. \n");
                sleep_ms(200);
           }
            else if(key=='C'){
                gpio_put(pinoDoPrimeiroLed,1);
                gpio_put(pinoDoSegundoLed,0);
                gpio_put(pinoDoTerceiroLed,1);
                printf("\nTecla pressionada: C. 2 Leds ligados. \n");
                sleep_ms(200);
           } 
           else if(key=='D'){
                gpio_put(pinoDoPrimeiroLed,1);
                gpio_put(pinoDoSegundoLed,1);
                gpio_put(pinoDoTerceiroLed,0);
                printf("\nTecla pressionada: D. 2 Leds ligados");
                sleep_ms(200);
           }
            else if (key == '*'){
                Beep();
                Beep();
                printf("\nTecla pressionada: *. Buzzer acionado. \n");
                sleep_ms(200); 
            }
            else{
                Beep();
                printf("\nNenhuma tecla pressionada");
                sleep_ms(200);
            }
        }
        return 0;
}