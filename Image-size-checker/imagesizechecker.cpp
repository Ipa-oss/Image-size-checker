#include "imagesizechecker.h"
#include "ui_imagesizechecker.h"
#include <QFile>
#include <QDebug>

ImageSizeChecker::ImageSizeChecker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageSizeChecker)
{
    ui->setupUi(this);
    connect(ui->getDim,&QPushButton::clicked,this,&ImageSizeChecker::imageSizeConfirmation);
    connect(ui->pathButton,&QPushButton::clicked,this,&ImageSizeChecker::getPath);
}

ImageSizeChecker::~ImageSizeChecker()
{
    delete ui;
}

bool ImageSizeChecker::imageSizeConfirmation()
{
    path = ui->origPath->text();
    QFile file(path); // unified button handler and subfunct? //what?
    if (!file.exists()){
        qDebug()<<"File not found.";
        ui->statusLabel->setText("File not found.");
        return false;
    }
    image.load(path);
    strMaxHeight = ui->maxHeight->text();
    strMaxWidth = ui->maxWidth->text();
    maxHeight = strMaxHeight.toInt();
    maxWidth = strMaxWidth.toInt();
    qDebug()<<"Height:"<<image.height();
    qDebug()<<"Width:"<<image.width();
    if (maxHeight > image.height() && maxWidth > image.width()){
        qDebug()<<"Image is too small.";
        ui->statusLabel->setText("Image is too small.");
        file.moveToTrash();
    }else{
        qDebug()<<"Image is big enough.";
        ui->statusLabel->setText("Image is big enough.");
    }
    return true;
}

void ImageSizeChecker::getPath()
{
    ui->origPath->setText(fileWindow.getOpenFileName(nullptr, "Open image", "", "Image files (*.png *.jpg *.jpeg *.webp *.gif *.bmp)")); //Uncanny how well this works
    //Hope we can do videos too at some point.
    /* List of tested formats:
    .png
    .jpg

    */
}
