#include "framework.h"

int main() {
	
	fw::init("data.bin");
	fw::mainloop();

	return 0;
}