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

void SortAlgorithms::appendVectorContentToFootprint( const std::vector< int > kVecContent, const QString& strLabel )
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
    int iNumOfEntries = 0;
    int iNewEntryVal = 0;
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
    for( int i = 0; i < iNumOfEntries; i++ )
    {
//        iNewEntryVal = kRandDistr( kRandEng );
        iNewEntryVal = qrand() % 60;
        QVariant kData( iNewEntryVal );
        QListWidgetItem* pkNewItem = new QListWidgetItem( QString::number( iNewEntryVal ),
                                                          ui->listW_RawInput );
        pkNewItem->setData( Qt::UserRole, kData );
    }
}

void SortAlgorithms::on_btn_DoSort_clicked()
{
    ESortAlgorithm      eCurrentMethod = static_cast< ESortAlgorithm >( m_btnGrpSortMethod.checkedId() );
    std::vector< int >  kRawInput;
    int                 iEntryVal = -1;

    // Grab values from UI
    kRawInput.reserve( ui->listW_RawInput->count() );
    for( int i = 0; i < ui->listW_RawInput->count(); i++ )
    {
        iEntryVal = ui->listW_RawInput->item( i )->data( Qt::UserRole ).toInt();
        kRawInput.push_back( iEntryVal );
    }
    appendVectorContentToFootprint( kRawInput, "Start to sort input:" );

    // Perform sort
    switch (eCurrentMethod) {
    case SORT_INSERT:

        break;
    default:
        break;
    }
}
