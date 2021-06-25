#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if((c == ' ' || c == '\t') && c != 0)
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if((c == ' ' || c == '\t') && c != 0)
    return 0;
  return 1;
}

char *word_start(char *str)
{
  int i = 0;
  while(space_char(*(str+i)) && *(str+i) != '\0')
    {
      i++;
    }
  return str+i;
}

char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(*(word+i)) && (*(word+i) != '\0'))
    {
      i++;
    }
  return word+i;
}

int count_words(char *str)
{
  int words = 0;
  char *start = word_start(str);
  while(*start != '\0')
    {
      if(non_space_char(*start)){ words++; }
      start = word_terminator(start);
      start = word_start(start);
    }
  return words;
}

char *copy_str(char *inStr, short len)
{
  char *copy = malloc((len+1) * sizeof(char));
  int i;
  for(i = 0; i <= len; i++)
    {
      if(i == len) { copy[i] = '\0'; }
      else {
	if(inStr[i] != '\n'){
	  copy[i] = inStr[i];
	}
      }
    }
  return copy;
}

char **tokenize(char* str)
{
  char *start = word_start(str);
  int words = count_words(str);
  char **tokens = malloc((words+1) * sizeof(char*));
  char *end;
  int i;
  for(i = 0; i < words; i++)
    {
      end = word_terminator(start);
      tokens[i] = copy_str(start, end-start);
      start = word_start(end);
    }
  tokens[i] = 0;
  return tokens;  
}

void print_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != 0; i++)
    {
      printf("Token[%d] = %s\n", i, tokens[i]);
    }
}

void free_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != 0; i++)
    {
      free(tokens[i]);
    }
  free(tokens);
}
