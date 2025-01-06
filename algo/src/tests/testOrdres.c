#include <stdio.h>
#include <stdlib.h>
#include "ordres.h"

LAB_Labyrinthe* creerLabyrintheExemple() {
	LAB_Labyrinthe* labyrinthe = malloc(sizeof(LAB_Labyrinthe));
	labyrinthe->largeur = 3;  
	labyrinthe->lesConnections = malloc(9 * sizeof(CASE_Case));

	for (int i = 0; i < 9; i++) {
		labyrinthe->lesConnections[i].Numero = i;
		labyrinthe->lesConnections[i].Haut = -1;
		labyrinthe->lesConnections[i].Bas = -1;
		labyrinthe->lesConnections[i].Gauche = -1;
		labyrinthe->lesConnections[i].Droite = -1;
	}

	labyrinthe->lesConnections[0].Droite = 1;

	labyrinthe->lesConnections[1].Gauche = 0; 
	labyrinthe->lesConnections[1].Bas = 4;   

	labyrinthe->lesConnections[2].Bas = 5;

	labyrinthe->lesConnections[3].Droite = 4;

	labyrinthe->lesConnections[4].Haut = 1;   
	labyrinthe->lesConnections[4].Gauche = 3; 
	labyrinthe->lesConnections[4].Bas = 7;   

	labyrinthe->lesConnections[5].Haut = 2;
	labyrinthe->lesConnections[5].Bas = 8;

	labyrinthe->lesConnections[6].Droite = 7;

	labyrinthe->lesConnections[7].Haut = 4;  
	labyrinthe->lesConnections[7].Gauche = 6; 
	labyrinthe->lesConnections[7].Droite = 8; 

	labyrinthe->lesConnections[8].Gauche = 7;
	labyrinthe->lesConnections[8].Haut = 5;


	labyrinthe->entree = 2;
	labyrinthe->sortie = 8;


	if (ORD_estVirage(&labyrinthe->lesConnections[1], Est, labyrinthe, labyrinthe->largeur)) {
		printf("Case 1 est un virage.\n");
	}

	if (ORD_estIntersection(&labyrinthe->lesConnections[4], labyrinthe)) {
		printf("Case 4 est une intersection.\n");
	}

	if (ORD_estIntersection(&labyrinthe->lesConnections[7], labyrinthe)) {
		printf("Case 7 est une intersection.\n");
	}

	if (ORD_estVirage(&labyrinthe->lesConnections[8], Nord, labyrinthe, labyrinthe->largeur)) {
		printf("Case 8 est un virage.\n");
	}

	return labyrinthe;
}

void tester_ordresRobot() {
	LAB_Labyrinthe* labyrinthe = creerLabyrintheExemple();

	ORD_Position* chemin[5];
	chemin[0] = &labyrinthe->lesConnections[2];  
	chemin[1] = &labyrinthe->lesConnections[5];  
	chemin[2] = &labyrinthe->lesConnections[8];  
	chemin[3] = &labyrinthe->lesConnections[7];
	chemin[4] = &labyrinthe->lesConnections[6];


	unsigned int tailleChemin = 5;

	ORD_Ordre* ordres = ORD_obtenirOrdres(chemin, tailleChemin, labyrinthe);

	printf("Ordres générés :\n");
	for (unsigned int i = 0; ordres[i] != FIN; i++) {
		switch (ordres[i]) {
			case AV:
				printf("AV\n");
				break;
			case TG:
				printf("TG\n");
				break;
			case TD:
				printf("TD\n");
				break;
			default:
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
