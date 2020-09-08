# build an executable named myprog from myprog.c
all: main.c
	gcc -g -Wall -o p main.c nets.c

clean:
	$(RM) p

run:
	echo "running:"
	./p
