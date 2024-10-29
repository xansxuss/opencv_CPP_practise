#include "VideoPlayer.h"
#include <iostream>

VideoPlayer::VideoPlayer(const std::string& videoPath) 
    : window_name("GStreamer 接收影像") {
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    // GStreamer 管道，使用傳入的影片檔路徑
    gst_pipeline = "filesrc location=" + videoPath + " ! "
                   "decodebin ! "
                   "videorate ! "
                   "videoconvert ! "
                   "appsink";
    
    // 初始化 VideoCapture
    cap.open(gst_pipeline, cv::CAP_GSTREAMER);

    // 確認是否成功開啟串流
    if (!cap.isOpened()) {
        std::cerr << "無法開啟影片串流" << std::endl;
        throw std::runtime_error("Video stream not opened");
    }
}

VideoPlayer::~VideoPlayer() {
    // 釋放資源
    cap.release();
    cv::destroyWindow(window_name);
}

void VideoPlayer::play() {
    while (true) {
        // 讀取影像
        if (!cap.read(frame)) {
            std::cerr << "無法讀取影像幀（串流可能已結束）" << std::endl;
            break;
        }

        // 顯示影像
        cv::imshow(window_name, frame);

        // 按 'q' 鍵退出
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
}

void VideoPlayer::setWindowSize(int width, int height) {
    cv::resizeWindow(window_name, width, height);
}