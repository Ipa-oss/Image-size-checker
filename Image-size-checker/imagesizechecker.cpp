#include "imagesizechecker.h"
#include "ui_imagesizechecker.h"

#include <QDebug>

ImageSizeChecker::ImageSizeChecker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageSizeChecker)
{
    ui->setupUi(this);
    connect(ui->dirButton,&QPushButton::clicked,this,&ImageSizeChecker::getPath);
    connect(ui->startButton,&QPushButton::clicked,this,&ImageSizeChecker::getFilesInDir);
}

ImageSizeChecker::~ImageSizeChecker()
{
    delete ui;
}

bool ImageSizeChecker::imageSizeConfirmation(QString recievedPath)
{
    imagePath = recievedPath;
    QFile file(imagePath); // unified button handler and subfunct? //what?
    if (!file.exists()){
        qDebug()<<"File not found.";
        ui->statusLabel->setText("File not found.");
        return false;
    }
    image.load(imagePath);
    strMinHeight = ui->minHeight->text();
    strMinWidth = ui->minWidth->text();
    minHeight = strMinHeight.toInt();
    minWidth = strMinWidth.toInt();
    qDebug()<<"Height:"<<image.height();
    qDebug()<<"Width:"<<image.width();
    if (minHeight > image.height() && minWidth > image.width()){
        qDebug()<<"Image is too small.";
        file.moveToTrash();
    }else{
        qDebug()<<"Image is big enough.";
    }
    return true;
}

void ImageSizeChecker::getPath()
{
    ui->fetchedPath->setText(fileWindow.getExistingDirectory(nullptr, "Use directory", "", QFileDialog::ShowDirsOnly)); //Uncanny how well this works
    /* List of tested formats:
    .png
    .jpg
    .jpeg
    .gif
    .bmp

    */
}

void ImageSizeChecker::getFilesInDir()
{
    ui->statusLabel->setText("Status: WORKING DO NOT CLOSE!"); //This doesn't have time to write lmao.
    QWidget::repaint();
    path = ui->fetchedPath->text();
    for (QDirListing::DirEntry dirEntry : QDirListing(path, QStringList{"*.png","*.jpg","*.jpeg","*.gif","*.bmp"}, QDirListing::IteratorFlag::FilesOnly)){
        imageSizeConfirmation(dirEntry.filePath());
    }
    ui->statusLabel->setText("Status: Finished! Check your trash.");
}
