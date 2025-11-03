MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Di sinilah kami para pengguna DRAGON\n"
	.string "berlatih.\p"
	.string "Bahkan CHAMPION pun berkunjung.\n"
	.string "Sekarang kamu lihat betapa istimewanya\l"
	.string "tempat ini?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "Aku tidak menyangka kamu sekuat ini!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Jalan di depan masih panjang dan berat.\p"
	.string "Kapan POKéMON-ku dan aku akan menjadi\n"
	.string "yang terbaik?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Aku ingin tahu lebih banyak tentang\n"
	.string "kekuatanmu.\p"
	.string "Biarkan aku mendaftarkanmu di\n"
	.string "POKéNAV-ku.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Sejak kita bertemu, kami telah berlatih\n"
	.string "keras dengan tujuan menjadi nomor satu.\p"
	.string "Bantu kami melihat seberapa kuat kami\n"
	.string "telah menjadi!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "Aku tidak menyangka kamu sekuat ini!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Kamu jelas melanjutkan latihan\n"
	.string "POKéMON-mu.\p"
	.string "Selama kamu tetap kuat, aku juga bisa\n"
	.string "menjadi lebih kuat!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Kami selalu bertarung POKéMON\n"
	.string "bersama sebagai pasangan.\l"
	.string "Kami percaya diri.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Oh, astaga.\n"
	.string "Kita kalah, istriku sayang.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Kami sudah menikah selama lima\n"
	.string "puluh tahun.\p"
	.string "Kalau dipikir-pikir, aku belum pernah\n"
	.string "mengalahkan istriku dalam pertarungan.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Wah, wah, TRAINER yang masih\n"
	.string "muda!\p"
	.string "Maukah kamu bertarung dengan kami?\n"
	.string "Jika iya, kamu harus kembali dengan\l"
	.string "lebih banyak POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: TRAINER muda, jika ada\n"
	.string "kesempatan, maukah kamu bertarung\l"
	.string "dengan kami lagi?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Kami sudah menikah selama lima\n"
	.string "puluh tahun.\p"
	.string "Ikatan yang kami bagi sebagai pasangan\n"
	.string "tidak akan pernah bisa putus.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Oh, sayang.\n"
	.string "Kita kalah, suamiku tersayang.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Lima puluh tahun pernikahan…\p"
	.string "Jika kami pernah bertengkar, kami\n"
	.string "selalu menyelesaikannya dengan\l"
	.string "pertarungan POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Wah, wah, bukankah kamu seorang\n"
	.string "TRAINER muda?\p"
	.string "Jika kamu ingin bertarung dengan kami,\n"
	.string "kamu harus kembali dengan lebih banyak\l"
	.string "POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Kami selalu bertarung POKéMON\n"
	.string "bersama sebagai pasangan.\l"
	.string "Kami percaya diri.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Oh, astaga.\n"
	.string "Kita kalah, istriku sayang.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Menikah selama lima puluh tahun…\p"
	.string "Setelah direnungkan, istriku dan aku,\n"
	.string "kami bertarung hari demi hari…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Wah, wah, TRAINER yang masih\n"
	.string "muda!\p"
	.string "Maukah kamu bertarung dengan kami?\n"
	.string "Jika iya, kamu harus kembali dengan\l"
	.string "lebih banyak POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Kami sudah menikah selama lima\n"
	.string "puluh tahun.\p"
	.string "Kami saling mendukung selama ini. Kami\n"
	.string "telah membuat diri kami kuat.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Oh, sayang.\n"
	.string "Kita kalah, suamiku tersayang.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Lima puluh tahun pernikahan…\n"
	.string "Banyak hal telah terjadi.\p"
	.string "Aku harap kita akan terus membuat\n"
	.string "kenangan indah bersama.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Wah, wah, bukankah kamu seorang\n"
	.string "TRAINER muda?\p"
	.string "Jika kamu ingin bertarung dengan kami,\n"
	.string "kamu harus kembali dengan lebih banyak\l"
	.string "POKéMON.$"
