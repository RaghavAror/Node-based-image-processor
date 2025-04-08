#include "OutputNode.h"

OutputNode::OutputNode(const std::string& name) : Node(name), quality(90) {
    // Default output format is PNG
    outputFormat = "png";
}

void OutputNode::process() {
    // Processing logic for the Output Node
    // For now, we'll assume the image is passed directly to saveImage
    // In a real scenario, you would get the image from the connected input node
    cv::Mat image; // This should be obtained from the input connection
    saveImage("output_image." + outputFormat, image);
}

void OutputNode::saveImage(const std::string& filePath, const cv::Mat& image) {
    if (image.empty()) {
        throw std::runtime_error("No image to save.");
    }
    std::vector<int> params;
    if (outputFormat == "jpg" || outputFormat == "jpeg") {
        params.push_back(cv::IMWRITE_JPEG_QUALITY);
        params.push_back(quality);
    }
    if (!cv::imwrite(filePath, image, params)) {
        throw std::runtime_error("Failed to save image: " + filePath);
    }
}

void OutputNode::setOutputFormat(const std::string& format) {
    outputFormat = format;
}

void OutputNode::setQuality(int quality) {
    if (quality < 0 || quality > 100) {
        throw std::invalid_argument("Quality must be between 0 and 100.");
    }
    this->quality = quality;
}
