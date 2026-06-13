/********************************************************************************
** Form generated from reading UI file 'asset_editor.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSET_EDITOR_H
#define UI_ASSET_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_asset_editor
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *tag_text;
    QLabel *label_2;
    QComboBox *location_combo;
    QLabel *label_3;
    QComboBox *system_combo;
    QLabel *label_4;
    QLineEdit *subsystem_text;
    QLabel *label_5;
    QComboBox *type_combo;
    QLabel *label_6;
    QPlainTextEdit *description_text;
    QLabel *label_7;
    QLineEdit *supplier_text;
    QLabel *label_8;
    QDateEdit *input_date;
    QLabel *label_9;
    QLineEdit *characteristics_text;
    QLabel *label_10;
    QPlainTextEdit *comment_text;
    QTableView *actionsTableView;
    QLabel *label_11;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_button;
    QPushButton *add_button;

    void setupUi(QDialog *asset_editor)
    {
        if (asset_editor->objectName().isEmpty())
            asset_editor->setObjectName("asset_editor");
        asset_editor->resize(745, 768);
        gridLayout = new QGridLayout(asset_editor);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(asset_editor);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        tag_text = new QLineEdit(widget);
        tag_text->setObjectName("tag_text");
        tag_text->setMaximumSize(QSize(70, 16777215));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, tag_text);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        location_combo = new QComboBox(widget);
        location_combo->setObjectName("location_combo");
        location_combo->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, location_combo);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        system_combo = new QComboBox(widget);
        system_combo->setObjectName("system_combo");
        system_combo->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, system_combo);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        subsystem_text = new QLineEdit(widget);
        subsystem_text->setObjectName("subsystem_text");
        subsystem_text->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, subsystem_text);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        type_combo = new QComboBox(widget);
        type_combo->setObjectName("type_combo");
        type_combo->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, type_combo);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        description_text = new QPlainTextEdit(widget);
        description_text->setObjectName("description_text");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(5);
        sizePolicy1.setHeightForWidth(description_text->sizePolicy().hasHeightForWidth());
        description_text->setSizePolicy(sizePolicy1);
        description_text->setMaximumSize(QSize(16777215, 60));

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, description_text);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_7);

        supplier_text = new QLineEdit(widget);
        supplier_text->setObjectName("supplier_text");
        supplier_text->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, supplier_text);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_8);

        input_date = new QDateEdit(widget);
        input_date->setObjectName("input_date");
        input_date->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, input_date);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, label_9);

        characteristics_text = new QLineEdit(widget);
        characteristics_text->setObjectName("characteristics_text");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, characteristics_text);

        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        formLayout->setWidget(9, QFormLayout::ItemRole::LabelRole, label_10);

        comment_text = new QPlainTextEdit(widget);
        comment_text->setObjectName("comment_text");
        comment_text->setMaximumSize(QSize(16777215, 60));

        formLayout->setWidget(9, QFormLayout::ItemRole::FieldRole, comment_text);

        actionsTableView = new QTableView(widget);
        actionsTableView->setObjectName("actionsTableView");

        formLayout->setWidget(10, QFormLayout::ItemRole::FieldRole, actionsTableView);

        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");

        formLayout->setWidget(10, QFormLayout::ItemRole::LabelRole, label_11);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(asset_editor);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_button = new QPushButton(widget_2);
        cancel_button->setObjectName("cancel_button");

        horizontalLayout->addWidget(cancel_button);

        add_button = new QPushButton(widget_2);
        add_button->setObjectName("add_button");

        horizontalLayout->addWidget(add_button);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(asset_editor);

        QMetaObject::connectSlotsByName(asset_editor);
    } // setupUi

    void retranslateUi(QDialog *asset_editor)
    {
        asset_editor->setWindowTitle(QCoreApplication::translate("asset_editor", "Add an asset", nullptr));
        label->setText(QCoreApplication::translate("asset_editor", "Tag (unique)", nullptr));
        label_2->setText(QCoreApplication::translate("asset_editor", "Location", nullptr));
        label_3->setText(QCoreApplication::translate("asset_editor", "System", nullptr));
        label_4->setText(QCoreApplication::translate("asset_editor", "Sub System", nullptr));
        label_5->setText(QCoreApplication::translate("asset_editor", "Type", nullptr));
        label_6->setText(QCoreApplication::translate("asset_editor", "Description", nullptr));
        label_7->setText(QCoreApplication::translate("asset_editor", "Supplier", nullptr));
        label_8->setText(QCoreApplication::translate("asset_editor", "Input Date", nullptr));
        label_9->setText(QCoreApplication::translate("asset_editor", "Characteristics", nullptr));
        label_10->setText(QCoreApplication::translate("asset_editor", "Comment", nullptr));
        label_11->setText(QCoreApplication::translate("asset_editor", "Actions", nullptr));
        cancel_button->setText(QCoreApplication::translate("asset_editor", "Cancel", nullptr));
        add_button->setText(QCoreApplication::translate("asset_editor", "ADD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class asset_editor: public Ui_asset_editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSET_EDITOR_H
