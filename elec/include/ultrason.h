/**
* @file ultrason.h
* @brief fichier header pour le capteur ultrason
*/
#ifndef __ULTRASON__
#define __ULTRASON__

/**
* @brief Pour initialiser les pins.
*/
void USON_init();

/**
* @brief Renvoie la distance mesurée par le capteur ultrason.
* @return float la distance mesurée.
*/
float USON_obtenirDistance();

#endif
