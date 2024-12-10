#ifndef __CASE__
#define __CASE__

typedef struct {
    int Numero;
    int Haut;
    int Gauche;
    int Bas;
    int Droite;
} CASE_Case;

int CASE_obtenirNumeroCase(CASE_Case);
int CASE_obtenirHaut(CASE_Case);
int CASE_obtenirBas(CASE_Case);
int CASE_obtenirGauche(CASE_Case);
int CASE_obtenirDroite(CASE_Case);
int *CASE_obtenirCasesAccessibles(CASE_Case);

#endif