/*
Projeto Horta Hidropônica Automatizada

Programação:

Bruno Vaz de Souza
Leonardo Gonçalves
Leonardo Morijo
Matheus Dantas Cipolotti

Microcontrolador: PIC16F877
Frequência clock: 20MHz
*/

#define ATVRD   RB7_bit
#define STRD    RB0_bit
#define FGC     RD2_bit
#define ATVBT1  RD7_bit

int bc=0;

void main() {

     TRISB = 0b00110001;
     TRISD = 0b00000100;
     PORTB = 0b00000000;
     PORTD = 0b00000000;

      while(1){
               if(STRD == 1){
                       ATVRD = 0;
                       ATVBT1 = 0;
                       bc = 0;
                       delay_ms(10);
               }
               if(STRD == 0){
                       ATVRD = 1;
                       delay_ms(10);
               }
               if(STRD == 0 && FGC == 0 && bc == 0){
                       ATVBT1 = 1;
                       bc = 1;
                       delay_ms(10);
               }
               if(STRD == 0 && FGC == 1 && bc == 1){
                       ATVBT1 = 1;
                       bc = 2;
                       delay_ms(10);
               }
               if(STRD == 0 && FGC == 0 && bc == 2){

                       ATVBT1 = 0;
               }
      }
}