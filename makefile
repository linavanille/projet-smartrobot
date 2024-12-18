SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR = test
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g
LDFLAGS=-lcunit -lm -lc
EXEC=$(BINDIR)/[______]
TESTS = $(TESTDIR)/[_____]TU

all :  $(EXEC) $(TESTS)

$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/[______].o $(SRCDIR)/[______].o (bibliotheque utilisee)
	$(CC)  -o $@ $^ $(LDFLAGS) 

$(LIBDIR)/[_____].a : $(SRCDIR)/[______].o 
	$(AR) -R $@ $^

$(TESTS) : $(SRCDIR)/[______]TU.o $(SRCDIR)/[______].o (bibliotheque utilisee)
	$(CC)  -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)  

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(TESTDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
