//gemini
SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseBoxMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseBoxMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Apakah Kamu tahu POKéMON SEEDOT?\n"
	.string "Jarang sekali terlihat di\l"
	.string "SOOTOPOLIS.\p"
	.string "Pokoknya, Aku suka SEEDOT yang\n"
	.string "besar. Semakin besar, semakin baik.\p"
	.string "Tapi adik laki-lakiku, dia bilang\n"
	.string "LOTAD lebih besar.\p"
	.string "Itu konyol. SEEDOT pasti lebih\n"
	.string "besar dari itu!\p"
	.string "Hah? Kamu bawa SEEDOT? T-t-tolong,\n"
	.string "tunjukkan padaku!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2}! Ya ampun, ini besar\n"
	.string "sekali!\p"
	.string "Ini bahkan bisa mengalahkan LOTAD\n"
	.string "besar yang dilihat adik\l"
	.string "laki-lakiku!\p"
	.string "Terima kasih sudah menunjukkannya.\n"
	.string "Ini adalah tanda terima kasih\l"
	.string "dariku!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} menerima POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hah? TAS Kamu sudah penuh sesak.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2}, ya?\p"
	.string "Hmm… Aku pernah melihat SEEDOT yang\n"
	.string "lebih besar dari ini.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, ini lumayan… Tapi ini bukan\n"
	.string "SEEDOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Kamu tidak punya SEEDOT yang besar?\n"
	.string "Sayang sekali…\p"
	.string "Jika Kamu mendapatkan SEEDOT besar,\n"
	.string "tolong datang dan tunjukkan padaku.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "SEEDOT terbesar dalam sejarah!\n"
	.string "Raksasa {STR_VAR_3} milik\l"
	.string "{STR_VAR_2}!\p"
	.string "SEEDOT yang lebih besar dari LOTAD,\n"
	.string "selalu Aku inginkan!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Apakah Kamu tahu POKéMON LOTAD?\n"
	.string "Jarang terlihat di SOOTOPOLIS.\p"
	.string "Aku suka, maksudku sangat suka,\n"
	.string "LOTAD yang besar!\p"
	.string "Kakak laki-lakiku bilang SEEDOT\n"
	.string "yang lebih besar.\p"
	.string "Tapi itu salah! Semua orang tahu\n"
	.string "LOTAD jauh lebih besar.\p"
	.string "Hah? Kamu bawa LOTAD? T-t-tolong\n"
	.string "tunjukkan padaku!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2}! Wow, itu besar!\p"
	.string "Mungkin ini bahkan lebih besar dari\n"
	.string "SEEDOT raksasa yang dilihat kakak\l"
	.string "laki-lakiku.\p"
	.string "Terima kasih sudah menunjukkannya!\n"
	.string "Ini adalah tanda terima kasih\l"
	.string "dariku!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} menerima POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hah? TAS Kamu sudah penuh sesak.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2}?\p"
	.string "Hmm… Aku pernah melihat LOTAD yang\n"
	.string "lebih besar dari yang ini.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Wah, ini lumayan! Tapi ini bukan\n"
	.string "LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Kamu tidak punya LOTAD yang besar?\n"
	.string "Sungguh mengecewakan…\p"
	.string "Jika Kamu mendapatkan LOTAD besar,\n"
	.string "tolong datang dan tunjukkan padaku!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "LOTAD terbesar dalam sejarah!\n"
	.string "Raksasa {STR_VAR_3} milik\l"
	.string "{STR_VAR_2}!\p"
	.string "LOTAD yang lebih besar dari SEEDOT,\n"
	.string "selalu Aku inginkan!$"
