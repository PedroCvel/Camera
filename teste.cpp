#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
	cv::CascadeClassifier faceCascade;
	
	if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
		std::cerr << "Erro ao carregar o classificador!" << std::endl;
		return -1;
	}

	cv::VideoCapture cap(5);

	
	if(!cap.isOpened()) {
		std::cerr << "Erro ao abrir a camera!" << std::endl;
		return -1;
	}

	while (true) {
		cv::Mat frame;
		cap >> frame;

		cv::Mat gray;
		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(gray, faces, 1.3, 5);

		for (const auto& face : faces) {
			std::cout << "Face: x=" << face.x << ", y=" << face.y << ", width=" << face.width << "height=" << face.height << std::endl;
		}

	

		if(cv::waitKey(1) == 'q') {
			break;
		}
	}

	cap.release();
	cv::destroyAllWindows();

	return 0;
}
