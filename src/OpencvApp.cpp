#include "OpencvApp.h"

void OpencvApp::Init()
{
	run = true;
}

void OpencvApp::Run()
{
	cv::Mat img;
	cv::VideoCapture cap(0);

	cv::CascadeClassifier face;
	face.load("harcascades/frontface.xml");
	
	cap.set(cv::CAP_PROP_BUFFERSIZE, 3);

	while (run)
	{
		cap >> img;

		face.detectMultiScale(img, faces, 1.1, 10);
		if (faces.size() != 0)
		{
			for (int i = 0; i < faces.size(); i++)
			{
				cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 3);
			}
		}

		cv::imshow("img", img);
		
		if (cv::waitKey(30) == 's')
		{
			cv::Mat frame;
			frame = img.clone();

			cv::cvtColor(frame, grayImg, cv::COLOR_BGR2GRAY);

			cv::imshow("frame", grayImg);	

		}
		
		if (cv::waitKey(30) == 'q')
		{
			run = false;
		}

		faces.clear();

		cv::waitKey(10);
	}
}

std::vector<std::vector<uint8_t>> OpencvApp::GetPixels()
{
	std::vector<std::vector<uint8_t>> pixels;

	for (int r = 0; r < grayImg.rows; r++)
	{
		for (int c = 0; c < grayImg.cols; c++)
		{
			std::vector<uchar> pixel(grayImg.at<uint8_t>(r, c));
			pixels.push_back(pixel);

			//grayImg.at<uint8_t>(r, c) = grayImg.at<uint8_t>(r, c) * 0.5f;
		}
	}

	return pixels;
}

bool OpencvApp::IsFaceShown()
{
	std::cout << ((faces.size() > 0) ? "true" : "false") << std::endl;
	return ((faces.size() > 0) ? true : false);
}
