
select 'title' as component, 'Todo closer' as contents;

select 'form' as component, 
	'closer' as id,
	'todo_done_act.sql' as action
;


select 'id' as name, 'hidden' as type, $todo_id as value
;

select 'tag' as name, 'Tag' as label, 3 as width,
	(select asset from Log_M WHERE ID=$todo_id) as value
;

select 'action' as name, 'Action' as label, 3 as width,
	(select action from Log_M WHERE ID=$todo_id) as value
;

select 'Date' as name, 'date' as type, date('now') as value, 3 as width
;

select 'user' as name, 'select' as type, "Executor" as label, 4 as width,
	(SELECT json_group_array( json_object( 'value', ID, 'label', Name ) )  FROM People) as options
;

select 'comment' as name, 'Comment' as label, 3 as rows, 'textarea' as type;

SELECT 'button' as component, 'closer' as form;
SELECT 
    'Annuler'        AS title,
    'sub_todos.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation