#include "batalla_naval.h"
#include <iostream>
#include <vector>

using namespace std;

bool comprovarVaixellEnfonsat(EstatTauler taulerInicial[N_FILES][N_COLUMNES], 
                               EstatTauler taulerResultat[N_FILES][N_COLUMNES], 
                               int fila, int columna) {
    // Verifiquem si la casella seleccionada té un vaixell tocat
    if (taulerResultat[fila][columna] != ESTAT_TOCAT) {
        return false;
    }

    // Busquem si hi ha alguna altra part del vaixell no descoberta
    bool enfonsat = true;
    vector<pair<int,int>> m_vector;
    // Comprovem horitzontalment
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

    // Comprovem verticalment
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
        // Marquem totes les parts del vaixell com a ENFONSAT
        c = columna;
        bool trobat=false;
        while (c >= 0 && taulerInicial[fila][c] == ESTAT_VAIXELL) {
            taulerResultat[fila][c] = ESTAT_ENFONSAT;
            m_vector.push_back(make_pair(fila, c));
            c--;
        }
        c = columna;
        while (c < N_COLUMNES && taulerInicial[fila][c] == ESTAT_VAIXELL) {
            taulerResultat[fila][c] = ESTAT_ENFONSAT;
            m_vector.push_back(make_pair(fila, c));
            c++;
        }
        taulerResultat[fila][c]=ESTAT_AIGUA;
        f = fila;
        while (f >= 0 && taulerInicial[f][columna] == ESTAT_VAIXELL) {
            taulerResultat[f][columna] = ESTAT_ENFONSAT;
            m_vector.push_back(make_pair(f, columna));
            f--;
        }
        f = fila;
        while (f < N_FILES && taulerInicial[f][columna] == ESTAT_VAIXELL) {
            taulerResultat[f][columna] = ESTAT_ENFONSAT;
            m_vector.push_back(make_pair(f, columna));
            f++;
        }
        for(int i = 0 ;i<m_vector.size();i++){
            if(taulerInicial[m_vector[i].first+1][m_vector[i].second]==ESTAT_AIGUA&&m_vector[i].first+1<N_FILES)
                taulerResultat[m_vector[i].first+1][m_vector[i].second]=ESTAT_AIGUA;

            if(taulerInicial[m_vector[i].first][m_vector[i].second+1]==ESTAT_AIGUA&&m_vector[i].second+1<N_COLUMNES)
                taulerResultat[m_vector[i].first][m_vector[i].second+1]=ESTAT_AIGUA;

            if(taulerInicial[m_vector[i].first-1][m_vector[i].second]==ESTAT_AIGUA&&m_vector[i].first-1>=0)
                taulerResultat[m_vector[i].first-1][m_vector[i].second]=ESTAT_AIGUA;

            if(taulerInicial[m_vector[i].first][m_vector[i].second-1]==ESTAT_AIGUA&&m_vector[i].second-1>=0)
                taulerResultat[m_vector[i].first][m_vector[i].second-1]=ESTAT_AIGUA;
            
            if(taulerInicial[m_vector[i].first+1][m_vector[i].second+1]==ESTAT_AIGUA&&m_vector[i].first+1<N_FILES&&m_vector[i].second<N_FILES)
                taulerResultat[m_vector[i].first+1][m_vector[i].second+1]=ESTAT_AIGUA;
            
            if(taulerInicial[m_vector[i].first-1][m_vector[i].second-1]==ESTAT_AIGUA&&m_vector[i].first+1>0&&m_vector[i].second>=0)
                taulerResultat[m_vector[i].first-1][m_vector[i].second-1]=ESTAT_AIGUA;
                
            if(taulerInicial[m_vector[i].first+1][m_vector[i].second-1]==ESTAT_AIGUA&&m_vector[i].first<N_FILES&&m_vector[i].second>=0)
                taulerResultat[m_vector[i].first+1][m_vector[i].second-1]=ESTAT_AIGUA;
                
            if(taulerInicial[m_vector[i].first-1][m_vector[i].second+1]==ESTAT_AIGUA&&m_vector[i].second<N_FILES&&m_vector[i].first>=0)
                taulerResultat[m_vector[i].first-1][m_vector[i].second+1]=ESTAT_AIGUA;
            
            
            
                
        }
        
    }

    return enfonsat;
}


void mostrarTauler(EstatTauler tauler[N_FILES][N_COLUMNES]) {
    for (int i = 0; i < N_FILES; i++) {
        for (int j = 0; j < N_COLUMNES; j++) { 
            switch(tauler[i][j]){
                case ESTAT_AIGUA:
                cout<<"A"<<" ";
                break;
                case ESTAT_ENFONSAT:
                cout<<"E"<<" ";
                break;
                case ESTAT_TOCAT:
                cout<<"T ";
                break;
                case ESTAT_NUL:
                cout<<"N ";
                break;
                case ESTAT_VAIXELL:
                cout<<"V ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Initialize the board
    int contador= 0;
    int fila=0;
    int columna=0;
    bool enfonsat=false;
    cout<<"A continuacio tenim la nomenclatura de la mostra de vaixells: "<<endl;
    cout<<"E: representa que esta enfonsat"<<endl;
    cout<<"A: representa Aigua"<<endl;
    cout<<"T: tocat"<<endl;
    EstatTauler taulerInicial[N_FILES][N_COLUMNES] = {
        {ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA},
        {ESTAT_AIGUA, ESTAT_VAIXELL, ESTAT_VAIXELL, ESTAT_VAIXELL, ESTAT_AIGUA},
        {ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA},
        {ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_VAIXELL, ESTAT_AIGUA, ESTAT_AIGUA},
        {ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_VAIXELL, ESTAT_AIGUA, ESTAT_AIGUA}
    };

    EstatTauler taulerResultat[N_FILES][N_COLUMNES] = {
        {ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL},
        {ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL},
        {ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL},
        {ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL},
        {ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL, ESTAT_NUL}
    };
    int casellesVaixell=0;
    for(int i =0;i<N_FILES;i++){
        for(int j = 0;j<N_COLUMNES;j++){
            if(taulerInicial[i][j]==ESTAT_VAIXELL)
                casellesVaixell++;
        }
    }
   
do{    cout<<"Taula inicial: "<<endl;
    mostrarTauler(taulerInicial);
    cout<<"Taula Resultat"<<endl;
    mostrarTauler(taulerResultat);
    cout<<"Introdueix a continuacio fila: "<<endl;
    cin>>fila;
    cout<<"Introdueix a continuacio columna: "<<endl;
    cin>>columna;
     if(taulerInicial[fila][columna]==ESTAT_VAIXELL){
        taulerResultat[fila][columna]=ESTAT_TOCAT;
        cout<<"Has tocat un vaixell"<<endl;
        enfonsat=comprovarVaixellEnfonsat(taulerInicial, taulerResultat, fila, columna);
        if(enfonsat){
            cout<<"Has enfonsat un vaixell"<<endl;
        }
        contador++;
     }else{
         cout<<"Has fallat, aigua"<<endl;
         taulerResultat[fila][columna]=ESTAT_AIGUA;
     }
}while(contador<casellesVaixell);
mostrarTauler(taulerResultat);
}
