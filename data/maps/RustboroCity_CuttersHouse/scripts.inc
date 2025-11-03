RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Ekspresi penuh tekad itu…\n"
	.string "Gerakanmu yang lincah…\l"
	.string "Dan POKéMON-mu yang terlatih dengan\l"
	.string "baik…\p"
	.string "Kamu jelas seorang TRAINER yang\n"
	.string "terampil!\p"
	.string "Tidak, tunggu, jangan katakan sepatah\n"
	.string "kata pun. Aku bisa tahu hanya dengan\l"
	.string "melihatmu.\p"
	.string "Aku yakin kamu bisa menggunakan\n"
	.string "MESIN TERSEMBUNYI ini dengan baik.\p"
	.string "Tidak perlu malu atau sungkan.\n"
	.string "Ayo, ambillah!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "MESIN TERSEMBUNYI itu, atau disingkat\n"
	.string "HM, adalah CUT.\p"
	.string "Gerakan HM adalah gerakan yang bisa\n"
	.string "digunakan oleh POKéMON di luar\l"
	.string "pertarungan.\p"
	.string "POKéMON mana pun yang telah\n"
	.string "mempelajari CUT bisa menebang pohon\l"
	.string "tipis jika TRAINER telah\l"
	.string "mendapatkan LENCANA BATU.\p"
	.string "Dan, tidak seperti TM, HM bisa\n"
	.string "digunakan lebih dari sekali.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Ketika mereka memperluas kota\n"
	.string "RUSTBORO, ayahku membantu.\p"
	.string "Dia membuat POKéMON-nya\n"
	.string "menggunakan CUT untuk membersihkan\l"
	.string "lahan dari pohon-pohon.$"

