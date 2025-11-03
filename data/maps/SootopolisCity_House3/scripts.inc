//gemini
SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Kamu seorang TRAINER POKéMON, ya?\p"
	.string "JUAN dari SOOTOPOLIS punya banyak\n"
	.string "penggemar. Bahkan lebih banyak dari\l"
	.string "muridnya, WALLACE!\p"
	.string "Apa kamu punya?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, kalau begitu kamu pasti cukup\n"
	.string "kuat.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, sayang… Itu sedikit kesepian.\p"
	.string "Coba berusaha sedikit lebih keras\n"
	.string "untuk mendapatkan penggemar.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Penggemar setia datang bahkan dari\n"
	.string "luar HOENN.\p"
	.string "Sungguh gila saat Aku pergi ke KLUB\n"
	.string "PENGGEMAR TRAINER di LILYCOVE.$"
