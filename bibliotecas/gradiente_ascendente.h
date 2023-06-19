#include <bits/stdc++.h>
#ifndef GRADIENTE_ASCENDENTE_H__
#define GRADIENTE_ASCENDENTE_H__
#include "gradiente.h"
#include "secao_aurea.h"
using namespace std;
template <typename F>
vector<double> gradiente_descendente(F f, vector<double> x){
    unsigned long long k=0;
    vector<double> x_pref = x;
    double diff;
    do{
        auto g = gradiente(f,x,1e-9);
        auto fu = [&f, &g, &x](double alpha){
            auto xd = x;
            for(int i=0;i<x.size();++i){
                xd[i] = xd[i] - alpha * g[i];
            }
            return f(xd);
        };
        auto alpha = secao_aurea(fu,0,3);
        x_pref = x;
        for(int i=0;i<x.size();++i){
            x_pref[i] = abs(x_pref[i] - alpha * g[i]);
        }

        for(int i=0;i<x.size();++i){
            diff += x[i] - x_pref[i] * x[i] - x_pref[i];
        }
        diff = sqrt(diff); 
    }while(abs(f(x_pref))-f(x)>0.01);
    return x;
}
#endif