/*	SCCS Id: @(#)artilist.h 3.4	2003/02/12	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

#include "config.h" /* WAC for blackmarket,  spoon */

#ifdef MAKEDEFS_C
/* in makedefs.c, all we care about is the list of names */

#define A(nam,typ,s1,s2,mt,atk,dfn,cry,inv,al,cl,rac,cost) nam

static const char *artifact_names[] = {
#else
/* in artifact.c, set up the actual artifact list structure */

#define A(nam,typ,s1,s2,mt,atk,dfn,cry,inv,al,cl,rac,cost) \
 { typ, nam, s1, s2, mt, atk, dfn, cry, inv, al, cl, rac, cost, 0 }

#define     NO_ATTK	{0,0,0,0}		/* no attack */
#define     NO_DFNS	{0,0,0,0}		/* no defense */
#define     NO_CARY	{0,0,0,0}		/* no carry effects */
#define     DFNS(c)	{0,c,0,0}
#define     CARY(c)	{0,c,0,0}
#define     PHYS(a,b)	{0,AD_PHYS,a,b}		/* physical */
#define     DRLI(a,b)	{0,AD_DRLI,a,b}		/* life drain */
#define     COLD(a,b)	{0,AD_COLD,a,b}
#define     FIRE(a,b)	{0,AD_FIRE,a,b}
#define     ELEC(a,b)	{0,AD_ELEC,a,b}		/* electrical shock */
#define     STUN(a,b)	{0,AD_STUN,a,b}		/* magical attack */
#define     ACID(a,b)	{0,AD_ACID,a,b}

STATIC_OVL NEARDATA struct artifact artilist[] = {
#endif	/* MAKEDEFS_C */

/* Artifact cost rationale:
 * 1.  The more useful the artifact, the better its cost.
 * 2.  Quest artifacts are highly valued.
 * 3.  Chaotic artifacts are inflated due to scarcity (and balance).
 */


/* [Tom] rearranged by alignment, so when people ask... */
/* KMH -- Further arranged:
 * 1.  By alignment (but quest artifacts last).
 * 2.  By weapon class (skill).
 */

/*  dummy element #0, so that all interesting indices are non-zero */
A("",				STRANGE_OBJECT,
	0, 0, 0, NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 0L ),

/*** Lawful artifacts ***/
A("Firewall",                  ATHAME,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	FIRE(4,2),      FIRE(0,0),      NO_CARY,        0, A_LAWFUL, PM_FLAME_MAGE, NON_PM, 400L ),

/*
 *	The combination of SPFX_WARN and M2_something on an artifact
 *	will trigger EWarn_of_mon for all monsters that have the appropriate
 *	M2_something flags.  In Sting's case it will trigger EWarn_of_mon
 *	for M2_ORC monsters.
 */
A("Sting",			ELVEN_DAGGER,
	(SPFX_WARN|SPFX_DCLAS), 0, M2_ORC,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, PM_ELF, 800L ),

A("Giantkiller",                AXE,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_GIANT,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 800L ),

A("Quick Blade",                ELVEN_SHORT_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(9,1),      NO_DFNS,        NO_CARY,        0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Orcrist",                    ELVEN_BROADSWORD,
	SPFX_DFLAG2, 0, M2_ORC,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, PM_ELF, 2000L ),

A("Dragonbane",			BROADSWORD,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_DRAGON,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 500L ),

A("Excalibur",                  LONG_SWORD, /* removed NOGEN --Amy */
	(SPFX_RESTR|SPFX_SEEK|SPFX_DEFN|SPFX_INTEL|SPFX_SEARCH),0,0,
	PHYS(5,5),	DRLI(0,0),	NO_CARY,	0, A_LAWFUL, PM_KNIGHT, NON_PM, 4000L ),

A("Luck Blade",			BROADSWORD,
	(SPFX_RESTR|SPFX_LUCK|SPFX_INTEL),0,0,
	PHYS(5,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, PM_CONVICT, NON_PM, 3000L ),

A("Sunsword",                   LONG_SWORD,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_UNDEAD,
	PHYS(5,0),	DFNS(AD_BLND),	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

/*
 *	Ah, never shall I forget the cry,
 *		or the shriek that shrieked he,
 *	As I gnashed my teeth, and from my sheath
 *		I drew my Snickersnee!
 *			--Koko, Lord high executioner of Titipu
 *			  (From Sir W.S. Gilbert's "The Mikado")
 */
A("Snickersnee",                KATANA,
	SPFX_RESTR, 0, 0,
	PHYS(0,4),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, PM_SAMURAI, NON_PM, 1200L ),

#ifdef YEOMAN
/* KMH -- Renamed from Holy Sword of Law (Stephen White)
 * This is an actual sword used in British coronations!
 */
A("Sword of Justice",           LONG_SWORD,
	(SPFX_RESTR|SPFX_DALIGN), 0, 0,
	PHYS(5,6),     NO_DFNS,        NO_CARY,        0, A_LAWFUL, PM_YEOMAN, NON_PM, 1500L ),
#endif

A("Demonbane",			LONG_SWORD,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_DEMON,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 2500L ),

A("Werebane",			SILVER_SABER,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_WERE,
	PHYS(5,0),	DFNS(AD_WERE),	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Grayswandir",		SILVER_SABER,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 8000L ),

A("Skullcrusher",               CLUB,
	SPFX_RESTR, 0, 0,
	PHYS(3,5),     NO_DFNS,        NO_CARY,        0, A_LAWFUL, PM_CAVEMAN, NON_PM, 300L ),

A("Trollsbane",                 MORNING_STAR,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_TROLL,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 200L ),

A("Ogresmasher",		WAR_HAMMER,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_OGRE,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 200L ),

#ifdef YEOMAN
A("Reaper",                     HALBERD,
	SPFX_RESTR, 0, 0,
	PHYS(5,10),      NO_DFNS,        NO_CARY,        0, A_LAWFUL, PM_YEOMAN, NON_PM, 1000L ),
#endif

A("Holy Spear of Light",        SILVER_SPEAR,
       (SPFX_RESTR|SPFX_INTEL|SPFX_DFLAG2), 0, M2_UNDEAD,
       PHYS(5,5),      NO_DFNS,  NO_CARY,     LIGHT_AREA, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("Rod of Lordly Might", MACE, /*needs quote*/
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	PHYS(3,0),	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, PM_NOBLEMAN, NON_PM, 4000L ), 

/*** Neutral artifacts ***/
A("Magicbane",                  ATHAME,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	STUN(3,2),	DFNS(AD_MAGM),	NO_CARY,	0, A_NEUTRAL, PM_WIZARD, NON_PM, 3500L ),

A("Doom Chainsaw",	CHAINSWORD,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	PHYS(20,2),	NO_DFNS,	NO_CARY,
	0,	A_NEUTRAL, PM_DOOM_MARINE, NON_PM, 2000L ),

A("Luckblade",                  SHORT_SWORD,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	PHYS(5,3),      NO_DFNS,        NO_CARY,        0, A_NEUTRAL, NON_PM, PM_GNOME, 1000L ),

A("Sword of Balance",           SILVER_SHORT_SWORD,
	(SPFX_RESTR|SPFX_DALIGN), 0, 0,
	PHYS(2,5),      NO_DFNS,        NO_CARY,        0, A_NEUTRAL, NON_PM, NON_PM, 5000L ),

A("Frost Brand",                LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	COLD(5,0),	COLD(0,0),	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Fire Brand",                 LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	FIRE(5,0),	FIRE(0,0),	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 3000L ),

/*
 *	Two problems:  1) doesn't let trolls regenerate heads,
 *	2) doesn't give unusual message for 2-headed monsters (but
 *	allowing those at all causes more problems than worth the effort).
 */
A("Vorpal Blade",		LONG_SWORD,
	(SPFX_RESTR|SPFX_BEHEAD), 0, 0,
	PHYS(5,1),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Disrupter",                  MACE,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_UNDEAD,
	PHYS(5,15),     NO_DFNS,        NO_CARY,        0, A_NEUTRAL, PM_PRIEST, NON_PM, 500L ),

/*
 *	Mjollnir will return to the hand of a Valkyrie when thrown
 *	if the wielder is a Valkyrie with strength of 25 or more.
 */
A("Mjollnir",                   HEAVY_HAMMER,           /* Mjo:llnir */
	(SPFX_RESTR|SPFX_ATTK),  0, 0,
	ELEC(5,12),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, PM_VALKYRIE, NON_PM, 4000L ),

/* STEPHEN WHITE'S NEW CODE */
A("Gauntlets of Defense",    GAUNTLETS_OF_DEXTERITY,
	SPFX_RESTR, SPFX_HPHDAM, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,    INVIS, A_NEUTRAL, PM_MONK, NON_PM, 5000L ),

A("Mirrorbright",               SHIELD_OF_REFLECTION,
	(SPFX_RESTR|SPFX_HALRES|SPFX_REFLECT), 0, 0,
	NO_ATTK,      NO_DFNS,        NO_CARY,        0, A_NEUTRAL, PM_HEALER, NON_PM, 5000L ),

A("Deluder",               CLOAK_OF_DISPLACEMENT,
	(SPFX_RESTR|SPFX_STLTH|SPFX_LUCK), 0, 0,
	NO_ATTK,      NO_DFNS,        NO_CARY,        0, A_NEUTRAL, PM_WIZARD, NON_PM, 5000L ),

#ifdef TOURIST
A("Whisperfeet",               SPEED_BOOTS,
	(SPFX_RESTR|SPFX_STLTH|SPFX_LUCK), 0, 0,
	NO_ATTK,      NO_DFNS,        NO_CARY,        0, A_NEUTRAL, PM_TOURIST, NON_PM, 5000L ),
#else
A("Whisperfeet",               SPEED_BOOTS,
	(SPFX_RESTR|SPFX_STLTH|SPFX_LUCK), 0, 0,
	NO_ATTK,      NO_DFNS,        NO_CARY,        0, A_NEUTRAL, NON_PM, NON_PM, 5000L ),
#endif

/*** Chaotic artifacts ***/
A("Grimtooth",                  ORCISH_DAGGER,
	SPFX_RESTR, 0, 0,
	PHYS(2,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, PM_ORC, 300L ),

A("Deep Freeze",                ATHAME,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	COLD(5,3),      COLD(0,0),      NO_CARY,        0, A_CHAOTIC, PM_ICE_MAGE, NON_PM, 400L ),


A("Serpent's Tongue",            DAGGER,
	SPFX_RESTR, 0, 0,
        PHYS(2,0),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_NECROMANCER, NON_PM, 400L ),
	/* See artifact.c for special poison damage */

A("The Marauder's Map", SCR_MAGIC_MAPPING,
	(SPFX_RESTR), 0, 0, NO_ATTK,	NO_DFNS,	NO_CARY,
	OBJECT_DET,	A_CHAOTIC, PM_PIRATE, NON_PM, 2000L ),


A("Cleaver",                    BATTLE_AXE,
	SPFX_RESTR, 0, 0,
	PHYS(3,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, PM_BARBARIAN, NON_PM, 1500L ),

A("Doomblade",                  ORCISH_SHORT_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(0,5),     NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_HUMAN_WEREWOLF, NON_PM, 1000L ),

A("Sea Gull",				DAGGER,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(2,2), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Jungle Guard",				SURVIVAL_KNIFE,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_REGEN), 0, 0,
	ACID(1,5), DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Dark Moon Rising",			OBSIDIAN_AXE,
	(SPFX_RESTR|SPFX_WARN|SPFX_ATTK), 0, 0,
	PHYS(4,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Digging Dog",			DWARVISH_MATTOCK,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	PHYS(2,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1200L ),

A("World's Largest Cock",		VIBROBLADE,
	(SPFX_RESTR|SPFX_ESP|SPFX_ATTK|SPFX_DCLAS), 0, S_HUMAN,
	PHYS(20, 10), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2500L ),

A("Stormbringer's Little Brother",			BLACK_AESTIVALIS,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	DRLI(1,1), DRLI(0,0), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("Thorn Rose",			WHITE_FLOWER_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	FIRE(5,1), FIRE(0,0), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("Bluewrath",			CRYSTAL_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	COLD(5,1), COLD(0,0), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Kamehamehadoken",			SUGUHANOKEN,
	(SPFX_RESTR), 0, 0,
	PHYS(8,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Electrifier",			GREAT_HOUCHOU,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ELEC(5,1), ELEC(0,0), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

/* intentional misspelling --Amy */
A("Double Bestard",			BASTERD_SWORD,
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	PHYS(0,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Guardian of Aranoch",			BENT_SABLE,
	(SPFX_RESTR), 0, 0,
	PHYS(0,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Dullswandir",			IRON_SABER,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Goldswandir",		GOLDEN_SABER,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	PHYS(5,5),	NO_DFNS,	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Sounding Iron",			AKLYS,
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	PHYS(2,3), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Firmnail",			SPIKED_CLUB,
	(SPFX_RESTR|SPFX_DEFN|SPFX_ATTK|SPFX_LUCK), 0, 0,
	FIRE(1,4), FIRE(0,0), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1600L ),

A("Superclean Deseamer",			BROOM,
	(SPFX_RESTR|SPFX_STLTH|SPFX_PROTEC), 0, 0,
	PHYS(10,2), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 400L ),

A("Soothing Fan",			CARDBOARD_FAN,
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 600L ),

A("Generic Japanese Melee Weapon",			OTAMA,
	(SPFX_RESTR|SPFX_HPHDAM|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Thwack-Whacker",                  FLANGED_MACE,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_UNDEAD,
	PHYS(10,24),     NO_DFNS,        NO_CARY,        0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Evening Star",			MORNING_STAR,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_ESP), 0, S_LIGHT,
	PHYS(10,30), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Flogging Rhythm",			JAGGED_STAR,
	(SPFX_RESTR), 0, 0,
	PHYS(4,8), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Modified Pocket Calculator",			FLAIL,
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	PHYS(24,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 240L ),

A("Bitchwhipper",			KNOUT,
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_WARN), 0, M2_FEMALE,
	PHYS(5,12), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Orc Magic",			ORCISH_RING_MAIL,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Anti-Disenchanter",			DISENCHANTING_BOOTS,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Hot and Cold",			RIN_FIRE_RESISTANCE,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Glorious Dead",			CORPSE,
	(SPFX_RESTR|SPFX_REFLECT), (SPFX_DEFN|SPFX_REFLECT), 0,
	NO_ATTK, NO_DFNS, CARY(AD_MAGM), 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Precious Wish",			SCR_WISHING,
	(SPFX_RESTR), (SPFX_DEFN), 0,
	NO_ATTK, NO_DFNS, CARY(AD_MAGM), 0, A_NONE, NON_PM, NON_PM, 20000L ),

A("Trolled by the RNG",			ROCK,
	(SPFX_RESTR), 0, 0,
	PHYS(5,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1L ),

A("Starcraft Flail",			OBSID,
	(SPFX_RESTR|SPFX_HSPDAM), 0, 0,
	PHYS(1,0), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 6500L ),

A("Pwnhammer",			MALLET,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
	COLD(5,8), DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Pwnhammer Duece",			SLEDGE_HAMMER,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_REGEN), 0, 0,
	FIRE(8,12), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Dockside Walk",			WEDGED_LITTLE_GIRL_SANDAL,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Karate Kid",			SOFT_GIRL_SNEAKER, /* free action */
	(SPFX_RESTR), 0, 0,
	PHYS(5,8), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 10000L ),

A("Girlful Bonking",			STURDY_PLATEAU_BOOT_FOR_GIRLS, /* aggravate monster, diarrhea, claw attacks deal extra damage to you, -500 carry capacity */
	(SPFX_RESTR), 0, 0,
	PHYS(20,15), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20000L ),

A("Armor-Piercing Hug",			HUGGING_BOOT,
	(SPFX_RESTR|SPFX_DEFN|SPFX_PROTEC), 0, 0,
	PHYS(50,1), DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Asian Winter",			HUGGING_BOOT, /* aggravate monster */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	COLD(4,9), DFNS(AD_FIRE), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("French Maria",			BLOCK_HEELED_COMBAT_BOOT,
	(SPFX_RESTR|SPFX_DEFN|SPFX_WARN), 0, 0,
	PHYS(2,6), DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Force India",			WOODEN_GETA,
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	PHYS(20,0), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Stupidity In Motion",			LACQUERED_DANCING_SHOE,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DRLI|SPFX_REFLECT), 0, 0,
	DRLI(1,1), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 6000L ),

A("Sexy Nurse Sandal",			HIGH_HEELED_SANDAL,
	(SPFX_RESTR|SPFX_REGEN|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2500L ),

A("Tender Beauty",			SEXY_LEATHER_PUMP,
	(SPFX_RESTR), 0, 0,
	PHYS(5,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Massive But Lovely",			SEXY_LEATHER_PUMP,
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	PHYS(6,9), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Sweetheart Pump",			SEXY_LEATHER_PUMP, /* psi resistance */
	(SPFX_RESTR), 0, 0,
	PHYS(15,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Sandra's Evil Minddrill",			SPIKED_BATTLE_BOOT, /* aggravate monster, can cause amnesia when wielded */
	(SPFX_RESTR|SPFX_DEFN|SPFX_SEARCH), 0, 0,
	PHYS(0,16), DFNS(AD_ELEC), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Ribcracker",			QUARTERSTAFF,
	(SPFX_RESTR), 0, 0,
	PHYS(8,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Dull Metal",			IRON_BAR,
	(SPFX_RESTR), 0, 0,
	PHYS(1,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Gnarlwhack",			PLATINUM_FIRE_HOOK,
	(SPFX_RESTR|SPFX_DEFN|SPFX_ATTK|SPFX_HALRES|SPFX_SEARCH), 0, 0,
	FIRE(5,4), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Fire Leader",			PARTISAN,
	(SPFX_RESTR|SPFX_ATTK|SPFX_LUCK), 0, 0,
	FIRE(9,12), NO_DFNS, NO_CARY, UNTRAP, A_NEUTRAL, NON_PM, NON_PM, 11200L ),

A("Fumata Yari",			SPETUM, /* makes the player very fast when wielded */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ACID(2,8), DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3400L ),

A("Non-Sucker",			RANSEUR,
	(SPFX_RESTR), 0, 0,
	PHYS(6,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Dimoak's Hew",			BARDICHE, /* blindness resistance */
	(SPFX_RESTR), 0, 0,
	PHYS(0,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Land Knight Piercer",			VOULGE,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Apply B",			HALBERD,
	(SPFX_RESTR|SPFX_SPEAK|SPFX_ESP|SPFX_STLTH), 0, 0,
	PHYS(1,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7500L ),

A("Cock Application",			BILL_GUISARME,
	(SPFX_ATTK|SPFX_RESTR|SPFX_PROTEC), 0, 0,
	DRLI(3,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6500L ),

A("Not A Hammer",			LUCERN_HAMMER,
	(SPFX_RESTR|SPFX_ATTK|SPFX_REFLECT), 0, 0,
	COLD(4,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("It's A Polearm",			LUCERN_HAMMER,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ELEC(4,8), DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Bec De Ascorbin",			BEC_DE_CORBIN,
	(SPFX_RESTR), 0, 0,
	PHYS(1,2), NO_DFNS, NO_CARY, HEALING, A_LAWFUL, NON_PM, NON_PM, 3000L ),

A("Paleolithic Relic",			FLINT_SPEAR,
	(SPFX_RESTR), 0, 0,
	PHYS(2,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Bronze Age Relic",			BRONZE_SPEAR,
	(SPFX_RESTR), 0, 0,
	PHYS(2,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Misguided Missile",			SPIRIT_THROWER,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	PHYS(0,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Mare's Special Rocket",			TORPEDO,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_REFLECT), 0, 0,
	COLD(8,8), DFNS(AD_COLD), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 9000L ),

A("Lightning Blade",			TRIDENT,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	ELEC(2,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Fishing Grandpa",			STYGIAN_PIKE,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_WARN), 0, S_EEL,
	PHYS(20,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Static Stick",			MARE_TRIDENT,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ELEC(4,7), DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("The People-Eating Trident",			MANCATCHER, /* sight bonus */
	(SPFX_RESTR|SPFX_DCLAS|SPFX_WARN), 0, S_HUMAN,
	PHYS(8,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 9000L ),

A("Madeline's Guardian",			PARASOL, /* Pokemon Emerald */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Penguin's Thrusting Sword",		UMBRELLA, /* It sure looks like a sword to me! --Amy also, conveys flying */
	(SPFX_RESTR), 0, 0,
	PHYS(12,9), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 500L ),

A("Lackware",			ORCISH_BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(1,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 50L ),

A("Wild Hunt",			HYDRA_BOW,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_SEARCH|SPFX_PROTEC), 0, 0,
	FIRE(2,8), DFNS(AD_FIRE), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 20000L ),

A("Buffy Ammo",			SILVER_ARROW,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_DEMON,
	PHYS(10,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("Heavy Hitter Arrow",			YA,
	(SPFX_RESTR), 0, 0,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 100L ),

A("Agora",			CATAPULT,
	(SPFX_RESTR), 0, 0,
	PHYS(0,7), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Upgraded Lemure",			CATAPULT,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	PHYS(5,9), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Walther PPK",			PISTOL,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Desert Eagle",			PISTOL,
	(SPFX_RESTR), 0, 0,
	PHYS(5,9), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Ingram Mac-10",			SUBMACHINE_GUN, /* makes the player very fast when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("FN M249 Para",			HEAVY_MACHINE_GUN, /* aggravate monster */
	(SPFX_RESTR), 0, 0,
	PHYS(0,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Surefire Gun",			RIFLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Mosin-Nagant",			SNIPER_RIFLE,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	PHYS(20,15), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Leone M3 Guage Super",			SHOTGUN,
	(SPFX_RESTR), 0, 0,
	PHYS(0,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1600L ),

A("Citykiller Combat Shotgun",			AUTO_SHOTGUN,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	PHYS(0,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3600L ),

A("Smugglers End",			HAND_BLASTER,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	PHYS(10,1), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Colonel Bastard's Laser Pistol",			ARM_BLASTER,
	(SPFX_RESTR), 0, 0,
	PHYS(10,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Cookie Cutter",			CUTTING_LASER,
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Doomguy's Wet Dream",			BFG,
	(SPFX_RESTR), 0, 0,
	PHYS(2,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 9000L ),

A("Grand Daddy",			ROCKET_LAUNCHER,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(20,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Extra Firepower",			BULLET,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Demon Machine",			DEMON_CROSSBOW, /* infravision when wielded */
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(6,6), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),

A("ICBM",			HELO_CROSSBOW,
	(SPFX_RESTR), 0, 0,
	PHYS(20,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 9900L ),

A("Bearkiller",			CROSSBOW_BOLT,
	(SPFX_RESTR|SPFX_DFLAG1), 0, M1_THICK_HIDE,
	PHYS(5,25), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 50L ),

A("Puncture Missile",			DART,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_HUMAN,
	PHYS(8,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 50L ),

A("Instant Death",			DART_OF_DISINTEGRATION,
	(SPFX_RESTR), 0, 0,
	PHYS(0,50), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Needle-like the new log",			SHURIKEN,
	(SPFX_RESTR), 0, 0,
	PHYS(7,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 70L ),

A("Catwomanbane",			BATARANG,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_SPEAK), 0, S_FELINE,
	PHYS(10,40), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Doctor Jones' Aid",			BULLWHIP,
	(SPFX_RESTR|SPFX_WARN|SPFX_DCLAS), 0, S_SNAKE,
	PHYS(5,2), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Cruel Punisher",			STEEL_WHIP, /* grants aggravate monster */
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	PHYS(2,6), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Bristly String",			ROSE_WHIP, /* monsters take 1d4 damage if they melee you */
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(3,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Police Brutality",			RUBBER_HOSE,
	(SPFX_RESTR), 0, 0,
	PHYS(4,7), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Demonstrants Go Home",			RUBBER_HOSE,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_DEFN|SPFX_WARN), 0, S_HUMAN,
	PHYS(6,8), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("We Are Not Oppressive",			RUBBER_HOSE,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	PHYS(8,8), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("Death To Shoplifters",			RUBBER_HOSE,
	(SPFX_RESTR|SPFX_BEHEAD|SPFX_DCLAS), 0, S_HUMAN,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Legendary Shirt",			KYRT_SHIRT,
	(SPFX_RESTR|SPFX_REFLECT|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Sexy Convicts",			STRIPED_SHIRT,
	(SPFX_RESTR|SPFX_ESP|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Nobility Worldwide",			RUFFLED_SHIRT,
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Peace Advocate",			RUFFLED_SHIRT, /* free action while worn */
	(SPFX_RESTR|SPFX_WARN|SPFX_DCLAS), 0, S_HUMAN,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Gentle-Soft Clothing",			VICTORIAN_UNDERWEAR, /* poison and disintegration resistance while worn */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Helen's Discarded Shirt",			VICTORIAN_UNDERWEAR, /* aggravate monster while worn */
	(SPFX_RESTR|SPFX_TCTRL|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Antimagic Shell",			VICTORIAN_UNDERWEAR, /* prevents spellcasting */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Memorial Garments",			VICTORIAN_UNDERWEAR, /* versus curses and keen memory */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 6000L ),

A("Total Control",			VICTORIAN_UNDERWEAR, /* resist confusion and stun */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Victoria Is Evil But Pretty",			VICTORIAN_UNDERWEAR, /* polymorph control and manaleech */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Medical Power Armor Prototype",			FULL_PLATE_MAIL,
	(SPFX_RESTR|SPFX_SPEAK|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, HEALING, A_NONE, NON_PM, NON_PM, 2500L ),

A("As Heavy As It Is Ugly",			BRONZE_PLATE_MAIL,
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Volume Armament",			SPLINT_MAIL, /* superscrolling screen effect */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Fucking Orichalcum",			OLIHARCON_SPLINT_MAIL,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Stealth Suit",			ELVEN_MITHRIL_COAT,
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Little Big Midget",			GNOMISH_SUIT, /* grants free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Cathan's Network",			CHAIN_MAIL, /* increases STR by its enchantment value +3 */
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3400L ),

A("Fly Like An Eagle",			FEATHER_ARMOR, /* flying */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Pretty Little Magical Girl",			SCHOOL_UNIFORM, /* manaleech if worn by a female char */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Playboy With Ears",			BUNNY_UNIFORM, /* increases CHA by its enchantment value +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Antisepsis Coat",			NURSE_UNIFORM, /* sickness resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1600L ),

A("Falcet",			SCALE_MAIL,
	(SPFX_RESTR|SPFX_DEFN|SPFX_REGEN), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4400L ),

A("Superescape Mail",			RING_MAIL, /* autocurses when worn, disables fire resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Grayscale Wanderer",			LEATHER_ARMOR, /* shades of grey effect */
	(SPFX_RESTR|SPFX_DEFN|SPFX_WARN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("CD Rome Arena",			ELVEN_TOGA, /* slows the player down */
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Chastity Armor",			CONSORT_S_SUIT, /* prevents you from contracting STD */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Laura Croft's Battlewear",			LEATHER_JACKET, /* like d-type equipment, prevents lava from harming player */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Offense Owns Defense",			ROBE, /* double attacks */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Protection With A Price",			ROBE_OF_WEAKNESS, /* stun resistance and 5 extra points of AC */
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Cute Idea",			ORANGE_DRAGON_SCALE_MAIL,
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("All Hail The Mighty RNG",			PURPLE_DRAGON_SCALE_MAIL,
	(SPFX_RESTR|SPFX_LUCK|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 10000L ),

A("Ho-Oh's Feathers",			SKY_DRAGON_SCALE_MAIL, /* aggravate monster and conflict */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 20000L ),

A("Upgrade This",			MERCURIAL_DRAGON_SCALES,
	(SPFX_RESTR|SPFX_SEEK|SPFX_SPEAK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Don Suicune Does Not Approve",			PLATINUM_DRAGON_SCALES, /* aggravate monster and random nasty effects */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Pretty Puff",			SAPPHIRE_DRAGON_SCALES,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Invisible Visibilitity",			MUMMY_WRAPPING, /* the Amy is a troll and makes this thing grant invis :P */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Visible Invisibilitity",			MUMMY_WRAPPING, /* see invis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Blackcloak",			ORCISH_CLOAK,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Eveline's Lab Coat",			LAB_COAT,
	(SPFX_RESTR|SPFX_STLTH|SPFX_LUCK), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Ina's Lab Coat",			LAB_COAT, /* hunger, random fainting, and disintegration/sickness resistance; autocurses */
	(SPFX_RESTR|SPFX_SPEAK|SPFX_SEEK), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Superman's Super Suit",			SUPER_MANTLE, /* quad attacks */
	(SPFX_RESTR|SPFX_REGEN|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Full Wings",			WINGS_OF_ANGEL, /* flying */
	(SPFX_RESTR|SPFX_HALRES|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Broken Wings",			DUMMY_WINGS, /* disables the flying intrinsic, aggravates monsters, and causes intrinsic freezing; autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5L ),

A("Acquired Poison Resistance",			POISONOUS_CLOAK, /* poison resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("It's A Wonderful Failure",			CLOAK_OF_DEATH,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Rita's Deceptive Mantle",			CLOAK_OF_FUMBLING, /* autocurses and sets its enchantment to -10 when worn! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Stunted Helper",			MANACLOAK,
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Insufficient Protection",			CLOAK_OF_MATADOR,
	(SPFX_RESTR|SPFX_WARN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Memory Aid",			CLOAK_OF_UNSPELLING, /* keen memory */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Frequent But Weak Status",			HEAVY_STATUS_CLOAK, /* resist confusion and stun */
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("A Reason To Live",			YELLOW_SPELL_CLOAK, /* deactivates teleport control */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Full Moon Tonight",			VULNERABILITY_CLOAK,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 600L ),

A("All-In-One Ascension Kit",			CLOAK_OF_INVENTORYLESSNESS, /* also magic and drain resistance */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20000L ),

A("Radar Cloak",			CLOAK_OF_RESPAWNING,
	(SPFX_RESTR|SPFX_ESP|SPFX_WARN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Hostes Ad Pulverem Ferire",			SPAWN_CLOAK, /* increase STR/DEX by enchantment value +5 */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Uberjackal Effect",			ADOM_CLOAK, /* aggravate monster */
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Variatio Delectat",			EGOIST_CLOAK, /* does nothing special - just meant to annoy lawful players who hoped for a good sacrifice gift */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Speedrunner's Dream",			CLOAK_OF_TIME, /* makes the player very fast */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Can't Kill What You Can't See",			EERIE_CLOAK, /* see invis and makes you invisible */
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Image Projector",			CLOAK_OF_NAKEDNESS, /* displacement */
	(SPFX_RESTR|SPFX_TCTRL|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Silent Noise",			CLOAK_OF_AGGRAVATION,
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Dark Angels",			CLOAK_OF_CONFLICT, /* flying */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2500L ),

A("Skills Beat Stats",			CLOAK_OF_STAT_LOCK, /* faster skill training */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Baron Von Richthofen's Premiere",			WING_CLOAK,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 16000L ),

A("RNG's Gamble",			CLOAK_OF_PREMATURE_DEATH,
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Fightright",			GNOMISH_HELM,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 200L ),

A("Vitamin B",			HELM_OF_LOSE_IDENTIFICATION,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 600L ),

A("Spectral Resistance",			COLOR_CONE, /* resist fire, cold, elec, poison */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 7500L ),

A("Giant WOK",			DENTED_POT,
	(SPFX_RESTR|SPFX_PROTEC|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Playboy Supplement",			BUNNY_EAR, /* increases CHA by its enchantment value +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Real Speed Devil",			SPEEDWAGON_S_HAT, /* makes the player very fast and adds extra speed sometimes */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Royal Tiara",			CROWN,
	(SPFX_RESTR|SPFX_ESP|SPFX_TCTRL|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Functional Radio",			ANTENNA, /* works like radio helmet */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Warner Brother",			PLASTEEL_HELM,
	(SPFX_RESTR|SPFX_WARN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 250L ),

A("Dark Nadir",			HELMET, /* autocurses, creates darkness once every 100 turns, but improves your to-hit by 5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Loving Deity",			HELM_OF_OPPOSITE_ALIGNMENT,
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("COW Enchantment",			HELM_OF_DETECT_MONSTERS, /* 9 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 900L ),

A("Thor's Mythical Helmet",			HELM_OF_STORMS,
	(SPFX_RESTR|SPFX_HPHDAM|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 50000L ),

A("Clang Compilation",			HELM_OF_STEEL,
	(SPFX_RESTR|SPFX_PROTEC|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Surface-To-Air Site",			FLACK_HELMET, /* +1 multishot */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1200L ),

A("Massive Cranium",			CRYSTAL_HELM,
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Burger Eater",			HELM_OF_HUNGER,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Omniscient",			HELMET_OF_UNDEAD_WARNING,
	(SPFX_RESTR|SPFX_WARN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 600L ),

A("Spacewarp",			HELM_OF_TELEPORTATION,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Dictatorship",			HELM_OF_TELEPORT_CONTROL, /* also gives polymorph control */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Safe Insecurity",			HELM_OF_OBSCURED_DISPLAY,
	(SPFX_RESTR|SPFX_HPHDAM|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("You Are Already Dead",			BLACKY_HELMET, /* also magic and drain resistance */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 20000L ),

A("Shpx Guvf Fuvg",			CYPHER_HELM, /* also unbreathing */
	(SPFX_RESTR|SPFX_SEEK|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Go Other Place",			HELM_OF_BAD_ALIGNMENT, /* teleportitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Beeswax Helmet",			SOUNDPROOF_HELMET,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 300L ),

A("Low Local Memory",			OUT_OF_MEMORY_HELMET, /* free action and drain resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Severe Aggravation",			ANGER_HELM, /* aggravate monster */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Formfiller",			CAPTCHA_HELM, /* heavily curses itself when worn */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("Stone Erosion",			HELM_OF_AMNESIA, /* petrification resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Blinding Fog",			DIMMER_HELMET, /* blindness resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Big Bonnet",			WAR_HAT, /* poison resistance */
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3500L ),

A("Eulogy's Eulogy",			BOOGEYMAN_HELMET,
	(SPFX_RESTR|SPFX_PROTEC|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),

A("Mind Shielding",			TINFOIL_HELMET, /* stun resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1600L ),

A("Conspiracy Theory",			PARANOIA_HELMET,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2300L ),

A("Box Fist",			LEATHER_GLOVES, /* +5 unarmed damage */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Swing Less Cast More",			GAUNTLETS_OF_PANIC,
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Molass Tank",			GAUNTLETS_OF_SLOWING, /* 10 extra points of AC */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Science Fliction",			OILSKIN_GLOVES,
	(SPFX_RESTR|SPFX_REGEN|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("AFK Means Ass-Fucker",			GAUNTLETS_OF_TYPING, /* autocurses, monsters with AD_SEDU or similar attacks have +12 speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Signons Steel Total",			GAUNTLETS_OF_STEEL, /* resist poison, cold, stone */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Double Luck",			GAUNTLETS_OF_GOOD_FORTUNE,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Plug And Pray",			GAUNTLETS_OF_PLUGSUIT,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Gauntlets of Slaying",			GAUNTLETS, /* increase STR and DEX by enchantment +3 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Iris's Precious Metal",			SILVER_GAUNTLETS, /* demons are spawned peaceful 90% of the time while you wear these */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 9000L ),

A("Flictionless Combat",			GAUNTLETS_OF_NO_FLICTION, /* putting them on for the first time gives you the blessing technique but also permanent itemcursing! */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Come Back To Life",			MENU_NOSE_GLOVES, /* 50% chance of life saving while wearing them */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("ScrollScrollScroll",			CONFUSING_GLOVES, /* increased drop rate of standard id and similar scrolls */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Sealed Knowledge",			GAUNTLETS_OF_MISSING_INFORMATI,
	(SPFX_RESTR|SPFX_HPHDAM|SPFX_REFLECT|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Fifty Shades Of Fucked Up",			SADO_MASO_GLOVES, /* +5 damage unarmed, +10 damage while wielding a whip */
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Arabella's Bank of Crossroads",			BANKING_GLOVES, /* levelteleportitis, heavily curse themselves when worn */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Out Of Control",			CHAOS_GLOVES, /* give teleportitis and disable tele control */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Shadowdisk",			SMALL_SHIELD, /* blindness resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Lurtz's Wall",			URUK_HAI_SHIELD, /* 20% boost to block rate, free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("Aeaeaeaeaegis",			STEEL_SHIELD, /* 10 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Shattered Dreams",			CRYSTAL_SHIELD, /* autocurses, aggravates monsters and causes conflict */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 6000L ),

A("Burning Disk",			FLAME_SHIELD, /* causes burn, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("The Type Of Ice Block Hates You",			ICE_SHIELD, /* causes freezing, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Numbed Can't Do",			LIGHTNING_SHIELD, /* causes numbness, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Venomat",			VENOM_SHIELD, /* causes stun, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("They Must All Die",			ORCISH_GUARD_SHIELD,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Whang Clink Clonk",			SHIELD, /* 5 extra points of AC and +10% chance to block */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Reflector Ejector",			SILVER_SHIELD, /* teleportitis */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Little Thorn Rose",			MIRROR_SHIELD, /* d5 passive damage to attackers, negates sleep resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Teh Bash0r",			RAPIRAPI, /* adds a flat +2 damage to your weapon attacks */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Too Good To Be True",			SILVER_DRAGON_SCALE_SHIELD,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 8000L ),

A("Solar Power",			BLACK_DRAGON_SCALE_SHIELD, /* sight bonus */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 8000L ),

A("Brass Guard",			COPPER_DRAGON_SCALE_SHIELD, /* free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 8000L ),

A("Systematic Chaos",			PURPLE_DRAGON_SCALE_SHIELD, /* autocurses, grants conflict and sustain ability */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 12000L ),

A("Golden Dawn",			EMERALD_DRAGON_SCALE_SHIELD, /* autocurses, causes the "verisiert" effect and gives keen memory */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 12000L ),

A("Real Psychos Wear Purple",			PSYCHIC_DRAGON_SCALE_SHIELD, /* autocurses, grants psi resistance and the hate trap and farlook bug effects */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 12000L ),

A("Binder Crash",			PLASTEEL_BOOTS, /* 1 out of 20 games, putting them on transforms you into a Binder permanently. Otherwise, they heavily curse themselves and increase your deity's anger by three. No ill effect if you actually are a Binder, but for them they count as high heels. */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20000L ),

A("Mephisto's Brogues",			LOW_BOOTS, /* autocurses, resist cold/poison, flying, disables fire resistance */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Gnomish Boobs",			GNOMISH_BOOTS, /* +3 charisma */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 100L ),

A("Kokyo no pafomansuu-oku",			ATSUZOKO_BOOTS, /* increases charisma by +5 + enchantment */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Little Girl's Revenge",			RUBBER_BOOTS,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("AmyBSOD's Vampiric Sneakers",			SNEAKERS, /* cause blood loss */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Cinderella's Slippers",			CRYSTAL_BOOTS, /* aggravate monster and wounded legs, because your feet are bigger than the owner's :-P */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0, /* actually prism reflection */
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Eveline's Lovelies",			WEDGE_SANDALS, /* +5 kicking damage, +3 charisma */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Natalia's Punisher",			WEDGE_SANDALS, /* +8 damage with hammer-class weapons, petrification resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Ella's Bloodlust",			WEDGE_SANDALS, /* double attacks, autocurses, aggravate monster */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("Anastasia's Gentleness",			DANCING_SHOES, /* free action, reduces your STR by 10 */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Katrin's Paralysis",			DANCING_SHOES, /* kicking a monster causes it to be stuck to you, resist elec and cold */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Eva's Inconspicuous Charm",			SWEET_MOCASSINS, /* increase CHA and DEX by enchantment value */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Solvejg's Stinking Slippers",			SWEET_MOCASSINS, /* heavily curses itself, aggravates monsters, resist elec, manaleech, +5 CHA, -5 INT and WIS */
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 7500L ),

A("Jessica's Tenderness",			SWEET_MOCASSINS, /* resist cold, sleep and psi */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 8000L ),

A("Leather Pumps of Horror",			FEMININE_PUMPS, /* poison resistance, increase CHA by 5 + enchantment value */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Lilac Beauty",			FEMININE_PUMPS, /* +10 CHA, -5 to all other stats, taking them off drains an experience level (ignoring resistance) */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN|SPFX_STLTH), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Rhea's Combat Pumps",			FEMININE_PUMPS, /* resist poison/sickness, d10 passive damage to non-poison-resistant monsters with 2% chance of instakill */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 8000L ),

A("Mandy's Rough Beauty",			LEATHER_PEEP_TOES, /* +10 kick damage, free action, increase CHA by 5 + enchantment */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 11000L ),

A("I'm A Bitch, Deal With It",			HIPPIE_HEELS, /* aggravate monster, +5 AC, becomes +0 if the enchantment is negative */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Manuela's Torture Heels",			HIPPIE_HEELS, /* aggravate monster, conflict, heavily curse themselves when worn */
	(SPFX_RESTR|SPFX_DEFN|SPFX_ESP), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Beautiful Topmodel",			HIPPIE_HEELS, /* +25 CHA */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 16000L ),

A("Corina's Unfair Scratcher",			COMBAT_STILETTOS, /* flying, resist cold, shock and petrification */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 5000L ),

A("Sporked",			BOOTS_OF_MOLASSES,
	(SPFX_RESTR|SPFX_REGEN|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Hermes' Unfairness",			FLYING_BOOTS, /* aggravate monster, unbreathing, monsters are always spawned hostile */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Yet Another Stupid Idea",			ZIPPER_BOOTS, /* resist fire and petrification */
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Hot Flame",			FIRE_BOOTS,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Jesus Footwear",			BOOTS_OF_SWIMMING, /* prevents your inventory from getting wet */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7500L ),

A("Cursing Anomaly",			ANTI_CURSE_BOOTS, /* autocurses :-P, causes random itemcursing */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Fun All In One",			MULTI_SHOES, /* conflict, unbreathing, aggravate monster */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Lollerskates",			ROLLER_BLADE,
	(SPFX_RESTR|SPFX_DEFN|SPFX_TCTRL), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2400L ),

A("Desertwalk",			FREEZING_BOOTS,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Waiting Timeout",			AUTODESTRUCT_DE_VICE_BOOTS, /* free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Nose Enchantment",			SPEEDBUG_BOOTS, /* polymorphitis */
	(SPFX_RESTR|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Fantastic Shoes",			SENTIENT_HIGH_HEELED_SHOES,
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Untrained Half Marathon",			BOOTS_OF_FAINTING, /* wounded legs, very fast speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Black Diamond Icon",			DIFFICULT_BOOTS, /* multiply monster spawn rate by 4 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Riddle Me This",			GRIDBUG_CONDUCT_BOOTS, /* causes quizzes */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Base for Speed Ascension",			LIMITATION_BOOTS, /* sickness resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Paranoia Stride",			DEMENTIA_BOOTS, /* resist fear */
	(SPFX_RESTR|SPFX_HALRES|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Ding Dong Ping Pong",			RIN_DISARMING,
	(SPFX_RESTR|SPFX_REFLECT|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2500L ),

A("Ring of Woe",			RIN_DOOM, /* prime curses itself, aggravate monster, hunger and conflict */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("Werefoo Go Home",			RIN_PROTECTION_FROM_SHAPE_CHAN,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Secret Detective",			RIN_STEALTH,
	(SPFX_RESTR|SPFX_ESP|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7500L ),

A("Magic Signet",			RIN_SUSTAIN_ABILITY,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Eat More Kittens",			RIN_AGGRAVATE_MONSTER, /* autocurses */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("The Ring of the Schwartz",			RIN_TIMELY_BACKUP, /* disintegration resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Afterthought",			RIN_POISON_RESISTANCE,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Polar Opposites",			RIN_SHOCK_RESISTANCE,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Win Or Lose",			RIN_INTRINSIC_LOSS,
	(SPFX_RESTR|SPFX_ESP|SPFX_LUCK|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Crylock",			RIN_BLOOD_LOSS, /* heavily curses itself, improves AC by 10 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("GoldenIvy's Rage",			RIN_SUPERSCROLLING, /* aggravate monster, teleportitis, sickness resistance, flying */
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Team Nastytrap's Bauble",			RIN_ENSNARING,
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Float Eyeler's Condition",			RIN_DIARRHEA, /* levitation */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Skill-less of the service",			RIN_NO_SKILL,
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Fatally Low",			RIN_LOW_STATS,
	(SPFX_RESTR|SPFX_ESP|SPFX_SEEK|SPFX_LUCK|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Criminal Queen",			RIN_DANGER, /* +5 charisma, very fast speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 6000L ),

A("Life Sucks",			AMULET_OF_CHANGE, /* another trolling artifact, because it disintegrates when worn :-P */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Bestestor",			AMULET_OF_UNDEAD_WARNING,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Traitorious Devil",			AMULET_OF_OWN_RACE_WARNING,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3500L ),

A("Warned and Protected",			AMULET_OF_POISON_WARNING, /* poison resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Controlled Teleportitis",			AMULET_OF_COVETOUS_WARNING,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Guardian Angle",			AMULET_OF_LIFE_SAVING, /* prism reflection */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Snorefest",			AMULET_OF_RESTFUL_SLEEP, /* 90% sleep resistance :-P, also aggravates monsters */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Precious Unobtainable Properties",			AMULET_OF_STRANGULATION, /* warp reflection, resist psi/stun/petrification/sickness */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Ballsy Bastard",			AMULET_OF_PREMATURE_DEATH, /* free action, resist petrification, manaleech */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Fix Everything",			AMULET_OF_UNCHANGING, /* sustain ability */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Only One Escape",			AMULET_OF_ANTI_TELEPORTATION, /* jumping */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Oh Come On",			AMULET_OF_ACID_RESISTANCE, /* +5 charisma */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 300L ),

A("Amulet of Carlammas",			AMULET_OF_REGENERATION,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4500L ),

A("Computer Amulet",			AMULET_OF_DATA_STORAGE, /* keen memory */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Stinging Medallion",			AMULET_OF_DANGER, /* disintegration resistance, flying */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Recovered Relic",			AMULET_OF_MENTAL_STABILITY, /* stun res */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Tyranitar's Quest",			AMULET_OF_PRISM, /* techniques get no timeout 50% of the time */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Space Cycle",			AMULET_OF_WARP_DIMENSION, /* teleportitis and polymorphitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Necklace of Adornment",			NECKLACE, /* +10 charisma */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Good Bee",			AMULET_OF_RMB_LOSS, /* sight bonus, poison resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Where Did It Go",			AMULET_OF_ITEM_TELEPORTATION,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Confusticator",			AMULET_OF_DIRECTIONAL_SWAP, /* confusion */
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Eeh-Eeh",			AMULET_OF_SUDDEN_CURSE,
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("The 10th Nazgul",			AMULET_OF_ANTI_EXPERIENCE, /* heavily curses itself, disables drain resistance, gives free action and manaleech */
	(SPFX_RESTR|SPFX_REGEN|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("Very Tricky Indeed",			BAG_OF_TRICKS, /* spawns more monsters than usual */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("One Size Fits Everything",			ICE_BOX_OF_HOLDING, /* like Wallet of Perseus */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Stonesplitter",			PICK_AXE,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Darkening Thing",			UNICORN_HORN, /* applying it aggravates monsters */
	(SPFX_RESTR), 0, 0,
	PHYS(3,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Roommate's Special Idea",			LASER_SWATTER,
	(SPFX_RESTR|SPFX_BEHEAD), 0, S_XAN,
	PHYS(0,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Lights, Camera, Action",			EXPENSIVE_CAMERA, /* if applied while it has charges, it scares all nearby monsters */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20000L ),

A("Fairest In The Land",			MIRROR, /* supposed to pacify nymphs if you apply it at them */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("The Eyes of the Spying Academy",			LENSES,
	(SPFX_RESTR|SPFX_ESP|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Blindfold of Mispelling",			BLINDFOLD, /* confusion problem, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("The Answer Is 42",			TOWEL, /* applying it, or putting it on, causes a random bad effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Penis Safety",			CONDOME,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Knight's Aid",			SADDLE, /* artifact saddles exist just so that deities can sometimes unrestrict your riding skill */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Vroom Vroom",			SADDLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Motorcycle Race",			SADDLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Yasdorian's Trophy Getter",			TINNING_KIT, /* always generates blessed tins, but also summons a random monster! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Yasdorian's Junethack Identity",			TIN_OPENER, /* psi resistance */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Tin-Fu",			TIN_OPENER, /* +20 damage when used as a melee weapon */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, PM_SUPERMARKET_CASHIER, NON_PM, 0L ),

A("Vibe Lube",			CAN_OF_GREASE, /* instantly applies the full 3 layers of grease with a single charge */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Guaranteed Special Pet",			FIGURINE, /* whatever monster comes out of it will always be tame */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Pen of Randomness",			MAGIC_MARKER, /* randomly chooses BUC status of target scroll */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Egg of Splat",			EGG, /* eating it makes you deathly sick */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Hoe Pa",			FOOD_RATION, /* eating it gives temporary resistance to fire, cold, shock, poison, rnz(10000) turns for each */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Yasdorian's Partly Eaten Tin",			TIN, /* eating it gives intrinsic magic resistance and nastiness, disables poison and sickness resistance for 1 million turns */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Boomshine",			POT_BOOZE, /* does d50 damage and gives intrinsic confusion */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Cursed Parts",			POT_BANISHING_FEAR, /* gives intrinsic fear resistance and item cursing */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Planechangers",			POT_POLYMORPH, /* gives intrinsic polymorphitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Sandman Volume 8",			SPE_DRAIN_LIFE, /* all the artifact spellbooks should have +10 melee damage */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DRLI|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("And Your Mortal World Shall Perish In Flames",			SPE_CURE_BURN,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	FIRE(5,5), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Source Codes of Work Avoidance",			SPE_AMNESIA, /* free action and flying when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Eru Iluvatar's Bible",			SPE_ALTER_REALITY, /* poison resistance and 20% life saving when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Orthodox Manifest",			SPE_TURN_UNDEAD, /* the turn undead technique works even in Gehennom while you wield this */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("The Secrets of Invisible Pleasure",			SPE_MAKE_VISIBLE, /* invisibility and see invis when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Acta Metallurgica Vol. 3",			SPE_CORRODE_METAL, /* improves AC by 5 when wielded */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("IBM guild manual",			SCR_CONFUSE_MONSTER, /* intrinsic confusing problem when read */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Nothing Ventured Nothing Gained",			WAN_NOTHING, /* if you or a monster zap an artifact wand, it should not lose a charge 50% of the time; bashing with it should add the # of charges (if positive) to the damage output */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Know Your Intrinsics",			WAN_ENLIGHTENMENT, /* +5 INT/WIS when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Stealing Protection",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Rare Findings",			WAN_SECRET_DOOR_DETECTION,
	(SPFX_RESTR|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Snare Begone",			WAN_TRAP_DISARMING,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3500L ),

A("Fook Yoo",			WAN_GENOCIDE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Overleveler",			WAN_STRIKING,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Un-Death",			WAN_UNDEAD_TURNING,
	(SPFX_RESTR|SPFX_DEFN|SPFX_ATTK|SPFX_DRLI), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Not Known Anymore",			WAN_AMNESIA, /* after the amnesia incident, secure identifies exactly one item for you */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Uselessness of Plenty",			WAN_FEAR, /* fear resistance when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Arabella's Secret Weapon",			WAN_BANISHMENT, /* 90% chance of not losing a charge if a monster zaps it */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20000L ),

A("AWOL Party",			WAN_CREATE_HORDE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Funny Segfault",			WAN_VENOM_SCATTERING, /* does not actually cause segfaults */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Bunga Bunga",			WAN_SUMMON_SEXY_GIRL, /* +5 + number of charges charisma when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Sovetskaya Pyat' Lo Nenavidit Igroki",			WAN_DESLEXIFICATION,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Faeaeaeaeaeau",			WAN_FIRE,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Digger Gem",			EMERALD,
	(SPFX_RESTR), 0, 0,
	ACID(5,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Khor's Curse",			LUCKSTONE, /* autocurses and sets itself to -5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Strange Protector",			ACID_VENOM,
	(SPFX_RESTR), (SPFX_PROTEC), 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Roadrash Weapon",			IRON_CHAIN,
	(SPFX_RESTR), 0, 0,
	PHYS(0,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Vuvuzela",			TOOLED_HORN, /* aggravates monsters when applied (idea by yasdorian) */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

/* The following artifacts are from SLASHTHEM. Many of these had to be redesigned, since all of them can now be generated
 * randomly. And it takes one overpowered artifact to destroy game balance - as soon as players become aware of its
 * existence, everyone will wish for it as soon as possible. Also, none of these are associated with any role now. --Amy
 * Soviet's comments are preserved just for the sake of it; his "temp names" are of course permanent in this variant. */

A("Clarent",			SHORT_SWORD,
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL|SPFX_LUCK|SPFX_DFLAG1), 0, M1_THICK_HIDE,
	PHYS(8,1),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("Shadowblade",			KNIFE,
	(SPFX_RESTR|SPFX_STLTH),0,0,
	PHYS(5,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("Yoichi no yumi",                YUMI, /* 5lo: Artifact from dNethack */
	SPFX_RESTR, 0, 0,
	PHYS(20,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1200L ),

A("Kiku-ichimonji",                KATANA, /* 5lo: New sacrifice gift for Samurai */
	SPFX_RESTR, 0, 0,
	PHYS(4,6),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1200L ),

A("Itlachiayaque",             SHIELD_OF_REFLECTION,
	(SPFX_RESTR|SPFX_HSPDAM), 0, 0,
	NO_ATTK,        DFNS(AD_FIRE),        NO_CARY,  0,    A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Queen's Guard",		RAPIER,
	(SPFX_RESTR), 0, 0,
	PHYS(6,3),	NO_DFNS,	NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

A("Peacekeeper",		PISTOL,
	(SPFX_RESTR|SPFX_DALIGN), 0, 0,
	PHYS(4,4),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

A("Restkeeper",		CLUB,
	(SPFX_RESTR|SPFX_DALIGN), 0, 0,
	PHYS(4,4),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

A("Icebiter",			AXE,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	COLD(6,3),	COLD(0,0),	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

A("Shock Brand",                LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ELEC(5,0),	ELEC(0,0),	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Acid Brand",                 LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ACID(5,0),	ACID(0,0),	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 3000L ),

/* 5lo: Generic artifact since Psions are deferred for now */
A("Snakeskin",             ROBE,
    (SPFX_RESTR|SPFX_HALRES|SPFX_PROTEC), 0, 0,
    NO_ATTK,    ACID(0,0),   NO_CARY,    0, A_NEUTRAL, NON_PM, NON_PM, 700L ),

A("Poseidon's Treasure",	TRIDENT,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	ELEC(10, 5),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Gladius",		SHORT_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(8,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1500L ),

A("Hrunting",		LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(4,2),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Debugger",       ATHAME,
    (SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
    ELEC(5,2),  ELEC(0,0), NO_CARY,     0, A_NEUTRAL, NON_PM, NON_PM, 400L ),
    
A("Acidtester",       ATHAME, /* temp name */
    (SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
    ACID(5,2),  ACID(0,0), NO_CARY,     0, A_NEUTRAL, NON_PM, NON_PM, 400L ),

A("Straightshot",   BOW,
    SPFX_RESTR, 0, 0,
    PHYS(10,1),     NO_DFNS,    NO_CARY,    0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),
    
A("Shimmerstaff",   SILVER_KHAKKHARA,
    SPFX_RESTR, 0, 0,
    PHYS(8,2),     NO_DFNS,    NO_CARY,    0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Full Metal Jacket",   LEATHER_JACKET, /* Temp name */
    (SPFX_RESTR|SPFX_DEFN|SPFX_PROTEC|SPFX_HALRES), 0, 0,
    NO_ATTK,    FIRE(0,0),    NO_CARY,   0, A_NEUTRAL, NON_PM, NON_PM, 1500L ), 
    
A("Tesla's Coat", LAB_COAT,
    (SPFX_RESTR|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
    NO_ATTK,    ELEC(0,0),  NO_CARY,    0,  A_NEUTRAL, NON_PM, NON_PM, 3000L ),

A("Oathkeeper", 		STILETTO, /* temp name? */
    (SPFX_RESTR), 0, 0,
    PHYS(7,4),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1500L ),

A("Blackshroud",		CLOAK_OF_PROTECTION,
    (SPFX_RESTR|SPFX_LUCK|SPFX_WARN),	0,	0,
    NO_ATTK,	DRLI(0,0),	NO_CARY,	0,	A_NEUTRAL,	NON_PM,	NON_PM, 1500L ),

A("Silvershard", SILVER_DAGGER,
    (SPFX_RESTR), 0, 0,
    PHYS(2,0),	NO_DFNS,	NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Mirror Brand",                 SILVER_LONG_SWORD, /* dNethack */
	(SPFX_RESTR|SPFX_ATTK|SPFX_REFLECT|SPFX_DALIGN), 0, 0,
	STUN(5,0),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 3500L ),

/* From Nethack--, This is pretty much a temp for Musicians
 * Until I can think of something better for them.	
 * Amy edit: that comment is from Soviet the Type Of Ice Block of course :D */
A("Dirk", 		DAGGER, 
	SPFX_RESTR, 	0, 	0,
	PHYS(5,2),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1500L ),

A("Tenderizer",                   MALLET,           
	(SPFX_RESTR|SPFX_ATTK),  0, 0,
	PHYS(3,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

/* 5lo: Some more artifacts... */
A("Fungisword", LONG_SWORD,
    (SPFX_RESTR|SPFX_DCLAS|SPFX_HALRES), 0, S_FUNGUS,
    PHYS(10,0), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 400L ),
    
A("Diplomat", GOLDEN_SABER,
    (SPFX_RESTR|SPFX_DFLAG2), 0, M2_PNAME,
    PHYS(10,12), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),
    
A("Petslayer", CLUB,
    (SPFX_RESTR|SPFX_DFLAG2), 0, M2_DOMESTIC,
    PHYS(5,5), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Mouser's Scalpel",			RAPIER,
	(SPFX_RESTR), 0, 0,
	PHYS(5,1),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 600L ),
    
A("Graywand",		TWO_HANDED_SWORD,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	COLD(3,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),
    
A("Heartseeker",		SHORT_SWORD,
	(SPFX_RESTR),	0, 0,
	PHYS(3,1),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Cat's Claw",		DAGGER,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_RODENT,
	PHYS(5,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Nightingale",                KATANA,
	SPFX_RESTR, 0, 0,
	PHYS(6,1),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),
	/* 5lo: Sacrifice gift for Ninja */

A("Bloodmarker",		KNIFE,
	(SPFX_RESTR), 0, 0,
	PHYS(3,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Shawshank",			KNIFE,
	(SPFX_RESTR), 0, 0,
	PHYS(9,4),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 1500L ),

A("Spineseeker",	STILETTO,
	SPFX_RESTR, 0, 0,
	PHYS(5,2),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 1500L ),

A("Crown Royal Cloak",	LEATHER_CLOAK,
	(SPFX_RESTR|SPFX_PROTEC|SPFX_LUCK), 0, 0,
	NO_ATTK,	ACID(0,0),	NO_CARY,
	0,	A_NEUTRAL,	 NON_PM, NON_PM, 1000L),

A("The Gambler's Suit",		COMMANDER_SUIT,
	(SPFX_RESTR|SPFX_PROTEC|SPFX_LUCK), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 1000L ),

A("The Wand of Might",		WAN_WISHING,
	(SPFX_RESTR), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_NONE, NON_PM, NON_PM, 3000L ),

A("Warforger",  HEAVY_HAMMER,   /* giant blacksmithing hammer */
	(SPFX_RESTR|SPFX_ATTK),  0, 0,
	PHYS(15,7),	FIRE(0,0),	NO_CARY, /* phys so fire resistance doesn't negate */
    0, A_NEUTRAL, NON_PM, NON_PM, 5000L ),

A("The Sling of David",                SLING,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_HPHDAM), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("The Golden Whistle of Nora",          MAGIC_WHISTLE, /* 5lo: temp name? Amy edit: you come up with a really good name ONCE and then decide that it's temporary? Seriously??? */
	(SPFX_RESTR|SPFX_INTEL|SPFX_WARN|SPFX_HPHDAM|SPFX_ESP), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,         A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Fuma-itto no Ken",                BROADSWORD,    /* 5lo: New quest artifact for Ninja - Credit to Chris as this comes from dNethack with minor changes */
	(SPFX_RESTR|SPFX_DALIGN), 0, 0,
	PHYS(8,4),      DFNS(AD_DRLI),     NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 5000L ),

A("The Pick of the Grave",		PICK_AXE, /* Amy addition: aggravates monsters and causes hunger when wielded */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DRLI|SPFX_DEFN|SPFX_REGEN|SPFX_HPHDAM|SPFX_TCTRL), 0, 0,
	DRLI(8,5),	COLD(0,0),   NO_CARY,
	0,		A_NEUTRAL, NON_PM, NON_PM, 3000L ),

A("The Flute of Slime",          MAGIC_FLUTE, /* 5lo: temp name */
	(SPFX_RESTR|SPFX_INTEL|SPFX_WARN|SPFX_TCTRL), 0, 0,
	NO_ATTK,        DFNS(AD_ELEC),        NO_CARY,
	0,         A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("The Fire Chief Helmet",                FIRE_HELMET, /* Amy edit: weak sight when worn */
	(SPFX_RESTR|SPFX_INTEL|SPFX_WARN|SPFX_PROTEC|SPFX_HSPDAM|SPFX_HPHDAM), 0, 0,
	NO_ATTK,      NO_DFNS,        NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("The Deluxe Yendorian Knife", KNIFE,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_ESP), 0, 0,
	PHYS(6,10),  	FIRE(0,0), 	NO_CARY,
	0,  A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("The Harp of Lightning",          MAGIC_HARP, 
 	(SPFX_RESTR|SPFX_INTEL|SPFX_WARN|SPFX_TCTRL), 0, 0,
 	NO_ATTK,        DFNS(AD_ACID),        NO_CARY,
	0,         A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("The Harp of Harmony",          MAGIC_HARP,
	(SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK|SPFX_WARN|SPFX_STLTH), 0, 0,
	NO_ATTK,	DFNS(AD_DRLI),	NO_CARY,
	0,		A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("The Cudgel of Cuthbert", QUARTERSTAFF, /* 5lo: from Nethack-- 3.1.3 */
	/* Amy edit: trap of walls and +10 difficulty effect when wielded */
	(SPFX_RESTR|SPFX_INTEL|SPFX_HALRES|SPFX_REGEN|SPFX_DALIGN|SPFX_WARN|SPFX_HSPDAM), 0, 0,
	PHYS(5,0),	DFNS(AD_DRLI),	NO_CARY,
	0,		A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("The Sword of Svyatogor", TWO_HANDED_SWORD, /* way to completely ignore the warrior's elder scrolls origin, Soviet! --Amy */
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
	PHYS(7,4),	COLD(0,0),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("The Tommy Gun of Capone", SUBMACHINE_GUN,
	(SPFX_RESTR|SPFX_DEFN|SPFX_LUCK|SPFX_INTEL|SPFX_WARN|SPFX_STLTH), 0, 0,
	PHYS(5,3),        DFNS(AD_FIRE),  NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),

A("The Whistle of the Warden", MAGIC_WHISTLE,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ESP|SPFX_TCTRL), 0, 0,
	NO_ATTK,        DFNS(AD_DRLI),  NO_CARY,
	0, 	A_LAWFUL, NON_PM, NON_PM, 3000L ),

A("The Hand Mirror of Cthylla",	MIRROR, /* 5lo: replaces Pen of the Void */
	(SPFX_RESTR|SPFX_INTEL|SPFX_TCTRL|SPFX_SEARCH), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_NONE, NON_PM, NON_PM, 5000L),

A("The Scalpel of the Bloodletter",	SCALPEL, /* bleedout when wielded */
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DRLI|SPFX_HPHDAM|SPFX_REGEN), 0, 0,
	DRLI(9,5),	NO_DFNS,	NO_CARY,
	0,	A_NEUTRAL, NON_PM, NON_PM, 2500L),

A("The Gourd of Infinity", HORN_OF_PLENTY,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ESP|SPFX_HSPDAM|SPFX_HALRES), 0, 0,
	NO_ATTK,    DFNS(AD_DRLI),    NO_CARY,
	0, A_NEUTRAL,  NON_PM,   NON_PM, 2500L),

A("The Lockpick of Arsene Lupin", LOCK_PICK,
	(SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK|SPFX_LUCK|SPFX_SEEK|SPFX_ESP|SPFX_STLTH|SPFX_WARN), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,		A_NEUTRAL, NON_PM, NON_PM, 3500L ),

A("The Staff of Withering",	QUARTERSTAFF,
	(SPFX_RESTR|SPFX_ATTK|SPFX_INTEL|SPFX_DRLI|SPFX_DALIGN), 0, 0,
	DRLI(3,2),	DFNS(AD_COLD),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 5000L ),

/* The following artifacts are from dnethack. Like the SLASHTHEM ones, they had to be redesigned to fit into this variant.
 * IMHO dnethack's balance is completely out of whack, so I tried my best to make them all balanced. --Amy
 * Chris's comments are preserved just for the sake of it. */

A("The Bow of Skadi",	BOW,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	COLD(1,12),	DFNS(AD_COLD),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 4000L), /*Read to learn Cone of Cold (Skadi's Galdr) */

A("The Crown of the Saint King",	HELMET, /*Actually gold circlet*/
	(SPFX_RESTR|SPFX_INTEL), 0, 0, /* Amy: +5 AC and no other effect */
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 4000L), /*Also causes pets to always follow you when worn*/

A("The Helm of the Dark Lord",	HELMET, /*Actually visored helmet*/
	(SPFX_RESTR|SPFX_INTEL), 0, 0, /* Amy: +5 AC and no other effect */
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), /*Also causes pets to always follow you when worn*/

A("Sunbeam",	GOLDEN_ARROW,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN), 0, 0,
	PHYS(10,0),	DFNS(AD_DRLI),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 1000L),

A("Moonbeam",	SILVER_ARROW,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN), 0, 0,
	PHYS(10,0),	DFNS(AD_DRLI),	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 1000L),

A("Veil of Latona",	CLOAK_OF_INVISIBILITY, /* drain res, superscroller, black ng walls and permanent confusion, heavily autocurses when worn */
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_REFLECT), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY, /* yes this is an example of an artifact that's uber imba in dnethack */
	0, A_NEUTRAL, NON_PM, NON_PM, 1000L),

A("Carnwennan",			DAGGER, /*needs quote*/
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_STLTH|SPFX_WARN), 0, M2_MAGIC,
	PHYS(5,5),	NO_DFNS,		NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 4000L), 

A("The Slave to Armok",			DWARVISH_MATTOCK, /*two handed, so no twoweaponing.*/
	(SPFX_RESTR|SPFX_DFLAG2), 0, (M2_ELF|M2_LORD|M2_PEACEFUL|M2_ORC), /*DF Dwarves can be a nasty lot.*/
	PHYS(5,0),	NO_DFNS,	NO_CARY, /* supposed to be bloodthirsty */
	0, A_LAWFUL, NON_PM, NON_PM, 2500L), 

A("Dragonlance",			LANCE,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_REFLECT|SPFX_WARN), 0, S_DRAGON, /* also makes a handy weapon for knights, since it can't break */
	PHYS(10,10),	NO_DFNS,	NO_CARY,				/* plus, reflection */
	0, A_NONE, NON_PM, NON_PM, 5000L), 

A("Kingslayer",		STILETTO,
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_WARN), 0, (M2_LORD|M2_PRINCE), /* works against just about all the late game badies */
	PHYS(10,10),	NO_DFNS,	NO_CARY,	
	0, A_CHAOTIC, NON_PM, NON_PM, 2500L), 

A("Peace Keeper",		ATHAME, 
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_WARN), 0, (M2_HOSTILE), /* speaks for itself */
	PHYS(5,5),	NO_DFNS,	NO_CARY,	/*Weaker attack and damage */
	0, A_LAWFUL, NON_PM, NON_PM, 2500L), 

A("Rhongomyniad",			LANCE, /*needs quote*/
	(SPFX_RESTR), 0, 0,
	PHYS(3,0),	NO_DFNS,		NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 4000L), 

A("Gilded Sword of Y'ha-Talla",			SCIMITAR,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	STUN(5,0),	DFNS(AD_DRST),	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 3000L), 

A("The Axe of the Dwarvish Lords", BATTLE_AXE, /*can be thrown by dwarves*/
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,	/*x-ray vision is for dwarves only.*/
	PHYS(1, 0),	NO_DFNS,	NO_CARY, /* Amy edit: vision bonus instead of x-ray */
	0, A_LAWFUL, NON_PM, NON_PM, 4000L), //needs quote

A("Windrider",	BOOMERANG, /*returns to your hand.*/
	SPFX_RESTR, 0,0,
	PHYS(1,0),	NO_DFNS,	NO_CARY,//needs quote
	0,	A_NONE, NON_PM, NON_PM, 4000L), 

A("The Rod of the Ram",			MACE, /* Wolf, Ram, and Hart? Ram demon? */
	(SPFX_RESTR), 0, 0,
	PHYS(1,0),	NO_DFNS,	NO_CARY, //needs quote	
	0, A_NEUTRAL, NON_PM, NON_PM, 3000L), 

A("Atma Weapon", 		RED_LIGHTSABER, /*Sword whose attack power is bound to its wielder's life force*/
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_NASTY,
	PHYS(6,3),	NO_DFNS,	NO_CARY, //needs quote
	0, A_NONE, NON_PM, NON_PM, 6660L), 

A("Limited Moon", 		MOON_AXE, /*Axe whose attack power is bound to its wielder's magical energy*/
	(SPFX_RESTR), 0, 0,
	PHYS(1,0),	NO_DFNS,	NO_CARY, //needs quote
	0, A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("The Black Arrow",		ANCIENT_ARROW,
	(SPFX_RESTR), 0, 0,
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 4444L),

A("Tensa Zangetsu",		TSURUGI,
	(SPFX_RESTR|SPFX_HSPDAM), 0, 0, /*also has a haste effect when wielded, but massively increases hunger and damages the wielder*/
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 4444L),/*The invoked attack is very powerful*/

A("Sode no Shirayuki",		KATANA,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	COLD(1,0),	COLD(0,0),	NO_CARY,  /*Sort of intermediate between a double damage and a utility weapon,*/
	0, A_LAWFUL, NON_PM, NON_PM, 8000L),/*Sode no Shirayuki gains x2 ice damage after using the third dance.*/
	/*however, it only keeps it for a few rounds, and the other dances are attack magic. */

A("Tobiume",		LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(1,1),	FIRE(0,0),	NO_CARY,/*Tobiume is an awkward weapon.  It loses 3 damage vs large and 2 vs small*/
	0, A_CHAOTIC, NON_PM, NON_PM, 8000L),
	/*Ram and Fire blast only trigger if enemy is low hp*/

A("The Lance of Longinus",			SILVER_SPEAR, /* stun, confusion, hallu and freezing when wielded because seriously, Chris... --Amy */
	(SPFX_RESTR|SPFX_HSPDAM|SPFX_HPHDAM|SPFX_DEFN|SPFX_REFLECT), 0, 0, //needs quote
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 1500L), 

A("The Harkenstone", DIAMOND, /* aggravate monster when wielded */
    SPFX_RESTR, 0, 0,
    PHYS(5,0), NO_DFNS, NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 8000L), 

A("Release from Care",			SCYTHE,
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL|SPFX_BEHEAD),0,0,
	PHYS(1,5),	DRLI(0,0),	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 4000L), 

A("The Silence Glaive",		GLAIVE, //needs quote
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_DRLI), 0, 0,
	DRLI(1,1),	DRLI(0,0),	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 8000L), 

A("The Garnet Rod",		STAR_ROD, //needs quote
	(SPFX_RESTR|SPFX_EREGEN|SPFX_REGEN), 0, 0, /*also has a haste effect when wielded, but massively increases hunger*/
	NO_ATTK,	NO_ATTK,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 8000L), 

A("Helping Hand",			GRAPPLING_HOOK, //needs quote
	(SPFX_RESTR|SPFX_SEEK|SPFX_SEARCH|SPFX_WARN|SPFX_STLTH),0,0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 2000L), 

A("The Blade Singer's Spear",		SILVER_SPEAR,//needs quote
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	PHYS(6,3),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 1500L), 

A("The Blade Dancer's Dagger",		SILVER_DAGGER,//needs quote
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	PHYS(4,2),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 1500L), 

A("The Limb of the Black Tree",			CLUB,//needs quote
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	FIRE(4,1),	DFNS(AD_FIRE),	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 3000L), 

A("The Lash of the Cold Waste",		BULLWHIP,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	COLD(4,1),	DFNS(AD_COLD),	NO_CARY,	
	0, A_CHAOTIC, NON_PM, NON_PM, 3000L), 

A("Ramiel",			PARTISAN,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	ELEC(4,1),	DFNS(AD_ELEC),	NO_CARY,	/*Ramiel's ranged attack is far more useful than the lash and the limb*/
	0, A_LAWFUL, NON_PM, NON_PM, 3000L), /*So it's your job to use it right!*/

A("Spinesearcher",	SHORT_SWORD,
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	PHYS(1,3),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 1200L),

A("Quicksilver",	FLAIL,
	SPFX_RESTR, 0, 0,
	PHYS(4,4),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 1200L),

A("Sky Render",		KATANA, /* displacement when wielded */
	SPFX_RESTR, 0, 0,
	PHYS(10,5),	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 1200L),

A("Fluorite Octahedron", FLUORITE, /*Needs encyc entry*/
	(SPFX_RESTR), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 4000L), 

A("The Tie-Dye Shirt of Shambhala",	T_SHIRT, //needs quote
	(SPFX_RESTR|SPFX_INTEL), 0, 0, /* Amy edit: sets itself to +10 when worn, but has create traps effect */
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 4500L), 

A("The Grandmaster's Robe",	ROBE, /*double robe effect*/
	(SPFX_RESTR), 0, 0,/*martial arts attacks use exploding dice and get extra damage*/
	NO_ATTK,	NO_DFNS,	NO_CARY, /* Amy edit: +5 AC, +10 marital arts damage */
	0, A_NEUTRAL, NON_PM, NON_PM, 4500L), 

A("The Platinum Dragon Plate",	SILVER_DRAGON_SCALE_MAIL,/*heavier than normal, and causes spell penalties*/
	(SPFX_RESTR|SPFX_INTEL), 0, 0, //needs quote
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 9000L), 

A("Beastmaster's Duster", LEATHER_JACKET, //needs quote
	(SPFX_RESTR), 0, 0, /* Amy edit: M1_ANIMAL are spawned peaceful 90% and tame 1% */
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 9000L), 

A("The Shield of the All-Seeing", ORCISH_SHIELD, //needs quote
	(SPFX_RESTR|SPFX_SEEK|SPFX_SEARCH|SPFX_WARN), 0, M2_ELF,
     NO_ATTK, DFNS(AD_FIRE), NO_CARY,
	 0, A_NONE, NON_PM, NON_PM, 3000L),//needs message

A("The Shield of Yggdrasil", ELVEN_SHIELD, //needs quote
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
     NO_ATTK, DFNS(AD_DRST), NO_CARY,
	 0, A_NONE, NON_PM, NON_PM, 3000L),

A("Water Flowers", WATER_WALKING_BOOTS, /* displacement */
	(SPFX_RESTR), 0, 0, //needs quote
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), //needs message

A("Hammerfeet", KICKING_BOOTS,
	(SPFX_RESTR), 0, 0, //needs quote
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("The Shield of the Resolute Heart",		GAUNTLETS_OF_DEXTERITY,
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 4000L), 

A("The Gauntlets of Spell Power",		GAUNTLETS_OF_POWER, /*Note: it is quite deliberate that these cause */
	(SPFX_RESTR|SPFX_HSPDAM), 0, 0,						/*		a spellcasting penalty. */
	NO_ATTK,	NO_DFNS,	NO_CARY, //needs quote
	0, A_NONE, NON_PM, NON_PM, 4000L), /* supposed to make spellcasting easier though... --Amy */

A("Premium Heart",		GAUNTLETS_OF_POWER,
	(SPFX_RESTR), 0, 0,
	PHYS(1,0),	NO_DFNS,	NO_CARY, //needs quote
	0, A_NONE, NON_PM, NON_PM, 4000L), 
	
A("Stormhelm",		HELM_OF_BRILLIANCE, /* elec resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK,	COLD(0,0),	NO_CARY, //needs quote
	0, A_CHAOTIC, NON_PM, NON_PM, 3000L), 

A("Hellrider's Saddle",			SADDLE,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 4000L), 

A("The Rod of Seven Parts",	SILVER_SPEAR, /*From D&D*/
	(SPFX_ATTK|SPFX_RESTR|SPFX_INTEL|SPFX_DALIGN|SPFX_DEFN), 0,0,
	PHYS(7,10),	DRLI(0,0),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 7777L), 

A("The Field Marshal's Baton",	MACE,
	(SPFX_RESTR|SPFX_WARN), 0, M2_MERC,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 5000L), 

A("Werebuster",			LONG_SWORD, //needs quote
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_WERE,/*should not be gifted or gened randomly*/
	PHYS(10,10),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 1500L), /*does not protect agains lycathropy*/

A("Masamune",			TSURUGI, //needs quote
	(SPFX_RESTR|SPFX_INTEL), 0, 0,/*should not be gifted or gened randomly*/
	NO_ATTK,	NO_DFNS,	NO_CARY, /* Amy edit: trap revealing effect */
	0, A_NONE, NON_PM, NON_PM, 7500L),

A("The Black Crystal", CRYSTAL_BALL, /*from Final Fantasy*/
        (SPFX_RESTR|SPFX_DEFN|SPFX_DALIGN|SPFX_WARN), 0, 0,
        PHYS(3,0), DFNS(AD_MAGM), NO_CARY, 
		0, A_CHAOTIC, NON_PM, NON_PM, 100L), 
	/*The crystals are generated together.  The Black Crystal counts, and the others don't.*/

A("The Water Crystal", CRYSTAL_BALL,
        (SPFX_RESTR|SPFX_DEFN), 0, 0,
        NO_ATTK, DFNS(AD_COLD), NO_CARY, 
		0, A_NONE, NON_PM, NON_PM, 100L), 

A("The Fire Crystal", CRYSTAL_BALL,
        (SPFX_RESTR|SPFX_DEFN), 0, 0,
        NO_ATTK, DFNS(AD_FIRE), NO_CARY, 
		0, A_NONE, NON_PM, NON_PM, 100L), 

A("The Earth Crystal", CRYSTAL_BALL,
        (SPFX_RESTR|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
        NO_ATTK, NO_DFNS, NO_CARY, 
		0, A_NONE, NON_PM, NON_PM, 100L), 

A("The Air Crystal", CRYSTAL_BALL,
        (SPFX_RESTR|SPFX_DEFN), 0, 0,
        NO_ATTK, DFNS(AD_ELEC), NO_CARY, 
		0, A_NONE, NON_PM, NON_PM, 100L), 

A("The Annulus", SILVER_CHAKRAM,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_HSPDAM), 0, 0,
     PHYS(5,1), DFNS(AD_MAGM), NO_CARY, /*Actually Phys(5,0) if not a lightsaber*/
	 0, A_CHAOTIC, NON_PM, NON_PM, 3000L), 

A("The Iron Ball of Levitation", HEAVY_IRON_BALL, /* levitation when wielded */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DALIGN|SPFX_LUCK|SPFX_INTEL|SPFX_STLTH|SPFX_WARN), 0, 0,
	PHYS(5,5),	DFNS(AD_DRLI),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 5000L),
	/*Note: it had caried stealth before*/

A("The Iron Spoon of Liberation", SPOON,
	(SPFX_RESTR|SPFX_LUCK|SPFX_INTEL|SPFX_STLTH|SPFX_SEARCH|SPFX_SEEK), 0, 0,
	PHYS(5,0),	DFNS(AD_MAGM),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 5000L),
	/*Note: it had caried stealth before*/

A("Silver Starlight",		RAPIER,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(4,2),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 5000L), /*Creates throwing stars. Makes throwing stars count as silver if wielded */
	/*Also can be (a)pplied as a magic flute.								  */

A("Wrathful Spider",		DROVEN_CROSSBOW,
	(SPFX_RESTR|SPFX_INTEL|SPFX_STLTH), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 5000L),

A("The Tentacle Rod",		FLAIL,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(7,1),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 5000L),

A("The Crescent Blade",		SILVER_SABER,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_BEHEAD|SPFX_REFLECT), 0, 0,
	FIRE(4,0),	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 5000L),

A("The Darkweaver's Cloak",	DROVEN_CLOAK,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY, 
	0,	A_NONE,	 NON_PM, NON_PM, 5000L),

A("Spidersilk",	ELVEN_MITHRIL_COAT, /* spellcasting chance bonus */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY, 
	0,	A_CHAOTIC,	 NON_PM, NON_PM, 5000L),
	/*Adds sleep poison to unarmed attacks*/

A("Webweaver's Crook",	FAUCHARD,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(1,0),	DFNS(AD_MAGM),	NO_CARY, 
	0,	A_LAWFUL,	 NON_PM, NON_PM, 5000L),
	/*Adds poison to all attacks*/

A("Lolth's Fang",		DROVEN_SHORT_SWORD, /* Hedrow crowning gift, chaotic or neutral */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_INTEL), 0, 0,
	ACID(10,5),	DRLI(0,0),	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 8000L), 

A("The Web of Lolth",	ELVEN_MITHRIL_COAT, /* Drow crowning gift, chaotic */
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_INTEL|SPFX_WARN), 0, M2_ELF, /* spellcasting chance bonus */
	NO_ATTK,	DRLI(0,0),	NO_CARY, /* magic resistance and half speed when worn */
	0,	A_CHAOTIC, NON_PM, NON_PM, 2000L), 

A("The Claws of the Revenancer",		GAUNTLETS_OF_DEXTERITY, /* Drow crowning gift, neutral */
	(SPFX_RESTR|SPFX_ATTK|SPFX_EREGEN|SPFX_DRLI|SPFX_DEFN|SPFX_INTEL), 0, 0, /* causes fainting when worn */
	DRLI(1,1),	DRLI(0,0),	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 8000L), 

A("Liecleaver",		DROVEN_CROSSBOW, /* Drow noble crowning gift, lawful */
	(SPFX_RESTR|SPFX_SEEK|SPFX_DEFN|SPFX_INTEL|SPFX_SEARCH|SPFX_HALRES), 0, 0,
	PHYS(5,5),	DRLI(0,0),	NO_CARY,	
	0, A_LAWFUL, NON_PM, NON_PM, 8000L), 

A("The Ruinous Descent of Stars",		MORNING_STAR, /* Herow noble crowning gift, Chaotic */
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL),0,0,
	PHYS(1,0),	DFNS(AD_MAGM),	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 8000L), 

A("Sickle Moon",	SICKLE, /*returns to your hand.*/
	SPFX_RESTR, 0,0,
	PHYS(1,0),	NO_DFNS,	NO_CARY,//needs quote
	0,	A_NONE, NON_PM, NON_PM, 4000L), 

A("Arcor Kerym",		LONG_SWORD, /* Lawful Elf crowning gift */
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0,
	PHYS(5,0),	DRLI(0,0),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 8000L), 

A("Aryfaern Kerym",		RUNESWORD, /* Neutral Elf crowning gift */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_INTEL), 0, 0, /* spellcasting chance bonus */
	ELEC(5,5),	ELEC(0,0),	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 8000L), 

A("Aryvelahr Kerym",		CRYSTAL_SWORD, /* Chaotic Elf crowning gift */
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL|SPFX_REFLECT), 0, 0,
	PHYS(5,0),	DRLI(0,0),	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 8000L), 

A("The Armor of Khazad-dum",	DWARVISH_MITHRIL_COAT, /*Moria dwarf noble first gift */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	0,	A_LAWFUL,	 NON_PM, NON_PM, 2500L),

A("The War-mask of Durin",	OUT_OF_MEMORY_HELMET, /*Moria dwarf noble */
	(SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM), 0, 0, /*+5 attk and damage with axes*/
	NO_ATTK,	NO_DFNS,	NO_CARY, /* Gives Fire, Acid, and Poison resistance */
	0,	A_LAWFUL,	 NON_PM, NON_PM, 2500L),

A("Durin's Axe",			AXE, /*Moria dwarf noble crowning */
	(SPFX_RESTR|SPFX_SEEK|SPFX_DEFN|SPFX_INTEL|SPFX_SEARCH),0,0,
	PHYS(10,5),	DRLI(0,0),	NO_CARY,	
	0, A_LAWFUL, NON_PM, NON_PM, 4000L), 

A("Glamdring",			ELVEN_BROADSWORD, /*Lonely Mountain dwarf noble first gift */
	(SPFX_WARN|SPFX_RESTR), 0, (M2_ORC|M2_DEMON), /* the old elves fought balrogs too. */
	PHYS(10,5),	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 2000L), 

A("The Armor of Erebor",	PLATE_MAIL, /*Lonely Mountain dwarf noble */
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,  /*+10 AC*/
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY, /*Also gives Fire and Cold*/
	0,	A_LAWFUL,	 NON_PM, NON_PM, 2500L), /* but disables flying and causes chaos terrain --Amy */
	/* and disables reflection 25% of the time */

A("The Sceptre of Lolth", SILVER_KHAKKHARA, /* Drow noble first gift (hedrow get lordly might) */
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0, /*needs quote*/
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("The Web of the Chosen",	DROVEN_CLOAK, /* Drow noble quest */
	(SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM|SPFX_REFLECT), 0, 0, /* elec res */
	NO_ATTK,	ACID(0,0),	NO_CARY, /* Plus double AC bonus */
	0,	A_CHAOTIC,	 NON_PM, NON_PM, 2500L), /* slows you down like being a spirit */

A("The Cloak of the Consort",	DROVEN_CLOAK, /* Hedrow noble quest */
	(SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM), 0, 0, /* cold res */
	NO_ATTK,	DRLI(0,0),	NO_CARY, /* Plus double AC bonus */
	0,	A_NEUTRAL,	 NON_PM, NON_PM, 2500L), /* display loss unless turn counter is divisible by 10 */

A("The Rogue Gear-spirits", CROSSBOW,
	(SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK|SPFX_SEARCH|SPFX_SEEK|SPFX_WARN|SPFX_ESP), 0, 0,
	PHYS(5,0),	DFNS(AD_FIRE), NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 4000L), 

A("The Moonbow of Sehanine", ELVEN_BOW,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), 
	/*silver is the moon's metal... but bows don't enter this code...*/

A("The Spellsword of Corellon", HIGH_ELVEN_WARSWORD, /*Needs encyc entry*/
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(1,5),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("The Warhammer of Vandria", WAR_HAMMER,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("The Shield of Saint Cuthbert", SHIELD_OF_REFLECTION,
	(SPFX_RESTR|SPFX_HSPDAM|SPFX_HPHDAM), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 4000L), 

A("Belthronding", ELVEN_BOW, /* displacement when wielded */
	(SPFX_RESTR|SPFX_INTEL|SPFX_STLTH), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("The Rod of the Elvish Lords", ELVEN_MACE, /* Elf noble first gift */
	(SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0, /*needs quote*/
	PHYS(3,0),	NO_DFNS,	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("Sol Valtiva",			TWO_HANDED_SWORD,		/* The Sun of the Gods of the Dead */
	(SPFX_RESTR|SPFX_ATTK),  0, 0,
	FIRE(5,12),	DFNS(AD_FIRE),	NO_CARY,	
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L), 

A("The Staff of the Archmagi",			QUARTERSTAFF, /* resist cold, elec, fire */
	(SPFX_RESTR|SPFX_ATTK|SPFX_SEARCH|SPFX_LUCK|SPFX_INTEL), 0, 0,
	STUN(20,2),	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 9000L), 

A("The Robe of the Archmagi",			ROBE, /* displacement, blood mana, stun */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_INTEL), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,	
	0, A_NONE, NON_PM, NON_PM, 9000L), 

A("The Hat of the Archmagi",			CORNUTHAUM, /* sight bonus */
	(SPFX_RESTR|SPFX_SPEAK|SPFX_WARN|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,	
	0, A_NONE, NON_PM, NON_PM, 9000L), 

A("The Kusanagi no Tsurugi",	LONG_SWORD, /* aggravate monster, recurring disenchantment and itemcursing when wielded */
	(SPFX_RESTR|SPFX_INTEL|SPFX_EREGEN|SPFX_BEHEAD|SPFX_LUCK|SPFX_SEARCH|SPFX_SEEK), 0, 0,
	PHYS(20,6),	NO_DFNS,	NO_CARY,
	0,		A_LAWFUL, NON_PM, NON_PM, 4500L), 

A("Genocide", TWO_HANDED_SWORD, /* bloodthirsty */
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	FIRE(10,10),	DFNS(AD_FIRE),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The Rod of Dis", MACE,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(10,4),	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("Avarice", SHORT_SWORD,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(10,1),	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("Fire of Heaven", TRIDENT, /* resist elec */
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	FIRE(1,0),	DFNS(AD_FIRE),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The Diadem of Amnesia", DUNCE_CAP, /* guess what the effect of this thing is :-P --Amy */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), /*was DRAIN_MEMORIES*/ 

A("Thunder's Voice", SILVER_DAGGER,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	ELEC(6,3),	DFNS(AD_ELEC),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 3333L), 

A("Serpent's Tooth", ATHAME, /* poison res when wielded */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 3333L), 

A("Unblemished Soul", UNICORN_HORN,
	(SPFX_RESTR|SPFX_INTEL|SPFX_LUCK), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 3333L), 

A("Wrath of Heaven", LONG_SWORD, /* resist fire */
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	ELEC(1,0),	DFNS(AD_ELEC),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The All-seeing Eye of the Fly", HELM_OF_TELEPATHY, /* undead warning */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), /* Was SLAY_LIVING */

A("Cold Soul", RANSEUR, /* resist cold, elec, fire */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The Sceptre of the Frozen Floor of Hell", IRON_BAR,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	COLD(1,0),	DFNS(AD_COLD),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("Caress", BULLWHIP,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DFLAG2), 0, (M2_ELF|M2_HUMAN|M2_DWARF),
	ELEC(1,10),	ELEC(0,0),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The Iconoclast", SILVER_SABER,  /*Weapon of Lixer, Prince of Hell, from Dicefreaks the Gates of Hell*/
	(SPFX_RESTR|SPFX_INTEL|SPFX_DFLAG2), 0, (M2_HUMAN|M2_ELF|M2_DWARF),
	PHYS(9,9),	DFNS(AD_MAGM),	NO_CARY, /*also does +9 damage to S_ANGELs*/
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The Three-Headed Flail", FLAIL, /* speed when wielded */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("Heartcleaver", HALBERD,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("Wrathful Wind", CLUB,
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	COLD(10,0),	DFNS(AD_COLD),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("The Sting of the Poison Queen", FLAIL,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN), 0, 0,
	PHYS(4,6),	DFNS(AD_MAGM),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("The Scourge of Lolth", BULLWHIP,
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("Doomscreamer", TWO_HANDED_SWORD,  /*Weapon of Graz'zt, from Gord the Rogue*/
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DEFN), 0, 0,
	ACID(1,0),	ACID(0,0),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 6660L), 

A("The Wand of Orcus", WAN_DEATH, /* bloodthirsty */
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DRLI), 0, 0,
	DRLI(5,6),	NO_DFNS,	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 8000L), 

A("The Sword of Erathaol",			LONG_SWORD,		/*  */
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,	/**/
	0, A_LAWFUL, NON_PM, NON_PM, 7500L), 	/**/

A("The Saber of Sabaoth",			SILVER_SABER,		/*  */
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,	/**/
	0, A_LAWFUL, NON_PM, NON_PM, 7500L), 	/**/

A("The Sword of Onoel",			TWO_HANDED_SWORD,		/*  */
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,	/**/
	0, A_LAWFUL, NON_PM, NON_PM, 7500L), 	/**/

A("The Glaive of Shamsiel",			GLAIVE,		/*  */
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,	/**/
	0, A_LAWFUL, NON_PM, NON_PM, 7500L), 	/**/

A("The Lance of Uriel",			LANCE,		/*  */
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,	/**/
	0, A_LAWFUL, NON_PM, NON_PM, 7500L), 	/**/

A("The Hammer of Barquiel",			LUCERN_HAMMER,		/* Yes, I know it's bladed ;-) */
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,	/**/
	0, A_LAWFUL, NON_PM, NON_PM, 7500L), 	/**/

A("Silver Sniver",				MERCURIAL_ATHAME, /* Yes I know "sniver" is not a word. --Amy */
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_WARN), 0, M2_DEMON,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Jesus Must Die",				WOODEN_STAKE,
	(SPFX_RESTR), 0, 0,
	PHYS(4,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("The Randomisator",				GREAT_DAGGER, /* bad effects while wielded */
	(SPFX_RESTR), 0, 0,
	STUN(4,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Mini People Eater",				WORM_TOOTH,
	(SPFX_RESTR|SPFX_DFLAG1|SPFX_WARN), 0, M1_HUMANOID,
	PHYS(10,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Tigator's Thorn",				TOOTH_OF_AN_ALGOLIAN_SUNTIGER, /* displays all M3_POKEMON while wielded */
	(SPFX_RESTR|SPFX_DFLAG1), 0, M1_ANIMAL,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Gimli's War Axe",				DWARVISH_BATTLE_AXE,
	(SPFX_RESTR), 0, 0,
	PHYS(5,5), DFNS(AD_FIRE), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 3000L ),

A("Rattle Battle",				DWARVISH_SHORT_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(2,2), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Sleepless Nights",				DARK_ELVEN_SHORT_SWORD, /* sleep resistance while wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Schringeling",				DROVEN_GREATSWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(8,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Memetal",				METAL_CLUB, /* deafness while wielded */
	(SPFX_RESTR), 0, 0,
	PHYS(6,8), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Cubic Bone",				BONE_CLUB, /* drain res while wielded */
	(SPFX_RESTR), 0, 0,
	PHYS(4,2), DFNS(AD_COLD), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Broomchamber Endurance",				MOP,
	(SPFX_RESTR|SPFX_REGEN|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2500L ),

A("Pinselflinseling",				MAGICAL_PAINTBRUSH, /* all engravings (even ones in the dust) never misengrave while you wield it */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	PHYS(7,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Teamantbane",				FUTON_SWATTER,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_ANT,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Laser Paladin",				REINFORCED_MACE, /* while having it equipped, all ranged attacks done by you have +1 multishot */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Armorwreaker",				BRONZE_MORNING_STAR, /* aggravate monster, disables stealth while equipped */
	(SPFX_RESTR), 0, 0,
	PHYS(0,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Destruction Ball",				SPINED_BALL, /* every time you hit with it, there's a 33% chance that its enchantment goes down by 1 unless it's already -20 or worse */
	(SPFX_RESTR), 0, 0,
	PHYS(0,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Yesterday Asterisk",				DEVIL_STAR, /* will time you 1 in 5000 turns */
	(SPFX_RESTR), 0, 0,
	PHYS(5,7), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Melee Duality",				CHAIN_AND_SICKLE, /* double attacks */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Smaaaaaaaaaaaash",				TWO_HANDED_FLAIL,
	(SPFX_RESTR), 0, 0,
	PHYS(10,3), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Strombringer",				RUNED_ROD, /* bloodthirsty */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_INTEL|SPFX_DRLI), 0, 0,
	DRLI(5,1),	DRLI(0,0),	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Blazerunner",				FIRE_HOOK,
	(SPFX_RESTR), 0, 0,
	FIRE(8,4), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Civil War",				PITCHFORK, /* conflict while wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Heavy Thunderstorm",				BLACK_HALBERD, /* bloodthirsty */
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_DRLI), 0, 0,
	DRLI(5,1), DRLI(0,0), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 5000L ),

A("Rightlash Left",				GUISARME, /* every time you successfully apply it at a monster, it has 1 in 100 chance to gain enchantment unless it's already at +15 or higher */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Alassea Telemnar",				ELVEN_SICKLE, /* heavily curses itself, bloodthirsty, 1 in 20000 chance per turn that it disintegrates, all glyphs are fleecy-colored */
	(SPFX_RESTR|SPFX_DRLI), 0, 0,
	DRLI(5,0), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Gilraen Seregon",				ELVEN_SPEAR, /* petrification resistance */
	(SPFX_RESTR), 0, 0,
	PHYS(5,5), DFNS(AD_FIRE), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2500L ),

A("Vampirebane",				LONG_STAKE,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_WARN), 0, S_VAMPIRE,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Golembane",				BAMBOO_SPEAR,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_WARN), 0, S_GOLEM,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Pointless Javelin",				JAVELIN,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Eelbane",				TWO_HANDED_TRIDENT,
	(SPFX_RESTR|SPFX_DCLAS|SPFX_WARN), 0, S_EEL,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Move In The Shadows",				COURSE_LANCE, /* invisibility */
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("Anachrononononaut Package",				FORCE_PIKE, /* unbreathing if you're an anachronist */
	(SPFX_RESTR), 0, 0,
	ELEC(8,4), DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1400L ),

A("Glasspoint",				DROVEN_LANCE,
	(SPFX_RESTR), 0, 0,
	PHYS(8,2), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1200L ),

A("Eamane Luinwe",				ELVEN_LANCE, /* confusion and speed while wielded */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	FIRE(10,6), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Gun Control Laws",				FLINTLOCK, /* ancient Morgothian curse, autocurses when wielded */
	(SPFX_RESTR), 0, 0,
	PHYS(5,20), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10L ),

A("Overheater",				RAYGUN, /* autocurses, 1 in 1000 chance per turn to spawn a fire trap underneath the player */
	(SPFX_RESTR), 0, 0,
	FIRE(5,8), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Maximum Launch Power",				GRENADE_LAUNCHER, /* +rnd(2) multishot */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Kill Them All",				ANTIMATTER_BULLET,
	(SPFX_RESTR), 0, 0,
	PHYS(20,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Pschiiiiiiiii",				HEAVY_BLASTER_BOLT,
	(SPFX_RESTR), 0, 0,
	PHYS(5,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 150L ),

A("Electrocution",				LASER_BEAM,
	(SPFX_RESTR), 0, 0,
	ELEC(10,30), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Power Pellet",				SHOTGUN_SHELL,
	(SPFX_RESTR), 0, 0,
	PHYS(1,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 400L ),

A("Fire In The Hole",				FRAG_GRENADE,
	(SPFX_RESTR), 0, 0,
	FIRE(5,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Powered Arbalest",				PILE_BUNKER,
	(SPFX_RESTR), 0, 0,
	PHYS(2,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Demon Breakpoint",				KOKKEN,
	(SPFX_RESTR), 0, 0,
	PHYS(0,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 300L ),

A("Little Annoyance",				SPIKE,
	(SPFX_RESTR), 0, 0,
	PHYS(6,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 40L ),

A("Ouchie Ouch",				NEEDLE,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 75L ),

A("Lag Spike",				CALTROP,
	(SPFX_RESTR), 0, 0,
	PHYS(10,3), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Punishment For You",				CHAINWHIP, /* +3 damage per flail skill */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Shocklash",				MITHRIL_WHIP,
	(SPFX_RESTR), 0, 0,
	ELEC(8,6), DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Everything Must Burn",				FLAME_WHIP, /* 1 in 100 chance to be burned for d10 turns, allows player to survive in lava */
	(SPFX_RESTR), 0, 0,
	FIRE(2,8), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Female Beauty",				BLACK_DRESS, /* +5 CHA if you're female, -5 to all stats otherwise */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Bienvenido a Miami",				PRINTED_SHIRT, /* resist fire and cold, +3 CHA */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 0L ),

A("Thermal Bath",				BATH_TOWEL, /* swimming, sickness resistance, stuff does not get wet, turn limitation effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Giant Swinging Penis",				MEN_S_UNDERWEAR, /* +10 AC if you're male, otherwise nakedness effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Maedhros Saralonde",				DARK_ELVEN_MITHRIL_COAT, /* 5 extra points of AC, +2 melee damage, prayer timeout can be 250 turns higher and you can still pray */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Water Shyness",				SAFEGUARD_SUIT, /* heavily curses itself, disables flying and swimming, 1 in 100 chance to spawn a pool underneath you per turn (doesn't autotrigger) */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Precious Virginity",				MAID_DRESS, /* prevents AD_SSEX if you're female */
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Very Invisible",				SPECIAL_CAMOUFLAGED_CLOTHES, /* invis, displacement */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Check Your Escapes",				SHOULDER_RINGS, /* anti-teleportation, sickness resistance, free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Woodstock",				BAMBOO_MAIL, /* +5% chance to block if you have a shield; arrows (and only arrows, not e.g. bolts) have 50% extra chance of not breaking */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Nopped Suit",				STUDDED_LEATHER_ARMOR, /* 3 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Luke's Jedi Power",				FORCE_ARMOR, /* "use the force" effect, jumping */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("Gregor's Gangster Garments",				GENTLEMAN_S_SUIT, /* improves "borrow" command */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, OBJ_DETECTION, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Soft Girl",				GENTLEWOMAN_S_DRESS, /* makes you female if you aren't, 5 extra points of AC */
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Shrink's Aid",				STRAITJACKET, /* autocurses (DUH), +7 AC */
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Lea's School Uniform",				DWARVISH_CLOAK, /* heavily autocurses (and does nothing else) because Lea is devious :P */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Larien Telrunya",				ELVEN_CLOAK, /* "Amy Bluescreen" translated to Elvish by www.chriswetherell.com/elf/index.php */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Fireburn Coldshatter",				PLASTEEL_CLOAK, /* resist fire and cold, 5 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("No More Explosions",				ALCHEMY_SMOCK, /* alchemy will not result in explosions, unless you do stupid things with acid potions; making potions also works more often */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Premium Viscosity",				RUBBER_APRON, /* works like an oilskin cloak, also poison res */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Cooking Course",				KITCHEN_APRON, /* stepping on a fire will delete it with 50% chance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2500L ),

A("Rokko Chan's suit",				FRILLED_APRON, /* jumping, speed, your ranged attacks have +5 to-hit, but you cannot score critical hits and your STR/DEX cap out at 12 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Fully Lionized",				LEO_NEMAEUS_HIDE, /* speed, hunger */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Cold like a Corpse",				AYANAMI_WRAPPING,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Yaui Gaui Furs",				FUR, /* 5 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Deathclaw Hide",				HIDE, /* +10 to-hit with all melee attacks */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Fast Camo Predator",				DISPLACER_BEAST_HIDE, /* speed and hunger */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Predatory Stability",				THE_NEMEAN_LION_HIDE, /* free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 5000L ),

A("Spacewaste",				FILLER_CLOAK, /* 3 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Bugnose",				CLOAK_OF_SPRAY, /* displays all 'a' and 'x' */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Disbelieving Powerlord",				ANTI_CASTER_CLOAK, /* +d5 melee damage */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Double Negation",				CLOAK_OF_LUCK_NEGATION,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Donald Trump's Presidential Coat",				CHATBOX_CLOAK,
	(SPFX_RESTR|SPFX_WARN|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 6000L ),

A("Godless Void",				HERETIC_CLOAK, /* blocks telepathy */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Number 8192",				MISSING_CLOAK, /* doesn't do anything special */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Jana's Extreme Hide-and-Seek",				NASTY_CLOAK, /* you can conceal underneath items, but uncovering a concealing monster has 1 in 100 chance to instakill you (no joke). */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("The Last Steeling",				SPECIAL_CLOAK, /* allows you to rustproof an iron object with 1 in 5000 chance per turn */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Nothing Really Special",				PLAIN_CLOAK,
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Primitive Shielding",				ARCHAIC_CLOAK,
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Tari Fefalas",				ELVEN_LEATHER_HELM, /* poison res, monsters attacking you take poison damage, radio broadcasts, glib effect times out in one turn */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("Steelskull Protector",				ORCISH_HELM, /* 3 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Elessar Elendil",				HIGH_ELVEN_HELM, /* speed and fumbling */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Sexyness Has A Name",				NURSE_CAP, /* doubles healup effects, or quadruples if you're a healer */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Squeaky Tenderness",				KATYUSHA, /* farting monsters are 25% generated tame */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("It Breathes More",				DRAGON_HORNED_HEADPIECE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, DRAGON_BREATH, A_NONE, NON_PM, NON_PM, 4000L ),

A("Coneshape Hat",				STRAW_HAT,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Hard Hat Area",				MECHA_IRAZU, /* 5 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Dunce Pounce",				SCHOOL_CAP, /* caps your INT and WIS at 6, but gives +5 STR, +3 DEX */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Remote Gamble",				CHAIN_COIF, /* +2 increase damage and accuracy */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Hot-Headed Hat",				SEDGE_HAT,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Green Status",				SKULLCAP, /* poison resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Alluration",				HELM_OF_DRAIN_RESISTANCE, /* gradually curses itself while worn (1 in 1000 chance per turn), and may give intrinsic nastiness if it does */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("The Wolf King",				HELM_OF_DISCOVERY, /* no digestion, weak sight, right mouse button loss, blocks telepathy, heavily autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Wschiiiiie!",				HELM_OF_THIRST, /* clairvoyance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Never Clean",				ANTI_DRINKER_HELMET, /* confusion */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Web Radio",				WHISPERING_HELMET, /* internet access */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2400L ),

A("Dullifier",				HELM_OF_SENSORY_DEPRIVATION, /* invisibility, disables sleep resistance */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("SOON THERE WILL BE AN ERROR",				BIGSCRIPT_HELM, /* every turn there is 1 in 5000 chance to give you intrinsic nastiness */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7500L ),

A("Double Jeopardy",				QUIZ_HELM, /* teleportitis and polymorphitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("If The Right Mouse Button Fails Now",				DIZZY_HELMET, /* 1 in 2000 chance per turn to summon a Gunnhild's General Store */
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("The Iron Helm of Gorlim",				MUTING_HELM, /* topi ylinen curse, +10 to-hit and to-damage */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Nevereater",				ULCH_HELMET, /* slow digestion */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Certain Slow Death",				HELM_OF_STARVATION, /* conflict */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Drink Coca Cola",				QUAFFER_HELMET, /* hunger */
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Have All You Need",				INCORRECTLY_ADJUSTED_HELMET, /* resist fire, cold, shock, sleep */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Nosed Bug",				RANDOMIZED_HELMET, /* 7 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("The Massive Iron Crown of Morgoth",				UNWANTED_HELMET, /* prime curses itself, carries ancient morgothian curse, +5 all stats, resist fire/cold/shock/poison/acid */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Randomness Prevails",				WONDER_HELMET, /* teleportitis and polymorphitis, disables tele and poly control */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Casquespire Translate",				POINTED_HELMET, /* 5 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Gold Standard",				BOG_STANDARD_HELMET, /* random gold drops have higher amounts of zorkmids in them */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Helmet of Digging",				MINING_HELM, /* supposed to increase digging speed with e.g. pick-axe */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Army Leader",				FIELD_HELM, /* soldier types are 5% tame */
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Secure Bathmaster",				HELM_OF_SAFEGUARD, /* resist fire, cold and light */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("Deep Insanity",				HELM_OF_UNDERWATER_ACTION, /* inventorylessness, autocurses when worn */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2500L ),

A("Radar Not Working",				HELM_OF_JAMMING, /* monsters never approach, but no detection methods work either and newly spawned ones are completely invisible */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Bettervision",				HELM_OF_TRUE_SIGHT,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Refuel Badly",				HELM_OF_NO_DIGESTION, /* manaleech */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Burn Or No",				PLASTEEL_GLOVES, /* player acquires intrinsic burnopathy from putting them on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Free Action Called Free Action",				ORIHALCYON_GAUNTLETS, /* free action (DUH) */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Fumblefingers Quest",				GAUNTLETS_OF_FUMBLING, /* sitting on a throne always gives the fumblefingers effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Oh Look At That",				COMMANDER_GLOVES, /* unlocks petkeeping skill and caps it at expert but also prime curses itself if you didn't have the skill before */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Line In The Sand",				FIELD_GLOVES, /* trap revealing */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Handboxed",				UNWIELDY_GLOVES, /* +1000 carry capacity */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Yes to Ranged Combat",				UNDROPPABLE_GLOVES, /* +d6 damage when throwing */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Spectrator",				GAUNTLETS_OF_TRAP_CREATION, /* 20% chance of resist fire, cold, shock, poison, acid, stone, drain and magic */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Use The Force Luke",				GAUNTLETS_OF_THE_FORCE, /* +10 damage for the force command */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, LEVITATION, A_NONE, NON_PM, NON_PM, 200L ),

A("Expertengame the entire level",				DIFFICULT_GLOVES, /* flying, monsters often create a trap upon spawning */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("What's Up Bitches",				GAUNTLETS_OF_STEALING, /* displays all 'n', and they're generated peaceful 90% and tame 2% */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Balls Flying Back And Forth",				GAUNTLETS_OF_MISFIRING,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("What Do",				UNKNOWN_GAUNTLETS,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 5000L ),

A("Grabber Master",				EVIL_GLOVES, /* while worn, you have 1 in 1000 chance per turn to detect gold (cannot be exploited to detect traps) */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Defensive Magic",				ARCANE_GAUNTLETS,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Non-Something",				PLACEHOLDER_GLOVES,
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Doubler Gloves",				PROTECTIVE_GLOVES,
	(SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 250L ),

A("Dwarven Bong",				DWARVISH_ROUNDSHIELD, /* no special effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Absurd-Heeled Tileset",				HIGH_BOOTS, /* count as high heels */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Grandpa's Brogues",				LEATHER_SHOES, /* fear resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 800L ),

A("Vera's Freezer",				SOFT_SNEAKERS, /* give a freezopathy-like effect when worn, kicking a monster will slow it down unless it resists, player's potions cannot shatter from cold attacks, being frozen slows the player less than usual, but fire resistance is deactivated and burn effects will always become "heavy burn" */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2500L ),

A("High Heeled Hug",				BOOTS_OF_ACID_RESISTANCE, /* count as high heels */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 8000L ),

A("Free For Enough",				FUMBLE_BOOTS, /* free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Double Safety",				BOOTS_OF_TOTAL_STABILITY,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Lovely Girls Wear Plateau Soles",				STOMPING_BOOTS,
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Fatality",				BOOTS_OF_WEAKNESS, /* conflict */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Porcelain Elephant",				STAIRWELL_STOMPING_BOOTS, /* aggravate monster, triggers wakeup 1 in 100 turns, +5 AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 250L ),

A("FD Deth",				PET_STOMPING_PLATFORM_BOOTS, /* displays all 'f' and 'd' monsters */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Lovely Girl Plateaus",				ASS_KICKER_BOOTS, /* kicking a monster will always stun and confuse it, aggravate monster, monsters are always spawned hostile */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Kylie Lum's Snakeskin Boots",				HIGH_STILETTOS, /* putting them on will cause all monsters to spawn hostile for the rest of the game; +10 kicking damage and your kick cannot be "clumsy" and has 25% chance of paralyzing the enemy; they carry an ancient Morgothian curse unless you're a topmodel, and if you try to put them on as a failed existence, you acquire intrinsic nastiness! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 25000L ),

A("Sandra's Beautiful Footwear",				UNFAIR_STILETTOS, /* confusion resistance, swimming, unbreathing */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),

A("Uneven Stilts",				SKY_HIGH_HEELS, /* fumbling (like irregular heels), +15 charisma */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Neanderthal Soccer Club",				PREHISTORIC_BOOTS, /* kicking an item will exercise STR and DEX if the item moves */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Shin Kick of Love",				SYNTHETIC_SANDALS, /* kicking a monster has 1% chance to make it peaceful, unless it resists */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 3000L ),

A("Absolute Autocurse",				RIN_CURSE, /* autocurses your entire inventory if you put it on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1L ),

A("Lucky Gadget",				RIN_RANDOM_EFFECTS,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Clearvision",				RIN_SPECIAL_EFFECTS,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Guaranteed Hit Power",				RIN_INCREASE_ACCURACY, /* increase DEX by enchantment value */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Unbelievably Strong Punch",				RIN_INCREASE_DAMAGE, /* increase STR by enchantment value */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Deathly Cold",				RIN_FAST_METABOLISM, /* disables cold resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Magical Shock",				RIN_NASTINESS, /* drain res */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Good Things Will Happen Eventually",				RIN_BAD_EFFECT, /* turn counter increases half as fast */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Required Gladness",				RIN_DISENGRAVING, /* speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Never Needed",				RIN_ANTI_DROP,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Knowledgeable Failure",				RIN_FAILED_TRAINING,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 700L ),

A("Scrawny Pipsqueak",				RIN_FAILED_EXERCISE, /* +5 AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Tschoeck Kloeck",				AMULET_OF_POLYMORPH, /* deactivates poly control for 1 million turns when put on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Spellcaster's Dream",				AMULET_OF_THE_RNG, /* disables sleep res */
	(SPFX_RESTR|SPFX_EREGEN|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Low Zero Number",				AMULET_OF_INFINITY, /* banking effect, silently autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Dynamitus",				AMULET_OF_EXPLOSION, /* causes an explosion centered on you 1 in 2000 turns */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("I Never Take Drugs",				AMULET_OF_WRONG_SEEING,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Uoy Ot Kcab Dnes",				AMULET_OF_WEAK_MAGIC,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Goodbye Trolls",				LARGE_BOX_OF_DIGESTION,
	(SPFX_RESTR|SPFX_WARN|SPFX_DCLAS), 0, S_TROLL,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Priamos' Treasure",				CHEST_OF_HOLDING, /* like Wallet of Perseus */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7000L ),

A("Ice Block Harharharharhar",				ICE_BOX_OF_WATERPROOFING, /* +2 melee damage for every corpse in it, up to a maximum of +30 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Recycler Bin",				ICE_BOX_OF_DIGESTION, /* +1 alignment for every item that is deleted by it; +50 alignment and +5 max alignment if it deletes an artifact */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Surfing Fun",				OILSKIN_SACK, /* never leaks, even if cursed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Monsterator",				BAG_OF_DIGESTION, /* if it deletes at least 10 items at once, it will summon as many monsters as the # of items deleted and increases your prayer timeout by 50x that value */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Go Away You Bastard",				DARK_MAGIC_WHISTLE, /* also has a phase door effect on you if not cursed, but will instantly curse itself (even if blessed) 25% of the time */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Battlehorn of Sescheron",				FROST_HORN, /* these artifact horns only consume a charge 50% of the time they're played */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Hellish Wartube",				FIRE_HORN,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Heaven's Call to Arms",				TEMPEST_HORN,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Bimmel Bimmel",				BELL, /* applying it tames all 'x' that fail a resistance check */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Scrabble Babble",				FELT_TIP_MARKER, /* only loses charges 10% of the time */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("i the Sage",				SWITCHER, /* spawns a Gunnhild's General Store on the level */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("F-PROT",				PACK_OF_FLOPPIES, /* applying it can also contain 'Bandarchor', which causes a random bad effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1L ),

A("Panic in Gotham Forest",				SCR_GROWTH, /* fills the entire level with trees */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("ENSBADEB FRAUSED",				WAN_TOXIC,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Movie Analogy",				WAN_CHLOROFORM,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Supergirl's Jump and Run Fun",				MORION, /* jumping when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Automatic Poke Ball",				LOADSTONE, /* if you have it in your inventory, all pokemon have 3% chance of being spawned tame */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Cubic Sodium Chloride",				SALT_CHUNK, /* dissolving it creates 5 tame familiars */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 400L ),

A("Magic Resistance Get",				BOULDER,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, CARY(AD_MAGM), 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Shocking Therapy",				REALLY_HEAVY_IRON_BALL, /* disables shock resistance */
	(SPFX_RESTR), 0, 0,
	ELEC(5,7), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Enigmatic Riddle",				HEAVY_CONUNDRUM_BALL,
	(SPFX_RESTR), 0, 0,
	PHYS(7,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2400L ),

A("Do You Even Lift",				IMPOSSIBLY_HEAVY_MINERAL_BALL,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	PHYS(0,0), DFNS(AD_DRLI), CARY(AD_MAGM), 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Gangbanging Like A Boss",				GOLD_CHAIN,
	(SPFX_RESTR), 0, 0,
	PHYS(0,10), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 5000L ),

A("Freezemetal",				ELYSIUM_SCOURGE,
	(SPFX_RESTR), 0, 0,
	COLD(7,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2400L ),

A("Kings Ransom For You",				MINERAL_HOSTAGE_CHAIN, /* curses itself with TY curse when wielded, half speed */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_PROTEC), 0, 0,
	STUN(5,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Do Not Throw Me",				SEGFAULT_VENOM, /* causes segfault panic if you're stupid enough to throw it! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 0L ),

A("Waters of Oblivion",				LETHE_CLOAK, /* amnesia 1 in 1000 turns, all & are 95% peaceful and 20% tame, swimming */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Jonadab's Winter Wear",				UGG_BOOTS,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Madman's Power",				AMULET_OF_MAP_AMNESIA, /* manaleech */
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 500L ),

A("Remembering The Bad Times",				CLOAK_OF_MAP_AMNESIA, /* keen memory */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Eighth Deadly Sin",				AMULET_OF_DEPRESSION, /* surrounds you with sin traps 1 in 10000 turns */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Permanentitis",				CLOAK_OF_TRANSFORMATION, /* polymorphs never time out, but also disables poly control */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Waterforce 2.0",				CLOAK_OF_WATER_SQUIRTING, /* swimming, unbreathing */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Now It's For Real",				CLOAK_OF_STARVING, /* conflict */
	(SPFX_RESTR|SPFX_REGEN|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Black Veil of Blackness",				CLOAK_OF_CURSE, /* ancient morgothian curse, antimagic */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Clapclap",				CLOAK_OF_DISENCHANTMENT,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("More Higher",				CLOAK_OF_ESCALATION, /* 1 in 2000 chance per turn to increase escalation counter, 1 in 100 monsters has escalation egotype */
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Filthy Mortals Will Die",				CLOAK_OF_ANGRINESS, /* +10 negative protection when putting it on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Dschlschlschlschlsch",				CLOAK_OF_CANCELLATION, /* deactivates MR for exactly one turn when you put it on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1L ),

A("Hahaha-ha hahahahaha",				CLOAK_OF_TOTTER, /* putting it on gives permanent respawning and displays a very funny message :D */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Cleanliness Lab",				HUGGING_GOWN, /* sickness resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Floating Flame",				FLOATCLOAK,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Demonic Undead Radar",				BESTEST_CLOAK, /* warning of demons */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Sexy Stroking Units",				BIKINI, /* +10 AC, +5 CHA */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("War Me Nevertheless",				CLOAK_OF_PERMANENCE,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 6000L ),

A("Jedi Mind Power",				CLOAK_OF_THE_FORCE, /* putting it on offers you to learn telekinesis, but if you say yes, three random intrinsics get disabled for 1 million turns each */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Arabella's Lightningrod",				CLOAK_OF_CURSE_CATCHING, /* banishmentitis, itemcursing, silently becomes prime cursed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Ka-Blammo",				SAWED_OFF_SHOTGUN, /* every time you trigger a trap, its enchantment randomly goes either up or down, but cannot go below -20 or above +10. BUC status determines if it's more likely to go up or down */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("RNG's Fun",				ROBE_OF_RANDOMNESS, /* if you put it on while it's +0, it will randomly set itself to something between -5 and +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("You're The Best",				ROBE_OF_SPECIALTY,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Anastasia's Soft Clothes",				ROBE_OF_NASTINESS, /* +10 AC */
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Plentyhorn of Famine",				HORN_OF_PLENTY, /* causes hunger when applied */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 50L ),

A("Marine Threat Neutered",				FLINT,
	(SPFX_RESTR|SPFX_DFLAG1), 0, M1_SWIM,
	PHYS(0,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Bang Bang",				SAWED_OFF_SHOTGUN, /* deafness when wielded, and sets itself to +2 if it's lower */
	(SPFX_RESTR), 0, 0,
	STUN(5,10), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Tuna Cannon",				POWER_CROSSBOW, /* +1 multishot */
	(SPFX_RESTR), 0, 0,
	COLD(0, 10), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Pfiiiiiiiiet",				TIN_WHISTLE, /* no specialty - just to unlock petkeeping skill */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Dogwalk",				LEASH, /* ditto */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Friend Call",				SCR_CREATE_FAMILIAR, /* creates two pets at once */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("For The Good Cause",				SCR_TAMING, /* confused radius even if you're not confused */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("Warpchange",				RIN_POLYMORPH, /* teleportitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Semi Shape Control",				RIN_POLYMORPH_CONTROL, /* also gives polymorphitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Formtaker",				AMULET_OF_POLYMORPH, /* gives permanent intrinsic polymorphitis if you put it on! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Colorless Variety",				AMULET_OF_POLYMORPH_CONTROL, /* shades of grey effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Medical Ophthalmoscope",				STETHOSCOPE, /* always acts like a blessed one */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Search And You Will Find",				RIN_SEARCHING,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Lots of Knowledge",				RIN_TRAP_REVEALING,
	(SPFX_RESTR|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Hoyo Hoyo Wololo",				GOD_O_METER, /* always acts like a blessed one */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Haaaaaaaaaaaaa leluja",				POT_WATER, /* blesses itself upon being picked up and identifies its BUC? */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Gruum Gruum",				HOLY_WAFER, /* no specialty - just meant to unlock spirituality skill */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Ancient Sacrifice",				SCR_CONSECRATION, /* ditto */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Zen Buddhism",				SCR_CREATE_ALTAR, /* ditto */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Chrrrrrrrrrrrrr",				SPE_GOOD_NIGHT, /* all of these are there just so gifts have a chance of unrestricting spell schools */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Useless Element",				SPE_POISON_BLAST,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Inversion Therapy",				SPE_BANISHING_FEAR,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Magical Blindfolding",				SPE_BLIND_SELF,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Tool-Assisted Magic",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Add Acid To Water",				SPE_CHEMISTRY,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Ohmygodhelpme",				SPE_CAUSE_FEAR,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Cursebreaking 101",				SPE_DESTROY_ARMOR,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Malignant Aura",				SPE_CURSE_ITEMS,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Coated For Good",				SPE_ACIDSHIELD,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Arabella's Escape Route",				SPE_WARPING,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Night Movement",				SPE_TIME_SHIFT,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Spamming Defense Magic",				SPE_REFLECTION,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Fartbolt",				SPE_FIRE_BOLT,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Jonadab's Evil Patch Artifact",			AKLYS,
	(SPFX_RESTR), 0, 0,
	PHYS(0,1), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 20L ),

A("What It Says On The Tin",				SPE_GENOCIDE,
	(SPFX_RESTR), 0, 0,
	FIRE(2,10), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Deadly Gambling",				SPE_RUSSIAN_ROULETTE, /* +d30 damage; every time you wield it there's a 1% chance to die instantly */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Prismatic Protection",				SPE_ELEMENTAL_BEAM, /* resist cold, fire, poison, lightning when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Irresistible Offense",				SPE_MANA_BOLT,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Eurgh",				SPE_INDUCE_VOMITING,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Quick Slowness",				SPE_RANDOM_SPEED,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Final Explosion",				SPE_SELFDESTRUCT,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Stalwart Bunker",				SPE_BURROW,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Frozen Polar Bear",				SPE_FROST,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Doenerteller Versace",				CRAM_RATION, /* eating it gives temporary drain and magic resistance as well as reflection, rnz(2000) turns for each */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 150L ),

/* below are artifacts suggested by ProzacElf */
A("ProzacElf Shatterhand",				GAUNTLETS_OF_FUMBLING,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("ProzacElf's Autohealer",				CLOAK_OF_INVENTORYLESSNESS, /* 1 in 1000 chance of gaining an additional max HP per turn, but if that effect procs, you also get rnd(1000) turns of nastiness */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("ProzacElf's Poopdeck",				SPE_CHAOS_TERRAIN, /* wielding it causes chaos terrain */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

/* below are artifacts suggested by Dikkin; they're a bit different from his original suggestions,
 * because (believe it or not) game balance is very important to me. --Amy */
A("Dikkin's Deadlight",				WAN_POLYMORPH, /* yellow spells when wielded, temporary yellow spells when zapped by anyone, zapping yourself gives 1 turn of polymorph control and allows you to choose a polyform effect instead */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Dikkin's Dragon Teeth",				AMULET_OF_POLYMORPH_CONTROL, /* yellow spells except if you're a kobold bard, being polymorphed allows you to choose a polyform effect instead, flying, prevents you from wearing body armor */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, DRAGON_BREATH, A_NONE, NON_PM, NON_PM, 4000L ),

A("Dikkin's Favorite Spell",				SPE_POLYMORPH, /* +8 INT and yellow spells when wielded, allows you to choose a polyform effect when you zap yourself with the spell but doing so causes temporary yellow spells */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),


/* below are randarts: they're supposed to be a random base item
 * melee weapons will become some other melee weapon, launchers will become
 * some other launcher, body armors will become some other body armor etc. --Amy */

A("Soulcalibur",                  LONG_SWORD,
	(SPFX_RESTR|SPFX_SEEK|SPFX_DEFN|SPFX_INTEL|SPFX_SEARCH),0,0,
	PHYS(5,5),	DRLI(0,0),	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 4000L ),

A("Undeadbane",			LONG_SWORD,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_UNDEAD,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 2500L ),

A("Rainbowswandir",		LONG_SWORD,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 8000L ),

A("Wizardbane",                  LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	STUN(3,2),	DFNS(AD_MAGM),	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 3500L ),

A("Vorpal Edge",		LONG_SWORD,
	(SPFX_RESTR|SPFX_BEHEAD), 0, 0,
	PHYS(5,1),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Dark Magic",			LEATHER_ARMOR,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Beam Control",			LONG_SWORD,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Sandra's Secret Weapon",			LONG_SWORD, /* aggravate monster, can cause amnesia when wielded */
	(SPFX_RESTR|SPFX_DEFN|SPFX_SEARCH), 0, 0,
	PHYS(0,6), DFNS(AD_ELEC), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Dumboak's Hew",			LONG_SWORD, /* blindness resistance */
	(SPFX_RESTR), 0, 0,
	PHYS(0,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Power Ammo",			DART,
	(SPFX_RESTR), 0, 0,
	PHYS(5,0), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 100L ),

A("Blobloblobloblo",			BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(0,7), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Pschiuditt",			BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Rattattattattatt",			BOW, /* aggravate monster */
	(SPFX_RESTR), 0, 0,
	PHYS(0,8), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Flam0r",			BOW,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	FIRE(10,1), DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Sureshot",			BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(20,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 9900L ),

A("Stingwing",			DART,
	(SPFX_RESTR), 0, 0,
	PHYS(7,0), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 70L ),

A("Nobile Mobility",			VICTORIAN_UNDERWEAR, /* "nobile" is intentional --Amy */
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Antimagic Field",			VICTORIAN_UNDERWEAR, /* prevents spellcasting */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Natalia Is Lovely But Dangerous",			VICTORIAN_UNDERWEAR, /* polymorph control and manaleech */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Tape Armament",			LEATHER_ARMOR, /* superscrolling screen effect */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Cathan's Sigil",			RIN_AGGRAVATE_MONSTER, /* increases STR by its enchantment value +3 */
	(SPFX_RESTR|SPFX_REGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3400L ),

A("Fleeing Mine Mail",			LEATHER_ARMOR, /* autocurses when worn, disables fire resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Grey Fuckery",			LEATHER_ARMOR, /* shades of grey effect */
	(SPFX_RESTR|SPFX_DEFN|SPFX_WARN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Little Penis Wanker",			LEATHER_ARMOR, /* prevents you from contracting STD */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("D-Type Equipment",			LEATHER_ARMOR, /* prevents lava from harming player */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Incredible Sweetness",			LEATHER_ARMOR,
	(SPFX_RESTR|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Queen Articuno's Hull",			LEATHER_ARMOR, /* aggravate monster and conflict */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 20000L ),

A("Don Suicune Used Selfdestruct",			LEATHER_ARMOR, /* aggravate monster and random nasty effects */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Wondercloak",			ORCISH_CLOAK,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Eveline's Civil Mantle",			ORCISH_CLOAK,
	(SPFX_RESTR|SPFX_STLTH|SPFX_LUCK), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Ina's Overcoat",			ORCISH_CLOAK, /* hunger, random fainting, and disintegration/sickness resistance; autocurses */
	(SPFX_RESTR|SPFX_SPEAK|SPFX_SEEK), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Groundbummer",			ORCISH_CLOAK, /* disables the flying intrinsic, aggravates monsters, and causes intrinsic freezing; autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5L ),

A("Rita's Lovely Overgarment",			ORCISH_CLOAK, /* autocurses and sets its enchantment to -10 when worn! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Lunar Eclipse Tonight",			ORCISH_CLOAK,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 600L ),

A("Lorskel's Speed",			HELMET, /* makes the player very fast and adds extra speed sometimes */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("106Dot1 Alien Radio",			HELMET, /* works like radio helmet */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Nadja's Darkness Generator",			HELMET, /* autocurses, creates darkness once every 100 turns, but improves your to-hit by 5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Tha Wall",			LEATHER_ARMOR, /* 9 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 900L ),

A("LLLLLLLLLLLLLM",			HELMET, /* LLM messages, free action and drain resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Arabella's Great Banisher",			LEATHER_GLOVES, /* levelteleportitis, heavily curse themselves when worn, disables teleport control */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("No Future But Agony",			SHIELD, /* autocurses, aggravates monsters and causes conflict */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 6000L ),

A("Bonus Hold",			SHIELD, /* autocurses, grants conflict and sustain ability */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 12000L ),

A("The Grexit Is Near",			SHIELD, /* autocurses, causes the "verisiert" effect and gives keen memory */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 12000L ),

A("Real Men Wear Psychos",			SHIELD, /* autocurses, grants psi resistance and the hate trap and farlook bug effects */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 12000L ),

A("AmyBSOD's New Footwear",			LOW_BOOTS, /* cause blood loss */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_DRLI), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Manuela's Unknown Heels",			LOW_BOOTS, /* aggravate monster, conflict, heavily curse themselves when worn, count as high heels */
	(SPFX_RESTR|SPFX_DEFN|SPFX_ESP), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Hades the Meanie",			LOW_BOOTS, /* aggravate monster, unbreathing, monsters are always spawned hostile */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Amy Loves Autocursing Items",			LOW_BOOTS, /* autocurses :-P, causes random itemcursing */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_SEEK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("AllyNone",			LOW_BOOTS, /* conflict, unbreathing, aggravate monster */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Khor's Required Idea",			LOW_BOOTS, /* free action, auto destruct */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Error In Play Enchantment",			LOW_BOOTS, /* polymorphitis, teleportitis, regeneration, speed bug */
	(SPFX_RESTR|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Whoa Hold On Dude",			RIN_AGGRAVATE_MONSTER,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("The Achromantic Ring",			RIN_AGGRAVATE_MONSTER, /* disintegration resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("GoldenIvy's Engagement Ring",			RIN_AGGRAVATE_MONSTER, /* aggravate monster, teleportitis, sickness resistance, flying */
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Tyranitar's Own Game",			AMULET_OF_STRANGULATION, /* prism reflection */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("One Moment In Time",			AMULET_OF_STRANGULATION, /* warp reflection, resist psi/stun/petrification/sickness, nastiness */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Bueing",			AMULET_OF_STRANGULATION, /* sight bonus, poison resistance, rmb loss */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Nazgul's Revenge",			AMULET_OF_STRANGULATION, /* heavily curses itself, disables drain resistance, gives free action and manaleech, anti-experience */
	(SPFX_RESTR|SPFX_REGEN|SPFX_HPHDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("Harry's Blackthorn Wand",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Professor Snape's Dildo",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("French Magical Device",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Saggittii",		DART, /* Yes this misspelling is intentional! --Amy */
	(SPFX_RESTR), 0, 0,
	PHYS(8,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1500L ),

A("Bentshot",   BOW,
    SPFX_RESTR, 0, 0,
    PHYS(10,1),     NO_DFNS,    NO_CARY,    0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),
    
A("Jellywhack", LONG_SWORD,
    (SPFX_RESTR|SPFX_DCLAS|SPFX_HALRES), 0, S_JELLY,
    PHYS(10,0), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 400L ),
    
A("One Through Four Scepter", LONG_SWORD, /* trap of walls and +10 difficulty effect when wielded */
	(SPFX_RESTR|SPFX_INTEL|SPFX_HALRES|SPFX_REGEN|SPFX_DALIGN|SPFX_WARN|SPFX_HSPDAM), 0, 0,
	PHYS(5,0),	DFNS(AD_DRLI),	NO_CARY,
	0,		A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("Al Canone", BOW,
	(SPFX_RESTR|SPFX_DEFN|SPFX_LUCK|SPFX_INTEL|SPFX_WARN|SPFX_STLTH), 0, 0,
	PHYS(5,3),        DFNS(AD_FIRE),  NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),

A("Veil of Ministry",	ORCISH_CLOAK, /* drain res, superscroller, black ng walls and permanent confusion, heavily autocurses when worn */
	(SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_REFLECT), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 1000L),

A("Zankai Hung Ze Tung Do Hai",		LONG_SWORD, /* very fast when wielded, but massively increases hunger and damages the wielder */
	(SPFX_RESTR|SPFX_HSPDAM), 0, 0, 
	PHYS(1,0),	NO_DFNS,	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 4444L),

A("Awkwardness",		LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(1,1),	FIRE(0,0),	NO_CARY,
	0, A_CHAOTIC, NON_PM, NON_PM, 8000L),

A("Schwanzus Langus",			LONG_SWORD, /* stun, confusion, hallu and freezing when wielded */
	(SPFX_RESTR|SPFX_HSPDAM|SPFX_HPHDAM|SPFX_DEFN|SPFX_REFLECT), 0, 0, //needs quote
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 1500L), 

A("Trap Dungeon of Shambhala",	VICTORIAN_UNDERWEAR, /* sets itself to +10 when worn, but has create traps and random bad effects */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_NEUTRAL, NON_PM, NON_PM, 4500L), 

A("Zero Percent Failure",		HELMET, /* makes spellcasting easier */
	(SPFX_RESTR|SPFX_HSPDAM), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0, A_NONE, NON_PM, NON_PM, 4000L),

A("Henrietta's Heavy Caster",	ORCISH_CLOAK, /* spellcasting chance bonus, aggravate monster :D */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY, 
	0,	A_CHAOTIC,	 NON_PM, NON_PM, 5000L),

A("The ROFLcopter Web",	LEATHER_ARMOR,  /* spellcasting chance bonus, magic resistance and half speed when worn */
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_INTEL|SPFX_WARN), 0, M2_ELF,
	NO_ATTK,	DRLI(0,0),	NO_CARY,
	0,	A_CHAOTIC, NON_PM, NON_PM, 2000L), 

A("ShivanHunter's Unused Prize",			LEATHER_ARMOR, /* displacement, blood mana, stun */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_INTEL), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,	
	0, A_NONE, NON_PM, NON_PM, 9000L), 

A("Arabella's Artifact Creation Result",	LONG_SWORD, /* aggravate monster, recurring disenchantment and itemcursing when wielded */
	(SPFX_RESTR|SPFX_INTEL|SPFX_EREGEN|SPFX_BEHEAD|SPFX_LUCK|SPFX_SEARCH|SPFX_SEEK), 0, 0,
	PHYS(20,6),	NO_DFNS,	NO_CARY,
	0,		A_LAWFUL, NON_PM, NON_PM, 4500L), 

A("The Tiara of Amnesia", HELMET, /* guess what the effect of this thing is :-P --Amy */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L),

A("Flue Flue Flueflue Flue", HELMET, /* undead warning, flying */
	(SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L),

A("Lixertypie", LONG_SWORD,
	(SPFX_RESTR|SPFX_INTEL|SPFX_DFLAG2), 0, (M2_HUMAN|M2_ELF|M2_DWARF),
	PHYS(9,9),	DFNS(AD_MAGM),	NO_CARY,
	0,	A_LAWFUL, NON_PM, NON_PM, 9999L), 

A("The Sameness of Chris",			LONG_SWORD,
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 7500L),

A("Donald Trump's Rage",                  LONG_SWORD,
	(SPFX_RESTR|SPFX_BEHEAD|SPFX_DCLAS|SPFX_DRLI), 0, S_HUMAN,
	DRLI(5,1),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 1500L ),

A("Prick Pass",                    LONG_SWORD,
	SPFX_DFLAG2, 0, M2_ELF,
	PHYS(5,8),     NO_DFNS,        NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 300L ),

A("Thranduil Lossehelin",				LONG_SWORD, /* heavily curses itself, bloodthirsty, 1 in 20000 chance per turn that it disintegrates, all glyphs are fleecy-colored */
	(SPFX_RESTR|SPFX_DRLI), 0, 0,
	DRLI(5,0), NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 10000L ),

A("Feanaro Singollo",				LONG_SWORD, /* confusion and speed while wielded */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	FIRE(10,6), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Winsett's Big Daddy",				BOW, /* +rnd(2) multishot */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Feminist Girl's Purple Wear",				VICTORIAN_UNDERWEAR, /* +5 CHA if you're female, -5 to all stats otherwise */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Lea's Spokeswoman Uniform",				ORCISH_CLOAK, /* heavily autocurses (and does nothing else) because Lea is devious :P */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Heretical Figure",				ORCISH_CLOAK, /* anti caster effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Jana's Secret Car",				ORCISH_CLOAK, /* speed, unbreathing, but bumping into an invisible monster has 1 in 100 chance to instakill you (no joke). */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Unimplemented Feature",				HELMET, /* confusion, DSTW effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Flat Insanity",				HELMET, /* inventorylessness, autocurses when worn */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2500L ),

A("Freeze Or Yes",				LEATHER_GLOVES, /* player acquires intrinsic freezopathy from putting them on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Princess Bitch",				LEATHER_GLOVES, /* sitting on a throne always gives the princess bitch effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Would You Raight That",				LEATHER_GLOVES, /* unlocks searching skill and caps it at expert but also prime curses itself if you didn't have the skill before */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Difficulty 5",				LEATHER_GLOVES, /* flying, monsters often create a trap upon spawning, monster spawn frequency doubled and difficulty + (6 + your experience level) */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Swarm-Soft High Heels",				LOW_BOOTS, /* count as high heels */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Weak From Hunger",				LOW_BOOTS, /* conflict, weakness effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Arabella's Resist Cold",				RIN_AGGRAVATE_MONSTER, /* autocurses your entire inventory if you put it on, bank trap effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1L ),

A("Ratsch Watsch",				AMULET_OF_STRANGULATION, /* deactivates tele control for 1 million turns when put on */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Arabella's Precious Gadget",				AMULET_OF_STRANGULATION, /* banking effect, silently autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Arabella's Warding Hoe",				LONG_SWORD, /* silently curses itself with TY curse when wielded, half speed */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_PROTEC), 0, 0,
	STUN(5,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10000L ),

A("Shapetake Number Five",				ORCISH_CLOAK, /* polymorphs never time out, but also disables poly control and gives polymorphitis */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Arabella's Wand Booster",				ORCISH_CLOAK, /* ancient morgothian curse, antimagic, curse items; silently curses itself heavily */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Intelligent Pope",				BOW, /* every time you trigger a trap, its enchantment randomly goes either up or down, but cannot go below -20 or above +10. BUC status determines if it's more likely to go up or down */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("RNG's Pride",				LEATHER_ARMOR, /* if you put it on while it's +0, it will randomly set itself to something between -5 and +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("RNG's Joy",				LEATHER_GLOVES, /* if you put it on while it's +0, it will randomly set itself to something between -5 and +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("RNG's Sexiness",				LOW_BOOTS, /* if you put it on while it's +0, it will randomly set itself to something between -5 and +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("RNG's Embrace",				ORCISH_CLOAK, /* if you put it on while it's +0, it will randomly set itself to something between -5 and +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("RNG's Grimace",				HELMET, /* if you put it on while it's +0, it will randomly set itself to something between -5 and +5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Complete Mon Dieu",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Agathe Bauer",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Anneliese Brown",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("I Will Think About You",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Del Olelong",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Jubeljubijeeah",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Duedelduedelduedelduedeldueueueueue",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Cause I'm A Cheater",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Batman Night",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Nikkenikkenik",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),



/* second batch of randarts - these use a different RNG to determine their base type --Amy */

A("Jana's Grave Wall",				ORCISH_CLOAK, /* speed, unbreathing, but bumping into a cloaked mimic has 1 in 100 chance to instakill you (no joke). */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Henrietta's Dogshit Boots",				LOW_BOOTS, /* aggravate monster, disables stealth, monsters are always spawned hostile and always approach the player, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Fireproof Wall",                  LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN), 0, 0,
	FIRE(4,2),      FIRE(0,0),      NO_CARY,        0, A_LAWFUL, NON_PM, NON_PM, 400L ),

A("Spearblade",                LONG_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(9,1),      NO_DFNS,        NO_CARY,        0, A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("Radiator Area",                   LONG_SWORD,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_UNDEAD,
	PHYS(5,0),	DFNS(AD_BLND),	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

A("Jessica's Winning Strike",                LONG_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(0,4),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, NON_PM, NON_PM, 1200L ),

A("Markus's Justice",           LONG_SWORD,
	(SPFX_RESTR|SPFX_DALIGN), 0, 0,
	PHYS(5,6),     NO_DFNS,        NO_CARY,        0, A_LAWFUL, NON_PM, NON_PM, 1500L ),

A("Katharina's Melee Prowess",               LONG_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(3,5),     NO_DFNS,        NO_CARY,        0, A_LAWFUL, NON_PM, NON_PM, 300L ),

A("Lichbane",                 LONG_SWORD,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_LICH,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NONE, NON_PM, NON_PM, 200L ),

A("Forked Tongue",                  LONG_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(2,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 300L ),

A("All Seriousness",                    LONG_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(3,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1500L ),

A("Special Lack",                  LONG_SWORD,
	SPFX_RESTR, 0, 0,
	PHYS(0,5),     NO_DFNS,        NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Wing Wing",				LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	FIRE(2,2), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Carmoufalsch",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Wie Es Auch Sei",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Morton Theirs of Ravel Radio",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Deep Friends",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Hae-hae hiiii",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("For Mommy Ever Forselessault",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Lawfire",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Wae wae wae daedeldaedeldaedellodeledeledelel",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("President Schiesskanista",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Knbloeloeloelodrio",				SPE_MAGICTORCH,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Desert Maid",			LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(0,10), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Cygniswan",			LONG_SWORD,
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Talkator",			LONG_SWORD,
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	PHYS(2,3), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Magesooze",			LONG_SWORD,
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 600L ),

A("Resistant Resistor",			LONG_SWORD,
	(SPFX_RESTR|SPFX_HPHDAM|SPFX_HSPDAM), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Vernon's Potterbasher",			LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(4,8), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Schwoingeloingeloing oooar",			LONG_SWORD,
	(SPFX_RESTR|SPFX_SPEAK), 0, 0,
	PHYS(24,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 240L ),

A("Femmy's Lash",			LONG_SWORD,
	(SPFX_RESTR|SPFX_DFLAG2|SPFX_WARN), 0, M2_MALE,
	PHYS(5,12), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Casque Outlook",			LONG_SWORD,
	(SPFX_RESTR|SPFX_TCTRL), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Unfair Pee",			LONG_SWORD,
	(SPFX_RESTR|SPFX_DEFN|SPFX_WARN), 0, 0,
	PHYS(2,6), DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Sea Captain Piercer",			LONG_SWORD,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("End Of Look Worse",			LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(2,4), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Space Begins After Here",			LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(2,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Corina's Thunder",			LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	ELEC(2,6), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Inner Tube",			LONG_SWORD,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Solo Slacker",			BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(1,1), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 50L ),

A("Ammo of the Machine",			DART,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_GOLEM,
	PHYS(10,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 20L ),

A("Dae-oe-oe-oe-oe-oe",			BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(0,7), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Cannoneer",			BOW,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Speedhack",			BOW, /* makes the player very fast when wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Earth Gas Gun",			BOW,
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	PHYS(0,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3600L ),

A("Fire Already",			DART,
	(SPFX_RESTR), 0, 0,
	PHYS(2,5), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Human Wipeout",			LONG_SWORD,
	(SPFX_RESTR|SPFX_BEHEAD|SPFX_DCLAS), 0, S_HUMAN,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Splinter Armament",			LEATHER_ARMOR, /* superscrolling screen effect */
	(SPFX_RESTR|SPFX_REFLECT|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 500L ),

A("Absolute Monster Mail",			LEATHER_ARMOR, /* autocurses when worn, disables fire resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 10L ),

A("Rita's Tender Stilettos",			LOW_BOOTS, /* counts as high heels, but also autocurses and sets its enchantment to -10 when worn! */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Half Moon Tonight",			ORCISH_CLOAK,
	(SPFX_RESTR|SPFX_LUCK), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 600L ),

A("Pantap",			ORCISH_CLOAK,
	(SPFX_RESTR|SPFX_ESP|SPFX_WARN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Ruth's Dark Force",			HELMET, /* autocurses, creates darkness once every 100 turns, but improves your to-hit by 5 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Hamburg One",			HELMET, /* hunger */
	(SPFX_RESTR|SPFX_HALRES), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Arabella's Melee Power",			LONG_SWORD, /* nastiness, spawns a Gunnhild when wielded and also 1 in 1000 chance to spawn another one if you keep wielding it */
	(SPFX_RESTR), 0, S_HUMAN,
	PHYS(10,10), NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 8000L ),

A("Asbestos Material",			LONG_SWORD, /* always poisoned */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Tanks A Lot",			LEATHER_GLOVES, /* glibbery hands, 5 extra points of AC */
	(SPFX_RESTR|SPFX_REGEN|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Dimvision",			LEATHER_GLOVES, /* putting them on for the first time gives you the eddy wind technique but also permanent weak sight! */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("I'm Getting Hungry",			SHIELD, /* 20% boost to block rate, free action */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("CCC CCC CCCCCCC",			SHIELD, /* causes confusion, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 100L ),

A("Five Star Party",			SHIELD, /* autocurses, causes the uninformation effect and gives confusion/stun resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 12000L ),

A("Gudrun's Stomping",			LOW_BOOTS,
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Goeffelboeffel",			LOW_BOOTS, /* half speed */
	(SPFX_RESTR|SPFX_REGEN|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("Temperator",			LOW_BOOTS, /* resist fire */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Green Color",			RIN_AGGRAVATE_MONSTER, /* poison resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Scarab of Adornment",			RIN_AGGRAVATE_MONSTER, /* +10 charisma */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Schwueu",			AMULET_OF_STRANGULATION, /* teleporting items */
	(SPFX_RESTR|SPFX_TCTRL|SPFX_ESP), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Fully The Long Penis",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3500L ),

A("World of Coq",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3500L ),

A("Whooshzap",			WAN_MAKE_INVISIBLE,
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3500L ),

A("Nadja's Silence",			LONG_SWORD,
	(SPFX_RESTR|SPFX_STLTH),0,0,
	PHYS(5,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 3000L ),

A("A Sword Named Sword",		LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(8,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1500L ),

A("Heritage Ignorer",		LONG_SWORD,
	(SPFX_RESTR), 0, 0,
	PHYS(4,2),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("Mimicbane", LONG_SWORD,
    (SPFX_RESTR|SPFX_DCLAS|SPFX_HALRES), 0, S_MIMIC,
    PHYS(10,0), NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 400L ),

A("Hahahahahahahaaaaaaaaaaaa",		LONG_SWORD,
	(SPFX_RESTR|SPFX_ATTK), 0, 0,
	COLD(3,3),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, NON_PM, NON_PM, 1000L ),
    
A("Poison Pen Letter",	LONG_SWORD, /* poisons you each turn you wield it */
	(SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DRLI|SPFX_HPHDAM|SPFX_REGEN), 0, 0,
	DRLI(9,5),	NO_DFNS,	NO_CARY,
	0,	A_NEUTRAL, NON_PM, NON_PM, 2500L),

A("Sunali's Summoning Storm",			LOW_BOOTS, /* improve spellcasting chances by 15% */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Filthy Press",		BOW, /* messages often get replaced by random ones */
	(SPFX_RESTR|SPFX_SEEK|SPFX_DEFN|SPFX_INTEL|SPFX_SEARCH|SPFX_HALRES), 0, 0,
	PHYS(5,5),	DRLI(0,0),	NO_CARY,	
	0, A_LAWFUL, NON_PM, NON_PM, 8000L), 

A("Mub Puh Mub Dit Dit",			LONG_SWORD,
	(SPFX_RESTR|SPFX_INTEL|SPFX_SEARCH), 0, 0,
	PHYS(7,5),	DFNS(AD_BLND),	NO_CARY,
	0, A_LAWFUL, NON_PM, NON_PM, 7500L),

A("Donnnnnnnnnnnng",				LONG_SWORD, /* every time you hit with it, there's a 33% chance that its enchantment goes down by 1 unless it's already -20 or worse */
	(SPFX_RESTR), 0, 0,
	PHYS(0,20), NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Provocateur",				LONG_SWORD, /* conflict while wielded */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Foeoeoeoeoeoeoe",				BOW, /* +rnd(3) multishot, projectiles misfire 1 out of 7 times */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Never Will This Be Useful",				LONG_SWORD, /* +4 damage per trident skill */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2000L ),

A("Quarry",				LEATHER_ARMOR, /* +5 AC; ammos made of mineral have 50% extra chance of not breaking */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Conny's Combat Coat",				ORCISH_CLOAK, /* heavily autocurses, your kicks do 5 extra points of damage and have 10% chance of causing paralysis and stun */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("Acidshock Castlecrusher",				ORCISH_CLOAK, /* resist shock and acid, 5 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 6000L ),

A("Laura's Swimsuit",				ORCISH_CLOAK, /* works like an oilskin cloak, also swimming and unbreathing, but -5 AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Protect What Cannot Be Protected",				ORCISH_CLOAK, /* allows you to erodeproof a nonerodable object with 1 in 5000 chance per turn */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Girlful Farting Noises",				HELMET, /* spawns a farting monster 1 in 1000 turns, flying */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("YOU SEE HERE AN ARTIFACT",				HELMET, /* bigscript */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 700L ),

A("Numb Or Maybe",				LEATHER_GLOVES, /* player acquires intrinsic numbopathy from putting them on 50%, gets a random bad effect 49% or acquires intrinsic yellow spells 1% */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Dead-Slam The Time Shut",				LEATHER_GLOVES, /* unlocks device skill and caps it at expert but also prime curses itself if you didn't have the skill before */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Anastasia's Unexpected Ability",				LOW_BOOTS, /* count as high heels, autocurses, teaches you the attire charm and world fall techniques if you didn't have them, but gives 3 or 9 random nasty properties as intrinsic */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Eliane's Shin Smash",				LOW_BOOTS, /* kicking a monster will always paralyze it and do double damage, and heaps of shit don't affect you and you cannot have wounded legs, but if you ever come into contact with water or something farts, they are vaporized instantly. */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ELEC), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 25000L ),

A("Mysterious Magic",				AMULET_OF_STRANGULATION, /* weak effects */
	(SPFX_RESTR|SPFX_EREGEN), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("BangCock",				BOW, /* every time you trigger a trap, its enchantment randomly goes either up or down, but cannot go below -20 or above +10. BUC status determines if it's more likely to go up or down */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("RNG's Completion",				LEATHER_ARMOR, /* if you put it on while it's +0, it will randomly set itself to something between -7 and +7 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("RNG's Beauty",				LOW_BOOTS, /* if you put it on while it's +0, it will randomly set itself to something between -7 and +7 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("RNG's Safeguard",				SHIELD, /* if you put it on while it's +0, it will randomly set itself to something between -7 and +7 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Black Darkness",				AMULET_OF_STRANGULATION, /* every glyph is black (like blacky trap) */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Fleecy Green",				AMULET_OF_STRANGULATION, /* every glyph is green */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 2000L ),

A("Peek",                    LONG_SWORD,
	SPFX_DFLAG2, 0, M2_ELF,
	PHYS(5,8),     NO_DFNS,        NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 300L ),

A("Tailcutter",			LONG_SWORD,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_WORM_TAIL,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0,		A_NEUTRAL,	NON_PM, NON_PM, 2000L ),


/* below here we have artifacts that depend on a randomized appearance --Amy */

A("Phantom Of The Opera",				ORCISH_CLOAK, /* initialized to always be an opera cloak; 5 extra points of AC */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1000L ),

A("High Desire of Fatality",				LOW_BOOTS, /* initialized to always be explosive boots; very fast speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Choice of Matter",				LOW_BOOTS, /* initialized to always be irregular boots; cold resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 5000L ),

A("Melissa's Beauty",				LOW_BOOTS, /* initialized to always be wedge boots; +10 charisma, +5 AC and +5 to-hit */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),

A("Corina's Snowy Tread",				LOW_BOOTS, /* initialized to always be winter stilettos; cold resistance, prevents potions from freezing, aggravate monster, the disarm technique works even if you're not skilled with your weapon */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7000L ),

A("Number 23",				HELMET, /* initialized to always be an aluminium helmet; psi resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 1500L ),

A("Hauntnight",				ORCISH_CLOAK, /* initialized to always be a ghostly cloak; monsters are always spawned permanently invisible */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Lorskel's Special Protection",				LEATHER_GLOVES, /* initialized to always be polnish gloves; AD_SITM fails 4 out of 5 times */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Robbery Gone Right",				LEATHER_GLOVES, /* initialized to always be polnish gloves; random gold spawns have 3 times more gold in them */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 6000L ),

A("Josefine's Evilness",				LOW_BOOTS, /* initialized to always be velcro boots; resist fire, cold, shock and psi, random fainting */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("Whiny Mary",				LEATHER_GLOVES, /* initialized to always be clumsy gloves; while wearing them, your weapon automatically curses itself every turn, but ranged attacks get +rnd(5) multishot */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2400L ),

A("Warp Speed",				LOW_BOOTS, /* initialized to always be fin boots; your speed is multiplied by 6 while you're on a water square */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Greneuvenia's Hug",				LOW_BOOTS, /* initialized to always be profiled boots; flying, fire resistance and improved vision, but displays a demonic taunt once per turn to drive the player nuts :-P */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L ),

A("Shelly",				ORCISH_CLOAK, /* initialized to always be a void cloak; antimagic on turns not divisible by 3 */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 5000L ),

A("Spread Your Legs Wide",				LEATHER_GLOVES, /* initialized to always be grey-shaded gloves; sets your AC to 10, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 200L ),

A("Greeb",				ORCISH_CLOAK, /* initialized to always be a weeb cloak; attracts monsters that are green or bright green once every 2000 turns */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Prince of Persia",				LOW_BOOTS, /* initialized to always be persian boots; jumping, 50% chance of life saving while wearing them */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 8000L ),

A("Anastasia's Playfulness",				LOW_BOOTS, /* initialized to always be hugging boots; spawns a shit trap somewhere on the level once every 1000 turns, and you will trigger them even if you fly */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_ACID), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Katie Melua's Female Weapon",				LOW_BOOTS, /* initialized to always be fleecy boots; count as high heels */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_COLD), NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Cockuetry",				LEATHER_GLOVES, /* initialized to always be fingerless gloves; petrification resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("PercentIoeoepsPercentD-thief",				ORCISH_CLOAK, /* initialized to always be a mantle of coat; thievery effect, stairs traps, monsters respawn when killed, heavily autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Peeping Groove",				LEATHER_GLOVES, /* initialized to always be fatal gloves; if you use a shotgun while wearing them, you get +rnd(7) multishot */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 2000L ),

A("Rare Asian Lady",				LOW_BOOTS, /* initialized to always be beautiful heels; resist cold, +20 charisma, can always resist if seducing monsters try to take off your gear */
	(SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 12000L ),

A("Jana's Fairness Cup",				ORCISH_CLOAK, /* initialized to always be a homicidal cloak; speed, flying, but triggering a trap has 1 in 100 chance to instakill you (no joke). */
	(SPFX_RESTR|SPFX_STLTH), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 6000L ),

A("Out Of Time",				LOW_BOOTS, /* initialized to always be castlevania boots; +5 strength and dexterity, turn limitation effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Paleolithic Elbow Contractor",				ORCISH_CLOAK, /* initialized to always be a greek cloak; +5 multishot with a bow, unskilled effect */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 2500L ),

A("Nuclear Bomb",				HELMET, /* initialized to always be a celtic helmet; newly generated golems always have the exploder and bomber egotypes */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_FIRE), NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 20000L ),

A("Beeeeeeeanpole",				LEATHER_GLOVES, /* initialized to always be english gloves; +5 range for arrows fired from bows */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Legma",				LOW_BOOTS, /* initialized to always be korean sandals */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, DFNS(AD_MAGM), NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 5000L ),

A("Terry Pratchett's Ingenuity",				ROBE, /* initialized to always be an octarine robe; prism reflection whenever it triggers */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 7000L ),

A("Arabella's Sexy Girl Butt",				ORCISH_CLOAK, /* initialized to always be a chinese cloak; tools need to be wielded if you want to apply them, autocurses */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),

A("Long-Lasting Joy",				ORCISH_CLOAK, /* initialized to always be a polyform cloak; your polymorphs last 2-3 times longer */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 3000L ),

A("Light Absorption",				ORCISH_CLOAK, /* initialized to always be an absorbing cloak */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, LIGHT_AREA, A_NONE, NON_PM, NON_PM, 8000L ),

A("Catherine's Sexuality",				ORCISH_CLOAK, /* initialized to always be a birthcloth; if you have children while wearing it, you instantly die of complications. */
	(SPFX_RESTR|SPFX_HSPDAM|SPFX_HPHDAM|SPFX_REFLECT), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 3500L ),

A("Pokewalker",				ORCISH_CLOAK, /* initialized to always be a poke mongo cloak; displays all pokemon on the level */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Winds of Change",				ORCISH_CLOAK, /* initialized to always be a levuntation cloak; confusing problem, occasionally increases movement speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2500L ),

A("Lightspeed Travel",				ORCISH_CLOAK, /* initialized to always be a quicktravel cloak; nomul(0,0) will not do anything, blinking speed */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("T-O-M-E",				ORCISH_CLOAK, /* initialized to always be an angband cloak; upon entering a level you've not been to yet, you will either get a princess or fumblefingers effect. */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 4000L ),

A("Femmy Fatale",				ORCISH_CLOAK, /* initialized to always be an anorexia cloak; weakness problem, diarrhea, monsters do not spawn corpses, slow digestion */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_LAWFUL, NON_PM, NON_PM, 8000L ),

A("Artificial Fake Difficulty",				ORCISH_CLOAK, /* initialized to always be a dnethack cloak; weaker form of failed existence effects, halves experience point gains, techniques become re-usable in half the usual amount of time */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2000L ),

A("Junethack 2016 Winner",				ORCISH_CLOAK, /* initialized to always be a team splat cloak; every time you get a trophy while wearing it, you gain +10 max HP and Pw */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 8000L ),

A("Yog-Sothoth Help Me",				ORCISH_CLOAK, /* initialized to always be an eldritch cloak; psi resistance */
	(SPFX_RESTR), 0, 0,
	NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 2400L ),

/*
 *	Stormbringer only has a 2 because it can drain a level,
 *	providing 8 more.
 */
A("Stormbringer",               RUNESWORD,
	(SPFX_RESTR|SPFX_ATTK|SPFX_DEFN|SPFX_INTEL|SPFX_DRLI), 0, 0,
	DRLI(5,1),	DRLI(0,0),	NO_CARY,	0, A_CHAOTIC, NON_PM, NON_PM, 8000L ),


A("Reaver",			SCIMITAR,
	(SPFX_RESTR|SPFX_INTEL),0,0,
	PHYS(5,4),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, PM_PIRATE, NON_PM, 6000L ),

#ifdef BLACKMARKET
A("Thiefbane",                  LONG_SWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_BEHEAD|SPFX_DCLAS|SPFX_DRLI), 0, S_HUMAN,
	DRLI(5,1),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 1500L ),
#endif /* BLACKMARKET */

A("Deathsword",                   TWO_HANDED_SWORD,
	(SPFX_RESTR|SPFX_DFLAG2), 0, M2_HUMAN,
	PHYS(5,7),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_BARBARIAN, NON_PM, 5000L ),

A("Bat from Hell",                BASEBALL_BAT,
	(SPFX_RESTR), 0, 0,
	PHYS(3,10),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_ROGUE, NON_PM, 5000L ),

A("Elfrist",                    ORCISH_SPEAR,
	SPFX_DFLAG2, 0, M2_ELF,
	PHYS(5,8),     NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_HUMAN_WEREWOLF, PM_ORC, 300L ),

A("Plague", DARK_ELVEN_BOW,	/* KMH */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	PHYS(5,4),        DFNS(AD_DRST),  NO_CARY,        0, A_CHAOTIC, PM_DROW, NON_PM, 6000L ),
	/* Auto-poison code in dothrow.c */


A("Mumakbane",			LONG_SWORD,
	(SPFX_RESTR|SPFX_DMONS), 0, PM_MUMAK,
	FIRE(5,30),	NO_DFNS,	NO_CARY,
	0, 		A_NEUTRAL,	NON_PM, NON_PM, 500L ),

A("Wormbiter",			CRYSKNIFE,
	(SPFX_RESTR|SPFX_DCLAS), 0, S_WORM,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0,		A_NEUTRAL,	NON_PM, NON_PM, 2000L ),

A("Shocker",			ELECTRIC_SWORD,
	SPFX_RESTR, 0, 0,
	ELEC(3,0),	NO_DFNS,	NO_CARY,
	0,		A_NEUTRAL,	NON_PM, NON_PM, 1000L ),

A("Scales of the Dragon Lord",	GRAY_DRAGON_SCALE_MAIL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_PROTEC), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	DRAGON_BREATH,	A_CHAOTIC,	NON_PM, NON_PM, 5000L ),

A("The Burned Moth Relay",	RELAY,
	(SPFX_RESTR), SPFX_PROTEC, 0, 	
	NO_ATTK,	NO_DFNS,	NO_CARY,
	0,		A_NEUTRAL,	NON_PM, NON_PM, 200L ),

A("The Key Of Access",		SKELETON_KEY,
	(SPFX_RESTR|SPFX_NOGEN),	0,		0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	CREATE_PORTAL,	A_NONE,		NON_PM, NON_PM, 200L ),

A("Hellfire", CROSSBOW,	/* WAC */
	(SPFX_RESTR|SPFX_DEFN), 0, 0,
	PHYS(5,4),        FIRE(0,0),  NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 4000L ),
	/* Auto-explode code in dothrow.c, uhitm.c */

A("Houchou",                SPOON,
	(SPFX_RESTR), 0, 0,
        NO_ATTK,      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, NON_PM, NON_PM, 50000L ),

/*** Special Artifacts ***/

/* KMH -- made it a bag of holding */
A("Wallet of Perseus",       BAG_OF_HOLDING,
        (SPFX_RESTR), 0, 0,
        NO_ATTK,        NO_DFNS,        NO_CARY,
        0,      A_NONE, NON_PM, NON_PM, 10000L ),

A("Nighthorn", UNICORN_HORN,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_REFLECT), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,      A_LAWFUL, NON_PM, NON_PM, 10000L ),

A("The Key of Law", SKELETON_KEY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,      A_LAWFUL, NON_PM, NON_PM, 1000L ),

A("The Eye of the Beholder", EYEBALL,
	(SPFX_NOGEN|SPFX_RESTR), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	DEATH_GAZE,     A_NEUTRAL, NON_PM, NON_PM, 500L ),

A("The Key of Neutrality", SKELETON_KEY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,      A_NEUTRAL, NON_PM, NON_PM, 1000L ),

A("The Hand of Vecna",       SEVERED_HAND,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_REGEN|SPFX_HPHDAM), 0, 0,
	NO_ATTK,        DRLI(0,0),      CARY(AD_COLD),
	SUMMON_UNDEAD,          A_CHAOTIC, NON_PM, NON_PM, 700L ),

A("The Key of Chaos", SKELETON_KEY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,      A_CHAOTIC, NON_PM, NON_PM, 1000L ),

A("The Gauntlet Key", SKELETON_KEY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,      A_LAWFUL, NON_PM, NON_PM, 1000L ),


/*** The artifacts for the quest dungeon, all self-willed ***/

A("The Orb of Detection",	CRYSTAL_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_ESP|SPFX_HSPDAM), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	INVIS,		A_LAWFUL, PM_ARCHEOLOGIST, NON_PM, 2500L ),

A("The Ball of Light",	CRYSTAL_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_ESP|SPFX_HSPDAM), 0,
	NO_ATTK,	DFNS(AD_BLND),	CARY(AD_MAGM),
	LIGHT_AREA,		A_LAWFUL, PM_ERDRICK, NON_PM, 2500L ),

A("The Heart of Ahriman",	LUCKSTONE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), SPFX_STLTH, 0,
	/* this stone does double damage if used as a projectile weapon */
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	LEVITATION,	A_NEUTRAL, PM_BARBARIAN, NON_PM, 2500L ),

A("The Arkenstone",	DIAMOND,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), SPFX_ESP, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	HEALING,	A_LAWFUL, PM_MIDGET, NON_PM, 2500L ),

A("The Sceptre of Might",	MACE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DALIGN), 0, 0,
	PHYS(3,3),      NO_DFNS,        CARY(AD_MAGM),
	CONFLICT,	A_LAWFUL, PM_CAVEMAN, NON_PM, 2500L ),

A("Mysterious Spikes",	TAIL_SPIKES,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DALIGN|SPFX_XRAY), 0, 0,
	PHYS(30,30),      NO_DFNS,        CARY(AD_MAGM),
	HEALING,	A_LAWFUL, PM_MYSTIC, NON_PM, 200000L ),

A("The Iron Ball of Liberation", HEAVY_IRON_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL),
		(SPFX_STLTH|SPFX_SEARCH|SPFX_WARN), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	PHASING,	A_NEUTRAL, PM_PRISONER, NON_PM, 5000L ),

A("Pitch Blade",			BROADSWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_TCTRL|SPFX_INTEL),0,0,
	PHYS(5,3),	NO_DFNS,	NO_CARY,	0, A_CHAOTIC, PM_MURDERER, NON_PM, 3000L ),

#if 0	/* OBSOLETE */
A("The Palantir of Westernesse",	CRYSTAL_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL),
		(SPFX_ESP|SPFX_REGEN|SPFX_HSPDAM), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	TAMING,		A_CHAOTIC, NON_PM , PM_ELF, 8000L ),
#endif

/* STEPHEN WHITE'S NEW CODE */

/* Let's reintroduce the elf role. --Amy */
A("The Palantir of Westernesse",	CRYSTAL_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL),
		(SPFX_ESP|SPFX_REGEN|SPFX_HSPDAM), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	TAMING,		A_CHAOTIC, PM_ELPH , NON_PM, 8000L ),

A("Rocker Sling",                SLING,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DFLAG2), 0, M2_GIANT,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, PM_ROCKER, NON_PM, 800L ),

A("Liontamer",                BULLWHIP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DCLAS), 0, S_FELINE,
	PHYS(5,8),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, PM_ZOOKEEPER, NON_PM, 800L ),

A("Dragonclan Sword",                KATANA,
	(SPFX_RESTR|SPFX_BEHEAD|SPFX_INTEL), 0, 0,
	PHYS(3,10),      NO_DFNS,        NO_CARY,        0, A_LAWFUL, PM_NINJA, NON_PM, 5000L ),

A("Killing Edge",                KATANA,
	(SPFX_RESTR|SPFX_BEHEAD|SPFX_INTEL), 0, 0,
	PHYS(3,3),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_ASSASSIN, NON_PM, 5000L ),

A("Black Death",                     HALBERD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	DRLI(5,5),      NO_DFNS,        NO_CARY,        0, A_CHAOTIC, PM_UNDERTAKER, NON_PM, 3000L ),

A("Slow Blade",                ORCISH_SHORT_SWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_SEARCH|SPFX_REGEN ), 0,
	PHYS(2,1),      NO_DFNS,        NO_CARY,        HEALING, A_LAWFUL, PM_ACID_MAGE, NON_PM, 1000L ),

A("Fire-Brigade Reel",                RUBBER_HOSE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_HSPDAM|SPFX_HPHDAM ), 0,
	COLD(4,4),      NO_DFNS,        NO_CARY,        SUMMON_WATER_ELEMENTAL, A_LAWFUL, PM_FIREFIGHTER, NON_PM, 2000L ),

A("The Candle of Eternal Flame",        MAGIC_CANDLE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_WARN|SPFX_TCTRL), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_COLD),
	SUMMON_FIRE_ELEMENTAL,         A_NEUTRAL, PM_FLAME_MAGE, NON_PM, 50000L ),

A("The Nethack Sources",	PACK_OF_FLOPPIES,
	(SPFX_NOGEN | SPFX_RESTR | SPFX_INTEL),
		 (SPFX_SEARCH | SPFX_ESP | SPFX_REGEN), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	IDENTIFY,	A_NEUTRAL,	PM_GEEK, NON_PM, 5000L ),

A("Master Boot Disk",	PACK_OF_FLOPPIES,
	(SPFX_NOGEN | SPFX_RESTR | SPFX_INTEL),
		 (SPFX_REFLECT), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	PHASING,	A_NEUTRAL,	PM_GRADUATE, NON_PM, 5000L ),

A("The Lyre of Orpheus",	WOODEN_HARP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK), 0, 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	TAMING,		A_NEUTRAL, PM_BARD, NON_PM, 5000L ),

A("Operational Scalpel",	SCALPEL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_ATTK|SPFX_INTEL|SPFX_DRLI|SPFX_REGEN), 0,0,
	DRLI(3,0),      NO_DFNS,        NO_CARY,
	HEALING,	A_NEUTRAL, PM_SCIENTIST, NON_PM, 5000L ),

A("The Staff of Aesculapius",	QUARTERSTAFF,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_ATTK|SPFX_INTEL|SPFX_DRLI|SPFX_REGEN), 0,0,
	DRLI(3,0),      NO_DFNS,        NO_CARY,
	HEALING,	A_NEUTRAL, PM_HEALER, NON_PM, 5000L ),

A("The Tentacle Staff",	QUARTERSTAFF,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_ATTK|SPFX_INTEL|SPFX_WARN|SPFX_STLTH), 0,0,
	ELEC(8,0),      NO_DFNS,        NO_CARY,
	CHARGE_OBJ,	A_CHAOTIC, PM_TWELPH, NON_PM, 5000L ),

/* STEPHEN WHITE'S NEW CODE */
A("The Storm Whistle",          MAGIC_WHISTLE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_WARN|SPFX_TCTRL), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_FIRE),
	SUMMON_WATER_ELEMENTAL,         A_LAWFUL, PM_ICE_MAGE, NON_PM, 1000L ),

A("The Thunder Whistle",          MAGIC_WHISTLE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_WARN|SPFX_TCTRL), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_ELEC),
	0,         A_CHAOTIC, PM_ELECTRIC_MAGE, NON_PM, 1000L ),

A("Immunity Ring",          RIN_SICKNESS_RESISTANCE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN), (SPFX_ESP), 0,
	NO_ATTK,        DFNS(AD_MAGM),        CARY(AD_DRLI),
	CHARGE_OBJ,         A_NEUTRAL, PM_POISON_MAGE, NON_PM, 1000L ),

A("Blackharp",          MAGIC_HARP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_WARN|SPFX_TCTRL), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_DRLI),
	0,         A_CHAOTIC, PM_MUSICIAN, NON_PM, 1000L ),

A("The Magic Mirror of Merlin", MIRROR,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK), SPFX_ESP, 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_COLD),
	0,		A_LAWFUL, PM_KNIGHT, NON_PM, 1500L ),

A("The Magic Mirror of Arthubert", MIRROR,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK), SPFX_HSPDAM, 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_STUN),
	0,		A_LAWFUL, PM_CHEVALIER, NON_PM, 1500L ),

A("Magic Mirror of Jason", MIRROR,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK), SPFX_HPHDAM, 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	0,		A_LAWFUL, PM_WARRIOR, NON_PM, 1500L ),

A("Chekhov's Gun", PISTOL,	/* KMH */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0,
	PHYS(5,4),        DFNS(AD_DRST),  NO_CARY,        0, A_CHAOTIC, PM_GANGSTER, NON_PM, 6000L ),

A("Shiny Magnum", PISTOL,	/* KMH */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0,
	PHYS(10,8),        DFNS(AD_DETH),  NO_CARY,        0, A_LAWFUL, PM_OFFICER, NON_PM, 10000L ),

A("Withered Nine Millimeter", PISTOL,	/* KMH */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0,
	PHYS(5,4),        NO_DFNS,  NO_CARY,        0, A_NEUTRAL, PM_COURIER, NON_PM, 3000L ),

A("Training SMG", SUBMACHINE_GUN,	/* KMH */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_DEFN|SPFX_INTEL), 0, 0,
	PHYS(5,4),        NO_DFNS,  NO_CARY,        ENLIGHTENING, A_NEUTRAL, PM_INTEL_SCRIBE, NON_PM, 3000L ),

A("Charged USB stick", INSECT_SQUASHER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,        NO_DFNS,  NO_CARY,        CHARGE_OBJ, A_NEUTRAL, PM_WANDKEEPER, NON_PM, 3000L ),

A("Verbal Blade",		ELVEN_SHORT_SWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_BEHEAD), 0, 0,
	PHYS(5,1),	NO_DFNS,	NO_CARY,	0, A_NEUTRAL, PM_ZYBORG, NON_PM, 3000L ),

A("Tome Dark Sword",		BLACK_AESTIVALIS,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM|SPFX_HPHDAM|SPFX_ESP|SPFX_STLTH), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,	ENLIGHTENING, A_NEUTRAL, PM_UNBELIEVER, NON_PM, 1000L ),

A("The Elder Staff",	QUARTERSTAFF,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_ATTK|SPFX_INTEL|SPFX_DRLI|SPFX_REGEN), 0,0,
	DRLI(6,0),      NO_DFNS,        NO_CARY,
	0,	A_CHAOTIC, PM_DEATH_EATER, NON_PM, 5000L ),

A("Gauntlets of Illusion",    GAUNTLETS_OF_DEXTERITY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), SPFX_HALRES, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,    INVIS, A_NEUTRAL, PM_POKEMON, NON_PM, 5000L ),

A("Lovely Pink Pumps",    FEMININE_PUMPS,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), SPFX_REGEN, 0,
	NO_ATTK,        DRLI(0,0),        NO_CARY,    INVIS, A_NEUTRAL, PM_TRANSVESTITE, NON_PM, 5000L ),

A("Kiss Boots",    HIPPIE_HEELS,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM|SPFX_HPHDAM), SPFX_EREGEN, 0,
	NO_ATTK,        DRLI(0,0),        NO_CARY,    IDENTIFY, A_NEUTRAL, PM_TRANSSYLVANIAN, NON_PM, 5000L ),

A("Golden High Heels",    LEATHER_PEEP_TOES,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), SPFX_STLTH, 0,
	NO_ATTK,        ACID(0,0),        NO_CARY,    LEVITATION, A_NEUTRAL, PM_TOPMODEL, NON_PM, 5000L ),

A("Unobtainable Beauties",    SENTIENT_HIGH_HEELS,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_WARN|SPFX_REFLECT|SPFX_SPEAK), SPFX_REGEN, 0,
	NO_ATTK,        ACID(0,0),        NO_CARY,    HEALING, A_NEUTRAL, PM_FAILED_EXISTENCE, NON_PM, 5000L ),

A("Activist Stick",			FLY_SWATTER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DCLAS), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,	0, A_LAWFUL, PM_ACTIVISTOR, NON_PM, 4800L ),

A("The Eyes of the Overworld",	LENSES,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_XRAY), 0, 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	ENLIGHTENING,	A_NEUTRAL,	 PM_MONK, NON_PM, 2500L ),

A("Gauntlets of Offense",    GAUNTLETS_OF_POWER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), SPFX_HPHDAM, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,    INVIS, A_NEUTRAL, PM_PSION, NON_PM, 5000L ),

A("the Pen of the Void",	ATHAME,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0,	A_NEUTRAL, PM_BINDER, NON_PM, 2500L),

A("Bloody Beauty",	BLOCK_HEELED_COMBAT_BOOT,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	DRLI(4,2),	NO_DFNS,	NO_CARY,
	0,	A_NEUTRAL, PM_BLEEDER, NON_PM, 2500L),

A("Goffic Backpack",	SACK,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL),
		 (SPFX_HSPDAM|SPFX_HPHDAM|SPFX_REGEN), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	ENERGY_BOOST,	A_NEUTRAL,	PM_GOFF, NON_PM, 5000L ),

A("The Mantle of Heaven",	LEATHER_CLOAK, /*Actually an ornamental cope in game*/
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM), 0, 0,
	NO_ATTK,	ELEC(0,0),	COLD(0,0), /* Plus double AC bonus */
	0,	A_LAWFUL,	 PM_NOBLEMAN, NON_PM, 2500L),

A("The Vestment of Hell",	LEATHER_CLOAK, /*Actually an opera cloak in game*/
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM), 0, 0,
	NO_ATTK,	ACID(0,0),	FIRE(0,0), /* Plus double AC bonus */
	0,	A_CHAOTIC,	 PM_NOBLEMAN, NON_PM, 2500L),

A("The Cloak of Neutrality",	LEATHER_CLOAK, /*Actually an opera cloak in game*/
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_EREGEN), 0, 0,
	NO_ATTK,	DRLI(0,0),	ACID(0,0), /* Plus double AC bonus */
	0,	A_NEUTRAL,	 PM_DRUNK, NON_PM, 2500L),

A("The Great Dagger of Glaurgnaa",       GREAT_DAGGER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_ATTK|SPFX_INTEL|SPFX_DRLI|SPFX_DALIGN), 0, 0,
	DRLI(8,2),      NO_DFNS,        CARY(AD_MAGM),
	ENERGY_BOOST,   A_CHAOTIC, PM_NECROMANCER, NON_PM, 50000L ),

A("The Mitre of Holiness",	HELM_OF_BRILLIANCE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_DFLAG2|SPFX_INTEL), 0, M2_UNDEAD,
	NO_ATTK,	NO_DFNS,	CARY(AD_FIRE),
	ENERGY_BOOST,	A_LAWFUL, PM_PRIEST, NON_PM, 2000L ),

A("Painkiller",        STEEL_WHIP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DFLAG2), 0, M2_HUMAN,
	PHYS(12,12),    NO_DFNS,        CARY(AD_MAGM),
	0,              A_CHAOTIC, PM_CRUEL_ABUSER, NON_PM, 5000L ),

A("Dragon Whip",                  BULLWHIP,
	(SPFX_RESTR|SPFX_NOGEN|SPFX_DEFN|SPFX_INTEL|SPFX_ATTK|SPFX_DFLAG2),0,M2_DOMESTIC,
	PHYS(5,5),	DFNS(AD_FIRE),	NO_CARY,	DRAGON_BREATH, A_CHAOTIC, PM_SLAVE_MASTER, NON_PM, 4000L ),

A("Rupturer",                  RUNESWORD,
	(SPFX_RESTR|SPFX_NOGEN|SPFX_WARN|SPFX_INTEL|SPFX_ATTK),0,0,
	PHYS(3,7),	DFNS(AD_COLD),	NO_CARY,	DRAGON_BREATH, A_CHAOTIC, PM_BLOODSEEKER, NON_PM, 4000L ),

A("Blood Marker",        KNIFE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_HSPDAM), 0, 0,
	NO_ATTK,    DFNS(AD_MAGM),        NO_CARY,
	IDENTIFY,              A_NEUTRAL, PM_LIBRARIAN, NON_PM, 5000L ),

A("Cutthroat Blade",        CRYSKNIFE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_BEHEAD), 0, 0,
	NO_ATTK,    DFNS(AD_MAGM),        NO_CARY,
	DEATH_GAZE,              A_NEUTRAL, PM_PICKPOCKET, NON_PM, 5000L ),

A("Sharpened Toothpick",        GREAT_DAGGER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SEEK|SPFX_SEARCH), 0, 0,
	PHYS(8,8),    NO_DFNS,        NO_CARY,
	0,              A_NEUTRAL, PM_BULLY, NON_PM, 5000L ),

A("Kitchen Cutter",        KNIFE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DFLAG2), 0, M2_STRONG,
	PHYS(6,6),    NO_DFNS,        NO_CARY,
	0,              A_NEUTRAL, PM_COOK, NON_PM, 3000L ),

A("Archon Staff",        BATTLE_STAFF,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DFLAG2), SPFX_EREGEN, M2_DEMON,
	PHYS(10,10),    NO_DFNS,        NO_CARY,
	OBJ_DETECTION,              A_LAWFUL, PM_AUGURER, NON_PM, 3000L ),

A("Shillelagh",        BATTLE_STAFF,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DFLAG2), SPFX_EREGEN, M2_NASTY,
	PHYS(16,4),    NO_DFNS,        NO_CARY,
	LIGHT_AREA,              A_LAWFUL, PM_SAGE, NON_PM, 3000L ),

A("Altar Carver",        ATHAME,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK|SPFX_DRLI|SPFX_DFLAG2), 0, M2_STALK,
	PHYS(8,8),    NO_DFNS,        NO_CARY,
	SUMMON_UNDEAD,              A_LAWFUL, PM_OTAKU, NON_PM, 3000L ),

A("Mirage Tail",        ROTATING_CHAIN,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN), 0, 0,
	PHYS(4,4),    DFNS(AD_FIRE),        NO_CARY,
	DRAGON_BREATH,              A_NEUTRAL, PM_ARTIST, NON_PM, 5000L ),

A("Game Disc",        SPOON,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN|SPFX_HPHDAM), 0, 0,
	NO_ATTK,    DFNS(AD_FIRE),        NO_CARY,
	0,              A_NEUTRAL, PM_GAMER, NON_PM, 5000L ),

A("Modified Z-Sword",        PICK_AXE, /* sorry Bug Sniper, I'm too lazy coding a sword to work as a pick-axe. :( Good idea though. --Amy */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(8,4),    NO_DFNS,        NO_CARY,
	ENERGY_BOOST,              A_LAWFUL, PM_SAIYAN, NON_PM, 5000L ),

A("The Pick of Flandal Steelskin",        PICK_AXE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM), 0, 0,
	NO_ATTK,    NO_DFNS,        NO_CARY,
	0,              A_NEUTRAL, PM_GOLDMINER, NON_PM, 5000L ),

A("Prime Minister's Tuxedo",	T_SHIRT,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM|SPFX_DEFN), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	0,	A_LAWFUL, PM_POLITICIAN, NON_PM, 2000L ),

A("Slowness Shirt",	HAWAIIAN_SHIRT,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM|SPFX_DEFN), 0, 0,
	NO_ATTK,	DFNS(AD_DRLI),	NO_CARY,
	0,	A_LAWFUL, PM_LADIESMAN, NON_PM, 2000L ),

A("Coat of Style",	LEATHER_JACKET,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM|SPFX_DEFN), 0, 0,
	NO_ATTK,	DFNS(AD_ACID),	NO_CARY,
	ENLIGHTENING,	A_CHAOTIC, PM_FEAT_MASTER, NON_PM, 2000L ),

A("Carbon Nanotube Suit",	LEATHER_ARMOR,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM|SPFX_DEFN), 0, 0,
	NO_ATTK,	DFNS(AD_MAGM),	NO_CARY,
	UNTRAP,	A_CHAOTIC, PM_GUNNER, NON_PM, 2000L ),

A("Brutal Chainsaw",	CHAINSWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_ATTK), 0, 0,
	PHYS(10,10),	NO_DFNS,	NO_CARY,
	CREATE_PORTAL,	A_NEUTRAL, PM_DOOM_MARINE, NON_PM, 4000L ),

A("The Treasury of Proteus",	CHEST,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_LUCK), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	0,	A_CHAOTIC,	 PM_PIRATE, NON_PM, 2500L ),

A("Portchest",	CHEST,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	CREATE_PORTAL,	A_LAWFUL,	 PM_FOXHOUND_AGENT, NON_PM, 2500L ),

A("Saint Something Four Crystal",	DILITHIUM_CRYSTAL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_REGEN|SPFX_EREGEN|SPFX_REFLECT), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	TAMING,	A_NEUTRAL,	 PM_MAHOU_SHOUJO, NON_PM, 12500L ),

A("Master Ball",	REALLY_HEAVY_IRON_BALL, /* bad effects when wielded */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_REGEN|SPFX_EREGEN|SPFX_REFLECT), 0, 0,
	PHYS(16,16),	DFNS(AD_MAGM),	NO_CARY,
	TAMING,	A_NEUTRAL,	 PM_DOLL_MISTRESS, NON_PM, 50000L ),

A("The One Ring",	RIN_INVISIBILITY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_REGEN|SPFX_EREGEN|SPFX_REFLECT), 0, 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	CREATE_PORTAL,	A_LAWFUL,	 PM_RINGSEEKER, NON_PM, 50000L ),

A("Imperial Token", FEDORA, /* sorry Fyr, making the rings work correctly would be a major pain in the butt --Amy */
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN), 0, 0,
	NO_ATTK,       DRLI(0,0),        NO_CARY,
	0,  A_NEUTRAL, PM_GLADIATOR, NON_PM, 2000L ),

A("The Pearl of Wisdom", FEDORA,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM), 0, 0,
	NO_ATTK,       NO_DFNS,        NO_CARY,
	0,  A_NEUTRAL, PM_KORSAIR, NON_PM, 2000L ),

A("Maui's Fishhook",	GRAPPLING_HOOK,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM|SPFX_WARN|SPFX_SEEK|SPFX_DCLAS), 0, S_EEL,
	PHYS(10,0),        NO_DFNS,        NO_CARY,
	0,		A_CHAOTIC, PM_DIVER, NON_PM, 4500L ),


A("Helm of Storms", HELMET,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM), 0, 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_MAGM),
	0,  A_NEUTRAL, PM_SPACEWARS_FIGHTER, NON_PM, 5000L ),

A("Amulet of Kings", AMULET_OF_DRAIN_RESISTANCE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	CREATE_PORTAL,  A_LAWFUL, PM_CAMPERSTRIKER, NON_PM, 1000L ),

A("The Longbow of Diana", BOW,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_REFLECT), SPFX_ESP, 0,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	CREATE_AMMO, A_CHAOTIC, PM_RANGER, NON_PM, 4000L ),

A("Heffer's Bow", BOW,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_WARN|SPFX_REGEN|SPFX_EREGEN), 0, 0,
	PHYS(6,0),	NO_DFNS,	NO_CARY,
	CREATE_AMMO, A_LAWFUL, PM_DRUID, NON_PM, 8000L ),

A("Gunbow", BOW,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HPHDAM), SPFX_EREGEN, 0,
	ELEC(7,0),	DRLI(0,0),	NO_CARY,
	CREATE_AMMO, A_NEUTRAL, PM_AMAZON, NON_PM, 4000L ),

A("The Master Key of Thievery", SKELETON_KEY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK),
		(SPFX_WARN|SPFX_TCTRL|SPFX_HPHDAM), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	UNTRAP,		A_CHAOTIC, PM_ROGUE, NON_PM, 3500L ),

A("Nocturnal Key", SKELETON_KEY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_SPEAK),
		(SPFX_SEEK|SPFX_HALRES|SPFX_LUCK), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	CREATE_PORTAL,		A_CHAOTIC, PM_LOCKSMITH, NON_PM, 3500L ),

A("The Tsurugi of Muramasa",	TSURUGI,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_BEHEAD|SPFX_LUCK), 0, 0,
	NO_ATTK,        NO_DFNS,        NO_CARY,
	0,		A_LAWFUL, PM_SAMURAI, NON_PM, 4500L ),

A("Vivec Blade",	TSURUGI,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_LUCK), 0, 0,
	PHYS(8,4),        NO_DFNS,        NO_CARY,
	0,		A_NEUTRAL, PM_ORDINATOR, NON_PM, 4500L ),

A("Summoned Sword",                ELVEN_BROADSWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_STLTH|SPFX_REGEN ), 0,
	PHYS(4,4),      NO_DFNS,        NO_CARY,        DRAGON_BREATH, A_CHAOTIC, PM_THALMOR, NON_PM, 3000L ),

A("Bow of Vines", ELVEN_BOW,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_LUCK), SPFX_ESP, 0,
	STUN(7,5),	NO_DFNS,	NO_CARY,
	ENERGY_BOOST, A_NEUTRAL, PM_BOSMER, NON_PM, 4000L ),

A("Ambassador Robe",	ROBE_OF_WEAKNESS,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_HSPDAM|SPFX_HPHDAM), SPFX_EREGEN, 0,
	NO_ATTK,	DRLI(0,0),	CARY(AD_MAGM),
	CREATE_PORTAL,	A_CHAOTIC,	 PM_ALTMER, NON_PM, 2500L),

A("N'wah Killer",        ELVEN_BROADSWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(5,6),    NO_DFNS,        CARY(AD_MAGM),
	0,              A_LAWFUL, PM_DUNMER, NON_PM, 5000L ),

A("Supreme Justice Keeper",		TWO_HANDED_SWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_LUCK|SPFX_PROTEC|SPFX_INTEL|SPFX_DALIGN), 0, A_NONE,
	PHYS(5,0),	NO_DFNS,	NO_CARY,
	0, 		A_LAWFUL, PM_JUSTICE_KEEPER, NON_PM, 200L ),

A("The Holydirk",		ATHAME,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_REFLECT|SPFX_INTEL|SPFX_DFLAG2), SPFX_HPHDAM, M2_UNDEAD,
	PHYS(5,0),	NO_DFNS,	CARY(AD_MAGM),
	0,	A_LAWFUL, PM_MEDIUM, NON_PM, 1500L ),

A("The Charmpoint",		SILVER_DAGGER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_REFLECT|SPFX_INTEL|SPFX_DFLAG2), SPFX_HPHDAM, M2_UNDEAD,
	PHYS(5,0),	NO_DFNS,	CARY(AD_MAGM),
	TAMING,	A_CHAOTIC, PM_SEXYMATE, NON_PM, 1500L ),

A("The Silver Crystal",		DILITHIUM_CRYSTAL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_ESP|SPFX_REGEN|SPFX_DBONUS), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	HEALING,	A_LAWFUL, PM_FIGHTER, NON_PM, 8000L ),

A("The Red Stone of Eigia",		RUBY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_WARN|SPFX_DRLI), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_FIRE),
	OBJ_DETECTION,	A_NEUTRAL, PM_STAND_USER, NON_PM, 1000L ),

A("The Fortune Sword",			SHORT_SWORD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_LUCK),
		(SPFX_ESP|SPFX_DBONUS), 0,
	PHYS(3,4),	NO_DFNS,	CARY(AD_MAGM),
	0,	A_NEUTRAL,	PM_FENCER, NON_PM, 10000L ),

# ifdef TOURIST
A("The Platinum Yendorian Express Card", CREDIT_CARD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN),
		(SPFX_ESP|SPFX_HSPDAM), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	CHARGE_OBJ,	A_NEUTRAL, PM_TOURIST, NON_PM, 7000L ),
# endif

A("Credex Gold", CREDIT_CARD,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_DEFN),
		(SPFX_STLTH|SPFX_TCTRL), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	CHARGE_OBJ,	A_NEUTRAL, PM_SUPERMARKET_CASHIER, NON_PM, 7000L ),

/* KMH -- More effective against normal monsters
 * Was +10 to-hit, +d20 damage only versus vampires
 */
A("The Stake of Van Helsing",        WOODEN_STAKE,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(5,6),    NO_DFNS,        CARY(AD_MAGM),
	0,              A_LAWFUL, PM_UNDEAD_SLAYER, NON_PM, 5000L ),

A("Vampire Killer",        BULLWHIP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(5,6),    NO_DFNS,        CARY(AD_MAGM),
	0,              A_LAWFUL, PM_LUNATIC, NON_PM, 5000L ),

A("Itchalaquiaque",        DROVEN_DAGGER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), 0, 0,
	PHYS(5,6),    NO_DFNS,        CARY(AD_MAGM),
	0,              A_LAWFUL, PM_ANACHRONIST, NON_PM, 5000L ),

A("The Orb of Fate",		CRYSTAL_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_LUCK),
		(SPFX_WARN|SPFX_HSPDAM|SPFX_HPHDAM), 0,
	NO_ATTK,	NO_DFNS,	NO_CARY,
	LEV_TELE,	A_NEUTRAL, PM_VALKYRIE, NON_PM, 3500L ),

A("The Orb of Resistance",		CRYSTAL_BALL,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL),
		(SPFX_WARN|SPFX_HSPDAM|SPFX_HPHDAM), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	LIGHT_AREA,	A_NEUTRAL, PM_PALADIN, NON_PM, 3500L ),

A("The Eye of the Aethiopica",	AMULET_OF_ESP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_EREGEN|SPFX_HSPDAM), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	CREATE_PORTAL,	A_NEUTRAL, PM_WIZARD, NON_PM, 4000L ),

A("The Medallion of Shifters",	AMULET_OF_ESP,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_EREGEN|SPFX_HPHDAM), 0,
	NO_ATTK,	NO_DFNS,	CARY(AD_MAGM),
	LEV_TELE,	A_NEUTRAL, PM_SHAPESHIFTER, NON_PM, 4000L ),

A("The King's Stolen Crown", HELM_OF_OPPOSITE_ALIGNMENT,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_HSPDAM|SPFX_HPHDAM), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_MAGM),
	LEV_TELE,  A_LAWFUL, PM_JESTER, NON_PM, 5000L ),

A("The Slime Crown", HELM_OF_STORMS,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_HSPDAM|SPFX_HPHDAM), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_MAGM),
	LEV_TELE,  A_CHAOTIC, PM_DQ_SLIME, NON_PM, 5000L ),

#ifdef YEOMAN
A("The Crown of Saint Edward", HELM_OF_TELEPATHY,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL), (SPFX_HSPDAM), 0,
	NO_ATTK,        NO_DFNS,        CARY(AD_MAGM),
	0,  A_LAWFUL, PM_YEOMAN, NON_PM, 5000L ),
#endif

A("The Lightsaber Prototype", RED_LIGHTSABER,
	(SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL|SPFX_REFLECT), 0, 0,
	PHYS(5, 5),	NO_DFNS, NO_CARY,
	ENERGY_BOOST,	A_LAWFUL, PM_JEDI, NON_PM, 3500L ),

/*
 *  terminator; otyp must be zero
 */
A(0, 0, 0, 0, 0, NO_ATTK, NO_DFNS, NO_CARY, 0, A_NONE, NON_PM, NON_PM, 0L )

};	/* artilist[] (or artifact_names[]) */

#undef	A

#ifndef MAKEDEFS_C
#undef	NO_ATTK
#undef	NO_DFNS
#undef	DFNS
#undef	PHYS
#undef	DRLI
#undef	COLD
#undef	FIRE
#undef	ELEC
#undef	STUN
#endif

/*artilist.h*/
