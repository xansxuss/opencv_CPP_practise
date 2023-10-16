#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;

int main()
{
    std::string image_path = "../members/P3.jpeg";

    // Load an image
    cv::Mat image = cv::imread(image_path);

    if (image.empty())
    {
        std::cerr << "Could not open or find the image." << std::endl;
        return -1;
    }

    // Check the number of channels in the image
    int numChannels = image.channels();

    // Assuming you're working with a 3-channel (BGR) image
    if (numChannels == 3)
    {
        // Split the image into individual channels
        std::vector<cv::Mat> channels;
        cv::split(image, channels);

        // Access the individual channels
        cv::Mat blueChannel = channels[0];  // Blue channel
        cv::Mat greenChannel = channels[1]; // Green channel
        cv::Mat redChannel = channels[2];   // Red channel

        // You can now perform operations on individual channels
        // For example, let's display the green channel
        for (int channel = 0; channel < 3; channel++)
        {
            std::string channelName;
            if (channel == 0)
                channelName = "Blue";
            else if (channel == 1)
                channelName = "Green";
            else if (channel == 2)
                channelName = "Red";
            cv::imshow(channelName, channels[channel]);
            cv::waitKey(0);
            cv::destroyWindow(channelName);
        }
    }
    else
    {
        std::cerr << "The image does not have 3 channels (BGR)." << std::endl;
    }
    cv::destroyAllWindows(); // Close OpenCV windows
    return 0;
}
