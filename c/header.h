#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR 36
#define NONE 63
#define YES 333
#define NO 4444
#define MAX_TRY 100
#define CHAR 255
#define SHORT 65535
#define INT 4294967295
#define LONG 18446744073709551615
#define FLOAT -4294967295
#define DOUBLE -18446744073709551615

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
mp* create_master_pointer(void);
int add_pointer_master(void* pointer,mp* master);
mp* reach_last_cell(mp* head);
void delete_down(mp* head);

/* fonctions */
void delete_up_and_down(REPLACE_ME* cell);
int test_succes(void* name);

/* main (devrait être vide) */

/* test */
