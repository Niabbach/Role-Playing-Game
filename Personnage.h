

#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class Personnage {

protected:
    int PV;
    int PVmax;
    int Force;
    int VIT;
    int nb_potion;
	string message;
	string nom;

public:

	Personnage();
	virtual int getPV() const;
	virtual void setPV(int nPV);
	virtual int getPVmax() const;
	virtual int getFoerce() const;
	virtual int getVIT() const;
	virtual int get_nb_potion() const;
	virtual string getmessage() const;
	virtual void setmessage(string nmessage);
	virtual string getnom() const;
	virtual void setnom(string nnom);
    virtual void affiche(int num_ligne) = 0;
    virtual void donner_coup(Personnage &ennemi);
    virtual void prendre_coup();
    virtual void win(Personnage &ennemi);
    virtual bool fuite(const Personnage &ennemi);
    virtual void soin();
};

class Hero : public Personnage {

public:
    Hero();
	virtual void affiche(int num_ligne);
};

class Lambda : public Personnage {

public:
    Lambda();
	virtual void affiche(int num_ligne);
};

class Monstre : public Personnage {
public:
    virtual void autocombat(Personnage &ennemi, bool &reussite) = 0;
};



class Serpent : public Monstre {

public:
    Serpent();
	virtual void affiche(int num_ligne);
	virtual void autocombat(Personnage &ennemi, bool &reussite);
};

class Renard : public Monstre {

public:
    Renard();
	virtual void affiche(int num_ligne);
	virtual void autocombat(Personnage &ennemi, bool &reussite);
};

class Fee : public Monstre {

public:
   Fee();
   virtual void affiche(int num_ligne);
   virtual void autocombat(Personnage &ennemi, bool &reussite);
};

class centaurus : public Monstre {

public:
	centaurus();
	virtual void affiche(int num_ligne);
	virtual void autocombat(Personnage &ennemi, bool &reussite);

};

#endif // PERSONNAGE_H_INCLUDED
