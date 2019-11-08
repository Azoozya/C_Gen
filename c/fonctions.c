#include "header.h"

REPLACE_ME* struct_factory(mp* master,long nb_cell)
{
  REPLACE_ME* to_return = NULL;
  REPLACE_ME* cell = NULL;
  REPLACE_ME* previous = NULL;

  for(long depth = 0 ; depth < nb_cell ; depth++)
    {
    	cell = (REPLACE_ME*)add_pointer_master((void*)cell ,master,STRUCTURE,0);
      cell->next = NULL;
      cell->previous = previous;

      if(depth == 0)
          to_return = cell;
      else
          cell->previous->next = cell;
      previous = cell;
    }

  return to_return;
}

//Libère chacune des cellules d'une liste chaînée de n'importe quel cellule , voir modèle de structure REPLACE_ME
void delete_up_and_down(REPLACE_ME* cell)
{
  if (cell != NULL)
    {
      if( cell->previous == NULL && cell->next == NULL)
        {
          free(cell);
        }
  REPLACE_ME* down = cell->next;
  REPLACE_ME* up = cell->previous;
  REPLACE_ME* buffer = NULL;
  while (down != NULL || up != NULL)
    {
      if( down != NULL && up != NULL)
        {
          buffer = down->next;
          free(down);
          down = buffer;

          buffer = up->previous;
          free(up);
          up = buffer;
      }
      if( down == NULL && up != NULL)
        {
          buffer = up->previous;
          free(up);
          up = buffer;
        }
      if( down != NULL && up == NULL)
        {
          buffer = down->next;
          free(down);
          down = buffer;
        }

    }
  }
}

//Libère chacune des cellules d'une liste chaînée en partant de la tête, la structure doit avoir un pointeur next.
void delete_down(REPLACE_ME* head)
{
  REPLACE_ME* buffer;
  int counter = 0;
  do
    {
      buffer = head->next;
      free(head);
      head = buffer;
      counter += 1;
    }
    while (head != NULL);
  printf("Suppression de %d cellule(s) effectué\n",counter);
}

//Vérifie que le pointeur est différent de NULL (return YES si != NULL)
int test_succes(void* name)
{
  if (name == NULL)
    return NO;
  else
    return YES;
}

//Permet une reallocation de mémoire pour un tableau d'un TYPE donné (voir les #define pour les type supportés)
void* reallocate(mp* master,void* pointer,char type,int new_size)
{
  void* to_return = NULL;
  mp* head = master;
  switch (type)
  {
    case CHAR:
      to_return = realloc((char*)pointer,new_size*sizeof(char));
      break;
    case SHORT:
      to_return = realloc((short*)pointer,new_size*sizeof(short));
      break;
    case INT:
      to_return = realloc((int*)pointer,new_size*sizeof(int));
      break;
    case LONG:
      to_return = realloc((long*)pointer,new_size*sizeof(long));
      break;
    case FLOAT:
      to_return = realloc((float*)pointer,new_size*sizeof(float));
      break;
    case DOUBLE:
      to_return = realloc((double*)pointer,new_size*sizeof(double));
      break;
    default:
      printf("[Reallocate]Typer non reconnu.\n");
      break;
  }

  while(head != NULL && head->pointer != pointer)
      head = head->next;

  if(head != NULL)
    {
      head->pointer = to_return;
      printf("Master Pointer mise à jour.\n");
    }
  return to_return;
}
