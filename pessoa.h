#include "headers.h"
#pragma once

class Pessoa {

    private:
    char nome[100],rg[12];

    public: 

    Pessoa();
    ~Pessoa();  

    void Setnome(char* nome);   
    void SetRG(char* RG);
    char* Getnome();
    char* GetRG();

};