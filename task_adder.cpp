#include "task_adder.h"

namespace Ui {
class task_adder;
}

task_adder::task_adder(QWidget* parent):
	QDialog(parent),
	ui(new Ui::task_adder)
/*
*/{

    ui->setupUi(this);

}
	
void task_adder::on_cancel_button_triggered()
/*
*/{
	this->close();
}

void task_adder::on_confirm_button_triggered()
/*
*/{


}


	//ui->tag_combo
	//ui->action_combo
	//ui->plan_date
