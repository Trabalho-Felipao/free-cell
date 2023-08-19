#include "../include/Baralho.h"

Baralho::Baralho() {
    for (int naipe = 0; naipe < QTDE_NAIPES; naipe++) {
        for (int valor = 0; valor < QTDE_VALORES; valor++) {
            unsigned int posicao_vetor = QTDE_VALORES * naipe + valor;
            this->cartas[posicao_vetor] = Carta(Simbolo::todos_valores[valor], Simbolo::todos_naipes[naipe]);
        }
    }
}

void Baralho::imprimeCartas() const {
    for (int carta = 0; carta < TAMANHO_BARALHO; carta++) {
        this->cartas[carta].imprimeCarta();
    }
}