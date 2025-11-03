AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Apa lucunya bawa ban dalam\n"
	.string "ke kapal?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Whoa, aku kalah telak!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Sulit melempar POKé BALL sambil\n"
	.string "berpegangan pada ban dalam!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Di sini menyenangkan, bukan?\n"
	.string "Aku jadi semangat hanya di sini!$"
