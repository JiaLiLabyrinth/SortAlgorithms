/********************************************************************************
** Form generated from reading UI file 'sortalgorithms.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTALGORITHMS_H
#define UI_SORTALGORITHMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortAlgorithms
{
public:
    QWidget *centralWidget;
    QListWidget *listW_RawInput;
    QLabel *label;
    QTextEdit *txEd_SortFootprint;
    QLabel *label_2;
    QPushButton *btn_Randomize;
    QPushButton *btn_Add;
    QPushButton *btn_Remove;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rdBtn_InsertionSort;
    QRadioButton *rdBtn_HeapSort;
    QRadioButton *rdBtn_QuickSort;
    QRadioButton *rdBtn_MergeSort;
    QRadioButton *rdBtn_SelectSort;
    QRadioButton *rdBtn_BubbleSort;
    QPushButton *btn_DoSort;
    QLabel *label_3;
    QSpinBox *spBx_NumOfEntry;
    QPushButton *btn_ClearFootprint;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SortAlgorithms)
    {
        if (SortAlgorithms->objectName().isEmpty())
            SortAlgorithms->setObjectName(QStringLiteral("SortAlgorithms"));
        SortAlgorithms->resize(543, 538);
        centralWidget = new QWidget(SortAlgorithms);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listW_RawInput = new QListWidget(centralWidget);
        listW_RawInput->setObjectName(QStringLiteral("listW_RawInput"));
        listW_RawInput->setGeometry(QRect(20, 50, 171, 192));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 111, 16));
        txEd_SortFootprint = new QTextEdit(centralWidget);
        txEd_SortFootprint->setObjectName(QStringLiteral("txEd_SortFootprint"));
        txEd_SortFootprint->setGeometry(QRect(40, 290, 471, 181));
        txEd_SortFootprint->setAcceptDrops(false);
        txEd_SortFootprint->setUndoRedoEnabled(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 270, 111, 16));
        btn_Randomize = new QPushButton(centralWidget);
        btn_Randomize->setObjectName(QStringLiteral("btn_Randomize"));
        btn_Randomize->setGeometry(QRect(220, 50, 115, 32));
        btn_Add = new QPushButton(centralWidget);
        btn_Add->setObjectName(QStringLiteral("btn_Add"));
        btn_Add->setGeometry(QRect(220, 160, 115, 32));
        btn_Remove = new QPushButton(centralWidget);
        btn_Remove->setObjectName(QStringLiteral("btn_Remove"));
        btn_Remove->setGeometry(QRect(220, 200, 115, 32));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 20, 140, 211));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rdBtn_InsertionSort = new QRadioButton(groupBox);
        rdBtn_InsertionSort->setObjectName(QStringLiteral("rdBtn_InsertionSort"));
        rdBtn_InsertionSort->setChecked(true);

        verticalLayout->addWidget(rdBtn_InsertionSort);

        rdBtn_HeapSort = new QRadioButton(groupBox);
        rdBtn_HeapSort->setObjectName(QStringLiteral("rdBtn_HeapSort"));

        verticalLayout->addWidget(rdBtn_HeapSort);

        rdBtn_QuickSort = new QRadioButton(groupBox);
        rdBtn_QuickSort->setObjectName(QStringLiteral("rdBtn_QuickSort"));

        verticalLayout->addWidget(rdBtn_QuickSort);

        rdBtn_MergeSort = new QRadioButton(groupBox);
        rdBtn_MergeSort->setObjectName(QStringLiteral("rdBtn_MergeSort"));

        verticalLayout->addWidget(rdBtn_MergeSort);

        rdBtn_SelectSort = new QRadioButton(groupBox);
        rdBtn_SelectSort->setObjectName(QStringLiteral("rdBtn_SelectSort"));
        rdBtn_SelectSort->setEnabled(false);

        verticalLayout->addWidget(rdBtn_SelectSort);

        rdBtn_BubbleSort = new QRadioButton(groupBox);
        rdBtn_BubbleSort->setObjectName(QStringLiteral("rdBtn_BubbleSort"));
        rdBtn_BubbleSort->setEnabled(false);

        verticalLayout->addWidget(rdBtn_BubbleSort);

        btn_DoSort = new QPushButton(groupBox);
        btn_DoSort->setObjectName(QStringLiteral("btn_DoSort"));

        verticalLayout->addWidget(btn_DoSort);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 100, 71, 16));
        spBx_NumOfEntry = new QSpinBox(centralWidget);
        spBx_NumOfEntry->setObjectName(QStringLiteral("spBx_NumOfEntry"));
        spBx_NumOfEntry->setGeometry(QRect(300, 100, 42, 22));
        spBx_NumOfEntry->setMaximum(1000);
        spBx_NumOfEntry->setValue(10);
        btn_ClearFootprint = new QPushButton(centralWidget);
        btn_ClearFootprint->setObjectName(QStringLiteral("btn_ClearFootprint"));
        btn_ClearFootprint->setGeometry(QRect(430, 260, 75, 23));
        SortAlgorithms->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SortAlgorithms);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 543, 22));
        SortAlgorithms->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SortAlgorithms);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SortAlgorithms->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SortAlgorithms);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SortAlgorithms->setStatusBar(statusBar);

        retranslateUi(SortAlgorithms);

        QMetaObject::connectSlotsByName(SortAlgorithms);
    } // setupUi

    void retranslateUi(QMainWindow *SortAlgorithms)
    {
        SortAlgorithms->setWindowTitle(QApplication::translate("SortAlgorithms", "SortAlgorithms", 0));
        label->setText(QApplication::translate("SortAlgorithms", "List of Numbers", 0));
        label_2->setText(QApplication::translate("SortAlgorithms", "Sort Footprint", 0));
        btn_Randomize->setText(QApplication::translate("SortAlgorithms", "Randomize", 0));
        btn_Add->setText(QApplication::translate("SortAlgorithms", "Add", 0));
        btn_Remove->setText(QApplication::translate("SortAlgorithms", "Remove", 0));
        groupBox->setTitle(QApplication::translate("SortAlgorithms", "Method", 0));
        rdBtn_InsertionSort->setText(QApplication::translate("SortAlgorithms", "Insertion Sort", 0));
        rdBtn_HeapSort->setText(QApplication::translate("SortAlgorithms", "Heap Sort", 0));
        rdBtn_QuickSort->setText(QApplication::translate("SortAlgorithms", "Quick Sort", 0));
        rdBtn_MergeSort->setText(QApplication::translate("SortAlgorithms", "Merge Sort", 0));
        rdBtn_SelectSort->setText(QApplication::translate("SortAlgorithms", "Selection Sort", 0));
        rdBtn_BubbleSort->setText(QApplication::translate("SortAlgorithms", "Bubble Sort", 0));
        btn_DoSort->setText(QApplication::translate("SortAlgorithms", "Do Sort", 0));
        label_3->setText(QApplication::translate("SortAlgorithms", "Num. of Entry", 0));
        btn_ClearFootprint->setText(QApplication::translate("SortAlgorithms", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class SortAlgorithms: public Ui_SortAlgorithms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTALGORITHMS_H
