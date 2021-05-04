#pragma once
#include <set>

using namespace std;

class Observer {
public:
	virtual void update() = 0;
};

class Subject {
	set<Observer*> observers;
public:
	void attach(Observer* p) { observers.insert(p); }
	void detach(Observer* p) { observers.erase(p); }
	void notify() {
		for (auto observer : observers) {
			observer->update();
		}
	}
};

class Command {
public:
	virtual ~Command() {}

	virtual void execute() = 0;
};