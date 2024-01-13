#pragma once

#include <iostream>
#include "Personnage.h"
#include "ElementDecor.h"

using namespace std;

void affiche_entete_promenade(const Personnage &hero);
void afficher_entete_combat(const Personnage &hero, const Personnage &ennemi);
void affiche_bordure();
void affiche_hero(Personnage &hero);
void affiche_personnage_combat(Personnage &hero, Personnage &ennemi);
void affiche_personnage(Personnage &ennemi);
void final_stage_decor();
