#pragma once
#include <string>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class ColorWidget : public QWidget {
	Q_OBJECT
private:
	QColor color;
    QLabel *colorLabel;
    QLabel *rLabel;
    QLabel *gLabel;
    QLabel *bLabel;
	QGridLayout *layout;

	void createLayout();
    void createColorLabel();
    void createRGBLabels();

    std::string colorBGRToString(QColor color);
public:
    ColorWidget(QColor color = QColor(0, 0, 0), QWidget *parent = 0);
    ColorWidget(QRgb rgbColor, QWidget *parent = 0);
};

