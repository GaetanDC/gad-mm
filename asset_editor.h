#ifndef ASSET_EDITOR_H
#define ASSET_EDITOR_H

#include "ui_asset_editor.h"


class asset_editor: public QDialog{
 	Q_OBJECT
public:
	asset_editor(QWidget*);
	inline ~asset_editor(){delete ui;};
	
private:
//	QSqlTableModel model;
	
	Ui::asset_editor *ui;

	void on_cancel_button_triggered();
	void on_confirm_button_triggered();
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
};
#endif //ifndef ASSET_EDITOR_H
