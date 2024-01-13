#include <iostream>
#include "ElementDecor.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "fonction.h"
#include "Personnage.h"
#include <windows.h>
#include <string>

using namespace std;

int main()
{
   int taille_ville = 25;
   int taille_quete = 100;
   const int limit_ville = 10;
   const int limit_foret = 16;
   //-----------------------------------------------------------------------
   ElementDecor ** village;
   ElementDecor ** foret;
   ElementDecor ** montagne;

   Maison * M;
   Escargot * E;
   Arbre * A;
   Pierre * P;
   //-----------------------------------------------------------------------
   Monstre * ptr_ennemi;
   Hero hero;
   Lambda lambda;
   Serpent * serpent;
   Renard * renard;
   Fee * fee;

   int rand_decor = 0;                  //taille du tableau de décor
   int rand_ennemie = 0;                 //limite du tableau à afficher pour la gestion du scrolling
   string player_name;
   bool reussite = 0;
   int game = 1;


   village = new ElementDecor * [taille_ville];
   foret = new ElementDecor * [taille_quete];
   montagne = new ElementDecor * [taille_quete];

   srand(time(NULL));


    for(int i = 0; i < taille_ville; i++){

       if (i%2==0){
            A = new Arbre;
            village[i] = A;
       }
       else{
            M = new Maison;
            village[i] = M;
       }
    }

    for(int i = 0; i < taille_quete; i++)
    {
        rand_decor = rand() % 2;
        if(rand_decor == 0)
        {
            A = new Arbre;
            foret[i] = A;
        }
        else
        {
            E = new Escargot;
            foret[i] = E;
        }
    }


    cout << "Entrer le nom de votre personnage : ";
    cin >> player_name;
    hero.setnom(player_name);

    system("cls");
    do
    {
		system("cls");
        affiche_entete_promenade(hero);
        cout << "\n\n";
        //Affichage décor
        for (int i = 0; i < 5; i++) {
            for(int j = 0; j < limit_ville; j++){
                (*(village + j))->affiche(i);
            }
       cout<<endl;
       }
        cout << "\n\n";
        // Affichage personnage
       affiche_hero(hero);
       affiche_bordure();

       int c = 1;
       int cpt = 0;
       int car;
       do{
           car = getch();
           if (car == 'd')
           {
               if (c < taille_ville)
               {
                   system("cls");
                   affiche_entete_promenade(hero);
                   cout << "\n\n";
                   //Affichage décor
                   for (int i = 0; i < 5; i++) {
                       for (int j = c; j < limit_ville + c; j++) {
                           (*(village + j))->affiche(i);
                           cpt = j;
                       }
                       cout << endl;
                   }
                    cout << "\n\n";
                    //Affichage personnage
                   affiche_hero(hero);
                   affiche_bordure();
                   if(c == 13){
                        system("cls");
                        affiche_entete_promenade(hero);
                        cout << "\n";
                        //Affichage décor
                       for (int i = 0; i < 5; i++) {
                           for (int j = c; j < limit_ville + c; j++) {
                               (*(village + j))->affiche(i);
                               cpt = j;
                           }
                           cout << endl;
                       }
                        affiche_personnage_combat(hero, lambda);
                        cout << lambda.getnom() << ": " << lambda.getmessage() << endl;
                        system("pause");
                   }
                   c++;
               }
           }

        }while(cpt!=0 && cpt!=taille_ville - 1);

            system("cls");
            system("pause");
            system("cls");

            affiche_entete_promenade(hero);
            cout << "\n\n";
            //Affichage décor
            for (int i = 0; i < 5; i++) {
                for(int j = 0; j < limit_foret; j++){
                    (*(foret + j))->affiche(i);
                }
           cout<<endl;
           }
           cout << "\n\n";
           affiche_hero(hero);
           affiche_bordure();

           c = 1;
           cpt = 0;
           do
           {
               car = getch();
               if (car == 'd')
               {
                   if (c < taille_quete)
                   {
                       system("cls");
                       affiche_entete_promenade(hero);
                       cout << "\n\n";
                       //Affichage décor
                       for (int i = 0; i < 5; i++) {
                           for (int j = c; j < limit_foret + c; j++) {
                               (*(foret + j))->affiche(i);
                               cpt = j;
                           }
                           cout << endl;
                       }
                        cout << "\n\n";
                        affiche_hero(hero);
                        affiche_bordure();

                       rand_ennemie = rand()% 101;
                       if(rand_ennemie > 95)
                       {
                           system("cls");
                           Sleep(2000);
                           rand_ennemie = rand() % 3;
                           if (rand_ennemie == 0){
                            serpent = new Serpent;
                            ptr_ennemi = serpent;
                           }
                           else if (rand_ennemie == 1){
                            renard = new Renard;
                            ptr_ennemi = renard;
                           }
                           else{
                            fee = new Fee;
                            ptr_ennemi = fee;
                           }

                            afficher_entete_combat(hero, *ptr_ennemi);
                            cout << "\n\n";
                            affiche_personnage_combat(hero, *ptr_ennemi);
                            reussite = 0;
                            do
                            {
                                car = getch();
                                if(car == 't')
                                {
                                    system("cls");
                                    afficher_entete_combat(hero, *ptr_ennemi);
                                    if(hero.getPV() != 0)
                                    {
                                        hero.donner_coup(*ptr_ennemi);
                                        cout << "\n";
										affiche_personnage_combat(hero, *ptr_ennemi);
                                        cout << hero.getmessage();
                                        ptr_ennemi ->prendre_coup();
                                        Sleep(1300);
                                        system("cls");
                                        afficher_entete_combat(hero, *ptr_ennemi);

                                        cout << "\n";
                                        affiche_personnage_combat(hero, *ptr_ennemi);
                                        cout<<"\t\t\t\t\t\t\t";
                                        cout << ptr_ennemi->getmessage();
                                     }

                                     if (ptr_ennemi->getPV()!=0)
                                    {
                                        ptr_ennemi->autocombat(hero, reussite);
                                        Sleep(1300);
                                        system("cls");
                                        afficher_entete_combat(hero, *ptr_ennemi);
                                        cout << "\n";
                                        affiche_personnage_combat(hero, *ptr_ennemi);
                                        cout<<"\t\t\t\t\t\t\t";
                                        cout << ptr_ennemi->getmessage();
                                        hero.prendre_coup();
                                        Sleep(1300);
                                        system("cls");
                                        afficher_entete_combat(hero, *ptr_ennemi);
                                        cout << "\n";
										affiche_personnage_combat(hero, *ptr_ennemi);
                                        cout << hero.getmessage();
                                    }
                                  }

                                if(car == 's')
                                {
                                    hero.soin();
                                    Sleep(1300);
                                    system("cls");
                                    afficher_entete_combat(hero, *ptr_ennemi);
                                    cout << "\n";
                                    affiche_personnage_combat(hero, *ptr_ennemi);

                                    if (ptr_ennemi->getPV()!=0)
                                    {
                                        ptr_ennemi->autocombat(hero, reussite);
                                        Sleep(1300);
                                        system("cls");
                                        afficher_entete_combat(hero, *ptr_ennemi);
                                        cout << "\n";
                                        affiche_personnage_combat(hero, *ptr_ennemi);
                                        cout<<"\t\t\t\t\t\t";
                                        cout << ptr_ennemi->getmessage();

                                        hero.prendre_coup();
                                        Sleep(1300);
                                        system("cls");
                                        afficher_entete_combat(hero, *ptr_ennemi);
                                        cout << "\n";
                                        affiche_hero(hero);
                                        cout << hero.getmessage();
                                        affiche_personnage(*ptr_ennemi);
                                    }
                                }

                                if(car == 'f')
                                {
                                    reussite = hero.fuite(*ptr_ennemi);
                                    if(reussite != 1)
                                    {
                                        cout << hero.getnom() <<": impossible de fuir ...";
                                        if (ptr_ennemi->getPV()!=0)
                                        {
                                            ptr_ennemi->autocombat(hero, reussite);
                                            Sleep(1300);
                                            system("cls");
                                            afficher_entete_combat(hero, *ptr_ennemi);
                                            cout << "\n";
                                            affiche_personnage_combat(hero, *ptr_ennemi);
                                            cout<<"\t\t\t\t\t\t";
                                            cout << ptr_ennemi->getmessage();

                                            hero.prendre_coup();
                                            Sleep(1300);
                                            system("cls");
                                            afficher_entete_combat(hero, *ptr_ennemi);
                                            cout << "\n";
                                            affiche_hero(hero);
                                            cout << hero.getmessage();
                                            affiche_personnage(*ptr_ennemi);
                                        }
                                    }
                                }

                                Sleep(1300);
                                system("cls");
                                afficher_entete_combat(hero, *ptr_ennemi);
                                cout << "\n";
                                affiche_personnage_combat(hero, *ptr_ennemi);
                            }while(hero.getPV()!= 0 && ptr_ennemi->getPV() != 0 && reussite == 0);

							ptr_ennemi = NULL;

                            system("cls");
                            Sleep(2000);
                            affiche_entete_promenade(hero);
                            cout << "\n\n";
                            //Affichage decor
                            for (int i = 0; i < 5; i++) {
                               for (int j = c; j < limit_foret + c; j++) {
                                   (*(foret + j))->affiche(i);
                                   cpt = j;
                               }
                               cout << endl;
                           }
                           cout << "\n\n";
                           affiche_hero(hero);
                           affiche_bordure();
                        }
                        c++;
                    }
                }
				cout << c;
				cout << cpt;
            } while (cpt != 0 && cpt != taille_quete - 1 && hero.getPV() != 0);

			
				ptr_ennemi = new centaurus;
				system("cls");
				afficher_entete_combat(hero, *ptr_ennemi);
				cout << "\n\n";
				final_stage_decor();
				affiche_personnage_combat(hero, *ptr_ennemi);
				do {
					car = getch();
					if (car == 't')
					{
						system("cls");
						afficher_entete_combat(hero, *ptr_ennemi);
						if (hero.getPV() != 0)
						{
							hero.donner_coup(*ptr_ennemi);
							cout << "\n";
							affiche_personnage_combat(hero, *ptr_ennemi);
							cout << hero.getmessage();
							ptr_ennemi->prendre_coup();
							Sleep(1300);
							system("cls");
							afficher_entete_combat(hero, *ptr_ennemi);

							cout << "\n";
							affiche_personnage_combat(hero, *ptr_ennemi);
							cout << "\t\t\t\t\t\t\t";
							cout << ptr_ennemi->getmessage();
						}

						if (ptr_ennemi->getPV() != 0)
						{
							ptr_ennemi->autocombat(hero, reussite);
							Sleep(1300);
							system("cls");
							afficher_entete_combat(hero, *ptr_ennemi);
							cout << "\n";
							affiche_personnage_combat(hero, *ptr_ennemi);
							cout << "\t\t\t\t\t\t\t";
							cout << ptr_ennemi->getmessage();
							hero.prendre_coup();
							Sleep(1300);
							system("cls");
							afficher_entete_combat(hero, *ptr_ennemi);
							cout << "\n";
							affiche_personnage_combat(hero, *ptr_ennemi);
							cout << hero.getmessage();
						}
					}

					if (car == 's')
					{
						hero.soin();
						Sleep(1300);
						system("cls");
						afficher_entete_combat(hero, *ptr_ennemi);
						cout << "\n";
						affiche_personnage_combat(hero, *ptr_ennemi);

						if (ptr_ennemi->getPV() != 0)
						{
							ptr_ennemi->autocombat(hero, reussite);
							Sleep(1300);
							system("cls");
							afficher_entete_combat(hero, *ptr_ennemi);
							cout << "\n";
							affiche_personnage_combat(hero, *ptr_ennemi);
							cout << "\t\t\t\t\t\t";
							cout << ptr_ennemi->getmessage();

							hero.prendre_coup();
							Sleep(1300);
							system("cls");
							afficher_entete_combat(hero, *ptr_ennemi);
							cout << "\n";
							affiche_hero(hero);
							cout << hero.getmessage();
							affiche_personnage(*ptr_ennemi);
						}
					}

				} while (hero.getPV() != 0 && ptr_ennemi->getPV() != 0);


       if(hero.getPV() != 0)
          {cout << "Stage complete!!!!";}
       else
          { cout << "Game over !!!";
            game = 0;
          }
    }while(game == 1);
    return 0;
}
