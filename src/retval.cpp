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

namespace ItSoftware::RetVal
{
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
			cout << "ABEND FAILURE. INVALID NUMBER OF ARGUMENTS." << endl;
			return EXIT_FAILURE;
		}
		
		int r = 0;
		try
		{
			r = stoi(argv[1]);
		}
		catch ( std::logic_error ) {
			PrintUsage();
			cout << "ABEND FAILURE: INVALID ARGUMENT VALUE. NOT A NUMBER." << endl;
			return EXIT_FAILURE;
		}

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
		cout << CLR_RESET << CLR_WHITE;
	}
}

//
// Function: main
//
// (i): Application entry point.
//      Redirects to ItSoftware::RetVal::main.
//
int main(int argc, char* argv[])
{
	return ItSoftware::RetVal::main(argc, argv);
}