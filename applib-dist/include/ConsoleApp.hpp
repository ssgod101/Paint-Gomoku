#pragma once
#pragma comment(linker, "/ENTRY:mainCRTStartup")

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

#if defined(_DEBUG) && defined(_DLL)
#pragma comment(lib,"applib-mt-gd.lib")
#elif defined(_DEBUG) && !defined(_DLL)
#pragma comment(lib,"applib-mt-sgd.lib")
#elif !defined(_DEBUG) && defined(_DLL)
#pragma comment(lib,"applib-mt.lib")
#elif !defined(_DEBUG) && !defined(_DLL)
#pragma comment(lib,"applib-mt-s.lib")
#endif

// Create a dbg version of new that provides more information
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include<vector>
#include<string>
using namespace std;

class ConsoleApplication {
private:
	using Args = vector<string>;
	static ConsoleApplication* thisApp_sm;
	friend int main(int argc, char* argv[]);
	int main(int argc, char* argv[]);
	Args args_m;
protected:
	ConsoleApplication();
	virtual ~ConsoleApplication() {}
	virtual int execute();
	Args const& get_args() const { return args_m; }
};