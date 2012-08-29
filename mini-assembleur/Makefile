#!/bin/bash

#--------- variables à configurer ------------#
OBJDIR = build/
DBOBJDIR = build_debug/
SRCDIR = src/
BINDIR = bin/
EXAMPLEDIR = examples/
DISTRIB = AMIL_assembleur_miniature

SRCS = moteur.c main.c ig.c controleur.c
SRCSLC = moteur.c commandline.c
SRCSTR = moteur.c textrace.c ordre.c

 
CFLAGS = -Wall `pkg-config --cflags gtk+-2.0`

DBFLAGS = -g

#--------- autres variables ------------------#
LDFLAGS = `pkg-config --libs gtk+-2.0`

PLATFORM = $(shell uname -s)
ifeq ($(PLATFORM), Darwin)
# macos specific
endif

OBJS = $(SRCS:%.c=%.o)
SRCFILES = $(SRCS:%=$(SRCDIR)%)
OBJFILES = $(OBJS:%=$(OBJDIR)%)
DBOBJFILES = $(OBJS:%=$(DBOBJDIR)%)

OBJSLC = $(SRCSLC:%.c=%.o)
SRCFILESLC = $(SRCSLC:%=$(SRCDIR)%)
OBJFILESLC = $(OBJSLC:%=$(OBJDIR)%)
DBOBJFILESLC = $(OBJSLC:%=$(DBOBJDIR)%)

OBJSTR = $(SRCSTR:%.c=%.o)
SRCFILESTR = $(SRCSTR:%=$(SRCDIR)%)
OBJFILESTR = $(OBJSTR:%=$(OBJDIR)%)
DBOBJFILESTR = $(OBJSTR:%=$(DBOBJDIR)%)

#-------- cibles -----------------------------#
.PHONY: all amil clean run indent tgz

all : amil amilnox amiltrace

amil : $(OBJFILES)
	gcc $(CFLAGS) $(LDFLAGS) $(OBJFILES) -o $(BINDIR)amil 
	echo "******** L'executable est dans $(BINDIR) **********"

amilnox : $(OBJFILESLC)
	gcc $(CFLAGS) $(LDFLAGS) $(OBJFILESLC) -o $(BINDIR)amilnox
	echo "******** L'executable est dans $(BINDIR) **********"

amiltrace : $(OBJFILESTR)
	gcc $(CFLAGS) $(LDFLAGS) $(OBJFILESTR) -o $(BINDIR)amiltrace
	echo "******** L'executable est dans $(BINDIR) **********"

$(OBJDIR)%.o : $(SRCDIR)%.c
	gcc -c $< $(CFLAGS) $(IFLAGS) -o $@ 

clean :	
	rm -rf src/*~ $(OBJFILES) $(OBJFILESLC) $(OBJFILESTR) $(DBOBJFILES) $(DBOBJFILESLC) $(BINDIR)amil $(BINDIR)amildb $(BINDIR)amilnox $(BINDIR)amilnox_db $(BINDIR)amiltrace *.log  $(DISTRIB).tar.gz


run : amil
	$(BINDIR)amil

test : amilnox
	$(BINDIR)amilnox test.ail

indent : $(SRCFILES)
	indent -gnu -br $(SRCFILES) $(SRCFILESLC) $(SRCFILETR)

# 1> affichage.log 2> erreur.log 

#------- Pour debugage -----------#

$(DBOBJDIR)%.o : $(SRCDIR)%.c
	gcc  -c $< $(DBFLAGS) $(CFLAGS) $(IFLAGS) -o $@ 

amildb : $(DBOBJFILES)
	gcc $(DBFLAGS) $(CFLAGS) $(LDFLAGS) $(DBOBJFILES) -o $(BINDIR)amildb 

amilnox_db : $(DBOBJFILESLC)
	gcc $(DBFLAGS) $(CFLAGS) $(LDFLAGS) $(DBOBJFILESLC) -o $(BINDIR)amilnox_db 

debug : amildb_lc
	echo 'set args test.ail' > amil_setargs.gdb
	gdb -e $(BINDIR)amildb_lc -x amil_setargs.gdb
	rm amil_setargs.gdb


tgz: 
	rm -rf $(DISTRIB)
	mkdir -p $(DISTRIB)/{$(OBJDIR),$(DBOBJDIR),$(SRCDIR),$(BINDIR),$(EXAMPLEDIR)}
	cp $(SRCDIR)*.c $(SRCDIR)*.h $(DISTRIB)/$(SRCDIR)
	cp Makefile LICENSE $(DISTRIB)/	
	cp $(EXAMPLEDIR)*.ail $(DISTRIB)/$(EXAMPLEDIR)
	cp test.ail $(DISTRIB)/
	tar -czf $(DISTRIB).tar.gz $(DISTRIB)
	rm -rf $(DISTRIB)

#### Trucs 
# 1. Indentation linux-kernel style --Pierre : j'aime moins que la gnu.
# /sw/bin/indent -kr -i8 -ts8 -sob -l80 -ss -bs -psl
