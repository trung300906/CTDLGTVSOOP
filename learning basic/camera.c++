#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0); // Open the default camera

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // Capture a new frame

        if (frame.empty()) {
            std::cerr << "Error: Could not read frame" << std::endl;
            break;
        }

        cv::imshow("Camera", frame);

        if (cv::waitKey(30) >= 0) break; // Exit on key press
    }

    return 0;
}
