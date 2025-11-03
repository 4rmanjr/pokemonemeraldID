MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Aku tidak punya masalah denganmu.\n"
	.string "Aku hanya mengikuti perintah!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Aku mungkin kalah, tapi…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Kami menggali sesuatu yang luar biasa!\n"
	.string "Dan, kami mendapatkan BLUE ORB!\p"
	.string "Tinggal pemimpin kami yang…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Aku tidak tahan panas. Mungkin seharusnya\n"
	.string "aku bergabung dengan TEAM AQUA saja…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ya, aku mungkin benar-benar tidak cocok\n"
	.string "untuk TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Apa kamu tidak merindukan laut jika\n"
	.string "berada di tempat seperti ini?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Terkadang kamu bisa mendengar getaran\n"
	.string "di sini.\p"
	.string "Mungkinkah itu gemuruh gunung berapi?\n"
	.string "Atau itu GROU…\p"
	.string "Ups!\n"
	.string "Tidak, tidak, lupakan saja!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Kamu petarung yang berapi-api.\n"
	.string "Seperti gunung berapi!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Kamu hanya kebetulan menang kali ini,\n"
	.string "tapi itu tidak masalah.\p"
	.string "Tujuan TEAM MAGMA akan segera\n"
	.string "tercapai!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Salah satu dari kami panik karena\n"
	.string "kehilangan MAGMA EMBLEM…\p"
	.string "Tunggu sebentar!\n"
	.string "Apa kamu yang menemukannya?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Aku sulit mempercayai ini…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Aku punya firasat rencana kita akan\n"
	.string "berakhir dengan kegagalan…$"

