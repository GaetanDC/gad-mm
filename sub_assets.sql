--select 'debug' as component, $selected_system as value;
select 'dynamic' as component, sqlpage.run_sql('shell.sql') as properties;

select 
    'button' as component,
    'center' as justify
;
select 
    'asset_form.sql'     as link,
    'green' as color,
    'Add new asset'  as title,
    'circle-plus'  as icon
;

select 'form' as component, TRUE as auto_submit, 'GET' as method;
select 'select' as type,
	'All...' as empty_option,
	5 as width,
	 ( select json_group_array(json_object('label', label, 'value', value))
	 from ( select Tag || ' (' || short || ')' as label, Tag as value from Systems )
	    ) as options,
	'selected_system' AS name,
	'System :' as label,
	$selected_system as value
;

-- select 'debug' as component, $selected_system as value;
SET current_filter = ( case when $selected_system = "" OR $selected_system is null then "%" else $selected_system end );
-- select 'debug' as component, :current_filter as value;

select 'table' as component,
   'Assets' as title,
	TRUE as small,
--	'Actions' as markdown,
--	'View,Edit' as actions,
	'Empty ...' as empty_title,
	TRUE as sort,
	TRUE as search,
	JSON('[
        {"name":"Edit","icon":"edit","link":"asset_form.sql?filter=' || :current_filter || '&todo_id={id}"},
		{"name":"view","icon":"eye","link":"asset_view.sql?filter=' || :current_filter || '&todo_id={id}"}
	]') AS custom_actions

;

--		{"name":"Delete","icon":"trash","link":"asset_del.sql?todo_id={id}"},



select
	Tag, Location, System,Type, description, Supplier, Date_install,
	Tag as _sqlpage_id
	from asset_list
	WHERE (System LIKE :current_filter)
	ORDER BY Tag
;

