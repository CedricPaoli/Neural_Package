CC=gcc
CFLAGS=-Wall -g

nsp: out/main.o out/nspio.o out/nspstd.o
	$(CC) $(CFLAGS) -o nsp out/main.o out/nspio.o out/nspstd.o

out/main.o: src/main.c
	 $(CC) $(CFLAGS) -c src/main.c -o out/main.o

out/nspio.o: src/nspio.c
	 $(CC) $(CFLAGS) -c src/nspio.c -o out/nspio.o

out/nspstd.o: src/nspstd.c
	 $(CC) $(CFLAGS) -c src/nspstd.c -o out/nspstd.o

clean:
	rm -f out/*.o

mrproper: clean
	rm -f nsp
