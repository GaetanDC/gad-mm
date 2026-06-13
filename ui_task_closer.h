/********************************************************************************
** Form generated from reading UI file 'task_closer.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_CLOSER_H
#define UI_TASK_CLOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task_closer
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *action_date;
    QComboBox *action_combo;
    QComboBox *tag_combo;
    QLabel *label_4;
    QLabel *label_5;
    QPlainTextEdit *Comment;
    QComboBox *actionBy_combo;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_button;
    QPushButton *confirm_button;

    void setupUi(QDialog *task_closer)
    {
        if (task_closer->objectName().isEmpty())
            task_closer->setObjectName("task_closer");
        task_closer->resize(400, 300);
        verticalLayout = new QVBoxLayout(task_closer);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(task_closer);
        widget->setObjectName("widget");
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        action_date = new QDateEdit(widget);
        action_date->setObjectName("action_date");
        action_date->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, action_date);

        action_combo = new QComboBox(widget);
        action_combo->setObjectName("action_combo");
        action_combo->setEnabled(false);
        action_combo->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, action_combo);

        tag_combo = new QComboBox(widget);
        tag_combo->setObjectName("tag_combo");
        tag_combo->setEnabled(false);
        tag_combo->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, tag_combo);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        Comment = new QPlainTextEdit(widget);
        Comment->setObjectName("Comment");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, Comment);

        actionBy_combo = new QComboBox(widget);
        actionBy_combo->setObjectName("actionBy_combo");
        actionBy_combo->setMaximumSize(QSize(220, 16777215));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, actionBy_combo);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(task_closer);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_button = new QPushButton(widget_2);
        cancel_button->setObjectName("cancel_button");

        horizontalLayout->addWidget(cancel_button);

        confirm_button = new QPushButton(widget_2);
        confirm_button->setObjectName("confirm_button");

        horizontalLayout->addWidget(confirm_button);


        verticalLayout->addWidget(widget_2);


        retranslateUi(task_closer);

        QMetaObject::connectSlotsByName(task_closer);
    } // setupUi

    void retranslateUi(QDialog *task_closer)
    {
        task_closer->setWindowTitle(QCoreApplication::translate("task_closer", "Close task", nullptr));
        label->setText(QCoreApplication::translate("task_closer", "Tag", nullptr));
        label_2->setText(QCoreApplication::translate("task_closer", "Action", nullptr));
        label_3->setText(QCoreApplication::translate("task_closer", "Action Date", nullptr));
        label_4->setText(QCoreApplication::translate("task_closer", "Action by", nullptr));
        label_5->setText(QCoreApplication::translate("task_closer", "Comment", nullptr));
        cancel_button->setText(QCoreApplication::translate("task_closer", "Cancel", nullptr));
        confirm_button->setText(QCoreApplication::translate("task_closer", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task_closer: public Ui_task_closer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_CLOSER_H
