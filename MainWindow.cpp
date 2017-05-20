#include "MainWindow.h"
#include "ColorWidget.h"
#include "ColorImage.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    initMenus();
    initColorsGroup();
    initMainLayout();

    QWidget * centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(openImageAction, &QAction::triggered, this, &MainWindow::openImageFromFile);
}


void MainWindow::initMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    openImageAction = fileMenu->addAction(tr("&Open Image"));
}

void MainWindow::initMainLayout() {
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(colorsGroupBox);
}

void MainWindow::initColorsGroup() {
    colorsGroupBox = new QGroupBox(tr("Colors"));
    colorsVBoxLayout = new QVBoxLayout;

    colorsGroupBox->setLayout(colorsVBoxLayout);
}

void MainWindow::initColorWidgets() {
    if (!colorImage.isNull()) {
        ColorCountVector topFiveColors = colorImage.getNthMostFrequentColors(5);
        for (ColorCount colorCount : topFiveColors) {
            colorsVBoxLayout->addWidget(new ColorWidget(colorCount.second));
        }
    }
}

void MainWindow::openImageFromFile() {
    QString imageFilePath = getImageFilePath();

	if (!imageFilePath.isNull()) {
        imageLabel = new QLabel;
		QPixmap pixmap(imageFilePath);
		imageLabel->setPixmap(pixmap);
        mainLayout->addWidget(imageLabel);
        colorImage = ColorImage(imageFilePath);
        initColorWidgets();

        statusBar()->addWidget(new QLabel(imageFilePath));
	}
}

QString MainWindow::getImageFilePath() {
    return QFileDialog::getOpenFileName(this,
                                        tr("Open Image"),
                                        QStandardPaths::displayName(QStandardPaths::PicturesLocation),
                                        tr("Images (*.png *.jpg *.bmp)"));
}
