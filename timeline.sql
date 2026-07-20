select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 
    'timeline' as component;
select 
    Asset ||' - ' || Action as title,
    'todo_form.sql?todo_id=' || id as link,
	'description' as description,
    DueDate as date,
    'calendar' as icon,
    'green' as color,
    printf('%d days ago', julianday('now') - julianday(DueDate)) as description
from log_M WHERE Done=1
order by DueDate desc;
