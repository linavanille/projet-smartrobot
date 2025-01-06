# Répertoire racine du projet
ROOTDIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

# Répertoires utiles
BINDIR := $(ROOTDIR)/bin
DOCDIR := $(ROOTDIR)/doc
INCDIR := $(ROOTDIR)/include
LIBDIR := $(ROOTDIR)/lib
OBJDIR := $(ROOTDIR)/obj
SRCDIR := $(ROOTDIR)/src
TSTDIR := $(ROOTDIR)/src/tests
BINTSTDIR := $(ROOTDIR)/tests

# Fichiers utiles
TARGET := $(BINDIR)/algo
GENDOCFILE := $(DOCDIR)/generate
OUTDOCDIR := $(DOCDIR)/output

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
TESTS := $(wildcard $(TSTDIR)/*.c)
BINTST := $(patsubst $(TSTDIR)/%.c,$(BINTSTDIR)/%,$(TESTS))

# Commandes utiles
CC := gcc
CFLAGS := -Wall -pedantic
IFLAGS := -I$(INCDIR)
LIBFLAGS := 

all: $(TARGET)

tests: $(BINTST)

gendoc:
	cd $(ROOTDIR)
	doxygen $(GENDOCFILE)

$(BINTST): $(OBJ) | $(BINTSTDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS) $(IFLAGS)

$(TARGET): $(OBJ) | $(BINDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS) $(IFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BINDIR) $(OBJDIR) $(BINTSTDIR):
	cd $(ROOTDIR)
	mkdir -p $@