#include "opencv2/opencv.hpp"
using namespace cv;

int main() {



	VideoCapture cap(0); // Открываем камеру или файл
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat edges;
	Mat edges2;
	namedWindow("edges", 1);
	namedWindow("edges2", 1);
	while (1) {
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, COLOR_BGR2GRAY); // Перевод в градации серого
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5); // Размытие
		Canny(edges, edges, 0, 30, 3); // Выделение границ

		cvtColor(frame, edges2, COLOR_BGR2GRAY); // Перевод в градации серого
		GaussianBlur(edges2, edges2, Size(7, 7), 1.2, 1.2); // Размытие
		Canny(edges2, edges2, 0, 30, 3); // Выделение границ


		imshow("edges2", edges2);
		imshow("edges", edges);
		imshow("camera", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}

