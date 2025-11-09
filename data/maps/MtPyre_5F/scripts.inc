//aistudio
MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Guru…\n"
	.string "Tolong awasi kemajuanku!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Guru…\n"
	.string "Tolong maafkan aku!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Sampai aku berkembang, guruku\n"
	.string "yang beristirahat di sini,\l"
	.string "tidak akan pernah menemukan\l"
	.string "kedamaian sejati…$"
