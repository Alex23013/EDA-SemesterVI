#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KDTree.h"
#include "csvLector.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    //string archivo ="crime10r.csv";
    string archivo ="1m.csv";
    //string archivo ="c10k.csv";
    cout<<"archivo por abrir: "<<archivo<<endl;
    int dimensions = 2;
    cKDTree tree(dimensions);
    vector <cCoordinate> asd = csvLector(archivo);
    tree.build(asd);
    cout << "-----------------------------Arbol-------------------------" << endl;
    tree.print(&p,20);
    cout << endl;
}
