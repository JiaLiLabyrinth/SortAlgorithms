#include "sortalgorithms.h"
#include "ui_sortalgorithms.h"

#include <QInputDialog>
#include <QVariant>
#include <QListWidgetItem>
#include <QtGlobal>

//#include <random>
//#include <chrono>
#include <string>
#include <sstream>
using namespace std;

SortAlgorithms::SortAlgorithms(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortAlgorithms)
{
    ui->setupUi(this);

    m_btnGrpSortMethod.addButton( ui->rdBtn_BubbleSort,     SORT_BUBBLE );
    m_btnGrpSortMethod.addButton( ui->rdBtn_HeapSort,       SORT_HEAP );
    m_btnGrpSortMethod.addButton( ui->rdBtn_InsertionSort,  SORT_INSERT );
    m_btnGrpSortMethod.addButton( ui->rdBtn_MergeSort,      SORT_MERGE );
    m_btnGrpSortMethod.addButton( ui->rdBtn_QuickSort,      SORT_QUICK );
    m_btnGrpSortMethod.addButton( ui->rdBtn_SelectSort,     SORT_SELECTION );
    m_btnGrpSortMethod.setExclusive( true );
}

SortAlgorithms::~SortAlgorithms()
{
    delete ui;
}

void SortAlgorithms::appendVectorContentToFootprint( const std::vector< Value >& kVecContent, const QString& strLabel )
{
    QString strDispContent;
    std::ostringstream  os;

    for( size_t i = 0; i < kVecContent.size(); i++ )
    {
        os.width( 3 );
        os.fill( ' ' );
        os << std::left << kVecContent[ i ];
    }

    if( strLabel.length() > 0 )
    {
        strDispContent = strLabel;
        strDispContent += " ";
    }
    strDispContent += QString::fromStdString( os.str() );

    appendToFootprintOutput( strDispContent );
}

void SortAlgorithms::appendToFootprintOutput( const QString& strDisplayTxt )
{
    ui->txEd_SortFootprint->append( QString(">> ") + strDisplayTxt );
}

void SortAlgorithms::clearFootprint()
{
    ui->txEd_SortFootprint->clear();
}

void SortAlgorithms::on_btn_ClearFootprint_clicked()
{
    clearFootprint();
}

void SortAlgorithms::on_btn_Randomize_clicked()
{
    Index   iNumOfEntries = 0;
    Value   kNewEntryVal = 0;
//    // For random entry generator
//    unsigned int uSeed = std::chrono::system_clock::now().time_since_epoch().count();
//    default_random_engine kRandEng( uSeed );
//    uniform_int_distribution< int > kRandDistr(0, 60);

    // Ask for number of entries
    iNumOfEntries = ui->spBx_NumOfEntry->value();

    if( iNumOfEntries <= 0 )
    {
        return;
    }

    // Remove old entries
    ui->listW_RawInput->clear();

    // Start generating random numbers
    for( Index i = 0; i < iNumOfEntries; i++ )
    {
//        iNewEntryVal = kRandDistr( kRandEng );
        kNewEntryVal = qrand() % 60;
        QVariant kData( kNewEntryVal );
        QListWidgetItem* pkNewItem = new QListWidgetItem( kData.toString(), // QString::number( kNewEntryVal )
                                                          ui->listW_RawInput );
        pkNewItem->setData( Qt::UserRole, kData );
    }
}

void SortAlgorithms::on_btn_DoSort_clicked()
{
    ESortAlgorithm          eCurrentMethod = static_cast< ESortAlgorithm >( m_btnGrpSortMethod.checkedId() );
    std::vector< Value >    kRawInput;
    Value                   kEntryVal = -1;
    bool                    bSortComplete = true;

    // Grab values from UI
    kRawInput.reserve( ui->listW_RawInput->count() );
    for( int i = 0; i < ui->listW_RawInput->count(); i++ )
    {
        kEntryVal = ui->listW_RawInput->item( i )->data( Qt::UserRole ).value< Value >();
        kRawInput.push_back( kEntryVal );
    }
    appendVectorContentToFootprint( kRawInput, "Sort input:" );

    // Perform sort
    switch (eCurrentMethod) {
    case SORT_INSERT:
        doInsertionSort( kRawInput );
        break;
    case SORT_HEAP:
        doHeapSort( kRawInput );
        break;
    default:
        bSortComplete = false;
        break;
    }

    if( bSortComplete )
    {
        appendVectorContentToFootprint( kRawInput, "Sort Result =>" );
    }
}

////////////////////////////////////////////////////////////////////////////
//  Sort Algorithms
////////////////////////////////////////////////////////////////////////////
// Common helper functions
void SortAlgorithms::exchElements( std::vector< Value >& rkContent, Index indA, Index indB )
{
    Value kTempVal = rkContent[ indA ];
    rkContent[ indA ] = rkContent[ indB ];
    rkContent[ indB ] = kTempVal;
}

// Compare and exchange to ensure A < B afterwares
void SortAlgorithms::exchCompAccend( std::vector< Value >& rkContent, Index indA, Index indB )
{
    if( rkContent[ indA ] > rkContent[ indB ] )
    {
        exchElements( rkContent, indA, indB );
    }
}

// Insert Sort
void SortAlgorithms::doInsertionSort( std::vector< Value >& rkContent )
{
    Index indL = 0;
    Index indR = rkContent.size() - 1;

    appendToFootprintOutput( "Begin Insertion Sort" );

    // Do a one-pass Bubble-sort to ensure the first element is the smallest
    // so that we can use it as a sentinel
    for( Index indI = indR; indI > indL; indI-- )
    {
        exchCompAccend( rkContent, indI - 1, indI );
    }

    appendVectorContentToFootprint( rkContent, "Sentinel Setup:" );

    // For the real thing
    // The sentinel setup ensures the first two entries are in order, so let's just
    // start checking with the 3 element
    for( Index indI = indL + 2; indI <= indR; indI++ )
    {
        Index indTravel = indI;
        Value kTravel   = rkContent[ indI ];

        // If value for the traveling entry less then previous one, move to the left
        // until traveling entry encounters a previous value less than itself
        while( kTravel < rkContent[ indTravel - 1 ] )
        {
            // Move previous entry to right
            rkContent[ indTravel ] = rkContent[ indTravel - 1 ];
            indTravel--;
        }
        rkContent[ indTravel ] = kTravel;

        appendVectorContentToFootprint( rkContent, QString("Pass %1:\t").arg( indI ) );
    }

    appendToFootprintOutput( "Finished Insertion Sort" );
}

// Heap Sort
void SortAlgorithms::doHeapSort( std::vector< Value >& rkContent )
{
    Heap kHeap;

    appendToFootprintOutput( "Begin Heap Sort" );

    // Build heap from content
    for( Index indI = 0; indI < rkContent.size(); indI++ )
    {
        insertToHeap( kHeap, rkContent[ indI ] );

        appendVectorContentToFootprint( kHeap, QString("Build Heap Pass %1").arg( indI ) );
    }

    // Insert values back to content by removing max from heap
    Index indInsert = kHeap.size() - 1;
    while( kHeap.size() > 0 && indInsert >= 0 )
    {
        Value kMax = popMaxFromHeap( kHeap );
        rkContent[ indInsert-- ] = kMax;

        appendVectorContentToFootprint( kHeap, QString("Rm Max %1").arg( kMax ) );
    }

    // After heap is built
    appendToFootprintOutput( "Finished Heap Sort" );
}

void SortAlgorithms::insertToHeap( Heap& rkHeap, const Value& kNewValue )
{
    // Add new element to bottom of heap
    rkHeap.push_back( kNewValue );

    // Heapify, bottom-up
    heapPromoteElement( rkHeap, rkHeap.size() - 1 );
}

Value SortAlgorithms::popMaxFromHeap( Heap& rkHeap )
{
    Value kMaxEntry = -1;
    Index indLast = rkHeap.size() - 1;

    if( indLast >= 0 )
    {
        // Have top (max) element swich place with last bottom item
        exchElements( rkHeap, 0, indLast );

        // Remove max element from heap
        kMaxEntry = rkHeap[ indLast ];
        rkHeap.pop_back();

        // Heapify, top-down
        heapDemoteElement( rkHeap, 0 );
    }

    return kMaxEntry;
}

void SortAlgorithms::heapPromoteElement( Heap& rkHeap, Index indMod )
{
    Index indParent = indMod / 2;
    while( indMod >= 1 & rkHeap[ indMod ] > rkHeap[ indParent ] )
    {
        exchElements( rkHeap, indMod, indParent );
        indMod = indParent;
        indParent = indMod / 2;
    }
}

void SortAlgorithms::heapDemoteElement( Heap& rkHeap, Index indMod )
{
    Index   indLast = rkHeap.size();
    bool    bFoundRightPlace = false;

    while( !bFoundRightPlace && ( indMod * 2 ) <= indLast )
    {
        Index indChild1 = indMod * 2;
        Index indChild2 = indMod * 2 + 1;
        Index indChildLarger = indChild1;   // Presume child 1 has the larger value

        // Determine which child is larger (i.e. the one to replace parent with if demotion is to occur)
        if( indChild1 < indLast                         // There are indeed 2 children
         && rkHeap[ indChild1 ] < rkHeap[ indChild2 ] ) // Child 2 is larger
        {
            indChildLarger = indChild2;
        }

        if( rkHeap[ indChildLarger ] < rkHeap[ indMod ] )
        {   // Element for indMod is where it should be in heap; Quit heapfy process
            bFoundRightPlace = true;
        }
        else
        {   // Move Element for indMod downwards
            exchElements( rkHeap, indMod, indChildLarger );
            indMod = indChildLarger;
        }
    }
}
