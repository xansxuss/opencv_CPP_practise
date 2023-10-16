#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;

int main()
{
    std::string image_path = "../members/P3.jpeg";
    // Load a 3-channel image (e.g., BGR color image)
    cv::Mat image = cv::imread(image_path);

    if (image.empty())
    {
        std::cerr << "Could not open or find the image." << std::endl;
        return -1;
    }

    // Specify the channel you want to extract (0 for blue, 1 for green, 2 for red)
    int channelToExtract = 1; // Extract the green channel

    // Extract the specified channel
    cv::Mat extractedChannel;
    cv::extractChannel(image, extractedChannel, channelToExtract);

    // Display the extracted channel
    cv::imshow("Extracted Channel", extractedChannel);
    cv::waitKey(0);
    cv::destroyAllWindows(); // Close OpenCV windows
    return 0;
}
