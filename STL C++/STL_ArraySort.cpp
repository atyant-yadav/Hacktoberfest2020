/*Before jumping on the implementation part we should know about the space and time complexity of our program.

The time complexity of std::sort() is:
1. Best Case – O(N log N)
2. Average Case – O(N log N)
3. Worst Case – O(N log N)

Space Complexity – It may use O( log N) auxiliary space.

*/

#include<bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
	           //Length of the array------------------------
	int n;
	cin>>n;

	           //Array declaration--------------------------
	int array[n];
	for(int i=0;i<n;i++)
		cin>>array[i];

	           //for sorting of the array in increasing order
	sort(array,array+n);

	           //for sorting of the array in decreasing order
	sort(array, array + n, greater<int>());

	          //printing the sorted array
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
		
	return 0;
}
