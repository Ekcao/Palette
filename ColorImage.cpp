#include "ColorImage.h"

ColorImage::ColorImage() {}

ColorImage::ColorImage(const QString &fileName, const char * format) : QImage(fileName, format) {
    countColorFrequency();
}

void ColorImage::countColorFrequency() {
    for (int y = 0; y < height(); y++) {
        for (int x = 0; x < width(); x++) {
            QRgb color = pixel(x, y);
            if (colorCountMap.count(color) == 0) {
                colorCountMap[color] = 1;
            } else {
                colorCountMap[color]++;
            }
        }
    }
}

void ColorImage::sortColorFrequency() {
    for (auto it = colorCountMap.begin(); it != colorCountMap.end(); ++it) {
        colorCountVector.push_back(ColorCount(it.value(), it.key()));
    }

    std::sort(colorCountVector.begin(), colorCountVector.end());
}