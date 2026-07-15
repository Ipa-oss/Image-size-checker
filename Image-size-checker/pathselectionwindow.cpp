#include "pathselectionwindow.h"
#include "ui_pathselectionwindow.h"
#include <QFileDialog>

PathSelectionWindow::PathSelectionWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PathSelectionWindow)
{
    ui->setupUi(this);
}

PathSelectionWindow::~PathSelectionWindow()
{
    delete ui;
}
