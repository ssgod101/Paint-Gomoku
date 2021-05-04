/*
File Name: PaintApp.cpp
Author: Bijan Khajavi
Date Last Modified: Feb 28, 2019
Purpose:
Contains all parameters and methods that relate to the Paint Application.
*/

//INSTRUCTIONS:
//Main
//sets eveything up and launches the model.run function

//model = SUBJECT
//Everything that the app uses for the program goes in the model
//Contains an instance of itself to check old values when model changes.
//
//Controller = Observer
//Event Handlers go in the controller
//Controller also contains handler functions that are called by the view that
//FINALLY calls the outer facade functions.
//
//View contains functions that are called by the controller that call
//a handler function in the controller.

#include <ConsoleApp.hpp>
#include "PaintController.hpp"

class PaintApp : public ConsoleApplication {
	int execute() override{
		PaintModel pm;
		PaintController pc(pm);
		pm.attach(&pc);
		pm.run();
		/*if (!program.setupConsole("Paint", WINDOW_WIDTH, WINDOW_HEIGHT)) {
			return EXIT_FAILURE;
		}
		program.paintAll(' ', BG_WHITE);
		program.waitForInput(&ProcessKeyEvent, &MouseEventProc);*/
		return EXIT_SUCCESS;
	}
}paintApp;


