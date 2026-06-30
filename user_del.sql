-- We find the todo item with the id given in the URL (/delete.sql?todo_id=1)
-- and we check that the URL also contains a 'confirm' parameter set to 'yes' (/delete.sql?todo_id=1&confirm=yes)
-- If both conditions are met, we delete the todo item from the database
-- and redirect the user to the home page.

delete from People
where ID = $todo_id and $confirm = 'yes'
returning -- returning will return one row if an item was deleted, and zero rows if no item was deleted
    'redirect' as component, -- if one item was deleted, we redirect the user to the home page, and skip the rest of the page
    'sub_users.sql' as link;



-- If we are here, it means that the delete statement above did not delete anything
-- because the confirm parameter was not set to 'yes'.

-- We display the same header as in other pages, by including the shell.sql file.


select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

-- When the page is initially loaded, it will contain a todo_id parameter
-- but no confirm parameter, so the delete statement above will not delete anything
-- and the 'redirect' component will not be returned.
-- In this case, we display a confirmation message to the user.


select
    'alert' as component, -- an alert is a message that is displayed to the user
    'red' as color,
    'Confirm deletion' as title,
    'Are you sure you want to delete the following user item ?

> ' || name as description_md, -- we include the text of the todo item in the markdown confirmation message
    '?todo_id=' || $todo_id || '&confirm=yes' as link, -- When the user clicks on the 'Delete' button, the page will be reloaded with the confirm parameter set to 'yes', so that the delete statement above will delete the todo item
    'Delete' as link_text
from People where ID = $todo_id; -- finds the todo item with the id given in the URL

select
	'sub_users.sql' as link,
	'Cancel' as title,
	'secondary' as color
;