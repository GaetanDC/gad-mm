 select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 
    'button' as component,
    'center' as justify
;
select 
    'asset_form.sql'     as link,
    'green' as color,
    'Add new asset'  as title,
    'circle-plus'  as icon
;


select 'table' as component,
   'Assets' as title,
	TRUE as small,
--	'Actions' as markdown,
--	'View,Edit' as actions,
	'Empty ...' as empty_title,
	TRUE as sort,
	TRUE as search,
	JSON('[{"name":"Edit","icon":"edit","link":"asset_form.sql?todo_id={id}"},
		{"name":"view","icon":"eye","link":"asset_view.sql?todo_id={id}"}
		]') as custom_actions

;

--		{"name":"Delete","icon":"trash","link":"asset_del.sql?todo_id={id}"},


select 
    Tag, Location, System,Type, description, Supplier, Date_install, Characteristics, Comment,
	Tag as _sqlpage_id

from asset_list ORDER BY Tag
;

