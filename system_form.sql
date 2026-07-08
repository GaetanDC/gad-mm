--select 'debug' as component, $todo_id, :tag,:short, :description;

insert or replace into Systems(Tag, Short, Long)
select $todo_id, :short, :long -- $todo_id will be null if the page is accessed via the 'Add new ' button (without a ?todo_id= parameter)
where :tag is not null -- only insert if the form was submitted
returning
    'redirect' as component,
    'sub_systems.sql' as link;


select 
	'form'            as component,
	'Systems'            as title,
	'system_form' as id,
	( case when $todo_id is null then 'Add new System'
		else 'Edit System'
		end ) as validate;

select 
	'Tag' as label,
	'tag' as name,
	2 as width,
	'Tag...' as placeholder,
	TRUE as readonly,
	(select Tag from Systems where tag = $todo_id) as value
;

select 
	'text' as type,
	'Name' as label,
	'short' as name,
	3 as width,
	'Name...' as placeholder,
	(select Short from Systems where tag = $todo_id) as value
;

select 
	'text' as type,
	'Description' as label,
	'long' as name,
	12 as width,
	'Description...' as placeholder,
	(select Long from Systems where Tag = $todo_id) as value
;


SELECT 'button' as component, 'system_form' as form;
SELECT 
    'Annuler'        AS title,
    'sub_systems.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation