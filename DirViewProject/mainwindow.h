#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QDockWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *nameEdit;
    QFileSystemModel *model;
    QTreeView *tree;
    QVBoxLayout *mlayout;
    QDockWidget *dock;

public slots :
    void SetSearchText(QString);

};
#endif // MAINWINDOW_H
