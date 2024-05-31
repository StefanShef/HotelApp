#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MyVector.cpp"
#include "MyVector.h"
#include <QApplication>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include <QAction>
#include <QtCharts>
#include <QRegularExpression>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

MyVector bookings;


void MainWindow::createIcons() {
    fileIcon = QPixmap("../OP/file.svg");
    saveIcon = QPixmap("../OP/save.svg");
    closeIcon = QPixmap("../OP/off.svg");
    plusIcon = QPixmap("../OP/plus.svg");
    downIcon = QPixmap("../OP/down.svg");
    upIcon = QPixmap("../OP/up.svg");
    xIcon = QPixmap("../OP/x.svg");
    searchIcon = QPixmap("../OP/search.svg");
    editIcon = QPixmap("../OP/pencil.svg");
    graphicIcon = QPixmap("../OP/graphic.svg");
    deleteIcon = QPixmap("../OP/delete.svg");
}

void MainWindow::tableView(){
    appTable = new QTableView();
    model = new QStandardItemModel(1, 8, this);
    appTable->setContextMenuPolicy(Qt::CustomContextMenu);
    appTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    appTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    /** Note **/
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("ФИО")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Дата заезда")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Дата выезда")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Тип номера")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Кол-во гостей")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("Email")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("Номер телефона")));
    model->setHorizontalHeaderItem(7, new QStandardItem(QString("Коментарий")));
    model->setHorizontalHeaderItem(8, new QStandardItem(QString("Способ оплаты")));
    model->setHorizontalHeaderItem(9, new QStandardItem(QString("Стоимость")));
    appTable->setModel(model);
    model->removeRow(0);
    for(int i = 0; i < bookings.Size(); i++){
        string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
        QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
        QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
        QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
        QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
        QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
        QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
        QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
        QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
        QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
        QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
        model->setItem(i,0,item1);
        model->setItem(i,1,item2);
        model->setItem(i,2,item3);
        model->setItem(i,3,item4);
        model->setItem(i,4,item5);
        model->setItem(i,5,item6);
        model->setItem(i,6,item7);
        model->setItem(i,7,item8);
        model->setItem(i,8,item9);
        model->setItem(i,9,item10);
    }
}

void MainWindow::setupCoreWidgets() {
    //testLayout();
    mainWidget = new QWidget();
    centralWidgetLayout = new QVBoxLayout();
    formLayout = new QGridLayout();
    buttonsLayout = new QHBoxLayout();
    savePushButton = new QPushButton(xIcon, "Удалить бронь", this);
    newPushButton = new QPushButton(plusIcon, "Добавить бронь", this);
    graphicPushButton = new QPushButton(graphicIcon, "Диаграмма", this);
    clearPushButton = new QPushButton(deleteIcon, "Удалить все", this);
    quitPushButton = new QPushButton(closeIcon, "Выйти", this);
    // TableView
    tableView();
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(newPushButton);
    buttonsLayout->addWidget(savePushButton);
    buttonsLayout->addWidget(graphicPushButton);
    buttonsLayout->addWidget(clearPushButton);
    buttonsLayout->addWidget(quitPushButton);

}

void MainWindow::deleteBooking() {
    if (bookings.Size() != 0) {
        int ind = bookInd->value();
        model->removeRows(0, bookings.Size());
        bookings.Remove(ind - 1);
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
    deleteWidget->close();
}

void MainWindow::deleteAll() {
    model->removeRows(0, bookings.Size());
    int len = bookings.Size();
    for (int i = 0; i < len; i++) {
        bookings.Remove(0);
    }
}

void MainWindow::clearAllRecords()
{
    int status = QMessageBox::question(this, "Вы уверены?",
    "После подтверждения будут удалены все записи " "<p> Вы уверены, что хотите удалить все записи? ", "Да, удалить", "Отмена", QString(), 1, 1);
    if (status == 0) {
        deleteAll();
    }
}

void MainWindow::exit()
{
    int status = QMessageBox::question(this, "Вы уверены?",
    "Вы уверены, что хотите выйти? :( " "<p> Выберите наиболее удобный способ ", "Выйти", "Сохранить и выйти", "Отмена", 2, 2);
    if (status == 0) {
        QApplication::quit();
    }
    else if (status == 1) {
        addDataToFile();
        QApplication::quit();
    }
}

void MainWindow::deleteBookingWidget() {
    deleteWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    QPushButton *confirm = new QPushButton(xIcon, "Удалить", this);
    bookInd = new QSpinBox;
    bookInd->setRange(1, bookings.Size());
    inputLayout->addRow("Введите номер удаляемой брони:", bookInd);
    inputLayout->addRow("", confirm);
    deleteWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(deleteBooking()));
    deleteWidget->setWindowTitle("Удаление записи...");
    deleteWidget->show();
}

void MainWindow::addBooking() {
    QString surname = QString(surnamenameLineEdit->text());
    if(surname != "") {
        surname.replace(0, 1, surname[0].toUpper());
        surname.replace(1, surname.length() - 1, surname.mid(1, surname.length() - 1).toLower());
    }
    QString nameB = QString(nameLineEdit->text());
    if (nameB != "") {
        nameB.replace(0, 1, nameB[0].toUpper());
        nameB.replace(1, nameB.length() - 1, nameB.mid(1, nameB.length() - 1).toLower());
    }
    QString fathersname = QString(fathersnameLineEdit->text());
    if (fathersname != "") {
        fathersname.replace(0, 1, fathersname[0].toUpper());
        fathersname.replace(1, fathersname.length() - 1, fathersname.mid(1, fathersname.length() - 1).toLower());
    }
    QString email = QString(emailLineEdit->text());
    QString phone = QString(phoneNumberLineEdit->text());
    QString comment = QString(commentLineEdit->text());
    QString type = QString(roomType->currentText());
    QDate arrivalDateB = QDate(arrivalDate->date());
    QDate departureDateB = QDate(departureDate->date());
    int quantity = guestsQuantity->value();
    QString pay = QString(payWay->currentText());
    ReservationList temp;
    if (phone.length() == 16) {
        if(surname != "") {
            temp.m_names[0] = surname.toStdString();
        }
        if (nameB != "") {
            temp.m_names[1] = nameB.toStdString();
        }
        if (fathersname != "") {
            temp.m_names[2] = fathersname.toStdString();
        }
        if (email != "") {
            temp.m_email = email.toStdString();
        }
        if (phone != "") {
            temp.m_phoneNumber = phone.toStdString();
        }
        if (comment != "") {
            temp.m_comments = comment.toStdString();
        }
        if (type != "") {
            temp.m_typeOfRoom = type.toStdString();
        }
        if (arrivalDateB.day() < 10 || arrivalDateB.month() < 10)
        {
            if(arrivalDateB.day() < 10 && arrivalDateB.month() < 10)
            {
                temp.m_dateOfArrival = "0" + to_string(arrivalDateB.day()) + "." + "0" + to_string(arrivalDateB.month()) + "." + to_string(arrivalDateB.year());
            }
            if(arrivalDateB.day() < 10 && arrivalDateB.month() >= 10)
            {
                temp.m_dateOfArrival = "0" + to_string(arrivalDateB.day()) + "." + to_string(arrivalDateB.month()) + "." + to_string(arrivalDateB.year());
            }
            if(arrivalDateB.day() >= 10 && arrivalDateB.month() < 10)
            {
                temp.m_dateOfArrival = to_string(arrivalDateB.day()) + "." + "0" + to_string(arrivalDateB.month()) + "." + to_string(arrivalDateB.year());
            }
        }
        else
        {
            temp.m_dateOfArrival = to_string(arrivalDateB.day()) + "." + to_string(arrivalDateB.month()) + "." + to_string(arrivalDateB.year());
        }
        if (departureDateB.day() < 10 || departureDateB.month() < 10)
        {
            if(departureDateB.day() < 10 && departureDateB.month() < 10)
            {
                temp.m_dateOfDeparture = "0" + to_string(departureDateB.day()) + "." + "0" + to_string(departureDateB.month()) + "." + to_string(departureDateB.year());
            }
            if(departureDateB.day() < 10 && departureDateB.month() >= 10)
            {
                temp.m_dateOfDeparture = "0" + to_string(departureDateB.day()) + "." + to_string(departureDateB.month()) + "." + to_string(departureDateB.year());
            }
            if(departureDateB.day() >= 10 && departureDateB.month() < 10)
            {
                temp.m_dateOfDeparture = to_string(departureDateB.day()) + "." + "0" + to_string(departureDateB.month()) + "." + to_string(departureDateB.year());
            }
        }
        else
        {
            temp.m_dateOfDeparture = to_string(departureDateB.day()) + "." + to_string(departureDateB.month()) + "." + to_string(departureDateB.year());
        }
        temp.m_numberOfSeats = to_string(quantity);
        temp.m_paymentMethod = pay.toStdString();
        int d, m, y;
        char d1[11]{};
        char d2[11]{};
        string d11 = temp.m_dateOfArrival;
        string d22 = temp.m_dateOfDeparture;
        strcpy(d1, d11.c_str());
        strcpy(d2, d22.c_str());
        sscanf(d1, "%d.%d.%d", &d, &m, &y);
        int date1 = y * 365 + m * 31 + d;
        sscanf(d2, "%d.%d.%d", &d, &m, &y);
        int date2 = y * 365 + m * 31 + d;
        if (date1 < date2) {
            if (temp.m_typeOfRoom == "Стандарт")
            {
                temp.m_price = to_string((date2 - date1) * 5000);
            }
            else
            {
                temp.m_price = to_string((date2 - date1) * 10000);
            }
            bookings.PushBack(temp);
            string fio = temp.m_names[0] + " " + temp.m_names[1] + " " + temp.m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(temp.m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(temp.m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(temp.m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(temp.m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(temp.m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(temp.m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(temp.m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(temp.m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(temp.m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
            addBookingW->close();
        }
        else {
            QMessageBox::warning(this, "Неверный ввод",
                                 " Дата выезда не может быть раньше даты заезда " "<p> Попробуйте еще раз", "Ок", QString(), QString(), 1, 1);
            addBookingW->close();
        }
    }
    else {
        QMessageBox::warning(this, "Неверный ввод",
                             "Введенный номер телефона слишком короткий " "<p> Попробуйте еще раз", "Ок", QString(), QString(), 1, 1);
        addBookingW->close();
    }
}

void MainWindow::addBookingWindow() {
    //int quantity{};
    addBookingW = new QWidget;
    surnamenameLineEdit = new QLineEdit;
    QRegularExpression nameCheck("[А-Яа-я]{0,32}");
    QValidator *validator9 = new QRegularExpressionValidator(nameCheck, this);
    surnamenameLineEdit->setValidator(validator9);
    nameLineEdit = new QLineEdit;
    nameLineEdit->setValidator(validator9);
    fathersnameLineEdit = new QLineEdit;
    emailLineEdit = new QLineEdit;
    fathersnameLineEdit->setValidator(validator9);
    QRegularExpression emailCheck("[a-z.0-9@]{0,36}");
    QValidator *validator7 = new QRegularExpressionValidator(emailCheck, this);
    emailLineEdit->setValidator(validator7);
    phoneNumberLineEdit = new QLineEdit;
    phoneNumberLineEdit->setInputMask("+7(000)000-00-00");
    commentLineEdit = new QLineEdit;
    QRegularExpression commentCheck("[a-z-A-Z-А-Я-а-я-0-9.@!?+]{0,100}");
    QValidator *validator8 = new QRegularExpressionValidator(commentCheck, this);
    commentLineEdit->setValidator(validator8);
    roomType = new QComboBox;
    QStringList types = {"Стандарт", "Люкс"};
    roomType->addItems(types);
    arrivalDate = new QDateEdit(QDate::currentDate());
    arrivalDate->setMinimumDate(QDate::currentDate());
    arrivalDate->setMaximumDate(QDate::currentDate().addYears(1));
    departureDate = new QDateEdit(QDate::currentDate());
    departureDate->setMinimumDate(QDate::currentDate().addDays(1));
    departureDate->setMaximumDate(QDate::currentDate().addDays(1).addYears(1));
    guestsQuantity = new QSpinBox;
    guestsQuantity->setRange(1, 6);
    payWay = new QComboBox;
    QStringList payWayList = {"Онлайн", "Наличными", "Картой"};
    payWay->addItems(payWayList);
    QPushButton *add = new QPushButton(plusIcon, "Добавить", this);
    connect(add, SIGNAL(clicked(bool)), this, SLOT(addBooking()));
    QFormLayout *layoutLeft = new QFormLayout;
    QFormLayout *layoutRight = new QFormLayout;
    QGridLayout *layout = new QGridLayout;
    layoutLeft->addRow("Фамилия:", surnamenameLineEdit);
    layoutLeft->addRow("Имя:", nameLineEdit);
    layoutLeft->addRow("Отчество:", fathersnameLineEdit);
    layoutLeft->addRow("Email:", emailLineEdit);
    layoutLeft->addRow("Номер телефона:", phoneNumberLineEdit);
    layoutLeft->addRow("Комметратий:", commentLineEdit);
    layoutRight->addRow("Тип номера:", roomType);
    layoutRight->addRow("Дата заезда:", arrivalDate);
    layoutRight->addRow("Дата выезда:", departureDate);
    layoutRight->addRow("Колличество гостей:", guestsQuantity);
    layoutRight->addRow("Способ оплаты:", payWay);
    layoutRight->addRow(add);
    layout->addLayout(layoutLeft, 0, 0);
    layout->addLayout(layoutRight, 0, 1);
    addBookingW->setLayout(layout);
    addBookingW->setWindowTitle("Добавление брони...");
    addBookingW->show();
}

void MainWindow::testLayout(){
    QWidget *window = new QWidget;
    window->setWindowTitle("Найденные брони:");
    window->resize(1280, 720);
    findTable = new QTableView();
    findItem = new QStandardItemModel(1, 10, this);
    findTable->setContextMenuPolicy(Qt::CustomContextMenu);
    findTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    findTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /** Note **/
    findItem->setHorizontalHeaderItem(0, new QStandardItem(QString("ФИО")));
    findItem->setHorizontalHeaderItem(1, new QStandardItem(QString("Дата заезда")));
    findItem->setHorizontalHeaderItem(2, new QStandardItem(QString("Дата выезда")));
    findItem->setHorizontalHeaderItem(3, new QStandardItem(QString("Тип номера")));
    findItem->setHorizontalHeaderItem(4, new QStandardItem(QString("Кол-во гостей")));
    findItem->setHorizontalHeaderItem(5, new QStandardItem(QString("Email")));
    findItem->setHorizontalHeaderItem(6, new QStandardItem(QString("Номер телефона")));
    findItem->setHorizontalHeaderItem(7, new QStandardItem(QString("Коментарий")));
    findItem->setHorizontalHeaderItem(8, new QStandardItem(QString("Способ оплаты")));
    findItem->setHorizontalHeaderItem(9, new QStandardItem(QString("Стоимость")));
    findTable->setModel(findItem);
    QFormLayout *menuLauout = new QFormLayout;
    menuLauout->addWidget(findTable);
    window->setLayout(menuLauout);
    window->show();
}

void MainWindow::addDataFromFile()
{ // Ввод из текстового файла
    ifstream fin;
    fin.open("/home/stepan/Документы/OP/inputStudents.txt");
    int newBookings{};
    while (!fin.eof())
    {
        ReservationList temp{};
        fin >> temp;
        if(temp.m_dateOfArrival != "-"){
            bookings.PushBack(temp);
            newBookings++;
        }
    }
    fin.close();
    for(int i = bookings.Size() - newBookings; i < bookings.Size(); i++)
    {
        string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
        QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
        QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
        QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
        QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
        QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
        QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
        QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
        QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
        QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
        QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
        model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
    }
}

void MainWindow::addDataToFile() {
    ofstream fout;
    fout.open("/home/stepan/Документы/OP/inputStudents.txt");
    for (int i = 0; i < bookings.Size(); i++)
    {
        fout << bookings[i];
    }
    fout.close();
}

void MainWindow::arrivalIncSort(){
    if (bookings.Size() != 0) {
        int d, m, y;
        for (int i = 0; i < bookings.Size() - 1; i++)
        {
            for (int j = 0; j < bookings.Size() - i - 1; j++)
            {
                char d1[11]{};
                char d2[11]{};
                string d11 = bookings[j].m_dateOfArrival;
                string d22 = bookings[j + 1].m_dateOfArrival;
                strcpy(d1, d11.c_str());
                strcpy(d2, d22.c_str());
                sscanf(d1, "%d.%d.%d", &d, &m, &y);
                int date1 = y * 365 + m * 31 + d;
                sscanf(d2, "%d.%d.%d", &d, &m, &y);
                int date2 = y * 365 + m * 31 + d;
                if (date1 > date2) // change here to change sorting direction
                {
                    ReservationList buff{};
                    buff = bookings[j];
                    bookings[j] = bookings[j + 1];
                    bookings[j + 1] = buff;
                }
            }
        }
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::arrivalDecSort() {
    if (bookings.Size() != 0) {
        int d, m, y;
        for (int i = 0; i < bookings.Size() - 1; i++)
        {
            for (int j = 0; j < bookings.Size() - i - 1; j++)
            {
                char d1[11]{};
                char d2[11]{};
                string d11 = bookings[j].m_dateOfArrival;
                string d22 = bookings[j + 1].m_dateOfArrival;
                strcpy(d1, d11.c_str());
                strcpy(d2, d22.c_str());
                sscanf(d1, "%d.%d.%d", &d, &m, &y);
                int date1 = y * 365 + m * 31 + d;
                sscanf(d2, "%d.%d.%d", &d, &m, &y);
                int date2 = y * 365 + m * 31 + d;
                if (date1 < date2) // change here to change sorting direction
                {
                    ReservationList buff{};
                    buff = bookings[j];
                    bookings[j] = bookings[j + 1];
                    bookings[j + 1] = buff;
                }
            }
        }
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::departureIncSort(){
    if (bookings.Size() != 0) {
        int d, m, y;
        for (int i = 0; i < bookings.Size() - 1; i++)
        {
            for (int j = 0; j < bookings.Size() - i - 1; j++)
            {
                char d1[11]{};
                char d2[11]{};
                string d11 = bookings[j].m_dateOfDeparture;
                string d22 = bookings[j + 1].m_dateOfDeparture;
                strcpy(d1, d11.c_str());
                strcpy(d2, d22.c_str());
                sscanf(d1, "%d.%d.%d", &d, &m, &y);
                int date1 = y * 365 + m * 31 + d;
                sscanf(d2, "%d.%d.%d", &d, &m, &y);
                int date2 = y * 365 + m * 31 + d;
                if (date1 > date2) // change here to change sorting direction
                {
                    ReservationList buff{};
                    buff = bookings[j];
                    bookings[j] = bookings[j + 1];
                    bookings[j + 1] = buff;
                }
            }
        }
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::departureDecSort() {
    if (bookings.Size() != 0) {
        int d, m, y;
        for (int i = 0; i < bookings.Size() - 1; i++)
        {
            for (int j = 0; j < bookings.Size() - i - 1; j++)
            {
                char d1[11]{};
                char d2[11]{};
                string d11 = bookings[j].m_dateOfArrival;
                string d22 = bookings[j + 1].m_dateOfArrival;
                strcpy(d1, d11.c_str());
                strcpy(d2, d22.c_str());
                sscanf(d1, "%d.%d.%d", &d, &m, &y);
                int date1 = y * 365 + m * 31 + d;
                sscanf(d2, "%d.%d.%d", &d, &m, &y);
                int date2 = y * 365 + m * 31 + d;
                if (date1 < date2) // change here to change sorting direction
                {
                    ReservationList buff{};
                    buff = bookings[j];
                    bookings[j] = bookings[j + 1];
                    bookings[j + 1] = buff;
                }
            }
        }
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::fioFind() {
    fioFindWidget->close();
    QString name = QString(inputForm->text());
    if (name != "") {
        name.replace(0, 1, name[0].toUpper());
        name.replace(1, name.length() - 1, name.mid(1, name.length() - 1).toLower());
    }
    testLayout();
    findItem->removeRow(0);
    for(int i = 0; i < bookings.Size(); i++)
    {
        string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
        string f = name.toStdString();
        if(f == bookings[i].m_names[0])
        {
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            findItem->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::dateFind() {
    dateFindWidget->close();
    QDate date = QDate(inputDateForm->date());
    string dateToFind = to_string(date.day()) + "." + to_string(date.month()) + "." + to_string(date.year());
    int d, m, y;
    char d1[11]{};
    char d2[11]{};
    strcpy(d1, dateToFind.c_str());
    sscanf(d1, "%d.%d.%d", &d, &m, &y);
    int date1 = y * 365 + m * 31 + d;
    testLayout();
    findItem->removeRow(0);
    for(int i = 0; i < bookings.Size(); i++)
    {
        string d22 = bookings[i].m_dateOfArrival;
        strcpy(d2, d22.c_str());
        sscanf(d2, "%d.%d.%d", &d, &m, &y);
        int date2 = y * 365 + m * 31 + d;
        if(date1 == date2)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            findItem->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::typeSearchFunction() {
    typeFindWidget->close();
    QString type = QString(inputTypeForm->currentText());
    testLayout();
    findItem->removeRow(0);
    for(int i = 0; i < bookings.Size(); i++)
    {
        if(type.toStdString() == bookings[i].m_typeOfRoom)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            findItem->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::commentFind() {
    commentFindWidget->close();
    QString comment = QString(inputForm->text());
    testLayout();
    findItem->removeRow(0);
    for(int i = 0; i < bookings.Size(); i++)
    {
        if(comment.toStdString() == bookings[i].m_comments)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            findItem->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
    }
}

void MainWindow::commentSearchLayout() {
    commentFindWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    inputForm = new QLineEdit;
    QRegularExpression commentCheck("[a-z-A-Z-А-Я-а-я-0-9.@!?+]{0,100}");
    QValidator *validator8 = new QRegularExpressionValidator(commentCheck, this);
    inputForm->setValidator(validator8);
    QPushButton *confirm = new QPushButton(searchIcon, " Найти", this);
    inputLayout->addRow("Введите комментарий:", inputForm);
    inputLayout->addRow("", confirm);
    commentFindWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(commentFind()));
    commentFindWidget->setWindowTitle("Поиск по комментарию...");
    commentFindWidget->show();
}

void MainWindow::dateSearchLayout() {
    dateFindWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    inputDateForm = new QDateEdit(QDate::currentDate());
    inputDateForm->setMinimumDate(QDate::fromString("01.01.2020", "dd.MM.yyyy"));
    inputDateForm->setMaximumDate(QDate::currentDate().addYears(1).addMonths(1));
    QPushButton *confirm = new QPushButton(searchIcon, " Найти", this);
    inputLayout->addRow("Введите дату заезда:", inputDateForm);
    inputLayout->addRow("", confirm);
    dateFindWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(dateFind()));
    dateFindWidget->setWindowTitle("Поиск по дате заезда...");
    dateFindWidget->show();
}

void MainWindow::fioSearchLayout() {
    fioFindWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    inputForm = new QLineEdit;
    QRegularExpression nameCheck("[А-Я-а-я]{0,32}");
    QValidator *validator9 = new QRegularExpressionValidator(nameCheck, this);
    inputForm->setValidator(validator9);
    QPushButton *confirm = new QPushButton(searchIcon, " Найти", this);
    inputLayout->addRow("Введите фамилию:", inputForm);
    inputLayout->addRow("", confirm);
    fioFindWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(fioFind()));
    fioFindWidget->setWindowTitle("Поиск по фамилии...");
    fioFindWidget->show();
}

void MainWindow::typeSearchLayout() {
    typeFindWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    inputTypeForm = new QComboBox;
    QStringList types = {"Стандарт", "Люкс"};
    inputTypeForm->addItems(types);
    QPushButton *confirm = new QPushButton(searchIcon, " Найти", this);
    inputLayout->addRow("Выберите тип номера:", inputTypeForm);
    inputLayout->addRow("", confirm);
    typeFindWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(typeSearchFunction()));
    typeFindWidget->setWindowTitle("Поиск по типу номера...");
    typeFindWidget->show();
}

void MainWindow::arrivalDateChange() {
    arrivalDateEditWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    bookInd = new QSpinBox;
    bookInd->setRange(1, bookings.Size());
    arrivalDateEditInput = new QDateEdit(QDate::currentDate());
    arrivalDateEditInput->setMinimumDate(QDate::currentDate());
    arrivalDateEditInput->setMaximumDate(QDate::currentDate().addYears(1));
    QPushButton *confirm = new QPushButton(editIcon, " Редактировать", this);
    inputLayout->addRow("Введите номер редактируемой брони:", bookInd);
    inputLayout->addRow("Выберите дату заеда:", arrivalDateEditInput);
    inputLayout->addRow("", confirm);
    arrivalDateEditWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(arrivalDateChangePush()));
    arrivalDateEditWidget->setWindowTitle("Редактирование даты заезда...");
    arrivalDateEditWidget->show();
}

void MainWindow::departureDateChange() {
    departureDateEditWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    bookInd = new QSpinBox;
    bookInd->setRange(1, bookings.Size());
    departureDateEditInput = new QDateEdit(QDate::currentDate());
    departureDateEditInput->setMinimumDate(QDate::currentDate());
    departureDateEditInput->setMaximumDate(QDate::currentDate().addDays(1).addYears(1));
    QPushButton *confirm = new QPushButton(editIcon, " Редактировать", this);
    inputLayout->addRow("Введите номер редактируемой брони:", bookInd);
    inputLayout->addRow("Выберите дату выеда:", departureDateEditInput);
    inputLayout->addRow("", confirm);
    departureDateEditWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(departureDateChangePush()));
    departureDateEditWidget->setWindowTitle("Редактирование даты выезда...");
    departureDateEditWidget->show();
}

void MainWindow::phoneChange() {
    phoneEditWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    bookInd = new QSpinBox;
    bookInd->setRange(1, bookings.Size());
    phoneEditInput = new QLineEdit;
    phoneEditInput->setInputMask("+7(000)000-00-00");
    QPushButton *confirm = new QPushButton(editIcon, " Редактировать", this);
    inputLayout->addRow("Введите номер редактируемой брони:", bookInd);
    inputLayout->addRow("Введите номер телефона:", phoneEditInput);
    inputLayout->addRow("", confirm);
    phoneEditWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(phoneChangePush()));
    phoneEditWidget->setWindowTitle("Редактирование номера телефона...");
    phoneEditWidget->show();
}

void MainWindow::emailChange() {
    emailEditWidget = new QWidget;
    QFormLayout *inputLayout = new QFormLayout;
    bookInd = new QSpinBox;
    bookInd->setRange(1, bookings.Size());
    emailEditInput = new QLineEdit;
    QRegularExpression emailCheck("[a-z0-9.@]{0,30}");
    QValidator *validator7 = new QRegularExpressionValidator(emailCheck, this);
    emailEditInput->setValidator(validator7);
    QPushButton *confirm = new QPushButton(editIcon, " Редактировать", this);
    inputLayout->addRow("Введите номер редактируемой брони:", bookInd);
    inputLayout->addRow("Введите email:", emailEditInput);
    inputLayout->addRow("", confirm);
    emailEditWidget->setLayout(inputLayout);
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(emailChangePush()));
    emailEditWidget->setWindowTitle("Редактирование email...");
    emailEditWidget->show();
}

void MainWindow::arrivalDateChangePush() {
    QDate newDate = QDate(arrivalDateEditInput->date());
    int ind = bookInd->value();
    int d, m, y;
    char d1[11]{};
    char d2[11]{};
    string d11 = to_string(newDate.day()) + "." + to_string(newDate.month()) + "." + to_string(newDate.year());
    string d22 = bookings[ind - 1].m_dateOfDeparture;
    strcpy(d1, d11.c_str());
    strcpy(d2, d22.c_str());
    sscanf(d1, "%d.%d.%d", &d, &m, &y);
    int date1 = y * 365 + m * 31 + d;
    sscanf(d2, "%d.%d.%d", &d, &m, &y);
    int date2 = y * 365 + m * 31 + d;
    if (date1 < date2) {
        if (newDate.day() < 10 || newDate.month() < 10)
        {
            if(newDate.day() < 10 && newDate.month() < 10)
            {
                bookings[ind - 1].m_dateOfArrival = "0" + to_string(newDate.day()) + "." + "0" + to_string(newDate.month()) + "." + to_string(newDate.year());
            }
            if(newDate.day() < 10 && newDate.month() >= 10)
            {
                bookings[ind - 1].m_dateOfArrival = "0" + to_string(newDate.day()) + "." + to_string(newDate.month()) + "." + to_string(newDate.year());
            }
            if(newDate.day() >= 10 && newDate.month() < 10)
            {
                bookings[ind - 1].m_dateOfArrival = to_string(newDate.day()) + "." + "0" + to_string(newDate.month()) + "." + to_string(newDate.year());
            }
        }
        else
        {
            bookings[ind - 1].m_dateOfArrival = to_string(newDate.day()) + "." + to_string(newDate.month()) + "." + to_string(newDate.year());
        }
        if (bookings[ind - 1].m_typeOfRoom == "Стандарт")
        {
            bookings[ind - 1].m_price = to_string((date2 - date1) * 5000);
        }
        else
        {
            bookings[ind - 1].m_price = to_string((date2 - date1) * 10000);
        }
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
        arrivalDateEditWidget->close();
    }
    else {
        QMessageBox::warning(this, "Неверный ввод",
        " Дата выезда не может быть раньше даты заезда " "<p> Попробуйте еще раз", "Ок", QString(), QString(), 1, 1);
        arrivalDateEditWidget->close();
    }
}

void MainWindow::departureDateChangePush() {
    QDate newDate = QDate(departureDateEditInput->date());
    int ind = bookInd->value();
    int d, m, y;
    char d1[11]{};
    char d2[11]{};
    string d11 = bookings[ind - 1].m_dateOfArrival;
    string d22 = to_string(newDate.day()) + "." + to_string(newDate.month()) + "." + to_string(newDate.year());;
    strcpy(d1, d11.c_str());
    strcpy(d2, d22.c_str());
    sscanf(d1, "%d.%d.%d", &d, &m, &y);
    int date1 = y * 365 + m * 31 + d;
    sscanf(d2, "%d.%d.%d", &d, &m, &y);
    int date2 = y * 365 + m * 31 + d;
    if (date1 < date2) {
        if (newDate.day() < 10 || newDate.month() < 10)
        {
            if(newDate.day() < 10 && newDate.month() < 10)
            {
                bookings[ind - 1].m_dateOfDeparture = "0" + to_string(newDate.day()) + "." + "0" + to_string(newDate.month()) + "." + to_string(newDate.year());
            }
            if(newDate.day() < 10 && newDate.month() >= 10)
            {
                bookings[ind - 1].m_dateOfDeparture = "0" + to_string(newDate.day()) + "." + to_string(newDate.month()) + "." + to_string(newDate.year());
            }
            if(newDate.day() >= 10 && newDate.month() < 10)
            {
                bookings[ind - 1].m_dateOfDeparture = to_string(newDate.day()) + "." + "0" + to_string(newDate.month()) + "." + to_string(newDate.year());
            }
        }
        else
        {
            bookings[ind - 1].m_dateOfDeparture = to_string(newDate.day()) + "." + to_string(newDate.month()) + "." + to_string(newDate.year());
        }
        if (bookings[ind - 1].m_typeOfRoom == "Стандарт")
        {
            bookings[ind - 1].m_price = to_string((date2 - date1) * 5000);
        }
        else
        {
            bookings[ind - 1].m_price = to_string((date2 - date1) * 10000);
        }
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
        departureDateEditWidget->close();
    }
    else {
        QMessageBox::warning(this, "Неверный ввод",
        " Дата выезда не может быть раньше даты заезда " "<p> Попробуйте еще раз", "Ок", QString(), QString(), 1, 1);
        departureDateEditWidget->close();
    }

}

void MainWindow::phoneChangePush() {
    QString newphone = QString(phoneEditInput->text());
    int ind = bookInd->value();
    if (newphone.length() == 16) {
        bookings[ind - 1].m_phoneNumber = newphone.toStdString();
        model->removeRows(0, bookings.Size());
        for (int i = 0; i < bookings.Size(); i++)
        {
            string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
            QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
            QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
            QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
            QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
            QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
            QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
            model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
        }
        phoneEditWidget->close();
    }
    else {
        QMessageBox::warning(this, "Неверный ввод",
        "Введенный номер телефона слишком короткий " "<p> Попробуйте еще раз", "Ок", QString(), QString(), 1, 1);
        phoneEditWidget->close();
    }
}

void MainWindow::emailChangePush() {
    QString newemail = QString(emailEditInput->text());
    int ind = bookInd->value();
    bookings[ind - 1].m_email = newemail.toStdString();
    model->removeRows(0, bookings.Size());
    for (int i = 0; i < bookings.Size(); i++)
    {
        string fio = bookings[i].m_names[0] + " " + bookings[i].m_names[1] + " " + bookings[i].m_names[2];
        QStandardItem *item1 = new QStandardItem(QString::fromStdString(fio));
        QStandardItem *item2 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfArrival));
        QStandardItem *item3 = new QStandardItem(QString::fromStdString(bookings[i].m_dateOfDeparture));
        QStandardItem *item4 = new QStandardItem(QString::fromStdString(bookings[i].m_typeOfRoom));
        QStandardItem *item5 = new QStandardItem(QString::fromStdString(bookings[i].m_numberOfSeats));
        QStandardItem *item6 = new QStandardItem(QString::fromStdString(bookings[i].m_email));
        QStandardItem *item7 = new QStandardItem(QString::fromStdString(bookings[i].m_phoneNumber));
        QStandardItem *item8 = new QStandardItem(QString::fromStdString(bookings[i].m_comments));
        QStandardItem *item9 = new QStandardItem(QString::fromStdString(bookings[i].m_paymentMethod));
        QStandardItem *item10 = new QStandardItem(QString::fromStdString(bookings[i].m_price));
        model->appendRow({item1, item2, item3, item4, item5, item6, item7, item8, item9, item10});
    }
    emailEditWidget->close();
}

void MainWindow::diogram() {
    QBarSet *set0 = new QBarSet("Стандарт");
    QBarSet *set1 = new QBarSet("Люкс");
    int standartQuantity{};
    int luxQuantity{};
    for(int i = 0; i < bookings.Size(); i++)
    {
        if (bookings[i].m_typeOfRoom == "Стандарт")
        {
            standartQuantity++;
        }
        else {
            luxQuantity++;
        }
    }
    *set0 << standartQuantity;
    *set1 << luxQuantity;
    int maxQ{};
    if (standartQuantity > luxQuantity) {
        maxQ = standartQuantity;
    }
    else {
        maxQ = luxQuantity;
    }
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Колличество забронированных номеров");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QString categories;
    categories = "Тип номера";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,maxQ + 1);
    axisY->setTickCount(maxQ + 2);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 800);
    chartView->setWindowTitle("Диаграмма");
    chartView->show();
}

void MainWindow::createMenuBar() {
    // Setup File Menu
    fileMenu = menuBar()->addMenu("Файлы");
    newAction = new QAction(fileIcon, "Добавить из файла", this);
    openAction = new QAction(saveIcon, "Сохранить в файл", this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    sortMenu = menuBar()->addMenu("Сортировка");
    arrivalIncSortAction = new QAction(upIcon, "По возрастанию даты заезда", this);
    arrivalDecSortAction = new QAction(downIcon, "По убыванию даты заезда", this);
    departureIncSortAction = new QAction(upIcon, "По возрастанию даты выезда", this);
    departureDecSortAction = new QAction(downIcon, "По убыванию даты выезда", this);
    sortMenu->addAction(arrivalIncSortAction);
    sortMenu->addAction(arrivalDecSortAction);
    sortMenu->addAction(departureIncSortAction);
    sortMenu->addAction(departureDecSortAction);
    searchMenu = menuBar()->addMenu("Поиск");
    fioSearch = new QAction(searchIcon, "Поиск по фамилии", this);
    dateSearch = new QAction(searchIcon, "Поиск по дате заезда", this);
    typeSearch = new QAction(searchIcon, "Поиск по типу номера", this);
    commentSearch = new QAction(searchIcon, "Поиск по комментарию", this);
    searchMenu->addAction(fioSearch);
    searchMenu->addAction(dateSearch);
    searchMenu->addAction(typeSearch);
    searchMenu->addAction(commentSearch);
    editMenu = menuBar()->addMenu("Редактирование");
    arrivalDateEdit = new QAction(editIcon, "Редактировать дату заеда", this);
    departureDateEdit = new QAction(editIcon, "Редактировать дату выезда", this);
    phoneEdit = new QAction(editIcon, "Редактировать номер телефона", this);
    emailEdit = new QAction(editIcon, "Редактировать email", this);
    editMenu->addAction(arrivalDateEdit);
    editMenu->addAction(departureDateEdit);
    editMenu->addAction(phoneEdit);
    editMenu->addAction(emailEdit);
    connect(newAction, SIGNAL(triggered()), this, SLOT(addDataFromFile()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(addDataToFile()));
    connect(arrivalIncSortAction, SIGNAL(triggered()), this, SLOT(arrivalIncSort()));
    connect(arrivalDecSortAction, SIGNAL(triggered()), this, SLOT(arrivalDecSort()));
    connect(departureIncSortAction, SIGNAL(triggered()), this, SLOT(departureIncSort()));
    connect(departureDecSortAction, SIGNAL(triggered()), this, SLOT(departureDecSort()));
    connect(fioSearch, SIGNAL(triggered()), this, SLOT(fioSearchLayout()));
    connect(dateSearch, SIGNAL(triggered()), this, SLOT(dateSearchLayout()));
    connect(typeSearch, SIGNAL(triggered()), this, SLOT(typeSearchLayout()));
    connect(commentSearch, SIGNAL(triggered()), this, SLOT(commentSearchLayout()));
    connect(arrivalDateEdit, SIGNAL(triggered()), this, SLOT(arrivalDateChange()));
    connect(departureDateEdit, SIGNAL(triggered()), this, SLOT(departureDateChange()));
    connect(phoneEdit, SIGNAL(triggered()), this, SLOT(phoneChange()));
    connect(emailEdit, SIGNAL(triggered()), this, SLOT(emailChange()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ReservationList first{"Стандарт", "01.01.2023", "02.02.2023", "2", "ДопВода", "Акимов", "Степан", "Владимирович", "stepaakimov@gmail.com", "+7(920)611-31-00", "Онлайн", "10000"};
    //bookings.PushBack(first);
    ui->setupUi(this);
    setWindowTitle("Приложение отеля");
    resize(1920, 1080);
    QPixmap bkgnd("../OP/back.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    createIcons();
    setupCoreWidgets();
    createMenuBar();
    connect(newPushButton, SIGNAL(clicked(bool)), this, SLOT(addBookingWindow()));
    connect(savePushButton, SIGNAL(clicked(bool)), this, SLOT(deleteBookingWidget()));
    connect(graphicPushButton, SIGNAL(clicked(bool)), this, SLOT(diogram()));
    connect(clearPushButton, SIGNAL(clicked(bool)), this, SLOT(clearAllRecords()));
    connect(quitPushButton, SIGNAL(clicked(bool)), this, SLOT(exit()));
    centralWidgetLayout->addLayout(formLayout);
    centralWidgetLayout->addWidget(appTable);
    centralWidgetLayout->addLayout(buttonsLayout);
    mainWidget->setLayout(centralWidgetLayout);
    setCentralWidget(mainWidget);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
