# comp322

## Lab1

### Building
```
$ cd Lab-1
$ make
```

### Run

``` 
$ ./h1
``` 

contents of makefile:

CFLAGS=-Wall -Wextra

all: main 

main: main.c
	gcc main.c hello.c world.c -o h1

clean:
	rm -rf *.o h1