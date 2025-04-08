#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), canvasView(new QGraphicsView), canvasScene(new QGraphicsScene) {

    setupCanvas();
    setupPropertiesPanel();

    setWindowTitle("Node-Based Image Processor");
    setMinimumSize(800, 600);
}

void MainWindow::setupCanvas() {
    canvasView->setScene(canvasScene);
    setCentralWidget(canvasView);

    // Example: Add a simple rectangle to the canvas
    canvasScene->addRect(0, 0, 100, 100);
}

void MainWindow::setupPropertiesPanel() {
    propertiesDock = new QDockWidget("Properties", this);
    propertiesList = new QListWidget(this);

    propertiesDock->setWidget(propertiesList);
    addDockWidget(Qt::RightDockWidgetArea, propertiesDock);

    // Example: Add a property item
    propertiesList->addItem("Brightness: 0");
    propertiesList->addItem("Contrast: 1.0");
}
