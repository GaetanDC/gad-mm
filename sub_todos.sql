 select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 'table' as component,
   'Todo' as title,
--	'Actions' as markdown,
--	'done,edit,delete' as actions,
	'Empty ...' as empty_title,
	TRUE as sort,
	FALSE as search,
	JSON('[{"name":"Edit","icon":"edit","link":"todo_form.sql?todo_id={id}"},
		{"name":"Delete","icon":"trash","link":"todo_del.sql?todo_id={id}"},
		{"name":"Close","icon":"check","link":"todo_done.sql?todo_id={id}"}
		]') as custom_actions

;

select 
	Asset as 'Asset',
	Short_desc as 'Action',
	DueDate as 'Due Date',
	ID as _sqlpage_id
	from log_M
	LEFT OUTER JOIN Actions on Action=tag
	WHERE Done=0
	ORDER BY DueDate,Asset
;


select 
    'button' as component,
    'center' as justify;
select 
    'todo_form.sql'     as link,
    'green' as color,
    'Add new todo'  as title,
    'circle-plus'  as icon;