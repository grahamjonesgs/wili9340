all: libtest

libtest: libtest.o fontx.o wili9340.o
	 gcc -o libtest libtest.o  wili9340.o fontx.o -lm -lpthread -lbcm2835

libtest.o: libtest.c
	 gcc -c libtest.c

fontx.o: fontx.c
	gcc -c fontx.c

wili9340.o: wili9340.c
		gcc -c wili9340.c -DBCM

clean:
	 rm -f libtest.o libtest wili9340.o fontx.o
