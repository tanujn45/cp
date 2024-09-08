#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                continue;
            } 
            break;
        }
    }
}

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    insertionSort(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
