#ifndef BLURNODE_H
#define BLURNODE_H

#include "Node.h"
#include <opencv2/opencv.hpp>

class BlurNode : public Node {
public:
    BlurNode(const std::string& name);

    void process() override;
    void setBlurRadius(int radius);
    cv::Mat applyGaussianBlur(const cv::Mat& image);

private:
    int blurRadius;
};

#endif // BLURNODE_H
