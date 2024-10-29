#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <opencv2/opencv.hpp>
#include <string>

class VideoPlayer {
public:
    VideoPlayer(const std::string& videoPath);
    ~VideoPlayer();
    void play();
    void setWindowSize(int width, int height);

private:
    std::string gst_pipeline;
    cv::VideoCapture cap;
    cv::Mat frame;
    std::string window_name;
};

#endif //VIDEOPLAYER_H