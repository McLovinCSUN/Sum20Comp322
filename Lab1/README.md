# comp322
```
https://github.com/McLovinCSUN/Sum20Comp322.git
```
#questions
```
Next, answer the following questions (this will require carefully examining the output of system calls):

1. What system call or calls correspond to opening the source and destination files?
-openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
-openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
2. What system call or calls correspond to reading the source file and writing the destination file?
-read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\260\34\2\0\0\0\0\0"..., 832) = 832
-write(1, "Please enter input file name: ", 30Please enter input file name: ) = 30
-read(0, 0x7fffbaa00270, 4096)           = ? ERESTARTSYS (To be restarted if SA_RESTART is set)
--- SIGWINCH {si_signo=SIGWINCH, si_code=SI_KERNEL} ---
-read(0,"\n", 4096)                     = 1
3. What system call or calls correspond to closing the source and destination files?
-close(3)
```

## Lab1

### Building
```
$ cd Lab1
$ make
```

### Run

``` 
$ ./fileCopy
``` 

contents of makefile:

CFLAGS=-Wall -Wextra

all: fileCopy 

catcher: fileCopy.c
	gcc fileCopy.c -o fileCopy

clean:
	rm -rf *.o fileCopy
