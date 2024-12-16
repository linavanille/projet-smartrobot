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
void ensemble(Ensemble* ensembleDeCases);


/**
*@brief Vérifie si une case est présente dans l'Ensemble
*@return booléen
*/
int estPresent(Ensemble *ensembleDeCases, int uneCase);


/**
*@brief Ajouter une case dans l'Ensemble 
*/
void ajouter(Ensemble *ensembleDeCases, int uneCase);

/** 
*@brief libére tous les noeuds de la liste
*/
void libererEnsemble(Ensemble* ensembleDeCases);



#endif