select 'debug' as component,
$todo_id, :building, :level, :room, :description;

insert or replace into Locations(tag, Building, Level, Room, Description)
select $todo_id, :building, :level, :room, :description -- $todo_id will be null if the page is accessed via the 'Add new todo' button (without a ?todo_id= parameter)
where :tag is not null -- only insert if the form was submitted
returning
    'redirect' as component,
    'sub_locations.sql' as link;


select 
    'form'            as component,
    'Location'            as title,
	'location_form' as id,
    (
        case when $todo_id is null then
            'Add new Location'
        else
            'Edit Location'
        end
    ) as validate;

select 
    'Tag' as label,
    'tag' as name,
	2 as width,
    'Tag...' as placeholder,
	TRUE as readonly,
    (select Tag from Locations where tag = $todo_id) as value
;

select 
	'select' as type,
    'Building' as label,
    'building' as name,
	3 as width,
    'Building...' as placeholder,
    (select Building from Locations where tag = $todo_id) as value,
    '[{"label":"Home", "value":"Home"},{"label":"Other", "value":"Other"}]' as options
	-- Here we have the opportunity to link to as list of buildings...
;

select 
	'select' as type,
    'Level' as label,
    'level' as name,
	3 as width,
    'Level...' as placeholder,
    (select Level from Locations where Tag = $todo_id) as value,
     '[{"label": "-1", "value": -1}, {"label": "0", "value": 0}, {"label": "+1", "value": 1}]' as options
	-- Here we have the opportunity to link to a list of levels for that building
;

select 
    'Room' as label,
    'room' as name,
	3 as width,
    (select Room from Locations where Tag = $todo_id) as value,
    'name...' as placeholder
;

select 
    'Description' as label,
    'description' as name,
	8 as width,
    (select Description from Locations where Tag = $todo_id) as value,

    'description...' as placeholder
;


SELECT 'button' as component, 'location_form' as form;
SELECT 
    'Annuler'        AS title,
    'sub_locations.sql'      AS link,     -- URL de redirection au clic
    'secondary'      AS color;    -- Couleur grise standard pour une annulation