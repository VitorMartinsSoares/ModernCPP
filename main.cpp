#include <iostream>
#include <algorithm>
#include "racional.h"
using namespace std;
int main() {
    vector<Racional> vet;
    vet.push_back(Racional(1,4));
    vet.push_back(Racional(1,2));
    vet.push_back(Racional(1,3));
    vet.push_back(Racional(1,1));
    for(auto x=vet.begin();x<vet.end();x++){
        cout << (*x).valor() << endl;
    }
    cout << "SORTEADO" << endl;
    sort(vet.begin(),vet.end());
    for(auto x=vet.begin();x<vet.end();x++){
        cout << *x << endl;
    }
    return 0;
}