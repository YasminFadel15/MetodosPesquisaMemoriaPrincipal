#include <stdio.h>

int pesquisaInterpolacao(int chave, int v[], int n) {
    int ini = 0, meio, fim = n - 1;
    while (ini <= fim && chave >= v[ini] && chave <= v[fim]) {
        if (ini == fim) {
            if (v[ini] == chave) 
                return ini;
            
            return -1;
        }
        
        meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
        
        if (chave == v[meio]) {    
            return meio;
        } else {
            if (chave < v[meio]) {
                fim = meio - 1;
            } else {
                ini = meio + 1;
            }
        }
    }
    return -1; //Índice inválido
}
