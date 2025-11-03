//gemini
Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Maaf semuanya berantakan…\n"
	.string "Kalau aku asyik meneliti,\l"
	.string "jadinya begini…\p"
	.string "Ini memalukan… Tolong\n"
	.string "rahasiakan ini sebagai\l"
	.string "imbalan untuk ini.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Bolehkah aku beri saran tentang\n"
	.string "Sistem Penyimpanan Pokémon-ku?\p"
	.string "Kamu harus atur BOXES-mu agar\n"
	.string "tahu Pokémon mana di dalamnya.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ini catatan penelitian LANETTE.\n"
	.string "Ada info tentang BOXES.\p"
	.string "Rancang BOXES untuk 30 Pokémon.\p"
	.string "Setiap TRAINER harus bisa simpan\n"
	.string "420 Pokémon di sistem PC.\p"
	.string "Lanjutkan membaca?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Sistem penandaan harus ditambah\n"
	.string "agar Pokémon mudah diatur.\p"
	.string "Nama & desain wallpaper tiap\n"
	.string "BOX bisa diubah agar senang\l"
	.string "Pokémon yang disimpan.\p"
	.string "Lanjutkan membaca?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Saat simpan Pokémon, ia harus\n"
	.string "dikirim ke BOX terakhir diperiksa.\p"
	.string "Jika BOX itu penuh, Pokémon\n"
	.string "diterima disimpan di BOX berikut.\p"
	.string "Artinya, saat BOX diperiksa,\n"
	.string "ia otomatis terpilih sebagai BOX\l"
	.string "tempat Pokémon dikirim.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} menutup buku catatan itu.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Ada e-mail dari seseorang di\n"
	.string "PC.\p"
	.string "“… … … … … … …\p"
	.string "“Sistem Penyimpananmu lebih\n"
	.string "nyaman dari milikku.\p"
	.string "“Punya banyak fitur ramah pengguna\n"
	.string "yang membuatnya asyik & berguna.\p"
	.string "“Aku bangga telah berperan\n"
	.string "dalam pengembangannya.\p"
	.string "“Semoga kamu terus meneliti\n"
	.string "Sistem Penyimpanan.\p"
	.string "“Dari BILL\n"
	.string "… … … … … … … …”$"
