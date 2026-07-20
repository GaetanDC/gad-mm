-- select 'debug' as component, :tag, $todo_id;

select 
	'form' as component,
	'Assets Management'            as title,
	'asset_form' as id,

	CASE when $todo_id is null 
	THEN 'Add new Asset'
	ELSE 'Edit Asset'
        END AS validate,
	
	sqlpage.link('asset_adder_act.sql', 
	        json_object( 'filter', $filter,  'todo_id', $todo_id)
	) AS action;
;

select 
    'Tag' as label,
    'tag' as name,
    (
        case when $todo_id is null then
            FALSE
        else
            TRUE
        end
    ) as readonly,

	2 as width,
    'tag...' as placeholder,
    (select Tag from asset_list where Tag = $todo_id) as value
;
select 
	'select' as type,
    'Location' as label,
    'location' as name,
	3 as width,
    'Location...' as placeholder,
	 ( select json_group_array(json_object('label', label, 'value', value))
	 from ( select tag as label, tag as value from Locations )
	    ) as options,

    (select Location from asset_list where Tag = $todo_id) as value
;
select 
	'select' as type,
    'System' as label,
    'system' as name,
	3 as width,
    'System...' as placeholder,
	 ( select json_group_array(json_object('label', label, 'value', value))
	 from ( select Tag || ' (' || short || ')' as label, Tag as value from Systems )
	    ) as options,

    (select System from asset_list where Tag = $todo_id) as value
;
select 
    'Sub-System' as label,
    'subsystem' as name,
	3 as width,
    'Sub-system...' as placeholder,
    (select subSystem from asset_list where Tag = $todo_id) as value
;
select 
	'select' as type,
    'Type' as label,
    'type' as name,
	3 as width,
    'Type...' as placeholder,
	 ( select json_group_array(json_object('label', label, 'value', value))
	 from ( select type || ' (' || Description || ')' as label, type as value from Asset_types )
	    ) as options,

    (select Type from asset_list where Tag = $todo_id) as value
;
select 
    'Sub-Type' as label,
    'subtype' as name,
	3 as width,
    'Sub-type...' as placeholder,
    (select subType from asset_list where Tag = $todo_id) as value
;

select 
	'Date' as type,
	3 as width,
    'Installation Date' as label,
    'date_install' as name,
    (select Date_install from asset_list where Tag = $todo_id) as value
;

select 
    'Description' as label,
	8 as width,
    'description' as name,
    'Description...' as placeholder,
    (select description from asset_list where Tag = $todo_id) as value
;

select 
    'Supplier' as label,
	6 as width,
    'supplier' as name,
    'Supplier, ref...' as placeholder,
    (select Supplier from asset_list where Tag = $todo_id) as value
;


select 
    'Characteristics' as label,
    'characteristics' as name,
	6 as width,
    'Characteristics...' as placeholder,
    (select Characteristics from asset_list where Tag = $todo_id) as value
;

select 
	'textarea' as type,
    'Comment' as label,
    'comment' as name,
    'Comment ...' as placeholder,
    (select Comment from asset_list where Tag = $todo_id) as value
;

select 
	'select' as type,
	'Parent' as label,
	'parent' as name,
	3 as width,
	'parent ...' as placeholder,
	 ( select json_group_array(json_object('label', label, 'value', value)) from
		( select 'None' as label, NULL as value
            union all
            select Tag as label, Tag as value from asset_list where Tag <> coalesce($todo_id, '')
        )
    ) as options,

	(select Parent from asset_list where Tag = $todo_id) as value
;


SELECT 
    'button' as component,
    'center' as justify;
select 
    sqlpage.link('template_form.sql', json_object('asset', $todo_id)) as link,
    'green' as color,
    'Add new Action'  as title,
    'circle-plus'  as icon;


select 'table' as component,
   'Actions' as title,
	FALSE as small,
	'Empty ...' as empty_title,
	FALSE as sort,
	FALSE as search,
	json_array(
	 json_object('name','Edit','icon','edit','link','template_form.sql?todo_id={id}&asset='||COALESCE($todo_id,'')),
	 json_object('name','Delete','icon','trash','link','template_del.sql?todo_id={id}&asset='||COALESCE($todo_id,''))
	) as custom_actions
;

select Action, Delay, Comment,
ID as _sqlpage_id
FROM Template_Planning
WHERE asset=$todo_id
;




SELECT 'button' as component;
SELECT 
--	'asset_form' as form,
	'Back'        AS title,
	sqlpage.link('sub_assets.sql',json_object('selected_system', $filter))      AS link,     -- URL de redirection au clic
	'secondary'      AS color    -- Couleur grise standard pour une annulation
;

