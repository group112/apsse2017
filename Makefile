CC    =gcc
CFLAGS=-g -Wall -Wextra -Werror -Wold-style-declaration -Wold-style-definition \
       -Wfloat-equal -pedantic -std=gnu99

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ap gp

ap: file1.o file2.o
	$(CC) $^ -o $@ -lm

gp: file1.o file3.o
	$(CC) $^ -o $@ -lm

clean:
	rm -f *.o ap gp
