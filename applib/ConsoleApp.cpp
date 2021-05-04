#include <ConsoleApp.hpp>
#include <iostream>
#include <exception>

int main(int argc, char* argv[]) try {
#ifdef _DEBUG
	// Enable CRT memory leak checking.
	int dbgFlags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	dbgFlags |= _CRTDBG_CHECK_ALWAYS_DF;
	dbgFlags |= _CRTDBG_DELAY_FREE_MEM_DF;
	dbgFlags |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(dbgFlags);
#endif
	return ConsoleApplication::thisApp_sm->main(argc, argv);
}
catch (char const * msg) {
	cerr << "exception string: " << msg << endl;
}
catch (exception const& e) {
	cerr << "std::exception: " << e.what() << endl;
}
catch (...) {
	cerr << "Error: an exception has been caught...\n";
	return EXIT_FAILURE;
}

ConsoleApplication* ConsoleApplication::thisApp_sm = nullptr;

int ConsoleApplication::main(int argc, char* argv[]) {
	args_m.assign(argv, argv + argc);
	return execute();
}

ConsoleApplication::ConsoleApplication() {
	if (thisApp_sm)
		throw std::logic_error("Error: ConsoleApplication already initialized!");
	thisApp_sm = this;
}

int ConsoleApplication::execute() {
	cout << "Console application framework. \n";
	return EXIT_SUCCESS;
}