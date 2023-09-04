/*
Given a sorted array of n elements, possibly with duplicates, find the number of occurrences of the target element.

Example 1:

Input: arr = [4, 4, 8, 8, 8, 15, 16, 23, 23, 42], target = 8
Output: 3
Example 2:

Input: arr = [3, 5, 5, 5, 5, 7, 8, 8], target = 6
Output: 0
Example 3:

Input: arr = [3, 5, 5, 5, 5, 7, 8, 8], target = 5
Output: 4
*/

//Count occurrences of a number in a sorted array with duplicates using Binary Search
using namespace std;
#include <iostream>
#include <vector>
int count_of_occurrences(vector<int> a, int target, int start, int end, bool first) {
    int result = -1;
    int mid = 0;
    while(start <= end) {
        mid = start + (end - start)/2;
        if(a[mid] == target) {
            result = mid;
            if(first) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        else if(target > a[mid]) {
            start = mid + 1;
        }
        else if(target < a[mid]) {
            end = mid - 1;
        }
    }
    return result;
} 

int main() {
    vector<int> v = {3, 5, 5, 5, 5, 7, 8, 8, 8, 8};
    int target = 8;
    int first = -1;
    int last = -1;
    first = count_of_occurrences(v, target, 0, v.size() - 1, true);
    if(first == -1) {
        cout<<target<<" not found:";
        return 0;
    } 
    last = count_of_occurrences(v, target, 0, v.size() - 1, false);
    cout<<"Count of "<<target<<" is: "<<(last - first)+1;
    return 0;
}
