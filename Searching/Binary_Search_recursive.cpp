#include <iostream>
#include <vector>
using namespace std;
int bsearch1(vector<int> list, int key, int start, int end) {
    if(start > end) {
        return -1;
    }
    int mid;
    mid = start + (end - start)/2;
    if(list[mid] == key) {
        return mid;
    }
    else if(key > list[mid]) {
        return bsearch1(list, key, mid+1, end);
    }
    else if(key < list[mid]) {
        return bsearch1(list, key, start, mid-1);
    }
    return -1;
}
int main() {
    vector<int> vet{10, 20, 30, 50, 50};
    cout<<"Element found at: "<<bsearch1(vet, 590, 0, vet.size()-1);
    return 0;
}
