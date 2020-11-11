void BubbleSort(int A[], int size)
{       
	int swapped;
	for(int i=0; i<size; i++)
	{    swapped = 0;
		for(int j=0; j<size-1; j++)
		{
			if( A[j] > A[j+1] )
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				swapped = 1;
			}
		}
	       if(swapped == 0)
		       break;
	}
}
