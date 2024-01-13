#include "ElementDecor.h"

using namespace std;

void Maison::affiche(int num_ligne){
    if(num_ligne==0){cout<<"/=========\\";}
    if(num_ligne==1){cout<<"|o        |";}
    if(num_ligne==2){cout<<"|  _____  |";}
    if(num_ligne==3){cout<<"|  |   |  |";}
    if(num_ligne==4){cout<<"|__|___|__|";}
}

void Arbre::affiche(int num_ligne){
    if(num_ligne==0){cout<<" /\\ ";}
    if(num_ligne==1){cout<<" /\\ ";}
    if(num_ligne==2){cout<<" /\\ ";}
    if(num_ligne==3){cout<<" /\\ ";}
    if(num_ligne==4){cout<<"_/\\_";}
}

void Escargot :: affiche(int num_ligne){
    if(num_ligne==0){cout<<"     ";}
    if(num_ligne==1){cout<<"     ";}
    if(num_ligne==2){cout<<"     ";}
    if(num_ligne==3){cout<<"     ";}
    if(num_ligne==4){cout<<"_Y@_ ";}
}

void Pierre :: affiche(int num_ligne){
    if(num_ligne==0){cout<<"     _____     __     ";}
    if(num_ligne==1){cout<<"   /      \   /   \   ";}
    if(num_ligne==2){cout<<"  |        \_/    |   ";}
    if(num_ligne==3){cout<<"  /                \  ";}
    if(num_ligne==4){cout<<"_/                  \_";}
}
