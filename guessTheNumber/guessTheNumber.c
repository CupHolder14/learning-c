#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWER  0 /* lower limit of temperature scale */ 
#define UPPER  300 /* upper limit */
#define STEP  20 /* step size */

int startGame();

int main()
{
  startGame();

  return 0;
}

int getRand()
{
  srand(time(NULL));
  return rand() % 10 + 1;
}

int startGame()
{
  /* Guess the number */

  int num; /* the number to guess for */
  int guess; /* the user's guess */
  char yn[1]; /* yes or no input */

  num = getRand(); /* get a random number */

  printf("Guess a number\n");

  while(guess != num) {
    scanf("%d", &guess);
    if(guess != num) {
      printf("\nIncorrect! Guess again \n");
    }
  }
  
  printf("\nNice you guessed the right number!\n");
  printf("Do you want to play again? (y/n)\n");
  do {
    scanf("%2s", yn);
  } while (strcmp(yn, "y") != 0 && strcmp(yn, "n") != 0);

  if(strcmp(yn, "y") == 0) {
    printf("\n Starting game\n");
    startGame();
  }

  return 0;
}
