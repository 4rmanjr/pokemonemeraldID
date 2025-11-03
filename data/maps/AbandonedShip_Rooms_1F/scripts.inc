//gemini
AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Kapal jenis ini langka, jadi aku\n"
	.string "sedang melihat-lihat.\p"
	.string "Hmhm… Sepertinya ada kabin lain…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Apa yang membuatmu datang ke sini?\n"
	.string "Kamu pasti penasaran!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Tidak hanya penasaran, tapi juga\n"
	.string "kuat…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Pria di sebelah…\p"
	.string "Dia bilang dia hanya jalan-jalan,\n"
	.string "tapi aku tidak tahu soal itu.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Kamu TRAINER yang tangguh! Biarkan\n"
	.string "aku mendaftarkanmu sebagai\l"
	.string "kenang-kenangan!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Apa yang membuatmu kembali? Kamu\n"
	.string "pasti benar-benar penasaran!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Apa kamu terlalu kuat?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Aku yakin pria itu sedang\n"
	.string "merencanakan sesuatu! Dia\l"
	.string "bertingkah sangat mencurigakan!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah! Aku ketahuan! …Hah?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, kamu bukan ibuku.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Aku bermasalah dengan ibuku, jadi\n"
	.string "aku kabur. Rahasiakan di mana aku\l"
	.string "berada!$"
