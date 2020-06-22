#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[5] = "0123", b[5] = "head";
    char c[20];
    scanf("%s", c);

    if(strlen(c) < 5){
	    strcpy(b, a);
	    strcpy(a, c);
    }
    else{
	    strcpy(a, b);
    }
    
    printf("a[]=<%s>\n", a);
    printf("b[]=<%s>\n", b);

    return 0;
}
