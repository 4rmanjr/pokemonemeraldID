BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Howdy! Kalau soal berita tentang\n"
	.string "BATTLE FRONTIER, akulah no. 1.\p"
	.string "Kamu bisa menganggapku sebagai\n"
	.string "FRONTIER MANIAC.\p"
	.string "Hanya memastikan, kamu seorang TRAINER,\n"
	.string "'kan?\p"
	.string "Aku akan dengan senang hati membagikan berita\n"
	.string "terpanas yang kukumpulkan tentang BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Howdy! Apa kamu mampir untuk menanyaiku\n"
	.string "tentang berita terbaru? Oh, baiklah!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Bagaimana? Bagaimana? Bagaimana?\p"
	.string "Aku yakin informasiku sangat\n"
	.string "berguna untukmu, kan?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Coba kita lihat…\p"
	.string "Sepertinya {STR_VAR_1}\n"
	.string "adalah tempat terpanas saat ini.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Coba kita lihat…\p"
	.string "Sepertinya BATTLE TOWER\n"
	.string "{STR_VAR_1} adalah yang terpanas.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER misterius bernama\n"
	.string "SALON MAIDEN yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Pernahkah kamu melawan SALON MAIDEN?\p"
	.string "Saat dia mengukur lawannya,\n"
	.string "dia sepertinya menggunakan POKéMON ini:\p"
	.string "POKéMON PSI tipe PSYCHIC,\n"
	.string "POKéMON VOLCANO tipe FIRE,\l"
	.string "dan POKéMON SLEEPING tipe NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Pernahkah kamu melawan SALON MAIDEN\n"
	.string "saat dia serius?\p"
	.string "Saat dia bertarung habis-habisan,\n"
	.string "dia sepertinya menggunakan POKéMON ini:\p"
	.string "POKéMON EON tipe DRAGON & PSYCHIC,\n"
	.string "POKéMON THUNDER tipe ELECTRIC,\l"
	.string "dan POKéMON SLEEPING tipe NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER flamboyan bernama\n"
	.string "DOME ACE yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Pernahkah kamu melawan DOME ACE?\p"
	.string "Saat dia meremehkan lawannya,\n"
	.string "dia menggunakan tiga POKéMON ini:\p"
	.string "POKéMON DRAGON tipe DRAGON & FLYING,\n"
	.string "POKéMON MUD FISH tipe WATER & GROUND,\l"
	.string "dan POKéMON FLAME tipe FIRE & FLYING.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Pernahkah kamu melawan DOME ACE\n"
	.string "saat dia serius?\p"
	.string "Saat dia menunjukkan strateginya,\n"
	.string "dia menggunakan tiga POKéMON ini:\p"
	.string "POKéMON EON tipe DRAGON & FLYING,\n"
	.string "POKéMON MUD FISH tipe WATER & GROUND,\l"
	.string "dan POKéMON IRON LEG tipe STEEL & PSYCHIC.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER aneh bernama\n"
	.string "FACTORY HEAD yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Sudahkah kamu melawan FACTORY HEAD?\p"
	.string "Coba kupikir… Saat dia bertarung,\n"
	.string "dia hanya mendapat tiga POKéMON sewaan.\p"
	.string "Dia bertarung dalam kondisi yang hampir\n"
	.string "sama denganmu.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Pernahkah kamu melawan FACTORY HEAD\n"
	.string "saat dia serius?\p"
	.string "Saat dia bertarung dengan serius,\n"
	.string "dia tetap mendapat tiga POKéMON sewaan.\p"
	.string "Dia bertarung dalam kondisi yang\n"
	.string "hampir sama denganmu.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER menakutkan bernama\n"
	.string "PIKE QUEEN yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Pernahkah kamu melawan PIKE QUEEN\n"
	.string "sebelumnya?\p"
	.string "Saat suasana hatinya sedang baik, katanya\n"
	.string "dia menggunakan tiga POKéMON ini:\p"
	.string "POKéMON FANG SNAKE tipe POISON,\n"
	.string "POKéMON MOLD tipe BUG & ROCK,\l"
	.string "dan POKéMON TENDER tipe WATER.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Pernahkah kamu melawan PIKE QUEEN\n"
	.string "saat dia serius?\p"
	.string "Saat dia benar-benar kesal, katanya\n"
	.string "dia menggunakan tiga POKéMON ini:\p"
	.string "POKéMON FANG SNAKE tipe POISON,\n"
	.string "POKéMON IRON SNAKE tipe STEEL & GROUND,\l"
	.string "dan POKéMON ATROCIOUS tipe WATER & FLYING.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER imut bernama\n"
	.string "ARENA TYCOON yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Pernahkah kamu melawan ARENA TYCOON\n"
	.string "sebelumnya?\p"
	.string "Saat dia menilai kemampuan lawan,\n"
	.string "dia konon menggunakan POKéMON ini:\p"
	.string "POKéMON SINGLE HORN tipe BUG & FIGHTING,\n"
	.string "POKéMON MOONLIGHT tipe DARK,\l"
	.string "dan POKéMON SHED tipe BUG & GHOST.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Pernahkah kamu melawan ARENA TYCOON\n"
	.string "saat dia serius?\p"
	.string "Saat dia bertarung sungguhan,\n"
	.string "dia konon menggunakan POKéMON ini:\p"
	.string "POKéMON MOONLIGHT tipe DARK,\n"
	.string "POKéMON SHADOW tipe GHOST & POISON\l"
	.string "dan POKéMON MUSHROOM tipe GRASS & FIGHTING.$"


BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER jahat bernama\n"
	.string "PALACE MAVEN yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Pernahkah kamu melawan PALACE MAVEN\n"
	.string "sebelumnya?\p"
	.string "Saat dia menguji semangat lawan,\n"
	.string "katanya dia menggunakan POKéMON ini:\p"
	.string "POKéMON BAT tipe POISON & FLYING,\n"
	.string "POKéMON LAZY tipe NORMAL, dan\l"
	.string "POKéMON TRANSPORT tipe WATER & ICE.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Pernahkah kamu melawan PALACE MAVEN\n"
	.string "saat dia serius?\p"
	.string "Saat dia mengerahkan seluruh kekuatannya\n"
	.string "dalam pertarungan, katanya dia menggunakan POKéMON ini:\p"
	.string "POKéMON LEGENDARY tipe FIRE,\n"
	.string "POKéMON LAZY tipe NORMAL,\l"
	.string "dan POKéMON AURORA tipe WATER.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Pasti kamu tidak tahu ini!\p"
	.string "Salah satu TRAINER top yang disebut SCOTT\n"
	.string "sebagai FRONTIER BRAIN ada di sana.\p"
	.string "TRAINER yang berapi-api bernama\n"
	.string "PYRAMID KING yang mengelola tempat itu.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Pernahkah kamu melawan PYRAMID KING\n"
	.string "sebelumnya?\p"
	.string "Saat dia memeriksa kekuatan lawan,\n"
	.string "dia sepertinya menggunakan POKéMON ini:\p"
	.string "POKéMON ROCK PEAK tipe ROCK,\n"
	.string "POKéMON ICEBERG tipe ICE,\l"
	.string "dan POKéMON IRON tipe STEEL.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Pernahkah kamu melawan PYRAMID KING\n"
	.string "saat dia serius?\p"
	.string "Saat dia dipenuhi kekuatan panas,\n"
	.string "dia sepertinya menggunakan POKéMON ini:\p"
	.string "POKéMON FREEZE tipe ICE & FLYING, POKéMON\n"
	.string "ELECTRIC tipe ELECTRIC & FLYING,\l"
	.string "dan POKéMON FLAME tipe FIRE & FLYING.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Tentu, ada beberapa tempat di mana\n"
	.string "kamu bisa mengikuti DOUBLE BATTLE.\p"
	.string "Tapi RUANG DOUBLE BATTLE di\n"
	.string "BATTLE TOWER itu, semacam, dasar!\p"
	.string "Di sanalah kamu harus belajar tentang\n"
	.string "bagaimana DOUBLE BATTLE dimainkan di\l"
	.string "BATTLE FRONTIER ini.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Hati-hati dalam pertarungan di sini.\p"
	.string "Kudengar ada TRAINER yang punya\n"
	.string "strategi yang mereka kembangkan khusus\l"
	.string "untuk DOUBLE BATTLE.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Setelah kamu percaya diri dan nyaman\n"
	.string "dengan DOUBLE BATTLE di sini, kamu harus\l"
	.string "mempertimbangkan untuk menantang tempat lain\l"
	.string "yang menawarkan DOUBLE BATTLE.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Segala macam TRAINER berkumpul di\n"
	.string "BATTLE SALON.\p"
	.string "Coba pikirkan--kamu mungkin bertemu\n"
	.string "teman atau pengikutmu!\l"
	.string "Kamu harus melihat dengan cermat!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Jika kamu bersama teman, pergilah ke\n"
	.string "RUANG LINK MULTI BATTLE.\p"
	.string "Jika kamu bermain dengan teman yang kuat,\n"
	.string "kamu bisa berharap bertemu lawan yang tangguh!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Kekuatan mengumpulkan berita yang luar biasa!\n"
	.string "Mentorku tiada duanya!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Daya observasi yang luar biasa!\n"
	.string "Mentorku tiada duanya!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Kekuatan persuasi yang luar biasa!\n"
	.string "Mentorku tiada duanya!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Tempat apa ini?\n"
	.string "Menakutkan…$"


