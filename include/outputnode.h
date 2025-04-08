#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include "Node.h"
#include <opencv2/opencv.hpp>
#include <string>

class OutputNode : public Node {
public:
    OutputNode(const std::string& name);

    void process() override;
    void saveImage(const std::string& filePath, const cv::Mat& image);
    void setOutputFormat(const std::string& format);
    void setQuality(int quality);

private:
    std::string outputFormat;
    int quality;
};

#endif // OUTPUTNODE_H
