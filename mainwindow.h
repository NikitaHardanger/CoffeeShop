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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonViewCart_clicked();

    void on_buttonBackToSelection_clicked();

    void on_buttonPay_clicked();

    void on_buttonConfirm_clicked();

    void on_buttonConfirm_2_clicked();

    void on_buttonBackToCart_clicked();

    void on_buttonAddCapucchino_clicked();

    void on_buttonAddLatte_clicked();

    void on_buttonAddEspresso_clicked();

    void on_buttonAddFrappucchino_clicked();

    void on_buttonAddIcedTeas_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
