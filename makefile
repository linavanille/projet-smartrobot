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
TARGET := $(BINDIR)/algo
GENDOCFILE := $(DOCDIR)/generate
OUTDOCDIR := $(DOCDIR)/output

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# Commandes utiles
CC := gcc
CFLAGS := -Wall -pedantic
IFLAGS := -I$(INCDIR)
LIBFLAGS := 

all: $(TARGET)

gendoc:
	cd $(ROOTDIR)
	doxygen $(GENDOCFILE)

$(TARGET): $(OBJ) #| $(BINDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c #| $(OBJDIR)
	cd $(ROOTDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

# $(BINDIR) $(OBJDIR):
# 	cd $(ROOTDIR)
# 	mkdir -p $@