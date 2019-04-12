#include <iostream>
// #include <math.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

void swap(int &a, int &b)
{
    if (a == b)
    {
        return;
    }
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void Merge(int *input_array, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc(sizeof(int) * (n1 + 1));
    int *R = (int *)malloc(sizeof(int) * (n2 + 1));
    for (int i = 1; i <= n1; i++)
    {
        L[i - 1] = input_array[(p + i - 1) - 1];
    }
    for (int j = 1; j <= n2; j++)
    {
        R[j - 1] = input_array[(q + j) - 1];
    }
    L[(n1 + 1) - 1] = INT32_MAX;
    R[(n2 + 1) - 1] = INT32_MAX;
    int i = 1;
    int j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i - 1] <= R[j - 1])
        {
            input_array[k - 1] = L[i - 1];
            i++;
        }
        else
        {
            input_array[k - 1] = R[j - 1];
            j++;
        }
    }
}

void MergeSort(int *input_array, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        MergeSort(input_array, p, q);
        MergeSort(input_array, q + 1, r);
        Merge(input_array, p, q, r);
    }
}

int partition(int *inputarray, int p, int r)
{
    int x = inputarray[r - 1];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (inputarray[j - 1] <= x)
        {
            i++;
            swap(inputarray[i - 1], inputarray[j - 1]);
        }
    }
    swap(inputarray[(i + 1) - 1], inputarray[r - 1]);
    return i + 1;
}

void Quicksort(int *inputarray, int p, int r)
{
    if (p < r)
    {
        int q = partition(inputarray, p, r);
        Quicksort(inputarray, p, q - 1);
        Quicksort(inputarray, q + 1, r);
    }
}

void Insertsort(int *inputarray, int len)
{
    for (int j = 2; j <= len; j++)
    {
        int key = inputarray[j - 1];
        int i = j - 1;
        while (i > 0 && inputarray[i - 1] > key)
        {
            inputarray[(i + 1) - 1] = inputarray[i - 1];
            i--;
        }
        inputarray[(i + 1) - 1] = key;
    }
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
        swap(input_array[index - 1], input_array[largest - 1]);
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
        swap(input_array[0], input_array[i - 1]);
        max_heapify(input_array, 1, i - 1);
    }
}

void revive(int *array, int *bk, int N)
{
    for (int i = 1; i <= N; i++)
    {
        array[i - 1] = bk[i - 1];
    }
}

int main()
{

    const int N = 60000;
    int array[N];
    int bk_array[N];

    clock_t begin, end;

    int number[7] = {100, 10000, 50000, 100000, 200000, 500000, 1000000};
    // 100 10, 50, 100, 200, 500, 1000,
    random_device rd;
    uniform_int_distribution<int> dist(0, 50000);

    for (int t = 1; t <= 10; t++)
    {

        cout << "QuickSort"
             << "\t"
             << "HeapSort"
             << "\t"
             << "MergeSort"
             << "\t"
             << "InsertSort" << endl;

        for (int i = 1; i <= N; i++)
        {
            array[i - 1] = dist(rd);
            bk_array[i - 1] = array[i - 1];
        }
        for (int num = 1; num <= 3; num++)
        {

            begin = clock();
            Quicksort(array, 1, number[num - 1]); //
            end = clock();
            cout << (end - begin)*1.0 / CLOCKS_PER_SEC << "\t";

            revive(array, bk_array, number[num - 1]);

            begin = clock();
            HeapSort(array, number[num - 1]); //
            end = clock();
            cout << (double)(end - begin) / CLOCKS_PER_SEC << "\t";

            revive(array, bk_array, number[num - 1]);

            begin = clock();
            MergeSort(array, 1, number[num - 1]); //
            end = clock();
            cout << (double)(end - begin) / CLOCKS_PER_SEC << "\t";

            revive(array, bk_array, number[num - 1]);

            begin = clock();
            Insertsort(array, number[num - 1]); //
            end = clock();
            cout << (double)(end - begin) / CLOCKS_PER_SEC << "\t";

            revive(array, bk_array, number[num - 1]);

            cout << endl;
        }
    }
    system("pause");
}