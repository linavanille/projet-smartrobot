#include <stdio.h>
#include <stdlib.h>
#include "ordresRobot.h"
#include "case.h"
#include "labyrinthe.h"

//-------------------------------------------------
// Fonctions utilitaires
//-------------------------------------------------
ORD_Position* CASE_obtenirParNumero(int numero, LAB_Labyrinthe* labyrinthe) {
	if (numero < 0 || numero >= labyrinthe->largeur * labyrinthe->largeur) {
		return NULL;
    }
    return &labyrinthe->lesConnections[numero];
}

//-------------------------------------------------
// Fonctions de motricité (avancer, gauche, droite)
//-------------------------------------------------
ORD_Position* ORD_avancer(ORD_Position* position, Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
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

        ORD_Position* voisinTrouvé = CASE_obtenirParNumero(voisinNumero, labyrinthe);

        if (voisinTrouvé == NULL || !estAccessible(position, voisinTrouvé)) {
            return position; 
        }

        if (ORD_estIntersection(voisinTrouvé, labyrinthe)) {
            return voisinTrouvé;
        }

        if (ORD_estVirage(voisinTrouvé, orientation, labyrinthe, largeurLabyrinthe)) {
            return voisinTrouvé;
        }

        position = voisinTrouvé;
    }
}

ORD_Position* ORD_tournerGauche(ORD_Position* position, Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
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

ORD_Position* ORD_tournerDroite(ORD_Position* position, Orientation* orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
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

bool estAccessible(CASE_Case* positionActuelle, CASE_Case* positionSuivante) {
    if (positionSuivante == NULL) {
        return false;
    }
    return true;
}


//----------------------------
// Fonctions d'initialisation 
//----------------------------
ORD_Position* ORD_initialisation(LAB_Labyrinthe* labyrinthe, Orientation* orientation) {
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

//-------------------------------------------------------
// Fonctions de décision (quelle action à effectuer)
//-------------------------------------------------------
Orientation ORD_calculerOrientation(ORD_Position* caseActuelle, ORD_Position* caseSuivante, unsigned int largeurLabyrinthe) {
    unsigned int numActuelle = CASE_obtenirNumeroCase(*caseActuelle);
    unsigned int numSuivante = CASE_obtenirNumeroCase(*caseSuivante);

    if (numSuivante == numActuelle - largeurLabyrinthe) return Nord;
    if (numSuivante == numActuelle + largeurLabyrinthe) return Sud;
    if (numSuivante == numActuelle + 1) return Est;
    if (numSuivante == numActuelle - 1) return Ouest;

    return Invalide;
}

Ordre ORD_tournerVers(Orientation orientationActuelle, Orientation orientationCible) {
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

bool ORD_estVirage(ORD_Position* position, Orientation orientation, LAB_Labyrinthe* labyrinthe, unsigned int largeurLabyrinthe) {
    ORD_Position* voisin1 = NULL;
    ORD_Position* voisin2 = NULL;

    if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe))) {
        if (voisin1 == NULL) voisin1 = CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe);
        else voisin2 = CASE_obtenirParNumero(CASE_obtenirHaut(*position), labyrinthe);
    }
    if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe))) {
        if (voisin1 == NULL) voisin1 = CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe);
        else voisin2 = CASE_obtenirParNumero(CASE_obtenirBas(*position), labyrinthe);
    }
    if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe))) {
        if (voisin1 == NULL) voisin1 = CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe);
        else voisin2 = CASE_obtenirParNumero(CASE_obtenirGauche(*position), labyrinthe);
    }
    if (estAccessible(position, CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe))) {
        if (voisin1 == NULL) voisin1 = CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe);
        else voisin2 = CASE_obtenirParNumero(CASE_obtenirDroite(*position), labyrinthe);
    }

    if (voisin1 == NULL || voisin2 == NULL) return false;

    if ((CASE_obtenirNumeroCase(*voisin1) == CASE_obtenirNumeroCase(*position) - largeurLabyrinthe &&
         CASE_obtenirNumeroCase(*voisin2) == CASE_obtenirNumeroCase(*position) + largeurLabyrinthe) ||
        (CASE_obtenirNumeroCase(*voisin1) == CASE_obtenirNumeroCase(*position) - 1 &&
         CASE_obtenirNumeroCase(*voisin2) == CASE_obtenirNumeroCase(*position) + 1)) {
        return false; 
    }

    return true; 
}

//--------------------
// Fonction principale
//--------------------
Ordre* ORD_obtenirOrdres(ORD_Position** chemin, unsigned int tailleChemin, LAB_Labyrinthe* labyrinthe) {
    Ordre* ordres = malloc(tailleChemin * sizeof(Ordre));
    unsigned int largeurLabyrinthe = labyrinthe->largeur;

    Orientation orientationActuelle = ORD_calculerOrientation(chemin[0], chemin[1], largeurLabyrinthe);

    for (unsigned int i = 1; i < tailleChemin; i++) {
        Orientation orientationSuivante = ORD_calculerOrientation(chemin[i - 1], chemin[i], largeurLabyrinthe);

        if (orientationActuelle != orientationSuivante) {
            ordres[i - 1] = ORD_tournerVers(orientationActuelle, orientationSuivante);
        } else {
            ordres[i - 1] = AV;
        }

        orientationActuelle = orientationSuivante;
    }

    return ordres;
}

