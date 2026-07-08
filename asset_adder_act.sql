--select 'debug' as component, $todo_id, $isnew,:action,:asset	;



INSERT OR REPLACE INTO asset_list(Tag, Location, System,subSystem,Type, subType,description, Supplier, Date_install, Characteristics, Comment,Parent)
SELECT :tag, :location, :system,  :subsystem, :type, :subtype, :description, :supplier, :date_install, :characteristics, :comment, (case when :parent='' then NULL else :parent end);




INSERT INTO Template_Planning(asset, Action, Delay, Comment)
SELECT :tag as Asset, Action, Delay, Comment
FROM Template_M
WHERE Type=:type AND $isnew = 1 ;



INSERT INTO Log_M (Asset, Action, SubAction, DueDate, Done, Executor)
SELECT :tag as Asset,
	Action as Action,
	Comment as SubAction,
	date('now',concat('+',Delay,' DAYS' )) as DueDate,
	0 as Done,
	0 as Executor
FROM Template_M
WHERE Type=:type AND $isnew = 1
;


SELECT 'redirect' AS component, 'sub_assets.sql?selected_system=' || $filter || '&todo_id=' || :tag AS link;





