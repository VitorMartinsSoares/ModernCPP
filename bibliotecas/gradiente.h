#include <bits/stdc++.h>
#ifndef GRADIENTE_H__
#define GRADIENTE_H__
using namespace std;
template <typename F>
vector<double> gradiente(F f, vector<double> x, double delta=1e-5){
    size_t n = x.size();
    vector<double> xd = x;
    vector<double> g(n,0);
    for(int i=0;i<n;i++){
        xd[i]+=delta;
        g[i] = (f(xd)-f(x))/delta;
        xd[i] = x[i];
    }   
    return g;
}
#endif