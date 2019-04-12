#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int partition(int *inputarray,int p,int r){
    int x = inputarray[r-1];
    int i = p-1;
    for(int j = p;j<=r-1;j++){
        if(inputarray[j-1] <= x){
            i++;
            swap(inputarray[i-1],inputarray[j-1]);
        }
    }
    swap(inputarray[(i+1)-1],inputarray[r-1]);
    return i+1;
}

void Quicksort(int *inputarray,int p ,int r){
    if(p<r){
        int q = partition(inputarray,p,r);
        Quicksort(inputarray,p,q-1);
        Quicksort(inputarray,q+1,r);
    }
}

void test()
{
    const int N = 100000;
    int array[N];
    srand((unsigned)time(0));

    for (int i = 1; i <= N; i++)
    {
        array[i - 1] = rand();
    }
    for (int i = 49900; i <= 50000; i++)
    {
        cout << array[i - 1] << ' ';
    }
    cout << endl;

    cout << array << endl;

    // sort(array,array+N);
    Quicksort(array, 1,N);
    for (int i = 49900; i <= 50000; i++)
    {
        cout << array[i - 1] << ' ';
    }
    cout << endl;

    system("pause");
}
int main(){
    test();
}