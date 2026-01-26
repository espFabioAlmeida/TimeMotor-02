////////////////////////////////////////////////////////////////////////////////                                          
//PROJETO:   TimeMotor-02                                                                                               
//CLIENTE:   AUTOMASENSOR                                                                                                               
//CONTATO:   RICARDO KADOTA                                                                                               
//TELEFONE:                                                                                                                 
////////////////////////////////////////////////////////////////////////////////
//AUTOR:    FABIO EDUARDO DE ALMEIDA
//TELEFONE: 47 98411-2998                                                                  
//E-MAIL:   teg.fabio.almeida@gmail.com               
////////////////////////////////////////////////////////////////////////////////
//COMPILADOR: CCS 5.028   
//V2: 14/05/2025
////////////////////////////////////////////////////////////////////////////////                
#include <16F1936.h>          
#define VERSAO_FIRMWARE 1 
#device ADC=10
/*==============================================================================
CONFIGURACOES                          
==============================================================================*/
#fuses INTRC_IO, NOWDT, PUT, PROTECT, BROWNOUT, NOLVP, NOCPD 
#use delay(clock = 4000000)  
#priority TIMER1          
/*==============================================================================
CONSTANTES                         
==============================================================================*/
#define on           output_high         
#define off          output_low  

#define DEBOUNCE     120
#define TEMPO_AH     150
#define TEMPO_MIN_H  10
#define TEMPO_MAX_H  600
/*==============================================================================
DEFINICOES DOS PINOS                                      
==============================================================================*/
#define ENTRADA   PIN_C4

#define RELE_H    PIN_B5
#define RELE_AH   PIN_C3
/*==============================================================================
VARIAVEIS
==============================================================================*/ 
int1 
   flagLeituraAnalogica = false,
   flagAcionamento = false;

unsigned int16
   contadorTempoAH = 0,
   contadorTempoH = 0,

   setpointTempoHorario = TEMPO_MAX_H;
/*==============================================================================
VARIAVEIS ARRAY
==============================================================================*/
/*==============================================================================
ARQUIVOS ANEXOS
==============================================================================*/
#include <UtilityAnalog.c>
#include <SubrotinasOperacao.c>
#include <InterrupcaoTimer1.c>
/*==============================================================================
MAIN                                           
==============================================================================*/
void main() {                              
   setup_oscillator(OSC_4MHZ);  
   setup_adc(adc_clock_internal);
   setup_adc_ports(sAN0);
   set_adc_channel(0);
                            
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);       
   setup_timer_2(T2_DISABLED, 0, 1); 
   
   off(RELE_AH);
   off(RELE_H);
   
   delay_ms(500);  
      
   leTempo();
                                                                                                   
   enable_interrupts(GLOBAL); 
   enable_interrupts(INT_TIMER1);

   while(true) {
      
      if(flagLeituraAnalogica) {
         flagLeituraAnalogica = false;
         leTempo();
      }

      operacao();
   }                                                   
}                          
/*==============================================================================
FIM DO FIRMWARE
==============================================================================*/
