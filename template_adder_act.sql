--select 'debug' as component, $todo_id, :action,:asset,:delay,:comment	;



INSERT OR REPLACE INTO Template_planning(ID,asset, Action, Delay,Comment)
SELECT $todo_id,:asset, :action, :delay, :comment
;

SELECT 'redirect' AS component, 'asset_form.sql?todo_id='||:asset AS link;





