#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int left, int mid, int right, int& comparisons) {
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);
    while(i <= mid && j <= right) {
        comparisons++;
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int l = left; l <= right; l++) {
        arr[l] = temp[l - left];
    }
    return comparisons;
}

int mergeSort(vector<int>& arr, int left, int right, int& comparisons) {
    if(left >= right) {
        return comparisons;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, comparisons);
    mergeSort(arr, mid + 1, right, comparisons);
    merge(arr, left, mid, right, comparisons);
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = 0;
    comparisons = mergeSort(arr, 0, arr.size() - 1, comparisons);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    return 0;
}
