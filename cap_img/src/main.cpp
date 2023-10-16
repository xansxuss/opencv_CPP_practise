#include "opencv2/core.hpp"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap1(0);
    if (!cap1.isOpened())
    {
        cout << "Cannot open camera\n";
        return 1;
    }
    // VideoCapture cap2(2);
    // if (!cap2.isOpened())
    // {
    //     cout << "Cannot open camera\n";
    //     return 1;
    // }
    Mat frame1;
    // Mat frame2;

    while (true)
    {

        // 擷取影像
        bool ret1 = cap1.read(frame1); // or cap >> frame;
        if (!ret1)
        {
            cout << "Can't receive frame (stream end?). Exiting ...\n";
            break;
        }
        // bool ret2 = cap2.read(frame2); // or cap >> frame;
        // if (!ret2)
        // {
        //     cout << "Can't receive frame (stream end?). Exiting ...\n";
        //     break;
        // }
#ifdef DEBUG
        cout << frame << endl;
#endif
        // int rows = frame.rows;
        // int cols = frame.cols;
        // cout << "row:" << rows << "col" << cols << endl;
        imshow("live1", frame1);
        // imshow("live2", frame2);
        if (waitKey(1) == 'q')
        {
            break;
        }
    }
    return 0;
}
