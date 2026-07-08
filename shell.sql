WITH menu_data AS (
    SELECT 'Todos' AS title, 'sub_todos.sql' AS link UNION ALL
    SELECT 'Assets', 'sub_assets.sql' UNION ALL
    SELECT 'Logs', 'sub_logs.sql' UNION ALL
    SELECT 'Users', 'sub_users.sql' UNION ALL
    SELECT 'Systems', 'sub_systems.sql' UNION ALL
    SELECT 'Locations', 'sub_locations.sql' UNION ALL
    SELECT 'Timeline', 'timeline.sql'
)
SELECT 
    'shell' AS component,
    'GAD Maintenance Manager' AS title,
    TRUE AS fixed_tomenu,
	'Published under GPL License. Gaetan De Cloedt 2026' as footer,
    -- Group every record into JSON for SQLPage shell menu tracking
    (
        SELECT json_group_array(
            json_object(
                'title', title, 
                'link', link, 
                'active', sqlpage.path() LIKE '%' || link
            )
        ) FROM menu_data
    ) AS menu_item;