#ifndef IMAGEINPUTNODE_H
#define IMAGEINPUTNODE_H

#include "Node.h"
#include <opencv2/opencv.hpp>
#include <string>

class ImageInputNode : public Node {
public:
    ImageInputNode(const std::string& name);

    void process() override;
    void loadImage(const std::string& filePath);
    cv::Mat getImage() const;
    std::string getImageMetadata() const;

private:
    cv::Mat image;
    std::string filePath;
};

#endif // IMAGEINPUTNODE_H
