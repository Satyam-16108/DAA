#include <iostream>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    int randomIndex = dis(gen);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

int randomizedSelect(vector<int>& arr, int low, int high, int k) {
    if(low == high) {
        return arr[low];
    }
    int pivotIndex = randomizedPartition(arr, low, high);
    int leftLength = pivotIndex - low + 1;
    if(k == leftLength) {
        return arr[pivotIndex];
    } else if(k < leftLength) {
        return randomizedSelect(arr, low, pivotIndex - 1, k);
    } else {
        return randomizedSelect(arr, pivotIndex + 1, high, k - leftLength);
    }
}

int main() {
    vector<int> arr = {3, 2, 6, 4, 7, 5, 1};
    int k = 3;
    int result = randomizedSelect(arr, 0, arr.size() - 1, k);
    cout << "The " << k << "th smallest element is: " << result << endl;
    return 0;
}
