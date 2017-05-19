#pragma once
#include <QImage>
#include <QString>
#include <QHash>
#include <QVector>
#include <vector>

typedef QHash<QRgb, int> ColorCountMap;
typedef std::pair<int, QRgb> ColorCount;
typedef std::vector<std::pair<int, QRgb>> ColorCountVector;

class ColorImage : public QImage {
private:
    ColorCountMap colorCountMap;
    ColorCountVector colorCountVector;

    void countColorFrequency();
    void sortColorFrequency();
public:
    ColorImage();
    ColorImage(const QString &fileName, const char * format = Q_NULLPTR);

    const ColorCountMap & getColorCountMap() const { return colorCountMap; }
};