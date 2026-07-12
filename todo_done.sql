
select 'title' as component, 'Todo closer' as contents;

select 'form' as component, 
	'closer' as id,
	'Mark as Done' as validate,
	'todo_done_act.sql' as action
;


select 'text' as type,
	'id' as name,
	'hidden' as type,
	$todo_id as value
;

select 'text as type,
	'tag' as name,
	'Tag' as label,
	3 as width,
	TRUE AS readonly,
	(select asset from Log_M WHERE ID=$todo_id) as value
;

select 'text' as type,
	action' as name,
	'Action' as label,
	3 as width,
	TRUE AS readonly,
	(select action from Log_M WHERE ID=$todo_id) as value
;

select 'date' as type,
	'Date' as name,
	date('now') as value,
	3 as width
;

select 'text' as type,
	'user' as name,
	'select' as type,
	"Executor" as label,
	4 as width,
	(SELECT json_group_array( json_object( 'value', ID, 'label', Name ) )  FROM People) as options
;

select 'textarea' as type,
	'comment' as name,
	'Comment' as label,
	3 as rows
;

SELECT 'button' as component,
	'closer' as form;
SELECT 
    'Annuler'        AS title,
    'sub_todos.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color    -- Couleur grise standard pour une annulation
;