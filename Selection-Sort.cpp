#include<stdio.h>

main()
{
    int n,i,j,temp,k,swap,l;

    printf("Declare Array Size:");
    scanf("%d",&n);

    int a[n];

    printf("Enter the Elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("The Array Is:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

    for(i=0;i<n-1;i++){
        temp = a[i];
        k=i;

        for(j=i+1;j<n;j++){
            if(temp>a[j]){
                temp = a[j];
                k = j;

            }
                //k=j;
        }

        if(k!=i){
            swap=a[i];
            a[i]=temp;
            a[k]=swap;
        }

        printf("\nPass %d:",i);
        for(l=0;l<n;l++){
            printf("%d\t",a[l]);
        }

    }
          printf("\nThe sorted array is:");
    for(l=0;l<n;l++){
        printf("%d\t",a[l]);

    }
}
