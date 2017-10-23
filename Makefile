CFLAGS := -g -Wall -std=c99
LDFLAGS := -lm

all: main test

%.o:%.c
	$(CC) -c $(CFLAGS) $^

main: main.o functions.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: test
test:
	$(info Automatically pass this!)

.PHONY: clean
clean:
	rm -f main *.o
	rm -f *~ \#*\# *.sw*
