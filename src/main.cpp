#include <iostream>

int getMax(int* arr, int n);
void countSort(int* arr, int a);

int main()
{
    int n = 7;

    int* arr = new int[n] {1, 0, 0, 3, 2, 5, 2};

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    countSort(arr, n);

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;


    return 0;
}

int getMax(int* arr, int n)
{
    int max = arr[0];

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void countSort(int* arr, int n)
{
    int max = getMax(arr, n);

    //Step 1
    int* count = new int[max + 1];
    int* output = new int[n];

    for (size_t i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    //Step 2

    for (size_t i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    //Step 3
   
    int j = 0;
    for (int i = 0; i <= max; ++i)
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
    }
}