#include <iostream>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }
    swap(arr[i + 1], arr[high]);
    comparisons++;
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int low, int high, int& comparisons) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    int randomIndex = dis(gen);
    swap(arr[randomIndex], arr[high]);
    comparisons++;
    return partition(arr, low, high, comparisons);
}

int randomizedQuickSort(vector<int>& arr, int low, int high, int& comparisons) {
    if(low < high) {
        int pi = randomizedPartition(arr, low, high, comparisons);
        randomizedQuickSort(arr, low, pi - 1, comparisons);
        randomizedQuickSort(arr, pi + 1, high, comparisons);
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = 0;
    comparisons = randomizedQuickSort(arr, 0, arr.size() - 1, comparisons);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    return 0;
}
