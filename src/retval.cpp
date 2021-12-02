//: Title       : retval
//: Date        : 2021-07-10
//: Author      : Kjetil Kristoffer Solberg <post@ikjetil.no>
//: Version     : 1.2
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
using std::stoi;
using std::cout;
using std::endl;

//
// #define
//
#define VERSION_NO     "1.2"
#define CLR_GREEN      "\033[32m"
#define CLR_WHITE      "\033[37;1m"
#define CLR_RESET      "\033[0m"

//
// Function Prototypes
//
void PrintUsage();

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
	
	int r = 0;
	try
	{
		r = stoi(argv[1]);
	}
	catch ( std::logic_error ) {
		PrintUsage();
		cout << "ABEND ERROR: INVALID ARGUMENT VALUE. NOT A NUMBER." << endl;
		return EXIT_FAILURE;
	}

	cout << "Return value is: " << r << endl;
	return r;
}

//
// Function: PrintUsage
//
// (i): Prints usage screen.
//
void PrintUsage()
{
	cout << CLR_RESET << CLR_GREEN;
	cout << "##" << endl;
	cout << "## Return Value" << endl;
	cout << "## Author  : Kjetil Kristoffer Solberg <post@ikjetil.no>" << endl;
	cout << "## Version : " << VERSION_NO << endl;
	cout << "## Usage   : retval <return value integer>" << endl;
	cout << "##" << endl;
	cout << "## Example: (return with exit/return code 5)" << endl;
	cout << "## ? retval 5" << endl;
	cout << "## ? echo $?" << endl;
	cout << "## 5" << endl;
	cout << "##" << endl;
	cout << CLR_RESET << CLR_WHITE;
}