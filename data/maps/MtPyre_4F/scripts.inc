MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Aku suka semua hal\n"
	.string "yang mengerikan…\p"
	.string "Ini seperti penyakit…\p"
	.string "Saat aku di sini…\n"
	.string "Aku gemetar ketakutan…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Aku tidak suka kalah…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Aku ingin melihat\n"
	.string "hal-hal mengerikan…\p"
	.string "Aku tidak bisa pergi…\p"
	.string "Tinggallah…\n"
	.string "Maukah kamu tinggal bersamaku?$"
