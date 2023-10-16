#include "opencv2/core.hpp"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("/home/xanxus/workspaces/C_test/opencv/read_img/src/cat.jpg", 1);
#ifdef DEBUG
    cout << image << endl;
#endif
    namedWindow("display", WINDOW_AUTOSIZE);
    imshow("display", image);
    waitKey(0);
    return 0;
}
