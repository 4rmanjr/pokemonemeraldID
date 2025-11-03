LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Selamat datang di TOKO HERBAL,\n"
	.string "rumah obat-obatan yang efektif dan\l"
	.string "murah!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Kamu datang untuk melihat obat herbal\n"
	.string "di LAVARIDGE?\p"
	.string "Itu cukup terpuji.\p"
	.string "Aku suka kamu! Ambil ini!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "CHARCOAL yang kuberikan padamu itu,\n"
	.string "digunakan untuk membuat obat herbal.\p"
	.string "Itu juga bekerja dengan baik saat\n"
	.string "dipegang oleh POKéMON.\p"
	.string "Itu meningkatkan kekuatan jurus tipe\n"
	.string "API.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Obat herbal bekerja dengan sangat\n"
	.string "baik. Tapi POKéMON-mu akan tidak\l"
	.string "menyukaimu karenanya. Pasti rasanya\l"
	.string "sangat pahit!$"
