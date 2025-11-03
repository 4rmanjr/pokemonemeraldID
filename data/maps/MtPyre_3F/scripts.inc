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
	.string "Suasana pegunungan yang kaya\n"
	.string "telah meningkatkan kekuatan psikisku!\p"
	.string "Hanya anak kecil sepertimu…\n"
	.string "Kamu bermimpi untuk menang?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Aku tenggelam dalam rasa kasihan pada diri sendiri…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Kekuatan psikisku pasti sudah\n"
	.string "berkembang beberapa kali lipat, tapi…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Ini bukan tempat untuk anak-anak, apalagi\n"
	.string "kamu!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Aku kalah bersih…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ini berarti latihanku masih belum\n"
	.string "cukup…\p"
	.string "Aku harus terus berusaha menuju\n"
	.string "puncak…\p"
	.string "Semangat, Aku!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Mengapa kamu datang ke sini?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Itu luar biasa!\n"
	.string "Kamu adalah TRAINER yang sangat istimewa.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON yang sudah tidak ada di dunia ini.\n"
	.string "POKéMON yang bersamamu sekarang.\p"
	.string "Dan POKéMON yang akan kamu temui\n"
	.string "di masa depan…\p"
	.string "Semuanya harus dihargai sama.\n"
	.string "Harap ingat itu.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Aku ingin melihat POKéMON-mu\n"
	.string "saat mereka tumbuh lebih besar lagi…\p"
	.string "Tolong, Aku perlu melihat POKéNAV-mu.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, itu kamu…\p"
	.string "Apakah kamu datang untuk menunjukkan POKéMON-mu\n"
	.string "yang sudah dewasa kepadaku?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Betapa menakjubkan!\n"
	.string "Kamu adalah orang yang istimewa.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON yang sudah tidak ada di dunia ini.\n"
	.string "POKéMON yang bersamamu sekarang.\p"
	.string "Dan POKéMON yang akan kamu temui\n"
	.string "di masa depan…\p"
	.string "Semuanya harus dihargai sama.\n"
	.string "Aku lihat kamu sudah mengingatnya.$"

