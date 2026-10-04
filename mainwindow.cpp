#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_wordRepo = new WordRepository();
    QList<Word> words = m_wordRepo->GetAll();
    for (int i = 0; i < words.count(); ++i)
    {
        ui->listWidget->insertItem(i, words[i].GetValue());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_wordRepo;
}
