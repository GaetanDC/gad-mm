select 
	'form' as component,
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
	'Location' as label,
	'location' as name,
	3 as width,
	TRUE as disabled,
	(select Location from asset_list WHERE Tag=$todo_id) as value
;

select
	'Description' as label,
	'description' as name,
	5 as width,
	TRUE as disabled,
	(select Description from asset_list WHERE Tag=$todo_id) as value
;



select 
    'table'            as component,
    'Asset Log'            as title,
	TRUE as sort
;

select 
	Action,DoneDate,People.Name,Comment
	from Log_M
	INNER JOIN People ON (Log_M.Executor=People.ID)
	WHERE (Log_M.Done=1 AND Log_M.Asset LIKE $todo_id) 
;



SELECT 'button' as component, 'asset_form' as form;
SELECT 
    'Return'        AS title,
    'sub_assets.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation