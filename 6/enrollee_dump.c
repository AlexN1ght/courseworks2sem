#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include "enrollee.h"


int readEnrollee(enrollee *e)
{
    return scanf("%[^\t]\t%c\t%u\t%c\t%u\t%u\t%u\t%c\n", e->name, &e->sex, &e->school, &e->medal,&e->exam_1, &e->exam_2, &e->exam_3, &e->essay) == 8;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        perror("No filename");
        return 1;
    }

    enrollee e;
    FILE *out = fopen(argv[1], "w+");
    if (!out) {
        perror("Can't open or create the file");
        return 2;
    }
    while (readEnrollee(&e)) {
        fwrite(&e, sizeof(e), 1, out);
    }

    fseek(out, 0, SEEK_SET);
    while (fread(&e, sizeof(e), 1, out) == 1) {
        printf("%s\t%c\t%u\t%c\t%u\t%u\t%u\t%c\n", e.name, e.sex, e.school, e.medal, e.exam_1, e.exam_2, e.exam_3, e.essay);
    }

    return 0;
}
