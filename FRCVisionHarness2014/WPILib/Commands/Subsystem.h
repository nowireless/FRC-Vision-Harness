#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H
#include <iostream>


class Subsystem {
private:
public:
	Subsystem(const char *subsystem) {
		printf("%s\n", subsystem);
	}
};

#endif