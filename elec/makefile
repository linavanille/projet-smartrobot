# Répertoire racine du projet
ROOTDIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

# Répertoires utiles
BINDIR := $(ROOTDIR)/bin
DOCDIR := $(ROOTDIR)/doc
INCDIR := $(ROOTDIR)/include
LIBDIR := $(ROOTDIR)/lib
OBJDIR := $(ROOTDIR)/obj
SRCDIR := $(ROOTDIR)/src

# Fichiers utiles
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
ROBFUNC := $(OBJDIR)/buzzer.o $(OBJDIR)/capteursLignes.o $(OBJDIR)/initElec.o $(OBJDIR)/lcd1602.o $(OBJDIR)/motorsPi.o $(OBJDIR)/ultrason.o

# Commandes utiles
AR := ar
CC := gcc
CFLAGS := -Wall -pedantic
IFLAGS := -I$(INCDIR)
LIBFLAGS := -lwiringPi -lwiringPiDev

robot: $(ROBFUNC)
	cd $(ROOTDIR)
	$(AR) -r $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< $(LIBFLAGS)

$(BINDIR) $(OBJDIR):
	cd $(ROOTDIR)
	mkdir -p $@
