BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Kami datang ke sini untuk menemani\n"
	.string "cucu kami.\p"
	.string "Tapi karena sudah di sini, kami pikir\n"
	.string "harus membeli beberapa oleh-oleh.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Sayang, bagaimana menurutmu tentang ini?\n"
	.string "Bukankah ini akan menjadi hadiah yang bagus?\p"
	.string "Ini…PRO…TE…IN?\n"
	.string "Kedengarannya enak, bukan?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "Banyak fasilitas BATTLE FRONTIER\n"
	.string "tidak mengizinkan penggunaan item\l"
	.string "selama pertarungan.\p"
	.string "Aturan itu membuat segalanya lebih sulit\n"
	.string "dari yang sudah ada!$"

