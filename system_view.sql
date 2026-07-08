select 
	'form' as component,
	'System detail' as title,
	'' AS validate
;

select
	'Tag' as label,
	'tag' as name,
	2 as width,
	TRUE as readonly,
	$todo_id as value
;

select
	'Name' as label,
	'short' as name,
	5 as width,
	TRUE as readonly,
	(select Short from Systems WHERE Tag=$todo_id) as value
;

select
	'Description' as label,
	'long' as name,
	12 as width,
	TRUE as readonly,
	(select Long from Systems WHERE Tag=$todo_id) as value
;


select 
	'table'            as component,
	'Asset List'            as title,
	TRUE as small,
	JSON('{"name":"View","icon":"eye","link":"asset_view.sql?todo_id={id}"}') as custom_actions,
	TRUE as sort
;

select 
	Tag,System, Type, Description,
	Tag as _sqlpage_id
	from asset_list
	WHERE (asset_list.System LIKE $todo_id) 
;


SELECT 'button' as component, 'system_form' as form;
SELECT 
    'Return'        AS title,
    'sub_systems.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation