#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <tic_toc.h>

using namespace std;
using namespace cv;

#include <opencv2/wechat_qrcode.hpp>
int main() 
{
	std::string root_dir = ROOT_DIR;
	std::string modelDir = root_dir+"/wechat_qrcode/model/";
    std::string videoDir = root_dir+"/figures/qrcode2.mp4";
	 
	// 构造（使用异常捕获构造函数是否正常）
	wechat_qrcode::WeChatQRCode detector{
        modelDir + "detect.prototxt", 
        modelDir + "detect.caffemodel",
        modelDir + "sr.prototxt",     
        modelDir + "sr.caffemodel"
    };

    VideoCapture capture;
    Mat frame;
    capture.open(videoDir);
    if(!capture.isOpened())
    {
        printf("can not open ...\n");
        return -1;
    }
	// VideoWriter writer;
	// Size size = Size(capture.get(CAP_PROP_FRAME_WIDTH), capture.get(CAP_PROP_FRAME_HEIGHT));
    // writer.open("/home/lyxichigoichie/Videos/read_qrcode.mp4", cv::VideoWriter::fourcc('M', 'P', '4', 'V'), capture.get(CAP_PROP_FPS), size, true);
    namedWindow("output");

    // 临时变量
	vector<Mat> points;   // qrcode: Retangle, not RotatedBox

    while (capture.read(frame))
    {
        TicToc time;
		auto res = detector.detectAndDecode(frame, points); 
        std::cout << "detect time: " << time.toc() << std::endl;
       	// 结果叠加
       	for(size_t idx = 0; idx < res.size(); idx ++){
			Point pt1 = points[idx].at<Point2f>(0);
			Point pt2 = points[idx].at<Point2f>(2);
	        Rect rect{pt1, pt2};
	        Point center = (pt1 + pt2) / 2;
			// 绘制矩形框
	        rectangle(frame, rect, {0,0,255}, 2);
	        circle(frame, center, rect.height / 15, {0,0,255}, -1);
			// 解码字符串
	        putText(frame, res[idx], {pt1.x, pt2.y + 16}, 1, 1, {0,0,255});    
        }
		// writer.write(frame);
        imshow("output", frame);
		cv::waitKey(1);
    }
}
