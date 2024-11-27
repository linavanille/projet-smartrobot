/**
* @file interruption.h
*/

#ifndef __INTERRUPTION__
#define __INTERRUPTION__

/** 
* @brief Arrête le robot si la distance  par rapport à un obstacle est inférieure à 10  
* @param interruption la fonction qui permet d'interrompre le mouvement du robot
* @param activation la fontion qui remet le robot en marche 
*/
void STOP_loop(void (*interruption)(void), void (*activation)(void));

#endif