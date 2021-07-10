//
// #include
//
#include <iostream>
#include <cstring>

//
// using
//
using std::atoi;
using std::cout;
using std::endl;

//
// Function Prototypes
//
void PrintUsage();
bool IsArgNumber(char *num);

//
// Function: main
//
// (i): Application entry point.
//
int main(int argc, char *argv[])
{
	if (argc != 2) {
		PrintUsage();
		return EXIT_FAILURE;
	}

	if ( IsArgNumber(argv[1]) ) {
		return atoi(argv[1]);
	}

	PrintUsage();
	return EXIT_FAILURE;
}

//
// Function: PrintUsage
//
// (i): Prints usage screen.
//
void PrintUsage()
{
	cout << "retval v1.0 (amd64)" << endl;
	cout << "Usage: retval <return value integer>" << endl;
	cout << endl;
	cout << "Example: (return with exit/return code 5)" << endl;
	cout << "    retval 5" << endl;
	cout << endl;
}

bool IsArgNumber(char *num)
{
	if (num == nullptr) {
		return false;
	}

	for (int i = 0; i < strlen(num); i++) {
		if (!isdigit(num[i])) {
			return false;
		}
	}

	return true;
}
