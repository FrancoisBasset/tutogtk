#ifndef DATA_H
#define DATA_H
#endif

extern char* word;

typedef struct {
	char* firstname;
} Data;

Data getData(int argc, char** argv);
