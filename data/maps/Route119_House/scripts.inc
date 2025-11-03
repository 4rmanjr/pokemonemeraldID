Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Aku dengar tentang gua bernama\n"
	.string "CAVE OF ORIGIN.\p"
	.string "Orang-orang desas-desus bahwa roh\n"
	.string "POKéMON dibangkitkan di sana. Bisakah\l"
	.string "hal seperti itu benar-benar terjadi?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

