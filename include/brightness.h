#ifndef BRIGHTNESSCONTRASTNODE_H
#define BRIGHTNESSCONTRASTNODE_H

#include "Node.h"
#include <opencv2/opencv.hpp>

class BrightnessContrastNode : public Node {
public:
    BrightnessContrastNode(const std::string& name);

    void process() override;
    void setBrightness(int brightness);
    void setContrast(double contrast);
    cv::Mat adjustBrightnessContrast(const cv::Mat& image);

private:
    int brightness;
    double contrast;
};

#endif // BRIGHTNESSCONTRASTNODE_H
