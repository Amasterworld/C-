#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // constructor
    MainWindow(QWidget *parent = nullptr);
    //destructor
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ClearButtonPressed();
    void FourBitButtonPressed();
    void ChangeSignPressed();
    void actionToExitPressed();
    //void on_actionExit_triggered();

    // menuBar
    void AboutCalc();

    void closeEvent(QCloseEvent* );

};
#endif // MAINWINDOW_H
