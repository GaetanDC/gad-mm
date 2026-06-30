 select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 'table' as component,
   'Logs' as title,
   'Empty ...' as empty_title,
	TRUE as sort,
	TRUE as search
;

select
	Asset,Action,DoneDate as 'Exectued on',People.Name as 'Executed by',Comment
	from Log_M, People
	WHERE Done=1
	INNER JOIN People ON (Log_M.Executor=People.ID)
;
