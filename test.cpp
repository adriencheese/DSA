#include <iostream>
#include <vector>

using namespace std;

int main() {

    int left = 0; 
    int right = arr.size()-1;
    
    while (left <= right) {
        int mid = (left + (right-left))/2;
        
        if (arr[mid] == true && arr[mid-1] == false) {
            return mid;
        }
        
        if (arr[mid] == true) {
            right = mid - 1;
        }
        
        else {
            left = mid + 1;
        }
    }
    return -1;
}