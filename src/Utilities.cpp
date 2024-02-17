#include "Utilities.h"

//====================================================================
void checkFile(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cerr << "Error opening file\n";
		exit(EXIT_FAILURE);
	}
}
