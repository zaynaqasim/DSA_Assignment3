#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// COUNTING SORT (NON-STABLE) 
void countingSortNonStable(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);

    // Count occurrences
    for (int num : arr) {
        count[num - minVal]++;
    }

    // Place elements back (non-stable: just fill in order)
    int idx = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[idx++] = i + minVal;
            count[i]--;
        }
    }
}

// COUNTING SORT (STABLE) 
void countingSortStable(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Count occurrences
    for (int num : arr) {
        count[num - minVal]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (traverse from right to maintain stability)
    for (int i = arr.size() - 1; i >= 0; i--) {
        int val = arr[i];
        output[count[val - minVal] - 1] = val;
        count[val - minVal]--;
    }

    // Copy back to original array
    arr = output;
}

// HELPER FOR RADIX SORT 
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

// LSD RADIX SORT 
void lsdRadixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    // Process each digit from least to most significant
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// BUCKET SORT 
void bucketSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Create buckets
    int numBuckets = sqrt(arr.size());
    if (numBuckets == 0) numBuckets = 1;

    vector<vector<int>> buckets(numBuckets);

    // Distribute elements into buckets
    for (int num : arr) {
        int bucketIdx = ((num - minVal) * numBuckets) / range;
        if (bucketIdx >= numBuckets) bucketIdx = numBuckets - 1;
        buckets[bucketIdx].push_back(num);
    }

    // Sort individual buckets using insertion sort
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    // Concatenate buckets
    int idx = 0;
    for (const auto& bucket : buckets) {
        for (int num : bucket) {
            arr[idx++] = num;
        }
    }
}

// MSD RADIX SORT HELPER 
int getDigit(int num, int digit, int base = 10) {
    return (num / static_cast<int>(pow(base, digit))) % base;
}

int getMaxDigits(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int maxVal = *max_element(arr.begin(), arr.end());
    int digits = 0;
    while (maxVal > 0) {
        digits++;
        maxVal /= 10;
    }
    return digits;
}

void msdRadixSortHelper(vector<int>& arr, int left, int right, int digit) {
    if (left >= right || digit < 0) return;

    vector<vector<int>> buckets(10);

    // Distribute into buckets based on current digit
    for (int i = left; i <= right; i++) {
        int d = getDigit(arr[i], digit);
        buckets[d].push_back(arr[i]);
    }

    // Place back and recursively sort each bucket
    int idx = left;
    for (int i = 0; i < 10; i++) {
        int start = idx;
        for (int num : buckets[i]) {
            arr[idx++] = num;
        }
        int end = idx - 1;

        // Recursively sort this bucket
        if (start < end) {
            msdRadixSortHelper(arr, start, end, digit - 1);
        }
    }
}

// MSD RADIX SORT 
void msdRadixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxDigits = getMaxDigits(arr);
    msdRadixSortHelper(arr, 0, arr.size() - 1, maxDigits - 1);
}

// TESTING & BENCHMARKING 
void printArray(const vector<int>& arr, int limit = 20) {
    cout << "[";
    for (int i = 0; i < min(limit, (int)arr.size()); i++) {
        cout << arr[i];
        if (i < min(limit, (int)arr.size()) - 1) cout << ", ";
    }
    if (arr.size() > limit) cout << " ...";
    cout << "]" << endl;
}

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

template<typename Func>
double measureTime(Func sortFunc, vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;
    return elapsed.count();
}

vector<int> generateRandomArray(int size, int maxVal) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, maxVal);

    for (int& num : arr) {
        num = dis(gen);
    }
    return arr;
}

vector<int> generateSortedArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

vector<int> generateReverseSortedArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

int main() {
    cout << " Non-Comparison Sorting Algorithms " << endl << endl;

    // Test Case 1: Small array
    cout << "Test 1: Small Random Array" << endl;
    vector<int> test1 = { 64, 34, 25, 12, 22, 11, 90, 88, 45, 50 };
    cout << "Original: "; printArray(test1);

    vector<int> temp = test1;
    countingSortNonStable(temp);
    cout << "Counting Sort (Non-Stable): "; printArray(temp);
    cout << "Sorted: " << (isSorted(temp) ? "YES" : "NO") << endl << endl;

    temp = test1;
    countingSortStable(temp);
    cout << "Counting Sort (Stable): "; printArray(temp);
    cout << "Sorted: " << (isSorted(temp) ? "YES" : "NO") << endl << endl;

    temp = test1;
    lsdRadixSort(temp);
    cout << "LSD Radix Sort: "; printArray(temp);
    cout << "Sorted: " << (isSorted(temp) ? "YES" : "NO") << endl << endl;

    temp = test1;
    bucketSort(temp);
    cout << "Bucket Sort: "; printArray(temp);
    cout << "Sorted: " << (isSorted(temp) ? "YES" : "NO") << endl << endl;

    temp = test1;
    msdRadixSort(temp);
    cout << "MSD Radix Sort: "; printArray(temp);
    cout << "Sorted: " << (isSorted(temp) ? "YES" : "NO") << endl << endl;

    // Benchmark Tests
    cout << " Performance Benchmarks " << endl << endl;

    vector<int> sizes = { 1000, 5000, 10000, 50000 };

    for (int size : sizes) {
        cout << "Array Size: " << size << endl;

        vector<int> arr = generateRandomArray(size, size * 10);

        cout << fixed << setprecision(2);
        cout << "Counting Sort (Non-Stable): " << measureTime(countingSortNonStable, arr) << " ms" << endl;
        cout << "Counting Sort (Stable):     " << measureTime(countingSortStable, arr) << " ms" << endl;
        cout << "LSD Radix Sort:             " << measureTime(lsdRadixSort, arr) << " ms" << endl;
        cout << "Bucket Sort:                " << measureTime(bucketSort, arr) << " ms" << endl;
        cout << "MSD Radix Sort:             " << measureTime(msdRadixSort, arr) << " ms" << endl;
        cout << endl;
    }

    return 0;
}