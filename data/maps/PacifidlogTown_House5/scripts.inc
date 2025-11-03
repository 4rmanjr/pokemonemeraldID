PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Aku tidak bisa melihat PULAU FATAMORGANA hari ini…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Astaga!\n"
	.string "Aku bisa melihat PULAU FATAMORGANA hari ini!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "PULAU FATAMORGANA…\p"
	.string "Pasti akan terlihat dan tidak terlihat\n"
	.string "tergantung pada kondisi cuaca\l"
	.string "yang menyebabkan fatamorgana muncul.\p"
	.string "Atau apakah ia benar-benar muncul dan\n"
	.string "menghilang?$"

