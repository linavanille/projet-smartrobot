#include <stdio.h>
#include "ensemble.h"


int main(){
    Ensemble* monEnsemble;
    ENS_ensemble(monEnsemble);
    ENS_ajouter(monEnsemble,12);
    ENS_ajouter(monEnsemble,13);
    ENS_ajouter(monEnsemble,17);
    ENS_afficherEnsemble(monEnsemble);
    ENS_libererEnsemble(monEnsemble);
    ENS_afficherEnsemble(monEnsemble);
    return 0;
}