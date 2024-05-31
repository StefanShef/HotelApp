#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenu>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QTableView>
#include <QStandardItem>
#include <QHeaderView>
#include <QComboBox>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    // init methods
    void addBookingWindow();
    void addBooking();
    void deleteBookingWidget();
    void deleteBooking();
    void deleteAll();
    void addDataFromFile();
    void addDataToFile();
    void setupCoreWidgets();
    void tableView();
    void testLayout();
    void arrivalIncSort();
    void arrivalDecSort();
    void departureIncSort();
    void departureDecSort();
    void fioSearchLayout();
    void fioFind();
    void dateSearchLayout();
    void dateFind();
    void typeSearchLayout();
    void typeSearchFunction();
    void commentSearchLayout();
    void commentFind();
    void diogram();
    void arrivalDateChange();
    void departureDateChange();
    void phoneChange();
    void emailChange();
    void arrivalDateChangePush();
    void departureDateChangePush();
    void phoneChangePush();
    void emailChangePush();
    void clearAllRecords();
    void exit();

private:
    Ui::MainWindow *ui;
    //ToolBar config
    QToolBar *toolbar;
    QAction *newToolBarAction;
    QAction *openToolBarAction;
    QAction *closeToolBarAction;
    //Menu config
    QMenu *fileMenu;
    QMenu *sortMenu;
    QMenu *searchMenu;
    QMenu *editMenu;
    QAction *aboutAction;
    QAction *saveAction;
    QAction *cancelAction;
    QAction *openAction;
    QAction *newAction;
    QAction *arrivalIncSortAction;
    QAction *arrivalDecSortAction;
    QAction *departureIncSortAction;
    QAction *departureDecSortAction;
    QAction *fioSearch;
    QAction *dateSearch;
    QAction *typeSearch;
    QAction *commentSearch;
    QAction *arrivalDateEdit;
    QAction *departureDateEdit;
    QAction *emailEdit;
    QAction *phoneEdit;
    //Main Widget
    QWidget *mainWidget;
    QVBoxLayout *centralWidgetLayout;
    QGridLayout *formLayout;
    QHBoxLayout *buttonsLayout;
    QLabel *nameLabel;
    QLabel *dateOfBirthLabel;
    QLabel *phoneNumberLabel;
    QPushButton *savePushButton;
    QPushButton *newPushButton;
    QPushButton *graphicPushButton;
    QPushButton *clearPushButton;
    QPushButton *quitPushButton;
    QDateEdit *dateOfBirthEdit;
    QTableView *appTable;
    QStandardItemModel *model;
    // AddBooking
    QWidget *addBookingW;
    QLineEdit *surnamenameLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *fathersnameLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *commentLineEdit;
    QComboBox *roomType;
    QDateEdit *arrivalDate;
    QDateEdit *departureDate;
    QSpinBox *guestsQuantity;
    QComboBox *payWay;
    // DeleteBooking
    QWidget *deleteWidget;
    QSpinBox *bookInd;
    // Find widget
    QWidget *fioFindWidget;
    QTableView *findTable;
    QStandardItemModel *findItem;
    QLineEdit *inputForm;
    QString *name;
    QWidget *dateFindWidget;
    QDateEdit *inputDateForm;
    QDate *dateToFind;
    QWidget *typeFindWidget;
    QComboBox *inputTypeForm;
    QWidget *commentFindWidget;
    // Edit widget
    QWidget *arrivalDateEditWidget;
    QDateEdit *arrivalDateEditInput;
    QWidget *departureDateEditWidget;
    QDateEdit *departureDateEditInput;
    QWidget *phoneEditWidget;
    QLineEdit *phoneEditInput;
    QWidget *emailEditWidget;
    QLineEdit *emailEditInput;
    // Icons
    QPixmap fileIcon;
    QPixmap saveIcon;
    QPixmap closeIcon;
    QPixmap plusIcon;
    QPixmap upIcon;
    QPixmap downIcon;
    QPixmap xIcon;
    QPixmap searchIcon;
    QPixmap editIcon;
    QPixmap graphicIcon;
    QPixmap deleteIcon;
    // init methods
    void createIcons();
    void createMenuBar();
};
#endif // MAINWINDOW_H
