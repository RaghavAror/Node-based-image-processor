#include "imageinput.h"

ImageInputNode::ImageInputNode(const std::string& name) : Node(name) {}

void ImageInputNode::process() {
    // Processing logic for the Image Input Node
    // For now, we'll just load the image
    loadImage(filePath);
}

void ImageInputNode::loadImage(const std::string& filePath) {
    this->filePath = filePath;
    image = cv::imread(filePath, cv::IMREAD_COLOR);
    if (image.empty()) {
        throw std::runtime_error("Failed to load image: " + filePath);
    }
}

cv::Mat ImageInputNode::getImage() const {
    return image;
}

std::string ImageInputNode::getImageMetadata() const {
    if (image.empty()) {
        return "No image loaded.";
    }
    std::string metadata = "Dimensions: " + std::to_string(image.cols) + "x" + std::to_string(image.rows) + "\n";
    metadata += "Channels: " + std::to_string(image.channels()) + "\n";
    metadata += "File Size: " + std::to_string(cv::imencode(".png", image).size()) + " bytes\n";
    return metadata;
}
