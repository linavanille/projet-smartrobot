# nom des ficchiers à générer
FILE = pseudocode

# liste des fichiers sources
SRCPDF = ./pseudocode.dtx
SRCSTY = ./pseudocode.ins

# commande de compilation
LATEXPDF = pdflatex
LATEX = latex

#règle pour générer le rapport
$(FILE):
	$(LATEX) $(SRCSTY)
	$(LATEXPDF) $(SRCPDF)
	$(LATEXPDF) $(SRCPDF)  
	rm -f ./pseudocode.log
	rm -f ./pseudocode.aux
	rm -f ./pseudocode.toc
	rm -f ./pseudocode.idx
	rm -f ./pseudocode.glo
	rm -f ./pseudocode.tmp
	rm -f ./pseudocode.out

# règle pour nettoyer les fichiers générés
clean:
	rm -f ./pseudocode.pdf
	rm -f ./pseudocode.sty
	rm -f ./pseudocode.log
	rm -f ./pseudocode.aux
	rm -f ./pseudocode.toc
	rm -f ./pseudocode.idx
	rm -f ./pseudocode.glo
	rm -f ./pseudocode.tmp
	rm -f ./pseudocode.out
