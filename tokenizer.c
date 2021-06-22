#include "tokenizer.h"
#include "stdio.h"

int space_char(char c)
{
  if((c == ' ' || c == '\t') && c != '\0')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if((c == ' ' || c == '\t') && c != '\0')
    return 0;
  return 1;
}
/*
char word_start(char *str)
{
  int i = 0;
  while(space_char(str[i]))
    {
      i++;
    }
  return &str[i];
}

char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(word[i]))
    {
      i++;
    }
  return &word[i];
}

int count_words(char *str)
{
  int words = 0;
  int i = 0;
  char *start = word_start(str);
  while(str[i] != '\0')
    {
      if(space_char(str[i]) && i+1 < len)
	{
	  if(non_space_char(str[i+1]))
	    {
	      words++;
	    }
	}
      i++;
    }
  return words;
}

char *copy_str(char *inStr, short len)
{
  char *copy = (char*) malloc((len+1) * sizeof(char));
  int i;
  for(i = 0; i <= len; i++)
    {
      if(i == len) { copy[i] = '\0'; }
      else { copy[i] = inStr[i]; }
    }
  return copy;
}

char **tokenize(char* str)
{
  char *start = word_start(str);
  int words = count_words(str);
  char **tokens = (char**) malloc((words+1) * sizeof(char*));
  int end = 0;
  int i;
  for(i = 0; i <= words; i++)
    {
      end = word_terminator(start);
      tokens[i] = copy_str(start, end);
      start = word_start(end);
    }
  return tokens;  
}

void print_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens)
    {
      printf("Token[%d] = %s", i, tokens[i]);
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
*/
