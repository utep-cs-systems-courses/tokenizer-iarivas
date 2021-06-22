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
    char *p = word_start(input);
    printf("Pointer = %c\n", *p);
    char *ep = word_terminator(p);
    printf("End Pointer = %c\n", *ep);
    printf("Length of word = %d\n", (ep-p));
    int words = count_words(input);
    printf("%d\n", words);
    char temp[];
    temp = copy_str(p, ep-p);
    int i;
    while(*(temp+i) != '\0')
      {
	printf("%c\n", *(temp+1));
      }
  quit:
    printf("quit.");
    return 0;
  }
  done:
  return 0;
}
