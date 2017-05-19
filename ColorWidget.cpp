#include "ColorWidget.h"
#include <QPainter>
#include <string>

ColorWidget::ColorWidget(QColor color, QWidget *parent) : color(color), QWidget(parent) {
    createColorCircle();
    createRGBLabels();
    createLayout();

    setLayout(layout);
}

void ColorWidget::createLayout() {
    layout = new QGridLayout;
    layout->addWidget(colorCircle, 0, 0);
    layout->addWidget(rLabel, 0, 1);
    layout->addWidget(gLabel, 0, 2);
    layout->addWidget(bLabel, 0, 3);
}

void ColorWidget::createColorCircle() {
    colorCircle = new QLabel;
    QString styles("background-color: ");
    styles.append(QString::fromStdString(colorBGRToString(color)));
    colorCircle->setStyleSheet(styles);    
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
