select 
	'form' as component,
	'Location detail' as title,
	'' AS validate
;

select
	'Tag' as label,
	'tag' as name,
	2 as width,
	TRUE as disabled,
	$todo_id as value
;

select
	'Description' as label,
	'description' as name,
	5 as width,
	TRUE as disabled,
	(select Description from Locations WHERE tag=$todo_id) as value
;



select 
	'table'            as component,
	'Asset List'            as title,
	JSON('{"name":"View","icon":"eye","link":"asset_view.sql?todo_id={id}"}') as custom_actions,
	TRUE as sort
;

select 
	Tag,System, Type, Description,
	Tag as _sqlpage_id
	from asset_list
	WHERE (asset_list.Location LIKE $todo_id) 
;



SELECT 'button' as component, 'asset_form' as form;
SELECT 
    'Return'        AS title,
    'sub_locations.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation