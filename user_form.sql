insert or replace into People(id, name, function)
select $todo_id, :user, :function -- $todo_id will be null if the page is accessed via the 'Add new todo' button (without a ?todo_id= parameter)
where :user is not null -- only insert if the form was submitted
returning 'redirect' as component,  'sub_users.sql' as link;



select 
    'form'            as component,
    'Users Management'            as title,
    (
        case when $todo_id is null then
            'Add new User'
        else
            'Edit User'
        end
    ) as validate,
	'user_form' as id
;

select 
    'User' as label,
    'user' as name,
    'name...' as placeholder,
    (select name from People where ID = $todo_id) as value
;
select 
    'Function' as label,
    'function' as name,
    'function...' as placeholder,
    (select Function from People where ID = $todo_id) as value
;


SELECT 'button' as component, 'user_form' as form;
SELECT 
    'Annuler'        AS title,
    'sub_users.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation