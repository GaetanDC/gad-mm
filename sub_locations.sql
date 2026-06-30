 select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 'table' as component,
   'Locations' as title,
	'Empty ...' as empty_title,
	TRUE as sort,
	FALSE as search,
	JSON('[	{"name":"Edit","icon":"edit","link":"location_form.sql?todo_id={id}"},
		{"name":"View","icon":"eye","link":"location_view.sql?todo_id={id}"}
		]') as custom_actions

;

select
	tag, Building, Level, Room, Description,
	tag as _sqlpage_id
from Locations
;



select 
    'button' as component,
    'center' as justify
;

select 
    'location_form.sql'     as link,
    'green' as color,
    'Add new location'  as title,
    'circle-plus'  as icon
;