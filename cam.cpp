#include <iostream>
#include <opencv2/opencv.hpp>
#include <dropbox/client.hpp>

int main() {
	cv::CascadeClassifierfaceCascade;
	if(!faceCascade.load("haarcascade_frontalface_default.xml")){
		std::cerr<<"erro ao carregar o classificador"<<std:endl;
		return -1;
	}
	cv::VideoCapture cap(5);

	if(!cap.isOpened()){
		std::cer<<"erro ao abrir camera"<<std::endl;
		return -1
	}

	const std::string appKey="s89wge8nxl27rt3";
	const std::string appSecret="s6mojbktm9610sa";
	const std::string accessToken="sl.BrLgIDnloF1F9nvjTfC_SbVv8n1NAiR_62dClaneiY6Gd0xLeYELDRs94gFDUhwOahX9UfDP1AuymiN1Q8crUOe_DMl1
