#include <stdio.h>
#include "pico/stdlib.h"

//Não constam as inicializações e declarações de constantes
#define DO 262
#define RE 294
#define MI 330
#define FA 349
#define SOL 392
#define LA 440
#define SI 494
#define DO2 523

void musica1();
void musica2();
void notamusical(int frequencia, int duracao);
void read_key(char key);

int main()
{
    stdio_init_all()
    keypad_init();

    while (true)
    {
        char key = read_keypad();
        read_key(key);
    }    
        return 0;
}

void read_key(char key){
switch (key)
        {
        case '1': //Buzzer emite um DÓ
            notamusical(DO, 600);
            printf("A tecla 1 foi pressionada. Tocando a nota DÓ.");
            sleep_ms(200);
            break;
        case '2'://Buzzer emite um RÉ
            notamusical(RE, 600);
            printf("A tecla 2 foi pressionada. Tocando a nota RÉ.");
            sleep_ms(200);
            break;
        case '3'://Buzzer emite um MI
            notamusical(MI, 600);
            printf("A tecla 3 foi pressionada. Tocando a nota MI");
            sleep_ms(200);
            break;
        case '4'://Buzzer emite um FÁ
            notamusical(FA, 600);
            printf("A tecla 4 foi pressionada. Tocando a nota FÁ");
            sleep_ms(200);
            break;
        case '5'://Buzzer emite um SOL
            notamusical(SOL, 600);
            printf("A tecla 5 foi pressionada. Tocando a nota SOL");
            sleep_ms(200);
            break;
        case '6'://Buzzer emite um LÁ
            notamusical(LA, 600);
            printf("A tecla 6 foi pressionada. Tocando a nota LÁ");
            sleep_ms(200);
            break;
        case '7'://Buzzer emite um SI
            notamusical(SI, 600);
            printf("A tecla 7 foi pressionada.  Tocando a nota SI");
            sleep_ms(200);
            break;
        case '8'://Buzzer emite um DÓ
            notamusical(DO2, 600);
            printf("A tecla 8 foi pressionada. Tocando a nota DÓ");
            sleep_ms(200);
            break;
        case '9'://Música toca
            musica1();
            printf("A tecla 9 foi pressionada. Música n°1 tocando.");
            sleep_ms(200);
            break;
        case '0'://Outra música toca
            musica2();
            printf("A tecla 0 foi pressionada. Música n°2 tocando");
            sleep_ms(200);
            break;
        case 'a'://liga verde
            gpio_put(,1);
            printf("A tecla a foi pressionada. Led verde ligado");
            sleep_ms(200);
            break;
        case 'b'://liga o azul
            gpio_put(,1);
            printf("A tecla b foi pressionada. Led azul ligado");
            sleep_ms(200);
            break;
        case 'c'://liga o vermelho
            gpio_put(,1);
            printf("A tecla c foi pressionada. Led vermelho ligado");
            sleep_ms(200);
            break;
        case 'd'://alterna entre as três cores
            while(1)
            {
                gpio_put(,1);
                sleep_ms(300);
                gpio_put(,0);
                gpio_put(,1);
                sleep_ms(300);
                gpio_put(,0);
                gpio_put(,1);
                sleep_ms(300);
                gpio_put(,0);
            }
            printf("A tecla d foi pressionada. Os três leds piscam de forma alternada");
            sleep_ms(200);
        break;
        case '#'://Os três leds acendem
            gpio_put(,1);
            gpio_put(,1);
            gpio_put(,1);
            printf("A tecla # foi pressionada.");
            sleep_ms(200);
        case '*'://Buzzer liga
            gpio_put(,1);
            printf("A tecla * foi pressionada. Buzzer ligado.");
            sleep_ms(200);
            break;
        default:
            break;
        }
}

void notamusical(int frequencia, int duracao) {
    if (frequencia > 0) {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(1000000 / frequencia);
        gpio_put(BUZZER_PIN, 0);
    }
        sleep_ms(duracao);
}

void musica1() {
    int notas[] = {262, 262, 392, 392, 440, 440, 392};  // Do, Do, Sol, Sol, La, La, Sol
    int duracoes[] = {400, 400, 400, 400, 400, 400, 800};  // Duração das notas
    for (int i = 0; i < 7; i++) {
        notamusical(notas[i], duracoes[i]);
    }
}

void musica2() {
    int notas[] = {
        392, 392, 440, 440, 392, 392, 349, 349, 330, 330, 294, 294, 262, 262, 294, 392  // Sol, Sol, La, La, Sol, Sol, Fa, Fa, Mi, Mi, Re, Re, Do, Do, Re, Sol
    };
    int duracoes[] = {
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500  // Duração das notas
    };
    
    for (int i = 0; i < 16; i++) {
        notamusical(notas[i], duracoes[i]);
    }
}