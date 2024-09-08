#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = static_cast<int>(arr.size());
    bool sorted = false;
    for (int i = 0; i < n; i++) {
        sorted = true;
        for (int j = 1; j < n - i; j++) {
            if (arr[j] < arr[j - 1]) {
                sorted = false;
                swap(arr[j], arr[j - 1]);
            }
        }

        if (sorted) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    bubbleSort(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
