FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Manusia… POKéMON…\p"
	.string "Kekuatan tersembunyi mereka bangkit\n"
	.string "dengan hidup di lingkungan alami…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Biar nenek ini lihat apakah kekuatan\n"
	.string "tersembunyimu telah bangkit…\p"
	.string "Aku memegang koin di tanganku.\p"
	.string "Sekarang, katakan, di tangan mana\n"
	.string "aku menyembunyikannya? Kanan? Atau\l"
	.string "kiri?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Ya, benar!\p"
	.string "Kita coba lagi.\p"
	.string "Di tangan mana aku menyembunyikan\n"
	.string "koinnya? Kanan atau kiri?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Ya, benar!\p"
	.string "Kita coba lagi.\p"
	.string "Di tangan mana aku menyembunyikan\n"
	.string "koinnya? Kanan atau kiri?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Hebat!\n"
	.string "Kekuatan tersembunyimu telah bangkit!\p"
	.string "Ini, ambil dan bangkitkan kekuatan\n"
	.string "tersembunyi POKéMON-mu.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "HIDDEN POWER adalah jurus yang\n"
	.string "berubah tergantung POKéMON-nya.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Bukan, sayang sekali.\n"
	.string "Tebakanmu salah.$"
