# Répertoire racine du projet
ROOTDIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

# Répertoires utiles
BINDIR := $(ROOTDIR)/bin
DOCDIR := $(ROOTDIR)/doc
INCDIR := $(ROOTDIR)/include
LIBDIR := $(ROOTDIR)/lib
OBJDIR := $(ROOTDIR)/obj
OBJRBTDIR := $(OBJDIR)/robot
SRCDIR := $(ROOTDIR)/src
RBTDIR := $(SRCDIR)/robot

# Fichiers utiles
SRC := $(wildcard $(SRCDIR)/*.c)
OBJSRC := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
RBT := $(wildcard $(RBTDIR)/*.c)
OBJRBT := $(patsubst $(RBTDIR)/%.c,$(OBJRBTDIR)/%.o,$(RBT))

# Commandes utiles
AR := ar
CC := gcc
CFLAGS := -Wall -pedantic
IFLAGS := -I$(INCDIR) -I$(INCDIR)/algo
LIBRBTFLAGS := -lwiringPi
LIBSRCFLAGS := -Llib -lrobot -lwiringPi

robot: $(LIBDIR)/librobot.a

$(LIBDIR)/librobot.a: $(OBJRBT)
	cd $(ROOTDIR)
	$(AR) -r $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< $(LIBSRCFLAGS)
	
$(OBJRBTDIR)/%.o: $(RBTDIR)/%.c | $(OBJRBTDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< $(LIBRBTFLAGS)

$(OBJRBTDIR): | $(OBJDIR)
	cd $(ROOTDIR)
	mkdir -p $@

$(BINDIR) $(OBJDIR):
	cd $(ROOTDIR)
	mkdir -p $@
