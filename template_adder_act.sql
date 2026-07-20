--select 'debug' as component, $todo_id, :action,:asset,:delay,:comment	;



INSERT OR REPLACE INTO Template_planning(ID,asset, Action, Delay,Comment)
SELECT $todo_id,:asset, :action, :delay, :comment
;

INSERT OR REPLACE INTO Log_M (Asset, Action, SubAction, DueDate, Done, Executor)
SELECT :asset AS Asset,
        :action AS Action,
        :comment AS SubAction,
        date('now') AS DueDate,
        0 AS Done,
        0 AS Executor
FROM Log_M
WHERE $todo_id is null AND Asset LIKE :asset AND Action LIKE :action
;


SELECT 'redirect' AS component, 'asset_form.sql?todo_id='||:asset AS link;





