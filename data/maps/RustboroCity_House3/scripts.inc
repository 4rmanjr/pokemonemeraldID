RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Untuk POKÉMON-ku, aku\n"
	.string "beri nama panggilan yang\l"
	.string "sangat cocok!\p"
	.string "Itu caraku menunjukkan,\n"
	.string "eh… orisinalitas! Ya, itu!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Tapi memberi nama PEKACHU\n"
	.string "pada PIKACHU? Seperti\l"
	.string "tidak ada gunanya.\p"
	.string "Memang bagus pakai nama\n"
	.string "yang mudah dimengerti,\l"
	.string "tapi…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"
