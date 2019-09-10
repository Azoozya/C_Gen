#include "header.h"

int main(int argc,char* argv[])
{
	mp* master = create_master_pointer();

	//             EXEMPLE
	// char* lama = malloc(sizeof(char));
	// if (test_succes(lama) == YES)
	// 	add_pointer_master((void*)lama ,master);

	delete_down(master);
	return 0;
}
