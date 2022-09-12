#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n) time | O(n) space
int firstDuplicateValueHashTable(vector<int> &array) {
    unordered_map<int, bool> seen;// O(n) space
    for(int element : array) {// O(n) time
        if(seen.find(element) != seen.end()) {// O(1) time
            return element;
        }
        seen[element] = true;// O(time | O(1) space
    }
    return -1;
}

// O(n^2) time | O(1) space
int firstDuplicateValueNested(vector<int> &array) {
    int closestDuplicateIndex = INT16_MAX;// O(1) space
    for(int i = 0; i < array.size(); i++) {// O(n) time
        for(int j = i + 1; j < array.size(); j++) {// O(n) time NESTED
            if(array[i] == array[j]) {// O(1) time
                closestDuplicateIndex = min(closestDuplicateIndex, j);// O(1) time | O(1) space
            }
        }
    }
    if(closestDuplicateIndex == INT16_MAX) {// O(1) time
        return -1;
    }
    return array[closestDuplicateIndex];
}

// O(n) time | O(1) space
int firstDuplicateValueAbsoluteValue(vector<int> &array) {
    for(int element : array) {// O(n) time
        int absoluteValue = abs(element);// O(1) time | O(1) space
        if(array[absoluteValue - 1] < 0) {// O(1) time
            return absoluteValue;
        }
        array[absoluteValue - 1] *= -1;// O(1) time
    }
    return -1;
}

int main() {
    vector<int> input = {2, 1, 5, 2, 3, 3, 4};
    cout << firstDuplicateValueNested(input) << endl;
    cout << firstDuplicateValueHashTable(input) << endl;
    cout << firstDuplicateValueAbsoluteValue(input) << endl;

    return 0;
}
