#pragma once
#include <string>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class ColorWidget : public QWidget {
	Q_OBJECT
private:
	QColor color;
    QLabel *colorCircle;
    QLabel *rLabel;
    QLabel *gLabel;
    QLabel *bLabel;
	QGridLayout *layout;

	void createLayout();
    void createColorCircle();
    void createRGBLabels();

    std::string colorBGRToString(QColor color);
public:
    ColorWidget(QColor color = QColor(0, 0, 0), QWidget *parent = 0);
};

