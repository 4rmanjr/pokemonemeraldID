RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, sulit sekali setiap hari…\p"
	.string "Apa yang sulit?\n"
	.string "Kamu perlu bertanya?\p"
	.string "Yaitu mencoba mencari tahu apa yang\n"
	.string "akan dibuat untuk makan setiap hari.\p"
	.string "Sungguh tidak mudah menyiapkan\n"
	.string "makanan setiap hari.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, halo!\n"
	.string "Selamat datang di keluarga PEPPER.\p"
	.string "Aku punya pertanyaan untukmu.\n"
	.string "Apakah kamu pernah menjaga bayi?\p"
	.string "Soalnya, aku ayah baru, jadi membesarkan\n"
	.string "anak adalah hal baru bagiku.\p"
	.string "Dan aku punya masalah. Putriku\n"
	.string "WALDA tidak cukup tertawa.\p"
	.string "Kurasa dia akan tertawa jika\n"
	.string "aku mengatakan sesuatu yang lucu\l"
	.string "padanya.\p"
	.string "Apa kamu tahu kata atau frasa lucu\n"
	.string "yang bisa kamu beritahukan padaku?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Aku sudah mengatakan “{STR_VAR_1}”\n"
	.string "untuk menghiburnya akhir-akhir ini.\p"
	.string "Apa kamu tahu kata atau frasa yang\n"
	.string "lebih baik yang mungkin berhasil?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, itu luar biasa.\n"
	.string "Jadi, mari kita dengar saranmu.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, begitu?\p"
	.string "Yah, jika kamu punya saran bagus,\n"
	.string "aku akan mendengarkan.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, aku mengerti.\n"
	.string "Baiklah, mari kita coba, ya?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, ya! Dia tertawa!\n"
	.string "Oh, aku sama senangnya dengannya!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, aku mengerti.\n"
	.string "Baiklah, mari kita coba, ya?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Dia tidak tersenyum sama\n"
	.string "sekali. Mungkin WALDA adalah anak\l"
	.string "yang serius…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, jadi kamu tidak tahu kata-kata\n"
	.string "yang bagus. Sebaiknya aku berpikir\l"
	.string "sendiri, kalau begitu.\p"
	.string "Hmm…\n"
	.string "Bagaimana kalau “{STR_VAR_1}”?\l"
	.string "Mari kita lihat apakah itu berhasil.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Dia tidak tersenyum sama\n"
	.string "sekali. Mungkin WALDA adalah anak\l"
	.string "yang serius…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, jadi kamu tidak tahu kata-kata\n"
	.string "yang bagus. Kurasa aku akan mencoba\l"
	.string "menghiburnya dengan perkataan yang\l"
	.string "kupakai sebelumnya.\p"
	.string "Bagaimanapun, jika kamu punya saran\n"
	.string "bagus, jangan ragu untuk\l"
	.string "memberitahuku, oke?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Terima kasih!\p"
	.string "Berkat kamu, WALDA kesayanganku\n"
	.string "tertawa untukku!\p"
	.string "Sebenarnya, aku mungkin tidak terlihat\n"
	.string "istimewa, tapi aku salah satu peneliti\l"
	.string "terbaik DEVON CORPORATION.\p"
	.string "Jadi, bagaimana kalau aku melakukan\n"
	.string "sesuatu sebagai balas budi untukmu?\p"
	.string "Aku tahu, aku akan menambahkan pola\n"
	.string "wallpaper baru untuk KOTAK di Sistem\l"
	.string "Penyimpanan POKéMON PC.\p"
	.string "Di menu pola wallpaper, pilih “TEMAN.”\p"
	.string "Itu akan memberimu akses ke pola\n"
	.string "wallpaper baru.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Itu BONEKA mewah POKéMON!$"

