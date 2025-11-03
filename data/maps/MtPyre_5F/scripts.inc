MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Aku suka semua hal yang mengerikan…\n"
	.string "Ini seperti penyakit…\p"
	.string "Ketika Aku di sini…\n"
	.string "Aku menggigil ketakutan…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Kalah, Aku tidak suka…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Aku ingin melihat hal-hal yang mengerikan…\n"
	.string "Aku tidak bisa pergi…\p"
	.string "Tetaplah…\n"
	.string "Maukah kamu tetap bersamaku?$"

