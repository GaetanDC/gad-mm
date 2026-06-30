 select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 'table' as component,
   'Users' as title,
	'Empty ...' as empty_title,
	TRUE as sort,
	FALSE as search,
	JSON('[{"name":"Edit","icon":"edit","link":"user_form.sql?todo_id={id}"},
		{"name":"Delete","icon":"trash","link":"user_del.sql?todo_id={id}"}
		]') as custom_actions

;

select
	Name, Function,
	ID as _sqlpage_id
from People
;


select 
    'button' as component,
    'center' as justify
;
select 
    'user_form.sql'     as link,
    'green' as color,
    'Add new user'  as title,
    'circle-plus'  as icon
;