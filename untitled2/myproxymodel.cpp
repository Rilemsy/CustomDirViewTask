#include "myproxymodel.h"
#include <QMessageBox>
MyProxyModel::MyProxyModel(QLineEdit &lineEdit)
{
    nameEdit = &lineEdit;
    //connect(nameEdit, SIGNAL(&QLineEdit::textChanged), this, SLOT (&MyProxyModel::SetSearchText));
    connect(nameEdit, &QLineEdit::textChanged, this, &MyProxyModel::SetSearchText);
}
void MyProxyModel::SetSearchText(){
    QRegExp rx(nameEdit->text());

    //QMessageBox msg; // testing slot
    //msg.setText(nameEdit->text());
    //msg.exec();

    this->setFilterRegExp(rx);
    this->setFilterKeyColumn(1);
}
bool MyProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index0 = sourceModel()->index(source_row, 0,source_parent);
    return sourceModel()->data(index0).toString().contains(filterRegExp());
}
