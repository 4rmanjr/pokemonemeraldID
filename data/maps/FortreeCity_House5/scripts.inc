FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Rumah pohon di FORTREE sangat bagus!\p"
	.string "Menurutku ini kota nomor satu untuk\n"
	.string "hidup bersama POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON dan manusia telah beradaptasi\n"
	.string "dengan alam untuk bertahan hidup.\p"
	.string "Tidak perlu membuat alam menyesuaikan\n"
	.string "dengan cara hidup kita.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: Bufuu!$"
