CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -lm -g -O0
DEPS = matrix.h vector.h hessenberg.h
ODIR = obj

_OBJ = matrix.o vector.o hessenberg.o main.o 
OBJ = $(patsubst %,$(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.c $(DEPS) dir
	$(CC) -c -o $@ $< $(CFLAGS)

programa: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: dir

dir:
	mkdir -p $(ODIR)

.PHONY: clear

clean:
	rm -f $(ODIR)/*.o *~ programa


