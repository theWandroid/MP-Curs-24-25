#include "batalla_naval.h"
#include <iostream>
#include <vector>

using namespace std;


bool comprovarVaixellEnfonsat(EstatTauler taulerInicial[N_FILES][N_COLUMNES],
    EstatTauler taulerResultat[N_FILES][N_COLUMNES],
    int fila, int columna) {

    if (taulerResultat[fila][columna] != ESTAT_TOCAT) {
        return false;
    }

    // Busquem si hi ha alguna altra part del vaixell no descoberta
    bool enfonsat = true;

    // Comprovem horitzontalment (esquerra i dreta)
    int c = columna;
    while (c >= 0 && taulerInicial[fila][c] == ESTAT_VAIXELL) {
        if (taulerResultat[fila][c] != ESTAT_TOCAT) {
            enfonsat = false;
            break;
        }
        c--;
    }
    c = columna;
    while (c < N_COLUMNES && taulerInicial[fila][c] == ESTAT_VAIXELL) {
        if (taulerResultat[fila][c] != ESTAT_TOCAT) {
            enfonsat = false;
            break;
        }
        c++;
    }

    // Comprovem verticalment (amunt i avall)
    int f = fila;
    while (f >= 0 && taulerInicial[f][columna] == ESTAT_VAIXELL) {
        if (taulerResultat[f][columna] != ESTAT_TOCAT) {
            enfonsat = false;
            break;
        }
        f--;
    }
    f = fila;
    while (f < N_FILES && taulerInicial[f][columna] == ESTAT_VAIXELL) {
        if (taulerResultat[f][columna] != ESTAT_TOCAT) {
            enfonsat = false;
            break;
        }
        f++;
    }

    // Si està enfonsat, canviem l'estat del vaixell a ENFONSAT
    if (enfonsat) {
        // Marquem totes les parts del vaixell com a ENFONSAT horitzontalment (esquerra i dreta)
        c = columna;
        while (c >= 0 && taulerInicial[fila][c] == ESTAT_VAIXELL) {
            taulerResultat[fila][c] = ESTAT_ENFONSAT;
            c--;
        }
        c = columna;
        while (c < N_COLUMNES && taulerInicial[fila][c] == ESTAT_VAIXELL) {
            taulerResultat[fila][c] = ESTAT_ENFONSAT;
            c++;
        }

        // Marquem totes les parts del vaixell com a ENFONSAT verticalment (amunt i avall)
        f = fila;
        while (f >= 0 && taulerInicial[f][columna] == ESTAT_VAIXELL) {
            taulerResultat[f][columna] = ESTAT_ENFONSAT;
            f--;
        }
        f = fila;
        while (f < N_FILES && taulerInicial[f][columna] == ESTAT_VAIXELL) {
            taulerResultat[f][columna] = ESTAT_ENFONSAT;
            f++;
        }

        // Canviem l'estat de les cel·les d'aigua al voltant de les parts enfonsades
        for (int i = fila - 1; i <= fila + 1; i++) {
            for (int j = columna - 1; j <= columna + 1; j++) {
                if (i >= 0 && i < N_FILES && j >= 0 && j < N_COLUMNES) {
                    if (taulerInicial[i][j] == ESTAT_AIGUA) {
                        taulerResultat[i][j] = ESTAT_AIGUA;
                    }
                }
            }
        }
    }

    return enfonsat;
}


void mostrarTauler(EstatTauler tauler[N_FILES][N_COLUMNES]) {
    for (int i = 0; i < N_FILES; i++) {
        for (int j = 0; j < N_COLUMNES; j++) {
            switch (tauler[i][j]) {
            case ESTAT_AIGUA:
                cout << "X" << " ";
                break;
            case ESTAT_ENFONSAT:
                cout << "E" << " ";
                break;
            case ESTAT_TOCAT:
                cout << "T";
                break;
            case ESTAT_NUL:
                cout << "-";
                break;
            case ESTAT_VAIXELL:
                cout << "V";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void inicialitza(EstatTauler tauler[N_FILES][N_COLUMNES]) {
    for (int i = 0; i < N_FILES; i++) {
        for (int j = 0; j < N_COLUMNES; j++) {
            tauler[i][j] = ESTAT_NUL;
        }
    }
}
bool batallaNaval(EstatTauler taulerInicial[N_FILES][N_COLUMNES], int nIntents, EstatTauler taulerResultat[N_FILES][N_COLUMNES])
{
    int contador = 0;
    int fila = 0;
    int columna = 0;
    bool enfonsat = false;
    int casellesVaixell = 0;
    int casellesEnfonsat = 0;
    bool trobat = false;
    for (int i = 0; i < N_FILES; i++) {
        for (int j = 0; j < N_COLUMNES; j++) {
            if (taulerInicial[i][j] == ESTAT_VAIXELL) {
                casellesVaixell++;
            }
        }
    }
    //hem de realitzar dos tipus de comprovacions: primer cal comprovar si el nosra intent  s m s petit que el numero de nIntents.
    //la segona comprovacio es comprovar que el numero de caselles tocades equival al numero 
    inicialitza(taulerResultat);
    while (contador < nIntents and !trobat) {
        cin >> fila;
        cin >> columna;


        fila = fila - 1;
        columna = columna - 1;
        //resetem un valor de fila i columna perque al principi esta indexat a 1, pero nosaltres ho indexem a 0.
        contador++;
        if (taulerInicial[fila][columna] == ESTAT_VAIXELL) {
            casellesEnfonsat++;
            taulerResultat[fila][columna] = ESTAT_TOCAT;
            enfonsat = comprovarVaixellEnfonsat(taulerInicial, taulerResultat, fila, columna);

        }
        else {
            taulerResultat[fila][columna] = ESTAT_AIGUA;
        }
        if (casellesVaixell == casellesEnfonsat) {
            trobat = true;
        }

    }
    return trobat;
}

