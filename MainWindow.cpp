#include "MainWindow.h"
#include "ColorWidget.h"
#include "ColorImage.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    createMenu();
    createColorsGroupBox();
    createMainVerticalLayout();

    centralWidget = new QWidget;
    centralWidget->setLayout(mainVerticalLayout);
    setCentralWidget(centralWidget);

    connect(openImageAction, &QAction::triggered, this, &MainWindow::openImage);
}

void MainWindow::createMenu() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    openImageAction = fileMenu->addAction(tr("&Open Image"));
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

    colorsGroupBox->setLayout(colorsVerticalLayout);
}

void MainWindow::createColorWidgetsFromImage() {
    if (!image.isNull()) {
        ColorCountVector topFiveColors = image.getNthMostFrequentColors(5);
        for (ColorCount colorCount : topFiveColors) {
            colorsVerticalLayout->addWidget(new ColorWidget(colorCount.second));
        }
    }
}

void MainWindow::openImage() {
    QString imageFilePath = pickImageFilePath();

	if (!imageFilePath.isNull()) {
		QPixmap pixmap(imageFilePath);
		imageLabel->setPixmap(pixmap);
        image = ColorImage(imageFilePath);
        createColorWidgetsFromImage();

        statusBar()->addWidget(new QLabel(imageFilePath));
	}
}

QString MainWindow::pickImageFilePath() {
    return QFileDialog::getOpenFileName(this,
                                        tr("Open Image"),
                                        QStandardPaths::displayName(QStandardPaths::PicturesLocation),
                                        tr("Images (*.png *.jpg *.bmp)"));
}
