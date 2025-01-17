#include <stdio.h>
#include "pico/stdlib.h"

//função main que conta com a descrição das interações
int main()
{
    stdio_init_all();
    keypad_init();
    
    while (true)
    {
        char key = read_keypad();        
        switch (key)
        {
        case '1':
            //FUNÇÕES SERÃO DEFINIDAS COM BASE NO NUZZER E PINS
            printf("A tecla 1 foi pressionada.");
            sleep_ms(200);
            break;
        case '2':

        printf("A tecla 2 foi pressionada.");
        sleep_ms(200);
            break;
        case '3':

            printf("A tecla 3 foi pressionada.");
            sleep_ms(200);
            break;
        case '4':

            printf("A tecla 4 foi pressionada.");
            sleep_ms(200);
            break;
        case '5':

        printf("A tecla 5 foi pressionada.");
        sleep_ms(200);
            break;
        case '6':

            printf("A tecla 6 foi pressionada.");
            sleep_ms(200);
            break;


        default:
            break;
        }


    }    
}