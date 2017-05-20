#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QPixmap>
#include <QString>

#include "ColorImage.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
private:
	QVBoxLayout *mainLayout;
	QGroupBox *colorsGroupBox;
	QVBoxLayout *colorsVBoxLayout;

	QMenu *fileMenu;
	QAction *openImageAction;
	QLabel *imageLabel;
    ColorImage colorImage;

	void initMenus();
	void initMainLayout();
	void initColorsGroup();
    void initColorWidgets();

    QString getImageFilePath();
public:
	MainWindow(QWidget *parent = 0);
private slots:
	void openImageFromFile();
};
