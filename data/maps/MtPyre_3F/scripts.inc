//aistudio
MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Atmosfer kaya di gunung ini telah\n"
	.string "meningkatkan kekuatan psikisku!\p"
	.string "Anak kecil sepertimu…\n"
	.string "Kamu bermimpi untuk menang?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Aku tenggelam dalam rasa kasihan diri…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Kekuatan psikisku pasti sudah\n"
	.string "berkembang berkali-kali, tapi…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Ini bukan tempat untuk anak-anak,\n"
	.string "apalagi kamu!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Aku kalah telak…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ini berarti latihanku masih belum\n"
	.string "cukup…\p"
	.string "Aku harus terus berusaha menuju\n"
	.string "puncak…\p"
	.string "Semangat, aku!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Kenapa kamu datang ke sini?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Itu luar biasa!\n"
	.string "Kamu TRAINER yang sangat spesial.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON yang tak lagi di dunia ini.\n"
	.string "POKéMON yang bersamamu sekarang.\p"
	.string "& POKéMON yang akan kamu temui\n"
	.string "di masa depan…\p"
	.string "Semuanya harus sama-sama dihargai.\n"
	.string "Tolong ingat itu.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Aku ingin melihat POKéMON-mu\n"
	.string "saat mereka tumbuh dewasa nanti…\p"
	.string "Tolong, aku perlu melihat POKéNAV-mu.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, ini kamu…\p"
	.string "Apa kamu datang untuk menunjukkan\n"
	.string "POKéMON dewasamu?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Luar biasa!\n"
	.string "Kamu orang yang spesial.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON yang tak lagi di dunia ini.\n"
	.string "POKéMON yang bersamamu sekarang.\p"
	.string "& POKéMON yang akan kamu temui\n"
	.string "di masa depan…\p"
	.string "Semuanya harus sama-sama dihargai.\n"
	.string "Aku lihat kamu mengingatnya.$"
