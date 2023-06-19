#include <iostream>
#include <vector>
#ifndef URL_H__
#define URL_H__
using namespace std;
class Url{
    public:
        Url(string esquema, string dominio, string caminho, int porta=0){
            this->esquema = esquema;
            this->dominio = dominio;
            this->caminho = caminho;
            this->porta = porta;
        }
        Url(const Url &url){
            this->esquema = url.esquema;
            this->dominio = url.dominio;
            this->caminho = url.caminho;
            this->porta = url.porta;
        }

        void setEsquema(string esquema){
            this->esquema = esquema;
        }
        void setDominio(string dominio){
            this->dominio = dominio;
        }
        void setCaminho(string caminho){
            this->caminho = caminho;
        }
        void setRecurso(string recurso){
            this->recurso = recurso;
        }
        void setQuery_string(string query_string){
            this->query_string = query_string;
        }
        void setFragmento(string fragmento){
            this->fragmento = fragmento;
        }
        void setPorta(int porta){
            this->porta = porta;
        }

        string getEsquema(){
            return esquema;
        }
        string getDominio(){
            return dominio;
        }
        string getCaminho(){
            return caminho;
        }
        string getRecurso(){
            return recurso;
        }
        string getQuery_string(){
            return query_string;
        }
        string getFragmento(){
            return fragmento;
        }
        int getPorta(){
            return porta;
        }

    private:
        string esquema;
        string dominio;
        int porta;
        string caminho;
        string recurso;
        string query_string;
        string fragmento;
};

Url operator"" _url(const char *str, size_t len){
    string t(str,len);
    string aux = "";
    string esquema;
    string dominio;
    string caminho;
    string recurso;
    string query_string;
    string fragmento;
    int porta;
    int x = 0;
    int op = 0;
    for(int i=x;i<t.length();i++){
        if(t[i]==':' && t[i+1]=='/' && t[i+2]=='/'){
            x = i+3;
            break;
        }
        aux+=t[i];
    }
    esquema = aux;
    aux = "";
    for(int i=x;i<t.length();i++){
        if(t[i]==':'){
            x = i+1;
            dominio = aux;
            aux = "";
            for(int j=x;j<t.length();j++){
                if(t[j]=='/'){
                    x = j+1;
                    break;
                }
                aux+=t[j];
            }
            porta = stoi(aux);
            break;
        }
        if(t[i]=='/'){
            x = i+1;
            dominio = aux;
            break;
        }
        aux+=t[i];
    }
    aux = "";
    for(int i=x;i<t.length();i++){
        if(t[i]=='/'){
            x = i+1;
            break;
        }
        aux+=t[i];
    }
    caminho = aux;
    aux = "";
    for(int i=x;i<t.length();i++){
        if(t[i]==':'){
            x = i+1;
            recurso = aux;
            for(int j=x;j<t.length();j++){
                if(t[j]=='#'){
                    x = j+1;
                    query_string = aux;
                    for(int j=x;j<t.length();j++){
                        aux+=t[j];
                    }
                    fragmento = aux;
                    break;
                }
                aux+=t[j];
            }
            break;
        }
        if(t[i]=='#'){
            x = i+1;
            recurso = aux;
            for(int j=x;j<t.length();j++){
                aux+=t[j];
            }
            fragmento = aux;
            break;
        }
        aux+=t[i];
    }
    Url novo_url(esquema, dominio, caminho, porta);
    return novo_url;
}
#endif