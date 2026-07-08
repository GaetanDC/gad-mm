select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 'table' as component,
   'Systems' as title,
	'Empty ...' as empty_title,
	TRUE as sort,
	FALSE as search,
	JSON('[	{"name":"Edit","icon":"edit","link":"system_form.sql?todo_id={id}"},
		{"name":"View","icon":"eye","link":"system_view.sql?todo_id={id}"}
		]') as custom_actions
-- no delete
;

select
	Tag, Short, Long,
	Tag as _sqlpage_id
from Systems
;



select 
    'button' as component,
    'center' as justify
;

select 
    'system_form.sql'     as link,
    'green' as color,
    'Add new system'  as title,
    'circle-plus'  as icon
;