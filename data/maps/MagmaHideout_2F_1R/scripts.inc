MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Apa, apa, apa?\p"
	.string "Hanya anggota TEAM MAGMA yang boleh\n"
	.string "ada di sini!\p"
	.string "Tapi kamu tidak memakai seragam\n"
	.string "TEAM MAGMA…\p"
	.string "Kamu mencurigakan!\n"
	.string "Lawan aku!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Harga diriku sebagai anggota TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Jika kamu kedinginan, kamu harus\n"
	.string "bergabung dengan TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Tunggu di sana!\p"
	.string "Kamu tidak berharap aku akan diam saja\n"
	.string "dan membiarkanmu lewat, kan?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ooh wow!\n"
	.string "Aku menyerah!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Mungkin lebih baik jika aku membiarkanmu\n"
	.string "lewat tanpa perlawanan…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahah!\n"
	.string "Penyusup!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Aku sudah kalah.\p"
	.string "Apa aku benar-benar harus terus berlari\n"
	.string "berputar-putar?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Penyusup!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Gumam…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Sebenarnya, aku tidak ahli bertarung…$"

