
// Fun��o para inicializar os LEDs e o Buzzer
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



