#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char ***input;
    input=malloc(sizeof(char *)*3);
    input[0]=malloc(sizeof(char *)*3);
    input[0][0]="mustafa";
    input[0][1]="emre";
    input[0][2]="yilmaz";

    printf("%p\n",input[0][0]);
    printf("%p\n",input[0]);
    printf("%p\n",input);

} 