#include <iostream>
#include <string>
#include <vector>
#ifndef BIGINT_H__
#define BIGINT_H__
using namespace std;
bool maior(string x, string y){
    if(x.length()>y.length()){
        return true;
    }else if(x.length()<y.length()){
        return false;
    }else{
        for(int i=0;i<x.length();i++){
            if(x[x.length()-1-i] == y[y.length()-1-i]){
                continue;   
            }else if(x[x.length()-1-i] > y[y.length()-1-i]){
                return true;
            }else if(x[x.length()-1-i] < y[y.length()-1-i]){
                return false;
            }
        }
    }
    return true;
}

string subtrair(string x,string y){
    int cont=0;
    for(int i=0;i<x.length();i++){
        string a = "";
        string b = "";
        a+=x[i];
        b+=y[i];
        if(stoi(to_string(y[i]))==0){
            b="0";
        }
        int val = stoi(a)-stoi(b)-cont;
        cont=0;
        if(val<0){
            cont+=1;
            val=val+10;
        }
        x[i] = to_string(val)[0];
    }
    return x;
}

string adicionar(string x, string y){
    int cont=0;
    for(int i=0;i<x.length();i++){
        string a = "";
        string b = "";
        a+=x[i];
        b+=y[i];
        if(stoi(to_string(y[i]))==0){
            b="0";
        }
        int val = stoi(a)+stoi(b)+cont;
        cont=0;
        if(val>9){
            cont+=1;
            val=val-10;               
        }
        x[i] = to_string(val)[0];
    }
    if(cont>0){
        x.push_back(to_string(cont)[0]);
    }
    return x;
}

class BigInt{
    public:
        BigInt(string valor){
            this->valor = valor;
            for(int x=0;x<valor.length();x++){
                this->valor[valor.length()-1-x] = valor[x];
            }
        }
        BigInt(const BigInt &bi){
            this->valor = bi.valor;
        }
        BigInt operator=(const BigInt &bi){
            if(this != &bi){
                this->valor = bi.valor;
            }
            return *this;
        }

        BigInt operator+(BigInt &bi){         
            if(maior(this->valor,bi.valor)){
                this->valor = adicionar(this->valor,bi.valor);
            }else{
                this->valor = adicionar(bi.valor,this->valor);
            }
            return *this;
        }
        BigInt operator-(BigInt &bi){
            if(maior(this->valor,bi.valor)){
                this->valor = subtrair(this->valor,bi.valor);
            }else{
                this->valor = subtrair(bi.valor,this->valor);
                this->valor.push_back('-');   
            }
            return *this;
        }
        BigInt operator*(BigInt &bi){
            BigInt result("0");
            BigInt menos("1");
            bool t=true;
            for(int i=0;i<bi.valor.length();i++){
                if(bi.valor[i]!='0'){
                    break;
                }
                if(i==(bi.valor.length()-1)){
                    t = false;
                }
            }
            while(t){
                result = result+*this;
                bi = bi - menos;
                for(int i=0;i<bi.valor.length();i++){
                    if(bi.valor[i]!='0'){
                        break;
                    }
                    if(i==(bi.valor.length()-1)){
                        t = false;
                    }
                }
            }   
            return result;
        }
        BigInt operator/(BigInt &bi){
            int cont=-1;
            while(this->valor[this->valor.length()-1]!='-'){
                cont+=1;
                *this = *this-bi;
            }
            BigInt result(to_string(cont));
            return result;
        }
        void print(){
            for(int x=0;x<this->valor.length();x++){
                cout << this->valor[valor.length()-1-x];
            }
            cout << endl;
        }

        string valor;
};
#endif