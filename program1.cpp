#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
bool RecursiveBinarySearch(int arr[], int lb, int ub, int key)
{
    if (lb > ub)
        return false;
    int mid = lb + (ub - lb) / 2;
    if (arr[mid] == key)
        return true;
    else if (arr[mid] < key)
        return RecursiveBinarySearch(arr, mid + 1, ub, key);
    else
        return RecursiveBinarySearch(arr, lb, mid - 1, key);
}
void BinarySearch(int arr[], int size, int key)
{
    bool found = RecursiveBinarySearch(arr, 0, size - 1, key);
    if (found)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        int t = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = t;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int counter = 4;
    while (counter > 0)
    {
        int size;
        cout << "Enter size: ";
        cin >> size;
        srand(time(0));
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 1000 + 1;
        }
        quickSort(arr, 0, size - 1);
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        int key;
        cout << "Enter key: ";
        cin >> key;
        auto start = high_resolution_clock::now();
        BinarySearch(arr, size, key);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time in microseconds: " << duration.count() << endl;
        counter--;
    }
    return 0;
}
