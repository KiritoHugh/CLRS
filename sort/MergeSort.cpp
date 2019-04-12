#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
// 给自己定下原则，以后涉及数组的程序，都按序号从1开始写，索引时候-1
// 以后排序默认稳定写法

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void Merge(int *input_array,int p,int q,int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int *L =(int*) malloc(sizeof(int)*(n1+1));
    int *R = (int*)malloc(sizeof(int)*(n2+1));
    for(int i=1;i<=n1;i++){
        L[i-1] = input_array[(p+i-1)-1];
    }
    for(int j = 1;j<=n2;j++){
        R[j-1] = input_array[(q+j)-1];
    }
    L[(n1+1)-1] = INT32_MAX;
    R[(n2+1)-1] = INT32_MAX;
    int i = 1;
    int j = 1;
    for(int k = p;k<=r;k++){
        if(L[i-1]<=R[j-1]){
            input_array[k-1] = L[i-1];
            i++;
        }
        else
        {
            input_array[k-1] = R[j-1];
            j++;
        }
        
    }

}

void MergeSort(int *input_array,int p,int r){
    if(p<r){
        int q = floor((p+r)/2);
        MergeSort(input_array,p,q);
        MergeSort(input_array,q+1,r);
        Merge(input_array,p,q,r);
    }

}

void test()
{
    int N = 200;
    int array[N];
    srand((unsigned)time(0));

    for (int i = 1; i <= N; i++)
    {
        array[i - 1] = rand();
    }
    for (int i = 1; i <= N; i++)
    {
        cout << array[i - 1] << ' ';
    }
    cout << endl;

    cout << array << endl;

    // sort(array,array+N);
    MergeSort(array, 1,N);
    for (int i = 1; i <= N; i++)
    {
        cout << array[i - 1] << ' ';
    }
    cout << endl;

    system("pause");
}

