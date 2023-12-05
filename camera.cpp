#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main() {
	cv::CascadeClassifier faceCascade;

	if(!faceCascade.load("haarcascade_frontalface_default.xml")) {
		std::cerr << "Erro ao carregar o classificador!" << std::endl;
		return -1;
	}
	cv::VideoCapture cap(5);

	if(!cap.isOpened()) {
		std::cerr<<"Erro ao abrir a camera" <<std::endl;
		return -1;
	}

	int imageCount=0;
	const int maxImages=150;

	while(true){
		cv::Mat frame;
		cap>>frame;

		if(frame.empty()){
			std::cerr<<"Erro ao capturar o quadro da camera" << std::endl;
			break;
		}

		cv::Mat gray;
		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(gray, faces, 1.3, 5);

		for(const auto& face : faces) {
			cv::Mat faceImage = frame(face);
			std::string imageName ="face_" + std::to_string(imageCount%maxImages)+ ".jpg";
			cv::imwrite(imageName, faceImage);
			std::cout << "Imagem salva como: " << imageName << std::endl;

			imageCount++;
		}
		
		if(cv::waitKey(1) == 'q') {
			break;
		}
	}
	cap.release();

	return 0;
}
