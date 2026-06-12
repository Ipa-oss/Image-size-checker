#include "imagesizechecker.h"
#include "ui_imagesizechecker.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>

ImageSizeChecker::ImageSizeChecker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageSizeChecker)
{
    ui->setupUi(this);
    connect(ui->getDim,&QPushButton::clicked,this,&ImageSizeChecker::CreateFileFromPath);
    connect(ui->move,&QPushButton::clicked,this,&ImageSizeChecker::moveToNewFolder);
}

ImageSizeChecker::~ImageSizeChecker()
{
    delete ui;
}

bool ImageSizeChecker::CreateFileFromPath()
{
    QString path = ui->origPath->text();
    QFile file(path); // unified button handler and subfunct?
    qDebug()<<file.exists();
    QImage image; //This works, memory efficiency time.
    image.load(path);
    QString strMaxHeight = ui->maxHeight->text();
    QString strMaxWidth = ui->maxWidth->text();
    int maxHeight = strMaxHeight.toInt();
    int maxWidth = strMaxWidth.toInt();
    if (maxHeight > image.height() && maxWidth > image.width()){
        qDebug()<<"Image is too small.";
        file.moveToTrash(); //If this works...
    }
    qDebug()<<"Height:"<<image.height();
    qDebug()<<"Width:"<<image.width();
    return true;
}

bool ImageSizeChecker::moveToNewFolder()
{
    QString path = ui->origPath->text();
    QFile file(path);
    qDebug()<<file.exists();
    QFileInfo fname(file);
    if(file.open(QIODevice::ReadWrite)){
        qDebug()<<"Create "<<path<<" Success!";
        qDebug()<<fname.fileName();
    }
    else{
        qDebug()<<"Create "<<path<<" Failed!";
        return false;
    }
    //QImage image(path);
    //QString
    //image.height();
    //qDebug()<<"Width:"<<image.width();
    QString newpath = ui->newPath->text();
    newpath.append("/");
    newpath.append(fname.fileName());
    file.rename(path,newpath);
    file.close();
    return true;
}
