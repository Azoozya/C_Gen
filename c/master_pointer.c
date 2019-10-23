#include "header.h"

mp* create_master_pointer(void)
{
  mp* to_return;
  do {
     to_return = malloc(sizeof(mp));
  } while(test_succes(to_return) != YES);
  to_return->next = NULL;
  to_return->previous = NULL;
  to_return->pointer = to_return;
  return to_return;
}

int add_pointer_master(void* pointer,mp* master)
{
  mp* buffer = reach_last_cell(master);
  int counter = 0;
  do {
     buffer->next = malloc(sizeof(mp));
     counter++;
  } while(test_succes(buffer->next) != YES && counter < MAX_TRY);

  if (counter  == 100 || buffer->next == NULL)
    {
      printf("Ajout du pointeur impossible.\n");
      return NO;
    }
  else
    {
      buffer->next->previous = buffer;
      buffer->next->next = NULL;
      buffer->next->pointer = pointer;
      return YES;
    }
}

mp* reach_last_cell(mp* head)
{
  mp* to_return = head;
  while(to_return->next != NULL)
    {
      to_return = to_return->next;
    }
  return to_return;
}

void delete_master(mp* head)
{
  mp* buffer = head->next;

  int counter = 1;
  free(head);
  while (buffer != NULL)
    {
      free(buffer->pointer);
      if(counter > 1)
        free(buffer->previous);
      if(buffer->next == NULL)
        free(buffer);
      buffer = buffer->next;
      counter++;
    }
  printf("Suppression de %d cellule(s) effectué\n",counter);
}
