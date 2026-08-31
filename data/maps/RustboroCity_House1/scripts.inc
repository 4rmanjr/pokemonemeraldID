RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hah? POKéMON-ku imut?\n"
	.string "Tentu, aku tahu itu.\p"
	.string "Tapi jika kamu benar-benar mau,\n"
	.string "aku bersedia menukarkannya padamu.\p"
	.string "Aku akan menukar {STR_VAR_2}-ku dengan\n"
	.string "seekor {STR_VAR_1} jika kamu mau.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh...\n"
	.string "Tolong rawat baik-baik POKéMON-ku.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hah? Itu tidak terlihat seperti\n"
	.string "seekor {STR_VAR_1} bagiku.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, jika kamu tidak mau, tidak apa-apa.\n"
	.string "Tapi POKéMON-ku imut, lho...$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "POKéMON mana pun bisa jadi imut\n"
	.string "jika kamu merawatnya dengan baik.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Di berbagai tempat, ada berbagai\n"
	.string "macam POKéMON dan orang.\p"
	.string "Aku merasa itu menarik, jadi aku pergi\n"
	.string "ke berbagai tempat.$"

