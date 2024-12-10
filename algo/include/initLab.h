/**
 * @file initLab.h
 * @brief initialisation du Labyrinthe (contexte du projet)
 */

#ifndef __INIT_LABYRINTHE__
#define __INT_LABYRINTHE__

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "labyrinthe.h"
#include "case.h"

/**
* @brief Initialise le labyrinthe avec les données du fichier
* @return un labyrinthe modifie
* @param fnom Nom du fichier utilisé
* @param labyrinthe Labyrinthe à "remplir"
* 
*/
void initialisationLabyrinthe(char* fnom, LAB_Labyrinthe* labyrinthe);

#endif