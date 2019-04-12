#include <iostream>
#include <random>

using namespace std;

int main()
{
    const int N = 60000;
    int array[N];
    random_device rd;
    uniform_int_distribution<int> dist(0, 50000);

    for (int num = 1; num <= 3; num++)
    {
        for (int i = 1; i <= N; i++)
        {
            array[i - 1] = dist(rd);
        }
        for (int i = 1; i <= 20; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}