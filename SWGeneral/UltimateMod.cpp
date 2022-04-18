﻿#include <chrono>
#include <iostream>
#include <vector>

#include "substance/UMSubstance.h"
#include "window/WindowPainterGlut.h"

std::vector<std::shared_ptr<UMSubstance> > substancesList;

int main(int argc, char**argv) {
	for(int id = 0; id < 2; id++) {
		std::cout << id << std::endl;
		substancesList.push_back(std::make_shared<UMSubstance>(id));
		if(substancesList.back()->enableSubstance()) {
			Log() << "Enable";
		}
		Log() << std::this_thread::get_id();
	}

	std::unique_ptr<WindowPainterBase> window = std::make_unique<WindowPainterGlut>();
	window->createWindow(argc, argv);
	while(true) {

	}
	// Signal<int> _myEvent;
	// _myEvent.connect(&testFunction);
	// for(int i = 0; i < 100000; i++) {
	// 	_myEvent.emit(std::move(i));
	// }
	return 0;
}
