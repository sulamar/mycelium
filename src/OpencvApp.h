#pragma once
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

class OpencvApp
{
public:
	void Init();
	void Run();
	std::vector<std::vector<uint8_t>> GetPixels();
	bool IsFaceShown();

private:
	bool run;
	std::vector<cv::Rect> faces;
	cv::Mat grayImg;

};