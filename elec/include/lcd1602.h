/**
 * @file lcd.h
 * @author Michel
 * @brief en-tête du fichier de contrôle du module d'affichage LCD du Smart Robot.
 * @details LCD en format 16x02 caractères.
 */


/**
 * @brief La fonction d'initialisation avec le module LCD. Ne fonctionne qu'après un wiringPiSetup externe.
 * @return EXIT_SUCCESS Si le travail s'est bien passé, et EXIT_FAILURE sinon.
 */
int LCD_Init(void);

void LCD_Write()