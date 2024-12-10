/**
 * @file motors.h
 * @author Tom G.
 * @brief Signatures des procédures pour l'utilisation des moteurs
 */

#ifndef __MOTORS__
#define __MOTORS__


//================================================================
//Fonctions de motricité (avant, gauche, droite, arriere, stop)
//----------------------------------------------------------------

/**
 * @fn void MTR_avancer(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1)
 * @brief Faire avancer le ROBOT (ligne droite) grâce au L293D
 * @param A_1 numéro du GPIO du in1
 * @param A_2 numéro du GPIO du in2
 * @param A_3 numéro du GPIO du in3
 * @param A_4 numéro du GPIO du in4
 * @param pwm0 numéro du GPIO pour le PWM 0
 * @param pwm1 numéro du GPIO pour le PWM 1
 * @details Les PWM sont utilisés pour compenser une potentielle différence de vitesse de rotation entre les moteurs
 * Différence définie au préalable
 */

void MTR_avancer(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1);


/**
 * @fn void MTR_tournerDroite(int A_1, int A_2, int A_3, int A_4)
 * @brief Faire tourner le ROBOT à droite sur lui-même grâce au L293D
 * @param A_1 numéro du GPIO du in1
 * @param A_2 numéro du GPIO du in2
 * @param A_3 numéro du GPIO du in3
 * @param A_4 numéro du GPIO du in4
 * @details Inverse le sens de rotation du moteur droit
 */

void MTR_tournerDroite(int A_1, int A_2, int A_3, int A_4);



/**
 * @fn void MTR_tournerGauche(int A_1, int A_2, int A_3, int A_4)
 * @brief Faire tourner le ROBOT à gauche sur lui-même grâce au L293D
 * @param A_1 numéro du GPIO du in1
 * @param A_2 numéro du GPIO du in2
 * @param A_3 numéro du GPIO du in3
 * @param A_4 numéro du GPIO du in4
 * @details Inverse le sens de rotation du moteur gauche
 */

void MTR_tournerGauche(int A_1, int A_2, int A_3, int A_4);


/**
 * @fn void MTR_redresser(int pwmInterieur, int pwmExterieur)
 * @brief Faire devier le ROBOT de sa trajectoire
 * @param pwmInterieur numéro du GPIO pour le PWM du moteur à l'interieur de la trajectoire voulue
 * @param pwmExterieur numéro du GPIO pour le PWM du moteur à l'extérieur de la trajectoire voulue
 * @details Augmente légèrement le pmwInterieur et baisse le pwmExterieur
 */

void MTR_redresser(int pwmInterieur, int pwmExterieur);


/**
 * @fn void MTR_arreter(int A_1, int A_2, int A_3, int A_4)
 * @brief Arrêter le ROBOT grâce au L293D
 * @param A_1 numéro du GPIO du in1
 * @param A_2 numéro du GPIO du in2
 * @param A_3 numéro du GPIO du in3
 * @param A_4 numéro du GPIO du in4
 * 
 */

void MTR_arreter(int A_1, int A_2, int A_3, int A_4);

//====================================================




//====================================================
//Fonctions d'initialisation des GPIO
//----------------------------------------------------

/**
 * @fn void MTR_initialisationPWM(int pwm0, int pwm1)
 * @brief Initialiser les PWM de la RaspberryPi
 * @param pwm0 numéro du GPIO pour le PWM 0
 * @param pwm1 numéro du GPIO pour le PWM 1
 */

void MTR_initialisationPWM(int pwm0, int pwm1); 

/**
 * @fn void MTR_changerVitessePWM(int pwm0, int pwm1)
 * @brief Faire avancer le ROBOT (ligne droite) grâce au L293D
 * @param cycleD Pourcentage de "puissance" souhaité du PWM
 * @details Applique la valeur (frequence*cycleD)/100 au PWM 
 */

void MTR_changerVitessePWM(int pwm, int cycleD); 

/**
 * @fn void MTR_initialisationMoteur(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1)
 * @brief Initialiser tous les GPIO nécessaires aux moteurs
 * @param A_1 numéro du GPIO du in1
 * @param A_2 numéro du GPIO du in2
 * @param A_3 numéro du GPIO du in3
 * @param A_4 numéro du GPIO du in4
 * @param pwm0 numéro du GPIO pour le PWM 0
 * @param pwm1 numéro du GPIO pour le PWM 1
 * @details Les moteurs sont mis à l'arrêt et les PWM à une valeur par défaut de 50%
 */

void MTR_initialisationMoteur(int A_1, int A_2, int A_3, int A_4, int pwm0, int pwm1);

//====================================================

#endif