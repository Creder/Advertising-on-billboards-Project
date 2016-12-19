/********************************************************************************
** Form generated from reading UI file 'image_view.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_VIEW_H
#define UI_IMAGE_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Image_View
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *Image_View)
    {
        if (Image_View->objectName().isEmpty())
            Image_View->setObjectName(QStringLiteral("Image_View"));
        Image_View->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Image_View);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Image_View);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(Image_View);

        QMetaObject::connectSlotsByName(Image_View);
    } // setupUi

    void retranslateUi(QWidget *Image_View)
    {
        Image_View->setWindowTitle(QApplication::translate("Image_View", "Form", 0));
        label->setText(QApplication::translate("Image_View", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Image_View: public Ui_Image_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_VIEW_H
