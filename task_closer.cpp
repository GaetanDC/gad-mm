#include "task_closer.h"


task_closer::task_closer(QWidget* parent):
	QDialog(parent),
	ui(new Ui::task_closer)
/*
*/{
	    ui->setupUi(this);
}

void task_closer::on_cancel_button_triggered()
/*
*/{
		this->close();
}

void task_closer::on_confirm_button_triggered()
/*
*/{
	
}



	//ui->tag_combo
	//ui->action_combo
	//ui->action_date
	//ui->actionBy_combo
	//ui->Comment
