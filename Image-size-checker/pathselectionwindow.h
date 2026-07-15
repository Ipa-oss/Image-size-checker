#ifndef PATHSELECTIONWINDOW_H
#define PATHSELECTIONWINDOW_H

#include <QDialog>

namespace Ui {
class PathSelectionWindow;
}

class PathSelectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PathSelectionWindow(QWidget *parent = nullptr);
    ~PathSelectionWindow();

private:
    Ui::PathSelectionWindow *ui;
};

#endif // PATHSELECTIONWINDOW_H
