//gemini
SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Halo! Kamu tamu pertama kami\n"
	.string "setelah sekian lama.\p"
	.string "Kamu telah mencerahkan hari Aku,\n"
	.string "jadi Aku akan berikan Kamu WAILMER\l"
	.string "DOLL yang besar.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Jaga baik-baik!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, Kamu menginginkannya, tapi\n"
	.string "tidak sekarang? Oke, kalau begitu\l"
	.string "Aku akan menyimpannya untuk Kamu.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Apa Kamu yakin? Kamu tidak mau DOLL\n"
	.string "ini?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Aku suka DOLL mewah!$"
