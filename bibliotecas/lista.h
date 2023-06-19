#ifndef __LISTA_H
#define __LISTA_H
#include <iostream>
#include "no.h"
using namespace std;
template<class R>
class Lista{
    public:
        Lista(){
            cabeca = NULL;
            valor = 0;
        }
        ~Lista();
        template<class T>
        void adicionaInicio(T x){
            if(cabeca==NULL){
                No<R> *t = new No<int>(x);
                cabeca = t;
                return;
            }
            No<R> *t = new No<int>();
            *t = *cabeca;
            cabeca->valor = x;
            cabeca->proximo = t;
        }
        
        template<class T>
        void adicionaFim(T x){
            No<R> *t = cabeca;
            if(cabeca == NULL){
                adicionaInicio(x);
                return;
            }
            while(t->proximo != NULL){
                t = t->proximo;
            }
            No<R> *c = new No<int>();
            c->valor = x;
            t->proximo = c;      
        }

        template<class T>
        void adiciona(T x, int pos){
            No<R> *t = new No<R>();
            t = this->cabeca;
            if(pos == 1){
                adicionaInicio(x);
                return;
            }
            for(int i=0;i<pos-2;i++){
                t = t->proximo;
            }
            No<R> *l = new No<R>();
            l->valor = x;
            l->proximo = t->proximo;
            t->proximo = l;
        }

        R buscar(int pos){
            No<R> *t = new No<R>();
            t = this->cabeca;
            for(int i=0;i<pos-1;i++){
                t = t->proximo;
            }
            return t->valor;
        }

        void remove(int pos){
            No<R> *t;
            t = this->cabeca;
            if(pos==1){
                this->cabeca = this->cabeca->proximo;
            }
            for(int i=0;i<pos-2;i++){
                t = t->proximo;
            }
            t->proximo = t->proximo->proximo;
        }

        void imprimir(){
            No<R> *t;
            t = this->cabeca;
            while(t != NULL){
                cout << t->valor << endl;
                t = t->proximo;
            }
            cout << endl;
        }        
    private:
        No<R> *cabeca = new No<R>();
        R valor;
};
#endif