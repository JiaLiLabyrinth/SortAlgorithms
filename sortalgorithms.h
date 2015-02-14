#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <QMainWindow>

namespace Ui {
class SortAlgorithms;
}

class SortAlgorithms : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortAlgorithms(QWidget *parent = 0);
    ~SortAlgorithms();

private slots:
    void on_pushButton_clicked();

    void on_btn_Randomize_clicked();

private:
    Ui::SortAlgorithms *ui;
};

#endif // SORTALGORITHMS_H
