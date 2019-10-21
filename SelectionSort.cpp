{\rtf1\ansi\ansicpg1252\cocoartf2509
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;\f1\froman\fcharset0 Times-Roman;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl280\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include <bits/stdc++.h> 
\f1 \

\f0 using
\f1  
\f0 namespace
\f1  
\f0 std; 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 void
\f1  
\f0 swap(int
\f1  
\f0 *xp, int
\f1  
\f0 *yp)\'a0 
\f1 \

\f0 \{\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 temp = *xp;\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0*xp = *yp;\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0*yp = temp;\'a0 
\f1 \

\f0 \}\'a0 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 void
\f1  
\f0 selectionSort(int
\f1  
\f0 arr[], int
\f1  
\f0 n)\'a0 
\f1 \

\f0 \{\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 i, j, min_idx;\'a0 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 \'a0\'a0\'a0\'a0// One by one move boundary of unsorted subarray\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0for
\f1  
\f0 (i = 0; i < n-1; i++)\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\{\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0// Find the minimum element in unsorted array\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0min_idx = i;\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0for
\f1  
\f0 (j = i+1; j < n; j++)\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0if
\f1  
\f0 (arr[j] < arr[min_idx])\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0min_idx = j;\'a0 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0// Swap the found minimum element with the first element\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0swap(&arr[min_idx], &arr[i]);\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\}\'a0 
\f1 \

\f0 \}\'a0 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 /* Function to print an array */
\f1 \

\f0 void
\f1  
\f0 printArray(int
\f1  
\f0 arr[], int
\f1  
\f0 size)\'a0 
\f1 \

\f0 \{\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 i;\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0for
\f1  
\f0 (i=0; i < size; i++)\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0cout << arr[i] << " ";\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0cout << endl;\'a0 
\f1 \

\f0 \}\'a0 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 // Driver program to test above functions\'a0 
\f1 \

\f0 int
\f1  
\f0 main()\'a0 
\f1 \

\f0 \{\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 arr[] = \{64, 25, 12, 22, 11\};\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 n = sizeof(arr)/sizeof(arr[0]);\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0selectionSort(arr, n);\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0cout << "Sorted array: \\n";\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0printArray(arr, n);\'a0 
\f1 \

\f0 \'a0\'a0\'a0\'a0return
\f1  
\f0 0;\'a0 
\f1 \

\f0 \}\'a0 
\f1 \
}