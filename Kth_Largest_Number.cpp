#include<iostream>
#include<vector>
using namespace std;

void maxHeapify(vector<int>& nums, int i, int n) {
	int l = 2*i;
   int r = 2*i+1;
   int largest=i;
   if (l < n && nums[l] > nums[i])
   	largest=l;
   if (r < n && nums[r] > nums[largest])
   	largest=r;
   if (largest!= i)
   {
   	swap(nums[i],nums[largest]);
      maxHeapify(nums,largest,n);
   }
}

int findKthLargest(vector<int>& nums, int k) {
	int n = nums.size();
   for(int i = n/2; i >= 0; i--)
   	maxHeapify(nums, i , n);
   while(--k) {
   	nums[0] = nums[--n];
      maxHeapify(nums, 0, n);
   }
   return nums[0];
}

int main() {
	vector<int> l;
   int size, k, val;
   cin>>size>>k;
   for(int i=0; i < size; i++) {
		cin>>val;
      l.push_back(val);
   }
	val = findKthLargest(l,k);
   cout<<val;
   return 0;
}
