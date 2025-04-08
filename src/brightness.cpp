#include "BrightnessContrastNode.h"

BrightnessContrastNode::BrightnessContrastNode(const std::string& name)
    : Node(name), brightness(0), contrast(1.0) {}

void BrightnessContrastNode::process() {
    // Processing logic for the Brightness/Contrast Node
    // For now, we'll assume the image is passed directly to adjustBrightnessContrast
    // In a real scenario, you would get the image from the connected input node
    cv::Mat image; // This should be obtained from the input connection
    cv::Mat adjustedImage = adjustBrightnessContrast(image);
    // Pass the adjustedImage to the next node in the pipeline
}

void BrightnessContrastNode::setBrightness(int brightness) {
    if (brightness < -100 || brightness > 100) {
        throw std::invalid_argument("Brightness must be between -100 and 100.");
    }
    this->brightness = brightness;
}

void BrightnessContrastNode::setContrast(double contrast) {
    if (contrast < 0 || contrast > 3) {
        throw std::invalid_argument("Contrast must be between 0 and 3.");
    }
    this->contrast = contrast;
}

cv::Mat BrightnessContrastNode::adjustBrightnessContrast(const cv::Mat& image) {
    cv::Mat adjustedImage;
    image.convertTo(adjustedImage, -1, contrast, brightness);
    return adjustedImage;
}
