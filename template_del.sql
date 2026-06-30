delete from Template_Planning
where ID = $todo_id 
;

SELECT 'redirect' AS component, 
	'asset_form.sql?todo_id='|| $asset AS link;
