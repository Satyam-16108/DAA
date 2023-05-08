#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int>& arr) {
    int max = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int getDigit(int num, int d) {
    for(int i = 1; i < d; i++) {
        num /= 10;
    }
    return num % 10;
}

void countingSort(vector<int>& arr, int exp) {
    vector<int> count(10, 0);
    vector<int> output(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        count[getDigit(arr[i], exp)]++;
    }
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for(int i = arr.size() - 1; i >= 0; i--) {
        output[count[getDigit(arr[i], exp)] - 1] = arr[i];
        count[getDigit(arr[i], exp)]--;
    }
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int radixSort(vector<int>& arr) {
    int comparisons = 0;
    int max = getMax(arr);
    for(int exp = 1; max/exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
    return comparisons;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int comparisons = radixSort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    return 0;
}
