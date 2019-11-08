#include "header.h"

int main(int argc,char* argv[])
{
	mp* master = create_master_pointer();
	short lama = verification(master);
	delete_master(master);
	return 0;
}
