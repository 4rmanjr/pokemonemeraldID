FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wrooooaaar! Aku butuh itu!\n"
	.string "Aku harus mendapatkan {STR_VAR_1}!\l"
	.string "Akan kulakukan apapun untuk itu!\p"
	.string "…Uh… Apa kamu dengar itu?\n"
	.string "Teriakan dari lubuk hatiku?\p"
	.string "Setelah mendengarnya, kamu mau\n"
	.string "menukar {STR_VAR_1}-mu dengan\l"
	.string "{STR_VAR_2}-ku, kan?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh, yeah, mantap!\p"
	.string "{STR_VAR_1}, selamat datang!\n"
	.string "{STR_VAR_2}, baik-baik ya!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Uh, bukan, kurasa bukan.\n"
	.string "Itu bukan {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Tidak? Kamu tidak mau bertukar?\n"
	.string "Bahkan setelah aku mencurahkan isi\l"
	.string "hatiku padamu?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Aku akan membuat VOLBEAT super kuat\n"
	.string "mulai saat ini!\p"
	.string "Kuharap kamu melakukan hal yang sama\n"
	.string "dengan PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Bertukar POKéMON dengan orang lain…\p"
	.string "Seolah-olah kamu menukar ingatanmu\n"
	.string "sendiri dengan orang lain.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gumomoh?$"
