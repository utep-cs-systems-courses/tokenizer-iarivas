#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
char input[50];

int main()
{
  while(1)
  {
  options:
    printf("Select n option below.\n");
    printf("Enter 'i' to input a string.\n");
    printf("Enter 'q' to exit the program.\n");
    printf(">");
    fgets(input, 50, stdin);
    if(input[0] == 'i'){ goto input; }
    else if(input[0] == 'q') {goto quit; }
    else
      {
	printf("Error try again.\n");
	goto options;
      }
  input:
    printf("Enter the sting you want to Tokenize.\n>");
    fgets(input, 50, stdin);
    int i;
    for(i = 0; i < 50; i++)
      {
	if(input[i] != 0)
	  {
	    printf("input[%d] == %c, sc = %d, npc = %d\n", i, input[i], space_char(input[i]), non_space_char(input[i]));
	  }
      }
  quit:
    printf("quit.");
    return 0;
  }
  done:
  return 0;
}
