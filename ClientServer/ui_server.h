/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTreeView *fileTree;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *conectarButton;
    QLabel *label;
    QSpinBox *portaBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *enviarButton;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(553, 218);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Server->sizePolicy().hasHeightForWidth());
        Server->setSizePolicy(sizePolicy);
        Server->setMinimumSize(QSize(0, 0));
        Server->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fileTree = new QTreeView(centralWidget);
        fileTree->setObjectName(QStringLiteral("fileTree"));

        verticalLayout->addWidget(fileTree);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        conectarButton = new QPushButton(centralWidget);
        conectarButton->setObjectName(QStringLiteral("conectarButton"));
        conectarButton->setMinimumSize(QSize(100, 24));
        conectarButton->setMaximumSize(QSize(100, 24));
        conectarButton->setIconSize(QSize(16, 16));

        horizontalLayout_4->addWidget(conectarButton);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(label);

        portaBox = new QSpinBox(centralWidget);
        portaBox->setObjectName(QStringLiteral("portaBox"));
        portaBox->setMinimumSize(QSize(0, 24));
        portaBox->setMaximumSize(QSize(16777215, 24));
        portaBox->setMinimum(1024);
        portaBox->setMaximum(65535);

        horizontalLayout_4->addWidget(portaBox);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        enviarButton = new QPushButton(centralWidget);
        enviarButton->setObjectName(QStringLiteral("enviarButton"));
        enviarButton->setMinimumSize(QSize(100, 24));
        enviarButton->setMaximumSize(QSize(100, 24));

        horizontalLayout->addWidget(enviarButton);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_6);

        Server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 553, 22));
        Server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Server->setStatusBar(statusBar);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "MainWindow", Q_NULLPTR));
        conectarButton->setText(QApplication::translate("Server", "Conectar", Q_NULLPTR));
        label->setText(QApplication::translate("Server", "Porta:", Q_NULLPTR));
        enviarButton->setText(QApplication::translate("Server", "Enviar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
