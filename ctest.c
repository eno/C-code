#include <stdio.h>

main()
{int i;
    int k;
    int a;
    int b,c,d,e,f,g; 
    printf("This is a table of increasing and decreasing values\n");

    for(i=1;i<=20;i++){
        printf("i= %d 20-i= %d\n",i,20-i);
    }

    printf("Table is done. Final value of i is %d\n",i);
    printf("input your age\n");
    scanf("%d",&k);
    printf("You are %d years old\n",k);
    a=10;
    b=12;
    c=3;
    k= (1-(a<b)) || !(b>c) ;
    if(k)printf("k true\n");
    else printf("k false\n");
    a= (5>4) +5;
    printf("(5>4)= %d a=%d\n",(5>4),a);
    a=10;
    b=12;
    c=a&b;
    d=a|b;
    e=a^b;
    f=a>>2;
    g=a<<2;
    printf("c=%d d=%d e=%d f=%d g=%d\n",c,d,e,f,g);
    while (a>0){
        printf("input an positive integer to continue, or non-positive integer to stop\n");
        scanf("%d",&a);
        if(a%2==0)printf("a is even, a=%d\n",a);
        else printf("a is odd, a=%d\n",a);
    }

}

