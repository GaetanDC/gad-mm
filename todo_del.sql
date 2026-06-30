delete from log_M
where ID = $todo_id and $confirm = 'yes'
returning -- returning will return one row if an item was deleted, and zero rows if no item was deleted
    'redirect' as component, -- if one item was deleted, we redirect the user to the home page, and skip the rest of the page
    'sub_todos.sql' as link;


select
    'alert' as component, -- an alert is a message that is displayed to the user
    'red' as color,
    'Confirm deletion' as title,
    'Are you sure you want to delete the following todo item ?

> ' || concat(Asset," - ",Action) as description_md, -- we include the text of the todo item in the markdown confirmation message
    '?todo_id=' || $todo_id || '&confirm=yes' as link, -- When the user clicks on the 'Delete' button, the page will be reloaded with the confirm parameter set to 'yes', so that the delete statement above will delete the todo item
    'Delete' as link_text
from log_M where id = $todo_id; -- finds the todo item with the id given in the URL