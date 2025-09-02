#include <iostream>
using namespace std;

struct Item {
    int weight, value;
    float ratio; // value:weight ratio
};

// Function to swap two items
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Partition function for Quick Sort
int partition(Item arr[], int low, int high) {
    float pivot = arr[high].ratio;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].ratio > pivot) {  //sort in descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Greedy Knapsack function
float knapsack(Item items[], int n, int capacity) {
    // Sort items by value:weight ratio using quicksort
    quickSort(items, 0, n - 1);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            break; //Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    float maxValue = knapsack(items, n, capacity);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}