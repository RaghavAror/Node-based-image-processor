#include "BlurNode.h"

BlurNode::BlurNode(const std::string& name) : Node(name), blurRadius(1) {}

void BlurNode::process() {
    // Processing logic for the Blur Node
    // For now, we'll assume the image is passed directly to applyGaussianBlur
    // In a real scenario, you would get the image from the connected input node
    cv::Mat image; // This should be obtained from the input connection
    cv::Mat blurredImage = applyGaussianBlur(image);
    // Pass the blurredImage to the next node in the pipeline
}

void BlurNode::setBlurRadius(int radius) {
    if (radius < 1 || radius > 20) {
        throw std::invalid_argument("Blur radius must be between 1 and 20.");
    }
    blurRadius = radius;
}

cv::Mat BlurNode::applyGaussianBlur(const cv::Mat& image) {
    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(blurRadius * 2 + 1, blurRadius * 2 + 1), 0);
    return blurredImage;
}
