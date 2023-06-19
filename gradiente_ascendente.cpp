#include "bibliotecas/gradiente.h"
#include "bibliotecas/gradiente_ascendente.h"
#include "bibliotecas/secao_aurea.h"
int main() {
    auto f = [](vector<double> x){
        return x[0]*x[0]+2*x[1];
    };
    vector<double>x = {2.0,3.0};
    auto x_ot = gradiente_descendente(f,x);
    auto f_ot = f(x_ot);
    cout << f_ot << endl;
    
    return 0;
}