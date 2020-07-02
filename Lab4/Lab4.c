#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define FREECHOPSTICK 3

sem_t *leftChopstick;
sem_t *rightChopstick;

typedef void (*sighandler_t)(int);
volatile sig_atomic_t done = 0;
int raise(int sig);
int phInt;
int loop;
char *lChopName;
char *rChopName;
struct chopsticks
{
    sem_t *left;
    sem_t *right;
    char *lName;
    char *rName;
};

struct chopsticks *chops;

void term(int signum)
{
    done = 1;
    sem_close(chops->left);
    sem_destroy(chops->left);
    sem_close(chops->right);
    sem_destroy(chops->right);
    fprintf(stderr, "Philosopher %d completed %d cycles.\n", phInt, loop);
    free(chops);
}

void eat(int phnum)
{
    printf("Philosopher %d is Eating\n", phnum);
    usleep(((rand() % 11) + 80) * 10000);
}

void think(int phnum)
{
    printf("Philosopher %d is Thinking\n", phnum);
    usleep(((rand() % 11) + 80) * 10000);
}

void wait()
{
    printf("Philosopher %d is waiting for left chopstick: %s\n", phInt, chops->lName);
    if (sem_trywait(chops->left) != 0)
    {
        printf("couldn't get left chopstick. going to think for a bit.\n");
        raise(FREECHOPSTICK);
        think(phInt);
    }
    else
    {
        printf("Philosopher %d is waiting for right chopstick: %s\n", phInt, chops->rName);
        if (sem_trywait(chops->right) != 0)
        {
            printf("couldn't get right chopstick. going to think for a bit.\n");
            raise(FREECHOPSTICK);
            think(phInt);
        }
    }
}

void signalHandler(int signal)
{
    sem_post(chops->left);
    sem_post(chops->right);
}

int main(int argc, char *argv[])
{
    signal(SIGTERM, term);
    signal(SIGINT, term);
    signal(FREECHOPSTICK, signalHandler);

    char *phil = argv[2];
    char *seats = argv[1];
    char *p1;
    char *p2;
    int a = sizeof(argv[1]);

    phInt = atoi(phil);

    int oflag = O_CREAT;
    mode_t mode = 0644;

    char lChopArr[7] = "/chop";
    strcat(lChopArr, phil);
    lChopName = lChopArr;

    char rChopArr[7];
    rChopArr[0] = '\0';
    strcpy(rChopArr, "/chop");

    if (*seats != '0')
    {
        char tmp[2];
        tmp[0] = '\0';
        strcpy(tmp, seats);
        strcat(rChopArr, tmp);
    }
    else
    {
        char tmp[2];
        tmp[0] = '\0';
        char *seatZero;
        sprintf(seatZero, "%d", a);
        seats = seatZero;
        strcpy(tmp, seats);
        strcat(rChopArr, tmp);
    }

    rChopName = rChopArr;

    chops = (struct chopsticks *)malloc(sizeof(struct chopsticks));

    leftChopstick = sem_open(lChopName, oflag, mode, argc);
    if (leftChopstick == SEM_FAILED)
    {
        fprintf(stderr, "sem_open() failed.  errno:%d\n", errno);
        leftChopstick = sem_open(phil, 0, mode, argc);
    }
    sem_unlink(lChopName);

    chops->left = leftChopstick;
    chops->lName = lChopName;

    rightChopstick = sem_open(rChopName, oflag, mode, argc);
    if (rightChopstick == SEM_FAILED)
    {
        fprintf(stderr, "sem_open() failed.  errno:%d\n", errno);
        rightChopstick = sem_open(seats, 0, mode, argc);
    }
    sem_unlink(rChopName);

    chops->right = rightChopstick;
    chops->rName = rChopName;

    while (!done)
    {
        wait();
        eat(phInt);
        raise(FREECHOPSTICK);
        think(phInt);
        loop++;
    }

    printf("done.\n");
    return 0;
}