#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<error.h>
# define n 4

void main()

{

  int mutex, empty, full, pid, id, i;

  key_t key;

  mutex = semget(key, 1, IPC_CREAT | 0666);

  void down(int);
  void up(int);
  key - ftok("eg.txt", 'a');
  printf(" Semaphore (mutex) id %d\n", mutex);
  semctl(mutex, 0, SETVAL, 1);
  printf("Mutex initialised as 1\n");
  key = ftok("eg.txt", 'b');
  printf("Empty initialized as %d\n", n);
  key = ftok("eg.txt", 'c');
  full = semget(key, 1, IPC_CREAT(0666); printf("Semaphore (full) id %d\n", full); semctl(full, 0, SETVAL, 0);

      empty = semget(key, 1, IPC_CREAT(0666); printf("semaphore (empty) id %d\n", empty); semctl(empty, 0, SETVAL, n);

        printf("Full initialized as 0\n");

        pid = fork();
        if (pid > 0)

        {
          for (i = 1; i <= n; i++)

          {

            down(empty);

            down(mutex);

            printf("producer produced item %d\n", i);

            up(mutex);

            up(full);

            sleep(1);

          }

        } else if (pid == 0)

        {
          for (i = 1; i <= n; i++)

          {
            down(full);

            down(mutex);

            printf("Consumer consumed item %d\n", i);

            up(mutex);
            up(empty);

          }

        } else

        {
          printf("error\n");

        }

      }

      void down(int id)

      if (semop(id, & sb[0], 1) == -1) struct sembuf sb[1] = {
        0,
        -1,
        0
      };

      {

        {

        }

      }

      printf("error\n");

      void up(int id)

      {

        struct sembuf sb[1] = {
          0,
          1,
          0);
        if (semop(id, & sb[0], 1) == -1)

          printf("error\n");

        {

        }

      }
