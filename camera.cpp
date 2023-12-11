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

	cap.set(cv::CAP_PROP_AUTOFOCUS, 0);

	int imageCount=0;
	const int maxImages=150;

	double fps;
	int64_t lastTime = cv::getTickCount();
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

		int64_t currentTime = cv::getTickCount();
		double elapsedTime= (currentTime - lastTime) / cv:getTickFrequency();
		fps= 1.0 / elapsedTime;
		lastTime=currentTime;

		std::cout << "FPS: " << static_cast<int>(fps)<<std::endl;
		
		if(cv::waitKey(1) == 'q') {
			break;
		}
	}
	cap.release();

	return 0;
}
