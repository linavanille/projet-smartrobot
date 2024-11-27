#ifndef
#define __ULTRASON__
/**
* @file ultrason.h
* @author Amsatou
* @brief fichier header pour le capteur ultrason
*/
/

/**
* @brief Pour initialiser les pins
*/

void USON_init();

/**
* @brief Renvoie la distance mesurée par le capteur ultrason
* @return float la distance mesurée
*/
 float USON_obtenirDistance();

#endif
