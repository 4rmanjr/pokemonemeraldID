MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Apa salahku sampai dapat tugas jaga\n"
	.string "di sini?\p"
	.string "Telinga kiriku panas sekali!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Aku kepanasan…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Tidakkah aneh kita memakai tudung di\n"
	.string "gunung berapi penuh magma ini?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Kami bergabung untuk membantu pemimpin\n"
	.string "mewujudkan visi fantastisnya.\p"
	.string "Aku tidak peduli kamu dari TEAM AQUA\n"
	.string "atau hanya anak kecil yang lewat.\p"
	.string "Tidak ada yang bisa mengganggu kami dan\n"
	.string "lolos begitu saja!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, tidak!\n"
	.string "Kamu sama sekali tidak bisa dipercaya!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Dengarkan aku.\n"
	.string "TEAM MAGMA benar!\p"
	.string "Jangan dengarkan TEAM AQUA.\n"
	.string "Jangan percaya kebohongan mereka!$"

