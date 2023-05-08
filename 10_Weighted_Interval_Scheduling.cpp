#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    int weight;
};

bool compare(Interval i1, Interval i2) {
    return i1.end < i2.end;
}

int binarySearch(vector<Interval> intervals, int index) {
    int low = 0;
    int high = index - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(intervals[mid].end <= intervals[index].start) {
            if(intervals[mid + 1].end <= intervals[index].start) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int weightedIntervalScheduling(vector<Interval> intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    vector<int> dp(intervals.size());
    dp[0] = intervals[0].weight;
    for(int i = 1; i < intervals.size(); i++) {
        int weight = intervals[i].weight;
        int index = binarySearch(intervals, i);
        if(index != -1) {
            weight += dp[index];
        }
        dp[i] = max(weight, dp[i - 1]);
    }
    return dp[intervals.size() - 1];
}

int main() {
    vector<Interval> intervals = {{0, 6, 2}, {1, 4, 3}, {3, 5, 1}, {3, 8, 4}, {4, 7, 2}, {5, 9, 3}, {6, 10, 1}, {8, 11, 2}};
    int result = weightedIntervalScheduling(intervals);
    cout << "Maximum Weight: " << result << endl;
    return 0;
}
