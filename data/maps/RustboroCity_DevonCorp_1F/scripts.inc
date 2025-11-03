RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Halo dan selamat datang di DEVON\n"
	.string "CORPORATION.\p"
	.string "Kami adalah produsen item dan\n"
	.string "obat-obatan yang meningkatkan\l"
	.string "kualitas hidupmu.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Salah satu staf penelitian kami\n"
	.string "dengan bodohnya dirampok sebuah\l"
	.string "paket penting.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hei, SEPATU LARI itu!\n"
	.string "Itu salah satu produk kami!\p"
	.string "Aku senang sekali melihat seseorang\n"
	.string "menggunakan produk buatan kami.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Paket yang dicuri itu…\p"
	.string "Ya, memang penting, tapi itu bukan\n"
	.string "sesuatu yang bisa digunakan siapa pun.\p"
	.string "Menurut perkiraanku, perampok itu\n"
	.string "pasti tidak terlalu cerdas.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Sepertinya BARANG DEVON yang dicuri\n"
	.string "sudah ditemukan.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Maaf, hanya orang yang berwenang\n"
	.string "yang diizinkan masuk ke sini.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Ini sangat bodoh.\n"
	.string "Bagaimana kita bisa dirampok?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hai!\n"
	.string "Kamu selalu diterima di sini!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Sampel batuan dan logam\n"
	.string "dipamerkan di kotak kaca.\p"
	.string "Ada panel dengan tulisan di atasnya…\p"
	.string "“DEVON CORPORATION dimulai sebagai\n"
	.string "produsen batu dari tambang.\p"
	.string "“Perusahaan juga memproduksi besi\n"
	.string "dari serbuk pasir.\p"
	.string "“Dari awal yang sederhana sebagai\n"
	.string "produsen bahan mentah, DEVON\l"
	.string "berkembang.\p"
	.string "“DEVON kini adalah produsen berbagai\n"
	.string "macam produk industri.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototipe dan produk uji mengisi\n"
	.string "kotak pajangan kaca.\p"
	.string "Ada panel dengan deskripsi…\p"
	.string "“Selain produk industri, DEVON kini\n"
	.string "memasarkan berbagai barang dan obat-\l"
	.string "obatan untuk gaya hidup yang lebih\l"
	.string "baik.\p"
	.string "“Baru-baru ini, DEVON mulai memasarkan\n"
	.string "alat untuk TRAINER POKéMON, termasuk\l"
	.string "POKé BALL dan sistem POKéNAV.”$"

