#ifndef MYTABLEMODELS_H
#define MYTABLEMODELS_H

#include <QAbstractTableModel>
#include <QUndoStack>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDate>



class myTableModel : public QAbstractTableModel{
    Q_OBJECT
protected:
    myTableModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent = 0);

public:
    virtual ~myTableModel();
    virtual inline int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent) return 0;};
    virtual inline int columnCount(const QModelIndex &parent) const {Q_UNUSED(parent) return 0;};

    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    virtual Qt::ItemFlags flags(const QModelIndex& index) const;
 	 virtual bool setData(const QModelIndex & index, const QVariant & value, int role);
	
	virtual int getEditCol(){return max_col_num-1;}
	inline int getDeleteCol(){return max_col_num;};
    virtual void refresh();    
//    void refreshActive(); //cycle through all task to recalculate the active state
	virtual QString toString()=0;

protected:
	 void safeComplete(const QModelIndex & index, bool state);
	 void safeEdit(const QModelIndex & index, QString _raw);
    void safeAdd(QString title, QString context);
    void safeDelete(QUuid index);
    QSqlQuery* q;
 	 QUndoStack* undoS;

signals:
public slots:
	virtual void refreshData()=0;
	void startModelChange(QString desc);
	void endModelChange();

protected:
	int max_col_num=0;
};




struct todoItem{QString asset; QString action; QDate dueDate;};

class myTodoModel : public myTableModel{
    Q_OBJECT
protected:
	int max_col_num=5;

public:
   explicit myTodoModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent = 0);
   ~myTodoModel();
	QString toString();
	inline int rowCount(const QModelIndex &parent) const {Q_UNUSED(parent) return content.size();};
	inline int columnCount(const QModelIndex &parent) const {Q_UNUSED(parent) return 3+2;};

	virtual QVariant data(const QModelIndex &index, int role) const;

protected:
	QList<todoItem> content;
	
public slots:
	virtual void refreshData();
};




struct assetItem{QString Tag;
						QString Location;
						QString System;
						QString subSystem;
						QString Type;
						QString subType;
						QString description;
						QString Supplier;
						QDate Date_install;
						QString Characteristics;
						QString Comment;
						QString Parent;
						};
						
class myAssetsModel : public myTableModel{
    Q_OBJECT
protected:
	int max_col_num=14;	

public:
    explicit myAssetsModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent = 0);
    ~myAssetsModel();
	QString toString();
	inline int rowCount(const QModelIndex &parent) const {Q_UNUSED(parent) return content.size();};
	inline int columnCount(const QModelIndex &parent) const {Q_UNUSED(parent) return max_col_num;};
	virtual QVariant data(const QModelIndex &index, int role) const;

protected:
	QList<assetItem> content;

public slots:
	virtual void refreshData();
};



struct logItem{	int ID;
						QString asset;
						QString Action;
						QDate Planned_date;
						bool Done;
						QDate Actual_date;
						QString Executor;
						QString Comment;
						};

class myLogModel : public myTableModel{
    Q_OBJECT
protected:
	int max_col_num=8;	

public:
    explicit myLogModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent = 0);
    ~myLogModel();
	QString toString();
	inline int rowCount(const QModelIndex &parent) const {Q_UNUSED(parent) return content.size();};
	inline int columnCount(const QModelIndex &parent) const {Q_UNUSED(parent) return max_col_num;};
	virtual QVariant data(const QModelIndex &index, int role) const;

protected:
	QList<logItem> content;

public slots:
	virtual void refreshData();
};





#endif // MYTABLEMODELS_H
