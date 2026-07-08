select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 
    'button' as component,
    'center' as justify;
select 
    'todo_form.sql'     as link,
    'green' as color,
    'Add new todo'  as title,
    'circle-plus'  as icon;

select 'form' as component, TRUE as auto_submit, 'GET' as method;
select 'checkbox' as type,
	FALSE as value,
	2 as width,
	'Show all' as label,
	'nolimit' as name,
	$nolimit as checked
;

--select 'debug' as component, $nolimit as value;
SET filter = ( case when $nolimit = false OR $nolimit is null then FALSE else TRUE end );
--select 'debug' as component, :filter as value;


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
	System as System,
	Asset as 'Asset',
	Short_desc as 'Action',
	DueDate as 'Due Date',
	ID as _sqlpage_id
	from log_M
	LEFT OUTER JOIN Actions ON Action=Actions.tag
	LEFT OUTER JOIN asset_list ON Asset=asset_list.tag
	WHERE Done=0 AND (DueDate <= DATE('now', '+60 days') OR :filter)
	ORDER BY DueDate,Asset
;


