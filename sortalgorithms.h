#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <QMainWindow>
#include <QString>
#include <QButtonGroup>

#include <vector>

namespace Ui {
class SortAlgorithms;
}

typedef int Index;
typedef int Value;

enum ESortAlgorithm
{
    SORT_INSERT,
    SORT_MERGE,
    SORT_QUICK,
    SORT_HEAP,
    SORT_SELECTION,
    SORT_BUBBLE,
    SORT_END
};

class SortAlgorithms : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortAlgorithms(QWidget *parent = 0);
    ~SortAlgorithms();

private:
    int getRandomEntryValue();

    void appendVectorContentToFootprint( const std::vector< Value >& kVecContent, const QString& strLabel = "" );

    void appendToFootprintOutput( const QString& strDisplayTxt );
    void clearFootprint();

    ////////////////////////////////////////////////////////////////////////////
    //  Sort Algorithms
    ////////////////////////////////////////////////////////////////////////////

    // Common helper functions
    void exchElements( std::vector< Value >& rkContent, Index indA, Index indB );
    // Compare and exchange to ensure A < B
    void exchCompAccend( std::vector< Value >& rkContent, Index indA, Index indB );

    // Insert Sort
    void doInsertionSort( std::vector< Value >& rkContent );

private slots:
    void on_btn_ClearFootprint_clicked();

    void on_btn_Randomize_clicked();
    void on_btn_DoSort_clicked();

private:
    Ui::SortAlgorithms* ui;
    QButtonGroup        m_btnGrpSortMethod;
};

#endif // SORTALGORITHMS_H
