//aistudio
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
	.string "Saat aku di sini…\n"
	.string "Kekuatan aneh mengalir ke dalam\l"
	.string "diriku…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Kekuatannya memudar…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Mungkin kekuatan itu dari arwah\n"
	.string "POKéMON yang tidur gelisah di sini…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Aku kalah, tapi…\n"
	.string "Aku punya kemampuan kecil ini…\p"
	.string "Tanpa menyentuh POKéNAV-mu…\n"
	.string "Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Di belakangmu…\n"
	.string "Ada apa…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Sesuatu memudar…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "POKéMON yang beristirahat di sini…\n"
	.string "Terkadang, mereka bermain…$"

MtPyre_6F_Text_CedricIntro:
	.string "Apa kamu tersesat?\n"
	.string "Jangan takut, aku di sini!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Bukankah kamu tersesat?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Aku merasa TRAINER yang tersesat\n"
	.string "akan panik & mudah dikalahkan.\p"
	.string "Itu curang & aku tidak akan\n"
	.string "mencobanya lagi…$"
