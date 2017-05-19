#include "MainWindow.h"
#include "ColorWidget.h"
#include "ColorImage.h"
#include <QFileDialog>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	createMenu();
	createColorsGroupBox();
	createMainVerticalLayout();

	centralWidget = new QWidget;
	centralWidget->setLayout(mainVerticalLayout);
	setCentralWidget(centralWidget);
}

void MainWindow::createMenu() {
	fileMenu = menuBar()->addMenu(tr("&File"));
	openImageAction = fileMenu->addAction(tr("&Open Image"));

	connect(openImageAction, &QAction::triggered, this, &MainWindow::openImage);
}

void MainWindow::createMainVerticalLayout() {
	mainVerticalLayout = new QVBoxLayout;
	imageLabel = new QLabel;
	mainVerticalLayout->addWidget(imageLabel);
	mainVerticalLayout->addWidget(colorsGroupBox);
}

void MainWindow::createColorsGroupBox() {
	colorsGroupBox = new QGroupBox(tr("Colors"));
	colorsVerticalLayout = new QVBoxLayout;

    ColorWidget * colorWidget = new ColorWidget(QColor(0, 0, 0));
    ColorWidget * colorWidget2 = new ColorWidget(QColor(255, 255, 255));
	colorsVerticalLayout->addWidget(colorWidget);
    colorsVerticalLayout->addWidget(colorWidget2);
	colorsGroupBox->setLayout(colorsVerticalLayout);
}

void MainWindow::openImage() {
	imageFilePath = QFileDialog::getOpenFileName(this,
												 tr("Open Image"),
												 QStandardPaths::displayName(QStandardPaths::PicturesLocation),
												 tr("Images (*.png *.jpg *.bmp)"));

	if (!imageFilePath.isNull()) {
		pixmap = QPixmap(imageFilePath);
		imageLabel->setPixmap(pixmap);
        image = ColorImage(imageFilePath);
	}
}
