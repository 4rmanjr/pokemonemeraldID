MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Saat aku muda, aku berkeliling dunia\n"
	.string "sebagai POKéMON TRAINER.\p"
	.string "Sekarang setelah aku menjadi orang tua,\n"
	.string "satu-satunya hiburanku adalah menonton\l"
	.string "pertarungan TRAINER muda.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "Pintunya sepertinya terkunci.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Seorang TRAINER bernama {STR_VAR_1} sedang\n"
	.string "mengunjungi rumahku.\p"
	.string "Apakah kamu ingin menantang\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Kamu tidak akan bertarung? Aku kecewa\n"
	.string "tidak bisa melihatmu bertarung…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, bagus, bagus!\p"
	.string "Tapi rumahku tidak terlalu kokoh.\p"
	.string "Bisakah aku memintamu untuk\n"
	.string "membatasinya menjadi pertandingan 3\l"
	.string "lawan 3?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Sebelum kalian berdua bertarung,\n"
	.string "sebaiknya kamu menyimpan progresmu.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Aku harap bisa melihat pertandingan\n"
	.string "yang bagus!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Jadi, hasilnya seri.\p"
	.string "Itu adalah pertandingan yang brilian di\n"
	.string "mana tidak ada pihak yang mau mengalah!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Itu luar biasa!\p"
	.string "Wah, seperti melihat diriku di masa\n"
	.string "muda lagi!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, sayang sekali!\p"
	.string "Tapi itu pertandingan yang bagus.\n"
	.string "Aku harap kamu bisa menang lain kali.$"
