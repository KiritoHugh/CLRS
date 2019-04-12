#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void max_heapify(int *input_array, int index, int input_len)
{
    int l = index * 2; //不必存值,存下标即可
    int r = index * 2 + 1;
    int largest = index;
    if (l <= input_len && input_array[l - 1] > input_array[index - 1])
    {
        largest = l;
    }
    if (r <= input_len && input_array[r - 1] > input_array[largest - 1]) //你之前把largest写成了index，无脑！
    {
        largest = r;
    }
    if (largest != index) //这也丢掉了
    {
        swap(input_array[index - 1],input_array[largest - 1]);
        max_heapify(input_array, largest, input_len);
    }
    return;
}

void R_build_max_heap(int *input_array, int index, int input_len)
{
    int l = index * 2;
    int r = index * 2 + 1;

    if (l > input_len)
    {
        return;
    }
    else if (l == input_len)
    {
        // R_build_max_heap(input_array,l,input_len);
        max_heapify(input_array, index, input_len); //这句也丢掉了
        return;
    }
    else
    {
        R_build_max_heap(input_array, l, input_len);
        R_build_max_heap(input_array, r, input_len);
        max_heapify(input_array, index, input_len);
        return;
    }
}

void build_max_heap(int *input_array, int input_len)
{
    for (int i = floor(input_len / 2); i >= 1; i--)
    {
        max_heapify(input_array, i, input_len);
    }
    return;
}

void HeapSort(int *input_array, int input_len)
{

    build_max_heap(input_array, input_len);
    for (int i = input_len; i >= 2; i--)
    {
        swap(input_array[0] ,input_array[i-1]);
        max_heapify(input_array, 1, i - 1);
    }
}

void test()
{
    int N = 60;
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
    HeapSort(array, N);
    for (int i = 1; i <= N; i++)
    {
        cout << array[i - 1] << ' ';
    }
    cout << endl;
    system("pause");
}