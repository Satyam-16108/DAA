#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int insertionSort(vector<int>& arr) {
    int comparisons = 0;
    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comparisons = insertionSort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    return 0;
}
