#include <stdio.h>
#include <stdlib.h>
#include "ordresRobot_test.h"
#include "labyrinthe_test.h"
#include "case_test.h"

LAB_Labyrinthe* creerLabyrintheExemple() {
	LAB_Labyrinthe* labyrinthe = malloc(sizeof(LAB_Labyrinthe));
	labyrinthe->largeur = 3;  
	labyrinthe->lesConnections = malloc(9 * sizeof(CASE_Case));

	for (int i = 0; i < 9; i++) {
		labyrinthe->lesConnections[i].Numero = i;
		labyrinthe->lesConnections[i].Haut = (i >= 3) ? i - 3 : -1;
		labyrinthe->lesConnections[i].Bas = (i < 6) ? i + 3 : -1;
		labyrinthe->lesConnections[i].Gauche = (i % 3 != 0) ? i - 1 : -1;
		labyrinthe->lesConnections[i].Droite = (i % 3 != 2) ? i + 1 : -1;
	}
	return labyrinthe;
}

void tester_ordresRobot() {
	LAB_Labyrinthe* labyrinthe = creerLabyrintheExemple();

	Position* chemin[4];
	chemin[0] = &labyrinthe->lesConnections[3];  
	chemin[1] = &labyrinthe->lesConnections[4];  
	chemin[2] = &labyrinthe->lesConnections[1];  
	chemin[3] = &labyrinthe->lesConnections[2];  

	unsigned int tailleChemin = 4;

	Ordre* ordres = ORD_obtenirOrdres(chemin, tailleChemin, labyrinthe);

	printf("Ordres générés :\n");
	for (unsigned int i = 0; i < tailleChemin - 1; i++) {
		switch (ordres[i]) {
			case AV:
				printf("AV\n");
				break;
			case TG:
				printf("TG\n");
				printf("AV\n");
				break;
			case TD:
				printf("TD\n");
				printf("AV\n");
				break;
			}
	}
	
	printf(".\n");
	
	free(ordres);
	free(labyrinthe->lesConnections);
	free(labyrinthe);
}

int main() {
	tester_ordresRobot();
	return 0;
}
