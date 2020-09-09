#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * 选择要处理的图片
 */
void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "选择图片", "/home",
                                                tr("Images (*.png *.xpm *.jpg)"));
    if (path.isEmpty())
        return ;

    QPixmap pixmap(path);
    ui->label->setPixmap(pixmap);

    auto colors = ImageUtil::extractImageThemeColors(pixmap.toImage(), 20);

}
