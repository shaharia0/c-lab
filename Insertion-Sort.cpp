#include<stdio.h>
main()
{
    int i,j,temp,k,n,p=1;

    printf("Declare Array Size:");
    scanf("%d",&n);

    int a[n];

    printf("Enter the Elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("The array is:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

    for(i=1;i<n;i++){
        temp = a[i];
        j=i;

        while(j>0&&temp<a[j-1]){
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=temp;
        printf("\nPass %d:",i);
        for(p=0;p<n;p++){
            printf("%d\t",a[p]);
        }
        printf("\n");
    }

    printf("The sorted array is:\n");
    for(k=0;k<n;k++){
        printf("%d\t",a[k]);
    }

}
