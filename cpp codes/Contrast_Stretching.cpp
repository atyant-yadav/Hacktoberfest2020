
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>



using namespace cv;

using namespace std;

int main(int argc, char** argv)

{

	if (argc != 2)

	{

		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;

		return -1;

	}

	Mat image;

	image = imread(argv[1], IMREAD_COLOR); // Read the file



	if (!image.data) // Check for invalid input

	{

		cout << "Could not open or find the image" << std::endl;

		return -1;

	}

	Mat gr;



	cvtColor(image, gr, COLOR_BGR2GRAY, 0);



	int h = gr.rows;

	int w = gr.cols;

	int x = 0;

	double y = 0.0;

	cout << "Width: " << w << endl;

	cout << "Height: " << h << endl;



	Mat CSt = gr.clone();



	for (int i = 0; i < h; i++) {

		for (int j = 0; j < w; j++) {

			x = (int)gr.at<uchar>(i, j);

			y = 0.0;

			if (x < 150) {

				y = (double)(5 / 150) * (double)(x);

			}

			else {

				if (x < 220) {

					y = (double)(245 / 70) * (double)(x - 150) + 5;

				}

				else {

					y = (double)(5 / 35) * (double)(x - 220) + 250;

				}



			}

			CSt.at<uchar>(i, j) = (uchar)(cvRound(y));

		}

	}

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.

	imshow("Display window", CSt); // Show our image inside it.

	namedWindow("Display Gray", WINDOW_AUTOSIZE); // Create a window for display.

	imshow("Display Gray", gr); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window

	image.release();

	gr.release();

	return 0;

}