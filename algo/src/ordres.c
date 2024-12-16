#include <stdio.h>
#include <stdlib.h>
#include "ordresRobot.h"
#include "case.h"
#include "labyrinthe.h"

ORD_Position* CASE_obtenirParNumero(int numero, LAB_Labyrinthe* labyrinthe) {
	if (numero < 0 || numero >= (int)(labyrinthe->largeur * labyrinthe->largeur)) {
		return NULL;
	}
	return &labyrinthe->lesConnections[numero];
}

bool estAccessible(ORD_Position* positionActuelle, ORD_Position* positionVoisine) {
	return positionVoisine != NULL;
}

ORD_Position* ORD_avancer(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
	while (1) {
		int voisinNumero = -1;

		if (orientation == Nord) {
			voisinNumero = CASE_obtenirHaut(*position);
		} else if (orientation == Sud) {
			voisinNumero = CASE_obtenirBas(*position);
		} else if (orientation == Est) {
			voisinNumero = CASE_obtenirDroite(*position);
		} else if (orientation == Ouest) {
			voisinNumero = CASE_obtenirGauche(*position);
		}

		ORD_Position* voisinTrouve = CASE_obtenirParNumero(voisinNumero, labyrinthe);

		if (voisinTrouve == NULL || !estAccessible(position, voisinTrouve) ||
			ORD_estIntersection(voisinTrouve, labyrinthe) ||
			ORD_estVirage(voisinTrouve, orientation, labyrinthe, largeurLabyrinthe)) {
			return voisinTrouve;
		}

		position = voisinTrouve;
	}
}

ORD_Position* ORD_tournerGauche(ORD_Position* position, ORD_Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
	if (*orientation == Nord) {
		*orientation = Ouest;
	} else if (*orientation == Ouest) {
		*orientation = Sud;
	} else if (*orientation == Sud) {
		*orientation = Est;
	} else if (*orientation == Est) {
		*orientation = Nord;
	}

	return ORD_avancer(position, *orientation, labyrinthe, largeurLabyrinthe);
}

ORD_Position* ORD_tournerDroite(ORD_Position* position, ORD_Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
	if (*orientation == Nord) {
		*orientation = Est;
	} else if (*orientation == Est) {
		*orientation = Sud;
	} else if (*orientation == Sud) {
		*orientation = Ouest;
	} else if (*orientation == Ouest) {
		*orientation = Nord;
	}

	return ORD_avancer(position, *orientation, labyrinthe, largeurLabyrinthe);
}

ORD_Position* ORD_initialisation(LAB_Labyrinthe* labyrinthe, ORD_Orientation* orientation) {
	ORD_Position* entree = CASE_obtenirParNumero(labyrinthe->entree, labyrinthe);

	if (entree == NULL) {
		perror("Erreur : entrée invalide dans le labyrinthe.");
		exit(EXIT_FAILURE);
	}

	if (estAccessible(entree, CASE_obtenirParNumero(CASE_obtenirHaut(*entree), labyrinthe))) {
		*orientation = Nord;
	} else if (estAccessible(entree, CASE_obtenirParNumero(CASE_obtenirBas(*entree), labyrinthe))) {
		*orientation = Sud;
	} else if (estAccessible(entree, CASE_obtenirParNumero(CASE_obtenirGauche(*entree), labyrinthe))) {
		*orientation = Ouest;
	} else if (estAccessible(entree, CASE_obtenirParNumero(CASE_obtenirDroite(*entree), labyrinthe))) {
		*orientation = Est;
	} else {
		perror("Erreur : aucune direction accessible depuis la case d'entrée.");
		exit(EXIT_FAILURE);
	}

	return entree;
}

ORD_Orientation ORD_calculerOrientation(ORD_Position* caseActuelle, ORD_Position* caseSuivante, unsigned int largeurLabyrinthe) {
	unsigned int numActuelle = CASE_obtenirNumeroCase(*caseActuelle);
	unsigned int numSuivante = CASE_obtenirNumeroCase(*caseSuivante);

	if (numSuivante == numActuelle - largeurLabyrinthe) return Nord;
	if (numSuivante == numActuelle + largeurLabyrinthe) return Sud;
	if (numSuivante == numActuelle + 1) return Est;
	if (numSuivante == numActuelle - 1) return Ouest;

	return Invalide;
}

ORD_Ordre ORD_tournerVers(ORD_Orientation orientationActuelle, ORD_Orientation orientationCible) {
	if (orientationActuelle == orientationCible) {
		return AV;
	}

	if ((orientationActuelle == Nord && orientationCible == Ouest) ||
		(orientationActuelle == Ouest && orientationCible == Sud) ||
		(orientationActuelle == Sud && orientationCible == Est) ||
		(orientationActuelle == Est && orientationCible == Nord)) {
		return TG;
	}

	return TD;
}

bool ORD_estIntersection(ORD_Position* position, LAB_Labyrinthe* labyrinthe) {
	int voisinsAccessibles = 0;

	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe))) voisinsAccessibles++;
	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe))) voisinsAccessibles++;
	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe))) voisinsAccessibles++;
	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe))) voisinsAccessibles++;

	return voisinsAccessibles > 2;
}

bool ORD_estVirage(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
	ORD_Position* voisin1 = NULL;
	ORD_Position* voisin2 = NULL;

	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe))) {
		voisin1 = voisin1 == NULL ? CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe) : voisin2;
	}
	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe))) {
		voisin1 = voisin1 == NULL ? CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe) : voisin2;
	}
	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe))) {
		voisin1 = voisin1 == NULL ? CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe) : voisin2;
	}
	if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe))) {
		voisin1 = voisin1 == NULL ? CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe) : voisin2;
	}

	if (voisin1 == NULL || voisin2 == NULL) return false;

	return (orientation == Nord || orientation == Sud)
		? (CASE_obtenirNumeroCase(*voisin1) != CASE_obtenirNumeroCase(*voisin2))
		: true;
}

ORD_Ordre* ORD_obtenirOrdres(ORD_Position** chemin, unsigned int tailleChemin, LAB_Labyrinthe* labyrinthe) {
	ORD_Ordre* ordres = malloc((tailleChemin + 1) * sizeof(ORD_Ordre));
	unsigned int largeurLabyrinthe = labyrinthe->largeur;

	ORD_Orientation orientationActuelle = ORD_calculerOrientation(chemin[0], chemin[1], largeurLabyrinthe);

	unsigned int ordreIndex = 0;

	for (unsigned int i = 1; i < tailleChemin; i++) {
		ORD_Orientation orientationSuivante = ORD_calculerOrientation(chemin[i - 1], chemin[i], largeurLabyrinthe);

		if (orientationActuelle != orientationSuivante) {
			ordres[ordreIndex++] = ORD_tournerVers(orientationActuelle, orientationSuivante);
		} else {
			if (ordreIndex == 0 || ordres[ordreIndex - 1] != AV) {
				ordres[ordreIndex++] = AV;
			}
		}

		orientationActuelle = orientationSuivante;
	}

	ordres[ordreIndex] = FIN;

	return ordres;
}
