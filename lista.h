#include "headers.h"
#include "pessoa.h"
#pragma once


class lista
{
private:
    Pessoa* prim;
    Pessoa* ult;

public:
    unsigned long long Cn,Mn;
    lista();
    ~lista();
    void inserirnofinal();
    void inserirnocomeço();
    void inserirnomeio();
    void inserirnofinal(Pessoa* nova);
    void removerdoinicio();
    void removedofim();
    void removedomeio();
    void salvararquivo();
    void ProcuraRG();
    void exibirMetricas();
    void zerarMetricas(){Cn=0;Mn=0;}


    Pessoa* getprim(){
        return prim;
    }
    Pessoa* getult(){
        return ult;
    }

};
