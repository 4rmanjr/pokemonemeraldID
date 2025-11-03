//gemini
Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "Taruhan minimum di meja ini\n"
	.string "adalah {STR_VAR_1}. Kamu mau main?$"

Roulette_Text_NotEnoughCoins::
	.string "Kamu tidak punya cukup KOIN.$"

Roulette_Text_SpecialRateTable::
	.string "Meja taruhan spesial sekarang!$"

Roulette_Text_ControlsInstruction::
	.string "Pasang taruhanmu dengan + Control\n"
	.string "Pad, lalu tekan Tombol A.$"

Roulette_Text_ItsAHit::
	.string "Kena!$"

Roulette_Text_Jackpot::
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
	.string "Tidak ada apa-apa!$"

Roulette_Text_YouveWonXCoins::
	.string "Kamu memenangkan {STR_VAR_1} KOIN!$"

Roulette_Text_NoCoinsLeft::
	.string "Tidak ada KOIN tersisa…$"

Roulette_Text_KeepPlaying::
	.string "Lanjut main?$"

Roulette_Text_BoardWillBeCleared::
	.string "Papan ROULETTE akan dibersihkan.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Kamu tidak punya KOTAK KOIN.$"

Roulette_Text_CoinCaseIsFull::
	.string "KOTAK KOIN-mu penuh!\n"
	.string "Koin bisa ditukar dengan hadiah.$"
