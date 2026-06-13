#include "asset_editor.h"

asset_editor::asset_editor(QWidget* parent):
	QDialog(parent),
	ui(new Ui::asset_editor)
/*
*/{
    ui->setupUi(this);
}


void asset_editor::on_cancel_button_triggered()
/*
*/{
	this->close();
}

void asset_editor::on_confirm_button_triggered()
/*
*/{

}
	
	
	
	//ui->tag_text
			//TODO: generation / check of tag?
	//ui->location_combo
	//ui->system_combo
	//ui->subsystem_text
	//ui->type_combo
	//ui->description_text
	//ui->supplier_text
	//ui->input_date
	//ui->characteristics_text
	//ui->comment_text
	//ui->actionsTableView
