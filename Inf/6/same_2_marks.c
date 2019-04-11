#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "enrollee.h"


int main(int argc, char* argv[])
{
    if (argc < 2) {
        perror("Usage: s_2_m [-f] dumb_file [result_file]\n");
        return 1;
    }
	
	int print = 0;
	
	if (strcmp(argv[1], "-f") == 0) {
		print = 1;
	}
	
    enrollee e;
    FILE *in = fopen(argv[1 + print], "r");
    if (!in) {
        perror("Can't open the fileTTTTTTTTT");
        printf("%s %d\n", argv[1 + print], print);
        return 2;
    }
    FILE *out = fopen(argv[2 + print], "w");
    if (!in && argv[2 + print]) {
        perror("Can't open the fileNNNNNNNNNNNNN");
        return 2;
    }
    while (fread(&e, sizeof(e), 1, in) == 1) {
        if (e.sex == 'f') {
            if (e.exam_1 == e.exam_2 || e.exam_2 == e.exam_3 || e.exam_1 == e.exam_3) {
            	if (argv[2 + print]) {
            		fprintf(out, "%s\n", e.name);
            	}
            	if (print) {
            		printf("%s\n", e.name);
            	}
            }
        }
    }
    return 0;
}
