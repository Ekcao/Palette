#include "ColorWidget.h"
#include <QPainter>
#include <string>

ColorWidget::ColorWidget(QRgb rgbColor, QWidget * parent) : ColorWidget(QColor(rgbColor), parent) {

}

ColorWidget::ColorWidget(QColor color, QWidget *parent) : color(color), QWidget(parent) {
    createColorLabel();
    createRGBLabels();
    createLayout();

    setLayout(layout);
}

void ColorWidget::createLayout() {
    layout = new QGridLayout;
    layout->addWidget(colorLabel, 0, 0);
    layout->addWidget(rLabel, 0, 1);
    layout->addWidget(gLabel, 0, 2);
    layout->addWidget(bLabel, 0, 3);
}

void ColorWidget::createColorLabel() {
    colorLabel = new QLabel;
    QString styles("border: 1px solid black; background-color: ");
    styles.append(QString::fromStdString(colorBGRToString(color)));
    colorLabel->setStyleSheet(styles);
}

void ColorWidget::createRGBLabels() {
    std::string rString = "R: " + std::to_string(color.red());
    rLabel = new QLabel(rString.c_str());

    std::string gString = "G: " + std::to_string(color.green());
    gLabel = new QLabel(gString.c_str());

    std::string bString = "B: " + std::to_string(color.blue());
    bLabel = new QLabel(bString.c_str());
}

std::string ColorWidget::colorBGRToString(QColor color) {
    std::string label = "rgb(" + std::to_string(color.red()) + ", "
        + std::to_string(color.green()) + ", "
        + std::to_string(color.blue()) + ")";

    return label;
}

