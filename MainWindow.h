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
	QWidget *centralWidget;
	QVBoxLayout *mainVerticalLayout;
	QGroupBox *colorsGroupBox;
	QVBoxLayout *colorsVerticalLayout;

	QMenu *fileMenu;
	QAction *openImageAction;
	QLabel *imageLabel;
	QPixmap pixmap;
	QString imageFilePath;
    ColorImage image;

	void createMenu();
	void createMainVerticalLayout();
	void createColorsGroupBox();
public:
	MainWindow(QWidget *parent = 0);
private slots:
	void openImage();
};