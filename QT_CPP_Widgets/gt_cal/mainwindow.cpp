#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));

    manager = new QNetworkAccessManager();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::on_btnLogin_clicked()
{
    QString url = "";

    QNetworkRequest  request;

    QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                qDebug() << answer;

                qDebug() << "request 1";

                manager->disconnect();

                ui->lblStatus->setText("Logging OK");
            }
        );

    ui->lblStatus->setText("Start Logging In");
    request.setUrl(QUrl("http://localhost:63761/weatherforecast"));
    manager->get(request);


}

void MainWindow::on_pushButton_clicked()
{
    QString url = "";

    QNetworkRequest  request;

    QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                qDebug() << answer;

                qDebug() << "request 2";

                manager->disconnect();

                ui->lblStatus->setText("Logging OK");
            }
        );

    ui->lblStatus->setText("Start Logging In");
    request.setUrl(QUrl("http://localhost:63761/test"));
    manager->get(request);

}
