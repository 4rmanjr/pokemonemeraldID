MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Ketika Aku di sini…\n"
	.string "Kekuatan aneh mengalir ke dalam diriku…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Kekuatan itu memudar…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Mungkin kekuatan itu berasal dari roh\n"
	.string "POKéMON yang tidur gelisah di sini…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Aku kalah dalam pertandingan, tapi…\n"
	.string "Aku punya sedikit kemampuan ini…\p"
	.string "Tanpa menyentuh POKéNAV-mu… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Di belakangmu…\n"
	.string "Ada apa…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Sesuatu memudar…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "POKéMON yang beristirahat di sini…\n"
	.string "Terkadang, mereka bermain…$"

MtPyre_6F_Text_CedricIntro:
	.string "Apakah kamu tersesat?\n"
	.string "Jangan takut karena Aku di sini!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Bukankah kamu tersesat?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Aku punya firasat bahwa TRAINER yang tersesat\n"
	.string "akan panik dan mudah dikalahkan.\p"
	.string "Itu kotor dan Aku tidak akan mencobanya lagi…$"

