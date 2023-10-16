#include "opencv2/core.hpp"
#include <iostream>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaobjdetect.hpp>
#include <opencv2/cudaimgproc.hpp>
using namespace cv;
using namespace std;

string front_face_cascade_name = "../data/haarcascades_cuda/haarcascade_frontalface_alt2.xml";
string left_face_cascade_name = "../data/haarcascades_cuda/haarcascade_profileface.xml";

Ptr<cuda::CascadeClassifier> front_face_cascade = cuda::CascadeClassifier::create(front_face_cascade_name);
Ptr<cuda::CascadeClassifier> left_face_cascade = cuda::CascadeClassifier::create(left_face_cascade_name);

int main()
{
    Mat img;
    cuda::GpuMat GpuGray, Gpuobj;
    VideoCapture cap(0);
    while (cap.isOpened())
    {
        cap >> img;
        cuda::GpuMat GpuImg;
        GpuImg.upload(img);
        clock_t start = clock();
        cuda::cvtColor()
    }

    return 0;
}
