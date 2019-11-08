#include "header.h"
int main(int argc,char* argv[])
{
	mp* master = create_master_pointer();

	// test_create_master();
	// test_add_pointer_master();
	// test_reach_last_cell();
	// test_locate_pointer();
	// test_delete_pointer();
	// test_verification();

	delete_master(master);
	return 0;
}




void test_ (void)
{

}

void test_create_master(void)
{
	mp* master = create_master_pointer();
	if(!test_success(master))
		printf("[Créer MP]Master Pointer non allouée !\n");
	else if(test_success(master->next))
		printf("[Créer MP]La 1ère cellule n'est pas la dernières !\n");
	else if(test_success(master->previous))
		printf("[Créer MP]La 1ère cellule n'est pas la première !\n");
	else if(master->pointer != master)
		printf("[Créer MP]La tête ne pointe pas sur elle même !\n");
	else
		printf("[Créer MP]Master Pointer crée , 1 seule et unique cellule !\n");
	delete_master(master);
}

void test_add_pointer_master(void)
{
		mp* master = create_master_pointer();

		char* first = NULL;
		first = add_pointer_master(first,master,CHAR,5);
		int* second = NULL;
		second = add_pointer_master(second,master,FLOAT,8);
		REPLACE_ME* third = NULL;
		third = add_pointer_master(third,master,STRUCTURE,16);

		if (first == master->next->pointer)
			printf("[Add pointer]Element de type CHAR crée !\n");
		else
			printf("[Add pointer]L'element de type CHAR n'a pas été crée !\n");

		if (second == master->next->next->pointer)
			printf("[Add pointer]Element de type INT crée !\n");
		else
			printf("[Add pointer]L'element de type INT n'a pas été crée !\n");

		if (third == master->next->next->next->pointer)
			printf("[Add pointer]Element de type STRUCTURE crée !\n");
		else
			printf("[Add pointer]L'element de type STRUCTURE n'a pas été crée !\n");

		if (master->pointer == master->next->next->next)
			printf("[Add pointer]Pointer en en-tête correspond bien au dernier !\n");
		else
			printf("[Add pointer]Pointer en en-tête ne correspond pas à la dernière cellule %p:%p!\n",master->pointer,master->next->next->next);

		delete_master(master);
}

void test_reach_last_cell(void)
{
	mp* master = create_master_pointer();

	if (reach_last_cell(master) == master->pointer)
		printf("[RLS]Reach_Last_Cell retourne bien un pointeur sur la dernière cellule !\n");
	else
		printf("[RLS]Reach_Last_Cell ne retourne pas un pointeur suur la dernière cellule !\n");

	delete_master(master);
}

void test_locate_pointer(void)
{
	mp* master = create_master_pointer();

	int* first = NULL;
	first = add_pointer_master(first,master,INT,5);

	if (master->pointer == locate_pointer(first,master))
		printf("[Locate]Renseigne bien là bonne cellule à partir d'un pointeur qui fais parti de la liste !\n");
	else
		printf("[Locate]Ne renseigne pas l'adresse de la bonne cellule !\n");

	delete_master(master);
}

void test_delete_pointer(void)
{
	mp* master = create_master_pointer();

	int* first = NULL;
	first = add_pointer_master(first,master,INT,5);

	char* second = NULL;
	second = add_pointer_master(second,master,CHAR,4);

	delete_pointer(second,master);

	if(master->pointer == locate_pointer(first,master))
		printf("[Delete Pointer]Le pointeur a bien été supprimé de la liste !\n");
	else
		printf("[Delete Pointer]Le pointeur n'a pas été supprimé de la liste !\n");

	delete_master(master);
}

void test_verification(void)
{
	mp* master = create_master_pointer();

	int* first = NULL;
	first = add_pointer_master(first,master,INT,5);

	char* second = NULL;
	second = add_pointer_master(second,master,CHAR,7);

	short try = verification(master);
	master->next = NULL;

	if(try == NO)
		printf("[Verification]Ne trouve pas la liste continue !\n");
	else if(!verification(master))
		printf("[Verification]Ne trouves pas que la liste est rompue !\n");
	else
		printf("[Verification]Trouve bien quand la liste est continue et quand la liste est rompue !\n");

	delete_master(master);
}
