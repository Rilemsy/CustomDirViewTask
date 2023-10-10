#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nameEdit = new QLineEdit(this);

    connect(nameEdit, SIGNAL(textChanged(QString)), this, SLOT (SetSearchText(QString)));

    model = new QFileSystemModel;
    QDir dir;
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::Hidden | QDir::NoDotAndDotDot);
    model->setFilter(dir.filter());
    model->setRootPath("");

    tree = new QTreeView(parent);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::homePath()));
    tree->setAnimated(false);
    tree->setIndentation(20);
    tree->setColumnWidth(0, tree->width() / 3);                              
    tree->setWindowTitle(QObject::tr("Dir View"));

    dock = new QDockWidget("Filter", this);
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    QWidget *container = new QWidget;
    dock->setWidget(container);
    mlayout = new QVBoxLayout(container);
    mlayout->addWidget(nameEdit);
    mlayout->addWidget(tree);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetSearchText(QString str){
    QStringList filters;
    filters << str+"*";
    model->setNameFilters(filters);
    model->setNameFilterDisables(false);
}


