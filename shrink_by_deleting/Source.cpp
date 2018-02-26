
//image shrinking by deleting rows and columns

#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	//Reading an image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p3.png");

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat shrink_image1(256, 128, CV_8UC1);

	Mat shrink_image2(128, 128, CV_8UC1);

	Mat shrink_image3(128, 128, CV_8UC3);

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols;j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}


	int l = 0, m = 0;

	for (int i = 0;i < 256;i++)
	{
		m = 0;
		for (int j = 0;j < 256;j++)
		{
			if (j % 2 == 0)
			{
				shrink_image1.at<uchar>(i, m) = grey_image.at<uchar>(i, j);
				m++;
			}
		}
	}

	l = 0;
	for (int i = 0;i < 256;i++)
	{
		for (int j = 0;j < 128;j++)
		{
			if (i % 2 == 0)
			{
				shrink_image2.at<uchar>(l, j) = shrink_image1.at<uchar>(i, j);

			}
		}
		if (i % 2 == 0)
			l++;
	}

	l = 0, m = 0;

	for (int i = 0;i < 256;i += 2)
	{
		m = 0;
		for (int j = 0;j < 256;j += 2)
		{
			shrink_image3.at<Vec3b>(l, m) = image.at<Vec3b>(i, j);
			m++;
		}
		l++;
	}

	cout << image.cols << ":" << image.rows << endl;
	imshow("1", image);
	imshow("2", grey_image);
	//imshow("3", shrink_image1);
	imshow("4", shrink_image2);
	imshow("5", shrink_image3);
	waitKey(0);
	return 1;
}