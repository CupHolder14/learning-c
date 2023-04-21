#include <stdio.h>

int main()
{
  float num1, num2; /* numbers we will add (user provided)*/
  float* pnum2 = &num2; /* Trying out pointers */
  float computed; /* the number we compute */

  printf("Hello C!\n");
  printf("Give me two numbers, press enter after each number\n");
  scanf("%f", &num1);
  scanf("%f", pnum2);

  printf("Computing %f + %f ...\n", num1, num2);

  computed = num1 + num2;

  printf("= %f or about %.2f", computed, computed);

  return 0;
}
