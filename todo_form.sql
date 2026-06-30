--select 'debug' as component, $todo_id, :action,:asset	;

insert or replace into log_M(ID, Asset, Action, DueDate, Done)
select $todo_id, :asset, :action, :duedate ,0
where :action is not null -- only insert if the form was submitted
returning
    'redirect' as component, 'sub_todos.sql' as link;

--select 'debug' as component, $todo_id, :action,:asset	;


select 
	'form'            as component,
	'Todo'            as title,
	(
	case when $todo_id is null then
            'Add new todo'
	else
		'Edit todo'
	end
	) as validate,
	'todo_form' as id

;

select 
	'select' as type,
	'Asset' as label,
	'asset' as name,
	'Asset...' as placeholder,
	10 as width,
	(select Asset from log_M where ID = $todo_id) as value,

	 ( select json_group_array(json_object('label', label, 'value', value)) from
		( select concat(tag, " - ", description) as label, tag as value from asset_list ORDER BY tag )
	    ) as options

;


select 
	'select' as type,
	'Action' as label,
	'action' as name,
	'Action...' as placeholder,
	4 as width,
	 ( select json_group_array(json_object('label', label, 'value', value))
	 from ( select Short_desc as label, tag as value from Actions )
	    ) as options,


	(select Action from log_M where ID = $todo_id) as value
;

select
	'date' as type,
	'Due date' as label,
	'duedate' as name,
	4 as width,
	(select DueDate from log_M where ID = $todo_id) as value
;





SELECT 'button' as component, 'todo_form' as form;
SELECT 
    'Annuler'        AS title,
    'sub_todos.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation