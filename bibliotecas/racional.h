#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#ifndef RACIONAL_H__
#define RACIONAL_H__
using namespace std;
class Racional{
    public:
    int numerador;
    int denominador;

    double valor(){
        return numerador/(denominador*1.0);
    }


    const int& numeradors(){
        return numerador;
    }

    const int& denominadors(){
        return denominador;
    }

    void numeradors(int num){
        numerador = num;
    }

    void denominadors(int den){
        denominador = den;
    }

    Racional(){
        numerador=0;
        denominador=1;
    }

    Racional(int a, int b){
        numerador=a;
        denominador=b;
    }

    Racional(const Racional &rc){
        numerador = rc.numerador;
        denominador = rc.denominador;
    }
    
    Racional(Racional&& rc){
        numerador = rc.numerador;
        denominador = rc.denominador;
        rc.denominador = 0;
        rc.numerador = 0;
    }

    ~Racional(){
        denominador = 0;
        numerador = 0;
    }

    Racional& operator=(Racional&& rc);
    
    Racional& operator=(Racional& rc);

    bool operator<(Racional& rc);

    bool operator>(Racional& rc);

    bool operator<=(Racional& rc);

    bool operator>=(Racional& rc);

    bool operator==(Racional& rc);

    Racional operator+(Racional& rc);


    Racional operator-(Racional& rc);

    void operator+=(Racional& rc);

    void operator-=(Racional& rc);

    Racional operator*(Racional& rc);

    Racional operator/(Racional& rc);

    void operator*=(Racional& rc);

    void operator/=(Racional& rc);

    Racional& operator++();

    Racional operator++(int);

    Racional& operator--();

    Racional operator--(int);

    Racional operator-();

    friend ostream& operator<<(ostream& os,const Racional& rac);
};
ostream& operator<<(ostream& os,const Racional& rac){
    os << " " << rac.numerador << "/" << rac.denominador << " ";
    return os;
}


bool Racional::operator<(Racional& rc){
    if(valor()<rc.valor()){
        return true;
    }
    return false;
}

bool Racional::operator>(Racional& rc){
    if(valor()>rc.valor()){
        return true;
    }
    return false;
}

bool Racional::operator<=(Racional& rc){
    if(valor()<=rc.valor()){
        return true;
    }
    return false;
}

bool Racional::operator>=(Racional& rc){
    if(valor()>=rc.valor()){
        return true;
    }
    return false;
}

bool Racional::operator==(Racional& rc){
    if(valor()==rc.valor()){
        return true;
    }
    return false;
}

Racional& Racional::operator=(Racional&& rc){
    if(this != &rc){
        denominador = rc.denominador;
        numerador = rc.numerador;
    }
    return *this;
}

Racional& Racional::operator=(Racional& rc){
    if(this != &rc){
        denominador = rc.denominador;
        numerador = rc.numerador;
    }
    return *this;
}

Racional Racional::operator+(Racional& rc){
    int mmc = lcm(rc.denominador,denominador);
    Racional x = *this;
    x.numerador = ((mmc/denominador)*numerador)+(mmc/rc.denominador)*rc.numerador;
    x.denominador = mmc;
    int mdc = gcd(x.numerador,x.denominador);
    x.numerador = x.numerador/mdc;
    x.denominador = x.denominador/mdc;
    return x;
}


Racional Racional::operator-(Racional& rc){
    int mmc = lcm(rc.denominador,denominador);
    Racional x = *this;
    x.numerador = ((mmc/denominador)*numerador)-(mmc/rc.denominador)*rc.numerador;
    x.denominador = mmc;
    int mdc = gcd(x.numerador,x.denominador);
    x.numerador = x.numerador/mdc;
    x.denominador = x.denominador/mdc;
    return x;
}


void Racional::operator+=(Racional& rc){
    int mmc = lcm(rc.denominador,denominador);
    numerador = ((mmc/denominador)*numerador)+(mmc/rc.denominador)*rc.numerador;
    denominador = mmc;
    int mdc = gcd(numerador,denominador);
    numerador = numerador/mdc;
    denominador = denominador/mdc;
}


void Racional::operator-=(Racional& rc){
    int mmc = lcm(rc.denominador,denominador);
    numerador = ((mmc/denominador)*numerador)+(mmc/rc.denominador)*rc.numerador;
    denominador = mmc;
    int mdc = gcd(numerador,denominador);
    numerador = numerador/mdc;
    denominador = denominador/mdc;
}


Racional Racional::operator*(Racional& rc){
    Racional x = Racional();
    x.denominador = denominador*rc.denominador;
    x.numerador = numerador*rc.numerador;
    return x;
}


Racional Racional::operator/(Racional& rc){
    Racional x = Racional();
    x.denominador = denominador*rc.numerador;
    x.numerador = numerador*rc.denominador;
    return x;
}


void Racional::operator*=(Racional& rc){
    denominador = denominador*rc.denominador;
    numerador = numerador*rc.numerador;
}


void Racional::operator/=(Racional& rc){
    denominador = denominador*rc.numerador;
    numerador = numerador*rc.denominador;
}


Racional& Racional::operator++(){
    Racional x = Racional(1,1);
    *this+=x;
    return *this;
}

Racional Racional::operator++(int){
    Racional x = Racional(1,1);
    Racional temp = *this;
    *this+=x;
    return temp;
}

Racional& Racional::operator--(){
    Racional x = Racional(1,1);
    *this-=x;    
    return *this;
}

Racional Racional::operator--(int){
    Racional x = Racional(1,1);
    Racional temp = *this;
    *this-=x;
    return temp;
}

Racional Racional::operator-(){
    numerador = -numerador;
    return *this;
}
#endif