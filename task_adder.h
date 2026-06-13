#ifndef TASK_ADDER_H
#define TASK_ADDER_H

#include "ui_task_adder.h"

class task_adder: public QDialog{
 	Q_OBJECT
public:
	task_adder(QWidget* parent);
	inline ~task_adder(){delete ui;};
	
private:
	Ui::task_adder *ui;

	void on_cancel_button_triggered();
	void on_confirm_button_triggered();
	//ui->tag_combo
	//ui->action_combo
	//ui->plan_date
};
#endif //ifndef TASK_ADDER_H
