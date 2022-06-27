#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // to use QMessageBox
#include <QCloseEvent> // to deal when the user click to X in order to exit progrw
#include <QRegularExpression>


double g_calc_val = 0.0; // to store the number

// to track whether the last operation is add
bool g_add_trigger = false;
bool g_sub_trigger = false;
bool g_div_trigger = false;
bool g_4bit_trigger = false;


//body of the constructor with  initializer lists
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)  // create the UI class and assign it to our UI member that we have
{
    ui->setupUi(this); // set up UI for us

    // QString::number is used to change the calVal(double)  to string, note only the static function can be accessed directly from function without an object
    ui->Display->setText(QString::number(g_calc_val));
    constexpr int num_of_nums = 10; // using it to avoid magic number if you do not like it,  can use macro #define NUMS 10
    QPushButton *numButtons[num_of_nums]; // use vector with resize is better? or next we will do it

    // connect all buttons, namely "Button" + the number from ui file
    for (int i = 0; i < num_of_nums; ++i){
        QString but_name = "Button" + QString:: number(i); // get the number from the user by clicking the numbers in the button
        numButtons[i] = MainWindow::findChild<QPushButton *>(but_name);

        // When the button is released call num_pressed()
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
      // make the connections in constructor, in order to whenever the users click to the number or menu, it immediately responds
    connect(ui->Add, SIGNAL(released()), this,  SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->Button4thBit, SIGNAL(released()), this, SLOT(FourBitButtonPressed()));
    // create a tooltip for a button 4thBit in the calc.
    ui->Button4thBit->setToolTip("To find 4th bit of the given number");

    connect(ui->Plus_by_bit, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    // create a tooltip for a button PLUS button in the calc.
    ui->Plus_by_bit->setToolTip("Plus two integer without using + operator");

    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeSignPressed()));
    // connect to equal button
    connect(ui->Equals, SIGNAL(released()), this, SLOT(EqualButtonPressed()));
    // connect to clear button
    connect(ui->Clear, SIGNAL(released()), this, SLOT(ClearButtonPressed()));


    // using connect with the lamda function
    connect(ui->actionAbout_the_Calc, &QAction::triggered,
            this, // control object to avoid crash if the signal is emitted after the receiver is deleted.
            [this](){
                AboutCalc();
            });

    connect(ui->actionExit, &QAction::triggered,
            this, // control object to avoid crash if the signal is emitted after the receiver is deleted.
            [this](){
                actionToExitPressed();
            });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: NumPressed(){
    QPushButton *button = (QPushButton *) sender();
    QString but_val =  button->text();
    QString display_val = ui->Display->text();
    // if the value in the Display is 0 or 0.0 hence replace it by the number from but_val that is given by users
    if (display_val.toDouble() == 0 || display_val.toDouble() == 0.0){
        ui->Display->setText(but_val);

    }
    else{
        // if the number is not 0 or 0.0 then + string
        QString new_val = display_val + but_val;
        // convert new_val to the double to calculate
        double double_new_val = new_val.toDouble();
        ui->Display->setText(QString::number(double_new_val, 'g', 16)); // precision = 16

    }
}

void MainWindow::MathButtonPressed(){

    g_add_trigger = false;
    //get the current value (string) from  display
    QString display_val = ui->Display->text();
    // and change it to double
    g_calc_val = display_val.toDouble();
    QPushButton *button = (QPushButton *) sender();

    QString but_val = button->text();
     // check which math buttom is given by user, so far only  + button is created but we will add more math operators in the future
     //note that here we use: CaseSensitive that mean we can search for words containing a sequence of letters matching the casing,
     //for example the users can enter ++ or +++ so with Qt::CaseSensitive, it still works

    if (QString::compare(but_val, "+", Qt::CaseSensitive) == 0 ){
        g_add_trigger = true;
    }
    else if (QString::compare(but_val, "-", Qt::CaseSensitive) == 0 ){
        g_sub_trigger = true;
    }
    else if (QString::compare(but_val, "/", Qt::CaseSensitive) == 0 ){
        g_div_trigger = true;
    }


     // Clear display
    ui->Display->setText("");
}

void MainWindow::EqualButtonPressed(){
   //ui->Display->setText(QString::number(0.0));
    double result = 0.0;
    // get the number from display
    QString display_val = ui->Display->text();
    // convert it to the double to implement the corresponding math operator
    double double_display_val = display_val.toDouble();
    // if +- button is pressed
    if (g_add_trigger || g_sub_trigger || g_div_trigger ){

        if(g_add_trigger){
            result = g_calc_val + double_display_val;
        }
        else if(g_sub_trigger){
            result = g_calc_val - double_display_val;
        }


        else if(g_div_trigger){
            if (double_display_val != 0.0 || double_display_val != 0){

                result = g_calc_val / double_display_val;
            }
        }
    }
     // if the user tries to divide for 0
    if (g_div_trigger && (double_display_val == 0 || double_display_val == 0.0)  ){
        ui->Display->setText("Divided by Zero");
        return;

    }
     // convert result to string, so we can show it in the Display
    ui->Display->setText(QString::number(result));

}

void MainWindow:: FourBitButtonPressed(){
    g_4bit_trigger = true;
    //get the current value (string) from  display
    QString display_val = ui->Display->text();
    // and change it to double
    g_calc_val = display_val.toDouble();
    double result = 0.0;
    // get the number from display

    if(g_4bit_trigger){

        result = ((int)g_calc_val>>3) & 1;

    }
    ui->Display->setText(QString::number(result));

}


void MainWindow::ClearButtonPressed(){
    g_calc_val = 0.0;
    ui->Display->setText(QString::number(g_calc_val));

}

void MainWindow::ChangeSignPressed(){
    // get the current value in the display
    QString display_val = ui->Display->text();
    QRegularExpression reg("[-]?[0-9.]*"); // if want to match exactly one digit so delete *
    QRegularExpressionMatch match = reg.match(display_val);

    if(match.hasMatch()){
        // change the number in the Display to the double number
        double dbl_display_val = display_val.toDouble();
                dbl_display_val = -1 * dbl_display_val; // change its sign
                ui->Display->setText(QString::number(dbl_display_val));
    }


}


void MainWindow:: actionToExitPressed(){



        QApplication::quit(); // it will call closeEvent function whenever QApplication::quit() is called.

}

/*void MainWindow:: on_actionExit_triggered(){

    QMessageBox msgBox;
    msgBox.setText("Do you really want to quit program?");
    //msgBox.setInformativeText("Do you really want to exit program?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    // set default button is No
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec(); // Shows the message box as a modal dialog, blocking until the user closes it.
    switch (ret){
    case QMessageBox::Yes: // Yes was clicked
        QApplication::quit();
    case QMessageBox::No: // No was clicked
            break;
    default:
        // should never be reached
            break;
    }

}
*/
void MainWindow::AboutCalc(){

    QMessageBox msgBox;
    msgBox.setText("This program is made based on my memory.");
    msgBox.exec();
}

void MainWindow::closeEvent(QCloseEvent *event){ // show prompt when user wants to close app

    event->ignore();

    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Do you really want to exit?", QMessageBox::No| QMessageBox::Yes))
    {
        event->accept();
    }

}
