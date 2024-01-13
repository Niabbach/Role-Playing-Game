#include "fonction.h"
#include "ElementDecor.h"
#include <string>
void affiche_entete_promenade(const Personnage &hero)
{
    cout << "\t\t" << "<<Mode Promenade>>" << endl;
    cout << hero.getnom() << endl;
    cout << "PV: " << hero.getPV() << "(100max)"<<endl;
    cout << "nb potions:" << hero.get_nb_potion() <<endl;
    cout << "---------------------------------------------------------------\n";
	cout << "d pour droite : q pour gauche : s pour soin"<<endl;
	cout << "===============================================================\n";
}

void afficher_entete_combat(const Personnage &hero, const Personnage &ennemi){

    cout << "\t" << "<<Mode Combat>>" << endl;
    cout << hero.getnom()<<"\t\t\t";
    cout << ennemi.getnom()<<endl;
    cout << "PV:"<<hero.getPV()<<"(100max)"<<"\t\t";
    cout << "PV:"<<ennemi.getPV()<<"(100max)"<<endl;
    cout << "Force:"<<hero.getFoerce()<<"\t\t";
    cout << "Force:"<<ennemi.getFoerce()<<endl;
    cout << "VIT:"<<hero.getVIT()<<"\t\t\t";
    cout << "VIT:"<<ennemi.getVIT()<<endl;
    cout << "nb potions:"<<hero.get_nb_potion()<<"\t\t";
    cout << "nb potions:"<<ennemi.get_nb_potion()<<endl;
    cout << "----------------------------------------------------\n";
    cout << "t pour taper : f pour fuite : s pour soin"<<endl;
    cout << "====================================================\n";

}

void affiche_bordure(){

    for(int i=0; i < 79; i++){
        cout << "-";
    }
}

void affiche_hero(Personnage &hero){
     for (int i = 0; i < 5; i++) {
	   hero.affiche(i + 1);
	   cout << endl;
     }
}
void affiche_personnage_combat(Personnage &hero, Personnage &ennemi){
     for (int i = 0; i < 6; i++) {
	   hero.affiche(i);
	   cout << "\t\t\t\t\t\t";
	   ennemi.affiche(i);
	   cout << endl;
     }
}

void affiche_personnage(Personnage &ennemi){
    for (int i = 0; i < 6; i++) {
       cout<<"\t\t\t\t\t\t";
       ennemi.affiche(i);
       cout << endl;
     }
}

void final_stage_decor()
{
												
	cout << "						 /\\   l^^^^^^^^^^^^^^^l  /\\\n";
	cout << "			            /__\\ _l O  O  O  O  O l_/__\\\n";
	cout << "		                l   l l               l     l\n";
	cout << "		                l   l l               l     l\n";
	cout << "		 [^^^]          l  [^^^]             [^^^]  l          [^^^]    \n";
	cout << "		 [ o ]-------------[ o ]-------------[ o ]-------------[ o ]    \n";
	cout << "		 [   ]             [   ]     ___     [   ]             [   ]    \n";
	cout << "		 [   ]             [   ]    /   \\    [   ]             [   ]    \n";
	cout << "		 [   ]             [   ]   |     |   [   ]   o         [   ]    \n";
	cout << "		 [   ]             [   ]   |     |   [   ]~\\_|_        [   ]    \n";
	cout << "    ________[___]_____________[___]___|_____|___[___]_/\\_/\\_______[___]_\n";
}