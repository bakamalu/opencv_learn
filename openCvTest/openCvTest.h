#pragma once

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

int test1();

// 创建和显示窗口
int win();

// 加载图像
void readImage();

// 保存图片
void saveImg();

// 视频采集
void captureVideo();