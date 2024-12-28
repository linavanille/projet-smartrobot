#include "../include/case.h"
#include <stdlib.h>

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

int *CASE_obtenirCasesAccessibles(CASE_Case c)
{
    int *res = (int *)malloc(5 * sizeof(int));
    int ca;
    res[0]=0;
    ca = CASE_obtenirBas(c);
    if (ca != 0)
    {
        res[0]++;
        res[res[0]] = ca; 
    }
    ca = CASE_obtenirHaut(c);
    if (ca != 0)
    {
        res[0]++;
        res[res[0]] = ca; 
    }
    ca = CASE_obtenirGauche(c);
    if (ca != 0)
    {
        res[0]++;
        res[res[0]] = ca; 
    }
    ca = CASE_obtenirDroite(c);
    if (ca != 0)
    {
        res[0]++;
        res[res[0]] = ca; 
    }
    return res;
}