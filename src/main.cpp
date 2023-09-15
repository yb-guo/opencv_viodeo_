#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>  // 添加此头文件以处理文件路径

using namespace std;
using namespace cv;
#include "build/config.h"  // 包含生成的 config.h 头文件

namespace fs = std::filesystem;  // 创建文件系统命名空间

int main() {
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "无法打开摄像头" << endl;
        cin.get();
        return -1;
    }

    int num = 0;

    double dwidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double dheight = cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "视频分辨率为: " << dwidth << "x" << dheight << endl;

    string win = "摄像头";
    namedWindow(win);

    string imgFolder = string(SOURCE_DIR) + "/img";  // 指定图像保存文件夹
    fs::create_directory(imgFolder);  // 如果文件夹不存在，创建它

    while (true) {
        Mat frame;

        bool b_frame = cap.read(frame);
        if (!b_frame) {
            cout << "摄像头断开连接" << endl;
            break;
        }

        imshow(win, frame);
        char key = waitKey(10);
        if (key == 27) {  // 按下Esc键退出
            destroyWindow(win);
            break;
        }
        else if (key == 's' || key == 'S') {
            string filename = imgFolder + "/frame" + to_string(num) + ".jpg";  // 指定保存路径
            imwrite(filename, frame);  // 保存帧为图像文件
            cout << "保存帧为 " << filename << endl;
            num++;
        }
    }
    return 0;
}
