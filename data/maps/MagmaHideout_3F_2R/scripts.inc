MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Aku mengerti semua yang dikatakan\n"
	.string "pemimpin. Tapi tahu tidak?\p"
	.string "Melakukan hal seperti menggali POKéMON\n"
	.string "purba dan merebut METEORITE seseorang…\p"
	.string "Kurasa kita sudah keterlaluan.\n"
	.string "Bagaimana menurutmu?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ya, kurasa kita melakukan sesuatu yang\n"
	.string "salah.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Tahu tidak, kalah darimu menjernihkan\n"
	.string "pikiranku.\p"
	.string "Lain kali aku bertemu pemimpin, aku akan\n"
	.string "bertanya tentang apa yang kita lakukan.$"

