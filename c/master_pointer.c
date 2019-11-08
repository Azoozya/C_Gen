#include "header.h"

mp* create_master_pointer(void)
{
  mp* to_return;
  do {
     to_return = malloc(sizeof(mp));
  } while(!test_success(to_return));

  to_return->next = NULL;
  to_return->previous = NULL;
  to_return->pointer = to_return;
  return to_return;
}

void* add_pointer_master(void* pointer,mp* master,char type,char size)
{
  mp* buffer = reach_last_cell(master);
  int counter = 0;
  do {
     buffer->next = malloc(sizeof(mp));
     counter++;
  } while(!test_success(buffer->next) && counter < MAX_TRY);

  if (counter  == 100 || buffer->next == NULL)
    {
      printf("Impossible d'ajouter une cellule au MP.\n");
      return NULL;
    }
  else
    {
      buffer->next->previous = buffer;
      master->pointer = (void*)(buffer->next);
      buffer->next->next = NULL;
      if (type != STRUCTURE)
          do { pointer = reallocate(master,pointer,type,size); } while(!test_success(pointer));
      else
          do { pointer = malloc(size); } while(!test_success(pointer));

      buffer->next->pointer = pointer;
      return pointer;
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

mp* locate_pointer(void* pointer,mp* head)
{
    mp* to_return = NULL;
    if(!test_success(pointer))
        printf("Pointeur sur NULL\n");
    else
        {
            mp* buffer = head;
            mp* last = reach_last_cell(head);
         while(buffer != last && !test_success(to_return))
             {
                 if(buffer->pointer == pointer)
                    to_return = buffer;
                 buffer = buffer->next;
             }
         if(buffer == last && !test_success(to_return) && buffer->pointer == pointer)
              to_return = buffer;
        }
    return to_return;
}

void delete_pointer(void* pointer,mp* head)
{
    mp* cell = locate_pointer(pointer,head);
    if( !test_success(cell))
      printf("%p ne fait pas parti de MP\n",pointer);
    else
      {
        if(pointer != (void*)head)
        {
            cell->previous->next = cell->next;

            if(cell != head->pointer)
              cell->next->previous = cell->previous;
            else
              head->pointer = cell->previous;

            free(cell->pointer);
            free(cell);
        }
      }
}

char verification(mp* master)
{
  mp* buffer = master;
  while (buffer != master->pointer && !test_success(buffer))
    {
      buffer = buffer->next;
    }
  if (test_success(buffer))
    {
      while (buffer != master && !test_success(buffer))
        {
          buffer = buffer->previous;
        }
      if(!test_success(buffer))
        {
          printf("Master pointer rompue (Retour)\n");
          return NO;
        }
      else
        return YES;
    }
  else
    {
      printf("Master pointer rompue (Aller) : %p %p\n",buffer,master);
      return NO;
    }
}
