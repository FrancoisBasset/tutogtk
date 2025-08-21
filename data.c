#include <string.h>
#include "data.h"

char* word;

Data getData(int argc, char** argv) {
    Data data;

	if (argc == 2) {
		data.firstname = strdup(argv[1]);
	} else {
		data.firstname = strdup("unknown");
	}

    return data;
}
