#ifndef __CASE__
#define __CASE__

typedef struct {
    int Numero;
    int Haut;
    int Gauche;
    int Bas;
    int Droite;
} CASE_Case;

CASE_Case CASE_creerCase(int);
int CASE_obtenirNumeroCase(CASE_Case);
int CASE_obtenirHaut(CASE_Case);
int CASE_obtenirBas(CASE_Case);
int CASE_obtenirGauche(CASE_Case);
int CASE_obtenirDroite(CASE_Case);
void CASE_fixerHaut(CASE_Case*, int);
void CASE_fixerBas(CASE_Case*, int);
void CASE_fixerGauche(CASE_Case*, int);
void CASE_fixerDroite(CASE_Case*, int);
int *CASE_obtenirCasesAccessibles(CASE_Case);

#endif