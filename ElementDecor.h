#ifndef ELEMENTDECOR_H_INCLUDED
#define ELEMENTDECOR_H_INCLUDED


#include <stdlib.h>
#include <iostream>


class ElementDecor {

public:

    virtual void affiche(int num_ligne)=0;

};

class Maison : public ElementDecor {

public:

    virtual void affiche(int num_ligne);

};

class Arbre : public ElementDecor {

public:

    virtual void affiche(int num_ligne);
};


class Escargot : public ElementDecor {

public:

    virtual void affiche(int num_ligne);

};

class Pierre : public ElementDecor {

public:

    virtual void affiche(int num_ligne);

};

#endif // ELEMENTDECOR_H_INCLUDED
