// https://leetcode.com/problems/sort-an-array/description/
// Zubin Shah

// Heap Sort
class Solution {
public:
    void heapify(vector<int> &nums,int index,int n){
        int parent = index;
        int largestChild = -1;
        int leftChild = parent*2+1;
        int rightChild = parent*2+2;
        if(leftChild<n && nums[leftChild]>nums[parent]) largestChild = leftChild;
        if(rightChild<n) {
            if(largestChild==-1){
                if(nums[rightChild]>nums[parent]) largestChild = rightChild;
            }
            else if(nums[rightChild]>nums[largestChild]) largestChild = rightChild;
        }
        if(largestChild!=-1){
            swap(nums[index],nums[largestChild]);
            heapify(nums,largestChild,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }

        for(int i = n-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }
        return nums;
    }
};