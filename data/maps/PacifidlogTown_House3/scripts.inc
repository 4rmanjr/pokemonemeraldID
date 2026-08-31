PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
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

