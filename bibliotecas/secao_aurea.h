#ifndef SECAO_AUREA_H__
#define SECAO_AUREA_H__
template <typename F>
double secao_aurea(F f, double a, double b, double eps=1e-9){
    double xa = b - 0.618*(b-a);
    double xb = a + 0.618*(b-a);
    double fa = f(xa);
    double fb = f(xb);
    while(b-a>eps){
        if(fa<fb){
            b = xb;
            xb = xa;
            xa = b - 0.618 * (b-a);
            fb = fa;
            fa = f(xa);
        }else{
            a = xa;
            xa = xb;
            xb = a + 0.618 * (b-a);
            fa = fb;
            fb = f(xb);
        }
    }
    return (a+b)/2.0;
}
#endif