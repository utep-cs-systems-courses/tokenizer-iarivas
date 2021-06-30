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
  while(*(len_temp +len) != '\0')    //Gets the length of the entire string
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
      temp -> next = malloc(sizeof(Item));       //Allocates memory inside of temp -> next
      temp -> next -> str = copy_str(str, len);  //Iputs a copy of str into temp -> next -> str
      temp -> next -> id = count;                //Updates the id to be the next number in history
    }
  else
    {
      temp = malloc(sizeof(Item));               //For the first item in history this else is used
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
  return "Empty.\n";     //If no history exist
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
      Item *temp2 = temp;            //Frees every part of the list
      temp = temp -> next;
      free(temp2 -> str);
      free(temp2);
    }
  free(temp -> str);
  free(temp);
  free(list);
}
