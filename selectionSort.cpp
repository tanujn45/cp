#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr) {
    int minIdx = 0;
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; i++) {
        minIdx = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    vector<int> arr = {7, 5, 9, 2, 8};

    selectionSort(arr);
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}
