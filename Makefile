all:
	cc -o example example.c -ljansson -std=c99
clean:
	rm -rf example
