//: Title       : retval
//: Date        : 2021-07-10
//: Author      : Kjetil Kristoffer Solberg <post@ikjetil.no>
//: Version     : 1.0
//: Description : Application starts and immediately exits with exit code given as argument.
//: Usage       : retval <integer exit code>
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

	if ( !IsArgNumber(argv[1]) ) {
		PrintUsage();
		return EXIT_FAILURE;
	}

	return atoi(argv[1]);
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
	cout << "? retval 5" << endl;
	cout << "? echo $?" << endl;
	cout << "5" << endl;
	cout << endl;
}

//
// Function: IsArgNumber
//
// (i): Is given string argument a number.
//
bool IsArgNumber(char *num)
{
	if (num == nullptr) {
		return false;
	}

	for (int i = 0; i < strlen(num); i++) {
		if (i == 0 && (num[i] == '+' || num[i] == '-')) {
			continue;
		}
		if (!isdigit(num[i])) {
			return false;
		}
	}

	return true;
}
