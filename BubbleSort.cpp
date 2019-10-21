{\rtf1\ansi\ansicpg1252\cocoartf2509
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;\f1\froman\fcharset0 Times-Roman;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl280\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include <stdio.h> 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 void
\f1  
\f0 swap(int
\f1  
\f0 *xp, int
\f1  
\f0 *yp) 
\f1 \

\f0 \{ 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 temp = *xp; 
\f1 \

\f0 \'a0\'a0\'a0\'a0*xp = *yp; 
\f1 \

\f0 \'a0\'a0\'a0\'a0*yp = temp; 
\f1 \

\f0 \} 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 // An optimized version of Bubble Sort 
\f1 \

\f0 void
\f1  
\f0 bubbleSort(int
\f1  
\f0 arr[], int
\f1  
\f0 n) 
\f1 \

\f0 \{ 
\f1 \

\f0 \'a0\'a0\'a0int
\f1  
\f0 i, j; 
\f1 \

\f0 \'a0\'a0\'a0bool
\f1  
\f0 swapped; 
\f1 \

\f0 \'a0\'a0\'a0for
\f1  
\f0 (i = 0; i < n-1; i++) 
\f1 \

\f0 \'a0\'a0\'a0\{ 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0swapped = false; 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0for
\f1  
\f0 (j = 0; j < n-i-1; j++) 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\{ 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0if
\f1  
\f0 (arr[j] > arr[j+1]) 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\{ 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0swap(&arr[j], &arr[j+1]); 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0swapped = true; 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0\} 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\} 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 \'a0\'a0\'a0\'a0\'a0// IF no two elements were swapped by inner loop, then break 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0if
\f1  
\f0 (swapped == false) 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0break; 
\f1 \

\f0 \'a0\'a0\'a0\} 
\f1 \

\f0 \} 
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
\f0 size) 
\f1 \

\f0 \{ 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 i; 
\f1 \

\f0 \'a0\'a0\'a0\'a0for
\f1  
\f0 (i=0; i < size; i++) 
\f1 \

\f0 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0printf("%d ", arr[i]); 
\f1 \

\f0 \'a0\'a0\'a0\'a0printf("n"); 
\f1 \

\f0 \} 
\f1 \

\f0 \'a0
\f1 \'a0\

\f0 // Driver program to test above functions 
\f1 \

\f0 int
\f1  
\f0 main() 
\f1 \

\f0 \{ 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 arr[] = \{64, 34, 25, 12, 22, 11, 90\}; 
\f1 \

\f0 \'a0\'a0\'a0\'a0int
\f1  
\f0 n = sizeof(arr)/sizeof(arr[0]); 
\f1 \

\f0 \'a0\'a0\'a0\'a0bubbleSort(arr, n); 
\f1 \

\f0 \'a0\'a0\'a0\'a0printf("Sorted array: \\n"); 
\f1 \

\f0 \'a0\'a0\'a0\'a0printArray(arr, n); 
\f1 \

\f0 \'a0\'a0\'a0\'a0return
\f1  
\f0 0; 
\f1 \

\f0 \} 
\f1 \
}