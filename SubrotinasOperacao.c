///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasOperacao
//AUTOR:      Fábio Almeida
//CRIADO:     23/12/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
OPERAÇÃO                                       
==============================================================================*/
void operacao() {
    if(flagAcionamento) {
        if(input(ENTRADA)) {
            delay_ms(DEBOUNCE);
            if(input(ENTRADA)) {
                flagAcionamento = false;
                return;
            }
        }

        if(contadorTempoH) {
            off(RELE_AH);
            on(RELE_H);
            if(contadorTempoH >= setpointTempoHorario) {
                contadorTempoH = 0;
                contadorTempoAH = 1;
            }
        }
        else if(contadorTempoAH) {
            on(RELE_AH);
            off(RELE_H);
            if(contadorTempoAH >= TEMPO_AH) {
                contadorTempoAH = 0;
                contadorTempoH = 1;
            }
        }

        return;
    }

    off(RELE_AH);
    off(RELE_H);

    contadorTempoAH = 0;
    contadorTempoH = 0;

    if(!input(ENTRADA)) {
        delay_ms(DEBOUNCE);
        if(!input(ENTRADA)) {
            flagAcionamento = true;
            contadorTempoAH = 0;
            contadorTempoH = 1;
        }
    }
}
/*==============================================================================
FIM DO ARQUIVO                                       
==============================================================================*/