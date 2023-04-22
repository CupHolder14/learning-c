#include <stdio.h>

#define X_WINNER  0
#define O_WINNER  1
#define NO_WINNER  2

int menu();
int startGame();
void renderBoard();
int checkBoardState(char boardState[3][3], char symbol);

int main()
{
  int gameState = 1;
  int userWins = 0;
  int aiWins = 0;

  do {
    menu(&gameState, &userWins, &aiWins);
  } while(gameState == 1);

  return 0;
}

int menu(int* ptrGameState, int* ptrUserWins, int* ptrAIWins)
{
  /* Display Menu */
  int opt;
  int matchState = 1; /* differs from gamestate, this is each game */

  printf("\n===============TIC TAC TOE===============\n");
  printf("You: %d\t AI: %d\n", *ptrUserWins, *ptrAIWins);
  printf("Select a menu option\n");

  printf("1. Start\n");
  printf("2. Exit\n");

  scanf("%d", &opt); /* wait for user input */

  switch(opt) {
    case 1:
      printf("Starting game...\n");
      int result = startGame(&matchState);
      if(result == X_WINNER) {
        (*ptrUserWins)++;
      } else if(result == O_WINNER) {
        (*ptrAIWins)++;
      } else {
        printf("\nNo winner\n");
      }
      printf("Game completed\n");
      menu(ptrGameState, ptrUserWins, ptrAIWins);
      break;
    case 2:
      printf("Thanks for playing!\n");
      *ptrGameState = 0; /* this will break do/while loop in main() */
      break;
    default:
      break;
  }
}

void renderBoard(char boardState[3][3])
{
  printf("\t 0 | 1 | 2 \n");
  for(int i = 0; i < 3; i++) {
    printf("%d\t %c | %c | %c \n", i, boardState[i][0], boardState[i][1], boardState[i][2]);
    if(i < 2) {
      printf("\t---|---|---\n");
    }
  }
  printf("\n");
}

int checkBoardState(char boardState[3][3], char symbol)
{
  /* check rows */
  for(int i = 0; i < 3; i++) {
    if(boardState[i][0] == symbol && boardState[i][1] == symbol && boardState[i][2] == symbol) {
      return 1;
    }
  }

  /* check columns */
  for(int i = 0; i < 3; i++) {
    if(boardState[0][i] == symbol && boardState[1][i] == symbol && boardState[2][i] == symbol) {
      return 1;
    }
  }

  /* check diagonal */
  if(boardState[0][0] == symbol && boardState[1][1] == symbol && boardState[2][2] == symbol) {
    return 1;
  }
  if(boardState[0][2] == symbol && boardState[1][1] == symbol && boardState[2][0] == symbol) {
    return 1;
  }

  /* lastly check if there are no more options */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(boardState[i][j] == ' ') {
        return 0;
      }
    }
  }

  return -1; /* no more moves */
}

int startGame(int* ptrMatchState)
{
  int winner = -1;
  int row;
  int col;
  char symbol = 'x';

  char boardState[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };

  do {
    renderBoard(boardState); /* re-render new state */

    printf("%c's turn\n", symbol); /* print current player's turn */

    printf("Select a row\n");
    scanf("%d", &row); /* get row */

    printf("Select a column\n");
    scanf("%d", &col); /* get column */

    if(boardState[row][col] != ' ') {
      printf("\nThere is already a symbol there\n");
      continue; /* continue if position is taken */
    }

    boardState[row][col] = symbol; /* update board state */

    /* check board state */
    int won = checkBoardState(boardState, symbol);
    if(won == 1) {
      printf("\n%c Won!\n", symbol);
      if (symbol == 'x') {
        winner = X_WINNER;
      } else {
        winner = O_WINNER;
      }
    } else if(won == -1) {
      winner = NO_WINNER;
    }


    /* flip symbol */
    if(symbol == 'x') {
      symbol = 'o';
    } else {
      symbol = 'x';
    }
  } while(winner < 0);

  return winner;
}
