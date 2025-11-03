//gemini
SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE…\p"
	.string "Di puncaknya terdapat dua orb\n"
	.string "diletakkan berdampingan. Kamu tahu?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Ya, dua orb berdampingan…\p"
	.string "Pemandangan mereka berdua… Entah\n"
	.string "kenapa itu terasa menenangkan…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Begitukah? Mungkin kamu harus\n"
	.string "berkunjung dan melihat…$"
