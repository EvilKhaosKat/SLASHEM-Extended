/*	SCCS Id: @(#)prop.h	3.4	1999/07/07	*/
/* Copyright (c) 1989 Mike Threepoint				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef PROP_H
#define PROP_H

/*** What the properties are ***/
#define FIRE_RES		 1
#define COLD_RES		 2
#define SLEEP_RES		 3
#define DISINT_RES		 4
#define SHOCK_RES		 5
#define POISON_RES		 6
#define ACID_RES		 7
#define STONE_RES		 8
/* note: for the first eight properties, MR_xxx == (1 << (xxx_RES - 1)) */
#define ADORNED			 9
#define REGENERATION		10
#define SEARCHING		11
#define SEE_INVIS		12
#define INVIS			13
#define TELEPORT		14
#define TELEPORT_CONTROL	15
#define POLYMORPH		16
#define POLYMORPH_CONTROL	17
#define LEVITATION		18
#define STEALTH			19
#define AGGRAVATE_MONSTER	20
#define CONFLICT		21
#define PROTECTION		22
#define PROT_FROM_SHAPE_CHANGERS 23
#define WARNING			24
#define TELEPAT			25
#define FAST			26
#define STUNNED			27
#define CONFUSION		28
#define SICK			29
#define BLINDED			30
#define SLEEPING		31
#define WOUNDED_LEGS		32
#define STONED			33
#define STRANGLED		34
#define HALLUC			35
#define HALLUC_RES		36
#define FUMBLING		37
#define JUMPING			38
#define WWALKING		39
#define HUNGER			40
#define GLIB			41
#define REFLECTING		42
#define LIFESAVED		43
#define ANTIMAGIC		44
#define DISPLACED		45
#define CLAIRVOYANT		46
#define VOMITING		47
#define ENERGY_REGENERATION	48
#define MAGICAL_BREATHING	49
#define HALF_SPDAM		50
#define HALF_PHDAM		51
#define SICK_RES		52
#define DRAIN_RES		53
#define WARN_UNDEAD		54
#define INVULNERABLE		55
#define FREE_ACTION		56
#define SWIMMING		57
#define SLIMED			58
#define FIXED_ABIL		59
#define FLYING			60
#define UNCHANGING		61
#define PASSES_WALLS		62
#define SLOW_DIGESTION		63
#define INFRAVISION		64
#define WARN_OF_MON		65
#define DETECT_MONSTERS		66
#define NUMBED			67
#define FEARED			68
#define FEAR_RES			69
#define FROZEN			70
#define BURNED			71
#define RMB_LOST			72
#define DISPLAY_LOST		73
#define SPELLS_LOST		74
#define YELLOW_SPELLS		75
#define AUTO_DESTRUCT		76
#define MEMORY_LOST		77
#define INVENTORY_LOST		78
#define BLACK_NG_WALLS		79
#define MENU_LOST			80
#define SPEED_BUG		81
#define SUPERSCROLLER_ACTIVE		82

#define DEAC_FIRE_RES	83
#define DEAC_COLD_RES	84
#define DEAC_SLEEP_RES	85
#define DEAC_DISINT_RES	86
#define DEAC_SHOCK_RES	87
#define DEAC_POISON_RES	88
#define DEAC_DRAIN_RES	89
#define DEAC_SICK_RES	90
#define DEAC_ANTIMAGIC	91
#define DEAC_ACID_RES	92
#define DEAC_STONE_RES	93
#define DEAC_FEAR_RES	94
#define DEAC_SEE_INVIS	95
#define DEAC_TELEPAT	96
#define DEAC_WARNING	97
#define DEAC_SEARCHING	98
#define DEAC_CLAIRVOYANT	99
#define DEAC_INFRAVISION	100
#define DEAC_DETECT_MONSTERS	101
#define DEAC_INVIS	102
#define DEAC_DISPLACED	103
#define DEAC_STEALTH	104
#define DEAC_JUMPING	105
#define DEAC_TELEPORT_CONTROL	106
#define DEAC_FLYING	107
#define DEAC_MAGICAL_BREATHING	108
#define DEAC_PASSES_WALLS	109
#define DEAC_SLOW_DIGESTION	110
#define DEAC_HALF_SPDAM	111
#define DEAC_HALF_PHDAM	112
#define DEAC_REGENERATION	113
#define DEAC_ENERGY_REGENERATION	114
#define DEAC_POLYMORPH_CONTROL	115
#define DEAC_FAST	116
#define DEAC_REFLECTING	117
#define DEAC_FREE_ACTION	118

#define HALLU_PARTY 119
#define DRUNKEN_BOXING 120
#define STUNNOPATHY 121
#define NUMBOPATHY 122
#define FREEZOPATHY 123
#define STONED_CHILLER 124
#define CORROSIVITY 125
#define FEAR_FACTOR 126
#define BURNOPATHY 127
#define SICKOPATHY 128

#define DEAC_HALLU_PARTY 129
#define DEAC_DRUNKEN_BOXING 130
#define DEAC_STUNNOPATHY 131
#define DEAC_NUMBOPATHY 132
#define DEAC_FREEZOPATHY 133
#define DEAC_STONED_CHILLER 134
#define DEAC_CORROSIVITY 135
#define DEAC_FEAR_FACTOR 136
#define DEAC_BURNOPATHY 137
#define DEAC_SICKOPATHY 138

#define HEAVY_STUNNED 139
#define HEAVY_CONFUSION 140
#define HEAVY_NUMBED 141
#define HEAVY_FEARED 142
#define HEAVY_FROZEN 143
#define HEAVY_BURNED 144
#define HEAVY_BLIND 145
#define HEAVY_HALLU 146

#define FREE_HAND_LOST 147
#define UNIDENTIFY 148
#define THIRST 149
#define LUCK_LOSS 150
#define SHADES_OF_GREY 151
#define INCREASED_GRAVITY 152
#define FAINT_ACTIVE 153
#define ITEMCURSING 154
#define DIFFICULTY_INCREASED 155
#define DEAFNESS 156
#define CASTER_PROBLEM 157
#define WEAKNESS_PROBLEM 158
#define ROT_THIRTEEN 159
#define BISHOP_GRIDBUG 160
#define CONFUSION_PROBLEM 161
#define DROP_BUG 162
#define DSTW_BUG 163
#define STATUS_FAILURE 164
#define ALIGNMENT_FAILURE 165
#define STAIRSTRAP 166

#define STORM_HELM 167

#define NO_STAIRCASE 168

#define TIME_STOPPED 169

#define UNINFORMATION 170

#define INTRINSIC_LOSS 171
#define TRAP_REVEALING 172
#define BLOOD_LOSS 173
#define NASTINESS_EFFECTS 174
#define BAD_EFFECTS 175
#define AUTOMATIC_TRAP_CREATION 176
#define SENTIENT_HIGH_HEELS 177
#define REPEATING_VULNERABILITY 178
#define TELEPORTING_ITEMS 179
#define RANDOM_RUMORS 180

#define CAPTCHA 181
#define FARLOOK_BUG 182
#define RESPAWN_BUG 183
#define MC_REDUCTION 184

#define PREMDEATH		185

#define KEEN_MEMORY	186
#define DEAC_KEEN_MEMORY	187

#define THE_FORCE	188
#define DEAC_THE_FORCE	189

#define SENSORY_DEPRIVATION 190
#define RECURRING_AMNESIA 191

#define BIGSCRIPT 192
#define BANKBUG 193
#define MAPBUG 194
#define TECHBUG 195
#define RECURRING_DISENCHANT 196
#define VERISIERTEFFECT 197
#define CHAOS_TERRAIN 198
#define MUTENESS 199
#define ENGRAVINGBUG 200
#define MAGIC_DEVICE_BUG 201
#define BOOKBUG 202
#define LEVELBUG 203
#define QUIZZES 204

#define FAST_METABOLISM 205
#define NORETURN 206
#define ALWAYS_EGOTYPES 207
#define FAST_FORWARD 208
#define FOOD_IS_ROTTEN 209
#define SKILL_DEACTIVATED 210
#define STATS_LOWERED 211
#define TRAINING_DEACTIVATED 212
#define EXERCISE_DEACTIVATED 213

#define SIGHT_BONUS	214
#define DEAC_SIGHT_BONUS	215
#define VERSUS_CURSES	216
#define DEAC_VERSUS_CURSES	217

#define STUN_RES	218
#define CONF_RES	219
#define MULTISHOES	220
#define EXTRA_WEAPON_PRACTICE	221
#define DTBEEM_RES	222
#define DOUBLE_ATTACK	223
#define QUAD_ATTACK	224
#define DEAC_STUN_RES	225
#define DEAC_CONF_RES	226
#define DEAC_DOUBLE_ATTACK	227
#define DEAC_QUAD_ATTACK	228

#define TURNLIMITATION 229
#define WEAKSIGHT 230
#define RANDOM_MESSAGES 231

#define ELEMENT_RES 232
#define PSI_RES 233
#define DEAC_PSI_RES 234

#define WONDERLEGS 235
#define GLIB_COMBAT 236
#define DEAC_WONDERLEGS 237
#define DEAC_GLIB_COMBAT 238

#define DESECRATION 239
#define STARVATION_EFFECT 240
#define NO_DROPS_EFFECT 241
#define LOW_EFFECTS 242
#define INVIS_TRAPS_EFFECT 243
#define GHOST_WORLD 244
#define DEHYDRATION 245
#define HATE_TRAP_EFFECT 246
#define TOTTER_EFFECT 247
#define NONINTRINSIC_EFFECT 248
#define DROPCURSES_EFFECT 249
#define NAKEDNESS 250
#define ANTILEVELING 251
#define ITEM_STEALING_EFFECT 252
#define REBELLION_EFFECT 253
#define CRAP_EFFECT 254
#define PROJECTILES_MISFIRE 255
#define WALL_TRAP_EFFECT 256

#define MANALEECH 257
#define DEAC_MANALEECH 258

#define MAP_AMNESIA 259

#define DIMMED 260

#define PEACEVISION 261
#define DEAC_PEACEVISION 262
#define DIMMOPATHY 263
#define DEAC_DIMMOPATHY 264

#define HEAVY_DIMMED 265

#define RNGE_IRREGULARITY 266
#define RNGE_INTERNET_ACCESS 267
#define RNGE_ANTI_GOVERNMENT 268
#define RNGE_GAS_FILTERING 269
#define RNGE_VAMPIRIC_DRAIN 270
#define RNGE_PSEUDO_IDENTIFICATION 271
#define RNGE_GHOST_SUMMONING 272
#define RNGE_PRAYER 273
#define RNGE_ANTI_BEHEADING 274
#define RNGE_POLAND 275
#define RNGE_KICKING 276
#define RNGE_TOESTOMPING 277
#define RNGE_JUNGLE_ACTION 278
#define RNGE_UNLIKABILITY 279
#define RNGE_SPELL_DISRUPTION 280
#define RNGE_BDSM 281
#define RNGE_SLIPPING 282
#define RNGE_MIRRORING 283
#define RNGE_TRUE_SIGHT 284
#define RNGE_LIQUID_DIET 285
#define RNGE_ANGRY_GODS 286
#define RNGE_RADIO_BROADCASTS 287
#define RNGE_OCCASIONAL_DAMAGE 288
#define RNGE_NOISE 289
#define RNGE_VORTICES 290
#define RNGE_EXPLOSIONS 291
#define RNGE_FATAL_ATTRACTION 292
#define RNGE_VOLTAGE 293
#define RNGE_WEEPING 294
#define RNGE_CASTLEVANIA 295
#define RNGE_ENGLAND 296
#define RNGE_FORGETTING 297
#define RNGE_ANTIMAGIC_A 298
#define RNGE_ANTIMAGIC_B 299
#define RNGE_ANTIMAGIC_C 300
#define RNGE_ANTIMAGIC_D 301
#define RNGE_CHINA 302
#define RNGE_LIGHT_ABSORPTION 303
#define RNGE_CHILDBIRTH 304
#define RNGE_RED_ATTUNEMENT 305
#define RNGE_POLAR_OPPOSITES 306
#define RNGE_SICKNESS 307
#define RNGE_COQUETRY 308
#define RNGE_IGNORANCE 309
#define RNGE_VENGEANCE 310
#define RNGE_HIGH_HEELING 311
#define RNGE_GRAVITY 312
#define RNGE_WISH_IMPROVEMENT 313
#define RNGE_POCKET_MONSTERS 314
#define RNGE_LEVUNTATION 315
#define RNGE_PERMANENT_OCCUPATION 316
#define RNGE_NURSERY 317
#define RNGE_SLEXUALITY 318
#define RNGE_ANGBAND 319
#define RNGE_ANOREXIA 320
#define RNGE_DNETHACK 321
#define RNGE_UNNETHACK 322
#define RNGE_NETHACK_FOURK 323
#define RNGE_MARITAL_ARTS 324
#define RNGE_TEAM_SPLAT 325
#define RNGE_ABOMINATIONS 326
#define RNGE_PUNISHMENT 327
#define RNGE_BLOODLUST 328
#define RNGE_IMMOBILITY 329
#define RNGE_BOSS_ENCOUNTERS 330
#define RNGE_IRONMAN_MODE 331
#define RNGE_RIVERS 332
#define RNGE_LOUDSPEAKERS 333
#define RNGE_ARMOR_PRESERVATION 334
#define RNGE_WEAKNESS 335
#define RNGE_FRAILNESS 336
#define RNGE_IRON_MAIDEN 337
#define RNGE_DONORS 338
#define RNGE_AIDS 339
#define RNGE_TRAP_ALERT 340

#define DISCONNECTED_STAIRS 341
#define INTERFACE_SCREW 342
#define BOSSFIGHT 343
#define ENTIRE_LEVEL 344
#define BONES_CHANGE 345
#define AUTOCURSE_EQUIP 346
#define HIGHLEVEL_STATUS 347
#define SPELL_FORGETTING 348
#define SOUND_EFFECT_BUG 349
#define TIMERUN_BUG 350

#define RNGE_EXTINCTION 351
#define RNGE_DEFUSING 352
#define RNGE_DENASTIFICATION 353

#define FEMTRAP_FEMMY 354
#define FEMTRAP_MADELEINE 355
#define FEMTRAP_MARLENA 356
#define FEMTRAP_ANASTASIA 357
#define FEMTRAP_JESSICA 358
#define FEMTRAP_SOLVEJG 359
#define FEMTRAP_WENDY 360
#define FEMTRAP_KATHARINA 361
#define FEMTRAP_ELENA 362
#define FEMTRAP_THAI 363
#define FEMTRAP_ELIF 364
#define FEMTRAP_NADJA 365
#define FEMTRAP_SANDRA 366
#define FEMTRAP_NATALJE 367
#define FEMTRAP_JEANETTA 368
#define FEMTRAP_YVONNE 369
#define FEMTRAP_MAURAH 370

#define LOOTCUT_BUG	371
#define MONSTER_SPEED_BUG	372
#define SCALING_BUG	373
#define ENMITY_BUG	374
#define WHITE_SPELLS	375
#define COMPLETE_GRAY_SPELLS	376
#define QUASAR_BUG	377
#define MOMMA_BUG	378
#define HORROR_BUG	379
#define ARTIFICER_BUG	380
#define WEREFORM_BUG	381
#define NON_PRAYER_BUG	382
#define EVIL_PATCH_EFFECT	383
#define HARD_MODE_EFFECT	384
#define SECRET_ATTACK_BUG	385
#define EATER_BUG	386
#define COVETOUSNESS_BUG	387
#define NOT_SEEN_BUG	388
#define DARK_MODE_BUG	389
#define ANTISEARCH_EFFECT	390
#define HOMICIDE_EFFECT	391
#define NASTY_NATION_BUG	392
#define WAKEUP_CALL_BUG	393
#define GRAYOUT_BUG	394
#define GRAY_CENTER_BUG	395
#define CHECKERBOARD_BUG	396
#define CLOCKWISE_SPIN_BUG	397
#define COUNTERCLOCKWISE_SPIN_BUG	398
#define LAG_BUG	399
#define BLESSCURSE_EFFECT	400
#define DE_LIGHT_BUG	401
#define DISCHARGE_BUG	402
#define TRASHING_EFFECT	403
#define FILTERING_BUG	404
#define DEFORMATTING_BUG	405
#define FLICKER_STRIP_BUG	406
#define UNDRESSING_EFFECT	407
#define HYPERBLUEWALL_BUG	408
#define NOLITE_BUG	409
#define PARANOIA_BUG	410
#define FLEECESCRIPT_BUG	411
#define INTERRUPT_EFFECT	412
#define DUSTBIN_BUG	413
#define MANA_BATTERY_BUG	414
#define MONSTERFINGERS_EFFECT	415
#define MISCAST_BUG	416
#define MESSAGE_SUPPRESSION_BUG	417
#define STUCK_ANNOUNCEMENT_BUG	418
#define BLOODTHIRSTY_EFFECT	419
#define MAXIMUM_DAMAGE_BUG	420
#define LATENCY_BUG	421
#define STARLIT_BUG	422
#define KNOWLEDGE_BUG	423
#define HIGHSCORE_BUG	424
#define PINK_SPELLS	425
#define GREEN_SPELLS	426
#define EVC_EFFECT	427
#define UNDERLAYER_BUG	428
#define DAMAGE_METER_BUG	429
#define ARBITRARY_WEIGHT_BUG	430
#define FUCKED_INFO_BUG	431
#define BLACK_SPELLS	432
#define CYAN_SPELLS	433
#define HEAP_EFFECT	434
#define BLUE_SPELLS	435
#define TRON_EFFECT	436
#define RED_SPELLS	437
#define TOO_HEAVY_EFFECT	438
#define ELONGATION_BUG	439
#define WRAPOVER_EFFECT	440
#define DESTRUCTION_EFFECT	441
#define MELEE_PREFIX_BUG	442
#define AUTOMORE_BUG	443
#define UNFAIR_ATTACK_BUG	444

#define CONT_RES 445
#define DEAC_CONT_RES 446

#define DISCOUNT_ACTION 447
#define DEAC_DISCOUNT_ACTION 448
#define FULL_NUTRIENT 449
#define DEAC_FULL_NUTRIENT 450
#define TECHNICALITY 451
#define DEAC_TECHNICALITY 452

#define ORANGE_SPELLS 453
#define VIOLET_SPELLS 454
#define LONGING_EFFECT 455
#define CURSED_PARTS 456
#define QUAVERSAL 457
#define APPEARANCE_SHUFFLING 458
#define BROWN_SPELLS 459
#define CHOICELESSNESS 460
#define GOLDSPELLS 461
#define DEPROVEMENT 462
#define INITIALIZATION_FAIL 463
#define GUSHLUSH 464
#define SOILTYPE 465
#define DANGEROUS_TERRAINS 466
#define FALLOUT_EFFECT 467
#define MOJIBAKE 468
#define GRAVATION 469
#define UNCALLED_EFFECT 470
#define EXPLODING_DICE 471
#define PERMACURSE_EFFECT 472
#define SHROUDED_IDENTITY 473
#define FEELER_GAUGES 474
#define LONG_SCREWUP 475
#define WING_YELLOW_GLYPHS 476
#define LIFE_SAVING_BUG 477
#define CURSEUSE_EFFECT 478
#define CUT_NUTRITION 479
#define SKILL_LOSS_EFFECT 480
#define AUTOPILOT_EFFECT 481
#define MYSTERIOUS_FORCE_EFFECT 482
#define MONSTER_GLYPH_BUG 483
#define CHANGING_DIRECTIVES 484
#define CONTAINER_KABOOM 485
#define STEAL_DEGRADING 486
#define LEFT_INVENTORY 487
#define FLUCTUATING_SPEED 488
#define TARMU_STROKING_NORA 489
#define FAILURE_EFFECTS 490
#define BRIGHT_CYAN_SPELLS 491
#define FREQUENTATION_SPAWNS 492
#define PET_AI_SCREWED 493
#define SATAN_EFFECT 494
#define REMEMBERANCE_EFFECT 495
#define POKELIE_EFFECT 496
#define AUTOPICKUP_ALWAYS 497
#define DYWYPI_PROBLEM 498
#define SILVER_SPELLS 499
#define METAL_SPELLS 500
#define PLATINUM_SPELLS 501
#define MANLER_EFFECT 502
#define DOORNING_EFFECT 503
#define NOWNSIBLE_EFFECT 504
#define ELM_STREET_EFFECT 505
#define MONNOISE_EFFECT 506
#define RANG_CALL_EFFECT 507
#define RECURRING_SPELL_LOSS 508
#define ANTI_TRAINING_EFFECT 509
#define TECHOUT_BUG 510
#define STAT_DECAY 511
#define MOVEMORKING 512

#define FEMTRAP_MELTEM 513

#define BAD_PARTS 514
#define COMPLETELY_BAD_PARTS 515
#define EVIL_VARIANT_ACTIVE 516

#define FEMTRAP_SARAH 517
#define FEMTRAP_CLAUDIA 518
#define FEMTRAP_LUDGERA 519
#define FEMTRAP_KATI 520

#define SANITY_TREBLE_EFFECT 521
#define STAT_DECREASE_BUG 522
#define SIMEOUT_BUG 523

#define RNGE_MULTISHOT 524
#define RNGE_SKILL_REVEAL 525
#define RNGE_TECH_INSIGHT 526
#define RNGE_LISTENING 527

#define RNGE_CANNIBALISM 528
#define RNGE_POLYVISION 529

#define PLAYERBLEEDING 530

#define SCENT_VIEW 531
#define DEAC_SCENT_VIEW 532
#define DIMINISHED_BLEEDING 533
#define DEAC_DIMINISHED_BLEEDING 534

#define RNGE_HEMOPHILIA 535
#define RNGE_BLAST_SHIELDING 536
#define RNGE_FUNNY_HALLU 537
#define RNGE_POLYPILING 538
#define RNGE_SAP_GENERATION 539
#define RNGE_WEALTH 540

#define FEMTRAP_NELLY 541
#define FEMTRAP_EVELINE 542
#define FEMTRAP_KARIN 543
#define FEMTRAP_JUEN 544
#define FEMTRAP_KRISTINA 545
#define FEMTRAP_LOU 546

#define CONTROL_MAGIC 547
#define DEAC_CONTROL_MAGIC 548
#define EXP_BOOST 549
#define DEAC_EXP_BOOST 550

#define FEMTRAP_ALMUT 551
#define FEMTRAP_JULIETTA 552
#define FEMTRAP_ARABELLA 553

#define RNGE_WHORING 554
#define RNGE_BOSSING 555
#define RNGE_STENCH 556
#define RNGE_ECHOLOCATION 557
#define RNGE_STACKMESSAGING 558

#define FEMTRAP_KRISTIN 559
#define FEMTRAP_ANNA 560
#define FEMTRAP_RUEA 561
#define FEMTRAP_DORA 562
#define FEMTRAP_MARIKE 563
#define FEMTRAP_JETTE 564
#define FEMTRAP_INA 565
#define FEMTRAP_SING 566
#define FEMTRAP_VICTORIA 567
#define FEMTRAP_MELISSA 568
#define FEMTRAP_ANITA 569
#define FEMTRAP_HENRIETTA 570
#define FEMTRAP_VERENA 571

#define ASTRAL_VISION 572
#define DEAC_ASTRAL_VISION 573
#define BLIND_RES 574
#define DEAC_BLIND_RES 575
#define DEAC_HALLUC_RES 576

#define RNGE_OVERVIEW_IMPROVEMENT 577

#define SECOND_CHANCE		578
#define LAST_PROP		(SECOND_CHANCE)

#define APP_VAMPIRIC_CLOAK 1000
#define APP_SHROUDED_CLOAK 1001
#define APP_MYSTERIOUS_CLOAK 1002
#define APP_GHOSTLY_CLOAK 1003
#define APP_STRAITJACKET_CLOAK 1004
#define APP_POLITICIAN_CLOAK 1005
#define APP_ANGELIC_CLOAK 1006
#define APP_DEMONIC_CLOAK 1007
#define APP_VOID_CLOAK 1008
#define APP_PETRIFIED_CLOAK 1009
#define APP_GODLESS_CLOAK 1010
#define APP_WEEB_CLOAK 1011
#define APP_DEADLY_CLOAK 1012
#define APP_JARRING_CLOAK 1013
#define APP_ENERGIZER_CLOAK 1014
#define APP_MANTLE_OF_COAT 1015
#define APP_CHILLING_CLOAK 1016
#define APP_ELECTROSTATIC_CLOAK 1017
#define APP_HOMICIDAL_CLOAK 1018
#define APP_GREEK_CLOAK 1019
#define APP_FORGETFUL_CLOAK 1020
#define APP_CHANGING_CLOAK 1021
#define APP_SHELL_CLOAK 1022
#define APP_CHINESE_CLOAK 1023
#define APP_POLYFORM_CLOAK 1024
#define APP_ABSORBING_CLOAK 1025
#define APP_DEEP_CLOAK 1026
#define APP_PINK_CLOAK 1027
#define APP_BIRTHCLOTH 1028
#define APP_GRASS_CLOAK 1029
#define APP_CONTAMINATED_COAT 1030
#define APP_WITHERED_CLOAK 1031
#define APP_IGNORANT_CLOAK 1032
#define APP_AVENGER_CLOAK 1033
#define APP_GRAVITY_CLOAK 1034
#define APP_WISHFUL_CLOAK 1035
#define APP_POKE_MONGO_CLOAK 1036
#define APP_LEVUNTATION_CLOAK 1037
#define APP_QUICKTRAVEL_CLOAK 1038
#define APP_GEEK_CLOAK 1039
#define APP_NURSE_CLOAK 1040
#define APP_SLEXUAL_CLOAK 1041
#define APP_ANGBAND_CLOAK 1042
#define APP_FLEECY_COLORED_CLOAK 1043
#define APP_ANOREXIA_CLOAK 1044
#define APP_FLASH_CLOAK 1045
#define APP_DNETHACK_CLOAK 1046
#define APP_BOXING_GOWN 1047
#define APP_TEAM_SPLAT_CLOAK 1048
#define APP_ELDRITCH_CLOAK 1049
#define APP_DIFFICULT_CLOAK 1050
#define APP_GENTLE_CLOAK 1051
#define APP_IRRADIATION_CLOAK 1052
#define APP_SOFT_CLOAK 1053
#define APP_EXCREMENT_CLOAK 1054
#define APP_HUNGRY_CLOAK 1055
#define APP_SCIENCE_CLOAK 1056
#define APP_GUILD_CLOAK 1057
#define APP_COLORFADE_CLOAK 1058
#define APP_SLOWING_GOWN 1059
#define APP_FOUNDRY_CLOAK 1060
#define APP_HEARING_CLOAK 1061
#define APP_SPELLSUCKING_CLOAK 1062
#define APP_ROADMAP_CLOAK 1063
#define APP_STORM_COAT 1064
#define APP_FLEECELING_CLOAK 1065
#define APP_UP_DOWN_CLOAK 1066
#define APP_CYANISM_CLOAK 1067
#define APP_LONG_RANGE_CLOAK 1068
#define APP_FLIER_CLOAK 1069
#define APP_RIFLING_POWER_CLOAK 1070
#define APP_CURSED_CALLED_CLOAK 1071
#define APP_FAILUNCAP_CLOAK 1072
#define APP_FOURCHAN_CLOAK 1073
#define APP_INALISH_CLOAK 1074
#define APP_VOLCANIC_CLOAK 1075
#define APP_DIFFERENT_CLOAK 1076
#define APP_FUEL_CLOAK 1077
#define APP_PURE_CLOAK 1078
#define APP_CLOISTER_CLOAK 1079
#define APP_OPERA_CLOAK 1080
#define APP_ORNAMENTAL_COPE 1081
#define APP_WETSUIT 1082

#define APP_INTERNET_HELMET 2000
#define APP_ALUMINIUM_HELMET 2001
#define APP_ANTI_GOVERNMENT_HELMET 2002
#define APP_FILTERED_HELMET 2003
#define APP_RNG_HELMET 2004
#define APP_COMPLETE_HELMET 2005
#define APP_VISORED_HELMET 2006
#define APP_ORANGE_VISORED_HELMET 2007
#define APP_WATER_PIPE_HELMET 2008
#define APP_RADIO_HELMET 2009
#define APP_SCUBA_HELMET 2010
#define APP_BUG_TRACKING_HELMET 2011
#define APP_WEEPING_HELMET 2012
#define APP_NARROW_HELMET 2013
#define APP_CELTIC_HELMET 2014
#define APP_MUSICAL_HELMET 2015
#define APP_SECRET_HELMET 2016
#define APP_INKCOAT_HELMET 2017
#define APP_KNOWLEDGEABLE_HELMET 2018
#define APP_FORMULA_ONE_HELMET 2019
#define APP_DREAM_HELMET 2020
#define APP_RUBYNUS_HELMET 2021
#define APP_THINKING_HELMET 2022
#define APP_NETRADIATION_HELMET 2023
#define APP_STRIP_BANDANA 2024
#define APP_TWISTED_VISOR_HELMET 2025
#define APP_BLUY_HELMET 2026
#define APP_LESS_HELMET 2027
#define APP_GRUNTER_HELMET 2028
#define APP_CLOUDY_HELMET 2029
#define APP_FAILUNCAP_HELMET 2030
#define APP_BREATH_CONTROL_HELMET 2031
#define APP_GAS_MASK 2032
#define APP_SAGES_HELMET 2033
#define APP_SHEMAGH 2034
#define APP_LEAD_HELMET 2035
#define APP_SERRATED_HELMET 2036
#define APP_TECHNICAL_HELMET 2037
#define APP_FREQUENT_HELMET 2038
#define APP_POPE_HAT 2039
#define APP_CORONA_MASK 2040
#define APP_ANACHRO_HELMET 2041
#define APP_PETSENSE_HELMET 2042

#define APP_GRAFFITI_GLOVES 3000
#define APP_VAMPIRIC_GLOVES 3001
#define APP_COMFORTABLE_GLOVES 3002
#define APP_POLNISH_GLOVES 3003
#define APP_CLUMSY_GLOVES 3004
#define APP_GREY_SHADED_GLOVES 3005
#define APP_SLIPPERY_GLOVES 3006
#define APP_MIRRORED_GLOVES 3007
#define APP_RIDING_GLOVES 3008
#define APP_BRAND_NEW_GLOVES 3009
#define APP_BOXING_GLOVES 3010
#define APP_FENCING_GLOVES 3011
#define APP_FINGERLESS_GLOVES 3012
#define APP_FATAL_GLOVES 3013
#define APP_RUNIC_GLOVES 3014
#define APP_SPANISH_GLOVES 3015
#define APP_ENGLISH_GLOVES 3016
#define APP_VELVET_GLOVES 3017
#define APP_RACER_GLOVES 3018
#define APP_SHITTY_GLOVES 3019
#define APP_SENSOR_GLOVES 3020
#define APP_SILK_FINGERLINGS 3021
#define APP_PRINCESS_GLOVES 3022
#define APP_UNCANNY_GLOVES 3023
#define APP_OCCULTISM_GLOVES 3024
#define APP_DIGGER_GLOVES 3025
#define APP_INVERSE_GLOVES 3026
#define APP_SLAYING_GLOVES 3027
#define APP_DEMOLITION_GLOVES 3028
#define APP_FAILUNCAP_GLOVES 3029
#define APP_RAYDUCTNAY_GLOVES 3030
#define APP_FLOWER_GLOVES 3031
#define APP_GAMEBLE_GLOVES 3032
#define APP_BISE_GLOVES 3033
#define APP_MULTILINGUITIS_GLOVES 3034
#define APP_NONDESCRIPT_GLOVES 3035

#define APP_IRREGULAR_BOOTS 4000
#define APP_WEDGE_BOOTS 4001
#define APP_WINTER_STILETTOS 4002
#define APP_CLUNKY_HEELS 4003
#define APP_ANKLE_BOOTS 4004
#define APP_BLOCK_HEELED_BOOTS 4005
#define APP_VELCRO_BOOTS 4006
#define APP_BATTLE_BOOTS 4007
#define APP_PLATFORM_BOOTS 4008
#define APP_PLATEAU_BOOTS 4009
#define APP_COMBAT_BOOTS 4010
#define APP_JUNGLE_BOOTS 4011
#define APP_FIN_BOOTS 4012
#define APP_PROFILED_BOOTS 4013
#define APP_HOT_BOOTS 4014
#define APP_RAINBOW_BOOTS 4015
#define APP_ROLLER_BOOTS 4016
#define APP_SNOW_BOOTS 4017
#define APP_WINTER_BOOTS 4018
#define APP_RIDING_BOOTS 4019
#define APP_EXPLOSIVE_BOOTS 4020
#define APP_HUGGING_BOOTS 4021
#define APP_FLEECY_BOOTS 4022
#define APP_CHESS_BOOTS 4023
#define APP_BEAUTIFUL_HEELS 4024
#define APP_ROMAN_SANDALS 4025
#define APP_CASTLEVANIA_BOOTS 4026
#define APP_KOREAN_SANDALS 4027
#define APP_GENTLE_BOOTS 4028
#define APP_BUCKLED_BOOTS 4029
#define APP_SPIDER_BOOTS 4030
#define APP_EROTIC_BOOTS 4031
#define APP_SPUTA_BOOTS 4032
#define APP_RADIANT_HEELS 4033
#define APP_TURBO_BOOTS 4034
#define APP_SEXY_HEELS 4035
#define APP_STROKING_BOOTS 4036
#define APP_BLUE_SNEAKERS 4037
#define APP_FEMMY_BOOTS 4038
#define APP_RED_SNEAKERS 4039
#define APP_YELLOW_SNEAKERS 4040
#define APP_PINK_SNEAKERS 4041
#define APP_SHARP_EDGED_SANDALS 4042
#define APP_SKI_HEELS 4043
#define APP_FETISH_HEELS 4044
#define APP_VELVET_PUMPS 4045
#define APP_CALF_LEATHER_SANDALS 4046
#define APP_VELCRO_SANDALS 4047
#define APP_BUFFALO_BOOTS 4048
#define APP_HEROINE_MOCASSINS 4049
#define APP_HEAP_OF_SHIT_BOOTS 4050
#define APP_LOLITA_BOOTS 4051
#define APP_WEAPON_LIGHT_BOOTS 4052
#define APP_ORGASM_PUMPS 4053
#define APP_WORN_OUT_SNEAKERS 4054
#define APP_IMAGINARY_HEELS 4055
#define APP_NOBLE_SANDALS 4056
#define APP_FAILUNCAP_SHOES 4057
#define APP_FLIPFLOPS 4058
#define APP_RUMBLE_BOOTS 4059
#define APP_HIGH_IRON_BOOTS 4060
#define APP_DOCTOR_CLAW_BOOTS 4061
#define APP_SPOOKY_BOOTS 4062
#define APP_FEELGOOD_HEELS 4063
#define APP_GENTLE_SNEAKERS 4064
#define APP_PLOF_HEELS 4065
#define APP_PRINCESS_PUMPS 4066
#define APP_BALLET_HEELS 4067
#define APP_STEEL_TOED_BOOTS 4068
#define APP_MARJI_SHOES 4069
#define APP_MARY_JANES 4070
#define APP_PERSIAN_BOOTS 4071
#define APP_THICK_BOOTS 4072
#define APP_SAND_ALS 4073
#define APP_SHADOWY_HEELS 4074
#define APP_REFLECTIVE_SLIPPERS 4075
#define APP_LEAD_BOOTS 4076
#define APP_WEIGHT_ATTACHMENT_BOOTS 4077
#define APP_FUNGAL_SANDALS 4078
#define APP_PORCELAIN_SANDALS 4079
#define APP_PRINTED_SANDALS 4080
#define APP_PRINTED_WEDGES 4081
#define APP_STANDING_FOOTWEAR 4082
#define APP_FLUFFY_BOOTS 4083
#define APP_FILIGREE_STILETTOS 4084
#define APP_UGLY_BOOTS 4085
#define APP_UNISEX_PUMPS 4086
#define APP_CUDDLE_CLOTH_BOOTS 4087
#define APP_GARDEN_SLIPPERS 4088
#define APP_DYKE_BOOTS 4089
#define APP_ANKLE_STRAP_SANDALS 4090
#define APP_BUSINESS_SHOES 4091
#define APP_BONE_HEELS 4092
#define APP_DEMONOLOGIST_BOOTS 4093
#define APP_MUD_BOOTS 4094
#define APP_GENERIC_HIGH_HEELS 4095
#define APP_FAILED_SHOES 4096
#define APP_OPERA_PUMPS 4097
#define APP_WOODEN_CLOGS 4098
#define APP_REGULAR_SNEAKERS 4099
#define APP_ELITE_SNEAKERS 4100
#define APP_FUR_BOOTS 4101
#define APP_CROSS_COUNTRY_BOOTS 4102
#define APP_BIKER_BOOTS 4103
#define APP_ZERO_DROP_SHOES 4104
#define APP_HIKING_BOOTS 4105
#define APP_THROWAWAY_SANDALS 4106
#define APP_MACHINERY_BOOTS 4107
#define APP_INDUSTRIAL_BOOTS 4108
#define APP_CHRISTMAS_CHILD_MODE_BOOTS 4109
#define APP_BAREFOOT_SHOES 4110
#define APP_SANDALS_WITH_SOCKS 4111
#define APP_CLIMBING_BOOTS 4112
#define APP_WEDGE_SNEAKERS 4113
#define APP_EXCEPTIONAL_SNEAKERS 4114
#define APP_CYAN_SNEAKERS 4115

#define APP_POTION_MILKY 5000
#define APP_POTION_SMOKY 5001
#define APP_POTION_VAPOR 5002
#define APP_POTION_SIZZLING 5003
#define APP_POTION_WHISKY 5004
#define APP_POTION_FUMING 5005
#define APP_POTION_DIMLY_SHINING 5006
#define APP_POTION_GASEOUS 5007
#define APP_POTION_STARLIGHT 5008
#define APP_POTION_ENDBRINGER 5009
#define APP_POTION_CHEWABLE 5010
#define APP_POTION_DEADWEIGHT 5011
#define APP_POTION_PRESENT 5012
#define APP_POTION_MALEEN 5013
#define APP_POTION_GLOSS 5014
#define APP_POTION_GLAM 5015

#define APP_CAMO_ROBE 6000
#define APP_OCTARINE_ROBE 6001

/*** Where the properties come from ***/
/* Definitions were moved here from obj.h and you.h */
struct prop {
	/*** Properties conveyed by objects ***/
	long extrinsic;
	/* Armor */
#	define W_ARM	    0x00000001L /* Body armor */
#	define W_ARMC	    0x00000002L /* Cloak */
#	define W_ARMH	    0x00000004L /* Helmet/hat */
#	define W_ARMS	    0x00000008L /* Shield */
#	define W_ARMG	    0x00000010L /* Gloves/gauntlets */
#	define W_ARMF	    0x00000020L /* Footwear */
#	define W_ARMU	    0x00000040L /* Undershirt */
#	define W_ARMOR	     (W_ARM | W_ARMC | W_ARMH | W_ARMS | W_ARMG | W_ARMF | W_ARMU)
	/* Weapons and artifacts */
#	define W_WEP	    0x00000100L /* Wielded weapon */
#	define W_QUIVER     0x00000200L /* Quiver for (f)iring ammo */
#	define W_SWAPWEP    0x00000400L /* Secondary weapon */
#	define W_ART	    0x00001000L /* Carrying artifact (not really worn) */
#	define W_ARTI	    0x00002000L /* Invoked artifact  (not really worn) */
	/* Amulets, rings, tools, and other items */
#	define W_AMUL	    0x00010000L /* Amulet */
#	define W_RINGL	    0x00020000L /* Left ring */
#	define W_RINGR	    0x00040000L /* Right ring */
#	define W_RING	    (W_RINGL | W_RINGR)
#	define W_TOOL	    0x00080000L /* Eyewear */
#	define W_SADDLE     0x00100000L	/* KMH -- For riding monsters */
#	define W_BALL	    0x00200000L /* Punishment ball */
#	define W_CHAIN	    0x00400000L /* Punishment chain */
#	define W_IMPLANT	    0x00800000L /* Implant */

	/*** Property is blocked by an object ***/
	long blocked;					/* Same assignments as extrinsic */

	/*** Timeouts, permanent properties, and other flags ***/
	long intrinsic;
	/* Timed properties */
#	define TIMEOUT	    0x00ffffffL /* Up to 16 million turns */
	/* Permanent properties */
#	define FROMEXPER    0x01000000L /* Gain/lose with experience, for role */
#	define FROMRACE     0x02000000L /* Gain/lose with experience, for race */
#	define FROMOUTSIDE  0x04000000L /* By corpses, prayer, thrones, etc. */
#	define INTRINSIC    (FROMOUTSIDE|FROMRACE|FROMEXPER)
	/* Control flags */
#	define I_SPECIAL    0x10000000L /* Property is controllable */

};

/*** Definitions for backwards compatibility ***/
#define LEFT_RING	W_RINGL
#define RIGHT_RING	W_RINGR
#define LEFT_SIDE	LEFT_RING
#define RIGHT_SIDE	RIGHT_RING
#define BOTH_SIDES	(LEFT_SIDE | RIGHT_SIDE)
#define WORN_ARMOR	W_ARM
#define WORN_CLOAK	W_ARMC
#define WORN_HELMET	W_ARMH
#define WORN_SHIELD	W_ARMS
#define WORN_GLOVES	W_ARMG
#define WORN_BOOTS	W_ARMF
#define WORN_AMUL	W_AMUL
#define WORN_BLINDF	W_TOOL
#define WORN_SHIRT	W_ARMU
#define WORN_IMPLANT	W_IMPLANT

#endif /* PROP_H */
