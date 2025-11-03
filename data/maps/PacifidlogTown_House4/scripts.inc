PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Orang-orang bilang mereka melihat POKéMON\n"
	.string "terbang tinggi di atas HOENN.\p"
	.string "Apakah ia terbang terus-menerus?\n"
	.string "Apakah ia tidak butuh istirahat?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "POKéMON langit!\n"
	.string "POKéMON langit!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Dari mana kamu berasal?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Ya?\n"
	.string "KOTA YA?\p"
	.string "Aku belum pernah mendengar tempat seperti itu.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Tidak? Itu tidak masuk akal.\n"
	.string "Kamu pasti berasal dari suatu tempat.\p"
	.string "Oh! Tunggu! Kamu tidak akan bilang kamu\n"
	.string "lahir di dasar laut?$"

