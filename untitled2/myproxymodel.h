#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QLineEdit>

class MyProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MyProxyModel(QLineEdit &lineEdit);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

    QLineEdit *nameEdit;

public slots :
    void SetSearchText();

};

#endif // MYPROXYMODEL_H
