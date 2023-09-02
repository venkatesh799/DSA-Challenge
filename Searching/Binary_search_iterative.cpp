#include <iostream>
#include <vector>
using namespace std;
int bsearch1(vector<int> list, int size, int key) {
    int mid;
    int start = 0;
    int end = size;
    while(start <= end) {
        mid = (start + end)/2;
        if(list[mid] == key) {
            return mid;
        }
        else if(key > list[mid]) {
            start = mid + 1;
        }
        else if(key < list[mid]) {
            end = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> vet{10, 20, 30, 50, 50};
    cout<<"Element found at: "<<bsearch1(vet, vet.size(), 220);
    return 0;
}

// Best case: O(1)
// Worst Case: O(LogN)
