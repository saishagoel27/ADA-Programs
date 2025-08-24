#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int counter = 5;
    while (counter > 0)
    {
        int size;
        cout << "Enter size: ";
        cin >> size;
        srand(time(0));
        int* arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 1000 + 1;
        }

        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, size - 1);
        auto stop = high_resolution_clock::now();

        cout << "Sorted Array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time in microseconds: " << duration.count() << endl;

        delete[] arr;
        counter--;
    }
    return 0;
}
