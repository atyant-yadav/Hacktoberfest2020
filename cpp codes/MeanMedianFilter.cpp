#include "stdafx.h"

#include <iostream>

#include <opencv2/core/core.hpp>

#include <opencv2/opencv.hpp>

#include<opencv2/imgproc/imgproc.hpp>

 

using namespace cv;

using namespace std;

 

void insertionSort(int arr[], int n)

{

    int i, key, j;

    for (i = 1; i < n; i++)

    {

        key = arr[i];

        j = i - 1;



        while (j >= 0 && arr[j] > key)

        {

            arr[j + 1] = arr[j];

            j = j - 1;

        }

        arr[j + 1] = key;

    }

}





int main(int argc, char *argv[])

{

    if (argc != 3) {

        printf("Enter exeFileName imageFileName\n");

    }



Mat image = imread(argv[1], IMREAD_COLOR);



    if (image.empty()) {

        cout << "Error: No Image to load" << endl;

    }



Mat gr(image.rows,image.cols,CV_8UC1,Scalar(0));

cvtColor(image,gr,COLOR_BGR2GRAY);



    Mat output = gr.clone();



    int a = atoi(argv[2]);

    int adj = a / 2;



   /* mean filter
   int sum = 0;

    int avg = 0;

    for (int i = adj; i < gr.rows - adj; i++) {

        for (int j = adj; j < gr.cols - adj; j++) {

            sum = 0;

            for (int g = i - adj; g <= i + adj; g++) {

                for (int h = j - adj; h <= j + adj; h++) {

                    sum= sum+(int)gr.at<uchar>(g, h);

                }

            }

            avg = sum / (a * a);

            output.at<uchar>(i, j) = (uchar)avg;

        }

    }*/

   

    int size = a * a;

    int* arr = new int[size];

    int index = 0;

    int middle = 0;

   

    for (int i = adj; i < gr.rows - adj; i++) {

        for (int j = adj; j < gr.cols - adj; j++) {

            index = 0;

            for (int g = i - adj; g <= i + adj; g++) {

                for (int h = j - adj; h <= j + adj; h++) {

                    arr[index]=(int)gr.at<uchar>(g, h);

                    index++;

                }

            }

            insertionSort(arr, size);

            middle = size / 2;

            output.at<uchar>(i, j) = (uchar)arr[middle];

        }

    }
