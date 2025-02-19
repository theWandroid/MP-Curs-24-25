#include "batalla_naval.h"
#include <iostream>

using namespace std;


void inicialitzarTauler(EstatTauler taulerInicial[N_FILES][N_COLUMNES]) {
    for (int i = 0; i < N_FILES; i++)
    {
        for (int j = 0; j < N_COLUMNES; j++)
        {
            taulerInicial[i][j] = ESTAT_NUL;

        }
    }
}

bool batallaNaval(EstatTauler taulerInicial[N_FILES][N_COLUMNES], int nIntents, EstatTauler taulerResultat[N_FILES][N_COLUMNES])
{
    // Inicialitzar tauler

    inicialitzarTauler(taulerInicial);

    //Inicialitzar variables control

    //mentre no acabi partida
        //demanar cel·la
        //comprovar cel·la
    inicialitzarTauler(taulerResultat);


    return true;
}




