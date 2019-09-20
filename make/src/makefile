IDIR = ../include
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=obj
LDIR=../lib
LIBS=-lm
_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
$(ODIR)/%.o: %.c $(DEPS)
	@echo "------- Compiling the file $^ -------- "
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o ../$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	@echo "------- Cleaning the object files --------"
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~