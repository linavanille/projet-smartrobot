/**
 * @file initialisationElec.h
 * @brief initialisation de la Raspberry Pi dans le contexte du projet
 */

#ifndef __INIT_ELEC__
#define __INIT_ELEC__

/**
 * @fn int initialisationGPIO();
 * @brief Initialise tous les pins des GPIO qui vont être utilisés.
 * @details Renvoie -1 en cas d'erreur et 1 dans le cas contraire.
 *
 */
int initialisationGPIO();

#endif