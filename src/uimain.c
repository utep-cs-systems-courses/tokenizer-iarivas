#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
char input[50];

int main()
{
  List *history = init_history();
  goto options;
  
  options:
  printf("\n\n");
    printf("Select an option below.\n");
    printf("Enter 'i' to input a string.\n");
    printf("Enter 'h' to view history.\n");
    printf("Enter '!#' to view a specific item in history.\n");
    printf("Enter 'q' to exit the program.\n");
    printf(">");
    fgets(input, 50, stdin);
    if(input[0] == 'i'){ goto input; }
    else if(input[0] == 'q') { goto quit; }
    else if(input[0] == 'h') { goto history; }
    else if(input[0] == '!') { goto s_history; } 
    else
      {
	printf("Error try again.\n");
	goto options;
      }
  input:
    printf("Enter the string you want to Tokenize.\n>");
    fgets(input, 50, stdin);
    char **tokens = tokenize(input);
    print_tokens(tokens);
    int i;
    add_history(history, input);
    free_tokens(tokens);
    goto options;
  history:
    print_history(history);
    goto options;
  s_history: ;
    char *temp = get_history(history, atoi(input+1));
    printf("[%d] = %s\n", atoi(input+1), temp);
    goto options;
  quit:
    printf("Thank you. Goodbye!.\n");
    free_history(history);
    return 0;
}
