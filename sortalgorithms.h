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

// Using array implementation of heap
typedef std::vector< Value >    Heap;

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

    // Heap Sort
    void doHeapSort( std::vector< Value >& rkContent );
    void insertToHeap( Heap& rkHeap, const Value& kNewValue );
    Value popMaxFromHeap( Heap& rkHeap );
    void heapPromoteElement( Heap& rkHeap, Index indMod );
    void heapDemoteElement( Heap& rkHeap, Index indMod );

    // Quick Sort
    void    doQuickSort( std::vector< Value >& rkContent );
    void    quicksort( std::vector< Value >& rkContent, Index indStart, Index indEnd );
    Index   partition( std::vector< Value >& rkContent, Index indStart, Index indEnd );

    // Merge Sort
    void    doMergeSort( std::vector< Value >& rkContent );
    void    mergesort( std::vector< Value >& rkInput, std::vector< Value >& kAuxBuff,
                       Index indStart, Index indEnd );
    void    mergesections( std::vector< Value >& rkInput, std::vector< Value >& kAuxBuff,
                           Index indStart, Index indMid, Index indEnd );

private slots:
    void on_btn_ClearFootprint_clicked();

    void on_btn_Randomize_clicked();
    void on_btn_DoSort_clicked();

private:
    Ui::SortAlgorithms* ui;
    QButtonGroup        m_btnGrpSortMethod;
};

#endif // SORTALGORITHMS_H
