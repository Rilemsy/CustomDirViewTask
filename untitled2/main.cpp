#include <QApplication>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QScreen>
#include <QScroller>
#include <QTreeView>
#include <QDir>
#include <QSortFilterProxyModel>
#include <QDesktopWidget>
#include "myproxymodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFileSystemModel model;
    QDir dir;
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::Hidden);
    QString rootPath = QDir::homePath();
    model.setFilter(dir.filter());
    model.setRootPath("");
    QLineEdit lineEdit;
    lineEdit.show();
    MyProxyModel proxyModel(lineEdit);
    proxyModel.setSourceModel(&model);

    QTreeView tree;
    tree.setModel(&proxyModel);
    tree.setRootIndex(proxyModel.mapFromSource(model.index(rootPath)));
    tree.setSortingEnabled(true);
    tree.sortByColumn(1,Qt::AscendingOrder);
    tree.setAnimated(false);
    tree.setIndentation(20);
    tree.setSortingEnabled(true);
    const QSize availableSize = app.screens()[0]->availableGeometry().size();
    tree.resize(availableSize/2);
    tree.setColumnWidth(0, tree.width() / 3);
    tree.setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,tree.size(),
                                         app.desktop()->availableGeometry()));
    tree.setWindowTitle(QObject::tr("Dir View"));
    tree.show();
    return app.exec();
}
