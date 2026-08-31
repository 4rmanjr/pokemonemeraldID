BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade::
	.string "POKéMON-ku adalah {STR_VAR_2}.\n"
	.string "Apa kamu tahu?\l"
	.string "Dia cukup imut dan baik.\p"
	.string "Si kecil ini, bisa kutukar dengan\n"
	.string "bangga!\p"
	.string "Maukah kamu menukar {STR_VAR_1}\n"
	.string "dengan {STR_VAR_2}-ku?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt::
	.string "Oh, manis sekali!\n"
	.string "Terima kasih!\l"
	.string "Aku janji akan merawatnya dengan baik!\p"
	.string "Oh! Kuharap kamu juga akan merawat\n"
	.string "{STR_VAR_2}-ku dengan baik!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon::
	.string "Oh, maaf!\n"
	.string "Aku tidak berniat menukar dengan apa pun\l"
	.string "selain {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo::
	.string "Oh, tidak mau?\n"
	.string "Yah, tidak apa-apa juga.\l"
	.string "Silakan kunjungi kami lagi.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined::
	.string "Terkikik!\n"
	.string "SKITTY jauh lebih imut dari yang\l"
	.string "kubayangkan. Aku senang sekali!$"

