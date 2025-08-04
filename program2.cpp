#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
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
    int counter = 5;
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
        auto start = high_resolution_clock::now();
            quickSort(arr, 0, size - 1);
         auto stop = high_resolution_clock::now();
        cout << "Sorted Array:"<<endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time in microseconds: " << duration.count() << endl;
        counter--;
    }
    return 0;
}
