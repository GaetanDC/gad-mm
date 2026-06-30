-- select 'debug' as component, :Date, :user, :comment, :id, :tag, :action;

UPDATE Log_M SET DoneDate=:Date, executor=:user,Comment=:comment, Done=1 WHERE id=:id;

-- select 'debug' as component, :Date, :user, :comment, :id, :tag, :action;

INSERT INTO Log_M (Asset, Action, SubAction, DueDate, Done, Executor)
	SELECT :tag as Asset,
		:action as Action,
		Template_Planning.Comment as SubAction,
		date(:Date,concat('+',Template_Planning.Delay,' DAYS' )) as DueDate,
		0 as Done,
		0 as Executor
	FROM Template_Planning 
	WHERE Template_Planning.asset = :tag AND Template_Planning.Action=:action
;


 select 'redirect' AS component, 'sub_todos.sql' AS link;