
#include <stdlib.h>
#include <stdio.h>


int main(void)

{


    FILE *my_fp ;

    char readbuf[80];



if ((my_fp = fopen("test.txt", "r"))== NULL){
    perror("fopen");
    exit(1);

}

while(fgets(readbuf, 80, my_fp))
    printf("%s", readbuf);
    
    return 0;
} 
