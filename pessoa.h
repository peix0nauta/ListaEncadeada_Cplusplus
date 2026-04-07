#include "headers.h"
#pragma once

class Pessoa {

    private:
    char nome[100],rg[12];
    Pessoa* prox;
    Pessoa* ant;
    public: 

    Pessoa();
    ~Pessoa();  

    void Setnome(char* nome);   
    void SetRG(char* RG);
    void Setprox(Pessoa* new_prox);
    void Setant(Pessoa* new_ant);
    char* Getnome();
    char* GetRG();
    Pessoa* getprox(){
        return prox;
    }
    Pessoa* getant(){
        return ant;
    }
};