BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
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

