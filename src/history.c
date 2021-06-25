#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List *list = malloc(sizeof(list));
  list -> root = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str)
{
  int count = 0;
  int len = 0;
  char *len_temp = str;
  while(*(len_temp +len) != '\0')
    {
      len++;
    }
  Item *temp = list -> root;
  if (temp != 0)
    {
      while(temp -> next != 0)
	{
	  temp = temp -> next;
	  count++;
	}
      temp -> next = malloc(sizeof(Item));
      temp -> next -> str = copy_str(str, len);
      temp -> next -> id = count;
    }
  else
    {
      temp = malloc(sizeof(Item));
      temp -> str = copy_str(str, len);
      temp -> id = 0;
    }
}

char *get_history(List *list, int id)
{
  if(!list) { return '\0'; }
  else
    {
      Item *temp = list -> root -> next;
      while(temp != 0)
	{
	  if(temp -> id == id){ return temp -> str; }
	  temp = temp -> next;
	}
    }
  return "Empty.\n";
}

void print_history(List *list)
{
  if(!list){ printf("List is empty.\n"); }
  else
    {
      Item *temp = list -> root -> next;
      while(temp)
	{
	  printf("[%d]: %s\n", temp -> id, temp -> str);
	  temp = temp -> next;
	}
      printf("\n");
    }
}

void free_history(List *list)
{
  Item *temp = list -> root;
  while(temp -> next != 0)
    {
      Item *temp2 = temp;
      temp = temp -> next;
      free(temp2 -> str);
      free(temp2);
    }
  free(temp -> str);
  free(temp);
  free(list);
}
