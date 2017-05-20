#include "ColorImage.h"

ColorImage::ColorImage() {}

ColorImage::ColorImage(const QString &fileName, const char * format) : QImage(fileName, format) {
    countColorFrequency();
    convertHashToVector();
    sortColorFrequency();
}

// Iterate through all pixels and count the occurence of each color.
void ColorImage::countColorFrequency() {
    for (int y = 0; y < height(); y++) {
        for (int x = 0; x < width(); x++) {
            QRgb color = pixel(x, y);
            if (colorCountHash.count(color) == 0) {
                colorCountHash[color] = 1;
            } else {
                colorCountHash[color]++;
            }
        }
    }
}

// Sort color vector by frequency (number of occurences).
void ColorImage::sortColorFrequency() {
    std::sort(colorCountVector.begin(), colorCountVector.end());
}

// Push all QRgb-int pairs to vector.
void ColorImage::convertHashToVector() {
    for (auto it = colorCountHash.begin(); it != colorCountHash.end(); ++it) {
        colorCountVector.push_back(ColorCount(it.value(), it.key()));
    }
}

// Retrieve nth most frequent colors.
// size_t n: Number of colors
// returns: ColorCountVector (std::vector<std::pair<int, QRgb>>)
ColorCountVector ColorImage::getNthMostFrequentColors(size_t n) {
    size_t end = std::min(colorCountVector.size(), n);
    return ColorCountVector(colorCountVector.end() - end, colorCountVector.end());
}

// Retrieve nth least frequent colors.
// size_t n: Number of colors
// returns: ColorCountVector (std::vector<std::pair<int, QRgb>>)
ColorCountVector ColorImage::getNthLeastFrequentColors(size_t n) {
    size_t end = std::min(colorCountVector.size(), n);
    return ColorCountVector(colorCountVector.begin(), colorCountVector.begin() + end);
}