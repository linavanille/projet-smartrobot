#include "case.h"

int CASE_obtenirNumeroCase(CASE_Case c)
{
    return c.Numero;
}

int CASE_obtenirHaut(CASE_Case c)
{
    return c.Haut;
}

int CASE_obtenirBas(CASE_Case c)
{
    return c.Bas;
}

int CASE_obtenirGauche(CASE_Case c)
{
    return c.Gauche;
}

int CASE_obtenirDroite(CASE_Case c)
{
    return c.Droite;
}

void CASE_fixerHaut(CASE_Case* c, int num)
{
    c->Haut = num;
}

void CASE_fixerBas(CASE_Case* c, int num)
{
    c->Bas = num;
}

void CASE_fixerGauche(CASE_Case* c, int num)
{
    c->Gauche = num;
}

void CASE_fixerDroite(CASE_Case* c, int num)
{
    c->Droite = num;
}
