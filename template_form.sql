-- select 'debug' as component, :tag, $todo_id;

select 
    'form' as component,
    'Action Management' as title,
    (
        case when $todo_id is null then
            'Add new Action'
        else
            'Edit Action'
        end
    ) as validate,
	'template_form' as id,

    (
        case when $todo_id is null then
            'template_adder_act.sql?isnew=1'
        else
	    'template_adder_act.sql?todo_id=' || $todo_id
        end
    ) as action

;

select 
   'Asset' as label,
    'asset' as name,
    (
        case when $todo_id is null then
            FALSE
        else
            TRUE
        end
    ) as readonly,

	2 as width,
     (select $asset ) as value
;

SELECT 'label' as type,
	'Description' as label,
	5 as width,
	TRUE as readonly,
	(SELECT asset_list.description from asset_list WHERE Tag = $asset) as value
;

SELECT	'select' as type,
    'Action' as label,
    'action' as name,
	8 as width,
    'Taction...' as placeholder,
	 ( select json_group_array(json_object('label', label, 'value', value))
	 from ( select Short_desc as label, tag as value from Actions )
	    ) as options,

    (select Action from Template_Planning where ID = $todo_id) as value
;

select 'number' as type, 
    'Delay (days)' as label,
    'delay' as name,
	2 as width,
	30 as min,
    365 as placeholder,
    COALESCE ((select Delay from Template_Planning where ID = $todo_id),30) as value
;

select 
	'textarea' as type,
    'Comment' as label,
    'comment' as name,
    'Comment ...' as placeholder,
    (select Comment from Template_Planning where ID = $todo_id) as value
;


SELECT 'button' as component, 'template_form' as form;
SELECT 
    'Back'        AS title,
    'asset_form.sql?todo_id='||$asset      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation
