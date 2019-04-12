#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

void Insertsort(int *inputarray,int len){
    for(int j=2;j<= len;j++){
        int key = inputarray[j-1];
        int i = j - 1;
        while(i>0&&inputarray[i-1]>key){
            inputarray[(i+1)-1] = inputarray[i-1];
            i--;
        }
        inputarray[(i+1)-1] = key;
    }
}

void test()
{
    int N = 10;
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
    Insertsort(array, N);
    for (int i = 1; i <= N; i++)
    {
        cout << array[i - 1] << ' ';
    }
    cout << endl;

    system("pause");
}
