#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& arr, int k, long long limit) {
    long long currentSum = 0;
    int parts = 1;

    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        if (x > limit) return false;

        if (currentSum + x <= limit) {
            currentSum += x;
        } else {
            parts++;
            currentSum = x;
        }

        if (parts > k) return false;
    }
    return true;
}

long long minimizeMaxSum(vector<int>& arr, int k) {
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canSplit(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "Answer = " << minimizeMaxSum(arr,k)<<endl;
}