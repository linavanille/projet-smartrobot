/**
 * @file lcd.h
 * @author Michel
 * @brief en-tête du fichier de contrôle du module d'affichage LCD du Smart Robot.
 * @details LCD en format 16x02 caractères.
 */

 #ifndef __LCD__
 #define __LCD__

/**
 * @brief La fonction d'initialisation avec le module LCD. Ne fonctionne qu'après un wiringPiSetup externe.
 * @return EXIT_SUCCESS Si le travail s'est bien passé, et EXIT_FAILURE sinon.
 */
int LCD_Init(void);

/**
 * @brief Fonction d'ecriture sur l'ecran LCD
 * @param arcline1 Chaine de Caractère à écrire sur la première ligne
 * @param arcline2 Chaine de caractère à écrire sur la deuxième ligne
 * @return EXIT_SUCCESS Si le travail s'est bien passé, et EXIT_FAILURE sinon.
 */
void LCD_Write(char arcLine1[17], char arcLine2[17]);

/**
 * @brief Efface le LCD
 *
 */
void LCD_clear();

#endif
