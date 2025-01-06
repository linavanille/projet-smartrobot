#ifndef __CASE__
#define __CASE__

typedef struct {
    int Numero;
    int Haut;
    int Gauche;
    int Bas;
    int Droite;
} CASE_Case;

/**
* @brief Crée une Case à partir d'un numero
* @return une CASE_case
* @param n Le numero de la case
*/
CASE_Case CASE_creerCase(int n);

/**
* @brief retourne le numero de la case
* @return un entier
* @param C la Case
*/
int CASE_obtenirNumeroCase(CASE_Case);

/**
* @brief retourne de la case du dessus (si elle existe)
* @return un entier
* @param C la case
*/
int CASE_obtenirHaut(CASE_Case);

/**
* @brief retourne de la case du bas (si elle existe et est accessible)
* @return un entier
* @param C la case
*/
int CASE_obtenirBas(CASE_Case);

/**
* @brief retourne de la case de gauche (si elle existe et est accessible)
* @return un entier
* @param C la case
*/
int CASE_obtenirGauche(CASE_Case);

/**
* @brief retourne de la case de droite (si elle existe et est accessible)
* @return un entier
* @param C la case
*/
int CASE_obtenirDroite(CASE_Case);

/**
* @brief fixe la case voisine du haut (si elle existe et accessible)
* @return un entier
* @param C la case
*/
void CASE_fixerHaut(CASE_Case*, int);

/**
* @brief fixe la case voisine du bas (si elle existe et accessible)
* @return un entier
* @param C la case
*/
void CASE_fixerBas(CASE_Case*, int);

/**
* @brief fixe la case voisine de gauche (si elle existe et accessible)
* @return un entier
* @param C la case
*/
void CASE_fixerGauche(CASE_Case*, int);

/**
* @brief fixe la case voisine de droite (si elle existe et accessible)
* @return un entier
* @param C la case
*/
void CASE_fixerDroite(CASE_Case*, int);

/**
* @brief Donne l'ensemble des cases accessibles depuis la case référencée
* @return une liste d'entier
* @param C la case
*/
int *CASE_obtenirCasesAccessibles(CASE_Case);

#endif