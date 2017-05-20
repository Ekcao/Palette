#pragma once
#include <QImage>
#include <QString>
#include <QHash>
#include <QVector>
#include <vector>

typedef QHash<QRgb, int> ColorCountHash;
typedef std::pair<int, QRgb> ColorCount;
typedef std::vector<ColorCount> ColorCountVector;

class ColorImage : public QImage {
private:
    ColorCountHash colorCountHash;
    ColorCountVector colorCountVector;

    void countColorFrequency();
    void sortColorFrequency();
    void convertHashToVector();
public:
    ColorImage();
    ColorImage(const QString &fileName, const char * format = Q_NULLPTR);

    const ColorCountHash & getColorCountHash() const { return colorCountHash; }
    const ColorCountVector & getColorCountVector() const { return colorCountVector; }
    ColorCountVector getNthMostFrequentColors(size_t n);
    ColorCountVector getNthLeastFrequentColors(size_t n);
};