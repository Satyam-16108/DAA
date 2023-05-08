#include <iostream>
#include <vector>

using namespace std;

int heapify(vector<int>& arr, int n, int i, int& comparisons) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[i], arr[largest]);
        comparisons++;
        heapify(arr, n, largest, comparisons);
    }
    return comparisons;
}

int heapSort(vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        comparisons++;
        heapify(arr, i, 0, comparisons);
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = heapSort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    return 0;
}
