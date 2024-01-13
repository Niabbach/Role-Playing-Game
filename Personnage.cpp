#include "Personnage.h"
#include <string>

using namespace std;


void Hero::affiche(int num_ligne)
{
    if (num_ligne == 1){ cout << "          "; }
	if (num_ligne == 2){ cout << "  _@_    "; }
	if (num_ligne == 3){ cout << " C\\_/\\/ "; }
	if (num_ligne == 4){ cout << "  | |     "; }
	if (num_ligne == 5){ cout << "  | l     "; }


}

void Lambda::affiche(int num_ligne)
{
    if (num_ligne == 1){ cout << "         "; }
	if (num_ligne == 2){ cout << "  _@_   "; }
	if (num_ligne == 3){ cout << " /\\_/\\ "; }
	if (num_ligne == 4){ cout << "  | |    "; }
	if (num_ligne == 5){ cout << "  | l    "; }
}

void Serpent::affiche(int num_ligne)
{
	if(num_ligne == 1) {cout <<"   _          " ; }
	if(num_ligne == 2) {cout <<"  /j \\       " ; }
	if(num_ligne == 3) {cout <<"    __/  _____" ; }
	if(num_ligne == 4) {cout <<"   /__/ /     " ; }
	if(num_ligne == 5) {cout <<"   \\__/      " ; }

}




void Renard::affiche(int num_ligne)
{
    if(num_ligne == 1) {cout <<"                __ " ; }
	if(num_ligne == 2) {cout <<"  ' _'        ___/   " ; }
	if(num_ligne == 3) {cout <<"  /j \\ ____/_____  " ; }
	if(num_ligne == 4) {cout <<"    __ /  _/\\__    " ; }
    if(num_ligne == 5) {cout <<"               \\__ " ; }

}

void Fee::affiche(int num_ligne)
{
    if(num_ligne == 1) {cout << "   |}.'}  " ; }
    if(num_ligne == 2) {cout << "  \()/%(  " ; }
	if(num_ligne == 3) {cout << "   _>\_{  " ; }
	if(num_ligne == 4) {cout << "    /|    " ; }
	if(num_ligne == 5) {cout << "    \\    " ; }
}

void centaurus::affiche(int num_ligne)
{
	if (num_ligne == 1) { cout << " <=======]}====== "; }
	if (num_ligne == 2) { cout << "    --.   /|      "; }
	if (num_ligne == 3) { cout << "   _\"/_.'/       "; }
	if (num_ligne == 4) { cout << " .'._._,.'        "; }
	if (num_ligne == 5) { cout << " :/ \{}/          "; }
}

void centaurus::autocombat(Personnage & ennemi, bool & reussite)
{
	donner_coup(ennemi);
}


Personnage::Personnage(){
    PV = 100;
    PVmax = 100;
    Force= 50;
    VIT = 50;
    nb_potion = 3;
    message = " ";
    nom = " ";

}

Hero::Hero(){
    PV = 100;
    PVmax = 100;
    Force= 70;
    VIT = 50;
    nb_potion = 3;
    message = " ";
    nom = "Player";
}

centaurus::centaurus() {
	PV = 100;
	PVmax = 100;
	Force = 100;
	VIT = 50;
	nb_potion = 3;
	message = " ";
	nom = "Centaurus";
}

Lambda::Lambda(){
    PV = 0;
    PVmax = 0;
    Force= 0;
    VIT = 0;
    nb_potion = 0;
    message = "Bonjour aventurier, si tu debutes et cherches a te faire de l'argent alors la je te conseille d'aller dans la foret noir ...";
    nom = "villageois";
}

Serpent::Serpent(){
    PV = 100;
    PVmax = 100;
    Force= 40;
    VIT = 100;
    nb_potion = 3;
    message = " ";
    nom = "Serpent";

}

Renard::Renard(){
    PV = 100;
    PVmax = 100;
    Force= 15;
    VIT = 50;
    nb_potion = 3;
    message = " ";
    nom = "Renard";
}

Fee::Fee(){
    PV = 100;
    PVmax = 100;
    Force= 100;
    VIT = 25;
    nb_potion = 3;
    message = " ";
    nom = "Fee";
}

int Personnage::getFoerce() const{
    return Force;
}

string Personnage::getmessage() const{
    return message;
}

string Personnage::getnom() const{
    return nom;
}

void Personnage::setnom(string nnom){
    nom = nnom;
}

int Personnage::getPV()const{
    return PV;
}

void Personnage::setPV(int nPV){
    PV = nPV;
}

int Personnage::getPVmax() const{
    return PVmax;
}

int Personnage::getVIT() const{
    return VIT;
}

int Personnage::get_nb_potion() const{
    return nb_potion;
}

 void Personnage::donner_coup(Personnage &ennemi){

    int degat;

    degat = 10 * Force/ennemi.Force;
    ennemi.PV = ennemi.PV - degat;
    if(PV < 0){PV = 0;}
    if(ennemi.PV < 0){ennemi.PV = 0;}
    message = "attack\n";
}


void Personnage::prendre_coup(){
    if(PV!=100){message = "arghhhh\n";}
}

void Personnage::win(Personnage &ennemi){
    Force = Force + (ennemi.Force / Force) * Force / 100;
    VIT = VIT = (ennemi.VIT / VIT) * VIT / 100;
}

bool Personnage::fuite(const Personnage &ennemi){

    if(((PV*VIT)/(ennemi.PV*ennemi.VIT) *(50/100)) >= 90/100)
    {return 1;}
    else{return 0;}
}

void Serpent::autocombat(Personnage &ennemi, bool &reussite){
    donner_coup(ennemi);
}

void Renard::autocombat(Personnage &ennemi, bool &reussite){

    donner_coup(ennemi);
    if(PV<15){
        soin();
    }
}

void Fee::autocombat(Personnage &ennemi, bool &reussite){

    if(PV<100){
      /*  ennemi.setPV(ennemi.getPV() - 100 * Force / ennemi.getFoerce());
        message = "super attack : sortilège d'annihilation";
        if(ennemi.getPV()<0){ennemi.setPV(0);} */
        reussite = fuite(ennemi);
    }
}


 void Personnage::soin(){
    if(nb_potion>0)
    {
        cout << nom << ": regeneration ";
        for(int i = 0; i < 5; i++)
        {
            cout <<".";
            Sleep(1000);
        }

        PV = PV + (PVmax * 50 /100);
        if (PV > PVmax){
            PV = PVmax;
        }
        nb_potion--;
    }

 }

void Personnage::setmessage(string nmessage){
    message = nmessage;
}




                         
                         