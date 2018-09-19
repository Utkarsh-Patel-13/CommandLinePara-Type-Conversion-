all:
	gcc cmdlinearg_learning.c -o typeconv -lm

clean:
	rm -rf typeconv
