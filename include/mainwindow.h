#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDockWidget>
#include <QListWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void setupCanvas();
    void setupPropertiesPanel();

    QGraphicsView* canvasView;
    QGraphicsScene* canvasScene;
    QDockWidget* propertiesDock;
    QListWidget* propertiesList;
};

#endif // MAINWINDOW_H
