**CONTROLE DE PINOS GPIO COM O EMPREGO DE UM TECLADO MATRICIAL**

Este repositório contém o código-fonte e o diagrama referentes a atividade 1 da unidade U4 - Microcontroladores do curso Embarcatech, que consiste em utilizar um teclado matricial 4x4 para controlar determinados pinos GPIO do microcontrolador RP2040, presente na placa de desenvolvimento Raspberry Pi Pico W, realizando o acionamento de 3 LEDs, junto com o controle do sinal sonoro de um buzzer, simulando-os no Wokwi integrado no ambiente de desenvolvimento VS Code.

**DIVISÃO DAS ATIVIDADES**

Analisando o que foi pedido na atividade, se dividiu a tarefa em 7 subtarefas, que ficou com a seguinte estrutura:

1. Construir diagrama.json no simulador wokwi; *(realizado por Vitória).*
	*Diagrama construído no simulador wowki com os componentes pedidos.*
2. Declarar estrutura do keypad; *(realizado por Enzo).*
   *Declaração da estrutura do keypad, definição de macros para os pinos.*
3. Escrever função para inicializar o keypad; *(realizado por Marcus).*
    *Criação de função para inicializar o keypad.*
4. Escrever função para ler o keypad; *(realizado por Marcus).*
    *Criação de função para ler o keypad.*
5. Escrever uma função para inicializar os LEDs e o buzzer; *(realizada por Mateus).*
    *Configurações do Buzzer e LEDs, criação de macros para os pinos, criação de funções para a inicialização e utilização de comandos.*
6. Escrever a lógica para a interação do keypad com os outros componentes; *(realizado por Camila)*
    *Implementação da lógica para integrar o keypad aos demais componentes, incluindo a leitura de teclas, interpretação de comandos e acionamento correspondente dos dispositivos.*
7. Escrever o README.md e produzir o vídeo explicativo do projeto. *(realizado por Vitória).*
    *Escrita do arquivo README.md, o qual contém as atividades realizadas, descrição do projeto e detalhamento da atividade realizada. Produção do vídeo demonstrativo do projeto.*
    
Enquanto o líder ficou responsável pela gestão do repositório e equipe de desenvolvedores.

**COMPONENTES E FERRAMENTAS UTILIZADAS**
	Para a realização do projeto, foram utilizadas as seguintes ferramentas:
- Simulador Wowki;
- Microcontrolador Raspberry Pi Pico w;
- 03 LEDs;
- 03 resistores de 220 Ω;
- 01 buzzer;
- 01 teclado matricial 4x4;
- Visual Studio Code.


**PRODUÇÃO DAS ATIVIDADES** 

A execução da tarefa foi organizada com a designação de um líder, responsável por oferecer suporte e supervisionar as atividades realizadas pelos desenvolvedores. Enquanto isso, os integrantes da equipe assumiram responsabilidades específicas para garantir a conclusão do projeto.
Inicialmente, foi criado o arquivo 'diagram.json' na plataforma Wokwi. Em seguida, o desenvolvimento continuou no VS Code, onde os códigos foram implementados. Durante esse processo, os GPIOs e funções foram definidos e integrados à função 'main'. Dessa maneira, foram realizados testes para a conclusão do projeto.

**LINGUAGEM UTILIZADA**
- C

**EQUIPE**
- Líder: Guilherme Emetério
- Desenvolvedores:
    - Enzo Andrade
    - Camila Ramos
    - Vitória Freire
    - Mateus Moreira
    - Marcus Vinicius
    
**LINK DO VÍDEO EXPLICATIVO**
