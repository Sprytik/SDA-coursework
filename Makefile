CC = cc
CFLAGS = -O2 -Wno-unused-result
PROG ?= coursework
OBJ = main.o menu.o MemoryNFilling.o Sort.o Measurement.o Table.o

.PHONY: greet build rebuild run clean

greet:
	@echo "Terminating make - please specify target explicitly"
	@echo "build: fast rebuild / build"
	@echo "rebuild: full rebuild"
	@echo "run after fast rebuild / build"
	@echo "clean: perform full clean"

build: $(PROG)

rebuild: clean $(PROG)

run: build
	./$(PROG)

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .o file with it's dependencies

main.o: main.c menu.h MemoryNFilling.h
	$(CC) $(CFLAGS) -c main.c -o $@

menu.o: menu.c menu.h MemoryNFilling.h Sort.h Table.h Measurement.h
	$(CC) $(CFLAGS) -c menu.c -o $@

MemoryNFilling.o: MemoryNFilling.c MemoryNFilling.h   
	$(CC) $(CFLAGS) -c MemoryNFilling.c -o $@

Sort.o: Sort.c Sort.h MemoryNFilling.h
	$(CC) $(CFLAGS) -c Sort.c -o $@

Measurement.o: Measurement.c Measurement.h Sort.h MemoryNFilling.h    
	$(CC) $(CFLAGS) -c Measurement.c -o $@

Table.o: Table.c MemoryNFilling.h Measurement.h Table.h
	$(CC) $(CFLAGS) -c Table.c -o $@


clean:
	rm -f $(OBJ) $(PROG)
