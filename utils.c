#include <stdio.h>
#include <stdlib.h>

char* getSentence(char* name) {
	char* s = malloc(sizeof(char) * 50);
	sprintf(s, "Hello %s", name);

	return s;
}