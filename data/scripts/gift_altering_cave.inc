//gemini
MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.\p"
	.string "Sepertinya ada rumor tentang\n"
	.string "penampakan POKéMON langka.\p"
	.string "Penampakan itu dilaporkan\n"
	.string "berasal dari ALTERING CAVE\l"
	.string "di RUTE 103.\p"
	.string "Mungkin ada baiknya kamu\n"
	.string "menyelidiki rumor ini.$"
