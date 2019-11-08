#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR 36
#define NONE 63
#define YES 333
#define NO 4444
#define MAX_TRY 100
#define CHAR 1
#define SHORT 2
#define INT 4
#define LONG 8
#define FLOAT 5
#define DOUBLE 9
#define STRUCTURE 10

/* master_pointer */
typedef struct mp mp;
struct mp
{
  void* pointer;
  mp* previous;
  mp* next;
};


/* fonctions */
typedef struct REPLACE_ME REPLACE_ME;
struct REPLACE_ME
{
    REPLACE_ME* previous;
    REPLACE_ME* next;
};

/* master_pointer */
/*------------------------------------------------------*/
mp* create_master_pointer(void);
void* add_pointer_master(void* pointer,mp* master,char type,char size);
mp* reach_last_cell(mp* head);
void delete_master(mp* head);
mp* locate_pointer(void* pointer,mp* head);
void delete_pointer(void* pointer,mp* head);
short verification(mp* master);
/*------------------------------------------------------*/


/* fonctions */
/*------------------------------------------------------*/
void delete_up_and_down(REPLACE_ME* cell);
void delete_down(REPLACE_ME* head);
void* reallocate(mp* master,void* pointer,char type,int new_size);
int test_succes(void* name);
REPLACE_ME* struct_factory(mp* master,long nb_cell);
/*------------------------------------------------------*/
/* main (devrait être vide) */

/* test */
