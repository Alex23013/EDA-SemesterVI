#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
class QGraphicsView;
QT_END_NAMESPACE

class GraphScene;

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QGraphicsView* view;
    GraphScene* scene;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* insertButton;
    QPushButton* deleteButton;
    QLineEdit* newElement;
    QLineEdit* childToRemove;

private slots:
 void handleUndoButton();
 void handleRedoButton();
 void handleInsertButton();
 void handleDeleteButton();

public:
   MainWindow();
};
#endif //MAINWINDOW_H
