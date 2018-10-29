main: main.c
	gcc -o main main.c

.PHONY: clean
clean:
	rm -f *.o
	rm main
