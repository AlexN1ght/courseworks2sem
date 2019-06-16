#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float d_gen(void)
{
    float out = (float)(rand() % 100);
    float len = (float)0.1;
    for(int i = 0; i < 5; i++) {
        out += (float)(rand() % 10) * len;
        len /= 10;
    }
    return out;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    if(argc != 2) {
        return 1;
    }
    printf("%s\n", argv[1]);
    for(int i = 0; i < atoi(argv[1]); i++) {
        printf("%f %d%s\n", d_gen(),i ,"hello");
    }
    return 0;
}
