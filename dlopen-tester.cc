#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2) {
		cerr << "Usage: " << endl << endl;
		cerr << "$ dlopen-tester filename.so" << endl << endl;
		return EXIT_FAILURE;
	}

	dlerror();

	const string filename = argv[1];
	int flag = RTLD_LAZY;
	cout << "Filename: " << filename << endl;
	cout << "dlopen flags: " << hex << flag << endl;
	void *handle = dlopen(filename.c_str(), flag);
	if (!handle) {
		const char *err = dlerror() ? : "";
		cerr << "Fail: dlopen: " << err << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
