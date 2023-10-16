#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;

int main()
{
	std::string directory_path = "../members";
    cv::String image_pattern = directory_path + "/*.jpeg";
    std::vector<cv::String> image_files;
    cv::glob(image_pattern, image_files, true);

    if (image_files.empty())
    {
        std::cerr << "No image files found in the specified directory." << std::endl;
        return 1;
    }

    for (const cv::String &image_file : image_files)
    {
        cv::Mat frame = cv::imread(image_file);

        if (frame.empty())
        {
            std::cerr << "Error: Unable to read the image file: " << image_file << std::endl;
            continue;
        }

        // Process the frame (e.g., display or perform image processing)
        cv::imshow("Frame", frame);

        // Wait for a key press (e.g., press any key to continue)
        cv::waitKey(0);
    }

    cv::destroyAllWindows(); // Close OpenCV windows
    return 0;
}
