/**
*@file Ensemble.h
*/

#ifndef ___Ensemble__H
#define ___Ensemble__H


typedef struct Node{
    int numeroCase;
    struct Node* suivant;
} Node;

typedef struct {
    Node* tete;
} Ensemble;





/**
*@brief Permet de créer un Ensemble vide
*/
void ENS_ensemble(Ensemble* ensembleDeCases);


/**
*@brief Vérifie si une case est présente dans l'Ensemble
*@return booléen
*/
int ENS_estPresent(Ensemble *ensembleDeCases, int uneCase);


/**
*@brief Ajouter une case dans l'Ensemble 
*/
void ENS_ajouter(Ensemble *ensembleDeCases, int uneCase);

/** 
*@brief libére tous les noeuds de la liste
*/
void ENS_libererEnsemble(Ensemble* ensembleDeCases);

/**
*@brief pour afficher l'ensemble de cases
*/
void ENS_afficher(Ensemble* ensembleDeCases);

#endif