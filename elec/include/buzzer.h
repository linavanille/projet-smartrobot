/**
 * @file buzzer.h
 * @author Nathan Levasseur
 * @brief Signatures des fonctions utiles pour le buzzer
 */

#ifndef __BUZZER__
#define __BUZZER__

/**
* \fn void BUZZ_setup()
* \brief Définir la pin du buzzer
*/
void BUZZ_setup();

/**
* \fn void BUZZ_loop()
* \brief Allumer le buzzer 3s 
*/
void BUZZ_loop();

/**
* \fn void BUZZ_ON()
* \brief Allumer le buzzer 
*/
void BUZZ_ON();

/**
* \fn void BUZZ_OFF()
* \brief Eteindre le buzzer 
*/
void BUZZ_OFF();

#endif