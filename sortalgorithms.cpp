#include "sortalgorithms.h"
#include "ui_sortalgorithms.h"

#include <QInputDialog>
#include <QVariant>
#include <QListWidgetItem>
#include <QtGlobal>

//#include <random>
//#include <chrono>
//using namespace std;

SortAlgorithms::SortAlgorithms(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortAlgorithms)
{
    ui->setupUi(this);
}

SortAlgorithms::~SortAlgorithms()
{
    delete ui;
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
    iNumOfEntries = QInputDialog::getInt( this,
                                          "Randomize Raw Input",
                                          "Please enter total number of inputs",
                                          10,
                                          0 );

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
