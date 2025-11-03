MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Saat TEAM MAGMA absen, kami mendapat\n"
	.string "tugas penjagaan penting sesuai\l"
	.string "urutan baris.\p"
	.string "Itulah kenapa aku terjebak di pojok ini.\n"
	.string "Aku selalu telat absen!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Aku juga selalu telat latihan!\p"
	.string "Benci mengatakannya, tapi aku payah…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Oke, aku akan berusaha lebih keras\n"
	.string "mulai sekarang…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Pemimpin kami menyuruh menggali\n"
	.string "GUNUNG CHIMNEY, jadi kami terus menggali.\p"
	.string "Dan saat menggali, kami menemukan\n"
	.string "sesuatu yang luar biasa!\p"
	.string "Apa yang kami temukan?\p"
	.string "Fuhahaha!\n"
	.string "Akan kuberitahu jika kamu mengalahkanku!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "Kalah!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Lagi pula tidak akan kuberitahu.\n"
	.string "Kamu akan tahu saat sampai di sana!\p"
	.string "Lebih baik menyimpan kejutan sampai\n"
	.string "akhir, bukan begitu?$"

