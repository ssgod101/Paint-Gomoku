/*
File Name: GomokuApp.cpp
Author: Bijan Khajavi
Date Last Modified: Apr 17, 2019
Purpose:
Used to setup MVC for Application and launch it.
*/

#include <ConsoleApp.hpp>
#include "GomokuController.hpp"

class GomokuApp : public ConsoleApplication {
	int execute() override{
		GomokuModel gm;
		GomokuController gc(gm);
		gm.attach(&gc);
		gm.run();
		return EXIT_SUCCESS;
	}
}GomokuApp;