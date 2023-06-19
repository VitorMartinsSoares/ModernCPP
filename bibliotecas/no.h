#ifndef __NO_H
#define __NO_H
#include <iostream>
template<class R>
class No{
    public:
    No(){
        proximo = NULL;
    }
    template<class M>
    No(M n){
        valor = n;
        proximo = NULL;
    }
    No *proximo;
    R valor;
};
#endif