CREATE TABLE "log_M" (
	"ID"	INTEGER NOT NULL UNIQUE,
	"Asset"	TEXT,
	"Action"	TEXT,
	"SubAction"	TEXT,
	"DueDate"	TEXT,
	"Done"	NUMERIC,
	"DoneDate"	TEXT,
	"Executor"	INTEGER DEFAULT 0,
	"Comment"	TEXT,
	PRIMARY KEY("ID" AUTOINCREMENT),
	FOREIGN KEY("Action") REFERENCES "Actions"("tag"),
	FOREIGN KEY("Asset") REFERENCES "asset_list"("Tag"),
	FOREIGN KEY("Executor") REFERENCES "People"("ID")
)


CREATE TABLE "asset_list" (
	"Tag"	TEXT NOT NULL UNIQUE,
	"Location"	TEXT,
	"System"	TEXT,
	"subSystem"	TEXT,
	"Type"	TEXT,
	"subType"	TEXT,
	"description"	TEXT,
	"Supplier"	TEXT,
	"Date_install"	TEXT,
	"Characteristics"	TEXT,
	"Comment"	TEXT,
	"Parent"	TEXT,
	PRIMARY KEY("Tag"),
	CONSTRAINT "loc" FOREIGN KEY("Location") REFERENCES "Locations"("tag"),
	CONSTRAINT "par" FOREIGN KEY("Parent") REFERENCES "asset_list"("Tag"),
	CONSTRAINT "system" FOREIGN KEY("System") REFERENCES "Systems"("Tag"),
	CONSTRAINT "typ" FOREIGN KEY("Type") REFERENCES "Asset_types"("type")
)

CREATE TABLE "Template_Planning" (
	"ID"	INTEGER NOT NULL UNIQUE,
	"asset"	TEXT,
	"Action"	TEXT,
	"Delay"	INTEGER,
	"Comment"	TEXT,
	PRIMARY KEY("ID" AUTOINCREMENT),
	FOREIGN KEY("Action") REFERENCES "Actions"("tag"),
	FOREIGN KEY("asset") REFERENCES "asset_list"("Tag")
)


CREATE TABLE "Template_M" (
	"Type"	TEXT,
	"Action"	TEXT,
	"Delay"	INTEGER,
	"Comment"	TEXT,
	FOREIGN KEY("Action") REFERENCES "Actions"("tag"),
	FOREIGN KEY("Type") REFERENCES "Asset_types"("type")
)

CREATE TABLE "Systems" (
	"Tag"	TEXT NOT NULL UNIQUE,
	"Short"	TEXT,
	"Long"	TEXT,
	PRIMARY KEY("Tag")
)

CREATE TABLE "People" (
	"ID"	INTEGER NOT NULL UNIQUE,
	"Name"	TEXT,
	"Function"	TEXT,
	"Date_out"	NUMERIC,
	PRIMARY KEY("ID")
)

CREATE TABLE "Locations" (
	"tag"	TEXT NOT NULL UNIQUE,
	"Building"	TEXT,
	"Level"	INTEGER,
	"Room"	TEXT,
	"Description"	TEXT,
	PRIMARY KEY("tag")
)


CREATE TABLE "Asset_types" (
	"type"	TEXT NOT NULL UNIQUE,
	"Description"	TEXT,
	PRIMARY KEY("type")
)


CREATE TABLE "Actions" (
	"tag"	TEXT NOT NULL UNIQUE,
	"Short_desc"	TEXT,
	"Long_desc"	TEXT,
	PRIMARY KEY("tag")
)

INSERT INTO "main"."Actions" ("tag", "Short_desc", "Long_desc") VALUES ('CLEAN1', 'Supperficial clean-up', '');
INSERT INTO "main"."Actions" ("tag", "Short_desc", "Long_desc") VALUES ('CLEAN2', 'In-deep cleaning', '');
INSERT INTO "main"."Actions" ("tag", "Short_desc", "Long_desc") VALUES ('CHECK', 'Visual control', '');
INSERT INTO "main"."Actions" ("tag", "Short_desc", "Long_desc") VALUES ('FUNCTION', 'Function check / move', '');
INSERT INTO "main"."Actions" ("tag", "Short_desc", "Long_desc") VALUES ('REPLACE', 'Full Replacement', '');
INSERT INTO "main"."Actions" ("tag", "Short_desc", "Long_desc") VALUES ('OTHER', 'Other action, to be described', '');

INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('VANNE', 'Water valve');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('GRID', 'Air in/out grid (bouche)');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('DIFF', 'Differential protection');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('FD', 'Fire Detector');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('MACH', 'Machine');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('Collecteur', 'Collecteur');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('Robinet', 'Robinet');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('Radiateur', 'Radiateur');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('OVERPRESSURE', 'Clapet surpression');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('ELEC PANEL', 'Tableau elec');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('Purgeur_auto', 'Purgeur Automatique');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('FILTER', 'Filtre');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('CHASSIS', 'Chassis ext.');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('PORTE', 'Porte ext.');
INSERT INTO "main"."Asset_types" ("type", "Description") VALUES ('Velux', 'Fenetre de toit');

INSERT INTO "main"."People" ("ID", "Name", "Function", "Date_out") VALUES (0, 'Admin', 'Admin', NULL);

INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('VANNE', 'FUNCTION', 1, 'Test annuel des vannes');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('GRID', 'CLEAN1', 1, 'Nettoyage annuel bouches de ventilation');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('DIFF', 'FUNCTION', 1, 'Test annuel des différentiels');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('FILTER', 'CLEAN2', 1, 'Nettoyage filtres');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('MACH', 'CHECK', 2, 'Vérification machines');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('FILTER', 'CLEAN1', 1, 'Nettoyage filtres');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('ELEC PANEL', 'CHECK', 2, 'Check TE');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('FD', 'FUNCTION', 1, 'Test annuel détecteur incendie');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('OVERPRESSURE', 'FUNCTION', 1, 'Test annuel valves surpression');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('Radiateur', 'CHECK', 1, 'Check annuel radiateurs');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('Purgeur_auto', 'CHECK', 1, 'Check annuel purgeurs');
INSERT INTO "main"."Template_M" ("Type", "Action", "Delay", "Comment") VALUES ('Collecteur', 'FUNCTION', 1, 'Test annuel collecteurs');


