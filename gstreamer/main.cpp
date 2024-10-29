#include <iostream>
#include "VideoPlayer.h"

int main(int argc, char** argv) {
    // 檢查是否提供了影片檔路徑
    if (argc < 2) {
        std::cerr << "請提供影片檔路徑，例如： ./display_gstreamer /path/to/video.mp4" << std::endl;
        return -1;
    }

    // 取得影片檔路徑
    std::string video_path = argv[1];

    try {
        // 創建 VideoPlayer 物件
        VideoPlayer player(video_path);
        
        // 設定視窗大小（可根據需要調整）
        player.setWindowSize(800, 600);
        
        // 播放影片
        player.play();
    } catch (const std::exception& e) {
        std::cerr << "錯誤: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}