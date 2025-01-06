# Répertoire racine du projet
ROOTDIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

# Répertoires utiles
ALGODIR := $(ROOTDIR)/algo
ELECDIR := $(ROOTDIR)/elec

# Commandes utiles
MAKE = make

doc-algo:
	cd $(ALGODIR) && $(MAKE) gendoc

tests-algo:
	cd $(ALGODIR) && $(MAKE) tests

lib-elec:
	cd $(ELECDIR) && $(MAKE) robot