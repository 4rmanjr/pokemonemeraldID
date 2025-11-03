MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Berbagai macam makhluk berkeliaran di lereng\n"
	.string "GUNUNG PYRE…\p"
	.string "Tidak ada yang tahu apa yang mungkin terjadi.\n"
	.string "Ambillah ini. Ini demi kebaikanmu.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Minta POKéMON memegang\n"
	.string "CLEANSE TAG itu.\p"
	.string "Itu akan membantu mengusir POKéMON liar.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Apakah kamu datang untuk menghormati\n"
	.string "roh-roh POKéMON yang telah tiada?\p"
	.string "Kamu pasti sangat peduli pada POKéMON-mu.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Ini adalah tempat peristirahatan terakhir\n"
	.string "ZIGZAGOON-ku. Aku sangat menyayanginya…$"

