// openCvTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "openCvTest.h"

using namespace std;
using namespace cv;

const string strPngPath = "C:\\Users\\Song\\AppData\\Local\\Microsoft\\Edge\\User Data\\Default\\Extensions\\lkanpeepkkpicfokidgcpnljbapllgfl\\1.0.3_0\\images\\1.jpg";
int test1()
{
    Mat image;
    image = imread(strPngPath);
    if (image.empty())
    {
        cout << "not image" << endl;
        return -1;
    }
    namedWindow("display window", WINDOW_AUTOSIZE);
    imshow("display window", image);
    waitKey(0);
}

int win()
{
    namedWindow("new", WINDOW_AUTOSIZE);
    imshow("new", 0);
    int nKey = waitKey(0);
    if (nKey == 'q')
    {
        destroyAllWindows();
        return -1;
    }
    return 0;
}

void readImage()
{
    namedWindow("img", WINDOW_NORMAL);
    Mat image = imread(strPngPath);

    imshow("img", image);
    char chKey;
    while ((chKey = waitKey(0)) != 'q')
    {
        cout << chKey << endl;
    }
}

void saveImg()
{
    namedWindow("img", WINDOW_NORMAL);
    // 导入的时候会自动转向，导致可能导出的文件和读入的文件方向不同
    Mat image = imread(strPngPath);

    imshow("img", image);
    char chKey;
    while (true)
    {
        chKey = waitKey(0);
        cout << chKey;
        if (chKey == 'q')
        {
            destroyAllWindows();
            return;
        }
        else if (chKey == 's')
        {
            imwrite("testSaveImg.png", image);
        }
        else
        {
            continue;
        }
    }
}

void captureVideo()
{
    namedWindow("video", WINDOW_NORMAL);
    resizeWindow("video", 1920, 1080);
    // 获取摄像设备
    VideoCapture device(0);
    while (true)
    {
        Mat image;
        // 从摄像头读取视频帧
        bool bCapture = device.read(image);
        
        // 显示读取到的视频帧
        if (bCapture)
        {
            imshow("video", image);
        }

        char chKey = waitKey(0);
        if (chKey == 'q')
        {
            destroyAllWindows();
            break;
        }
        else
        {
            cout << chKey;
        }
    }
    device.release();
}

int main()
{
    //test1();
    //win();
    //readImage();
    //saveImg();
    captureVideo();
    return 0;
}