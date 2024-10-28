## A07 - Priority Queezy
### Victor Marchesi

## Description

- This weeks assignment is focusing on Priority Queues (remember min heap, max heap are basically synonyms for a PQ).
- Queues typically are FIFO, and PQ's still are accept based on a "priority" you could get to move closer to the front or get passed up.
- [LINK](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/07-A07) to the github instructions.
- I chose [P703 - Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./p703.pdf) | PDF instructions for P703 - Kth Largest Element in a Stream. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P703 - Kth Largest Element in a Stream. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P703 - Kth Largest Element in a Stream. |

### Solution in C++
```c++
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the k largest elements
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num); // Initialize by adding each element from nums
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // Keep only k elements in the heap
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        // The k-th largest element is the top of the heap
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */