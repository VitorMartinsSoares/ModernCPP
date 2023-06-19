#include "bibliotecas/gradiente.h"
#include "bibliotecas/secao_aurea.h"
int main() {
    auto f = [](vector<double> x){
        return x[0]*x[0]+2*x[1];
    };
    vector<double>x = {2.0,3.0};
    auto g = gradiente(f,x);
    cout << "[" << g[0] << ", " << g[1] << "]" << endl;
    auto ff = [](double x){
        return x*x;
    };
    auto gg = secao_aurea(ff,-5,3);
    cout << gg << endl;
    
    return 0;
}