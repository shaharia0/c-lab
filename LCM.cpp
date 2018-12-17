#include<stdio.h>
main()
{
    int i,x,y,n,c,L,S,s;
    printf("Declare Array Size:");
    scanf("%d",&n);

    int a[n];

    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    s=a[0];
    for(i=1;i<n;i++){
        x=s;
        y=a[i];
        if(x>y){
            L=x;
            S=y;
        }
        else{
            L=y;
            S=x;
        }
        while(L%S!=0){
            c=L%S;
            L=S;
            S=c;
        }
        s=(x*y)/S;
    }

    printf("LCM is:%d",s);

    return 0;

}
