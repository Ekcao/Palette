#include "ColorWidget.h"
#include <string>

ColorWidget::ColorWidget(QRgb rgbColor, QWidget * parent) : ColorWidget(QColor(rgbColor), parent) {

}

ColorWidget::ColorWidget(QColor color, QWidget *parent) : color(color), QWidget(parent) {
    initColorLabel();
    initRGBLabels();
    initGridLayout();

    setLayout(gridLayout);
}

void ColorWidget::initGridLayout() {
    gridLayout = new QGridLayout;
    gridLayout->setContentsMargins(1, 0, 1, 0);
    gridLayout->addWidget(colorLabel, 0, 0);
    gridLayout->addWidget(redLabel, 0, 1);
    gridLayout->addWidget(greenLabel, 0, 2);
    gridLayout->addWidget(blueLabel, 0, 3);
}

void ColorWidget::initColorLabel() {
    colorLabel = new QLabel;
    QString styles("border: 1px solid black; background-color: ");
    styles.append(QString::fromStdString(colorBGRToString(color)));
    colorLabel->setStyleSheet(styles);
}

void ColorWidget::initRGBLabels() {
    std::string redString = "R: " + std::to_string(color.red());
    redLabel = new QLabel(redString.c_str());

    std::string greenString = "G: " + std::to_string(color.green());
    greenLabel = new QLabel(greenString.c_str());

    std::string blueString = "B: " + std::to_string(color.blue());
    blueLabel = new QLabel(blueString.c_str());
}

std::string ColorWidget::colorBGRToString(QColor color) {
    std::string label = "rgb(" + std::to_string(color.red()) + ", "
        + std::to_string(color.green()) + ", "
        + std::to_string(color.blue()) + ")";

    return label;
}

