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