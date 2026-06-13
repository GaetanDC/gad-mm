#ifndef TASK_CLOSER_H
#define TASK_CLOSER_H
#include "ui_task_closer.h"


class task_closer: public QDialog{
 	Q_OBJECT
public:
	task_closer(QWidget* );
	inline ~task_closer(){delete ui;};
	
private:
	Ui::task_closer *ui;

	void on_cancel_button_triggered();
	void on_confirm_button_triggered();
	//ui->tag_combo
	//ui->action_combo
	//ui->action_date
	//ui->actionBy_combo
	//ui->Comment
};
#endif //ifndef TASK_CLOSER_H
