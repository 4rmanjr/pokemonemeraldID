//gemini
Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, astaga. Bukankah POKéMON-mu\n"
	.string "kelelahan?\p"
	.string "Kalau Kamu mau, istirahatlah di sini.\n"
	.string "Itu ide bagus! Kamu harus\l"
	.string "melakukannya.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Itu benar. Santai saja dan\n"
	.string "istirahatlah!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, astaga. Apakah POKéMON-mu masih\n"
	.string "lelah?\p"
	.string "Kamu harus beristirahat lagi di sini.\n"
	.string "Itu ide bagus. Kamu harus\l"
	.string "melakukannya.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Begitukah? Kamu tidak perlu malu\n"
	.string "tentang itu.$"
