#include <stdio.h>
#include <stdlib.h>

int comp(const void *p1,const void *p2);
int binarysearch(int *a,int size,int val);

int main()
{
    int val;
    int flag;
    int a[15]={84,48,68,10,18,98,12,23,54,57,33,16,77,11,29};

    puts("排序前数组：\n");
    for (int i = 0; i < 15; ++i) printf("%d\t",a[i]);
    qsort(a,15, sizeof(int),comp);//对数组排序
    puts("\n排序后数组：\n");
    for (int i = 0; i < 15; ++i) printf("%d\t",a[i]);
    printf("\n输入待查找值：\n");
    scanf("%d",&val);
    flag=binarysearch(a,15,val);
    if(flag<0) printf("待查找值不存在于数组中\n");
    else printf("待查找值的下标为%d.\n",flag);
    puts("Done!");

    return 0;
}

int comp(const void *p1,const void *p2)
{
    int a=*(const int *)p1;
    int b=*(const int *)p2;

    return a-b;
}

int binarysearch(int *a,int size,int val)
{
    int lo=0;
    int hi=size-1;
    while (lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(a[mid]>val) hi=mid-1;
        else if(a[mid]<val) lo=mid+1;
        else return mid;
    }
    return -1;
}