PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Lihatlah {STR_VAR_2} ini!\p"
	.string "Ini adalah {STR_VAR_2} yang Aku tangkap\n"
	.string "kemarin untuk merayakan ulang tahunku!\p"
	.string "Oh, Aku bisa melihat kamu menginginkannya!\n"
	.string "Bagaimanapun, itu tak ternilai harganya!\p"
	.string "Aku akan memberitahumu. Aku mungkin bersedia\n"
	.string "menukarkannya dengan {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, jadi ini {STR_VAR_1}?\p"
	.string "Agak mirip {STR_VAR_2},\n"
	.string "namun sedikit berbeda.\p"
	.string "Terima kasih!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Tidak, tidak, tidak! Aku tidak akan menerima\n"
	.string "yang kurang dari {STR_VAR_1} yang asli!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, jadi kamu tidak akan\n"
	.string "melanjutkan ini?\p"
	.string "Tidak apa-apa. Aku tidak putus asa untuk\n"
	.string "melakukan pertukaran atau semacamnya.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Aku tahu Aku bisa mencarinya\n"
	.string "sendiri, tapi…\p"
	.string "Tapi Aku sangat ingin mendapatkan BAGON\n"
	.string "yang ditangkap TRAINER lain…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Apakah itu POKéDEX?\p"
	.string "Apakah kamu bertemu banyak POKéMON\n"
	.string "berbeda?\p"
	.string "Aku berharap Aku sepertimu.$"

