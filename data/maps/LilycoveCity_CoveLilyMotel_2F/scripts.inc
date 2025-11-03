LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Aku seorang GAME DESIGNER.\p"
	.string "Oh, benarkah? Kamu sedang\n"
	.string "mengerjakan POKéDEX?\p"
	.string "Menyelesaikannya memang sulit,\n"
	.string "tapi jangan menyerah.\p"
	.string "Jika kamu berhasil menyelesaikannya,\n"
	.string "tolong perlihatkan padaku.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! Keren sekali!\n"
	.string "Yap, benar-benar keren!\p"
	.string "POKéDEX ini terisi penuh!\n"
	.string "Kamu pasti sangat menyukai POKéMON!\p"
	.string "Aku sangat terkesan!\p"
	.string "Biar kuberikan sesuatu sebagai\n"
	.string "penghargaan atas pencapaianmu!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Aku? Kamu bicara padaku?\n"
	.string "Aku seorang PROGRAMMER.\p"
	.string "Aku penasaran seperti apa SLOTS\n"
	.string "di sini.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Aku GRAPHIC ARTIST! POKéMON di HOENN\n"
	.string "menarik, bukan?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Para TUBER perempuan, mereka imut, kan?\n"
	.string "Bertarung melawan TUBER yang imut…\p"
	.string "Whoop, keren sekali!\p"
	.string "Dan para TWINS! Imut juga, kan?\n"
	.string "Pertarungan 2-lawan-2 dengan TWINS…\p"
	.string "Whoop, sangat menyenangkan!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Angin laut menyejukkan hatiku.\n"
	.string "Rasanya indah sekali di sini!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Kamu tidak akan pernah tahu kapan dan\n"
	.string "di mana orang akan menantangmu.\p"
	.string "Itulah sebabnya aku tidak pernah pergi\n"
	.string "tanpa GAME BOY ADVANCE-ku.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hah?!\n"
	.string "Oh, maaf, maaf! Aku ketiduran!\p"
	.string "Aku datang untuk melihat\n"
	.string "POKéMON CONTEST ini.\p"
	.string "Harus kuakui, kelihatannya cukup\n"
	.string "menghibur, tapi…\p"
	.string "Anggap saja aku seorang purist--aku\n"
	.string "lebih suka pertarungan dan TRAINER tangguh.\p"
	.string "Tapi itu hanya pendapatku.\p"
	.string "{PLAYER}, kuharap kamu menikmati semuanya\n"
	.string "seperti GYM, CONTEST, BATTLE TENT,\l"
	.string "dan semuanya!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Menurutku butuh strategi\n"
	.string "untuk memenangkan CONTEST.\p"
	.string "Menyusun strategi CONTEST adalah salah\n"
	.string "satu cara menjadi TRAINER lebih baik, menurutku.$"

