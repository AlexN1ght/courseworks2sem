#include <stdio.h>

#include "enrollee.h"


int main(int argc, char* argv[])
{
    if (argc != 2) {
        perror("No filepath");
        return 1;
    }

    enrollee e;
    FILE *in = fopen(argv[1], "r");
    if (!in) {
        perror("Can't open the file");
        return 2;
    }
    
    while (fread(&e, sizeof(e), 1, in) == 1) {
        if (e.sex == 'f') {
            if (e.exam_1 == e.exam_2 || e.exam_2 == e.exam_3 || e.exam_1 == e.exam_3) {
                printf("%s\n", e.name);
            }
        }
    }
    return 0;
}
