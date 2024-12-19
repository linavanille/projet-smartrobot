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

		// Détermine le voisin suivant basé sur l'orientation
		if (orientation == Nord) voisinNumero = CASE_obtenirHaut(*position);
		else if (orientation == Sud) voisinNumero = CASE_obtenirBas(*position);
		else if (orientation == Est) voisinNumero = CASE_obtenirDroite(*position);
		else if (orientation == Ouest) voisinNumero = CASE_obtenirGauche(*position);

		// Obtenir le voisin trouvé
		ORD_Position* voisinTrouve = CASE_obtenirParNumero(voisinNumero, labyrinthe);

		// Conditions d'arrêt : mur, intersection, ou virage
		if (voisinTrouve == NULL ||
		    ORD_estIntersection(voisinTrouve, labyrinthe) ||
		    ORD_estVirage(voisinTrouve, orientation, labyrinthe, largeurLabyrinthe)) {
			return voisinTrouve;
		}

		// Avance à la case suivante
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

    printf("Case %d a %d connexions accessibles.\n", CASE_obtenirNumeroCase(*position), voisinsAccessibles);

    return voisinsAccessibles > 2; // Intersection si plus de 2 connexions
}



bool ORD_estVirage(ORD_Position* position, ORD_Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
    ORD_Position* voisinHaut = CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe);
    ORD_Position* voisinBas = CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe);
    ORD_Position* voisinGauche = CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe);
    ORD_Position* voisinDroite = CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe);

    int directionsAccessibles = 0;
    if (voisinHaut) directionsAccessibles++;
    if (voisinBas) directionsAccessibles++;
    if (voisinGauche) directionsAccessibles++;
    if (voisinDroite) directionsAccessibles++;

    printf("Case %d a %d directions accessibles (Orientation actuelle : %d).\n", CASE_obtenirNumeroCase(*position), directionsAccessibles, orientation);

    if (directionsAccessibles == 2) {
        if ((orientation == Nord || orientation == Sud) && (voisinGauche || voisinDroite)) {
            return true; // Virage pour Nord/Sud connecté à Gauche/Droite
        }
        if ((orientation == Est || orientation == Ouest) && (voisinHaut || voisinBas)) {
            return true; // Virage pour Est/Ouest connecté à Haut/Bas
        }
    }

    return false;
}

ORD_Ordre* ORD_obtenirOrdres(ORD_Position** chemin, unsigned int tailleChemin, LAB_Labyrinthe* labyrinthe) {
    ORD_Ordre* ordres = malloc((2 * tailleChemin + 2) * sizeof(ORD_Ordre)); 
    unsigned int ordreIndex = 0;

    ORD_Orientation orientationActuelle = ORD_calculerOrientation(chemin[0], chemin[1], labyrinthe->largeur);

    if (ORD_estIntersection(chemin[0], labyrinthe) || 
        ORD_estVirage(chemin[0], orientationActuelle, labyrinthe, labyrinthe->largeur)) {
        ordres[ordreIndex++] = AV;
    }

    for (unsigned int i = 1; i < tailleChemin; i++) {
        ORD_Orientation orientationSuivante = ORD_calculerOrientation(chemin[i - 1], chemin[i], labyrinthe->largeur);

        if (orientationActuelle != orientationSuivante) {
            ordres[ordreIndex++] = ORD_tournerVers(orientationActuelle, orientationSuivante);
            ordres[ordreIndex++] = AV;
            orientationActuelle = orientationSuivante;
        } else {
            if (ORD_estIntersection(chemin[i], labyrinthe) || 
                ORD_estVirage(chemin[i], orientationActuelle, labyrinthe, labyrinthe->largeur)) {
                ordres[ordreIndex++] = AV;
            }
        }
    }

    if (ORD_estIntersection(chemin[tailleChemin - 1], labyrinthe) || 
        ORD_estVirage(chemin[tailleChemin - 1], orientationActuelle, labyrinthe, labyrinthe->largeur)) {
        ordres[ordreIndex++] = AV;
    }

    ordres[ordreIndex] = FIN;

    return ordres;
}
