/**
 *    Name:        objects/states.c
 *    Description: the objects' state dispatcher and the objects' handlers (provisional: by subject later)
 *    Version:     0.1.0
 *    Created:     29-10-2026
 *    Modified:    29-10-2026
 *    Author:      Sebastian Toyos
 *
 *    Teenage Mutant Ninja Turtles (arcade, Konami 1989): the game's 68000 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void func_048236(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t a6_2 = 0;

	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 5u) << 2);
	a6_2 = mem_read32(a6 + d0);
	switch (a6_2)
	{
	case 0x00FA00u:
		*p_d7 = func_00FA00(*p_d7, a0);
		return;
	case 0x00FC00u:
		*p_d7 = func_00FC00(*p_d7, a0, a6_2);
		return;
	case 0x00FFC0u:
		*p_d7 = func_00FFC0(*p_d7, a0);
		return;
	case 0x00FFE0u:
		*p_d7 = func_00FFE0(*p_d7, a0);
		return;
	case 0x048F62u:
		func_048F62(a0);
		return;
	case 0x048F72u:
		func_048F72(a0);
		return;
	case 0x048FBAu:
		*p_d7 = func_048FBA(*p_d7, a0);
		return;
	case 0x048FFAu:
		func_048FFA(a0);
		return;
	case 0x04901Au:
		func_04901A(a0);
		return;
	case 0x049078u:
		func_049078(a0);
		return;
	case 0x0490D6u:
		func_0490D6(a0);
		return;
	case 0x0490E6u:
		func_0490E6(a0);
		return;
	case 0x04911Cu:
		*p_d7 = func_04911C(*p_d7, a0);
		return;
	case 0x04916Cu:
		func_04916C(a0);
		return;
	case 0x0491A8u:
		*p_d7 = func_0491A8(*p_d7, a0);
		return;
	case 0x0491F8u:
		func_0491F8(a0);
		return;
	case 0x049260u:
		func_049260(a0);
		return;
	case 0x049276u:
		func_049276(a0);
		return;
	case 0x0492A8u:
		func_0492A8(a0);
		return;
	case 0x0492DEu:
		func_0492DE(a0);
		return;
	case 0x049300u:
		func_049300(a0);
		return;
	case 0x04933Au:
		func_04933A(a0);
		return;
	case 0x049378u:
		func_049378(a0, p_d6, p_d7, p_a5);
		return;
	case 0x0493CAu:
		func_0493CA(a0, p_d6, p_d7, p_a5);
		return;
	case 0x049420u:
		func_049420(a0, p_d6, p_d7);
		return;
	case 0x049468u:
		*p_d7 = func_049468(*p_d7, a0);
		return;
	case 0x04949Eu:
		*p_d7 = func_04949E(*p_d7, a0);
		return;
	case 0x0494DAu:
		*p_d7 = func_0494DA(*p_d7, a0);
		return;
	case 0x049534u:
		*p_d7 = func_049534(*p_d7, a0);
		return;
	case 0x049570u:
		*p_d7 = func_049570(*p_d7, a0);
		return;
	case 0x0495DEu:
		func_0495DE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049604u:
		func_049604(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04966Eu:
		func_04966E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049694u:
		func_049694(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0496FAu:
		func_0496FA(a0);
		return;
	case 0x04971Eu:
		func_04971E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04973Eu:
		func_04973E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0497A6u:
		*p_d7 = func_0497A6(*p_d7, a0);
		return;
	case 0x0497C2u:
		func_0497C2(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04984Cu:
		func_04984C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049868u:
		func_049868(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0498B2u:
		func_0498B2(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0498EEu:
		func_0498EE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04991Eu:
		func_04991E(a0, a1);
		return;
	case 0x049948u:
		func_049948(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049980u:
		func_049980(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0499B8u:
		func_0499B8(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0499EAu:
		func_0499EA(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049A1Au:
		*p_d7 = func_049A1A(*p_d7, a0);
		return;
	case 0x049A42u:
		func_049A42(a0);
		return;
	case 0x049A66u:
		*p_d7 = func_049A66(*p_d7, a0);
		return;
	case 0x049AA2u:
		*p_d7 = func_049AA2(*p_d7, a0);
		return;
	case 0x049ADEu:
		*p_d7 = func_049ADE(*p_d7, a0);
		return;
	case 0x049B2Eu:
		*p_d7 = func_049B2E(*p_d7, a0);
		return;
	case 0x049B56u:
		*p_d7 = func_049B56(*p_d7, a0);
		return;
	case 0x049B82u:
		*p_d7 = func_049B82(*p_d7, a0);
		return;
	case 0x049BE4u:
		*p_d7 = func_049BE4(*p_d7, a0);
		return;
	case 0x049C0Cu:
		*p_d7 = func_049C0C(*p_d7, a0);
		return;
	case 0x049C38u:
		*p_d7 = func_049C38(*p_d7, a0);
		return;
	case 0x049C92u:
		func_049C92(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049D06u:
		func_049D06(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x049D7Eu:
		func_049D7E(a0, a1);
		return;
	case 0x049DD0u:
		func_049DD0(a0);
		return;
	case 0x049DF0u:
		func_049DF0(a0);
		return;
	case 0x049E00u:
		func_049E00(a0);
		return;
	case 0x049E24u:
		func_049E24(a0);
		return;
	case 0x049E48u:
		func_049E48(a0);
		return;
	case 0x049E6Cu:
		func_049E6C(a0);
		return;
	case 0x049EACu:
		*p_d7 = func_049EAC(*p_d7, a0, a1);
		return;
	case 0x049EC8u:
		*p_d7 = func_049EC8(*p_d7, a0);
		return;
	case 0x049F38u:
		func_049F38(a0, a1);
		return;
	case 0x049F6Au:
		func_049F6A(a0);
		return;
	case 0x049F78u:
		*p_d7 = func_049F78(*p_d7, a0);
		return;
	case 0x049FA0u:
		func_049FA0(a0, a1);
		return;
	case 0x049FE8u:
		*p_d7 = func_049FE8(*p_d7, a0, a1);
		return;
	case 0x04A004u:
		*p_d7 = func_04A004(*p_d7, a0);
		return;
	case 0x04A074u:
		func_04A074(a0, a1);
		return;
	case 0x04A0A6u:
		func_04A0A6(a0);
		return;
	case 0x04A0B4u:
		*p_d7 = func_04A0B4(*p_d7, a0);
		return;
	case 0x04A0DCu:
		func_04A0DC(a0, a1);
		return;
	case 0x04A120u:
		*p_d7 = func_04A120(*p_d7, a0, a1);
		return;
	case 0x04A13Cu:
		*p_d7 = func_04A13C(*p_d7, a0);
		return;
	case 0x04A176u:
		func_04A176(a0, a1);
		return;
	case 0x04A1BAu:
		func_04A1BA(a0);
		return;
	case 0x04A202u:
		unreached_04A202(a0);
		return;
	case 0x04A214u:
		func_04A214(a0, a1, p_d7, p_a5);
		return;
	case 0x04A25Au:
		*p_d7 = func_04A25A(*p_d7, a0);
		return;
	case 0x04A396u:
		unreached_04A396(a0);
		return;
	case 0x04A3A8u:
		func_04A3A8(a0, a1, p_d7, p_a5);
		return;
	case 0x04A454u:
		unreached_04A454(a0);
		return;
	case 0x04A466u:
		func_04A466(a0, a1, p_d7, p_a5);
		return;
	case 0x04A512u:
		unreached_04A512(a0);
		return;
	case 0x04A524u:
		func_04A524(a0, a1, p_d7, p_a5);
		return;
	case 0x04A5CEu:
		*p_d7 = func_04A5CE(*p_d7, a0, a1);
		return;
	case 0x04A5F8u:
		*p_d7 = func_04A5F8(*p_d7, a0);
		return;
	case 0x04A632u:
		func_04A632(a0, a1);
		return;
	case 0x04A676u:
		func_04A676(a0);
		return;
	case 0x04A690u:
		func_04A690(a0);
		return;
	case 0x04A6C6u:
		*p_d7 = func_04A6C6(*p_d7, a0);
		return;
	case 0x04A6E6u:
		func_04A6E6(a0);
		return;
	case 0x04A718u:
		*p_d7 = func_04A718(*p_d7, a0);
		return;
	case 0x04ADC8u:
		func_04ADC8(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AE0Eu:
		func_04AE0E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AE34u:
		func_04AE34(a0);
		return;
	case 0x04AE58u:
		func_04AE58(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AE8Cu:
		func_04AE8C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AEBCu:
		func_04AEBC(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AF3Cu:
		func_04AF3C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AF78u:
		func_04AF78(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04AFA8u:
		func_04AFA8(a0, a1);
		return;
	case 0x04AFD2u:
		func_04AFD2(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B00Au:
		func_04B00A(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B04Eu:
		func_04B04E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B08Cu:
		func_04B08C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B0B2u:
		func_04B0B2(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B118u:
		func_04B118(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B146u:
		func_04B146(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B168u:
		func_04B168(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B1ACu:
		func_04B1AC(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B250u:
		func_04B250(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B284u:
		func_04B284(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04B2BCu:
		func_04B2BC(a0, a1);
		return;
	case 0x04B2EEu:
		*p_d7 = func_04B2EE(*p_d7, a0);
		return;
	case 0x04B32Au:
		*p_d7 = func_04B32A(*p_d7, a0);
		return;
	case 0x04B37Au:
		*p_d7 = func_04B37A(*p_d7, a0);
		return;
	case 0x04B3A2u:
		*p_d7 = func_04B3A2(*p_d7, a0);
		return;
	case 0x04B3F0u:
		*p_d7 = func_04B3F0(*p_d7, a0);
		return;
	case 0x04B452u:
		*p_d7 = func_04B452(*p_d7, a0);
		return;
	case 0x04B47Au:
		*p_d7 = func_04B47A(*p_d7, a0);
		return;
	case 0x04B4A6u:
		*p_d7 = func_04B4A6(*p_d7, a0);
		return;
	case 0x04B508u:
		*p_d7 = func_04B508(*p_d7, a0);
		return;
	case 0x04B530u:
		*p_d7 = func_04B530(*p_d7, a0);
		return;
	case 0x04B588u:
		*p_d7 = func_04B588(*p_d7, a0);
		return;
	case 0x04B5EAu:
		*p_d7 = func_04B5EA(*p_d7, a0);
		return;
	case 0x04B622u:
		func_04B622(a0);
		return;
	case 0x04B646u:
		func_04B646(a0);
		return;
	case 0x04B66Au:
		func_04B66A(a0);
		return;
	case 0x04B68Eu:
		func_04B68E(a0);
		return;
	case 0x04B6B2u:
		func_04B6B2(a0);
		return;
	case 0x04B6D6u:
		func_04B6D6(a0);
		return;
	case 0x04B6FAu:
		func_04B6FA(a0);
		return;
	case 0x04C824u:
		func_04C824(a0);
		return;
	case 0x04C840u:
		func_04C840(a0);
		return;
	case 0x04C860u:
		func_04C860(a0);
		return;
	case 0x04CF74u:
		func_04CF74(a0);
		return;
	case 0x04CF9Au:
		func_04CF9A(a0, a6_2, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04CFD6u:
		func_04CFD6(a0);
		return;
	case 0x04D006u:
		*p_d7 = func_04D006(*p_d7, a0);
		return;
	case 0x04D00Cu:
		*p_d7 = func_04D00C(*p_d7, a0);
		return;
	case 0x04D04Au:
		func_04D04A(a0);
		return;
	case 0x04D072u:
		func_04D072(a0);
		return;
	case 0x04D08Eu:
		func_04D08E(a0);
		return;
	case 0x04D2D4u:
		func_04D2D4(a0);
		return;
	case 0x04D2FEu:
		*p_d7 = func_04D2FE(*p_d7, a0);
		return;
	case 0x04D330u:
		func_04D330(a0);
		return;
	case 0x04D820u:
		func_04D820(a0);
		return;
	case 0x04D856u:
		func_04D856(a0);
		return;
	case 0x04D884u:
		*p_d7 = func_04D884(*p_d7, a0);
		return;
	case 0x04D8ACu:
		func_04D8AC(a0);
		return;
	case 0x04D8E0u:
		func_04D8E0(a0);
		return;
	case 0x04D91Cu:
		func_04D91C(a0);
		return;
	case 0x04D93Au:
		*p_d7 = func_04D93A(*p_d7, a0);
		return;
	case 0x04D96Cu:
		*p_d7 = func_04D96C(*p_d7, a0);
		return;
	case 0x04D9A6u:
		func_04D9A6(a0);
		return;
	case 0x04D9C2u:
		func_04D9C2(a0);
		return;
	case 0x04D9F8u:
		func_04D9F8(a0);
		return;
	case 0x04DA2Cu:
		func_04DA2C(a0);
		return;
	case 0x04DA58u:
		func_04DA58(a0, a6_2, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04DA92u:
		func_04DA92(a0);
		return;
	case 0x04DACAu:
		func_04DACA(a0);
		return;
	case 0x04DAF6u:
		func_04DAF6(a0);
		return;
	case 0x04DB1Au:
		func_04DB1A(a0);
		return;
	case 0x04DB36u:
		*p_d7 = func_04DB36(*p_d7, a0);
		return;
	case 0x04DB76u:
		func_04DB76(a0);
		return;
	case 0x04DBAEu:
		func_04DBAE(a0);
		return;
	case 0x04DBD4u:
		func_04DBD4(a0);
		return;
	case 0x04DD50u:
		func_04DD50(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DD8Eu:
		func_04DD8E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DDC8u:
		func_04DDC8(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DDF8u:
		func_04DDF8(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DE78u:
		func_04DE78(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DEB2u:
		func_04DEB2(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DEF6u:
		func_04DEF6(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DF40u:
		func_04DF40(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DF80u:
		func_04DF80(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04DFBEu:
		func_04DFBE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E018u:
		func_04E018(a0, p_d6, p_d7, p_a5);
		return;
	case 0x04E06Au:
		func_04E06A(a0, p_d6, p_d7, p_a5);
		return;
	case 0x04E0C4u:
		*p_d7 = func_04E0C4(*p_d7, a0);
		return;
	case 0x04E0E0u:
		func_04E0E0(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E16Au:
		func_04E16A(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E186u:
		func_04E186(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E1D0u:
		func_04E1D0(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E20Au:
		func_04E20A(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E23Eu:
		func_04E23E(a0, a1);
		return;
	case 0x04E268u:
		func_04E268(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E2A0u:
		func_04E2A0(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E2D8u:
		*p_d7 = func_04E2D8(*p_d7, a0);
		return;
	case 0x04E300u:
		func_04E300(a0);
		return;
	case 0x04E354u:
		func_04E354(a0);
		return;
	case 0x04E380u:
		func_04E380(a0, p_d7, p_a5);
		return;
	case 0x04E3A0u:
		func_04E3A0(a0, a1, a6_2, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E3D8u:
		*p_d7 = func_04E3D8(*p_d7, a0);
		return;
	case 0x04E414u:
		*p_d7 = func_04E414(*p_d7, a0);
		return;
	case 0x04E464u:
		*p_d7 = func_04E464(*p_d7, a0);
		return;
	case 0x04E48Cu:
		*p_d7 = func_04E48C(*p_d7, a0);
		return;
	case 0x04E4B8u:
		*p_d7 = func_04E4B8(*p_d7, a0);
		return;
	case 0x04E510u:
		func_04E510(a0);
		return;
	case 0x04E53Cu:
		func_04E53C(a0, p_d7, p_a5);
		return;
	case 0x04E556u:
		func_04E556(a0);
		return;
	case 0x04E57Au:
		func_04E57A(a0);
		return;
	case 0x04E59Eu:
		func_04E59E(a0);
		return;
	case 0x04E5C2u:
		func_04E5C2(a0);
		return;
	case 0x04E5E6u:
		func_04E5E6(a0);
		return;
	case 0x04E60Au:
		func_04E60A(a0);
		return;
	case 0x04E62Eu:
		func_04E62E(a0);
		return;
	case 0x04E652u:
		func_04E652(a0);
		return;
	case 0x04E676u:
		func_04E676(a0);
		return;
	case 0x04E7CEu:
		func_04E7CE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E80Cu:
		func_04E80C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E84Au:
		func_04E84A(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E870u:
		func_04E870(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E8D8u:
		func_04E8D8(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E912u:
		func_04E912(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E94Cu:
		func_04E94C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E97Cu:
		func_04E97C(a0, a1);
		return;
	case 0x04E9A6u:
		func_04E9A6(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04E9DEu:
		func_04E9DE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EA26u:
		func_04EA26(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EA64u:
		func_04EA64(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EAA2u:
		func_04EAA2(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EAE0u:
		func_04EAE0(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EB1Cu:
		func_04EB1C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EB4Cu:
		func_04EB4C(a0, a1);
		return;
	case 0x04EB76u:
		func_04EB76(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EBAEu:
		func_04EBAE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04EBF4u:
		func_04EBF4(a0);
		return;
	case 0x04EC20u:
		func_04EC20(a0, p_d7, p_a5);
		return;
	case 0x04EC72u:
		*p_d7 = func_04EC72(*p_d7, a0);
		return;
	case 0x04ECAEu:
		*p_d7 = func_04ECAE(*p_d7, a0);
		return;
	case 0x04ECF4u:
		func_04ECF4(a0);
		return;
	case 0x04ED20u:
		func_04ED20(a0, p_d7, p_a5);
		return;
	case 0x04ED72u:
		func_04ED72(a0);
		return;
	case 0x04ED96u:
		func_04ED96(a0);
		return;
	case 0x04EDBAu:
		func_04EDBA(a0);
		return;
	case 0x04EDDEu:
		func_04EDDE(a0);
		return;
	case 0x04EE02u:
		func_04EE02(a0);
		return;
	case 0x04F094u:
		func_04F094(a0);
		return;
	case 0x04F0C0u:
		func_04F0C0(a0, p_d7, p_a5);
		return;
	case 0x04F10Au:
		func_04F10A(a0);
		return;
	case 0x04F11Au:
		func_04F11A(a0);
		return;
	case 0x04F150u:
		func_04F150(a0, p_d7, p_a5);
		return;
	case 0x04F186u:
		func_04F186(a0);
		return;
	case 0x04F2AEu:
		func_04F2AE(a0);
		return;
	case 0x04F2CEu:
		func_04F2CE(d0, a0, p_d5, p_d6, p_d7);
		return;
	case 0x04F318u:
		*p_d7 = func_04F318(*p_d7, a0);
		return;
	case 0x04F340u:
		func_04F340(a0);
		return;
	case 0x04F35Eu:
		func_04F35E(a0);
		return;
	case 0x04F380u:
		func_04F380(a0, p_d7, p_a5);
		return;
	case 0x04F736u:
		func_04F736(a0, a1);
		return;
	case 0x04F764u:
		func_04F764(a0, a1);
		return;
	case 0x04F792u:
		func_04F792(a0, a1);
		return;
	case 0x04F7ACu:
		func_04F7AC(a0);
		return;
	case 0x04F7C6u:
		func_04F7C6(a0, a1);
		return;
	case 0x04F7E0u:
		func_04F7E0(a0);
		return;
	case 0x04F802u:
		func_04F802(a0, a1);
		return;
	case 0x04F830u:
		func_04F830(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04F862u:
		func_04F862(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04F8B0u:
		func_04F8B0(a0, a1);
		return;
	case 0x04F8CCu:
		func_04F8CC(a0, a1);
		return;
	case 0x04F936u:
		func_04F936(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04F952u:
		func_04F952(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x04F9F2u:
		func_04F9F2(a0, p_d7, p_a5);
		return;
	case 0x04FA0Au:
		func_04FA0A(a0, p_d7, p_a5);
		return;
	case 0x04FAE6u:
		func_04FAE6(a0);
		return;
	case 0x04FB06u:
		func_04FB06(a0);
		return;
	case 0x04FB3Cu:
		func_04FB3C(a0);
		return;
	case 0x04FB82u:
		func_04FB82(a0);
		return;
	case 0x04FB86u:
		func_04FB86(a0);
		return;
	case 0x04FBEEu:
		func_04FBEE(a0);
		return;
	case 0x04FC1Cu:
		*p_d7 = func_04FC1C(*p_d7, a0);
		return;
	case 0x04FC4Au:
		func_04FC4A(a0);
		return;
	case 0x04FC76u:
		func_04FC76(a0);
		return;
	case 0x04FCE8u:
		*p_d7 = func_04FCE8(*p_d7, a0);
		return;
	case 0x04FD2Cu:
		func_04FD2C(a0);
		return;
	case 0x04FD60u:
		*p_d7 = func_04FD60(*p_d7, a0);
		return;
	case 0x04FDB8u:
		*p_a5 = func_04FDB8(a0, a1);
		return;
	case 0x04FE02u:
		func_04FE02(a0, p_d7, p_a5);
		return;
	case 0x04FE5Eu:
		func_04FE5E(a0);
		return;
	case 0x04FE7Au:
		func_04FE7A(a0);
		return;
	case 0x04FEC6u:
		func_04FEC6(a0);
		return;
	case 0x04FEFEu:
		func_04FEFE(a0);
		return;
	case 0x04FF5Eu:
		*p_d7 = func_04FF5E(*p_d7, a0, a1);
		return;
	case 0x04FF98u:
		*p_d7 = func_04FF98(*p_d7, a0);
		return;
	case 0x04FFCEu:
		func_04FFCE(a0);
		return;
	case 0x04FFFCu:
		*p_d7 = func_04FFFC(*p_d7, a0);
		return;
	case 0x050036u:
		func_050036(a0);
		return;
	case 0x0500AEu:
		*p_d7 = func_0500AE(*p_d7, a0, a1);
		return;
	case 0x0500F0u:
		*p_d7 = func_0500F0(*p_d7, a0);
		return;
	case 0x050152u:
		func_050152(a0);
		return;
	case 0x050180u:
		func_050180(a0);
		return;
	case 0x0502A6u:
		*p_d7 = func_0502A6(*p_d7, a0);
		return;
	case 0x0502DCu:
		func_0502DC(a0);
		return;
	case 0x0502F2u:
		*p_d7 = func_0502F2(*p_d7, a0);
		return;
	case 0x050320u:
		*p_d7 = func_050320(*p_d7, a0);
		return;
	case 0x050340u:
		*p_d7 = func_050340(*p_d7, a0);
		return;
	case 0x05036Eu:
		*p_d7 = func_05036E(*p_d7, a0);
		return;
	case 0x050392u:
		func_050392(a0);
		return;
	case 0x0503B2u:
		func_0503B2(a0, p_d7, p_a5);
		return;
	case 0x0506A2u:
		func_0506A2(a0, a1, p_d6, p_d7);
		return;
	case 0x0506D2u:
		func_0506D2(a0);
		return;
	case 0x0506ECu:
		func_0506EC(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x050708u:
		func_050708(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x050784u:
		func_050784(a0, a1);
		return;
	case 0x050802u:
		func_050802(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x05081Eu:
		func_05081E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0508F0u:
		func_0508F0(a0);
		return;
	case 0x050952u:
		func_050952(a0);
		return;
	case 0x050988u:
		func_050988(a0);
		return;
	case 0x0509CEu:
		func_0509CE(a0);
		return;
	case 0x0509D2u:
		*p_d7 = func_0509D2(*p_d7, a0);
		return;
	case 0x050AB8u:
		func_050AB8(a0);
		return;
	case 0x050AF0u:
		*p_d7 = func_050AF0(*p_d7, a0);
		return;
	case 0x050B38u:
		func_050B38(a0);
		return;
	case 0x050BA4u:
		*p_d7 = func_050BA4(*p_d7, a0);
		return;
	case 0x050BD2u:
		func_050BD2(a0);
		return;
	case 0x050BFEu:
		func_050BFE(a0);
		return;
	case 0x050C82u:
		func_050C82(a0);
		return;
	case 0x050CAEu:
		func_050CAE(a0, p_d7, p_a5);
		return;
	case 0x050CFAu:
		func_050CFA(a0);
		return;
	case 0x050D0Au:
		func_050D0A(a0);
		return;
	case 0x050D40u:
		func_050D40(a0);
		return;
	case 0x050D56u:
		func_050D56(a0);
		return;
	case 0x050DA4u:
		*p_d7 = func_050DA4(*p_d7, a0, a1);
		return;
	case 0x050DCCu:
		*p_d7 = func_050DCC(*p_d7, a0);
		return;
	case 0x050E00u:
		func_050E00(a0);
		return;
	case 0x050E2Eu:
		*p_d7 = func_050E2E(*p_d7, a0);
		return;
	case 0x050E8Eu:
		*p_d7 = func_050E8E(*p_d7, a0, a1);
		return;
	case 0x050EC0u:
		*p_d7 = func_050EC0(*p_d7, a0);
		return;
	case 0x050F20u:
		func_050F20(a0);
		return;
	case 0x050F4Eu:
		func_050F4E(a0);
		return;
	case 0x05103Au:
		func_05103A(a0);
		return;
	case 0x05106Eu:
		func_05106E(a0);
		return;
	case 0x0510B2u:
		*p_d7 = func_0510B2(*p_d7, a0);
		return;
	case 0x0510E4u:
		func_0510E4(a0);
		return;
	case 0x05135Cu:
		*p_d7 = func_05135C(*p_d7, a0);
		return;
	case 0x0513A2u:
		*p_d7 = func_0513A2(*p_d7, a0, a1);
		return;
	case 0x051404u:
		func_051404(a0);
		return;
	case 0x051414u:
		func_051414(a0);
		return;
	case 0x0514EEu:
		func_0514EE(a0);
		return;
	case 0x05152Cu:
		*p_d7 = func_05152C(*p_d7, a0);
		return;
	case 0x05156Cu:
		func_05156C(a0);
		return;
	case 0x051588u:
		func_051588(a0);
		return;
	case 0x0515D8u:
		func_0515D8(a0);
		return;
	case 0x051628u:
		func_051628(a0);
		return;
	case 0x051654u:
		*p_d7 = func_051654(*p_d7, a0);
		return;
	case 0x0516A0u:
		func_0516A0(a0);
		return;
	case 0x0516D2u:
		*p_d7 = func_0516D2(*p_d7, a0);
		return;
	case 0x05171Eu:
		func_05171E(a0);
		return;
	case 0x051774u:
		func_051774((uint8_t)d0, a0, p_d6, p_d7, p_a5);
		return;
	case 0x0517A0u:
		func_0517A0(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x051812u:
		func_051812(a0, p_d6, p_d7);
		return;
	case 0x05181Cu:
		func_05181C(a0);
		return;
	case 0x05183Eu:
		func_05183E((uint8_t)d0, a0, p_d7, p_a5);
		return;
	case 0x05185Cu:
		func_05185C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0518D4u:
		func_0518D4(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x05190Eu:
		func_05190E((uint8_t)d0, a0, p_d7, p_a5);
		return;
	case 0x05192Cu:
		func_05192C(a0, p_d6, p_d7);
		return;
	case 0x05194Cu:
		func_05194C(a0, a1);
		return;
	case 0x051980u:
		*p_d7 = func_051980(*p_d7, a0);
		return;
	case 0x0519E4u:
		*p_d7 = func_0519E4(*p_d7, a0);
		return;
	case 0x051A2Cu:
		*p_d7 = func_051A2C(*p_d7, a0, a1);
		return;
	case 0x051A6Cu:
		*p_d7 = func_051A6C(*p_d7, a0);
		return;
	case 0x051AB0u:
		func_051AB0(a0, a1);
		return;
	case 0x051CC8u:
		*p_d7 = func_051CC8(*p_d7, a0);
		return;
	case 0x051CFCu:
		func_051CFC(a0);
		return;
	case 0x051D36u:
		func_051D36(a0);
		return;
	case 0x051D72u:
		func_051D72(a0);
		return;
	case 0x05200Eu:
		func_05200E(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x05207Au:
		*p_d7 = func_05207A(a0);
		return;
	case 0x052116u:
		func_052116(a0);
		return;
	case 0x05214Eu:
		func_05214E(a0);
		return;
	case 0x052188u:
		*p_d7 = func_052188(a0);
		return;
	case 0x052244u:
		*p_d7 = func_052244(*p_d7, a0);
		return;
	case 0x052286u:
		func_052286(a0, p_d5, p_d6, p_d7);
		return;
	case 0x0522CCu:
		func_0522CC(a0);
		return;
	case 0x0522F0u:
		func_0522F0(a0, a1);
		return;
	case 0x052330u:
		*p_d7 = func_052330(*p_d7, a0);
		return;
	case 0x052378u:
		func_052378(a0);
		return;
	case 0x0523A8u:
		*p_d7 = func_0523A8(*p_d7, a0);
		return;
	case 0x0523C6u:
		func_0523C6(a0, p_d7, p_a5);
		return;
	case 0x05240Eu:
		func_05240E(a0);
		return;
	case 0x052484u:
		*p_d7 = func_052484(*p_d7, a0);
		return;
	case 0x05248Cu:
		func_05248C(a0, p_d5, p_d6, p_d7);
		return;
	case 0x052494u:
		*p_d7 = func_052494(*p_d7, a0);
		return;
	case 0x0524D2u:
		func_0524D2(a0, p_d7, p_a5);
		return;
	case 0x052530u:
		*p_d7 = func_052530(*p_d7, a0);
		return;
	case 0x0525D0u:
		*p_d7 = func_0525D0(a0);
		return;
	case 0x0525E6u:
		func_0525E6(a0);
		return;
	case 0x052624u:
		*p_d7 = func_052624(*p_d7, a0, a1);
		return;
	case 0x05265Cu:
		*p_d7 = func_05265C(*p_d7, a0);
		return;
	case 0x05268Au:
		func_05268A(a0);
		return;
	case 0x0526CCu:
		*p_d7 = func_0526CC(*p_d7, a0, a1);
		return;
	case 0x052704u:
		*p_d7 = func_052704(*p_d7, a0);
		return;
	case 0x05273Cu:
		func_05273C(a0);
		return;
	case 0x052756u:
		func_052756(a0, a1);
		return;
	case 0x052CAEu:
		*p_d7 = func_052CAE(*p_d7, a0);
		return;
	case 0x052CDCu:
		*p_d7 = func_052CDC(*p_d7, a0);
		return;
	case 0x052D20u:
		*p_d7 = func_052D20(*p_d7, a0);
		return;
	case 0x052D62u:
		func_052D62(a0, p_d7, p_a5);
		return;
	case 0x052DB2u:
		func_052DB2(a0);
		return;
	case 0x052DE4u:
		func_052DE4(a0);
		return;
	case 0x052E1Au:
		*p_d7 = func_052E1A(*p_d7, a0);
		return;
	case 0x052E84u:
		func_052E84(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x052EAEu:
		func_052EAE(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x052F20u:
		func_052F20(a0);
		return;
	case 0x052F52u:
		func_052F52(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x052F80u:
		func_052F80(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x052FECu:
		func_052FEC(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x053016u:
		func_053016(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x053084u:
		func_053084(a0);
		return;
	case 0x0530B0u:
		*p_d6 = func_0530B0(*p_d6, a0);
		return;
	case 0x053102u:
		func_053102(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x05314Cu:
		func_05314C(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x053198u:
		func_053198(a0, a1);
		return;
	case 0x0531C8u:
		func_0531C8(a0);
		return;
	case 0x0531E4u:
		func_0531E4(a0, p_d7, p_a5);
		return;
	case 0x053256u:
		func_053256(a0);
		return;
	case 0x0532AAu:
		func_0532AA(a0);
		return;
	case 0x0532E8u:
		func_0532E8(a0);
		return;
	case 0x053368u:
		*p_d7 = func_053368(*p_d7, a0, a1);
		return;
	case 0x053398u:
		*p_d7 = func_053398(*p_d7, a0);
		return;
	case 0x0533D2u:
		*p_d7 = func_0533D2(*p_d7, a0);
		return;
	case 0x053422u:
		func_053422(a0);
		return;
	case 0x05343Eu:
		func_05343E();
		return;
	case 0x053458u:
		func_053458(a0, a1);
		return;
	case 0x053482u:
		func_053482(a0);
		return;
	case 0x053496u:
		func_053496(a0);
		return;
	case 0x0534D8u:
		*p_d7 = func_0534D8(*p_d7, a0);
		return;
	case 0x05350Eu:
		func_05350E(a0);
		return;
	case 0x053538u:
		*p_d7 = func_053538(*p_d7, a0);
		return;
	case 0x053582u:
		*p_d7 = func_053582(*p_d7, a0);
		return;
	case 0x0535CCu:
		*p_d7 = func_0535CC(*p_d7, a0);
		return;
	case 0x053628u:
		func_053628(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x053644u:
		func_053644(a0, a1, p_d6, p_d7, p_a5);
		return;
	case 0x0536CAu:
		func_0536CA(a0);
		return;
	case 0x0536EAu:
		func_0536EA(a0, p_d7, p_a5);
		return;
	case 0x05373Au:
		func_05373A(a0);
		return;
	}
}

void func_048244(uint32_t a0)
{
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Eu));
	func_04824C(a0);
}

void func_04824C(uint32_t a0)
{
	uint32_t t1 = 0, t2 = 0;

	t1 = mem_read32(a0 + 0x12u) + (int16_t)mem_read16(a0 + 0x1Au);
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read32(a0 + 0x16u) + (int16_t)mem_read16(a0 + 0x1Cu);
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
}

void func_048262(uint32_t a0)
{
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Eu));
	func_04826A(a0);
}

void func_04826A(uint32_t a0)
{
	uint32_t d0 = 0;
	uint32_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = (int16_t)mem_read16(a0 + 0x1Au);
	d0 = t1;
	if ((int32_t)t1 >= 0)
	{
		if ((mem_read8(a0 + 1u) & 8u) == 0u)
		{
			t2 = mem_read32(a0 + 0x12u) + d0;
			mem_write16(a0 + 0x14u, t2);
			mem_write16(a0 + 0x12u, t2 >> 16);
		}
	}
	else if ((mem_read8(a0 + 1u) & 0x10u) == 0u)
	{
		t2 = mem_read32(a0 + 0x12u) + d0;
		mem_write16(a0 + 0x14u, t2);
		mem_write16(a0 + 0x12u, t2 >> 16);
		t3 = (int16_t)mem_read16(a0 + 0x1Cu);
		d0 = t3;
		if ((int32_t)t3 < 0)
		{
			if ((mem_read8(a0 + 1u) & 4u) == 0u)
			{
				t4 = mem_read32(a0 + 0x16u) + d0;
				mem_write16(a0 + 0x18u, t4);
				mem_write16(a0 + 0x16u, t4 >> 16);
			}
			return;
		}
		if ((mem_read8(a0 + 1u) & 2u) != 0u)
			return;
		t4 = mem_read32(a0 + 0x16u) + d0;
		mem_write16(a0 + 0x18u, t4);
		mem_write16(a0 + 0x16u, t4 >> 16);
		return;
	}
	t3 = (int16_t)mem_read16(a0 + 0x1Cu);
	d0 = t3;
	if ((int32_t)t3 < 0)
	{
		if ((mem_read8(a0 + 1u) & 4u) == 0u)
		{
			t4 = mem_read32(a0 + 0x16u) + d0;
			mem_write16(a0 + 0x18u, t4);
			mem_write16(a0 + 0x16u, t4 >> 16);
		}
		return;
	}
	if ((mem_read8(a0 + 1u) & 2u) != 0u)
		return;
	t4 = mem_read32(a0 + 0x16u) + d0;
	mem_write16(a0 + 0x18u, t4);
	mem_write16(a0 + 0x16u, t4 >> 16);
}

void func_0482B6(uint32_t a0, uint32_t *p_d3, uint32_t *p_d7, uint32_t *p_a6)
{
	uint32_t d3 = *p_d3;
	uint32_t d7 = *p_d7;
	uint32_t a6 = *p_a6;
	uint16_t d1 = 0, d2 = 0;
	uint32_t d3_2 = 0;
	uint16_t t1 = 0;

	d1 = mem_read16(a0 + 0x2Cu);
	if (d1 >= 0x100u)
		d3_2 = 0xFFFFFFFFu;
	else
	{
		d2 = mem_read16(a0 + 0x2Eu);
		if (d2 >= 0x100u)
			d3_2 = 0xFFFFFFFFu;
		else
		{
			d7 = 3u;
			for (;;)
			{
				if (mem_read8(a6) < (uint8_t)d2)
				{
					d3_2 = 0xFFFFFFFFu;
					break;
				}
				if ((uint8_t)d1 < mem_read8(a6 + 1u) || mem_read8(a6 + 2u) < (uint8_t)d1)
				{
					t1 = d7 - 1u;
					d7 = t1;
					a6 += 0xCu;
					if (t1 != 0xFFFFu)
						continue;
					d3_2 = 0xFFFFFFFFu;
					break;
				}
				d3_2 = (d3 & ~0xFFu) | mem_read8(a6 + 3u);
				break;
			}
		}
	}
	*p_d3 = d3_2;
	*p_d7 = d7;
	*p_a6 = a6;
}

void func_0482FA(uint32_t a0, uint32_t a6, uint32_t *p_d1, uint32_t *p_d2)
{
	uint8_t d0 = 0, d3 = 0;
	uint16_t d1 = 0, d2 = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	d2 = mem_read16(a6 + 0xEu);
	d0 = 0u;
	t1 = mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu);
	d1 = t1;
	if ((int16_t)t1 < 0)
	{
		d1 = (uint16_t)(0u - d1);
		d0 = 0x40u;
	}
	d3 = mem_read8(a6) ^ d0;
	t2 = d2 - mem_read16(a0 + 0xEu);
	d2 = t2;
	if ((int16_t)t2 >= 0)
		d0 ^= 0xC0u;
	else
		d2 = (uint16_t)(0u - d2);
	if ((d0 & 0x40u) != 0u)
	{
		if (d2 <= d1)
			d0 |= 0x20u;
	}
	else if (d1 <= d2)
		d0 |= 0x20u;
	mem_write8(a0 + 0x2Bu, d0);
	mem_write16(a0 + 0x2Cu, d1);
	mem_write16(a0 + 0x2Eu, d2);
	t3 = (uint32_t)d3 << 1;
	d3 = t3;
	if ((int8_t)t3 >= 0 && d2 < 6u && d1 < 0x40u)
		mem_write8(a6 + 0x44u, 0xFFu);
	mem_write8(a0 + 0x44u, d3);
	*p_d1 = (*p_d1 & 0xFFFF0000u) | d1;
	*p_d2 = (*p_d2 & 0xFFFF0000u) | d2;
}

void func_04835E(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t a6 = *p_a6;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a4 = 0, d6_2 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;
	uint32_t t3 = 0;

	if (unk_061207 == 0u)
	{
		a6 = unk_06122E;
		a5 = unk_061232;
	}
	else
	{
		d7 = 3u;
		a4 = unk_062000_ADDRESS;
		d5 = 0xFFFFFFFFu;
		d6 = 0xFFFFFFFFu;
		do
		{
			if (mem_read8(a4) != 0u)
			{
				t1 = mem_read16(a0 + 0xCu) - mem_read16(a4 + 0xCu);
				d0 = t1;
				if ((int16_t)t1 < 0)
					d0 = (uint16_t)(0u - d0);
				t2 = mem_read16(a0 + 0xEu) - mem_read16(a4 + 0xEu);
				d1 = t2;
				if ((int16_t)t2 < 0)
					d1 = (uint16_t)(0u - d1);
				d0 += d1;
				if ((uint16_t)d6 <= d0)
				{
					if (d0 < (uint16_t)d5)
					{
						d5 = (d5 & ~0xFFFFu) | d0;
						a5 = a4;
					}
				}
				else
				{
					t3 = d6;
					d6_2 = d5;
					d5 = t3;
					a5 = a6;
					d6 = (d6_2 & ~0xFFFFu) | d0;
					a6 = a4;
				}
			}
			t4 = d7 - 1u;
			d7 = t4;
			a4 += 0x50u;
		} while (t4 != 0xFFFFu);
		unk_06122E = a6;
		unk_061232 = a5;
	}
	*p_d5 = d5;
	*p_d6 = d6;
	*p_d7 = d7;
	*p_a5 = a5;
	*p_a6 = a6;
}

void func_0483D2(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5, uint32_t *p_a6)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t a6 = *p_a6;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a3 = 0, a4 = 0, d6_2 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;
	uint32_t t3 = 0;

	if (unk_061207 == 0u)
	{
		a6 = unk_061226;
		a5 = unk_06122A;
	}
	else
	{
		d7 = 3u;
		a3 = unk_062FA0_ADDRESS;
		d5 = 0xFFFFFFFFu;
		d6 = 0xFFFFFFFFu;
		do
		{
			a4 = mem_read32(a3);
			if (mem_read8(a4) != 0u)
			{
				t1 = mem_read16(a0 + 0xCu) - mem_read16(a4 + 0xCu);
				d0 = t1;
				if ((int16_t)t1 < 0)
					d0 = (uint16_t)(0u - d0);
				t2 = mem_read16(a0 + 0xEu) - mem_read16(a4 + 0xEu);
				d1 = t2;
				if ((int16_t)t2 < 0)
					d1 = (uint16_t)(0u - d1);
				d0 += d1;
				if ((uint16_t)d6 <= d0)
				{
					if (d0 < (uint16_t)d5)
					{
						d5 = (d5 & ~0xFFFFu) | d0;
						a5 = a3;
					}
				}
				else
				{
					t3 = d6;
					d6_2 = d5;
					d5 = t3;
					a5 = a6;
					d6 = (d6_2 & ~0xFFFFu) | d0;
					a6 = a3;
				}
			}
			t4 = d7 - 1u;
			d7 = t4;
			a3 += 0x10u;
		} while (t4 != 0xFFFFu);
		unk_061226 = a6;
		unk_06122A = a5;
	}
	*p_d5 = d5;
	*p_d6 = d6;
	*p_d7 = d7;
	*p_a5 = a5;
	*p_a6 = a6;
}

void func_048448(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint16_t d6 = 0;
	uint32_t d7_2 = 0;

	d6 = (uint16_t)d7;
	d7_2 = (uint16_t)(unk_06120E + unk_0600A4 - mem_read16(a0 + 0x14u) + mem_read16(a0 + 0xEu) - mem_read16(a0 + 0x18u) + mem_read16(a0 + 0xCu) + 0x4ACBu) * 0x17u;
	unk_06120E = d7_2;
	d7_2 = ((uint32_t)(uint16_t)d7_2 * d6) & ~0xFFFFu;
	d7_2 = (d7_2 << 16) | (d7_2 >> 16);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
	*p_d7 = d7_2;
}

void unreached_048480(uint32_t a0, uint32_t a5)
{
	uint16_t d1 = 0, d2 = 0;

	d1 = mem_read16(a0 + 0x2Cu);
	d2 = mem_read16(a0 + 0x2Eu);
	if (d1 <= d2)
		d1 = (uint16_t)d2;
}

void func_0484B2(uint8_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = 0;

	func_048516(d0, a0, a6, &d6, p_d7);
	*p_a5 = func_0484B6((uint8_t)*p_d7, a0, *p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_0484B6(uint8_t d7, uint32_t a0, uint32_t a5)
{
	uint32_t a6 = 0;

	if ((int8_t)d7 < 0)
		a5 += 4u;
	a6 = mem_read32(a5);
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((d7 & 0x40u) != 0u)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 0x30u, d7);
	return a5;
}

void func_0484E2(uint8_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = 0;

	func_048516(d0, a0, a6, &d6, p_d7);
	*p_a5 = func_0484E6((uint8_t)*p_d7, a0, *p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_0484E6(uint8_t d7, uint32_t a0, uint32_t a5)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x30u) ^ d7;
	mem_write8(a0 + 0x30u, t1);
	if ((int8_t)t1 >= 0)
	{
		if ((mem_read8(a0 + 0x30u) & 0x40u) != 0u)
			mem_write8(a0, mem_read8(a0) ^ 0x40u);
		mem_write8(a0 + 0x30u, d7);
		return a5;
	}
	if ((int8_t)d7 < 0)
		a5 += 4u;
	a6 = mem_read32(a5);
	set_animation(0u, a0, a6);
	if ((mem_read8(a0 + 0x30u) & 0x40u) != 0u)
		mem_write8(a0, mem_read8(a0) ^ 0x40u);
	mem_write8(a0 + 0x30u, d7);
	return a5;
}

void func_048516(uint8_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint16_t d6 = 0;
	uint16_t t1 = 0;

	d7 &= ~0xFFFFu;
	t1 = mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu);
	d6 = t1;
	if ((int16_t)t1 >= 0 && d6 >= 4u)
		d7 |= 0x80u;
	if ((int8_t)(d0 - 0x40u) < 0)
		d7 |= 0x40u;
	*p_d6 = (*p_d6 & 0xFFFF0000u) | d6;
	*p_d7 = d7;
}

void func_04853E(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;

	d7 = func_04854C(d0, d7);
	*p_a5 = func_0484B6((uint8_t)d7, a0, *p_a5);
	*p_d7 = d7;
}

void func_048546(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;

	d7 = func_04854C(d0, d7);
	*p_a5 = func_0484E6((uint8_t)d7, a0, *p_a5);
	*p_d7 = d7;
}

uint32_t func_04854C(uint8_t d0, uint32_t d7)
{
	d7 &= ~0xFFu;
	if ((uint8_t)d0 >= 0x84u && (uint8_t)d0 < 0xFDu)
		d7 |= 0x80u;
	if ((int8_t)(d0 - 0x40u) < 0)
		d7 |= 0x40u;
	return d7;
}

void func_048570(uint32_t a0)
{
	if (mem_read16(a0 + 0xCu) >= 0x170u)
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 8u);
	if (mem_read16(a0 + 0xCu) < 0x80u)
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x10u);
}

void func_048592(uint32_t a0, uint32_t *p_d7, uint32_t *p_zero)
{
	uint32_t zero = *p_zero;

	if (mem_read16(a0 + 0xCu) >= 0x190u || mem_read16(a0 + 0xCu) < 0x70u)
	{
		zero = 0xFFFFFFFFu == 0u;
		*p_d7 = 0xFFFFFFFFu;
	}
	else
	{
		zero = 1u;
		*p_d7 &= ~0xFFu;
	}
	*p_zero = zero;
}

uint32_t func_0485AE(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | unk_060130;
	d7_2 = d7_2 & ~0xFFF8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 1);
	mem_write16(a0 + 8u, mem_read16(a6 + (uint16_t)d7_2));
	return d7_2;
}

uint32_t func_0485C2(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | unk_060130;
	d7_2 = d7_2 & ~0xFFF8u;
	d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(d7_2 << 1);
	mem_write8(a0 + 9u, mem_read8(a6 + 1u + (uint16_t)d7_2));
	return d7_2;
}

uint32_t func_0485D6(uint32_t d7, uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		d7 = d7 | 0x80u;
	}
	mem_write8(a0 + 6u, d7);
	return d7;
}

void func_0485F6(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0 + 0x22u, 0u);
}

void func_048608(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0 + 0x22u, 0u);
}

void func_04861A(uint32_t a0, uint32_t *p_d7, uint32_t *p_zero)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = *p_zero;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 0x10u);
	if ((uint8_t)d7_2 >= 0xF0u || (uint8_t)d7_2 < mem_read8(a0 + 0x32u))
	{
		mem_write8(a0 + 0x10u, mem_read8(a0 + 0x32u));
		zero = 1u;
		mem_write8(a0 + 0x11u, 0u);
	}
	else
	{
		zero = 0xFFFFFFFFu == 0u;
		d7_2 = 0xFFFFFFFFu;
	}
	*p_d7 = d7_2;
	*p_zero = zero;
}

uint32_t func_04863E(uint32_t d7, uint32_t a0, uint32_t a6)
{
	uint32_t d7_2 = 0;
	uint32_t t1 = 0, t2 = 0;

	mem_write16(a0 + 0x1Au, mem_read16(a6));
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, mem_read16(a6 + 4u));
	d7_2 = (d7 & ~0xFFFFu) | mem_read16(a6 + 8u);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		d7_2 = (d7_2 & ~0xFFFFu) | (uint16_t)(0u - d7_2);
	}
	if (unk_060120 == 7u && mem_read8(a0 + 0x32u) != 0u)
		return d7_2;
	t1 = (int16_t)d7_2;
	d7_2 = t1;
	if ((int32_t)t1 >= 0)
	{
		if ((mem_read8(a0 + 1u) & 8u) == 0u)
		{
			t2 = mem_read32(a0 + 0x12u) + d7_2;
			mem_write16(a0 + 0x14u, t2);
			mem_write16(a0 + 0x12u, t2 >> 16);
		}
		return d7_2;
	}
	if ((mem_read8(a0 + 1u) & 0x10u) != 0u)
		return d7_2;
	t2 = mem_read32(a0 + 0x12u) + d7_2;
	mem_write16(a0 + 0x14u, t2);
	mem_write16(a0 + 0x12u, t2 >> 16);
	return d7_2;
}

void func_048696(uint32_t a0, uint32_t a6)
{
	uint16_t d0 = 0, d1 = 0;

	d0 = mem_read16(a6 + 2u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		d0 = (uint16_t)(0u - d0);
	d1 = (uint16_t)d0;
	d0 += mem_read16(a0 + 0x1Au);
	if ((int16_t)(d1 ^ d0) < 0)
		mem_write16(a0 + 0x1Au, d0);
	d0 = (uint16_t)(mem_read16(a6 + 6u) + mem_read16(a0 + 0x1Eu));
	if ((int16_t)mem_read16(a6 + 0xAu) <= (int16_t)d0)
		mem_write16(a0 + 0x1Eu, d0);
}

void func_0486CC(uint32_t a0, uint32_t a1)
{
	if (mem_read8(a0 + 0x2Au) != 1u)
		return;
	func_0486D6(a0, a1);
}

void func_0486D6(uint32_t a0, uint32_t a1)
{
	uint8_t d0 = 0;
	uint8_t t1 = 0;

	d0 = 0x7Fu;
	t1 = mem_read8(a0 + 0x45u);
	mem_write8(a0 + 0x45u, t1 & 0x7Fu);
	if ((t1 & 0x80u) != 0u)
		d0 = 0xBFu;
	mem_write8(a1 + 5u, mem_read8(a1 + 5u) & d0);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x22u, 0u);
}

void func_0486F6(uint32_t a0, uint32_t a6, uint32_t *p_d0, uint32_t *p_d7)
{
	uint16_t d0 = 0, d7 = 0;
	uint32_t a6_2 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	mem_write8(a0 + 0x30u, (uint8_t)d0);
	d7 = d0 >> 3;
	a6_2 = mem_read32(a6 + d7);
	set_animation(0u, a0, a6_2);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(d0 - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	*p_d0 = (*p_d0 & 0xFFFF0000u) | d0;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
}

void func_048724(uint8_t d7, uint32_t a0)
{
	if (mem_read8(a0 + 8u) <= 6u)
	{
		mem_write8(a0 + 0x42u, d7);
		if ((unk_0600A4 & 4u) != 0u)
			mem_write8(a0 + 0x42u, 0xFFu);
	}
}

void func_048746(uint32_t a0)
{
	if (unk_060120 != 3u || mem_read32(a0 + 0x16u) < 0x5800u)
	{
		mem_write8(a0 + 0x32u, 0u);
		return;
	}
	mem_write8(a0 + 0x32u, 0x18u);
}

void func_04876C(uint32_t a0, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t a6 = 0;

	if ((mem_read8(a0) & 0x20u) != 0u || (int16_t)mem_read16(a0 + 0xEu) < 8)
	{
		*p_d0 = 1u;
		*p_d1 = 1u;
		*p_d2 = 1u;
		*p_d3 = 1u;
	}
	else
	{
		func_01DE3E(a0, &d5, &d6, p_a5, &a6);
		unk_061248 = a6;
		if (unk_0633D3 >= 0xFDu)
		{
			func_048798(a0, p_d0, p_d1, p_d2, p_d3, p_d7);
			*p_a5 = 0x4881Bu;
			mem_write8(a0 + 1u, mem_read8(a0 + 1u) & mem_read8(0x4881Bu + (int16_t)(int8_t)unk_0633D3));
		}
		else
			func_048798(a0, p_d0, p_d1, p_d2, p_d3, p_d7);
	}
	*p_d5 = (*p_d5 & 0xFFFF0000u) | (d5 & 0xFFFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_048798(uint32_t a0, uint32_t *p_d0, uint32_t *p_d1, uint32_t *p_d2, uint32_t *p_d3, uint32_t *p_d7)
{
	uint32_t d7 = *p_d7;
	uint8_t d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	d7 &= ~0xFFu;
	t1 = unk_0633D5;
	d0 = t1;
	if ((int8_t)t1 < 0 && d0 == unk_0633DA)
		d7 = 8u;
	t2 = unk_0633D6;
	d1 = t2;
	if ((int8_t)t2 < 0 && d1 == unk_0633DB)
		d7 |= 0x10u;
	t3 = unk_0633D4;
	d2 = t3;
	if ((int8_t)t3 < 0 && d2 == unk_0633D9)
		d7 |= 2u;
	t4 = unk_061118;
	d3 = t4;
	if ((int8_t)t4 < 0)
		d7 |= 4u;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | d7);
	*p_d0 = (*p_d0 & 0xFFFFFF00u) | d0;
	*p_d1 = (*p_d1 & 0xFFFFFF00u) | d1;
	*p_d2 = (*p_d2 & 0xFFFFFF00u) | d2;
	*p_d3 = (*p_d3 & 0xFFFFFF00u) | d3;
	*p_d7 = d7;
}

void func_04883A(uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_zero)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = *p_zero;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0;

	d7_2 = (uint16_t)((d7 & ~0xFFu) | mem_read8(a0 + 0x32u));
	if ((uint8_t)d7_2 != mem_read8(a0 + 0x10u))
	{
		if (unk_060120 == 3u)
		{
			if (mem_read8(a0 + 0x18u) >= 0x4Bu)
			{
				mem_write16(a0 + 0x10u, 0x1800u);
				mem_write8(a0 + 0x32u, 0x18u);
			}
			else
			{
				mem_write16(a0 + 0x10u, 0u);
				mem_write8(a0 + 0x32u, 0u);
			}
		}
		zero = 1u;
		d7_2 = 0u;
	}
	else if ((mem_read8(a0 + 1u) & 1u) == 0u)
	{
		a6 = mem_read32(a1);
		if ((uint8_t)d7_2 == mem_read8(a6 + 0x32u))
		{
			zero = 1u;
			d7_2 = 0u;
		}
		else if (mem_read8(a6 + 0x32u) <= (uint8_t)d7_2)
		{
			if ((uint8_t)d3 != 0xFCu)
			{
				if ((uint8_t)d0 != 0xFAu)
				{
					if ((uint8_t)d1 != 0xFBu)
					{
						zero = 1u;
						d7_2 = 0u;
					}
					else
					{
						mem_write16(a0 + 0x28u, 0x14u);
						zero = 0x600u == 0u;
						mem_write16(a0 + 4u, 0x600u);
					}
				}
				else
				{
					mem_write16(a0 + 0x28u, 0x10u);
					zero = 0x600u == 0u;
					mem_write16(a0 + 4u, 0x600u);
				}
			}
			else
			{
				mem_write16(a0 + 0x28u, 0xCu);
				zero = 0x600u == 0u;
				mem_write16(a0 + 4u, 0x600u);
			}
		}
		else if ((uint8_t)d0 != 0xFBu)
		{
			if ((uint8_t)d1 != 0xFAu)
			{
				if ((uint8_t)d2 != 0xFCu)
				{
					zero = 1u;
					d7_2 = 0u;
				}
				else
				{
					mem_write16(a0 + 0x28u, 0u);
					zero = 0x600u == 0u;
					mem_write16(a0 + 4u, 0x600u);
				}
			}
			else
			{
				mem_write16(a0 + 0x28u, 8u);
				zero = 0x600u == 0u;
				mem_write16(a0 + 4u, 0x600u);
			}
		}
		else
		{
			mem_write16(a0 + 0x28u, 4u);
			zero = 0x600u == 0u;
			mem_write16(a0 + 4u, 0x600u);
		}
	}
	else
	{
		mem_write16(a0 + 0x28u, 0x18u);
		zero = 0x600u == 0u;
		mem_write16(a0 + 4u, 0x600u);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_2;
	*p_zero = zero;
}

void func_04890E(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	a6 = unk_061248;
	d0 = unk_0633D3;
	if (d0 < 0xFAu || d0 >= 0xFCu)
		return;
	if (d0 == unk_0633D4)
	{
		func_048994(a0, a6);
		return;
	}
	func_048954(a0, a6);
}

void func_048938(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	a6 = unk_061248;
	d0 = unk_0633D3;
	if (d0 < 0xFAu || d0 >= 0xFDu)
		return;
	func_048954(a0, a6);
}

void func_048954(uint32_t a0, uint32_t a6)
{
	uint8_t t1 = 0;

	do
	{
		t1 = mem_read8(a0 + 0x32u);
		mem_write8(a0 + 0x32u, t1 - 8u);
		if (t1 < 8u)
			mem_write8(a0 + 0x32u, 0u);
		a6 += 0x40u;
		if (a6 >= unk_062000_ADDRESS)
			a6 -= 0x800u;
	} while ((int8_t)mem_read8(a6) < 0);
}

void func_04897C(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	a6 = unk_061248;
	d0 = unk_0633D3;
	if (d0 < 0xFAu || d0 >= 0xFDu)
		return;
	func_048994(a0, a6);
}

void func_048994(uint32_t a0, uint32_t a6)
{
	uint8_t d0 = 0;

	do
	{
		mem_write8(a0 + 0x32u, mem_read8(a0 + 0x32u) + 8u);
		d0 = unk_06124C;
		if (d0 < mem_read8(a0 + 0x32u))
			mem_write8(a0 + 0x32u, d0);
		a6 -= 0x40u;
		if (a6 < 0x61800u)
			a6 += 0x800u;
	} while ((int8_t)mem_read8(a6) < 0);
}

void func_0489E2(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	func_048746(a0);
	unk_06120C++;
	func_0489EE(a0, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0489EE(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6_2 = 0;
	uint8_t t1 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0 + 0x4Bu, 0x84u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, enemy_definitions_ADDRESS);
	t1 = mem_read8(a0 + 3u);
	d0 = t1;
	if (t1 != 0u)
	{
		mem_write16(a0 + 0x28u, (uint32_t)d0 << 2);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		return;
	}
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = animations_0547C6_ADDRESS;
	set_animation(0u, a0, a6_2);
}

void func_048A60(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t a1 = 0, a6 = 0, d6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = mem_read32(a1);
	func_0482FA(a0, a6, &ignored, &ignored_2);
	func_047662(a0, p_d5, &d6, p_d7, p_a5);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, &d6, p_d7, p_a5);
	d6_2 = (d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	a6 = mem_read32(0x53ED6u + (int16_t)d6_2);
	*p_d6 = d6_2;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
	*p_a1 = a1;
}

void func_048A94(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_048BCA = false, L_048CC0 = false;
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6_2 = 0, d0_2 = 0, d1 = 0, d2 = 0, d3 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t11 = 0, t12 = 0;
	uint16_t t10 = 0, t13 = 0;
	uint32_t t2 = 0, t3 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	t1 = mem_read8(a0 + 0x23u);
	mem_write8(a0 + 0x23u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x23u, 0x10u);
		if (unk_061207 != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
			d0 = unk_06120D;
			if (d0 <= mem_read8(a6 + 4u))
			{
				t2 = *p_a5;
				*p_a5 = a6;
				a6 = t2;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = unk_061208;
					if (d0 <= mem_read8(a6 + 4u))
					{
						t3 = *p_a5;
						*p_a5 = a6;
						a6 = t3;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != mem_read16(a0 + 0x20u))
				func_0486CC(a0, *p_a1);
			mem_write16(a0 + 0x20u, a6);
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	if (unk_06131D != 0u)
	{
		mem_write16(a0, 0u);
		t4 = unk_06120C - 1u;
		unk_06120C = t4;
		if ((int8_t)t4 < 0)
			unk_06120C = 0u;
		return;
	}
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		func_0486CC(a0, *p_a1);
		mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
		mem_write16(a0, 0u);
		t4 = unk_06120C - 1u;
		unk_06120C = t4;
		if ((int8_t)t4 < 0)
			unk_06120C = 0u;
		return;
	}
	t5 = mem_read8(a0 + 0x32u);
	*p_d7 = (*p_d7 & ~0xFFFFu) | t5;
	if (t5 != 0u)
	{
		*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)(*p_d7 + mem_read16(a0 + 0xEu));
		if ((int16_t)*p_d7 >= 0xF0)
		{
			func_0486CC(a0, *p_a1);
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			mem_write16(a0, 0u);
			t4 = unk_06120C - 1u;
			unk_06120C = t4;
			if ((int8_t)t4 < 0)
				unk_06120C = 0u;
			return;
		}
	}
	a6_2 = mem_read32(*p_a1);
	func_0482FA(a0, a6_2, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &d0_2, &d1, &d2, &d3, p_d5, p_d6, p_d7, p_a5);
	func_04883A((uint8_t)d0_2, (uint8_t)d1, (uint8_t)d2, (uint8_t)d3, a0, *p_a1, p_d7, &zero);
	if (zero == 0u)
	{
		return;
	}
	if (mem_read8(a0 + 0x2Au) != 0u)
	{
		if (mem_read8(a0 + 0x2Au) != 1u)
		{
			if (mem_read8(a0 + 0x2Au) == 2u && mem_read8(*p_a1 + 5u) < 0xC0u)
			{
				mem_write8(a0 + 0x2Au, 0u);
				mem_write8(a0 + 0x22u, 0u);
			}
		}
		else if (mem_read16(a0 + 0x2Cu) >= 0x50u || mem_read16(a0 + 0x2Eu) >= 0x50u)
			func_0486D6(a0, *p_a1);
	}
	else if (mem_read8(*p_a1 + 5u) < 0xC0u)
	{
		if (mem_read16(a0 + 0x2Cu) < 0x40u && mem_read16(a0 + 0x2Eu) < 0x40u)
		{
			mem_write8(a0 + 0x2Au, 1u);
			mem_write8(a0 + 0x22u, 0u);
			do
			{
				if (L_048BCA || (int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
				{
					for (;;)
					{
						L_048BCA = false;
						t6 = mem_read8(*p_a1 + 5u);
						mem_write8(*p_a1 + 5u, t6 | 0x40u);
						if ((t6 & 0x40u) != 0u)
						{
							t7 = mem_read8(*p_a1 + 5u);
							mem_write8(*p_a1 + 5u, t7 | 0x80u);
							if ((t7 & 0x80u) != 0u)
								continue;
							mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
							break;
						}
						mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x80u);
						break;
					}
				}
				else
				{
					t7 = mem_read8(*p_a1 + 5u);
					mem_write8(*p_a1 + 5u, t7 | 0x80u);
					L_048BCA = (t7 & 0x80u) != 0u;
					if (!L_048BCA)
						mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
				}
			} while (L_048BCA);
		}
	}
	else
	{
		mem_write8(a0 + 0x2Au, 2u);
		mem_write8(a0 + 0x22u, 0u);
	}
	if (mem_read8(a0 + 0x2Au) != 1u)
		L_048CC0 = true;
	else
	{
		a6_2 = mem_read32(*p_a1);
		if (mem_read8(a6_2 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] != 0u)
		{
			L_048CC0 = mem_read8(mem_read32(*p_a1) + 4u) != 3u || mem_read16(a0 + 0x2Eu) >= 8u || (int8_t)mem_read8(a0 + 0x44u) >= 0;
			if (!L_048CC0)
			{
				*p_d7 = 0x64u;
				func_048448(a0, p_d6, p_d7);
				L_048CC0 = mem_read8(a0 + 0x31u) <= (uint8_t)*p_d7;
				if (!L_048CC0)
				{
					func_0486D6(a0, *p_a1);
					mem_write8(a0 + 0x2Au, 4u);
					mem_write8(a0 + 0x22u, 0u);
				}
			}
		}
		else
		{
			func_0486D6(a0, *p_a1);
			mem_write8(a0 + 0x2Au, 3u);
			mem_write8(a0 + 0x22u, 0u);
		}
	}
	if (L_048CC0)
	{
		func_048592(a0, p_d7, &zero);
		if (zero)
		{
			a6_2 = mem_read32(*p_a1);
			if (mem_read8(a6_2 + 4u) != 4u || (int8_t)indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] < 0)
			{
				a6_2 = mem_read32(a0 + 0x24u) + 0x28u;
				func_0482B6(a0, &d3, p_d7, &a6_2);
				if ((int8_t)d3 >= 0)
				{
					*p_d7 = 0x64u;
					func_048448(a0, p_d6, p_d7);
					if ((uint8_t)*p_d7 < (uint8_t)d3)
					{
						*p_d7 = 0x64u;
						func_048448(a0, &ignored_3, p_d7);
						*p_d6 = 3u;
						do
						{
							t8 = mem_read8(a6_2 + 8u + (int16_t)*p_d6);
							t9 = *p_d7;
							*p_d7 = (*p_d7 & ~0xFFu) | (uint8_t)(t9 - t8);
							if (t9 < t8)
							{
								*p_d6 = (*p_d6 & ~0xFFu) | mem_read8(a6_2 + 4u + (int16_t)*p_d6);
								*p_d6 = (uint16_t)(*p_d6 << 2);
								mem_write16(a0 + 0x28u, *p_d6);
								mem_write16(a0 + 4u, 0x300u);
								mem_write8(a0, mem_read8(a0) & ~8u);
								return;
							}
							t10 = *p_d6 - 1u;
							*p_d6 = t10;
						} while (t10 != 0xFFFFu);
					}
				}
			}
		}
	}
	if (mem_read8(a0 + 0x22u) == 0u)
	{
		a6_2 = mem_read32(a0 + 0x24u) + (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 3);
		*p_d7 = 0x64u;
		func_048448(a0, &ignored_3, p_d7);
		*p_d6 = 3u;
		for (;;)
		{
			t11 = mem_read8(a6_2 + 4u + (int16_t)*p_d6);
			t12 = *p_d7;
			*p_d7 = (*p_d7 & ~0xFFu) | (uint8_t)(t12 - t11);
			if (t12 < t11)
				break;
			t13 = *p_d6 - 1u;
			*p_d6 = t13;
			if (t13 == 0xFFFFu)
			{
				*p_d6 = 0u;
				break;
			}
		}
		*p_d6 = (*p_d6 & ~0xFFu) | mem_read8(a6_2 + (int16_t)*p_d6);
		*p_d6 = (uint16_t)(*p_d6 << 2);
		mem_write16(a0 + 0x28u, *p_d6);
		mem_write8(a0 + 5u, 0u);
	}
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_048D8A(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint32_t jump_target = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = mem_read32(*p_a1);
	func_0482FA(a0, a6, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	jump_target = mem_read32(0x53D2Au + (int16_t)*p_d6);
	switch (jump_target)
	{
	case 0x049A06u:
		func_049A06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049A52u:
		func_049A52(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049A8Eu:
		func_049A8E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049ACAu:
		func_049ACA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049B06u:
		func_049B06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049BBCu:
		func_049BBC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049C72u:
		func_049C72();
		return;
	case 0x049C74u:
		func_049C74();
		return;
	case 0x049C76u:
		func_049C76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B2DAu:
		func_04B2DA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B316u:
		func_04B316(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B352u:
		func_04B352(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B42Au:
		func_04B42A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B4E0u:
		func_04B4E0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B5D6u:
		func_04B5D6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E2C4u:
		func_04E2C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E336u:
		func_04E336(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E3C4u:
		func_04E3C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E400u:
		func_04E400(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E43Cu:
		func_04E43C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E4F2u:
		func_04E4F2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EBD6u:
		func_04EBD6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EC5Eu:
		func_04EC5E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EC9Au:
		func_04EC9A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04ECD6u:
		func_04ECD6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04F076u:
		func_04F076(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04F0E4u:
		func_04F0E4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FA96u:
		func_04FA96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FC04u:
		func_04FC04(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FCD4u:
		func_04FCD4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FD4Cu:
		func_04FD4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FD88u:
		func_04FD88(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0508A0u:
		func_0508A0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050ADCu:
		func_050ADC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050B8Cu:
		func_050B8C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050C68u:
		func_050C68(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x052306u:
		func_052306(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x052422u:
		func_052422(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0534C4u:
		func_0534C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x053524u:
		func_053524(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x05356Eu:
		func_05356E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0535B8u:
		func_0535B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x053602u:
		func_053602(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_048DBA(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t d7 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & ~4u);
	d7 = 0xA8u;
	func_0091A4(d7, 0u);
	if (mem_read16(a0 + 0x28u) == 0x20u && mem_read8(a0 + 0x40u) == 3u && mem_read8(a0 + 0x41u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) | 0x80u);
		a6 = 0x60000u | mem_read16(a0 + 0x4Eu);
		if (mem_read8(a6 + 4u) == 4u && (mem_read8(a6 + 0x23u) == 0xEu || mem_read8(a6 + 0x23u) == 0x15u))
			mem_write8(a6 + 0x27u, 0x10u);
	}
	d1 = mem_read8(a0 + 7u);
	if ((int8_t)(((uint32_t)mem_read8(a0) << 1) ^ d1) >= 0)
	{
		if (mem_read8(a0 + 9u) != 0u)
		{
			if (mem_read8(a0 + 0x32u) != mem_read8(a0 + 0x10u))
				mem_write16(a0 + 0x28u, 0x10u);
			else
			{
				d1 &= 0x7Fu;
				mem_write16(a0 + 0x28u, (uint32_t)mem_read8(mem_read32(a0 + 0x24u) + 0x58u + d1) << 2);
			}
		}
		else
		{
			if ((int8_t)unk_061107 >= 0 && (int8_t)mem_read8(mem_read32(a0 + 0x24u) + 0x58u + (d1 & 0x7Fu)) >= 0)
			{
				mem_write16(a0 + 0x28u, 0x10u);
				mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
				func_048EDA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
				return;
			}
			mem_write16(a0 + 0x28u, 0x20u);
		}
	}
	else if (mem_read8(a0 + 9u) == 0u)
	{
		if ((int8_t)unk_061107 < 0 || (int8_t)mem_read8(mem_read32(a0 + 0x24u) + 0x58u + (d1 & 0x7Fu)) < 0)
			mem_write16(a0 + 0x28u, 0x24u);
		else
			mem_write16(a0 + 0x28u, 0x14u);
	}
	else
	{
		if (mem_read8(a0 + 0x32u) != mem_read8(a0 + 0x10u))
		{
			mem_write16(a0 + 0x28u, 0x14u);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			func_048EDA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
			return;
		}
		mem_write16(a0 + 0x28u, 0xCu);
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_048EDA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_048EDA(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &ignored, &ignored_2, &ignored_3, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	switch ((uint32_t)(int16_t)mem_read16(a0 + 0x28u))
	{
	case 228:
		func_0494C6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04955C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_049DDC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_049E10(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_049E34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_049E58(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049E7C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_049FB8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_04A0F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04A1D4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		*p_a5 = unreached_04A338(a0, *p_a1);
		return;
	case 136:
		func_04A368(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		*p_a5 = unreached_04A3F4(a0, *p_a1);
		return;
	case 188:
		func_04A426(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		*p_a5 = unreached_04A4B2(a0, *p_a1);
		return;
	case 196:
		func_04A4E4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		*p_a5 = unreached_04A570(a0, *p_a1);
		return;
	case 20:
		func_04A5A2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04A6B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_04A704(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04B632(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_04B656(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04B67A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04B69E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B6C2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B6E6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B70A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04E566(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04E58A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04E5AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04E5D2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E5F6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E61A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04E63E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04E662(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04ED5E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04ED82(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04EDA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04EDCA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04EDEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_04FE42(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_04FEAA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_04FEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04FF1A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_050076(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_050CE6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_050D2C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_050D78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_050E66(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_051968(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_0519C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_051A08(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_052600(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_0526A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_0531AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_053242(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_0532D4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_05333C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_053440(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_048F02(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a1 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = mem_read32(a1);
	func_0482FA(a0, a6, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	a6 = TABLE32(indexed_table_of_32_bit_values_048F36, (uint32_t)(int16_t)mem_read16(a0 + 0x28u));
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
	*p_a1 = a1;
}

void func_048F62(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
}

void func_048F72(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, DATA16(rom_04881C_ADDRESS + (uint16_t)((unk_060120 & 0xFu) << 1)));
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0x100u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

uint32_t func_048FBA(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04897C(a0);
	func_048262(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_048FFA(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
		mem_write16(a0 + 4u, 0x200u);
}

void func_04901A(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, DATA16(rom_04881C_ADDRESS + (uint16_t)((unk_060120 & 0xFu) << 1)));
	mem_write16(a0 + 0x1Au, 0x100u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

void func_049078(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, DATA16(rom_04881C_ADDRESS + (uint16_t)((unk_060120 & 0xFu) << 1)));
	mem_write16(a0 + 0x1Au, 0xFF00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

void func_0490D6(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_04CF3E_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_0490E6(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0xFF80u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x4CF5Eu;
	set_animation(0u, a0, a6);
}

uint32_t func_04911C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048938(a0);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x4CB1Eu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04916C(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Au, 0x100u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

uint32_t func_0491A8(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048938(a0);
	func_048262(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_0491F8(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Au, 0xFF00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

void func_049234(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049240_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049260(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x46u, 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54A18u;
	set_animation(0u, a0, a6);
}

void func_049276(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Au, 0x100u);
	if ((mem_read8(a0) & 0x40u) == 0u)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54A38u;
	set_animation(0u, a0, a6);
}

void func_0492A8(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
	{
		func_04826A(a0);
		return;
	}
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		a6 = 0x54A38u;
		set_animation(0u, a0, a6);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54A62u;
	set_animation(0u, a0, a6);
}

void func_0492DE(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0 + 0x22u, 0u);
}

void unreached_0492EC(uint32_t d7, uint32_t a0, uint32_t a1, uint32_t a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0;

	a6 = indexed_table_of_32_bit_values_0492F8_ADDRESS;
	func_048236(a0, a1, a6, &ignored, &ignored_2, &d7, &a5);
}

void func_049300(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	mem_write8(a0 + 0x22u, 0x54u);
	d0 = mem_read8(a0 + 0x2Bu);
	mem_write32(a0 + 0x1Au, 0x1800000u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(d0 - 0x40u) < 0)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		mem_write8(a0, mem_read8(a0) | 0x40u);
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54908u;
	set_animation(0u, a0, a6);
}

void func_04933A(uint32_t a0)
{
	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	func_04826A(a0);
}

void func_049344(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049350_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049378(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, ignored = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0xB4u);
	a6 = animations_049358_ADDRESS;
	func_0486F6(a0, a6, &d0, &ignored);
	mem_write8(a0 + 0x4Au, 0u);
	if ((int8_t)(uint8_t)(unk_06120E >> 8u) >= 0)
	{
		func_0493A2((uint8_t)d0, a0, p_d6, p_d7, p_a5);
		return;
	}
	mem_write8(a0 + 0x4Au, 1u);
	func_0493A2((uint8_t)d0, a0, p_d6, p_d7, p_a5);
}

void func_0493A2(uint8_t d0, uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;

	if (mem_read8(a0 + 0x4Au) != 0u)
		d0 += 0x50u;
	else
		d0 -= 0x30u;
	d1 = 0x180u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
}

void func_0493CA(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 1u);
	t1 = d7_2 & 0x1Eu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		mem_write8(a0 + 0x4Au, mem_read8(a0 + 0x4Au) ^ 1u);
		a6 = animations_049358_ADDRESS;
		func_0486F6(a0, a6, &d0, &ignored);
		func_0493A2((uint8_t)d0, a0, p_d6, &d7_2, p_a5);
		func_04826A(a0);
		*p_d7 = d7_2;
		return;
	}
	if (mem_read8(a0 + 0x2Bu) != mem_read8(a0 + 0x30u))
	{
		a6 = animations_049358_ADDRESS;
		func_0486F6(a0, a6, &d0, &ignored);
		func_0493A2((uint8_t)d0, a0, p_d6, &d7_2, p_a5);
	}
	func_04826A(a0);
	*p_d7 = d7_2;
}

void func_049408(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049414_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049420(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	*p_d7 = 0x100u;
	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x46u, *p_d7);
	d0 = mem_read8(a0 + 0x2Bu);
	mem_write32(a0 + 0x1Au, 0x3000000u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	if ((int8_t)(d0 - 0x40u) >= 0)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		mem_write8(a0, mem_read8(a0) & 0xBFu);
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0xB4u);
	a6 = 0x54A78u;
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_049468(uint32_t d7, uint32_t a0)
{
	uint16_t d2 = 0;

	d2 = mem_read16(a0 + 0x2Eu);
	if (mem_read16(a0 + 0x2Cu) > 0x28u)
	{
		func_04826A(a0);
		return d7;
	}
	d7 = (d7 & ~0xFFu) | 7u;
	if (d2 >= 0x10u && (int8_t)mem_read8(a0 + 0x46u) < 0)
		d7 = (d7 & ~0xFFu) | 0x20u;
	mem_write8(a0 + 0x22u, d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_04826A(a0);
	return d7;
}

uint32_t func_04949E(uint32_t d7, uint32_t a0)
{
	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	if (mem_read8(a0 + 0x22u) >= 7u)
	{
		func_04826A(a0);
		return d7;
	}
	d7 = (d7 & ~0xFFFFu) | 0x80u;
	if ((mem_read8(a0) & 0x40u) != 0u)
		d7 = (d7 & ~0xFFFFu) | (uint16_t)(0u - d7);
	mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + d7);
	func_04826A(a0);
	return d7;
}

void func_0494C6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0494D2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0494DA(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x40u;
	func_0091A4((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x14u;
	a6 = 0x189D8u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x15u;
	a6 = 0x18A12u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x16u;
	a6 = 0x18A70u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x17u;
	a6 = 0x18A8Au;
	draw_tile_block((uint16_t)d7_2, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05C9C4_ADDRESS;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_049534(uint32_t d7, uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		d7 = (d7 & ~0xFFu) | 0x10u;
		func_0091A4((uint8_t)d7, 0u);
		mem_write16(a0, 0u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
	return d7;
}

void func_04955C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049568_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049570(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x40u;
	func_0091A4((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x18u;
	a6 = 0x18A24u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x19u;
	a6 = 0x18A5Eu;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x1Au;
	a6 = 0x18A70u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x1Bu;
	a6 = 0x18A8Au;
	draw_tile_block((uint16_t)d7_2, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05C9C4_ADDRESS;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_0495CA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0495D6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0495DE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	mem_write16(a0 + 0x40u, 0x100u);
	*p_a5 = animations_049258_ADDRESS;
	mem_write32(a0 + 0x46u, animations_049258_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_049604(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		a6 = mem_read32(a1);
		d0 = func_047D90(0u, a0, a6);
		a5 = mem_read32(a0 + 0x46u);
		func_0484E2((uint8_t)d0, a0, a6, &ignored, p_d7, &a5);
		d1 = mem_read16(a0 + 0x40u);
		func_047CCC((uint8_t)d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
		mem_write8(a0 + 0x22u, 8u);
	}
	if (mem_read16(a0 + 0x2Cu) >= 0x20u || mem_read16(a0 + 0x2Eu) >= 0x20u)
		func_04826A(a0);
}

void func_04964E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04965A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04966E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x140u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	mem_write32(a0 + 0x46u, animations_049258_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_049694(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = mem_read32(a0 + 0x46u);
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) < 0x20u || (int8_t)(d0 - 0x40u - mem_read8(a0 + 0x45u)) < 0)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x40u));
		if ((int8_t)mem_read8(a0 + 0x45u) < 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, mem_read16(a0 + 0x40u));
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	if (mem_read16(a0 + 0x2Eu) < 3u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0496FA(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((unk_0600A4 & 7u) != 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 2u);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x549E4u;
	set_animation(0u, a0, a6);
}

void func_04971E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6_2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6_2, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6_2 & 0xFFFFu);
}

void func_04973E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = mem_read32(a0 + 0x46u);
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) >= 0x10u)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x40u));
		if ((int8_t)(d0 - 0x40u) >= 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	else
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0u);
	}
	if (mem_read16(a0 + 0x2Eu) < 3u)
	{
		func_04826A(a0);
		*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 3u);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04978A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049796_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0497A6(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_049358_ADDRESS;
	func_0486F6(a0, a6, &ignored, &d7);
	mem_write8(a0 + 0x33u, 0u);
	return d7;
}

void func_0497C2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, ignored = 0, ignored_2 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	if (mem_read8(a0 + 0x2Bu) != mem_read8(a0 + 0x30u))
	{
		a6 = animations_049358_ADDRESS;
		func_0486F6(a0, a6, &ignored, p_d7);
		mem_write8(a0 + 0x33u, 0u);
	}
	if (mem_read16(a0 + 0x2Cu) < 0x50u && mem_read16(a0 + 0x2Eu) < 0x20u)
	{
		mem_write8(a0 + 5u, 2u);
		d0 = (uint8_t)(mem_read8(a0 + 0x2Bu) - 0x80u);
		a5 = animations_049258_ADDRESS;
		a6 = mem_read32(a1);
		func_0484B2(d0, a0, a6, &ignored_2, p_d7, &a5);
		d1 = 0x100u;
		func_047CCC(d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
		return;
	}
	if (mem_read16(a0 + 0x2Cu) >= 0x70u || mem_read16(a0 + 0x2Eu) >= 0x40u)
	{
		mem_write8(a0 + 5u, 3u);
		d0 = mem_read8(a0 + 0x2Bu);
		a5 = animations_049258_ADDRESS;
		a6 = mem_read32(a1);
		func_0484B2(d0, a0, a6, &ignored_2, p_d7, &a5);
		d1 = 0x100u;
		func_047CCC(d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
	}
}

void func_04984C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	if (mem_read16(a0 + 0x2Cu) >= 0x50u || mem_read16(a0 + 0x2Eu) >= 0x20u)
		mem_write8(a0 + 5u, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_049868(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	if (mem_read16(a0 + 0x2Cu) < 0x70u && mem_read16(a0 + 0x2Eu) < 0x40u)
		mem_write8(a0 + 5u, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04989A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0498A6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0498B2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 0x46u, 0x28u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &ignored, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_0498EE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04991E(a0, a1);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x549E4u;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04991E(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_049934(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049940_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049948(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 8u);
	d0 = (uint8_t)(mem_read8(a0 + 0x2Bu) - 0x80u);
	d1 = 0x200u;
	func_047CCC(d0, d1, p_d6, p_d7, &ignored);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, p_d6, p_d7, p_a5);
	func_049980(a0, a1, p_d6, p_d7, p_a5);
}

void func_049980(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 0x2Au, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0499A4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0499B0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0499B8(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0x78u);
	mem_write32(a0 + 0x1Au, 0x1000000u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) >= 0)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0499EA(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_049258_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_049A06(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049A12_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049A1A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x54CC8u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x201u);
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_049A42(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_0485F6(a0);
}

void func_049A52(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049A5E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049A66(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x54D02u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x201u);
	d7_2 = (d7 & ~0xFFu) | 1u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_049A8E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049A9A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049AA2(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x54D3Cu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x201u);
	d7 &= ~0xFFu;
	d7 = func_0485D6(d7, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

void func_049ACA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049AD6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049ADE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x54D76u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x201u);
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_049B06(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049B12_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049B2E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x203u);
	d7_2 = (d7 & ~0xFFu) | 4u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

uint32_t func_049B56(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x49B22u;
	d7 = func_04863E(d7, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54B1Cu;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_049B82(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x49B22u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_049BBC(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049BC8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049BE4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x203u);
	d7_2 = (d7 & ~0xFFu) | 4u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

uint32_t func_049C0C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x49BD8u;
	d7 = func_04863E(d7, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54B1Cu;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_049C38(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x49BD8u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_049C72(void)
{
}

void func_049C74(void)
{
}

void func_049C76(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049C82_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049C92(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0, d0 = 0, d7 = 0;

	if ((int8_t)mem_read8(a0 + 0x44u) < 0 || mem_read8(mem_read32(a1) + 4u) == 4u || mem_read8(a1 + 8u) != 0u)
		func_0485F6(a0);
	else
	{
		a6 = 0x54872u;
		set_animation(0u, a0, a6);
		mem_write16(a0 + 0xAu, 0x101u);
		d7 = 0xEu;
		func_0485D6(d7, a0);
		mem_write8(a1 + 8u, 0x60u);
		mem_write8(a0 + 0x46u, 0x3Cu);
		a6 = mem_read32(a1);
		d0 = func_047D90(0u, a0, a6);
		d1 = 0x200u;
		func_047CCC((uint8_t)d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
		mem_write8(a0, mem_read8(a0) | 4u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		func_04826A(a0);
	}
}

void func_049D06(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0, d0 = 0;
	uint8_t t1 = 0;

	mem_write8(a1 + 8u, 0x60u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	if ((mem_read8(a0) & 8u) != 0u)
	{
		func_0486CC(a0, a1);
		mem_write8(a0, mem_read8(a0) & 0x73u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		return;
	}
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		t1 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t1 - 1u);
		if (t1 != 1u)
		{
			a6 = mem_read32(a1);
			d0 = func_047D90(0u, a0, a6);
			d1 = 0x200u;
			func_047CCC((uint8_t)d0, d1, p_d6, p_d7, p_a5);
			mem_write16(a0 + 0x1Au, *p_d6);
			mem_write16(a0 + 0x1Cu, *p_d7);
			func_04826A(a0);
			return;
		}
	}
	mem_write8(a0, mem_read8(a0) & ~4u);
	func_0485F6(a0);
}

void func_049D7E(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a1 + 8u, 0x60u);
	a6 = 0x60000u | mem_read16(a0 + 0x4Eu);
	if (mem_read8(a6 + 4u) == 4u)
	{
		if (mem_read8(a6 + 0x23u) == 0xEu || mem_read8(a6 + 0x23u) == 0x15u)
		{
			mem_write32(a6 + 0x28u, a0);
			return;
		}
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		return;
	}
	mem_write16(a0, 0u);
	t1 = unk_06120C - 1u;
	unk_06120C = t1;
	if ((int8_t)t1 < 0)
		unk_06120C = 0u;
}

void func_049DD0(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) | 0x82u);
	func_0485F6(a0);
}

void func_049DDC(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049DE8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049DF0(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54B4Eu;
	set_animation(0u, a0, a6);
}

void func_049E00(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_048608(a0);
}

void func_049E10(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E1C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049E24(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54B82u;
	set_animation(0u, a0, a6);
}

void func_049E34(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E40_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049E48(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54BACu;
	set_animation(0u, a0, a6);
}

void func_049E58(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E64_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_049E6C(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54BD6u;
	set_animation(0u, a0, a6);
}

void func_049E7C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049E88_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049EAC(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	a6 = 0x49EA0u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x54C54u;
	set_animation(0u, a0, a6);
	func_0486CC(a0, a1);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_049EC8(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		mem_write8(a0 + 5u, 3u);
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = 0x54EACu;
		set_animation(0u, a0, a6);
		return d7_2;
	}
	func_04890E(a0);
	func_048262(a0);
	a6 = 0x49EA0u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54C6Au;
	set_animation(0u, a0, a6);
	return d7;
}

void func_049F38(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x4A5C2u;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 0x28u, 0x1Cu);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void func_049F6A(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

uint32_t func_049F78(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - 0x100u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x54ECCu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_049FA0(uint32_t a0, uint32_t a1)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 0x28u, 0x1Cu);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void func_049FB8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_049FC4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_049FE8(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	a6 = 0x49FDCu;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x54BECu;
	set_animation(0u, a0, a6);
	func_0486CC(a0, a1);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_04A004(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) != 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		mem_write8(a0 + 5u, 3u);
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = 0x54E62u;
		set_animation(0u, a0, a6);
		return d7_2;
	}
	func_04890E(a0);
	func_048262(a0);
	a6 = 0x49FDCu;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54BF6u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04A074(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x4A114u;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x28u, 0x18u);
	mem_write8(a0 + 5u, 0u);
	mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
}

void func_04A0A6(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

uint32_t func_04A0B4(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) - 0x100u);
	func_04861A(a0, &d7, &zero);
	if (zero)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
		a6 = 0x54E82u;
		set_animation(0u, a0, a6);
	}
	return d7;
}

void func_04A0DC(uint32_t a0, uint32_t a1)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 0x28u, 0x18u);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void func_04A0F4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A100_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04A120(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	a6 = 0x4A114u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x54BECu;
	set_animation(0u, a0, a6);
	func_0486CC(a0, a1);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_04A13C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4A114u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54BF6u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04A176(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x4A114u;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x46u, 0x1Eu);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		if (mem_read8(a0 + 8u) == 0u)
		{
			mem_write16(a0 + 0x28u, 0x18u);
			mem_write8(a0 + 5u, 0u);
			mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
		}
	}
}

void func_04A1BA(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x54C16u;
		set_animation(0u, a0, a6);
	}
}

void func_04A1D4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A1E0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void unreached_04A202(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	mem_write8(a0 + 0x22u, 0xCu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04A214(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)mem_read8(a0 + 0x30u) >= 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	*p_a5 = 0x4A1FCu;
	func_04A2E4(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	func_04A2CA((uint16_t)d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	d7_2 = func_04A5CE(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t func_04A25A(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d7_2 = 0;

	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		mem_write8(a0 + 5u, 4u);
		d7_2 = (d7 & ~0xFFu) | 0x89u;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = 0x54EACu;
		set_animation(0u, a0, a6);
		return d7_2;
	}
	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4A5C2u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54C6Au;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04A2CA(uint16_t d7, uint32_t a0)
{
	uint16_t d2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	d2 = mem_read16(a0 + 8u);
	t1 = (uint8_t)d2;
	d2 = (uint16_t)((d2 & ~0xFFu) | (uint8_t)(t1 - d7));
	if (t1 <= (uint8_t)d7)
	{
		t2 = (d2 & ~0xFFu) | (uint8_t)d7;
		d2 = (uint16_t)(t2 - d7);
		if (t2 < (uint16_t)d7)
			d2 = 0u;
	}
	mem_write16(a0 + 8u, d2);
}

void func_04A2E4(uint32_t a0, uint32_t a5, uint32_t a6)
{
	uint16_t d1 = 0;
	uint32_t t1 = 0, t2 = 0;

	d1 = (uint16_t)(mem_read16(a6 + 0xCu) - mem_read16(a0 + 0xCu) + mem_read16(a5));
	if ((mem_read8(a0) & 0x40u) != 0u)
		d1 = (uint16_t)(d1 - mem_read16(a5) - mem_read16(a5));
	t1 = mem_read32(a0 + 0x12u) + ((uint32_t)(int16_t)d1 << 8);
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	t2 = mem_read32(a0 + 0x16u) + ((uint32_t)(int16_t)(mem_read16(a6 + 0xEu) - mem_read16(a0 + 0xEu) + mem_read16(a5 + 2u)) << 8);
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	mem_write8(a0 + 0x10u, mem_read8(a6 + 0x10u) + mem_read8(a5 + 4u));
	mem_write8(a0 + 0x32u, mem_read8(a6 + 0x32u));
}

uint32_t unreached_04A338(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	func_0486CC(a0, a1);
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	a5 = record_04A332_ADDRESS;
	func_04A2E4(a0, a5, a6);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	return a5;
}

void func_04A368(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A374_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void unreached_04A396(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	mem_write8(a0 + 0x22u, 0x12u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04A3A8(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)mem_read8(a0 + 0x30u) >= 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	*p_a5 = 0x4A390u;
	func_04A2E4(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	func_04A2CA((uint16_t)d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	d7_2 = func_04A5CE(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t unreached_04A3F4(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	func_0486CC(a0, a1);
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	a5 = record_04A3EE_ADDRESS;
	func_04A2E4(a0, a5, a6);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	return a5;
}

void func_04A426(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A432_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void unreached_04A454(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04A466(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)mem_read8(a0 + 0x30u) >= 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	*p_a5 = 0x4A44Eu;
	func_04A2E4(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	func_04A2CA((uint16_t)d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	d7_2 = func_04A5CE(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t unreached_04A4B2(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	func_0486CC(a0, a1);
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	a5 = record_04A4AC_ADDRESS;
	func_04A2E4(a0, a5, a6);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	return a5;
}

void func_04A4E4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A4F0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void unreached_04A512(uint32_t a0)
{
	mem_write8(a0, mem_read8(a0) & 0x7Fu);
	mem_write8(a0 + 0x22u, 0x14u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04A524(uint32_t a0, uint32_t a1, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)mem_read8(a0 + 0x30u) >= 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	*p_a5 = 0x4A50Cu;
	func_04A2E4(a0, *p_a5, a6);
	d7_2 = (d7 & ~0xFFFFu) | 0x306u;
	func_04A2CA((uint16_t)d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	d7_2 = func_04A5CE(d7_2, a0, a1);
	*p_d7 = d7_2;
}

uint32_t unreached_04A570(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	func_0486CC(a0, a1);
	a6 = 0x60000u | mem_read16(a0 + 0x4Cu);
	a5 = record_04A56A_ADDRESS;
	func_04A2E4(a0, a5, a6);
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	return a5;
}

void func_04A5A2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A5AE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04A5CE(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	a6 = 0x4A5C2u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x54C54u;
	set_animation(0u, a0, a6);
	func_0486CC(a0, a1);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_04A5F8(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4A5C2u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54C6Au;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04A632(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x4A5C2u;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 0x46u, 0x1Eu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	if (mem_read8(a0 + 8u) == 0u)
	{
		mem_write16(a0 + 0x28u, 0x1Cu);
		mem_write8(a0 + 5u, 0u);
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	}
}

void func_04A676(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54C94u;
	set_animation(0u, a0, a6);
}

void func_04A690(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		func_048608(a0);
		mem_write8(a0 + 0x2Au, 0u);
		if (mem_read8(a0 + 9u) == 0u)
			mem_write8(a0 + 9u, 6u);
	}
}

void func_04A6B2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A6BE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04A6C6(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x10u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) & ~6u);
	a6 = 0x54DBAu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04A6E6(uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0, 0u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
}

void func_04A704(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04A710_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04A718(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x10u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) & ~6u);
	a6 = 0x54E16u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04A744(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = 0;
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7 = 0x43Au;
	a6 = 0xC704u;
	*p_a5 = post_palette_request(d7, a6);
	a6 = animations_05CE06_ADDRESS;
	set_animation(0u, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
}

uint32_t func_04A76A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (unk_063380 < 0x3F000u)
		return d7;
	mem_write8(a0 + 0x46u, 0x5Au);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7 & ~0xFFFFu) | 0xFEu;
	unk_060080 = d7_2;
	func_0091A4((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0x36u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x5CE10u;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_04A7AA(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & 0x7Fu);
		t1 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t1 - 1u);
		if (t1 == 1u)
		{
			mem_write16(a0, 0u);
			unk_06123D = 0xFFu;
			d7_2 = (d7 & ~0xFFFFu) | 0x64u;
			unk_060080 = d7_2;
			func_0091A4((uint8_t)d7_2, 0u);
			return d7_2;
		}
	}
	return d7;
}

void func_04A7F8(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04A7E6_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04A814(void)
{
}

void func_04A830(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x28u, 0xDCu);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 6u, 0xCu);
	mem_write16(a0 + 0xAu, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04A81E_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04A856(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
}

void func_04A880(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04A86E_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04A8E6(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = TABLE32(animations_04A8A4, mem_read8(a0 + 3u));
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write16(a0 + 0x34u, 4u);
}

uint32_t func_04A90E(uint32_t d7)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	d0 = 2u;
	func_047C02(d0, &d7, &a6, &zero);
	if (zero)
	{
		mem_write16(a6, 0x100u);
		mem_write16(a6 + 2u, 0x3B00u);
		mem_write16(a6 + 4u, 0u);
		mem_write16(a6 + 0x42u, 0xFF00u);
		mem_write8(a6 + 0x4Bu, 0u);
		mem_write16(a6 + 0x10u, 0u);
		mem_write32(a6 + 0x12u, unk_061218 - 0x18000u);
		mem_write32(a6 + 0x16u, 0x6000u);
	}
	return d7;
}

void func_04A97E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 6u, 0x87u);
	mem_write16(a0 + 0xAu, 0x403u);
	mem_write16(a0 + 0x28u, 0xD4u);
	a6 = animations_04A95C_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write16(a0 + 0x1Au, 0x400u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x34u, 0x10u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_04A9B6(a0);
}

void func_04A9B6(uint32_t a0)
{
	if ((int16_t)mem_read16(a0 + 0xCu) >= 0x1E0)
		mem_write16(a0, 0u);
	func_04824C(a0);
}

void func_04AA82(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 6u, 0u);
	mem_write16(a0 + 0xAu, 0x103u);
	mem_write16(a0 + 0x34u, 3u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write16(a0 + 0x28u, 0x70u);
	a6 = animations_04A9DA_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04AAAA(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d1 = 0, d2 = 0;

	if (mem_read16(a0 + 0xCu) >= 0x100u)
	{
		func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
		func_0482FA(a0, a6, &d1, &d2);
		if ((uint16_t)d1 > 0x10u || (uint16_t)d2 > 0x10u)
		{
			func_04AB2A(a0);
			return;
		}
	}
	mem_write8(a0, 0x85u);
	mem_write16(a0 + 0x1Eu, 0xFF00u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_04AB2A(a0);
}

uint32_t func_04AAE4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Eu));
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	if ((int8_t)mem_read8(a0 + 0x10u) >= 0 || mem_read8(a0 + 0x10u) < 0xF0u)
		return d7;
	mem_write16(a0 + 0x10u, 0u);
	mem_write8(a0, 0x81u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0x31u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x4AA16u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04AB2A(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
}

uint32_t func_04AB5E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write16(a0 + 0xAu, 0x206u);
	mem_write8(a0 + 6u, 7u);
	mem_write16(a0 + 0x34u, 6u);
	mem_write16(a0 + 0x28u, 0x44u);
	mem_write16(a0 + 8u, 0x101u);
	d7_2 = (d7 & ~0xFFu) | 0x3Au;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) | 0x86u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0xFD00u);
	if (mem_read8(a0 + 3u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	a6 = animations_05C632_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x46u, 1u);
	mem_write8(a0 + 0x4Au, 0u);
	return d7_2;
}

void func_04ABCA(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x46u, 8u);
		func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
		mem_write32(a0 + 0x20u, a6);
	}
	a6_2 = mem_read32(a0 + 0x20u);
	func_0482FA(a0, a6_2, &d1, &d2);
	if ((uint16_t)d2 >= 8u || (uint16_t)d1 >= 0x40u)
	{
		func_04AC0E(a0);
		return;
	}
	mem_write8(a0 + 0x4Au, 1u);
	a6_2 = 0x5C686u;
	set_animation(d1, a0, a6_2);
	func_04AC0E(a0);
}

void func_04AC0E(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
	func_04824C(a0);
}

void func_04AC22(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint8_t d7 = 0;
	uint32_t a5 = 0, a6 = 0, d7_2 = 0;

	d7 = 0xA8u;
	func_0091A4(d7, 0u);
	a6 = 0x5C65Cu;
	a5 = 0x4AB4Eu;
	if (mem_read8(a0 + 0x4Au) != 0u)
	{
		a6 = 0x5C6B0u;
		a5 = 0x4AB56u;
	}
	set_animation(0u, a0, a6);
	func_047C30(a0, a5, &d7_2, &a6, &zero);
	if (zero)
	{
		mem_write8(a6, mem_read8(a0));
		mem_write8(a6, mem_read8(a6) & 0xC1u);
		mem_write16(a6 + 4u, 0x500u);
		mem_write16(a6 + 8u, 0u);
		mem_write16(a6 + 0x28u, 0x10u);
		mem_write32(a6 + 0x3Au, 0x2E928u);
		unk_06120C++;
	}
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write16(a0 + 4u, 0x200u);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
	*p_a5 = a5;
}

void func_04ACB0(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x87u);
	mem_write8(a0 + 0x42u, 7u);
	mem_write8(a0 + 0x32u, 0u);
	func_048746(a0);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x53F86u);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = animations_055722_ADDRESS;
	set_animation(0u, a0, a6_2);
}

void func_04AD3C(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 0u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x85u);
	mem_write8(a0 + 0x42u, 5u);
	mem_write8(a0 + 0x32u, 0u);
	func_048746(a0);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x5400Eu);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = animations_057B46_ADDRESS;
	set_animation(0u, a0, a6_2);
}

void func_04ADAC(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ADB8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04ADC8(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04ADC0_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04ADC0_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04ADEE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ADFA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04AE0E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x140u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04ADC0_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04AE34(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((unk_0600A4 & 0x700u) != 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 2u);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55852u;
	set_animation(0u, a0, a6);
}

void func_04AE58(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6_2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6_2, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6_2 & 0xFFFFu);
}

void func_04AE78(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04AE84_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04AE8C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xB4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) >= 0)
		mem_write16(a0 + 0x40u, 0u - mem_read16(a0 + 0x40u));
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04ADC0_ADDRESS;
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04AEBC(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Eu) >= 0x20u)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x40u));
		if (mem_read16(a0 + 0x2Cu) >= 0x40u)
		{
			mem_write16(a0 + 0x40u, 0x100u);
			if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) >= 0)
				mem_write16(a0 + 0x40u, 0u - mem_read16(a0 + 0x40u));
		}
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, 0x100u);
		if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04AF24(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04AF30_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04AF3C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 0x46u, 0x28u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &ignored, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04AF78(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04AFA8(a0, a1);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x55852u;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04AFA8(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04AFBE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04AFCA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04AFD2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0x10u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	mem_write32(a0 + 0x1Au, 0x100u);
	if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
		mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B00A(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04ADC0_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 0x2Au, 0u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B032(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B03E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B04E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04B046_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04B046_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B074(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B080_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B08C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04B046_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04B046_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B0B2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = mem_read32(a0 + 0x46u);
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) < 0x40u || (int8_t)(d0 - 0x40u - mem_read8(a0 + 0x45u)) < 0)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x40u));
		if ((int8_t)mem_read8(a0 + 0x45u) < 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, mem_read16(a0 + 0x40u));
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	if (mem_read16(a0 + 0x2Eu) < 3u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B118(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = 0;

	func_04973E(a0, a1, &d6, p_d7, p_a5);
	if ((int8_t)mem_read8(a0 + 5u) < 0)
		mem_write8(a0 + 5u, 1u);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B12E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B13A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B146(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x46u, 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B168(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) < 0x40u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x47u, 1u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0x100u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) >= 0)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B1AC(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint32_t a5 = *p_a5;
	uint8_t d0 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	if (mem_read16(a0 + 0x2Cu) < 0x50u)
	{
		t1 = mem_read8(a0 + 0x47u);
		mem_write8(a0 + 0x47u, t1 - 1u);
		if (t1 != 1u)
		{
			if ((mem_read8(a0 + 0x46u) & 1u) != 0u)
			{
				d0 = mem_read8(a0 + 0x2Bu);
				a5 = animations_04B046_ADDRESS;
				a6 = mem_read32(a1);
				func_0484E2(d0, a0, a6, &d6, p_d7, &a5);
			}
			func_04826A(a0);
		}
		else
		{
			mem_write8(a0 + 0x47u, 0x30u);
			mem_write8(a0 + 0x46u, mem_read8(a0 + 0x46u) + 1u);
			mem_write16(a0 + 0x1Cu, 0u);
			mem_write16(a0 + 0x1Au, 0u);
			if ((mem_read8(a0 + 0x46u) & 1u) == 0u)
			{
				a6 = 0x57BF2u;
				set_animation(0u, a0, a6);
			}
			else
			{
				mem_write16(a0 + 0x1Cu, 0x100u);
				if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
					mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
				d0 = mem_read8(a0 + 0x2Bu);
				a5 = animations_04B046_ADDRESS;
				a6 = mem_read32(a1);
				func_0484B2(d0, a0, a6, &d6, p_d7, &a5);
			}
		}
	}
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 1u);
		if ((mem_read8(a0 + 0x46u) & 1u) == 0u)
		{
			d0 = mem_read8(a0 + 0x2Bu);
			a5 = animations_04B046_ADDRESS;
			a6 = mem_read32(a1);
			func_0484B2(d0, a0, a6, &d6, p_d7, &a5);
		}
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_a5 = a5;
}

void func_04B238(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B244_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B250(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0x100u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B284(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04B046_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x22u, 0xFFu);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x57BF2u;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04B2BC(uint32_t a0, uint32_t a1)
{
	if (mem_read8(a0 + 0x33u) == 0u && mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x22u, 0u);
		mem_write8(a0 + 0x2Au, 0u);
	}
}

void func_04B2DA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B2E6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04B2EE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x55948u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x302u);
	d7 &= ~0xFFu;
	d7 = func_0485D6(d7, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

void func_04B316(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B322_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04B32A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x5598Cu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x302u);
	d7_2 = (d7 & ~0xFFu) | 1u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04B352(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B35E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04B37A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x559C8u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x403u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

uint32_t func_04B3A2(uint32_t d7, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, d1 = 0;
	uint16_t t1 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x4B36Eu;
	d7 = func_04863E(d7, a0, a6);
	t1 = mem_read16(a0 + 0x2Cu);
	d0 = (uint16_t)(t1 - 0x10u);
	if (t1 < 0x10u)
		d0 = 0u;
	d1 = 6u * d0;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d1 = (uint16_t)(0u - d1);
	mem_write16(a0 + 0x1Au, d1);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x559DEu;
	set_animation(d1, a0, a6);
	return d7;
}

uint32_t func_04B3F0(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4B36Eu;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55A18u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04B42A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B436_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04B452(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x55824u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x303u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

uint32_t func_04B47A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x4B446u;
	d7 = func_04863E(d7, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55878u;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_04B4A6(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4B446u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55824u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04B4E0(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B4EC_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04B508(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x55824u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x503u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

uint32_t func_04B530(uint32_t d7, uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0, d1 = 0;
	uint16_t t1 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x4B4FCu;
	d7 = func_04863E(d7, a0, a6);
	t1 = mem_read16(a0 + 0x2Cu);
	d0 = (uint16_t)(t1 - 0x10u);
	if (t1 < 0x10u)
		d0 = 0u;
	d1 = (0x2AAu * d0) >> 8;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d1 = (uint16_t)(0u - d1);
	mem_write16(a0 + 0x1Au, d1);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 0x46u, 0x48u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55830u;
	set_animation(d1, a0, a6);
	return d7;
}

uint32_t func_04B588(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		a6 = 0x55840u;
		set_animation(0u, a0, a6);
	}
	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4B4FCu;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55852u;
	set_animation(ignored, a0, a6);
	return d7;
}

void func_04B5D6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B5E2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04B5EA(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x57BFEu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x303u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	d7_2 = (d7_2 & ~0xFFu) | 8u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 0x46u, 0x3Au);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04B622(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	func_0485F6(a0);
}

void func_04B632(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B63E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B646(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x558AAu;
	set_animation(0u, a0, a6);
}

void func_04B656(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B662_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B66A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x558DEu;
	set_animation(0u, a0, a6);
}

void func_04B67A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B686_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B68E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55908u;
	set_animation(0u, a0, a6);
}

void func_04B69E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6AA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B6B2(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55932u;
	set_animation(0u, a0, a6);
}

void func_04B6C2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6CE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B6D6(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x57C62u;
	set_animation(0u, a0, a6);
}

void func_04B6E6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6F2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04B6FA(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x57C96u;
	set_animation(0u, a0, a6);
}

void func_04B70A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04B6CE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void unreached_04B716(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x57C96u;
	set_animation(0u, a0, a6);
}

void func_04B7F8(uint16_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	mem_write16(a0 + 0xAu, 0u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0, mem_read8(a0) | 0x86u);
	mem_write8(a0 + 6u, 0x8Fu);
	if ((mem_read8(a0) & 0x40u) == 0u)
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write16(a0 + 0x46u, 0u);
	func_04B828(d0, a0, p_d7, p_a1);
}

void func_04B828(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = 0, a6 = 0;

	a1 = mem_read32(a0 + 0x24u);
	if ((mem_read8(a1 + 0x4Au) & 0x80u) == 0u)
	{
		if ((mem_read8(a1 + 0x4Au) & 0x40u) == 0u)
		{
			if ((mem_read8(a1 + 0x4Au) & 0x20u) == 0u)
			{
				a6 = indexed_table_of_16_bit_values_04B776_ADDRESS;
				func_04B950(a0, a1, a6, &d0, p_d7);
				a6 = animations_04B742_ADDRESS;
			}
			else
			{
				mem_write8(a0 + 4u, 3u);
				mem_write8(a0, mem_read8(a0) & ~0xEu);
				a6 = indexed_table_of_16_bit_values_04B7C4_ADDRESS;
				func_04B950(a0, a1, a6, &d0, p_d7);
				a6 = animations_04B790_ADDRESS;
			}
		}
		else
		{
			mem_write8(a0, mem_read8(a0) & ~0xEu);
			a6 = indexed_table_of_16_bit_values_04B776_ADDRESS;
			func_04B950(a0, a1, a6, &d0, p_d7);
			a6 = animations_04B742_ADDRESS;
		}
		a6 = DATA32(a6 + (uint16_t)(IN_PAGE(d0, mem_read8(a1 + 0x46u)) << 2));
		set_animation(0u, a0, a6);
	}
	else
		mem_write16(a0, 0u);
	*p_a1 = a1;
}

void func_04B88E(uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = 0;

	a1 = mem_read32(a0 + 0x24u);
	mem_write8(a1 + 0x4Au, mem_read8(a1 + 0x4Au) | 4u);
	mem_write8(a0 + 4u, 1u);
	*p_a1 = a1;
	func_04B89E(a0, p_d7, p_a1);
}

void func_04B89E(uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = 0, a2 = 0, d1 = 0, d2 = 0;

	a1 = mem_read32(a0 + 0x24u);
	*p_d7 = 0x60000u | mem_read16(a0 + 0x4Eu);
	a2 = *p_d7;
	if (mem_read8(a1 + 4u) != 5u)
	{
		d2 = mem_read16(a0 + 0xEu);
		mem_write32(a2 + 0x16u, (uint32_t)(uint16_t)(d2 - 2u) << 8);
		d1 = DATA16(rom_04B7DE_ADDRESS + (uint16_t)((uint32_t)mem_read8(a1 + 0x46u) << 1));
		if ((mem_read8(a0) & 0x40u) != 0u)
			d1 = (uint16_t)(0u - d1);
		mem_write32(a2 + 0x12u, (uint32_t)(uint16_t)(d1 + mem_read16(a0 + 0xCu)) << 8);
	}
	else
	{
		mem_write8(a2 + 0x27u, 0x10u);
		mem_write16(a0, 0u);
	}
	*p_a1 = a1;
}

void func_04B900(uint32_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a1)
{
	uint32_t a1 = 0, a6 = 0;

	if ((mem_read8(a0) & 8u) != 0u)
	{
		*p_d7 = 0x60000u | mem_read16(a0 + 0x4Eu);
		mem_write8(*p_d7 + 0x27u, 0x10u);
		a1 = mem_read32(a0 + 0x24u);
		mem_write8(a1 + 0x4Au, mem_read8(a1 + 0x4Au) | 4u);
	}
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	a1 = mem_read32(a0 + 0x24u);
	mem_write8(a1 + 0x4Au, mem_read8(a1 + 0x4Au) | 2u);
	mem_write8(a0 + 4u, 1u);
	a6 = indexed_table_of_16_bit_values_04B776_ADDRESS;
	func_04B950(a0, a1, a6, &d0, p_d7);
	a6 = animations_04B742_ADDRESS;
	a6 = DATA32(a6 + (uint16_t)(IN_PAGE(d0, mem_read8(a1 + 0x46u)) << 2));
	set_animation(0u, a0, a6);
	*p_a1 = a1;
}

void func_04B950(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d0, uint32_t *p_d7)
{
	uint16_t d0 = (uint16_t)*p_d0;
	uint16_t d1 = 0;

	if (mem_read8(a1 + 4u) != 5u)
	{
		d0 = (uint16_t)((uint32_t)mem_read8(a1 + 0x46u) << 1);
		d1 = mem_read16(a6 + d0);
		if ((mem_read8(a0) & 0x40u) != 0u)
			d1 = (uint16_t)(0u - d1);
		mem_write32(a0 + 0x12u, (int16_t)d1 + mem_read32(a1 + 0x12u));
		mem_write32(a0 + 0x16u, mem_read32(a1 + 0x16u));
	}
	else
	{
		if ((mem_read8(a0) & 8u) != 0u)
		{
			*p_d7 = 0x60000u | mem_read16(a0 + 0x4Eu);
			mem_write8(*p_d7 + 0x27u, 0x10u);
		}
		mem_write16(a0, 0u);
	}
	*p_d0 = (*p_d0 & 0xFFFF0000u) | d0;
}

void func_04B9C2(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x34u, 3u);
	mem_write8(a0, mem_read8(a0) | 0x85u);
	mem_write16(a0 + 0xAu, 0x201u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x8000000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x58880u;
	set_animation(0u, a0, a6);
}

void func_04BA04(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = 0x58892u;
		set_animation(0u, a0, a6);
		return;
	}
	func_04824C(a0);
}

void func_04BA34(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

void func_04BA56(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write16(a0 + 0xAu, 0x306u);
	mem_write16(a0 + 0x34u, 6u);
	mem_write16(a0 + 0x28u, 0x44u);
	mem_write8(a0 + 6u, 0x87u);
	mem_write32(a0 + 0x1Au, 0x4000000u);
	if ((int8_t)mem_read8(a0 + 3u) >= 0)
	{
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 0x22u, 0xAu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	a6 = 0x54F60u;
	set_animation(0u, a0, a6);
}

void func_04BAB2(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04BAC4(a0);
		return;
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0, mem_read8(a0) | 2u);
	func_04BAC4(a0);
}

void func_04BAC4(uint32_t a0)
{
	uint8_t t1 = 0;

	if ((mem_read8(a0) & 0x20u) == 0u)
	{
		func_04824C(a0);
		return;
	}
	t1 = unk_06120C - 1u;
	unk_06120C = t1;
	if ((int8_t)t1 < 0)
		unk_06120C = 0u;
	mem_write16(a0, 0u);
	func_04824C(a0);
}

uint32_t func_04BAE8(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	if (mem_read8(a0 + 2u) != 0x19u)
		d7_2 = (d7_2 & ~0xFFu) | 0x41u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 0x22u, 0xAu);
	mem_write8(a0 + 6u, mem_read8(a0 + 6u) ^ 0x80u);
	mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 4u, 1u);
	return d7_2;
}

void func_04BB32(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	mem_write16(a0 + 0xAu, 0x202u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0, mem_read8(a0) | 0x86u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x4000000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x5711Au;
	set_animation(0u, a0, a6);
}

void func_04BB88(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~0xEu);
		mem_write8(a0 + 4u, 2u);
		a6 = 0x5712Cu;
		set_animation(0u, a0, a6);
		return;
	}
	func_04824C(a0);
}

void func_04BBB6(uint32_t a0)
{
	uint32_t t1 = 0;

	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

uint32_t func_04BBD8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, 2u);
	a6 = 0x5712Cu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04BC0E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0xAu, 0x303u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0, mem_read8(a0) | 0x86u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x6000000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x55DF4u;
	set_animation(0u, a0, a6);
}

void func_04BC50(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	func_04824C(a0);
}

void func_04BC60(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

uint32_t func_04BC6E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, 2u);
	a6 = 0x55E06u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04BC98(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	mem_write16(a0 + 0xAu, 0x301u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x4000000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x576F0u;
	set_animation(0u, a0, a6);
}

void func_04BCEE(uint32_t a0)
{
	uint32_t t1 = 0;

	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	func_04824C(a0);
}

void func_04BD2C(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	mem_write16(a0 + 0xAu, 0x301u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0, mem_read8(a0) | 0x85u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x6000000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write16(a0 + 0x1Eu, 0xFE00u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x56B2Au;
	set_animation(0u, a0, a6);
	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
}

void func_04BD78(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		if (unk_060120 == 6u)
		{
			t1 = mem_read32(a0 + 0x12u) + 0x600u;
			mem_write16(a0 + 0x14u, t1);
			mem_write16(a0 + 0x12u, t1 >> 16);
		}
		return;
	}
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~0xEu);
		mem_write8(a0 + 4u, 2u);
		a6 = 0x56B5Cu;
		set_animation(0u, a0, a6);
		return;
	}
	if (mem_read8(a0 + 0x10u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~0xEu);
		mem_write8(a0 + 4u, 2u);
		a6 = 0x56B3Cu;
		set_animation(0u, a0, a6);
		return;
	}
	func_048244(a0);
	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
}

void func_04BD9E(uint32_t a0)
{
	uint32_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
	if (unk_060120 == 6u)
	{
		t1 = mem_read32(a0 + 0x12u) + 0x600u;
		mem_write16(a0 + 0x14u, t1);
		mem_write16(a0 + 0x12u, t1 >> 16);
	}
}

uint32_t func_04BDC0(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x25u;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, 2u);
	a6 = 0x56B5Cu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04BE12(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x86u);
	mem_write16(a0 + 0xAu, 0x201u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x5800000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 0x46u, 0x20u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x55B96u;
	set_animation(0u, a0, a6);
}

void func_04BE5A(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) ^ 0x80u);
		mem_write8(a0 + 0x46u, 0x20u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	func_04824C(a0);
	if (mem_read8(mem_read32(a0 + 0x20u) + 4u) == 5u)
		mem_write8(a0 + 4u, 3u);
}

void func_04BE92(uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(mem_read32(a0 + 0x20u) + 4u) != 5u)
	{
		t1 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t1 - 1u);
		if (t1 == 1u)
			mem_write16(a0, 0u);
	}
	else
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_04824C(a0);
}

void func_04BEBA(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
	func_04824C(a0);
}

uint32_t func_04BECE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0x25u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x55C2Cu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04BEE8(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

void func_04BF0A(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a0, mem_read8(a0) | 0x86u);
	mem_write16(a0 + 0xAu, 0x301u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x5000000u);
	t1 = mem_read8(a0);
	mem_write8(a0, t1 & 0xBFu);
	if ((t1 & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x55A62u;
	set_animation(0u, a0, a6);
}

void func_04BF4C(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	if ((mem_read8(a0) & 8u) == 0u)
	{
		func_04824C(a0);
		return;
	}
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x55AA8u;
	set_animation(0u, a0, a6);
}

void unreached_04BF5A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x55A9Eu;
	set_animation(0u, a0, a6);
}

void func_04BF96(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

uint32_t func_04BFA4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	mem_write8(a0 + 4u, mem_read8(a0 + 4u) - 1u);
	d7_2 = (d7 & ~0xFFu) | 0x25u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x55A9Eu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04BFE6(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d5 = 0;
	uint32_t a6 = 0, d1 = 0, ignored = 0;

	mem_write16(a0 + 0xAu, 0x101u);
	mem_write16(a0 + 0x34u, 2u);
	mem_write8(a0, mem_read8(a0) | 0x85u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d5 = mem_read8(a0 + 3u);
	a6 = 0x4BFD4u;
	mem_write8(a0 + 6u, 0x80u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		a6 = 0x4BFD2u;
		mem_write8(a0 + 6u, 0u);
	}
	d0 = DATA8(a6 + d5);
	d1 = 0x600u;
	func_047CCC(d0, (uint16_t)d1, p_d6, p_d7, &ignored);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Eu, *p_d7);
	mem_write16(a0 + 0x1Cu, 0u);
	d5 = (uint16_t)((uint32_t)d5 << 3);
	*p_a5 = animations_04BFD6_ADDRESS;
	a6 = animations_04BFD6[d5 / 4u];
	mem_write32(a0 + 0x24u, rom_04BFDA[d5 / 4u]);
	set_animation(d1, a0, a6);
	*p_d5 = (*p_d5 & 0xFFFF0000u) | d5;
}

void func_04C054(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x10u) >= 0xF8u || (mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~0xEu);
		mem_write8(a0 + 4u, 2u);
		a6 = mem_read32(a0 + 0x24u);
		set_animation(0u, a0, a6);
		return;
	}
	func_048244(a0);
}

void func_04C078(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

void unreached_04C086(uint32_t a0)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;

	d7 = 0x25u;
	func_0091A4(d7, 0u);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 4u, 2u);
	a6 = mem_read32(a0 + 0x24u);
	set_animation(0u, a0, a6);
}

void func_04C0AE(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0xAu, 0x401u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x4000000u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x5A7CAu;
	set_animation(0u, a0, a6);
}

void func_04C0F0(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		mem_write16(a0, 0u);
		return;
	}
	func_04824C(a0);
}

void func_04C11A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write16(a0 + 0xAu, 0x606u);
	mem_write16(a0 + 0x34u, 0x12u);
	mem_write16(a0 + 0x28u, 0x44u);
	mem_write8(a0 + 6u, 0x80u);
	mem_write32(a0 + 0x1Au, 0x4000000u);
	if ((int8_t)mem_read8(a0 + 3u) >= 0)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 0x22u, 0xAu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	a6 = 0x5C890u;
	set_animation(0u, a0, a6);
}

void func_04C17C(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 0x4Au, 0xFFu);
	mem_write16(a0 + 0x1Au, 0x300u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0x100u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x5B5BEu;
	set_animation(0u, a0, a6);
}

uint32_t func_04C1B6(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero)
	{
		mem_write16(a0 + 0x1Eu, (int16_t)(0u - mem_read16(a0 + 0x1Eu)) >> 1);
		t1 = mem_read8(a0 + 0x4Au) + 1u;
		mem_write8(a0 + 0x4Au, t1);
		if (t1 == 0u)
		{
			a6 = 0x5B5C8u;
			set_animation(0u, a0, a6);
		}
	}
	if ((mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
	return d7;
}

void func_04C204(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0xAu, 0xA03u);
	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 6u, 0x98u);
	if ((mem_read8(a0) & 0x40u) == 0u)
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) & 0x7Fu);
	mem_write8(a0 + 0x22u, 0x3Cu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_05C220_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04C23C(uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(mem_read32(a0 + 0x24u) + 4u) != 5u)
	{
		t1 = mem_read8(a0 + 0x22u);
		mem_write8(a0 + 0x22u, t1 - 1u);
		if (t1 == 1u)
			mem_write16(a0, 0u);
		return;
	}
	mem_write16(a0, 0u);
}

void func_04C264(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x84u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write16(a0 + 0xAu, 0x102u);
	mem_write16(a0 + 0x34u, 3u);
	mem_write16(a0 + 0x28u, 0x70u);
	mem_write16(a0 + 0x1Au, 0x400u);
	if (mem_read8(a0 + 3u) != 0u)
		mem_write16(a0 + 0x1Au, 0u);
	mem_write8(a0 + 6u, 0x80u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write8(a0 + 6u, 0u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Eu, 0x200u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	a6 = 0x5C95Au;
	set_animation(0u, a0, a6);
}

uint32_t func_04C2CE(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x80u);
	func_04861A(a0, &d7, &zero);
	if (zero)
	{
		d7 = (d7 & ~0xFFu) | 0x13u;
		func_0091A4((uint8_t)d7, 0u);
		a6 = rom_015258;
		set_animation(0u, a0, a6);
		mem_write16(a0 + 0xAu, 0x303u);
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 7u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return d7;
}

void func_04C30C(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

void func_04C32A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0xAu, 0x206u);
	mem_write8(a0 + 6u, 7u);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = 0x5CB10u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x28u, 0x70u);
	mem_write8(a0 + 0x4Au, 3u);
	mem_write16(a0 + 0x34u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_04C35E(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t d0 = 0, d7 = 0, ignored = 0, ignored_2 = 0;

	func_04835E(a0, p_d5, &ignored, &ignored_2, p_a5, &a6);
	d0 = func_047D90(0u, a0, a6);
	d1 = 0x100u;
	func_047CCC((uint8_t)d0, d1, p_d6, &d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, d7);
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7 = func_04C386(d7, a0);
	*p_d7 = d7;
}

uint32_t func_04C386(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x42u, indexed_table_of_8_bit_values_04C3EE[(uint8_t)unk_0600A4 & 4u]);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero)
	{
		mem_write16(a0 + 0x1Eu, (int16_t)(0u - mem_read16(a0 + 0x1Eu)) >> 1);
		t1 = mem_read8(a0 + 0x4Au);
		mem_write8(a0 + 0x4Au, t1 - 1u);
		if (t1 == 1u)
		{
			d7 = (d7 & ~0xFFu) | 0x11u;
			func_0091A4((uint8_t)d7, 0u);
			a6 = animations_05CEEE_ADDRESS;
			set_animation(0u, a0, a6);
			mem_write8(a0 + 0x42u, 0xFFu);
			mem_write8(a0, mem_read8(a0) | 4u);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		}
	}
	return d7;
}

void func_04C3F2(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
}

void func_04C4E6(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, 0x81u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04C410_ADDRESS;
	set_animation(0u, a0, a6);
}

uint32_t func_04C4FC(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read16(a0 + 0xCu) >= 0x100u)
		return d7;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0xDu;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x4C41Au;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_04C522(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t a5 = *p_a5;
	uint32_t zero = 0;
	uint32_t a5_2 = 0, a6 = 0, d6_2 = 0, d7_2 = 0, ignored = 0;
	uint16_t t1 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	d6_2 = 3u;
	a5_2 = record_04C4C6_ADDRESS;
	do
	{
		func_047C30(a0, a5_2, &d7_2, &ignored, &zero);
		t1 = d6_2 - 1u;
		d6_2 = t1;
		a5_2 += 8u;
	} while (t1 != 0xFFFFu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x4C444u;
	set_animation(0u, a0, a6);
	*p_d6 = d6_2;
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
	*p_a5 = a5_2;
}

void func_04C552(uint32_t a0)
{
	mem_write16(a0, 0x8100u);
	mem_write16(a0 + 2u, 0u);
	mem_write16(a0 + 4u, 0u);
}

void func_04C5F4(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0_2 = 0;
	uint16_t d0 = 0, d1 = 0;
	uint32_t a6 = 0;

	mem_write16(a0, 0x8100u);
	d0 = (uint16_t)((uint32_t)(int8_t)mem_read8(a0 + 3u) << 2);
	a6 = TABLE32(animations_04C5D4, (uint32_t)(int16_t)d0);
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Eu, mem_read16(0x4C5E6u + (int16_t)d0));
	d0_2 = (uint8_t)TABLE16(indexed_table_of_16_bit_values_04C5E4, (uint32_t)(int16_t)d0);
	d1 = 0x500u;
	func_047CCC(d0_2, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_04C63A(uint32_t a0)
{
	if ((mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
	func_04824C(a0);
}

void func_04C6E8(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0, 0x8100u);
	a6 = 0x4C6E0u;
	if (mem_read8(a0 + 3u) != 0u)
		a6 = 0x4C6E4u;
	mem_write32(a0 + 0x24u, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04C65E_ADDRESS;
	set_animation(0u, a0, a6);
}

uint32_t func_04C716(uint32_t a0)
{
	uint32_t a1 = 0;

	a1 = mem_read32(a0 + 0x24u);
	if (mem_read16(a0 + 0xCu) <= mem_read16(a1))
	{
		mem_write8(a0 + 0x46u, mem_read8(a1 + 2u));
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
	return a1;
}

void func_04C730(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a5_2 = 0, a6 = 0, ignored = 0, ignored_3 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		d7_2 = 0x36u;
		func_0091A4(d7_2, 0u);
		a6 = 0x4C668u;
		set_animation(0u, a0, a6);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		if (unk_061207 < 3u)
		{
			a5 = 0x4C6D8u;
			func_047C30(a0, a5, &d7, &ignored, &zero);
		}
		else
		{
			a5_2 = record_04C6C8_ADDRESS;
			func_047C30(a0, a5_2, &ignored_3, &ignored, &zero);
			a5 = 0x4C6D0u;
			func_047C30(a0, a5, &d7, &ignored, &zero);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
	*p_a5 = a5;
}

void func_04C784(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u && (mem_read8(a0) & 0x20u) != 0u)
		mem_write16(a0, 0u);
}

void func_04C824(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write8(a0 + 0x46u, 0x18u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_04C7B2_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04C840(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 0x46u, 0x20u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_04C7B2_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04C860(uint32_t a0)
{
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
	t2 = mem_read32(a0 + 0x16u) - 0x100u;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
}

void func_04C89C(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06120C++;
	mem_write8(a0 + 0x32u, 0u);
	mem_write8(a0, 0x81u);
	mem_write16(a0 + 0x20u, 0x168u);
	if ((mem_read8(a0 + 3u) & 0x80u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write16(a0 + 0x20u, 0xA0u);
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	a6 = 0x5C890u;
	set_animation(0u, a0, a6);
}

void func_04C8E0(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if (mem_read16(a0 + 0x20u) < mem_read16(a0 + 0xCu))
		return;
	t1 = mem_read32(a0 + 0x16u) - 0x1000u;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_05C846_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04C906(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write32(a0 + 0x1Au, 0x80u);
	if ((mem_read8(a0 + 3u) & 0x40u) != 0u)
		mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

uint32_t func_04C936(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x5C87Au;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04C964(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		d7_2 = 8u;
		func_0091A4(d7_2, 0u);
		*p_a5 = 0x4C894u;
		func_047C30(a0, *p_a5, &d7, &a6, &zero);
		if (zero)
			mem_write8(a6 + 3u, mem_read8(a0 + 3u));
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = 0x54F36u;
		set_animation(0u, a0, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04C9C6(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06120C++;
	mem_write8(a0, 0x81u);
	mem_write16(a0 + 0x20u, 0x160u);
	if ((mem_read8(a0 + 3u) & 0x80u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write16(a0 + 0x20u, 0xA0u);
	}
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	a6 = 0x54F56u;
	set_animation(0u, a0, a6);
}

void func_04CA06(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if (mem_read16(a0 + 0x20u) < mem_read16(a0 + 0xCu))
		return;
	t1 = mem_read32(a0 + 0x16u) - 0x1000u;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x54EECu;
	set_animation(0u, a0, a6);
}

void func_04CA2C(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t ignored = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write32(a0 + 0x1Au, 0x80u);
		if ((mem_read8(a0 + 3u) & 0x40u) != 0u)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
		mem_write16(a0 + 0x1Eu, 0x400u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		*p_a5 = 0x4C9BEu;
		func_047C30(a0, *p_a5, &d7, &ignored, &zero);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04CA68(uint32_t a0)
{
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	if ((int8_t)mem_read8(a0 + 0x10u) >= 0)
		return;
	mem_write16(a0 + 0x10u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x54F20u;
	set_animation(0u, a0, a6);
}

void func_04CA98(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		d7_2 = 8u;
		func_0091A4(d7_2, 0u);
		*p_a5 = 0x4C9B6u;
		func_047C30(a0, *p_a5, &d7, &a6, &zero);
		if (zero)
			mem_write8(a6 + 3u, mem_read8(a0 + 3u));
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = 0x54F36u;
		set_animation(0u, a0, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04CAD2(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0, 0x8100u);
		mem_write16(a0 + 2u, 0u);
		mem_write16(a0 + 4u, 0u);
	}
}

uint32_t func_04CBFC(uint32_t a0)
{
	uint32_t a5 = 0;

	a5 = object_tile_blocks_ADDRESS + (int16_t)TABLE16(object_tile_block_offsets, (uint32_t)(int16_t)((uint32_t)(int8_t)mem_read8(a0 + 3u) << 1));
	mem_write16(a0 + 0x20u, mem_read16(a5));
	a5 += 2u;
	mem_write16(a0 + 0x46u, mem_read16(a5));
	a5 += 2u;
	mem_write32(a0 + 0x24u, a5);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return a5;
}

void func_04CC2E(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	if (mem_read16(a0 + 0x20u) < mem_read16(a0 + 0xCu))
		return;
	t1 = mem_read8(a0 + 0x47u);
	mem_write8(a0 + 0x47u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write8(a0 + 0x46u, 4u);
	*p_a5 = record_04CBAC_ADDRESS;
	func_047C30(a0, *p_a5, &d7_2, &ignored, &zero);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04CAFE_ADDRESS;
	set_animation(0u, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
}

void func_04CC76(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t a5 = *p_a5;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04CCA0(a0);
	else
	{
		do
		{
			a5 = mem_read32(a0 + 0x24u);
			a6 = mem_read32(a5);
			a5 += 4u;
			d7 = (uint16_t)(int8_t)mem_read8(a5);
			a5++;
			mem_write8(a0 + 0x46u, mem_read8(a5));
			a5++;
			mem_write32(a0 + 0x24u, a5);
			draw_tile_block(d7, a6);
		} while (mem_read8(a0 + 0x46u) != 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		func_04CCA0(a0);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7;
	*p_a5 = a5;
}

void func_04CCA0(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	t1 = mem_read32(a0 + 0x16u) - 0x80u;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Eu));
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	if ((int16_t)mem_read16(a0 + 0x1Eu) < -0x4000)
		mem_write16(a0 + 0x1Eu, 0xFC00u);
	if (mem_read8(a0 + 0x10u) < 0xF0u)
		return;
	mem_write16(a0 + 0x10u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x4CB1Eu;
	set_animation(0u, a0, a6);
}

void func_04CCEC(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 2u, 0u);
		mem_write16(a0 + 4u, 0u);
	}
}

void func_04CD80(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = object_tile_block_pairs_ADDRESS + (int16_t)((int8_t)mem_read8(a0 + 3u) * 0xCu);
	mem_write16(a0 + 0x20u, mem_read16(a6));
	mem_write32(a0 + 0x24u, a6 + 2u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_04CDAA(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint16_t d7_2 = 0;
	uint32_t a5 = 0, a6 = 0, ignored = 0;

	if ((int16_t)mem_read16(a0 + 0x20u) <= (int16_t)mem_read16(a0 + 0xEu))
	{
		a5 = mem_read32(a0 + 0x24u);
		d7_2 = (uint16_t)(int8_t)mem_read8(a5);
		a6 = mem_read32(a5 + 2u);
		draw_tile_block(d7_2, a6);
		d7_2 = (uint16_t)(int8_t)mem_read8(a5 + 1u);
		a6 = mem_read32(a5 + 6u);
		draw_tile_block(d7_2, a6);
		mem_write8(a0, mem_read8(a0) | 0x80u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
		mem_write16(a0 + 0x1Eu, 0u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		*p_a5 = record_04CD3C_ADDRESS;
		func_047C30(a0, *p_a5, &d7, &ignored, &zero);
		a6 = animations_04CD10_ADDRESS;
		set_animation(0u, a0, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04CE06(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	t1 = mem_read32(a0 + 0x12u) - 0x280u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + mem_read16(a0 + 0x1Eu));
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	if ((int16_t)mem_read16(a0 + 0x1Eu) < -0x4000)
		mem_write16(a0 + 0x1Eu, 0xFC00u);
	if (mem_read8(a0 + 0x10u) < 0xF0u)
		return;
	mem_write16(a0 + 0x10u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x4CD26u;
	set_animation(0u, a0, a6);
}

uint32_t func_04CECA(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d0 = 0, d7_2 = 0;

	mem_write8(a0, 0x81u);
	a6 = animations_04CE5A_ADDRESS;
	d0 = 0x80u;
	if ((int8_t)mem_read8(a0 + 3u) < 0)
	{
		a6 = 0x4CE7Au;
		d0 = 0xFF800000u;
	}
	mem_write32(a0 + 0x1Au, d0);
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Eu, 0u);
	d7_2 = (d7 & ~0xFFu) | 0x40u;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	return d7_2;
}

void func_04CF10(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0, 0u);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
}

void func_04CF74(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write16(a0 + 0x1Au, 0xFF00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 0x32u, 0x50u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_0547C6_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04CF9A(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_04826A(a0);
	if (mem_read16(a0 + 0xCu) >= 0x120u)
		return;
	func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	if (mem_read8(a6 + 0x32u) != 0x50u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6_2 = animations_04CF3E_ADDRESS;
		set_animation(0u, a0, a6_2);
		return;
	}
	mem_write8(a0 + 0x22u, 0u);
	mem_write16(a0 + 4u, 0x200u);
}

void func_04CFD6(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Eu, 0x200u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0xFF80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	a6 = 0x4CF5Eu;
	set_animation(0u, a0, a6);
}

uint32_t func_04D006(uint32_t d7, uint32_t a0)
{
	func_048938(a0);
	return func_04D00C(d7, a0);
}

uint32_t func_04D00C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	if ((int16_t)mem_read16(a0 + 0x1Eu) < -0x4000)
		mem_write16(a0 + 0x1Eu, 0xFC00u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x4CB1Eu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04D04A(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x22u, 0u);
		mem_write16(a0 + 4u, 0x200u);
	}
}

void func_04D072(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x46u, 0x10u);
	a6 = 0x4C444u;
	set_animation(0u, a0, a6);
}

void func_04D08E(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_04CF3E_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04D1AE(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06120C++;
	mem_write8(a0, 0x81u);
	mem_write16(a0 + 0x1Au, 0xFF80u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 0x46u, 0x5Au);
	mem_write8(a0 + 0x32u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04D0BC_ADDRESS;
	set_animation(0u, a0, a6);
}

uint32_t func_04D1DE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (mem_read16(a0 + 0xCu) >= 0xA0u)
	{
		if (mem_read16(a0 + 0xCu) >= 0x160u)
			mem_write16(a0 + 0x1Au, 0xFF80u);
	}
	else
		mem_write16(a0 + 0x1Au, 0x80u);
	func_04824C(a0);
	if ((mem_read8(a0) & 0x20u) == 0u)
	{
		t1 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t1 - 1u);
		if (t1 != 1u)
			return d7;
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		d7_2 = (d7 & ~0xFFu) | 0xEu;
		func_0091A4((uint8_t)d7_2, 0u);
		a6 = 0x4D0D6u;
		set_animation(0u, a0, a6);
		return d7_2;
	}
	mem_write16(a0, 0u);
	t2 = unk_06120C - 1u;
	unk_06120C = t2;
	if ((int8_t)t2 < 0)
		unk_06120C = 0u;
	return d7;
}

void func_04D24C(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		a6 = 0x4D100u;
		set_animation(0u, a0, a6);
		*p_a5 = record_04D1A6_ADDRESS;
		func_047C30(a0, *p_a5, &d7, &a6, &zero);
		if (zero == 0u)
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		else
		{
			mem_write8(a6, mem_read8(a0));
			mem_write8(a6, mem_read8(a6) & 0x41u);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04D288(uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0, 0u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
}

void func_04D2A6(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 4u, 1u);
	mem_write8(a0 + 0x46u, 0x5Au);
	a6 = animations_04D0BC_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04D2D4(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Eu, 0x600u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

uint32_t func_04D2FE(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	mem_write8(a0 + 0x32u, 0u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04D330(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04D46C(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;

	d0 = 0x10u;
	d1 = 0x180u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_04D488(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0xCu) >= 0x160u)
		return;
	mem_write8(a0 + 0x22u, 0x4Au);
	mem_write8(a0, 0x81u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_04D35C_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04D4B0(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x22u, 0x48u);
	a6 = animations_05CA64_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04D4D0(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		*p_a5 = record_04D466_ADDRESS;
		func_047C5A(a0, *p_a5, &d7, &ignored, &zero);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = 0x4D3A8u;
		set_animation(0u, a0, a6);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04D4FE(uint32_t a0)
{
	uint32_t a6 = 0;
	uint32_t t1 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	t1 = mem_read32(a0 + 0x12u) + 0x1000u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	mem_write8(a0 + 0x22u, 0x1Eu);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x547F8u;
	set_animation(0u, a0, a6);
}

void func_04D52C(uint32_t a0)
{
	uint8_t t1 = 0;

	func_04824C(a0);
	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0 + 2u, 0u);
		mem_write16(a0 + 4u, 0u);
	}
}

void func_04D564(uint32_t a0)
{
	uint32_t a6 = 0;

	unk_06120C++;
	mem_write8(a0, mem_read8(a0) | 0x82u);
	a6 = animations_05C92A_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0x1Au, 0xFFC0u);
	mem_write8(a0 + 0x46u, 1u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_04D58E(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0;

	a6 = mem_read32(a0 + 0x20u);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x46u, 8u);
		func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
		mem_write32(a0 + 0x20u, a6);
	}
	func_0482FA(a0, a6, &ignored, &ignored_2);
	mem_write16(a0 + 0x1Cu, 0x80u);
	if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
		mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	func_04826A(a0);
	if (mem_read16(a0 + 0xCu) < 0x170u && mem_read16(a0 + 0x2Eu) < 0x10u)
	{
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a6 = 0x5C944u;
		set_animation(ignored, a0, a6);
	}
}

void func_04D5EE(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0, d7_3 = 0, ignored = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) & ~2u);
	d7_2 = 8u;
	func_0091A4(d7_2, 0u);
	*p_a5 = 0x4D558u;
	func_047C5A(a0, *p_a5, &d7_3, &ignored, &zero);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = 0x54F36u;
	set_animation(0u, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

void func_04D624(uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0, 0x8100u);
		mem_write16(a0 + 2u, 0u);
		mem_write16(a0 + 4u, 0u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
}

void func_04D64C(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	*p_a5 = 0x4D55Eu;
	func_047C5A(a0, *p_a5, &ignored, &a6, &zero);
	if (zero)
		mem_write8(a6 + 3u, 1u);
	t1 = unk_06120C - 1u;
	unk_06120C = t1;
	if ((int8_t)t1 < 0)
		unk_06120C = 0u;
	func_0489E2(a0, a6, p_d5, p_d6, &ignored, p_a5);
	mem_write16(a0 + 2u, 0u);
	mem_write16(a0 + 4u, 0x400u);
	if ((int8_t)mem_read8(mem_read32(a0 + 0x24u) + 0x58u + (mem_read8(a0 + 7u) & 0x7Fu)) < 0)
		mem_write16(a0 + 8u, 0u);
	func_048DBA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_04D6C8(uint32_t a0)
{
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_04D6CE(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint16_t d7_3 = 0;
	uint32_t a5 = 0, a6 = 0, ignored = 0, ignored_3 = 0;

	if (mem_read16(a0 + 0xCu) < 0x100u)
	{
		mem_write8(a0, mem_read8(a0) | 0x80u);
		a6 = animations_05CDA0_ADDRESS;
		set_animation(0u, a0, a6);
		d7_2 = 0x3Fu;
		func_0091A4(d7_2, a6);
		d7_3 = 0x22u;
		a6 = 0x1904Au;
		draw_tile_block(d7_3, a6);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		a5 = 0x4D6B8u;
		func_047C30(a0, a5, &ignored, &ignored_3, &zero);
		*p_a5 = 0x4D6C0u;
		func_047C30(a0, *p_a5, &d7, &ignored_3, &zero);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

uint32_t func_04D722(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	mem_write16(a0, 0u);
	d7_2 = (d7 & ~0xFFFFu) | 0x23u;
	a6 = 0x19100u;
	draw_tile_block((uint16_t)d7_2, a6);
	d7_2 = (d7_2 & ~0xFFFFu) | 0x24u;
	a6 = 0x19152u;
	draw_tile_block((uint16_t)d7_2, a6);
	return d7_2;
}

void func_04D76C(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	a6 = animations_05CE9E_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04D782(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint16_t d7_3 = 0;
	uint32_t a6 = 0, d7_2 = 0, ignored = 0;

	if (mem_read16(a0 + 0xCu) >= 0x140u)
		return;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_a5 = 0x4D75Cu;
	func_047C30(a0, *p_a5, &d7_2, &ignored, &zero);
	d7_3 = (uint16_t)((d7_2 & ~0xFFu) | 0x36u);
	func_0091A4((uint8_t)d7_3, ignored);
	mem_write8(a0 + 0x46u, 0x18u);
	mem_write8(a0 + 0x47u, rom_04D764[unk_060130 & 7u]);
	a6 = 0x5CEA8u;
	set_animation(0u, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_3;
}

void func_04D7D0(uint32_t a0)
{
	mem_write8(a0 + 0x46u, mem_read8(a0 + 0x46u) - 1u);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & 0x7Fu);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
}

void func_04D7E8(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x46u, 0x18u);
		*p_a5 = 0x4D75Cu;
		func_047C30(a0, *p_a5, &d7, &ignored, &zero);
		t2 = mem_read8(a0 + 0x47u);
		mem_write8(a0 + 0x47u, t2 - 1u);
		if (t2 == 1u)
			mem_write16(a0, 0u);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04D820(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x46u, 0x60u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0xFF00u);
	if (mem_read8(a0 + 0xCu) == 0u)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	a6 = animations_05C52C_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04D856(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	func_04824C(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x1Eu, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0u);
	a6 = 0x4CF68u;
	set_animation(0u, a0, a6);
}

uint32_t func_04D884(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	mem_write8(a0 + 0x32u, 0u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x4CB1Eu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04D8AC(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x22u, 0u);
		mem_write16(a0 + 4u, 0x200u);
	}
}

void func_04D8E0(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0xC2u);
	mem_write32(a0 + 0x1Au, 0x3000000u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	if (mem_read8(a0 + 0xCu) != 0u)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		mem_write8(a0, mem_read8(a0) & 0xBFu);
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x46u, 0x28u);
	a6 = 0x54A78u;
	set_animation(0u, a0, a6);
}

void func_04D91C(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
}

uint32_t func_04D93A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x4D8D4u;
	d7 = func_04863E(d7, a0, a6);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54B1Cu;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_04D96C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048262(a0);
	a6 = 0x4D8D4u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04D9A6(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x22u, 0u);
		mem_write16(a0 + 4u, 0x200u);
	}
}

void func_04D9C2(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x46u, 0x7Eu);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x1Au, 0x1800000u);
	if (mem_read8(a0 + 0xCu) != 0u)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		mem_write8(a0, mem_read8(a0) | 0x40u);
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54908u;
	set_animation(0u, a0, a6);
}

void func_04D9F8(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
		mem_write16(a0 + 4u, 0x200u);
	func_04826A(a0);
}

void func_04DA2C(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write16(a0 + 0x1Au, 0xFD00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x46u, 0x20u);
	mem_write8(a0 + 0x32u, 0x50u);
	a6 = 0x54A78u;
	set_animation(0u, a0, a6);
}

void func_04DA58(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	if (mem_read16(a0 + 0xCu) >= 0x120u)
	{
		func_04826A(a0);
		return;
	}
	func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	if (mem_read8(a6 + 0x32u) == 0x50u)
	{
		mem_write8(a0 + 0x22u, 0u);
		mem_write16(a0 + 4u, 0x200u);
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6_2 = 0x54ACEu;
	set_animation(0u, a0, a6_2);
}

void func_04DA92(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x1Au, 0xFF80u);
	mem_write16(a0 + 0x1Cu, 0xFF80u);
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write8(a0 + 0x46u, 0xCu);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ADAu;
	set_animation(0u, a0, a6);
}

void func_04DACA(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = animations_05C566_ADDRESS;
		set_animation(0u, a0, a6);
	}
	func_048938(a0);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x38u);
}

void func_04DAF6(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 0x46u, 0x14u);
		mem_write8(a0 + 0x43u, 2u);
		a6 = 0x54AEEu;
		set_animation(0u, a0, a6);
	}
	func_048938(a0);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x38u);
}

void func_04DB1A(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 0x43u, 0u);
		a6 = 0x54AE4u;
		set_animation(0u, a0, a6);
	}
	func_048938(a0);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x38u);
}

uint32_t func_04DB36(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048938(a0);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x38u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54ACEu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04DB76(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x81u);
	mem_write16(a0 + 0x1Au, 0xFEC0u);
	if (mem_read8(a0 + 0xCu) != 0u)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 0x46u, 0x1Au);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_0547C6_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04DBAE(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	func_04826A(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 0x46u, 0x30u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05C5A4_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04DBD4(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04DC04(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x87u);
	mem_write8(a0 + 0x42u, 7u);
	mem_write8(a0 + 0x32u, 0u);
	func_048746(a0);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x54096u);
	mem_write16(a0 + 0x28u, (mem_read8(a0 + 3u) & 0xF0u) << 2);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = animations_056F42_ADDRESS;
	set_animation(0u, a0, a6_2);
}

void func_04DC9E(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x84u);
	mem_write8(a0 + 0x42u, 4u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write8(a0 + 0x4Au, indexed_table_of_8_bit_values_04DD2C[unk_060130 & 7u]);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x5411Eu);
	mem_write16(a0 + 0x28u, (mem_read8(a0 + 3u) & 0xF0u) << 2);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = 0x55C60u;
	set_animation(0u, a0, a6_2);
}

void func_04DD34(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DD40_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DD50(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04DD48_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DD76(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DD82_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DD8E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DD48_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04DD48_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DDB4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DDC0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DDC8(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xB4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) >= 0)
		mem_write16(a0 + 0x40u, 0u - mem_read16(a0 + 0x40u));
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DDF8(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DD48_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Eu) >= 0x20u)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x40u));
		if (mem_read16(a0 + 0x2Cu) >= 0x40u)
		{
			mem_write16(a0 + 0x40u, 0x100u);
			if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) >= 0)
				mem_write16(a0 + 0x40u, 0u - mem_read16(a0 + 0x40u));
		}
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, 0x100u);
		if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DE60(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DE6C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DE78(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 0x46u, 0x20u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0x100u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DEB2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04826A(a0);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x55D62u;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DEE2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DEEE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DEF6(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = 0x60u;
	if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
		d0 = (uint8_t)(0u - d0);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		d0 ^= 0x40u;
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, &ignored);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	func_0484B2(d0, a0, a6, p_d6, p_d7, p_a5);
}

void func_04DF40(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 0x2Au, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DD48_ADDRESS;
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DF64(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DF70_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DF80(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x140u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04DF78_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04DF78_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DFA6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DFB2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04DFBE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x140u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04DF78_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04DFE4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04DFF0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E018(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, ignored = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0xB4u);
	a6 = animations_04DFF8_ADDRESS;
	func_0486F6(a0, a6, &d0, &ignored);
	mem_write8(a0 + 0x4Au, 0u);
	if ((int8_t)(uint8_t)(unk_06120E >> 8u) >= 0)
	{
		func_04E042((uint8_t)d0, a0, p_d6, p_d7, p_a5);
		return;
	}
	mem_write8(a0 + 0x4Au, 1u);
	func_04E042((uint8_t)d0, a0, p_d6, p_d7, p_a5);
}

void func_04E042(uint8_t d0, uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;

	if (mem_read8(a0 + 0x4Au) != 0u)
		d0 += 0x50u;
	else
		d0 -= 0x30u;
	d1 = 0x140u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
}

void func_04E06A(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0, d0 = 0, d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 1u);
	t1 = d7_2 & 0x1Eu;
	d7_2 = (d7_2 & ~0xFFu) | t1;
	if (t1 != 0u)
	{
		mem_write8(a0 + 0x4Au, mem_read8(a0 + 0x4Au) ^ 1u);
		a6 = animations_04DFF8_ADDRESS;
		func_0486F6(a0, a6, &d0, &ignored);
		func_04E042((uint8_t)d0, a0, p_d6, &d7_2, p_a5);
		func_04826A(a0);
		*p_d7 = d7_2;
		return;
	}
	if (mem_read8(a0 + 0x2Bu) != mem_read8(a0 + 0x30u))
	{
		a6 = animations_04DFF8_ADDRESS;
		func_0486F6(a0, a6, &d0, &ignored);
		func_04E042((uint8_t)d0, a0, p_d6, &d7_2, p_a5);
	}
	func_04826A(a0);
	*p_d7 = d7_2;
}

void func_04E0A8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E0B4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04E0C4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_04DFF8_ADDRESS;
	func_0486F6(a0, a6, &ignored, &d7);
	mem_write8(a0 + 0x33u, 0u);
	return d7;
}

void func_04E0E0(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, ignored = 0, ignored_2 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	if (mem_read8(a0 + 0x2Bu) != mem_read8(a0 + 0x30u))
	{
		a6 = animations_04DFF8_ADDRESS;
		func_0486F6(a0, a6, &ignored, p_d7);
		mem_write8(a0 + 0x33u, 0u);
	}
	if (mem_read16(a0 + 0x2Cu) < 0x50u && mem_read16(a0 + 0x2Eu) < 0x20u)
	{
		mem_write8(a0 + 5u, 2u);
		d0 = (uint8_t)(mem_read8(a0 + 0x2Bu) - 0x80u);
		a5 = animations_04DF78_ADDRESS;
		a6 = mem_read32(a1);
		func_0484B2(d0, a0, a6, &ignored_2, p_d7, &a5);
		d1 = 0x100u;
		func_047CCC(d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
		return;
	}
	if (mem_read16(a0 + 0x2Cu) >= 0x70u || mem_read16(a0 + 0x2Eu) >= 0x40u)
	{
		mem_write8(a0 + 5u, 3u);
		d0 = mem_read8(a0 + 0x2Bu);
		a5 = animations_04DF78_ADDRESS;
		a6 = mem_read32(a1);
		func_0484B2(d0, a0, a6, &ignored_2, p_d7, &a5);
		d1 = 0x100u;
		func_047CCC(d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
	}
}

void func_04E16A(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	if (mem_read16(a0 + 0x2Cu) >= 0x50u || mem_read16(a0 + 0x2Eu) >= 0x20u)
		mem_write8(a0 + 5u, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E186(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	if (mem_read16(a0 + 0x2Cu) < 0x70u && mem_read16(a0 + 0x2Eu) < 0x40u)
		mem_write8(a0 + 5u, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E1B8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E1C4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E1D0(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 0x46u, 0x1Eu);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &ignored, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x140u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04E20A(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0, ignored = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04E23E(a0, a1);
	else
	{
		a6 = animations_04DFF8_ADDRESS;
		func_0486F6(a0, a6, &ignored, p_d7);
		mem_write8(a0 + 0x33u, 0u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		func_04E23E(a0, a1);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E23E(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04E254(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E260_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E268(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0x140u);
	if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
		mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E2A0(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 0x2Au, 0u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04DF78_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E2C4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E2D0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04E2D8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x55D6Cu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x202u);
	d7_2 = (d7 & ~0xFFu) | 3u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04E300(uint32_t a0)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	if ((mem_read8(a0) & 8u) != 0u)
	{
		t1 = mem_read8(a0 + 0x4Au);
		mem_write8(a0 + 0x4Au, t1 - 1u);
		if (t1 == 1u)
		{
			mem_write16(a0 + 0x28u, 0x4Cu);
			mem_write16(a0 + 4u, 0x300u);
			mem_write8(a0, mem_read8(a0) & ~8u);
			return;
		}
	}
	func_0485F6(a0);
}

void func_04E336(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E342_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E354(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 0x22u, 0x14u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55DB6u;
	set_animation(0u, a0, a6);
}

void func_04E380(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint32_t d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	*p_a5 = 0x4E34Eu;
	func_047C5A(a0, *p_a5, &d7_2, &ignored, &zero);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
}

void func_04E3A0(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_0486CC(a0, a1);
	mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
	mem_write16(a0 + 2u, 0u);
	func_0489EE(a0, a6, p_d5, p_d6, p_d7, p_a5);
	mem_write16(a0 + 4u, 0x200u);
}

void func_04E3C4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E3D0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04E3D8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x570AAu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x202u);
	d7_2 = (d7 & ~0xFFu) | 3u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04E400(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E40C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04E414(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x5714Cu;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x302u);
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04E43C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E448_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04E464(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x57088u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x303u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

uint32_t func_04E48C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	a6 = 0x4E458u;
	d7 = func_04863E(d7, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x57190u;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_04E4B8(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x4E458u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x57088u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04E4F2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E4FE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E510(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 0x46u, 0x14u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x570DCu;
	set_animation(0u, a0, a6);
}

void func_04E53C(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint32_t d7_2 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_a5 = 0x4E50Au;
	func_047C5A(a0, *p_a5, &d7_2, &ignored, &zero);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_2 & 0xFFFFu);
}

void func_04E556(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	func_0485F6(a0);
}

void func_04E566(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E572_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E57A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55E30u;
	set_animation(0u, a0, a6);
}

void func_04E58A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E596_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E59E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55E64u;
	set_animation(0u, a0, a6);
}

void func_04E5AE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E5BA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E5C2(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55E8Eu;
	set_animation(0u, a0, a6);
}

void func_04E5D2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E5DE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E5E6(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55EB8u;
	set_animation(0u, a0, a6);
}

void func_04E5F6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E602_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E60A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x571C2u;
	set_animation(0u, a0, a6);
}

void func_04E61A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E626_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E62E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x571F6u;
	set_animation(0u, a0, a6);
}

void func_04E63E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E64A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E652(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x57220u;
	set_animation(0u, a0, a6);
}

void func_04E662(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E66E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E676(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5724Au;
	set_animation(0u, a0, a6);
}

void func_04E6A2(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x85u);
	mem_write8(a0 + 0x42u, 5u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x541A6u);
	mem_write16(a0 + 0x28u, (mem_read8(a0 + 3u) & 0xF0u) << 2);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = 0x575AAu;
	set_animation(0u, a0, a6_2);
}

void func_04E736(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x85u);
	mem_write8(a0 + 0x42u, 5u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x5422Eu);
	mem_write16(a0 + 0x28u, (mem_read8(a0 + 3u) & 0xF0u) << 2);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = 0x56A08u;
	set_animation(0u, a0, a6_2);
}

void func_04E7AE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E7BA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E7CE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x120u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04E7C2_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04E7C2_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E7F4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E800_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E80C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04E7C2_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04E7C2_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E832(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E83E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E84A(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04E7C2_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04E7C2_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E870(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a5 = 0, a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	a5 = mem_read32(a0 + 0x46u);
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, &a5);
	if (mem_read16(a0 + 0x2Cu) < 0x5Au)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x40u));
		if ((int8_t)mem_read8(a0 + 0x45u) < 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, mem_read16(a0 + 0x40u));
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	if (mem_read16(a0 + 0x2Eu) >= 2u)
		func_04826A(a0);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a5 = mem_read32(a0 + 0x46u);
		a6 = mem_read32(a5 + 8u);
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_a5 = a5;
}

void func_04E8D8(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d6 = (uint16_t)*p_d6;
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6_2 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	if (mem_read16(a0 + 0x2Eu) < 3u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = mem_read32(a0 + 0x46u);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6_2, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6_2 & 0xFFFFu);
}

void func_04E8FA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E906_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E912(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 0x46u, 0x20u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &ignored, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04E94C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04E97C(a0, a1);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x56B1Eu;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04E97C(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04E992(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04E99E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04E9A6(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 8u);
	d0 = (uint8_t)(mem_read8(a0 + 0x2Bu) - 0x80u);
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, &ignored);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, p_d6, p_d7, p_a5);
	func_04E9DE(a0, a1, p_d6, p_d7, p_a5);
}

void func_04E9DE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04E7C2_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04EA06(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EA12_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EA26(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x140u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_04EA1A_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04EA1A_ADDRESS);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04EA4C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EA58_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EA64(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x140u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04EA1A_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04EA1A_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04EA8A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EA96_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EAA2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x40u, 0x100u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04EA1A_ADDRESS;
	mem_write32(a0 + 0x46u, animations_04EA1A_ADDRESS);
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04EAC8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EAD4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EAE0(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 0x46u, 0x28u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &ignored, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04EB1C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		func_04EB4C(a0, a1);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x576E4u;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04EB4C(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04EB62(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EB6E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EB76(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 8u);
	d0 = (uint8_t)(mem_read8(a0 + 0x2Bu) - 0x80u);
	d1 = 0x180u;
	func_047CCC(d0, d1, p_d6, p_d7, &ignored);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, p_d6, p_d7, p_a5);
	func_04EBAE(a0, a1, p_d6, p_d7, p_a5);
}

void func_04EBAE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_04EA1A_ADDRESS;
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04EBD6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EBE2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EBF4(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a0 + 0x46u, 0x1003u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x576ACu;
	set_animation(0u, a0, a6);
}

void func_04EC20(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		d7_2 = 2u;
		func_0091A4(d7_2, 0u);
		*p_a5 = 0x4EBEEu;
		func_047C5A(a0, *p_a5, &d7, &ignored, &zero);
		mem_write8(a0 + 0x46u, 0x10u);
		t2 = mem_read8(a0 + 0x47u);
		mem_write8(a0 + 0x47u, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
			a6 = 0x576E4u;
			set_animation(0u, a0, a6);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04EC5E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EC6A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04EC72(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x5773Au;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x302u);
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04EC9A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ECA6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04ECAE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x56AB4u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x302u);
	d7_2 = (d7 & ~0xFFu) | 1u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04ECD6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ECE2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04ECF4(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a0 + 0x46u, 0x804u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x56AF0u;
	set_animation(0u, a0, a6);
}

void func_04ED20(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		d7_2 = 0x18u;
		func_0091A4(d7_2, 0u);
		*p_a5 = 0x4ECEEu;
		func_047C5A(a0, *p_a5, &d7, &ignored, &zero);
		mem_write8(a0 + 0x46u, 8u);
		t2 = mem_read8(a0 + 0x47u);
		mem_write8(a0 + 0x47u, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
			a6 = 0x56B1Eu;
			set_animation(0u, a0, a6);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04ED5E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ED6A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04ED72(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x56B7Cu;
	set_animation(0u, a0, a6);
}

void func_04ED82(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04ED8E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04ED96(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x56BB0u;
	set_animation(0u, a0, a6);
}

void func_04EDA6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EDB2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EDBA(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5777Eu;
	set_animation(0u, a0, a6);
}

void func_04EDCA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EDD6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EDDE(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x577B2u;
	set_animation(0u, a0, a6);
}

void func_04EDEE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04EDFA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04EE02(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x577DCu;
	set_animation(0u, a0, a6);
}

void func_04EE2E(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x86u);
	mem_write8(a0 + 0x42u, 6u);
	mem_write8(a0 + 0x32u, 0u);
	func_048746(a0);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x542B6u);
	mem_write16(a0 + 0x28u, (mem_read8(a0 + 3u) & 0xF0u) << 2);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = animations_0547C6_ADDRESS;
	set_animation(0u, a0, a6_2);
}

void func_04EEC8(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write8(a0 + 0x4Bu, 0x85u);
	mem_write8(a0 + 0x42u, 5u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x24u, 0x5433Eu);
	mem_write16(a0 + 0x28u, (mem_read8(a0 + 3u) & 0xF0u) << 2);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
	a6_2 = animations_0547C6_ADDRESS;
	set_animation(0u, a0, a6_2);
}

void func_04EF58(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x31u, 5u);
	mem_write16(a0 + 0x34u, 3u);
	unk_06120C++;
	d0 = mem_read8(a0 + 3u);
	mem_write8(a0 + 0x42u, indexed_table_of_8_bit_values_04EFD0[d0]);
	d0 = (uint16_t)((uint32_t)d0 << 2);
	mem_write32(a0 + 0x24u, indexed_table_of_32_bit_values_04EFE0[d0 / 4u]);
	a6_2 = animations_04EFD4[d0 / 4u];
	set_animation(0u, a0, a6_2);
	mem_write16(a0 + 8u, 0x306u);
	mem_write32(a0 + 0x3Au, sprite_lists_05CA54_ADDRESS);
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
}

void func_04EFEC(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t t1 = 0;

	func_048A94(a0, a6, p_d5, p_d6, p_d7, p_a1, p_a5);
	t1 = mem_read32(a0 + 0x12u) + 0x600u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	func_04F038(a0);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	if ((unk_0600A4 & 4u) == 0u)
		mem_write32(a0 + 0x3Au, sprite_lists_05CA54_ADDRESS);
	else
		mem_write32(a0 + 0x3Au, 0x5CA5Cu);
}

void func_04F002(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t t1 = 0;

	func_048D8A(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
	t1 = mem_read32(a0 + 0x12u) + 0x600u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	if ((unk_0600A4 & 4u) == 0u)
		mem_write32(a0 + 0x3Au, sprite_lists_05CA54_ADDRESS);
	else
		mem_write32(a0 + 0x3Au, 0x5CA5Cu);
}

void func_04F014(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t t1 = 0;

	func_048DBA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
	t1 = mem_read32(a0 + 0x12u) + 0x600u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	if ((unk_0600A4 & 4u) == 0u)
		mem_write32(a0 + 0x3Au, sprite_lists_05CA54_ADDRESS);
	else
		mem_write32(a0 + 0x3Au, 0x5CA5Cu);
}

void func_04F026(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t t1 = 0;

	t1 = mem_read32(a0 + 0x12u) + 0x600u;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	func_048EDA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	if ((unk_0600A4 & 4u) == 0u)
		mem_write32(a0 + 0x3Au, sprite_lists_05CA54_ADDRESS);
	else
		mem_write32(a0 + 0x3Au, 0x5CA5Cu);
}

void func_04F038(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = DATA32(animations_04EFD4_ADDRESS + (uint16_t)((uint32_t)mem_read8(a0 + 3u) << 2));
	set_animation(0u, a0, a6);
}

void func_04F076(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F082_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F094(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 0x46u, 0x14u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55A24u;
	set_animation(0u, a0, a6);
}

void func_04F0C0(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t d7_3 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7_2 = 0x2Au;
	func_0091A4(d7_2, 0u);
	*p_a5 = 0x4F08Eu;
	func_047C5A(a0, *p_a5, &d7_3, &ignored, &zero);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

void func_04F0E4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F0F0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F10A(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55ABEu;
	set_animation(0u, a0, a6);
}

void func_04F11A(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55AF2u;
	set_animation(0u, a0, a6);
}

void func_04F150(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0, d7_3 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	d7_2 = 0x2Au;
	func_0091A4(d7_2, 0u);
	*p_a5 = 0x4F104u;
	func_047C5A(a0, *p_a5, &d7_3, &a6, &zero);
	if (zero)
	{
		mem_write32(a6 + 0x20u, a0);
		mem_write32(a0 + 0x46u, a6);
	}
	mem_write8(a0 + 0x22u, 0x3Cu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7_3 & 0xFFFFu);
}

void func_04F186(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	if (mem_read8(mem_read32(a0 + 0x46u) + 4u) == 4u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
		return;
	}
	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x55B3Au;
	set_animation(0u, a0, a6);
}

void func_04F1D2(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write16(a0 + 0x46u, 0x12Cu);
	mem_write16(a0 + 0x48u, 0x1010u);
	unk_06120C++;
	unk_061236++;
	unk_061237 = rom_04F5B4[unk_060130 & 7u];
	mem_write32(a0 + 0x3Au, sprite_lists_059A18_ADDRESS);
	if (mem_read8(a0 + 3u) != 0u)
	{
		mem_write8(a0 + 3u, 0xAu);
		unk_061220 = a0;
		mem_write16(a0 + 4u, 0x104u);
		mem_write8(a0, mem_read8(a0) | 0x80u);
		a6_2 = 0x59CFCu;
		set_animation(0u, a0, a6_2);
		return;
	}
	mem_write8(a0 + 3u, 0xCu);
	*p_d7 = (*p_d7 & ~0xFFFFu) | 0xFEu;
	unk_060080 = *p_d7;
	func_0091A4((uint8_t)*p_d7, a6);
	mem_write8(a0 + 0x40u, 0xAu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6_2 = 0x59CBAu;
	set_animation(0u, a0, a6_2);
}

void func_04F28A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F296_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F2AE(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0 + 0x40u, 0x32u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_059CB0_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04F2CE(uint16_t d0, uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint32_t d7 = *p_d7;
	uint16_t d0_2 = 0, d2 = 0;
	uint32_t a6 = 0, d1 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 != 1u)
		return;
	d7_2 = (d7 & ~0xFFFFu) | 0x64u;
	unk_060080 = d7_2;
	func_0091A4((uint8_t)d7_2, 0u);
	d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
	d1 = (uint16_t)(mem_read16(a0 + 0xCu) - 0x10u);
	d2 = mem_read16(a0 + 0xEu);
	func_03008E(d0_2, d1, d2, &d5, &d6, &d7_2);
	mem_write32(a0 + 0x16u, 0x6C00u);
	mem_write8(a0 + 0x40u, 0x78u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x59D58u;
	set_animation(d1, a0, a6);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7_2;
}

uint32_t func_04F318(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 != 1u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = table_loaded_by_lea_054746_ADDRESS;
	d7 = func_0485AE(d7, a0, a6);
	mem_write8(a0 + 0x40u, 0x10u);
	a6 = animations_0596BA_ADDRESS;
	set_animation(0u, a0, a6);
	return d7;
}

void func_04F340(uint32_t a0)
{
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
	}
	t2 = mem_read32(a0 + 0x16u) - 0x100u;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
}

void func_04F35E(uint32_t a0)
{
	uint32_t a6 = 0;

	if (unk_06123D == 0u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x40u, 0x20u);
	a6 = animations_0596BA_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04F380(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		a6 = 0x54766u;
		func_0485AE(d7, a0, a6);
		a6 = 0xD0B4u;
		d7 = 0x43Au;
		*p_a5 = post_palette_request((uint16_t)d7, a6);
		mem_write16(a0 + 4u, 0x200u);
	}
	t2 = mem_read32(a0 + 0x16u) - 0x100u;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04F3BA(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0, ignored_5 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0, t7 = 0;

	*p_d7 = (*p_d7 & ~0xFFu) | mem_read8(a0 + 3u);
	func_048724((uint8_t)*p_d7, a0);
	t1 = mem_read8(a0 + 0x23u);
	mem_write8(a0 + 0x23u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x23u, 0x10u);
		if (unk_061207 != 0u)
		{
			func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
			mem_write16(a0 + 0x20u, a6);
		}
	}
	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6_2 = *p_a1;
	func_0482FA(a0, a6_2, &ignored, &ignored_2);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	if (unk_061240 != 0u)
	{
		mem_write16(a0 + 0x20u, unk_06123E);
		mem_write16(a0 + 0x28u, 0x98u);
		mem_write16(a0 + 4u, 0x300u);
		return;
	}
	t2 = mem_read16(a0 + 0x46u);
	mem_write16(a0 + 0x46u, t2 - 1u);
	if (t2 != 1u)
	{
		if ((mem_read8(*p_a1 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(*p_a1 + 0x23u)] != 0u) && mem_read16(a0 + 0x2Eu) <= 8u)
		{
			if (mem_read16(a0 + 0x2Cu) > 0x32u)
			{
				t3 = mem_read8(a0 + 0x49u);
				mem_write8(a0 + 0x49u, t3 - 1u);
				if (t3 == 1u && (mem_read8(a0 + 0x2Au) != 0u || unk_061238 != 0x88u))
				{
					a6_2 = 0x4F5C0u;
					*p_a5 = rom_04F5CC_ADDRESS;
					func_04F51C(a0, a6_2, p_d6, p_d7, p_a5);
					mem_write8(a0 + 0x49u, mem_read8(*p_a5 + *p_d7));
					mem_write16(a0 + 4u, 0x300u);
					mem_write8(a0, mem_read8(a0) & ~8u);
					return;
				}
			}
			else
			{
				t4 = mem_read8(a0 + 0x48u);
				mem_write8(a0 + 0x48u, t4 - 1u);
				if (t4 == 1u)
				{
					a6_2 = 0x4F5BCu;
					*p_a5 = rom_04F5C4_ADDRESS;
					func_04F51C(a0, a6_2, p_d6, p_d7, p_a5);
					mem_write8(a0 + 0x48u, mem_read8(*p_a5 + *p_d7));
					mem_write16(a0 + 4u, 0x300u);
					mem_write8(a0, mem_read8(a0) & ~8u);
					return;
				}
			}
		}
		if (mem_read8(a0 + 0x22u) == 0u)
		{
			a6_2 = 0x4F5D4u + (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 3);
			*p_d7 = 0x64u;
			func_048448(a0, &ignored_5, p_d7);
			*p_d6 = 3u;
			for (;;)
			{
				t5 = mem_read8(a6_2 + 4u + (int16_t)*p_d6);
				t6 = *p_d7;
				*p_d7 = (*p_d7 & ~0xFFu) | (uint8_t)(t6 - t5);
				if (t6 < t5)
					break;
				t7 = *p_d6 - 1u;
				*p_d6 = t7;
				if (t7 != 0xFFFFu)
					continue;
				*p_d7 = 0x64u;
				func_048448(a0, &ignored_5, p_d7);
				*p_d6 = 3u;
			}
			*p_d6 = (*p_d6 & ~0xFFu) | mem_read8(a6_2 + (int16_t)*p_d6);
			*p_d6 = (uint16_t)(*p_d6 << 2);
			mem_write16(a0 + 0x28u, *p_d6);
			mem_write8(a0 + 5u, 0u);
		}
	}
	else
	{
		mem_write8(a0 + 0x2Au, mem_read8(a0 + 0x2Au) ^ 1u);
		d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 2);
		mem_write16(a0 + 0x28u, indexed_table_of_16_bit_values_04F58C[d0 / 2u]);
		mem_write8(a0 + 5u, 0u);
		mem_write16(a0 + 0x46u, mem_read16(0x4F594u + (int16_t)rom_04F58E[d0 / 2u] + (uint16_t)((uint32_t)unk_060130 << 2)));
		*p_a5 = rom_04F5C4_ADDRESS;
		mem_write8(a0 + 0x48u, rom_04F5C4[d0]);
		mem_write8(a0 + 0x49u, rom_04F5CC[d0]);
	}
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_04F51C(uint32_t a0, uint32_t a6, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;
	uint32_t d6 = 0;

	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 1);
	mem_write16(a0 + 0x28u, mem_read16(a6 + d0));
	unk_061238 = mem_read16(a0 + 0x28u);
	*p_a5 += (uint16_t)((uint32_t)d0 << 1);
	*p_d7 = 4u;
	func_048448(a0, &d6, p_d7);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_04F5E4(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 3u);
	func_048724((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	func_04F5EE(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_04F5EE(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint32_t jump_target = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = *p_a1;
	func_0482FA(a0, a6, &ignored, &ignored_2);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	jump_target = mem_read32(0x53D2Au + (int16_t)*p_d6);
	switch (jump_target)
	{
	case 0x049A06u:
		func_049A06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049A52u:
		func_049A52(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049A8Eu:
		func_049A8E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049ACAu:
		func_049ACA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049B06u:
		func_049B06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049BBCu:
		func_049BBC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049C72u:
		func_049C72();
		return;
	case 0x049C74u:
		func_049C74();
		return;
	case 0x049C76u:
		func_049C76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B2DAu:
		func_04B2DA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B316u:
		func_04B316(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B352u:
		func_04B352(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B42Au:
		func_04B42A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B4E0u:
		func_04B4E0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B5D6u:
		func_04B5D6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E2C4u:
		func_04E2C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E336u:
		func_04E336(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E3C4u:
		func_04E3C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E400u:
		func_04E400(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E43Cu:
		func_04E43C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E4F2u:
		func_04E4F2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EBD6u:
		func_04EBD6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EC5Eu:
		func_04EC5E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EC9Au:
		func_04EC9A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04ECD6u:
		func_04ECD6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04F076u:
		func_04F076(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04F0E4u:
		func_04F0E4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FA96u:
		func_04FA96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FC04u:
		func_04FC04(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FCD4u:
		func_04FCD4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FD4Cu:
		func_04FD4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FD88u:
		func_04FD88(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0508A0u:
		func_0508A0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050ADCu:
		func_050ADC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050B8Cu:
		func_050B8C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050C68u:
		func_050C68(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x052306u:
		func_052306(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x052422u:
		func_052422(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0534C4u:
		func_0534C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x053524u:
		func_053524(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x05356Eu:
		func_05356E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0535B8u:
		func_0535B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x053602u:
		func_053602(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_04F622(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint8_t d1 = 0;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0;

	unk_061237--;
	d7_2 = (d7 & ~0xFFu) | 0x82u;
	func_0091A4((uint8_t)d7_2, 0u);
	unk_061240 = 0u;
	d0 = 0x9Cu;
	if (mem_read16(a0 + 8u) != 0u)
	{
		d0 = 0x98u;
		if (mem_read8(a0 + 9u) != 0u)
		{
			d0 = mem_read8(a0);
			d1 = mem_read8(a0 + 7u);
			d0 = (uint8_t)((uint32_t)d0 << 1);
			if ((int8_t)(d0 ^ d1) >= 0)
				d0 = (uint16_t)((uint32_t)indexed_table_of_8_bit_values_04F6B6[d1 & 0x7Fu] << 2);
			else
				d0 = 0xA0u;
		}
	}
	mem_write16(a0 + 0x28u, d0);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_d7 = d7_2;
	func_04F680(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_04F680(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 3u);
	func_048724((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	func_04F68A(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_04F68A(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x4Cu);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored, &ignored_2, &ignored_3, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	switch ((uint32_t)(int16_t)mem_read16(a0 + 0x28u))
	{
	case 228:
		func_0494C6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04955C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_049DDC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_049E10(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_049E34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_049E58(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049E7C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_049FB8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_04A0F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04A1D4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		*p_a5 = unreached_04A338(a0, *p_a1);
		return;
	case 136:
		func_04A368(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		*p_a5 = unreached_04A3F4(a0, *p_a1);
		return;
	case 188:
		func_04A426(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		*p_a5 = unreached_04A4B2(a0, *p_a1);
		return;
	case 196:
		func_04A4E4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		*p_a5 = unreached_04A570(a0, *p_a1);
		return;
	case 20:
		func_04A5A2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04A6B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_04A704(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04B632(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_04B656(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04B67A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04B69E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B6C2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B6E6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B70A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04E566(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04E58A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04E5AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04E5D2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E5F6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E61A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04E63E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04E662(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04ED5E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04ED82(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04EDA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04EDCA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04EDEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_04FE42(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_04FEAA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_04FEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04FF1A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_050076(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_050CE6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_050D2C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_050D78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_050E66(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_051968(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_0519C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_051A08(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_052600(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_0526A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_0531AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_053242(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_0532D4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_05333C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_053440(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

uint32_t func_04F6E6(uint32_t d7)
{
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	d0 = 0u;
	func_047C02(d0, &d7, &a6, &zero);
	if (zero)
	{
		mem_write16(a6, 0x100u);
		mem_write16(a6 + 2u, 0x1100u);
		mem_write16(a6 + 4u, 0u);
		mem_write16(a6 + 0x42u, 0xFF00u);
		mem_write8(a6 + 0x4Bu, 0u);
		mem_write16(a6 + 0x10u, 0u);
		mem_write32(a6 + 0x12u, 0x16800u);
		mem_write32(a6 + 0x16u, 0x11400u);
	}
	return d7;
}

void func_04F722(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F72E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F736(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	mem_write8(a0 + 0x22u, 1u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x59CFCu;
	set_animation(0u, a0, a6);
}

void func_04F750(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F75C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F764(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	mem_write8(a0 + 0x22u, 0x88u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x59D58u;
	set_animation(0u, a0, a6);
}

void func_04F77E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F78A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F792(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x59CC4u;
	set_animation(0u, a0, a6);
}

void func_04F7AC(uint32_t a0)
{
	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
}

void func_04F7B2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F7BE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F7C6(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05A08A_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_04F7E0(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write8(a0 + 0x22u, 0u);
}

void func_04F7EE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F7FA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F802(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5A0D2u;
	set_animation(0u, a0, a6);
}

void func_04F81C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F828_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F830(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x22u, 0xB4u);
	mem_write8(a0 + 0x40u, 1u);
	mem_write8(a0 + 0x4Au, 0u);
	if ((unk_06120E & 0x80u) != 0u)
		mem_write8(a0 + 0x4Au, 0x40u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_0596BA_ADDRESS;
	set_animation(0u, a0, a6);
	func_04F862(a0, a1, p_d6, p_d7, p_a5);
}

void func_04F862(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x40u, 8u);
		func_04F9A0(a0, a1);
		d0 = (uint8_t)((mem_read8(a0 + 0x2Bu) & 0xC0u) + mem_read8(a0 + 0x4Au));
		d1 = 0x160u;
		func_047CCC(d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
	}
	func_04826A(a0);
}

void func_04F89C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F8A8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F8B0(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 0x40u, 1u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05979C_ADDRESS;
	set_animation(0u, a0, a6);
	func_04F8CC(a0, a1);
}

void func_04F8CC(uint32_t a0, uint32_t a1)
{
	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	func_04F9A0(a0, a1);
	if (mem_read16(a0 + 0x2Cu) < 0x50u)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0x200u);
		if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		func_04826A(a0);
		return;
	}
	if (mem_read16(a0 + 0x2Eu) < 3u)
		return;
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0x200u);
	if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
	{
		func_04826A(a0);
		return;
	}
	mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	func_04826A(a0);
}

void func_04F922(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F92E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F936(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x22u, 0x80u);
	mem_write8(a0 + 0x31u, 1u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_059618_ADDRESS;
	set_animation(0u, a0, a6);
	func_04F952(a0, a1, p_d6, p_d7, p_a5);
}

void func_04F952(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	t1 = mem_read8(a0 + 0x31u);
	mem_write8(a0 + 0x31u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return;
	}
	func_04F9A0(a0, a1);
	d1 = 0x20u;
	if ((mem_read8(a0) & 0x40u) != 0u)
		d1 = (uint16_t)(0u - d1);
	d1 = (uint16_t)(d1 + mem_read16(a1 + 0xCu));
	d2 = mem_read16(a1 + 0xEu);
	direction_to(a0, &d0, &d1, &d2);
	d1_2 = 0x180u;
	func_047CCC((uint8_t)d0, d1_2, p_d6, p_d7, p_a5);
	*p_d6 = (uint16_t)((int16_t)*p_d6 >> 1);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 0x31u, 8u);
	func_04826A(a0);
}

void func_04F9A0(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0;

	a6 = a1;
	func_0482FA(a0, a6, &ignored, &ignored_2);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
}

void func_04F9C0(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04F9CC_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04F9F2(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write32(a0 + 0x1Au, 0x4F9D4u);
	mem_write8(a0 + 0x22u, 7u);
	mem_write16(a0 + 0x40u, 0x101u);
	func_04FA0A(a0, p_d7, p_a5);
}

void func_04FA0A(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a5 = *p_a5;
	uint32_t zero = 0;
	uint32_t a4 = 0, a6 = 0, d7_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint32_t t4 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(a0 + 0x41u);
		mem_write8(a0 + 0x41u, t2 - 1u);
		if (t2 != 1u)
		{
			mem_write8(a0 + 0x40u, 8u);
			d7 = IN_PAGE(d7, 0x18u);
			func_0091A4((uint8_t)d7, a6);
			a5 = mem_read32(a0 + 0x24u);
			func_047C5A(a0, a5, &d7, &a6, &zero);
			if (zero)
				mem_write8(a6 + 3u, mem_read8(a0 + 0x4Au));
		}
		else
		{
			t3 = mem_read8(a0 + 0x22u);
			mem_write8(a0 + 0x22u, t3 - 1u);
			if (t3 != 1u)
			{
				mem_write8(a0 + 0x41u, 3u);
				a4 = mem_read32(a0 + 0x1Au);
				d7_2 = LINKED(d7, mem_read8(a4));
				mem_write32(a0 + 0x1Au, a4 + 1u);
				mem_write8(a0, mem_read8(a0) & 0xBFu);
				t4 = d7_2;
				d7 = t4 & ~0x80u;
				if ((t4 & 0x80u) != 0u)
					mem_write8(a0, mem_read8(a0) | 0x40u);
				mem_write8(a0 + 0x4Au, 0u);
				if ((uint8_t)d7 != 0u)
					mem_write8(a0 + 0x4Au, 1u);
				d7 = LINKED(d7, (uint16_t)(d7 << 3));
				mem_write32(a0 + 0x24u, indexed_table_of_32_bit_values_04F9DE[(uint16_t)d7 / 4u]);
				a6 = animations_04F9DA[(uint16_t)d7 / 4u];
				set_animation(0u, a0, a6);
				mem_write8(a0 + 0x40u, 8u);
				d7 = IN_PAGE(d7, 0x18u);
				func_0091A4((uint8_t)d7, a6);
				a5 = mem_read32(a0 + 0x24u);
				func_047C5A(a0, a5, &d7, &a6, &zero);
				if (zero)
					mem_write8(a6 + 3u, mem_read8(a0 + 0x4Au));
			}
		}
	}
	*p_d7 = d7;
	*p_a5 = a5;
}

void func_04FA96(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FACE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
	if (unk_061240 == 0u && unk_061247 == 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04FAE6(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = animations_0596BA_ADDRESS;
	if (mem_read8(a0 + 0x2Au) != 0u)
		a6 = animations_059618_ADDRESS;
	set_animation(0u, a0, a6);
	func_0508FC(a0);
}

void func_04FB06(uint32_t a0)
{
	uint8_t d0 = 0;

	func_04826A(a0);
	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		mem_write8(a0, mem_read8(a0) ^ 0x40u);
		unk_061242 |= mem_read8(a0 + 0x45u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_04FB3C(uint32_t a0)
{
	uint32_t a6 = 0;

	if (unk_061242 < 0xC0u)
		return;
	a6 = animations_05983E_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x103u);
	mem_write8(a0 + 6u, 7u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~0xAu);
	mem_write8(a0 + 0x22u, 0x1Eu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04FB82(uint32_t a0)
{
	func_04FC4A(a0);
}

void func_04FB86(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d1 = 0;

	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		unk_061240 = 0u;
		return;
	}
	d1 = 0u;
	if (mem_read16(a0 + 0x2Eu) >= 3u)
	{
		d1 = 0x200u;
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			d1 = (uint16_t)(0u - d1);
	}
	mem_write16(a0 + 0x1Cu, d1);
	func_04826A(a0);
	if (unk_061247 != 0u)
	{
		a6 = animations_05AD06_ADDRESS;
		set_animation(d1, a0, a6);
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_04FBEE(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 0x28u, 0x98u);
		mem_write16(a0 + 4u, 0x500u);
	}
}

void func_04FC04(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FC10_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04FC1C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = animations_05983E_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x103u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) & ~0xAu);
	mem_write8(a0 + 0x22u, 0x1Eu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04FC4A(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0xFC80u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_04FC76(uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;

	d0 = mem_read8(a0 + 1u);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		if ((d0 & 8u) != 0u)
		{
			mem_write8(a0, mem_read8(a0) & ~4u);
			mem_write8(a0, mem_read8(a0) | 2u);
			mem_write16(a0 + 4u, 0x200u);
			mem_write8(a0 + 0x22u, 0u);
			return;
		}
		d1 = 0u;
		if (mem_read16(a0 + 0x2Eu) >= 3u)
		{
			d1 = 0x200u;
			if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
				d1 = (uint16_t)(0u - d1);
		}
		mem_write16(a0 + 0x1Cu, d1);
		func_04826A(a0);
		return;
	}
	if ((d0 & 0x10u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
		return;
	}
	d1 = 0u;
	if (mem_read16(a0 + 0x2Eu) >= 3u)
	{
		d1 = 0x200u;
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			d1 = (uint16_t)(0u - d1);
	}
	mem_write16(a0 + 0x1Cu, d1);
	func_04826A(a0);
}

void func_04FCD4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FCE0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04FCE8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	a6 = animations_059FAA_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x203u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	t1 = mem_read8(a0);
	mem_write8(a0, t1 | 2u);
	if ((t1 & 2u) == 0u && unk_061207 >= 2u)
		mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_04FD2C(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_04FD4C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FD58_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04FD60(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x59FD2u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x203u);
	d7 &= ~0xFFu;
	d7 = func_0485D6(d7, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

void func_04FD88(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FD94_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04FDB8(uint32_t a0, uint32_t a1)
{
	uint32_t a5 = 0, a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a0 + 0x40u, 0x104u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x4Au, 0u);
	a5 = animations_04FDA8_ADDRESS;
	if (mem_read8(a1 + 0x10u) >= 0x40u)
	{
		mem_write8(a0 + 0x4Au, 1u);
		a5 += 8u;
	}
	a6 = DATA32(a5);
	a5 += 4u;
	mem_write32(a0 + 0x24u, DATA32(a5));
	set_animation(0u, a0, a6);
	return a5;
}

void func_04FE02(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		d7_2 = 0x18u;
		func_0091A4(d7_2, 0u);
		*p_a5 = mem_read32(a0 + 0x24u);
		func_047C5A(a0, *p_a5, &d7, &a6, &zero);
		if (zero)
			mem_write8(a6 + 3u, mem_read8(a0 + 0x4Au));
		mem_write8(a0 + 0x40u, 8u);
		t2 = mem_read8(a0 + 0x41u);
		mem_write8(a0 + 0x41u, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write16(a0 + 4u, 0x200u);
			mem_write8(a0 + 0x22u, 0u);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_04FE42(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FE4E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04FE5E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = DATA32(animations_04FE56_ADDRESS + (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 2));
	set_animation(0u, a0, a6);
}

void func_04FE7A(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
		if (unk_061237 == 0u)
		{
			mem_write8(a0, mem_read8(a0) & ~2u);
			mem_write8(a0 + 0x48u, 1u);
		}
	}
}

void func_04FEAA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FEB6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04FEC6(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = DATA32(animations_04FEBE_ADDRESS + (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 2));
	set_animation(0u, a0, a6);
}

void func_04FEE2(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FEEE_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_04FEFE(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = DATA32(animations_04FEF6_ADDRESS + (uint16_t)((uint32_t)mem_read8(a0 + 0x2Au) << 2));
	set_animation(0u, a0, a6);
}

void func_04FF1A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_04FF26_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_04FF5E(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	a6 = record_04FF52_ADDRESS;
	d7 = func_04863E(d7, a0, a6);
	a6 = animations_04FF3A_ADDRESS;
	if (mem_read8(a0 + 0x2Au) != 0u)
		a6 += 0xCu;
	mem_write32(a0 + 0x24u, a6);
	a6 = DATA32(a6);
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_04FF98(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048262(a0);
	a6 = record_04FF52_ADDRESS;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = mem_read32(mem_read32(a0 + 0x24u) + 4u);
	set_animation(0u, a0, a6);
	return d7;
}

void func_04FFCE(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = record_04FF52_ADDRESS;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x4Au, 0x1Eu);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

uint32_t func_04FFFC(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x4Au);
	mem_write8(a0 + 0x4Au, t1 - 1u);
	if (t1 != 1u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = table_loaded_by_lea_054746_ADDRESS;
	if (unk_060120 != 2u)
		a6 = 0x54766u;
	d7 = func_0485C2(d7, a0, a6);
	a6 = mem_read32(mem_read32(a0 + 0x24u) + 8u);
	set_animation(0u, a0, a6);
	return d7;
}

void func_050036(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		unk_061237 = rom_04F5B4[unk_060130 & 7u];
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
		if (mem_read8(a0 + 0x2Au) == 0u)
			mem_write16(a0 + 0x46u, 1u);
	}
}

void func_050076(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050082_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0500AE(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	unk_061243 = 0xFFu;
	func_04F9A0(a0, a1);
	a6 = record_0500A2_ADDRESS;
	d7 = func_04863E(d7, a0, a6);
	a6 = animations_050092_ADDRESS;
	if (mem_read8(a0 + 0x2Au) != 0u)
		a6 += 8u;
	mem_write32(a0 + 0x24u, a6);
	a6 = DATA32(a6);
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_0500F0(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	func_048262(a0);
	a6 = record_0500A2_ADDRESS;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	t1 = unk_061236;
	unk_061236 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_06131D = 1u;
		d7 &= ~0xFFFFu;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, a6);
	}
	d7_2 = (d7 & ~0xFFu) | 0x8Bu;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = mem_read32(mem_read32(a0 + 0x24u) + 4u);
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_050152(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = record_0500A2_ADDRESS;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x4Au, 0x78u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_050180(uint32_t a0)
{
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(a0 + 0x4Au) & 0x10u) == 0u)
		mem_write8(a0, mem_read8(a0) ^ 0x80u);
	t1 = mem_read8(a0 + 0x4Au);
	mem_write8(a0 + 0x4Au, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0, 0u);
		t2 = unk_06120C - 1u;
		unk_06120C = t2;
		if ((int8_t)t2 < 0)
			unk_06120C = 0u;
	}
}

void func_0501C6(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0 + 0x4Au, 3u);
	mem_write32(a0 + 0x3Au, sprite_lists_059A18_ADDRESS);
	unk_06120C++;
	unk_061236++;
	if (mem_read8(a0 + 3u) != 0u)
	{
		mem_write8(a0 + 0x32u, 0u);
		unk_061224 = 0x168u;
		unk_061243 = 0u;
		unk_061240 = 0u;
		mem_write8(a0 + 3u, 0xEu);
		mem_write16(a0 + 4u, 0x106u);
		mem_write8(a0, mem_read8(a0) | 0x80u);
		a6_2 = 0x5A5AEu;
		set_animation(0u, a0, a6_2);
		return;
	}
	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6_2 = 0x5A5E6u;
	set_animation(0u, a0, a6_2);
	mem_write8(a0 + 0x33u, 0u);
	mem_write8(a0 + 0x32u, 0x28u);
	unk_061243 = 0xFFu;
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 3u, 0xCu);
	a6_2 = 0xD094u;
	*p_d7 = (*p_d7 & ~0xFFFFu) | 0x43Cu;
	*p_a5 = post_palette_request((uint16_t)*p_d7, a6_2);
}

void func_05027A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050286_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0502A6(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (unk_063380 < 0x8C000u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x46u, 0x5Au);
	d7_2 = (d7 & ~0xFFFFu) | 0xFEu;
	unk_060080 = d7_2;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x54756u;
	return func_0485AE(d7_2, a0, a6);
}

void func_0502DC(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write16(a0 + 0x1Eu, 0u);
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0u);
	}
}

uint32_t func_0502F2(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x60u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	d7_2 = (d7 & ~0xFFu) | 0x3Eu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5A61Eu;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_050320(uint32_t d7, uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	mem_write16(a0 + 0x1Eu, 0x600u);
	mem_write16(a0 + 0x1Au, 0x100u);
	mem_write16(a0 + 0x1Cu, 0xFF00u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return func_050340(d7, a0);
}

uint32_t func_050340(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x60u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	d7_2 = (d7 & ~0xFFu) | 0x3Fu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5A648u;
	set_animation(0u, a0, a6);
	return func_05036E(d7_2, a0);
}

uint32_t func_05036E(uint32_t d7, uint32_t a0)
{
	uint32_t d7_2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	mem_write16(a0 + 4u, 0x200u);
	mem_write8(a0, mem_read8(a0) | 2u);
	d7_2 = (d7 & ~0xFFFFu) | 0x64u;
	unk_060080 = d7_2;
	func_0091A4((uint8_t)d7_2, 0u);
	return d7_2;
}

void func_050392(uint32_t a0)
{
	uint32_t a6 = 0;

	if (unk_06123D == 0u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x40u, 0x20u);
	a6 = animations_05A430_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_0503B2(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t a6 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		a6 = 0x54776u;
		func_0485AE(d7, a0, a6);
		a6 = 0xD094u;
		d7 = 0x43Eu;
		*p_a5 = post_palette_request((uint16_t)d7, a6);
	}
	t2 = mem_read32(a0 + 0x16u) - 0x100u;
	mem_write16(a0 + 0x18u, t2);
	mem_write16(a0 + 0x16u, t2 >> 16);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_0503EC(uint32_t d0, uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint16_t d0_2 = 0, d1 = 0, d2 = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	*p_d7 = (*p_d7 & ~0xFFu) | mem_read8(a0 + 3u);
	func_048724((uint8_t)*p_d7, a0);
	if (unk_060120 == 2u)
	{
		if (unk_061112 == 0u && unk_061104 >= 0x80u)
		{
			d0 = (d0 & ~0xFFu) | 0xFFu;
			if ((mem_read8(a0) & 0x40u) != 0u)
				d0 &= ~0xFFu;
			d1 = mem_read16(a0 + 0xCu);
			d2 = mem_read16(a0 + 0xEu);
			func_02FFFE(d1, d2, &d0, p_d5, p_d6, p_d7, &a6);
		}
		if (unk_061112 == 2u && unk_061104 >= 0x60u)
		{
			d0_2 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
			if ((mem_read8(a0) & 0x40u) != 0u)
				d0_2 &= ~0xFFu;
			d1 = mem_read16(a0 + 0xCu);
			d2 = mem_read16(a0 + 0xEu);
			func_0300F0(d0_2, d1, d2, p_d5, p_d6, p_d7, &a6);
		}
	}
	t1 = mem_read8(a0 + 0x23u);
	mem_write8(a0 + 0x23u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x23u, 0x10u);
		if (unk_061207 != 0u)
		{
			func_04835E(a0, p_d5, p_d6, p_d7, p_a5, &a6);
			mem_write16(a0 + 0x20u, a6);
		}
	}
	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6_2 = *p_a1;
	func_0482FA(a0, a6_2, &ignored, &ignored_2);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	if (unk_061243 == 0u)
	{
		t2 = unk_061224;
		unk_061224 = t2 - 1u;
		if (t2 == 1u)
		{
			unk_061224 = 0x1Eu;
			unk_061240 = 1u;
			unk_06123E = *p_a1;
			unk_061241 = 0u;
			unk_061242 = 0u;
			unk_061247 = 0u;
			mem_write16(a0 + 0x28u, 0x84u);
			mem_write16(a0 + 4u, 0x300u);
			return;
		}
	}
	if (mem_read8(*p_a1 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(*p_a1 + 0x23u)] != 0u)
	{
		func_048592(a0, p_d7, &zero);
		if (zero)
		{
			if (mem_read16(a0 + 0x2Cu) >= 0x28u)
			{
				a6_2 = table_loaded_by_lea_0505E2_ADDRESS + (uint16_t)((mem_read8(a0 + 0x2Au) & 3u) << 3);
				*p_d7 = 0x64u;
				func_048448(a0, p_d6, p_d7);
				if (*p_d7 < DATA16(a6_2 + 6u) && mem_read16(a0 + 0x2Eu) <= DATA16(a6_2) && mem_read16(a0 + 0x2Cu) <= DATA16(a6_2 + 2u))
				{
					mem_write16(a0 + 0x28u, DATA16(a6_2 + 4u));
					mem_write16(a0 + 4u, 0x300u);
					mem_write8(a0, mem_read8(a0) & ~8u);
					return;
				}
			}
			else if (mem_read16(a0 + 0x2Eu) < 5u)
			{
				mem_write16(a0 + 0x28u, 0x7Cu);
				mem_write16(a0 + 4u, 0x300u);
				mem_write8(a0, mem_read8(a0) & ~8u);
				return;
			}
		}
	}
	if (mem_read8(a0 + 0x22u) == 0u)
	{
		a6_2 = 0x50602u;
		*p_d7 = 0x64u;
		func_048448(a0, p_d6, p_d7);
		*p_d6 &= ~0xFFFFu;
		for (;;)
		{
			t3 = DATA16(a6_2);
			t4 = *p_d7;
			*p_d7 = (uint16_t)(t4 - t3);
			if (t4 < t3)
				break;
			*p_d6 = (*p_d6 & ~0xFFu) | (uint8_t)(*p_d6 + 1u);
			a6_2 += 4u;
			if ((uint8_t)*p_d6 >= 4u)
			{
				a6_2 = 0x50602u;
				*p_d6 &= ~0xFFFFu;
				break;
			}
		}
		mem_write8(a0 + 0x2Au, *p_d6);
		mem_write16(a0 + 0x28u, DATA16(a6_2 + 2u));
		mem_write8(a0 + 5u, 0u);
	}
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_050612(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 3u);
	func_048724((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	func_04F5EE(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_050622(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint16_t d0 = 0;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x82u;
	func_0091A4((uint8_t)d7_2, 0u);
	unk_061240 = 0u;
	d0 = 0xB8u;
	if (mem_read16(a0 + 8u) != 0u)
	{
		d0 = 0xB4u;
		if (mem_read8(a0 + 9u) != 0u)
		{
			if ((int8_t)(((uint32_t)mem_read8(a0) << 1) ^ mem_read8(a0 + 7u)) >= 0)
				d0 = 0xACu;
			else
				d0 = 0xB0u;
		}
	}
	mem_write16(a0 + 0x28u, d0);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	*p_d7 = d7_2;
	func_05066E(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_05066E(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | mem_read8(a0 + 3u);
	func_048724((uint8_t)d7_2, a0);
	*p_d7 = d7_2;
	func_04F68A(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_05067E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05068A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0506A2(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;

	func_04F9A0(a0, a1);
	mem_write8(a0 + 0x22u, 0x78u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7 = 4u;
	func_048448(a0, &d6, &d7);
	d7 = d7 & 3u;
	d7 = (uint16_t)(d7 << 2);
	a6 = animations_050692[d7 / 4u];
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_0506D2(uint32_t a0)
{
	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
}

void func_0506D8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0506E4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0506EC(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 0x46u, 1u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05A430_ADDRESS;
	set_animation(0u, a0, a6);
	func_050708(a0, a1, p_d6, p_d7, p_a5);
}

void func_050708(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t a5 = 0, d0 = 0, d1 = 0, d2 = 0, d6 = 0, d7 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return;
	}
	func_04F9A0(a0, a1);
	d1 = 0x50u;
	if ((mem_read8(a0) & 0x40u) != 0u)
		d1 = (uint16_t)(0u - d1);
	d1 = (uint16_t)(d1 + mem_read16(a1 + 0xCu));
	d2 = mem_read16(a1 + 0xEu);
	direction_to(a0, &d0, &d1, &d2);
	d1_2 = 0x200u;
	func_047CCC((uint8_t)d0, d1_2, &d6, &d7, &a5);
	d6 = (uint16_t)((int16_t)d6 >> 1);
	if (mem_read16(a0 + 0x2Cu) <= 0x50u)
		d6 = (uint16_t)((int16_t)d6 >> 1);
	if (mem_read16(a0 + 0x2Eu) <= 2u)
		d7 = (uint16_t)((int16_t)d7 >> 1);
	mem_write16(a0 + 0x1Au, d6);
	mem_write16(a0 + 0x1Cu, d7);
	mem_write8(a0 + 0x46u, 4u);
	func_04826A(a0);
	*p_d6 = d6;
	*p_d7 = d7;
	*p_a5 = a5;
}

void func_050770(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05077C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_050784(uint32_t a0, uint32_t a1)
{
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return;
	}
	func_04F9A0(a0, a1);
	if (mem_read16(a0 + 0x2Eu) > 4u)
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, 0x100u);
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
		mem_write8(a0 + 0x46u, 4u);
		func_04826A(a0);
		return;
	}
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0x80u);
	if (mem_read16(a0 + 0x2Cu) >= 0x50u)
		mem_write16(a0 + 0x1Au, 0x100u);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		mem_write8(a0 + 0x46u, 4u);
		func_04826A(a0);
		return;
	}
	mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 0x46u, 4u);
	func_04826A(a0);
}

void func_0507EE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0507FA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_050802(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 0x46u, 1u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05A430_ADDRESS;
	set_animation(0u, a0, a6);
	func_05081E(a0, a1, p_d6, p_d7, p_a5);
}

void func_05081E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return;
	}
	func_04F9A0(a0, a1);
	if (mem_read16(a0 + 0x2Eu) > 4u)
	{
		d1 = 0x30u;
		if ((mem_read8(a0) & 0x40u) != 0u)
			d1 = (uint16_t)(0u - d1);
		d1 = (uint16_t)(d1 + mem_read16(a1 + 0xCu));
		d2 = mem_read16(a1 + 0xEu);
		direction_to(a0, &d0, &d1, &d2);
		d1_2 = 0x180u;
		func_047CCC((uint8_t)d0, d1_2, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
	}
	else
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0u);
		if (mem_read16(a0 + 0x1Au) >= 0x10u)
		{
			mem_write16(a0 + 0x1Au, 0x100u);
			if ((mem_read8(a0) & 0x40u) == 0u)
				mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		}
	}
	mem_write8(a0 + 0x46u, 4u);
	func_04826A(a0);
}

void func_0508A0(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0508D8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
	if (unk_061240 == 0u && unk_061247 == 0u)
	{
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_0508F0(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = animations_05A430_ADDRESS;
	set_animation(0u, a0, a6);
	func_0508FC(a0);
}

void func_0508FC(uint32_t a0)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(a0 + 0x45u, 0u);
	if (mem_read16(a0 + 0xCu) < 0x100u)
	{
		t1 = unk_061241;
		unk_061241 = t1 | 0x40u;
		if ((t1 & 0x40u) == 0u)
		{
			mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x40u);
			mem_write8(a0, mem_read8(a0) & 0xBFu);
			mem_write16(a0 + 0x1Au, 0xFE00u);
			mem_write16(a0 + 0x1Cu, 0u);
			mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
			return;
		}
	}
	do
	{
		t2 = unk_061241;
		unk_061241 = t2 | 0x80u;
		if ((t2 & 0x80u) == 0u)
		{
			mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x80u);
			mem_write8(a0, mem_read8(a0) | 0x40u);
			mem_write16(a0 + 0x1Au, 0x200u);
			mem_write16(a0 + 0x1Cu, 0u);
			mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
			return;
		}
		t1 = unk_061241;
		unk_061241 = t1 | 0x40u;
	} while ((t1 & 0x40u) != 0u);
	mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x40u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write16(a0 + 0x1Au, 0xFE00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_050952(uint32_t a0)
{
	uint8_t d0 = 0;

	func_04826A(a0);
	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		mem_write8(a0, mem_read8(a0) ^ 0x40u);
		unk_061242 |= mem_read8(a0 + 0x45u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_050988(uint32_t a0)
{
	uint32_t a6 = 0;

	if (unk_061242 < 0xC0u)
		return;
	a6 = animations_05A930_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x103u);
	mem_write8(a0 + 6u, 7u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write8(a0 + 6u, mem_read8(a0 + 6u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~0xAu);
	mem_write8(a0 + 0x22u, 0x1Eu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_0509CE(uint32_t a0)
{
	func_050BD2(a0);
}

uint32_t func_0509D2(uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, d1_2 = 0, d7_2 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0;
	uint32_t t2 = 0;

	d0 = 8u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = 0x10u;
	if ((d0 & mem_read8(a0 + 1u)) != 0u)
	{
		unk_061240 = 0u;
		unk_061224 = 0x168u;
		return d7;
	}
	d1 = 0u;
	if (mem_read16(a0 + 0x2Eu) >= 3u)
	{
		d1 = 0x200u;
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			d1 = (uint16_t)(0u - d1);
	}
	mem_write16(a0 + 0x1Cu, d1);
	func_04826A(a0);
	a6 = unk_061220;
	func_0482FA(a0, a6, &ignored, &ignored_2);
	mem_write8(a0 + 0x2Bu, mem_read8(a0 + 0x2Bu) - 0x40u);
	t1 = mem_read8(a0 + 0x2Bu) ^ ((uint32_t)mem_read8(a0) << 1);
	mem_write8(a0 + 0x2Bu, t1);
	if ((int8_t)t1 < 0 || mem_read16(a0 + 0x2Cu) >= 0x38u || mem_read16(a0 + 0x2Eu) >= 5u)
		return d7;
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	unk_061247 = 1u;
	mem_write32(a6 + 0x16u, mem_read32(a0 + 0x16u));
	t2 = mem_read32(a6 + 0x16u) + 0x200u;
	mem_write16(a6 + 0x18u, t2);
	mem_write16(a6 + 0x16u, t2 >> 16);
	d1_2 = 0x4000u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d1_2 = (uint16_t)(0u - d1_2);
	mem_write32(a6 + 0x12u, (int16_t)d1_2 + mem_read32(a0 + 0x12u));
	mem_write16(a6 + 0x4Cu, a0);
	mem_write16(a0 + 0x4Cu, a6);
	a6 = 0x5AD12u;
	set_animation(d1_2, a0, a6);
	d7_2 = (d7 & ~0xFFu) | 0x3Eu;
	func_0091A4((uint8_t)d7_2, a6);
	d7 = (d7_2 & ~0xFFu) | 0x8Fu;
	func_0091A4((uint8_t)d7, a6);
	return d7;
}

void func_050AB8(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		unk_061240 = 0u;
		unk_061224 = 0x708u;
		mem_write16(a0 + 0x28u, 0xB4u);
		mem_write16(a0 + 4u, 0x500u);
	}
}

void func_050ADC(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050AE8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_050AF0(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x43u, mem_read8(a0 + 0x4Au));
	mem_write16(a0 + 0xAu, 0x203u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	t1 = mem_read8(a0);
	mem_write8(a0, t1 | 2u);
	if ((t1 & 2u) == 0u && unk_061207 >= 2u)
		mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05A9BE_ADDRESS;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_050B38(uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t t1 = 0;

	if (mem_read8(a0 + 0x43u) != 1u || mem_read16(a0 + 0x2Cu) < 0x28u)
	{
		if (mem_read8(a0 + 0x33u) == 0u)
		{
			mem_write8(a0 + 0x43u, 0u);
			mem_write8(a0 + 0x4Au, 3u);
			mem_write8(a0, mem_read8(a0) & ~4u);
			mem_write8(a0, mem_read8(a0) | 2u);
			mem_write16(a0 + 4u, 0x200u);
			mem_write8(a0 + 0x22u, 0u);
		}
		return;
	}
	d0 = 0x80u;
	if ((mem_read8(a0) & 0x40u) == 0u)
		d0 = (uint16_t)(0u - d0);
	t1 = mem_read32(a0 + 0x12u) + (int16_t)d0;
	mem_write16(a0 + 0x14u, t1);
	mem_write16(a0 + 0x12u, t1 >> 16);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x43u, 0u);
		mem_write8(a0 + 0x4Au, 3u);
		mem_write8(a0, mem_read8(a0) & ~4u);
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_050B8C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050B98_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_050BA4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = animations_05A930_ADDRESS;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x103u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) & ~0xAu);
	mem_write8(a0 + 0x22u, 0x1Eu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_050BD2(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0xFC80u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_050BFE(uint32_t a0)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;

	d0 = mem_read8(a0 + 1u);
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		if ((d0 & 8u) == 0u)
		{
			d1 = 0u;
			if (mem_read16(a0 + 0x2Eu) >= 3u)
			{
				d1 = 0x200u;
				if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
					d1 = (uint16_t)(0u - d1);
			}
			mem_write16(a0 + 0x1Cu, d1);
			func_04826A(a0);
			return;
		}
	}
	else if ((d0 & 0x10u) == 0u)
	{
		d1 = 0u;
		if (mem_read16(a0 + 0x2Eu) >= 3u)
		{
			d1 = 0x200u;
			if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
				d1 = (uint16_t)(0u - d1);
		}
		mem_write16(a0 + 0x1Cu, d1);
		func_04826A(a0);
		return;
	}
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write16(a0 + 4u, 0x200u);
	mem_write16(a0 + 0x28u, 0xD8u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x22u, 1u);
}

void func_050C68(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050C74_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_050C82(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write16(a0 + 0x40u, 0x1403u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05A77E_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_050CAE(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint8_t d7_2 = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x40u);
	mem_write8(a0 + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		d7_2 = 2u;
		func_0091A4(d7_2, 0u);
		*p_a5 = 0x50C7Cu;
		func_047C5A(a0, *p_a5, &d7, &ignored, &zero);
		mem_write8(a0 + 0x40u, 0xCu);
		t2 = mem_read8(a0 + 0x41u);
		mem_write8(a0 + 0x41u, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write16(a0 + 4u, 0x200u);
			mem_write8(a0 + 0x22u, 0u);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_050CE6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050CF2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_050CFA(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5AB38u;
	set_animation(0u, a0, a6);
}

void func_050D0A(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 4u, 0x300u);
		mem_write16(a0 + 0x28u, 0x7Cu);
		mem_write8(a0 + 0x2Au, 1u);
		mem_write8(a0 + 0x4Au, 1u);
	}
}

void func_050D2C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050D38_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_050D40(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0x30u);
	a6 = animations_05AAF6_ADDRESS;
	set_animation(0u, a0, a6);
}

void func_050D56(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0 + 4u, 0x300u);
		mem_write16(a0 + 0x28u, 0x7Cu);
		mem_write8(a0 + 0x2Au, 1u);
		mem_write8(a0 + 0x4Au, 1u);
	}
}

void func_050D78(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050D84_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_050DA4(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_04F9A0(a0, a1);
	a6 = 0x50D98u;
	d7 = func_04863E(d7, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5AB58u;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_050DCC(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048262(a0);
	a6 = 0x50D98u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5AB6Eu;
	set_animation(0u, a0, a6);
	return d7;
}

void func_050E00(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x50D98u;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x46u, 0x14u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

uint32_t func_050E2E(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x54756u;
	if (unk_060120 != 3u)
		a6 = 0x54776u;
	d7 = func_0485C2(d7, a0, a6);
	a6 = 0x5AB7Au;
	set_animation(0u, a0, a6);
	return d7;
}

void func_050E66(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_050E72_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_050E8E(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	unk_061243 = 0xFFu;
	func_04F9A0(a0, a1);
	a6 = 0x50E82u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x5AB9Au;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_050EC0(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	func_048262(a0);
	a6 = 0x50E82u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	t1 = unk_061236;
	unk_061236 = t1 - 1u;
	if (t1 == 1u)
	{
		unk_06131D = 1u;
		d7 &= ~0xFFFFu;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, a6);
	}
	d7_2 = (d7 & ~0xFFu) | 0x8Bu;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5ABBAu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_050F20(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x50E82u;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x46u, 0x78u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_050F4E(uint32_t a0)
{
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(a0 + 0x46u) & 0x10u) == 0u)
		mem_write8(a0, mem_read8(a0) ^ 0x80u);
	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0, 0u);
		t2 = unk_06120C - 1u;
		unk_06120C = t2;
		if ((int8_t)t2 < 0)
			unk_06120C = 0u;
	}
}

void func_050F98(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;
	uint8_t t1 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write16(a0 + 0x34u, 4u);
	unk_06120C++;
	mem_write16(a0 + 8u, 0x101u);
	mem_write32(a0 + 0x3Au, sprite_lists_0582B4_ADDRESS);
	t1 = mem_read8(a0 + 3u);
	mem_write8(a0 + 3u, t1 & 0x7Fu);
	if ((t1 & 0x80u) != 0u)
	{
		mem_write8(a0, mem_read8(a0) | 0x82u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		a6_2 = 0x5811Au;
		set_animation(0u, a0, a6_2);
	}
	else if (mem_read8(a0 + 3u) == 0u)
	{
		func_048746(a0);
		mem_write8(a0, mem_read8(a0) | 0x82u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		a6_2 = 0x5811Au;
		set_animation(0u, a0, a6_2);
	}
	else
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_051002(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05100E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_05103A(uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 3u);
	d0 = (uint8_t)(d0 - 1u);
	mem_write8(a0 + 3u, (uint8_t)d0);
	mem_write8(a0 + 0x32u, DATA8(rom_051036_ADDRESS + d0));
	a6 = DATA32(animations_05101E_ADDRESS + (uint16_t)((uint32_t)d0 << 2));
	set_animation(0u, a0, a6);
}

void func_05106E(uint32_t a0)
{
	uint16_t d0 = 0;
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) | 2u);
	d0 = (uint16_t)((uint32_t)mem_read8(a0 + 3u) << 2);
	mem_write16(a0 + 0x1Cu, indexed_table_of_16_bit_values_05102A[d0 / 2u]);
	mem_write16(a0 + 0x1Eu, rom_05102C[d0 / 2u]);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x10u, mem_read16(a0 + 0x10u) + 0x1000u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x581BAu;
	set_animation(0u, a0, a6);
}

uint32_t func_0510B2(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0x39u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x581C4u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_0510E4(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write16(a0 + 4u, 0x200u);
}

void func_0510F4(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_051210 = false;
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint32_t a6_2 = 0, d0_2 = 0, d1 = 0, d2 = 0, d3 = 0, ignored = 0, ignored_2 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t t2 = 0, t3 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	t1 = mem_read8(a0 + 0x23u);
	mem_write8(a0 + 0x23u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x23u, 0x10u);
		if (unk_061207 != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
			d0 = unk_06120D;
			if (d0 <= mem_read8(a6 + 4u))
			{
				t2 = *p_a5;
				*p_a5 = a6;
				a6 = t2;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = unk_061208;
					if (d0 <= mem_read8(a6 + 4u))
					{
						t3 = *p_a5;
						*p_a5 = a6;
						a6 = t3;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != mem_read16(a0 + 0x20u))
				func_0512EA(a0, *p_a1);
			mem_write16(a0 + 0x20u, a6);
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	if (unk_061313 != 0u)
	{
		mem_write16(a0 + 0x28u, 0xE0u);
		mem_write16(a0 + 4u, 0x500u);
		return;
	}
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		func_0512EA(a0, *p_a1);
		mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
		mem_write16(a0, 0u);
		t4 = unk_06120C - 1u;
		unk_06120C = t4;
		if ((int8_t)t4 >= 0)
		{
			return;
		}
		unk_06120C = 0u;
		return;
	}
	a6_2 = mem_read32(*p_a1);
	func_0482FA(a0, a6_2, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &d0_2, &d1, &d2, &d3, p_d5, p_d6, p_d7, p_a5);
	func_04883A((uint8_t)d0_2, (uint8_t)d1, (uint8_t)d2, (uint8_t)d3, a0, *p_a1, p_d7, &zero);
	if (zero == 0u)
	{
		return;
	}
	if (mem_read8(a0 + 0x2Au) != 0u)
	{
		if (mem_read8(a0 + 0x2Au) == 1u && (mem_read16(a0 + 0x2Cu) >= 0x54u || mem_read16(a0 + 0x2Eu) >= 0x34u))
			func_0512F4(a0, *p_a1);
		if (mem_read8(a0 + 0x2Au) != 2u)
		{
			a6_2 = mem_read32(*p_a1);
			if (mem_read8(a6_2 + 4u) == 4u && indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] == 0u)
			{
				func_0512EA(a0, *p_a1);
				mem_write8(a0 + 0x2Au, 2u);
				mem_write8(a0 + 0x22u, 0u);
			}
		}
	}
	else if (mem_read8(*p_a1 + 7u) >= 0xC0u || mem_read16(a0 + 0x2Cu) >= 0x40u || mem_read16(a0 + 0x2Eu) >= 0x20u)
	{
		if (mem_read8(a0 + 0x2Au) != 2u)
		{
			a6_2 = mem_read32(*p_a1);
			if (mem_read8(a6_2 + 4u) == 4u && indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] == 0u)
			{
				func_0512EA(a0, *p_a1);
				mem_write8(a0 + 0x2Au, 2u);
				mem_write8(a0 + 0x22u, 0u);
			}
		}
	}
	else
	{
		mem_write8(a0 + 0x2Au, 1u);
		mem_write8(a0 + 0x22u, 0u);
		do
		{
			if (L_051210 || (int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
			{
				for (;;)
				{
					L_051210 = false;
					t5 = mem_read8(*p_a1 + 7u);
					mem_write8(*p_a1 + 7u, t5 | 0x40u);
					if ((t5 & 0x40u) != 0u)
					{
						t6 = mem_read8(*p_a1 + 7u);
						mem_write8(*p_a1 + 7u, t6 | 0x80u);
						if ((t6 & 0x80u) != 0u)
							continue;
						mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
						break;
					}
					mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x80u);
					break;
				}
			}
			else
			{
				t6 = mem_read8(*p_a1 + 7u);
				mem_write8(*p_a1 + 7u, t6 | 0x80u);
				L_051210 = (t6 & 0x80u) != 0u;
				if (!L_051210)
					mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
			}
		} while (L_051210);
	}
	func_048592(a0, p_d7, &zero);
	if (zero && mem_read8(mem_read32(*p_a1) + 4u) != 4u && mem_read16(a0 + 0x2Eu) < 4u && mem_read16(a0 + 0x2Cu) < 0x30u)
	{
		mem_write16(a0 + 4u, 0x300u);
		mem_write8(a0, mem_read8(a0) & ~8u);
		return;
	}
	if (mem_read8(a0 + 0x22u) == 0u)
	{
		mem_write16(a0 + 0x28u, TABLE16(indexed_table_of_16_bit_values_0512E4, (uint32_t)(int16_t)((uint32_t)(int8_t)mem_read8(a0 + 0x2Au) << 1)));
		mem_write8(a0 + 5u, 0u);
	}
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_0512EA(uint32_t a0, uint32_t a1)
{
	if (mem_read8(a0 + 0x2Au) != 1u)
		return;
	func_0512F4(a0, a1);
}

void func_0512F4(uint32_t a0, uint32_t a1)
{
	uint8_t d0 = 0;
	uint8_t t1 = 0;

	d0 = 0x7Fu;
	t1 = mem_read8(a0 + 0x45u);
	mem_write8(a0 + 0x45u, t1 & 0x7Fu);
	if ((t1 & 0x80u) != 0u)
		d0 = 0xB7u;
	mem_write8(a1 + 7u, mem_read8(a1 + 7u) & d0);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x22u, 0u);
}

void func_051314(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a1 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = mem_read32(a1);
	func_0482FA(a0, a6, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	a6 = indexed_table_of_32_bit_values_051340_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
	*p_a1 = a1;
}

uint32_t func_05135C(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = 0x58134u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x103u);
	d7_2 = (d7 & ~0xFFu) | 0x10u;
	d7_2 = func_0485D6(d7_2, a0);
	a6 = 0x51350u;
	d7_2 = func_04863E(d7_2, a0, a6);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0, mem_read8(a0) & ~8u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x28u, 0xA0u);
	return d7_2;
}

uint32_t func_0513A2(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04890E(a0);
	func_048262(a0);
	a6 = 0x51350u;
	func_048696(a0, a6);
	if ((mem_read8(a0) & 8u) != 0u)
	{
		mem_write16(a0, mem_read16(a0) & 0x7100u);
		mem_write8(a0 + 5u, 3u);
		func_0512EA(a0, a1);
		return d7;
	}
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0, mem_read8(a0) & ~4u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, 2u);
	a6 = animations_058076_ADDRESS;
	set_animation(0u, a0, a6);
	return d7;
}

void func_051404(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return;
	func_0485F6(a0);
}

void func_051414(uint32_t a0)
{
	uint8_t t1 = 0;

	if ((unk_0600A4 & 3u) == 0u && mem_read8((0x60000u | mem_read16(a0 + 0x4Eu)) + 4u) != 4u)
	{
		mem_write16(a0, 0u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
}

void func_05144E(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t d7 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	d7 = 0xA8u;
	func_0091A4(d7, 0u);
	t1 = mem_read8(a0);
	mem_write8(a0, t1 & ~8u);
	if ((t1 & 8u) != 0u)
	{
		a6 = 0x60000u | mem_read16(a0 + 0x4Eu);
		if (mem_read8(a6 + 4u) == 4u)
			mem_write8(a6 + 0x27u, 0x10u);
	}
	mem_write16(a0 + 0x28u, 0x90u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_048EDA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_051492(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a1 = 0, a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = mem_read32(a1);
	func_0482FA(a0, a6, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	a6 = TABLE32(indexed_table_of_32_bit_values_0514C6, (uint32_t)(int16_t)mem_read16(a0 + 0x28u));
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
	*p_a1 = a1;
}

void func_0514EE(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Eu, DATA16(rom_04881C_ADDRESS + (uint16_t)((unk_060120 & 0xFu) << 1)));
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0x100u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x58134u;
	set_animation(0u, a0, a6);
}

uint32_t func_05152C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_04897C(a0);
	func_048262(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_058076_ADDRESS;
	set_animation(0u, a0, a6);
	return d7;
}

void func_05156C(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
		mem_write16(a0 + 4u, 0x200u);
}

void func_051588(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Eu, DATA16(rom_04881C_ADDRESS + (uint16_t)((unk_060120 & 0xFu) << 1)));
	mem_write16(a0 + 0x1Au, 0x100u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x58134u;
	set_animation(0u, a0, a6);
}

void func_0515D8(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Eu, DATA16(rom_04881C_ADDRESS + (uint16_t)((unk_060120 & 0xFu) << 1)));
	mem_write16(a0 + 0x1Au, 0xFF00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	a6 = 0x58134u;
	set_animation(0u, a0, a6);
}

void func_051628(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0xFF80u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x581BAu;
	set_animation(0u, a0, a6);
}

uint32_t func_051654(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048938(a0);
	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x581C4u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_0516A0(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Au, 0x100u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x58134u;
	set_animation(0u, a0, a6);
}

uint32_t func_0516D2(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048938(a0);
	func_048262(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 0x22u, 0x10u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_058076_ADDRESS;
	set_animation(0u, a0, a6);
	return d7;
}

void func_05171E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write16(a0 + 0x1Au, 0xFF00u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0, mem_read8(a0) & ~2u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	a6 = 0x58134u;
	set_animation(0u, a0, a6);
}

void func_051750(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05175C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_051774(uint8_t d0, uint32_t a0, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = 0;

	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 0x46u, 8u);
	*p_d7 = 0xF0u;
	func_048448(a0, &d6, p_d7);
	mem_write8(a0 + 0x47u, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_a5 = animations_05176C_ADDRESS;
	func_04853E(d0, a0, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0517A0(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (mem_read16(a0 + 0x2Cu) < 0x3Eu && mem_read16(a0 + 0x2Eu) < 0x1Eu)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		return;
	}
	t1 = mem_read8(a0 + 0x47u);
	mem_write8(a0 + 0x47u, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t2 - 1u);
		if (t2 == 1u)
		{
			a6 = mem_read32(a1);
			d0 = func_047D90(0u, a0, a6);
			a5 = animations_05176C_ADDRESS;
			func_048546((uint8_t)d0, a0, p_d7, &a5);
			d1 = 0xC0u;
			func_047CCC((uint8_t)d0, d1, p_d6, p_d7, p_a5);
			mem_write16(a0 + 0x1Au, *p_d6);
			*p_d7 = (uint16_t)((int16_t)*p_d7 >> 1);
			mem_write16(a0 + 0x1Cu, *p_d7);
			mem_write8(a0 + 0x46u, 8u);
		}
		func_04826A(a0);
		return;
	}
	*p_d7 = 0xF0u;
	func_048448(a0, p_d6, p_d7);
	mem_write8(a0 + 0x47u, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_051812(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d6 = 0;

	mem_write8(a0 + 0x46u, 0x78u);
	func_05192C(a0, &d6, p_d7);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_05181C(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 5u, 0u);
}

void func_05182A(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051836_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_05183E(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 0x46u, 8u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_a5 = animations_05176C_ADDRESS;
	func_04853E(d0, a0, p_d7, p_a5);
}

void func_05185C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1_2 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, d1 = 0, d2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return;
	}
	a6 = mem_read32(a1);
	d1 = 0x20u;
	if ((mem_read8(a0 + 0x45u) & 0x80u) != 0u)
		d1 = (uint16_t)(0u - d1);
	d1 = (uint16_t)(d1 + mem_read16(a6 + 0xCu));
	d2 = mem_read16(a6 + 0xEu);
	direction_to(a0, &d0, &d1, &d2);
	a5 = animations_05176C_ADDRESS;
	func_048546((uint8_t)d0, a0, p_d7, &a5);
	d1_2 = 0x80u;
	func_047CCC((uint8_t)d0, d1_2, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	*p_d7 = (uint16_t)((int16_t)*p_d7 >> 1);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 0x46u, 8u);
	func_04826A(a0);
}

void func_0518B0(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0518BC_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0518D4(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0, d0 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0xFFu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x46u, 0x20u);
	a6 = mem_read32(a1);
	d0 = func_047D90(0u, a0, a6);
	d0 = (uint8_t)(d0 - 0x80u);
	d1 = 0x100u;
	func_047CCC((uint8_t)d0, d1, p_d6, p_d7, &ignored);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	*p_a5 = animations_05176C_ADDRESS;
	func_04853E((uint8_t)d0, a0, p_d7, p_a5);
}

void func_05190E(uint8_t d0, uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	*p_a5 = animations_05176C_ADDRESS;
	func_048546(d0, a0, p_d7, p_a5);
	func_04826A(a0);
}

void func_05192C(uint32_t a0, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t a6 = 0, d6 = 0, d7 = 0;

	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7 = 2u;
	func_048448(a0, &d6, &d7);
	d7 = (uint16_t)(d7 << 2);
	a6 = animations_0518CC[d7 / 4u];
	set_animation(0u, a0, a6);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
	*p_d7 = d7;
}

void func_05194C(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_051968(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051974_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_051980(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((mem_read8(a0 + 0x30u) & 0x80u) != 0u)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x51A20u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x58146u;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

void func_0519C0(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0519CC_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0519E4(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = 0x519D8u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x58146u;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

void func_051A08(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051A14_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_051A2C(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	func_0512EA(a0, a1);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x51A20u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x58146u;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_051A6C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;

	func_04890E(a0);
	func_048244(a0);
	a6 = 0x51A20u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	d7_2 = (d7 & ~0xFFu) | 0xFu;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x581D0u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_051AB0(uint32_t a0, uint32_t a1)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0, 0u);
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
}

void func_051B56(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, 0x81u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x46u, DATA8(table_loaded_by_lea_051AEE_ADDRESS + (uint16_t)((mem_read8(a0 + 3u) & 0xFu) << 3) + unk_060130));
	a6 = DATA32(animations_051AE2_ADDRESS + ((mem_read8(a0 + 3u) & 0xF0u) >> 2));
	mem_write32(a0 + 0x24u, a6);
	a6 = mem_read32(a6);
	set_animation(0u, a0, a6);
}

uint32_t func_051BA2(uint32_t d7, uint32_t a0)
{
	uint32_t a4 = 0, a6 = 0;

	if (mem_read16(a0 + 0xCu) < 0x100u)
	{
		unk_06120C += 6u;
		a4 = mem_read32(a0 + 0x24u);
		a6 = mem_read32(a4 + 4u);
		set_animation(0u, a0, a6);
		mem_write32(a0 + 0x24u, a4 + 8u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
		d7 = (d7 & ~0xFFu) | 0x31u;
		func_0091A4((uint8_t)d7, a6);
	}
	return d7;
}

void func_051BDA(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x22u, 0x10u);
		mem_write8(a0, mem_read8(a0) & 1u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	}
}

void func_051BF4(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		*p_a5 = mem_read32(a0 + 0x24u);
		func_047C30(a0, *p_a5, &d7, &ignored, &zero);
		mem_write8(a0 + 0x22u, 0x3Cu);
		t2 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write16(a0, 0u);
			t3 = unk_06120C - 6u;
			unk_06120C = t3;
			if ((int8_t)t3 < 0)
				unk_06120C = 0u;
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_051C44(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6_2 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0 + 0x32u, 0u);
	unk_06120C++;
	mem_write16(a0 + 8u, 0x10Cu);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	if ((int8_t)mem_read8(a0 + 3u) >= 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x82u);
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 2u);
		a6_2 = animations_0585C4_ADDRESS;
		set_animation(0u, a0, a6_2);
		return;
	}
	mem_write8(a0 + 0x33u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	mem_write8(a0 + 0x46u, 0xB4u);
}

void func_051CAC(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_051CB8_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_051CC8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	if (mem_read16(a0 + 0xCu) >= 0x140u)
	{
		t1 = mem_read8(a0 + 0x46u);
		mem_write8(a0 + 0x46u, t1 - 1u);
		if (t1 != 1u)
			return d7;
	}
	d7_2 = (d7 & ~0xFFu) | 0x2Eu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x58960u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_051CFC(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write16(a0 + 0x10u, 0x1800u);
	mem_write32(a0 + 0x1Au, 0x10u);
	mem_write16(a0 + 0x1Eu, 0x400u);
	mem_write8(a0, mem_read8(a0) | 2u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x589A8u;
	set_animation(0u, a0, a6);
}

void func_051D36(uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	func_048244(a0);
	mem_write16(a0 + 0x1Eu, mem_read16(a0 + 0x1Eu) - 0x40u);
	d0 = mem_read8(a0 + 0x10u);
	if (d0 <= mem_read8(a0 + 0x32u) || d0 >= 0xF8u)
	{
		mem_write16(a0 + 0x10u, 0u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
		a6 = 0x589CCu;
		set_animation(0u, a0, a6);
		return;
	}
}

void func_051D72(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
		mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
}

void func_051D80(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_051E78 = false;
	uint32_t zero = 0;
	uint8_t d0 = 0;
	uint16_t d0_2 = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t7 = 0;
	uint32_t t2 = 0, t3 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	t1 = mem_read8(a0 + 0x23u);
	mem_write8(a0 + 0x23u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x23u, 0x10u);
		if (unk_061207 != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
			d0 = unk_06120D;
			if (d0 <= mem_read8(a6 + 4u))
			{
				t2 = *p_a5;
				*p_a5 = a6;
				a6 = t2;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = unk_061208;
					if (d0 <= mem_read8(a6 + 4u))
					{
						t3 = *p_a5;
						*p_a5 = a6;
						a6 = t3;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != mem_read16(a0 + 0x20u))
				func_051FCC(a0, *p_a1);
			mem_write16(a0 + 0x20u, a6);
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	if (unk_06131D != 0u)
	{
		mem_write16(a0, 0u);
		t4 = unk_06120C - 1u;
		unk_06120C = t4;
		if ((int8_t)t4 < 0)
			unk_06120C = 0u;
		return;
	}
	if ((mem_read8(a0) & 0x20u) != 0u)
	{
		func_051FCC(a0, *p_a1);
		mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
		mem_write16(a0, 0u);
		t4 = unk_06120C - 1u;
		unk_06120C = t4;
		if ((int8_t)t4 < 0)
			unk_06120C = 0u;
		return;
	}
	a6_2 = mem_read32(*p_a1);
	func_0482FA(a0, a6_2, &ignored, &ignored_2);
	func_047662(a0, p_d5, p_d6, p_d7, p_a5);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	if (mem_read8(a0 + 0x2Au) != 0u)
	{
		if (mem_read8(a0 + 0x2Au) == 1u && ((int16_t)mem_read16(a0 + 0xCu) < 0x70 || (int16_t)mem_read16(a0 + 0xCu) >= 0x190))
		{
			mem_write8(a0 + 0x2Au, 0u);
			mem_write8(a0 + 0x22u, 0u);
			func_051FD6(a0, *p_a1);
		}
	}
	else if (mem_read8(*p_a1 + 6u) < 0xC0u && mem_read16(a0 + 0x2Cu) < 0x20u)
	{
		mem_write8(a0 + 0x2Au, 1u);
		mem_write8(a0 + 0x22u, 0u);
		do
		{
			if (L_051E78 || (int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
			{
				for (;;)
				{
					L_051E78 = false;
					t5 = mem_read8(*p_a1 + 6u);
					mem_write8(*p_a1 + 6u, t5 | 0x40u);
					if ((t5 & 0x40u) != 0u)
					{
						t6 = mem_read8(*p_a1 + 6u);
						mem_write8(*p_a1 + 6u, t6 | 0x80u);
						if ((t6 & 0x80u) != 0u)
							continue;
						mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
						break;
					}
					mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x80u);
					break;
				}
			}
			else
			{
				t6 = mem_read8(*p_a1 + 6u);
				mem_write8(*p_a1 + 6u, t6 | 0x80u);
				L_051E78 = (t6 & 0x80u) != 0u;
				if (!L_051E78)
					mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
			}
		} while (L_051E78);
	}
	if (mem_read8(a0 + 0x2Au) != 1u)
	{
		func_048592(a0, p_d7, &zero);
		if (zero && mem_read8(a0 + 0x2Au) == 1u && mem_read8(mem_read32(*p_a1) + 4u) != 4u && mem_read16(a0 + 0x2Eu) < 6u)
		{
			*p_d7 = 0x64u;
			func_048448(a0, p_d6, p_d7);
			d0_2 = 1u;
			a6_2 = table_loaded_by_lea_051F94_ADDRESS;
			do
			{
				if (DATA16(a6_2) <= mem_read16(a0 + 0x2Cu) && (uint8_t)*p_d7 < DATA8(a6_2 + 2u))
				{
					*p_d6 = (*p_d6 & ~0xFFFFu) | DATA8(a6_2 + 3u);
					*p_d6 = (*p_d6 & ~0xFFFFu) | (uint16_t)(*p_d6 << 2);
					mem_write16(a0 + 0x28u, *p_d6);
					mem_write16(a0 + 4u, 0x300u);
					mem_write8(a0, mem_read8(a0) & ~8u);
					return;
				}
				t7 = d0_2 - 1u;
				d0_2 = t7;
				a6_2 += 4u;
			} while (t7 != 0xFFFFu);
		}
	}
	else
	{
		a6_2 = mem_read32(*p_a1);
		if (mem_read8(a6_2 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] != 0u)
		{
			func_048592(a0, p_d7, &zero);
			if (zero && mem_read8(a0 + 0x2Au) == 1u && mem_read8(mem_read32(*p_a1) + 4u) != 4u && mem_read16(a0 + 0x2Eu) < 6u)
			{
				*p_d7 = 0x64u;
				func_048448(a0, p_d6, p_d7);
				d0_2 = 1u;
				a6_2 = table_loaded_by_lea_051F94_ADDRESS;
				do
				{
					if (DATA16(a6_2) <= mem_read16(a0 + 0x2Cu) && (uint8_t)*p_d7 < DATA8(a6_2 + 2u))
					{
						*p_d6 = (*p_d6 & ~0xFFFFu) | DATA8(a6_2 + 3u);
						*p_d6 = (*p_d6 & ~0xFFFFu) | (uint16_t)(*p_d6 << 2);
						mem_write16(a0 + 0x28u, *p_d6);
						mem_write16(a0 + 4u, 0x300u);
						mem_write8(a0, mem_read8(a0) & ~8u);
						return;
					}
					t7 = d0_2 - 1u;
					d0_2 = t7;
					a6_2 += 4u;
				} while (t7 != 0xFFFFu);
			}
		}
		else
		{
			func_051FD6(a0, *p_a1);
			mem_write8(a0 + 0x2Au, 2u);
			mem_write8(a0 + 0x22u, 0u);
		}
	}
	if (mem_read8(a0 + 0x22u) == 0u)
	{
		d0_2 = mem_read8(a0 + 0x2Au);
		mem_write16(a0 + 0x28u, (uint32_t)DATA8(rom_051F9C_ADDRESS + d0_2) << 2);
		mem_write8(a0 + 5u, 0u);
	}
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_051FA0(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t d7 = 0;
	uint16_t d0 = 0;

	d7 = 5u;
	func_0091A4(d7, 0u);
	d0 = 0x40u;
	if (mem_read8(a0 + 9u) == 0u)
		d0 = 0x74u;
	mem_write16(a0 + 0x28u, d0);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_048EDA(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_051FCC(uint32_t a0, uint32_t a1)
{
	if (mem_read8(a0 + 0x2Au) != 1u)
		return;
	func_051FD6(a0, a1);
}

void func_051FD6(uint32_t a0, uint32_t a1)
{
	uint8_t d0 = 0;
	uint8_t t1 = 0;

	d0 = 0x7Fu;
	t1 = mem_read8(a0 + 0x45u);
	mem_write8(a0 + 0x45u, t1 & 0x7Fu);
	if ((t1 & 0x80u) != 0u)
		d0 = 0xB7u;
	mem_write8(a1 + 6u, mem_read8(a1 + 6u) & d0);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x22u, 0u);
}

void func_051FF6(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052002_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_05200E(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0, d0 = 0, d1 = 0, d2 = 0;

	d0 = 0x80u;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
	{
		d0 = 0u;
		mem_write8(a0, mem_read8(a0) | 0x40u);
	}
	if (mem_read16(a0 + 0x2Eu) < 0x20u)
	{
		d2 = 0x20u;
		if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
			d2 = (uint16_t)(0u - d2);
		a6 = mem_read32(a1);
		d1 = mem_read16(a6 + 0xCu);
		d2 = (uint16_t)(d2 + mem_read16(a6 + 0xEu));
		direction_to(a0, &d0, &d1, &d2);
	}
	d1 = 0x300u;
	func_047CCC((uint8_t)d0, (uint16_t)d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 0x22u, 0xB4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_0585C4_ADDRESS;
	set_animation(d1, a0, a6);
}

uint32_t func_05207A(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;
	uint32_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d7 = 0xFFFFFFFFu;
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		if ((mem_read8(a0 + 1u) & 8u) != 0u)
		{
			t1 = mem_read32(a0 + 0x16u) - 0x100u;
			mem_write16(a0 + 0x18u, t1);
			mem_write16(a0 + 0x16u, t1 >> 16);
			d7 &= ~0xFFu;
		}
	}
	else if ((mem_read8(a0 + 1u) & 0x10u) != 0u)
	{
		t1 = mem_read32(a0 + 0x16u) - 0x100u;
		mem_write16(a0 + 0x18u, t1);
		mem_write16(a0 + 0x16u, t1 >> 16);
		d7 &= ~0xFFu;
	}
	if ((int8_t)((mem_read8(a0 + 0x2Bu) - 0x40u) ^ ((uint32_t)mem_read8(a0) << 1)) >= 0)
	{
		func_04826A(a0);
		return d7;
	}
	if ((int8_t)d7 >= 0)
		mem_write8(a0 + 0x22u, 0u);
	if (mem_read16(a0 + 0x2Cu) < 0x50u)
	{
		func_04826A(a0);
		return d7;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x48u, 0x20u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write16(a0 + 0x48u, 0u - mem_read16(a0 + 0x48u));
	mem_write16(a0 + 0x1Cu, 0xFFC0u);
	a6 = 0x58636u;
	if ((int8_t)mem_read8(a0 + 0x2Bu) < 0)
	{
		mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
		a6 = 0x58660u;
	}
	set_animation(0u, a0, a6);
	return d7;
}

void func_052116(uint32_t a0)
{
	mem_write16(a0 + 0x1Au, mem_read16(a0 + 0x1Au) + mem_read16(a0 + 0x48u));
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
	}
	func_04826A(a0);
}

void func_052136(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052142_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_05214E(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0xFD00u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
	{
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		mem_write8(a0, mem_read8(a0) | 0x40u);
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0xB4u);
	a6 = animations_0585C4_ADDRESS;
	set_animation(0u, a0, a6);
}

uint32_t func_052188(uint32_t a0)
{
	uint32_t a6 = 0, d7 = 0;
	uint32_t t1 = 0;

	mem_write8(a0 + 0x22u, mem_read8(a0 + 0x22u) - 1u);
	d7 = 0xFFFFFFFFu;
	if ((mem_read8(a0) & 0x40u) != 0u)
	{
		if ((mem_read8(a0 + 1u) & 8u) != 0u)
		{
			t1 = mem_read32(a0 + 0x16u) - 0x100u;
			mem_write16(a0 + 0x18u, t1);
			mem_write16(a0 + 0x16u, t1 >> 16);
			d7 &= ~0xFFu;
		}
	}
	else if ((mem_read8(a0 + 1u) & 0x10u) != 0u)
	{
		t1 = mem_read32(a0 + 0x16u) - 0x100u;
		mem_write16(a0 + 0x18u, t1);
		mem_write16(a0 + 0x16u, t1 >> 16);
		d7 &= ~0xFFu;
	}
	if ((int8_t)((mem_read8(a0 + 0x2Bu) - 0x40u) ^ ((uint32_t)mem_read8(a0) << 1)) >= 0)
	{
		func_04826A(a0);
		return d7;
	}
	if ((int8_t)d7 >= 0)
		mem_write8(a0 + 0x22u, 0u);
	if (mem_read16(a0 + 0x2Cu) < 0x50u)
	{
		func_04826A(a0);
		return d7;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x48u, 0x20u);
	if ((mem_read8(a0) & 0x40u) != 0u)
		mem_write16(a0 + 0x48u, 0u - mem_read16(a0 + 0x48u));
	mem_write16(a0 + 0x1Cu, (uint32_t)mem_read16(a0 + 0x2Eu) << 3);
	a6 = 0x58660u;
	if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
	{
		mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
		a6 = 0x58636u;
	}
	set_animation(0u, a0, a6);
	return d7;
}

void func_052228(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052234_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_052244(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x8Cu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x48u, 0xFFE0u);
	mem_write16(a0 + 0x1Au, 0x200u);
	if ((mem_read8(a0) & 0x40u) == 0u)
	{
		mem_write16(a0 + 0x48u, 0u - mem_read16(a0 + 0x48u));
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x22u, 0xB4u);
	a6 = 0x585DEu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_052286(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;
	uint16_t d0 = 0, d2 = 0;
	uint32_t a6 = 0, d1 = 0;
	uint16_t t1 = 0;

	d0 = mem_read16(a0 + 0x48u);
	t1 = mem_read16(a0 + 0x1Au) + d0;
	mem_write16(a0 + 0x1Au, t1);
	if (t1 != 0u)
		func_04826A(a0);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		if (unk_061244 == 0u)
		{
			d0 = (uint16_t)((d0 & ~0xFFu) | 0xFFu);
			d1 = mem_read16(a0 + 0xCu);
			d2 = mem_read16(a0 + 0xEu);
			func_030024(d0, d1, d2, &d5, &d6, p_d7);
			unk_061244 = 0xFFu;
		}
		a6 = 0x5860Cu;
		set_animation(d1, a0, a6);
	}
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0522CC(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_0522F0(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_052306(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052312_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_052330(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	d7_2 = (d7 & ~0xFFu) | 0x8Cu;
	func_0091A4((uint8_t)d7_2, 0u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	mem_write16(a0 + 0x48u, 0x20u);
	mem_write16(a0 + 0x1Au, 0xFE00u);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x40u);
		mem_write16(a0 + 0x48u, 0u - mem_read16(a0 + 0x48u));
		mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x585DEu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_052378(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x587FAu;
	set_animation(0u, a0, a6);
}

uint32_t func_0523A8(uint32_t d7, uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 0x46u, 0x103u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		d7 = (d7 & ~0xFFu) | 0x14u;
		func_0091A4((uint8_t)d7, 0u);
	}
	return d7;
}

void func_0523C6(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x46u);
	mem_write8(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x46u, 4u);
		*p_a5 = 0x5232Au;
		func_047C5A(a0, *p_a5, &d7, &a6, &zero);
		if (zero == 0u)
		{
			mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
			a6 = 0x58856u;
			set_animation(0u, a0, a6);
		}
		else
		{
			mem_write8(a6 + 3u, (uint32_t)mem_read8(a0) << 1);
			mem_write16(a6 + 0x28u, mem_read16(a0 + 0x28u));
			t2 = mem_read8(a0 + 0x47u);
			mem_write8(a0 + 0x47u, t2 - 1u);
			if (t2 == 1u)
			{
				mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
				a6 = 0x58856u;
				set_animation(0u, a0, a6);
			}
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_05240E(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write16(a0 + 0x22u, 0u);
	}
}

void func_052422(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05242E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_052484(uint32_t d7, uint32_t a0)
{
	func_052510(a0);
	return func_052330(d7, a0);
}

void func_05248C(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7)
{
	uint32_t d5 = *p_d5;
	uint32_t d6 = *p_d6;

	func_052510(a0);
	func_052286(a0, &d5, &d6, p_d7);
	*p_d5 = (*p_d5 & 0xFFFFFF00u) | (d5 & 0xFFu);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

uint32_t func_052494(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	func_052510(a0);
	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7_2 = (d7 & ~0xFFu) | 0x2Au;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = 0x588BCu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_0524D2(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_052510(a0);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		mem_write8(a0 + 0x4Au, 0u);
		mem_write8(a0 + 0x46u, 0u);
		*p_a5 = 0x5244Au;
		func_047C5A(a0, *p_a5, &d7, &a6, &zero);
		if (zero == 0u)
		{
			mem_write16(a0 + 4u, 0x200u);
			mem_write16(a0 + 0x22u, 0u);
		}
		else
		{
			mem_write32(a0 + 0x24u, a6);
			mem_write32(a6 + 0x24u, a0);
			a6 = 0x58918u;
			set_animation(0u, a0, a6);
		}
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_052510(uint32_t a0)
{
	uint16_t d1 = 0;
	uint32_t t1 = 0;

	d1 = 0x200u;
	if (mem_read16(a0 + 0x2Eu) < 3u)
		return;
	if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
		d1 = (uint16_t)(0u - d1);
	t1 = mem_read32(a0 + 0x16u) + (int16_t)d1;
	mem_write16(a0 + 0x18u, t1);
	mem_write16(a0 + 0x16u, t1 >> 16);
}

uint32_t func_052530(uint32_t d7, uint32_t a0)
{
	uint8_t d0 = 0;
	uint32_t a2 = 0, a6 = 0, d7_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	func_052510(a0);
	a2 = mem_read32(a0 + 0x24u);
	if ((mem_read8(a2) & 8u) == 0u)
	{
		if ((mem_read8(a0 + 0x4Au) & 2u) != 0u)
		{
			func_0525AA(a0);
			return d7;
		}
		mem_write8(a0 + 0x46u, mem_read8(a0 + 0x46u) + 1u);
		if (mem_read8(a0 + 0x46u) != 0xDu)
			return d7;
		mem_write8(a0 + 0x46u, mem_read8(a0 + 0x46u) - 1u);
		func_0525AA(a0);
		return d7;
	}
	d7_2 = 0x60000u | mem_read16(a2 + 0x4Eu);
	t1 = mem_read16(d7_2 + 0xCu) - mem_read16(a0 + 0xCu);
	d0 = (uint8_t)t1;
	if ((int16_t)t1 < 0)
		d0 = (uint8_t)(uint16_t)(0u - d0);
	t2 = d0;
	d0 = (uint8_t)(t2 - 0x30u);
	if (t2 < 0x30u)
		d0 = 0u;
	d0 = d0 >> 3;
	if (d0 >= 0xCu)
		d0 = 0xCu;
	mem_write8(a0 + 0x46u, d0);
	mem_write8(a0 + 0x4Au, mem_read8(a0 + 0x4Au) | 0x20u);
	mem_write8(a0 + 5u, 5u);
	a6 = 0x59150u;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_0525AA(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x4Au, mem_read8(a0 + 0x4Au) | 0x40u);
	a6 = TABLE32(animations_052450, (uint32_t)(int16_t)((uint32_t)(int8_t)mem_read8(a0 + 0x46u) << 2));
	set_animation(0u, a0, a6);
	mem_write8(a0 + 5u, 6u);
}

uint32_t func_0525D0(uint32_t a0)
{
	uint32_t d7 = 0;

	d7 = 0x60000u | mem_read16(a0 + 0x4Eu);
	if ((mem_read8(a0 + 0x4Au) & 4u) != 0u)
	{
		func_0525AA(a0);
		return d7;
	}
	return d7;
}

void func_0525E6(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x46u) - 1u;
	mem_write8(a0 + 0x46u, t1);
	if ((int8_t)t1 < 0)
	{
		mem_write8(a0 + 0x4Au, mem_read8(a0 + 0x4Au) | 0x80u);
		mem_write16(a0 + 4u, 0x200u);
		mem_write16(a0 + 0x22u, 0u);
	}
}

void func_052600(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05260C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_052624(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x526C0u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x5877Eu;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_051FCC(a0, a1);
	return d7;
}

uint32_t func_05265C(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	func_048262(a0);
	a6 = 0x52618u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x58788u;
	set_animation(0u, a0, a6);
	return d7;
}

void func_05268A(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0 + 4u, 0x200u);
		mem_write8(a0 + 0x22u, 0u);
		mem_write8(a0, mem_read8(a0) | 2u);
	}
}

void func_0526A4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0526B0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0526CC(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	a6 = 0x526C0u;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x58794u;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_051FCC(a0, a1);
	return d7;
}

uint32_t func_052704(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0, d7_2 = 0;

	func_048262(a0);
	a6 = 0x526C0u;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	d7_2 = (d7 & ~0xFFu) | 0xFu;
	func_0091A4((uint8_t)d7_2, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5879Eu;
	set_animation(0u, a0, a6);
	return d7_2;
}

void func_05273C(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5879Eu;
	set_animation(0u, a0, a6);
}

void func_052756(uint32_t a0, uint32_t a1)
{
	uint8_t t1 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write16(a0, 0u);
		mem_write8(a1 + 4u, mem_read8(a1 + 4u) - 1u);
		t1 = unk_06120C - 1u;
		unk_06120C = t1;
		if ((int8_t)t1 < 0)
			unk_06120C = 0u;
	}
}

void func_052790(uint32_t a0, uint32_t a1, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d0 = 0;

	func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
	mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
	mem_write16(a0 + 0x20u, a6);
	mem_write8(a0 + 0x23u, 0x10u);
	mem_write8(a0 + 0x22u, 0u);
	mem_write8(a0 + 0x2Au, 0u);
	mem_write8(a0 + 0x45u, 0u);
	mem_write8(a0 + 0x24u, 3u);
	d0 = unk_060130 & 7u;
	mem_write8(a0 + 0x31u, DATA8(indexed_table_of_8_bit_values_052A60_ADDRESS + d0));
	mem_write8(a0 + 0x4Au, DATA8(rom_052ADE_ADDRESS + d0));
	mem_write16(a0 + 0x46u, DATA16(indexed_table_of_16_bit_values_052B3A_ADDRESS + (uint16_t)((uint32_t)d0 << 1)));
	mem_write16(a0 + 0x34u, 4u);
	mem_write8(a0 + 0x32u, 0u);
	mem_write32(a0 + 0x3Au, 0x2E928u);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	unk_06120C++;
	if ((int8_t)mem_read8(a0 + 3u) < 0)
	{
		mem_write8(a0, mem_read8(a0) | 0x80u);
		mem_write16(a0 + 0x28u, 0xA8u);
		func_052830(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
	unk_06123A = 0u;
	unk_06123B = 0u;
	unk_06123C = 0u;
	mem_write16(a0 + 0x28u, 0xECu);
}

void func_052830(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_052840(uint32_t a0, uint32_t a6, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	bool L_052920 = false, L_052992 = false, L_052A68 = false;
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6_2 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t8 = 0, t9 = 0;
	uint32_t t2 = 0, t3 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	t1 = mem_read8(a0 + 0x23u);
	mem_write8(a0 + 0x23u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x23u, 0x10u);
		if (unk_061207 != 0u)
		{
			mem_write8(*p_a1 + 4u, mem_read8(*p_a1 + 4u) - 1u);
			func_0483D2(a0, p_d5, p_d6, p_d7, p_a5, &a6);
			d0 = unk_06120D;
			if (d0 <= mem_read8(a6 + 4u))
			{
				t2 = *p_a5;
				*p_a5 = a6;
				a6 = t2;
				if (d0 <= mem_read8(a6 + 4u))
				{
					a6 = unk_061208;
					if (d0 <= mem_read8(a6 + 4u))
					{
						t3 = *p_a5;
						*p_a5 = a6;
						a6 = t3;
					}
				}
			}
			*p_d7 = (*p_d7 & ~0xFFFFu) | (uint16_t)a6;
			if ((uint16_t)*p_d7 != mem_read16(a0 + 0x20u))
				func_0486CC(a0, *p_a1);
			mem_write16(a0 + 0x20u, a6);
			*p_a1 = a6;
			mem_write8(a6 + 4u, mem_read8(a6 + 4u) + 1u);
		}
	}
	a6_2 = mem_read32(*p_a1);
	func_0482FA(a0, a6_2, &ignored, &ignored_2);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	if ((mem_read8(a0) & 2u) != 0u)
	{
		L_052920 = (int8_t)mem_read8(a0 + 3u) < 0;
		if (!L_052920)
		{
			d0 = unk_061207;
			L_052920 = d0 < unk_06120C || DATA8(indexed_table_of_8_bit_values_052918_ADDRESS + (d0 & 7u)) < unk_06123C;
			if (!L_052920)
			{
				unk_06123C++;
				mem_write16(a0 + 0x28u, 0xF0u);
				mem_write8(a0 + 5u, 0u);
			}
		}
		if (L_052920)
		{
			if (unk_06123A != 0u)
			{
				mem_write8(a0, mem_read8(a0) | 0x80u);
				mem_write8(a0, mem_read8(a0) & ~2u);
				mem_write16(a0 + 0x28u, 0xDCu);
				mem_write16(a0 + 4u, 0x500u);
				return;
			}
			if (mem_read8(a0 + 0x2Au) != 0u || mem_read8(*p_a1 + 5u) >= 0xC0u)
			{
				if (mem_read8(a0 + 0x2Au) == 1u && (mem_read16(a0 + 0x2Cu) >= 0x50u || mem_read16(a0 + 0x2Eu) >= 0x50u))
					func_0486D6(a0, *p_a1);
			}
			else if (mem_read16(a0 + 0x2Cu) < 0x40u && mem_read16(a0 + 0x2Eu) < 0x40u)
			{
				mem_write8(a0 + 0x2Au, 1u);
				mem_write8(a0 + 0x22u, 0u);
				do
				{
					if (L_052992 || (int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
					{
						for (;;)
						{
							L_052992 = false;
							t4 = mem_read8(*p_a1 + 5u);
							mem_write8(*p_a1 + 5u, t4 | 0x40u);
							if ((t4 & 0x40u) != 0u)
							{
								t5 = mem_read8(*p_a1 + 5u);
								mem_write8(*p_a1 + 5u, t5 | 0x80u);
								if ((t5 & 0x80u) != 0u)
									continue;
								mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
								break;
							}
							mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 0x80u);
							break;
						}
					}
					else
					{
						t5 = mem_read8(*p_a1 + 5u);
						mem_write8(*p_a1 + 5u, t5 | 0x80u);
						L_052992 = (t5 & 0x80u) != 0u;
						if (!L_052992)
							mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & 0x7Fu);
					}
				} while (L_052992);
			}
			if (mem_read8(a0 + 0x2Au) != 1u)
				L_052A68 = true;
			else
			{
				a6_2 = mem_read32(*p_a1);
				if (mem_read8(a6_2 + 4u) != 4u || indexed_table_of_8_bit_values_048C5E[mem_read8(a6_2 + 0x23u)] != 0u)
				{
					t6 = mem_read8(a0 + 0x31u);
					mem_write8(a0 + 0x31u, t6 - 1u);
					L_052A68 = t6 != 1u;
					if (!L_052A68)
					{
						mem_write8(a0 + 0x31u, DATA8(indexed_table_of_8_bit_values_052A60_ADDRESS + (unk_060130 & 7u)));
						L_052A68 = mem_read8(mem_read32(*p_a1) + 4u) != 3u || mem_read16(a0 + 0x2Eu) >= 6u || mem_read16(a0 + 0x2Cu) >= 0x50u || (int8_t)mem_read8(a0 + 0x44u) >= 0;
						if (!L_052A68)
						{
							func_0486D6(a0, *p_a1);
							mem_write8(a0 + 0x2Au, 2u);
							mem_write8(a0 + 0x22u, 0u);
						}
					}
				}
				else
				{
					func_0486D6(a0, *p_a1);
					mem_write8(a0 + 0x2Au, 3u);
					mem_write8(a0 + 0x22u, 0u);
				}
			}
			if (L_052A68)
			{
				if (mem_read8(mem_read32(*p_a1) + 4u) != 4u)
				{
					t7 = mem_read8(a0 + 0x4Au);
					mem_write8(a0 + 0x4Au, t7 - 1u);
					if (t7 == 1u)
					{
						mem_write8(a0 + 0x4Au, DATA8(rom_052ADE_ADDRESS + (unk_060130 & 7u)));
						if (mem_read16(a0 + 0x2Eu) <= 5u)
						{
							a6_2 = record_052ACE_ADDRESS;
							d1 = mem_read16(a0 + 0x2Cu);
							*p_d6 = 3u;
							do
							{
								if (d1 < DATA16(a6_2))
								{
									mem_write16(a0 + 0x28u, DATA16(a6_2 + 8u));
									mem_write16(a0 + 4u, 0x300u);
									mem_write8(a0, mem_read8(a0) & ~8u);
									return;
								}
								t8 = *p_d6 - 1u;
								*p_d6 = t8;
								a6_2 += 2u;
							} while (t8 != 0xFFFFu);
						}
					}
					if ((int8_t)mem_read8(a0 + 8u) < 0 && unk_06123B == 0u)
					{
						t9 = mem_read16(a0 + 0x46u);
						mem_write16(a0 + 0x46u, t9 - 1u);
						if (t9 == 1u)
						{
							mem_write16(a0 + 0x46u, DATA16(indexed_table_of_16_bit_values_052B3A_ADDRESS + (uint16_t)((unk_060130 & 7u) << 1)));
							mem_write16(a0 + 0x28u, 0xB0u);
							mem_write16(a0 + 4u, 0x300u);
							mem_write8(a0, mem_read8(a0) & ~8u);
							mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) | 1u);
							unk_06123B = 0xFFu;
							return;
						}
					}
				}
			}
			if (mem_read8(a0 + 0x22u) == 0u)
			{
				mem_write16(a0 + 0x28u, DATA16(indexed_table_of_16_bit_values_052B7C_ADDRESS + (uint16_t)((mem_read8(a0 + 0x2Au) & 3u) << 1)));
				mem_write8(a0 + 5u, 0u);
			}
		}
	}
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	switch ((uint32_t)(int16_t)*p_d6)
	{
	case 20:
		func_049234(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_049344(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049408(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_0495CA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_04964E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_04978A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_04989A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_049934(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_0499A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04ADAC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04ADEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04AE78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_04AF24(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04AFBE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B032(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B074(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B12E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_04B238(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04DD34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04DD76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04DDB4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04DE60(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04DEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04DF64(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04DFA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_04DFE4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04E0A8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04E1B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04E254(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E7AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E7F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04E832(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		func_04E8FA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_04E992(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04EA06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04EA4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_04EA8A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		func_04EAC8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 136:
		func_04EB62(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 196:
		func_04F722(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		func_04F750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		func_04F77E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_04F7B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 188:
		func_04F7EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_04F81C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_04F89C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_04F922(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04F9C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 228:
		func_05067E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_0506D8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_050770(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_0507EE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_051750(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_05182A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_0518B0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_051FF6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_052136(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_052228(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 236:
		func_052C96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 240:
		func_052D46(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_052DD0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 244:
		func_052E54(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 248:
		func_052FD8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 252:
		func_053070(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 256:
		func_0530EA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_052B84(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t a6 = 0, ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;
	uint16_t t1 = 0;
	uint32_t jump_target = 0;

	t1 = mem_read16(a0 + 0x46u);
	mem_write16(a0 + 0x46u, t1 - 1u);
	if (t1 == 1u)
		mem_write16(a0 + 0x46u, 1u);
	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	a6 = mem_read32(*p_a1);
	func_0482FA(a0, a6, &ignored, &ignored_2);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored_3, &ignored, &ignored_2, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	*p_d6 = (*p_d6 & ~0xFFFFu) | mem_read16(a0 + 0x28u);
	jump_target = mem_read32(0x53D2Au + (int16_t)*p_d6);
	switch (jump_target)
	{
	case 0x049A06u:
		func_049A06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049A52u:
		func_049A52(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049A8Eu:
		func_049A8E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049ACAu:
		func_049ACA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049B06u:
		func_049B06(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049BBCu:
		func_049BBC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x049C72u:
		func_049C72();
		return;
	case 0x049C74u:
		func_049C74();
		return;
	case 0x049C76u:
		func_049C76(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B2DAu:
		func_04B2DA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B316u:
		func_04B316(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B352u:
		func_04B352(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B42Au:
		func_04B42A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B4E0u:
		func_04B4E0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04B5D6u:
		func_04B5D6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E2C4u:
		func_04E2C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E336u:
		func_04E336(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E3C4u:
		func_04E3C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E400u:
		func_04E400(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E43Cu:
		func_04E43C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04E4F2u:
		func_04E4F2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EBD6u:
		func_04EBD6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EC5Eu:
		func_04EC5E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04EC9Au:
		func_04EC9A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04ECD6u:
		func_04ECD6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04F076u:
		func_04F076(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04F0E4u:
		func_04F0E4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FA96u:
		func_04FA96(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FC04u:
		func_04FC04(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FCD4u:
		func_04FCD4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FD4Cu:
		func_04FD4C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x04FD88u:
		func_04FD88(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0508A0u:
		func_0508A0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050ADCu:
		func_050ADC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050B8Cu:
		func_050B8C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x050C68u:
		func_050C68(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x052306u:
		func_052306(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x052422u:
		func_052422(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0534C4u:
		func_0534C4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x053524u:
		func_053524(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x05356Eu:
		func_05356E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x0535B8u:
		func_0535B8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0x053602u:
		func_053602(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_052BC8(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint8_t t1 = 0;

	*p_d7 = (*p_d7 & ~0xFFu) | 0x92u;
	func_0091A4((uint8_t)*p_d7, 0u);
	t1 = mem_read8(a0 + 0x45u);
	mem_write8(a0 + 0x45u, t1 & ~1u);
	if ((t1 & 1u) != 0u)
	{
		unk_06123B = 0u;
		if (mem_read8(a0 + 0x41u) < 4u)
			mem_write16(a0 + 0x46u, 1u);
	}
	if (mem_read16(a0 + 8u) != 0u)
	{
		if (mem_read8(a0 + 9u) == 0u)
		{
			mem_write16(a0 + 0x28u, 0xCCu);
			mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
			func_052C68(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
			return;
		}
		*p_d7 = ((*p_d7 & ~0xFFFFu) | mem_read16(a0 + 0x32u)) & ~0xFFu;
		if ((uint16_t)*p_d7 != mem_read16(a0 + 0x10u))
		{
			mem_write8(a0 + 0x42u, 0xBu);
			mem_write8(a0 + 4u, 2u);
			return;
		}
		if ((int8_t)(((uint32_t)mem_read8(a0) << 1) ^ mem_read8(a0 + 7u)) >= 0)
			mem_write16(a0 + 0x28u, 0xD0u);
		else
			mem_write16(a0 + 0x28u, 0xD4u);
	}
	else if ((int8_t)mem_read8(a0 + 3u) >= 0)
		mem_write16(a0 + 0x28u, 0xD8u);
	else
		mem_write16(a0 + 0x28u, 0xDCu);
	mem_write8(a0 + 4u, mem_read8(a0 + 4u) + 1u);
	func_052C68(a0, p_d5, p_d6, p_d7, p_a1, p_a5);
}

void func_052C68(uint32_t a0, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a1, uint32_t *p_a5)
{
	uint32_t ignored = 0, ignored_2 = 0, ignored_3 = 0, ignored_4 = 0;

	*p_a1 = 0x60000u | mem_read16(a0 + 0x20u);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0xE0u);
	func_04876C(a0, &ignored, &ignored_2, &ignored_3, &ignored_4, p_d5, p_d6, p_d7, p_a5);
	func_048570(a0);
	switch ((uint32_t)(int16_t)mem_read16(a0 + 0x28u))
	{
	case 228:
		func_0494C6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 232:
		func_04955C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 0:
		func_049DDC(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 4:
		func_049E10(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 8:
		func_049E34(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 12:
		func_049E58(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 36:
		func_049E7C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 32:
		func_049FB8(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 16:
		func_04A0F4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 128:
		func_04A1D4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 132:
		*p_a5 = unreached_04A338(a0, *p_a1);
		return;
	case 136:
		func_04A368(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 140:
		*p_a5 = unreached_04A3F4(a0, *p_a1);
		return;
	case 188:
		func_04A426(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 192:
		*p_a5 = unreached_04A4B2(a0, *p_a1);
		return;
	case 196:
		func_04A4E4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 200:
		*p_a5 = unreached_04A570(a0, *p_a1);
		return;
	case 20:
		func_04A5A2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 24:
		func_04A6B2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 28:
		func_04A704(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 40:
		func_04B632(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 44:
		func_04B656(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 48:
		func_04B67A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 52:
		func_04B69E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 56:
		func_04B6C2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 60:
		func_04B6E6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 68:
		func_04B70A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 72:
		func_04E566(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 76:
		func_04E58A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 80:
		func_04E5AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 84:
		func_04E5D2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 88:
		func_04E5F6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 92:
		func_04E61A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 96:
		func_04E63E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 100:
		func_04E662(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 120:
		func_04ED5E(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 124:
		func_04ED82(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 104:
		func_04EDA6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 108:
		func_04EDCA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 112:
		func_04EDEE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 164:
		func_04FE42(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 168:
		func_04FEAA(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 160:
		func_04FEE2(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 152:
		func_04FF1A(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 156:
		func_050076(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 172:
		func_050CE6(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 176:
		func_050D2C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 180:
		func_050D78(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 184:
		func_050E66(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 148:
		func_051968(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 224:
		func_0519C0(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 144:
		func_051A08(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 64:
		func_052600(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 116:
		func_0526A4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 204:
		func_0531AE(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 208:
		func_053242(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 212:
		func_0532D4(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 216:
		func_05333C(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	case 220:
		func_053440(a0, *p_a1, p_d5, p_d6, p_d7, p_a5);
		return;
	}
}

void func_052C96(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052CA2_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_052CAE(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (unk_06120C != 1u)
		return d7;
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0, mem_read8(a0) | 0x80u);
	d7_2 = (d7 & ~0xFFu) | 0x16u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = animations_05AD40_ADDRESS;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_052CDC(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return d7;
	mem_write16(a0 + 0x1Au, 0u);
	mem_write16(a0 + 0x1Cu, 0xFF00u);
	mem_write8(a0 + 0x48u, 0x20u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d7_2 = (d7 & ~0xFFFFu) | 0x6Au;
	unk_060080 = d7_2;
	func_0091A4((uint8_t)d7_2, 0u);
	d7_2 = (d7_2 & ~0xFFu) | 0xA7u;
	func_0091A4((uint8_t)d7_2, 0u);
	a6 = animations_05B07E_ADDRESS;
	set_animation(0u, a0, a6);
	return d7_2;
}

uint32_t func_052D20(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 2u);
		mem_write16(a0 + 4u, 0x200u);
		a6 = 0x54786u;
		d7 = func_0485AE(d7, a0, a6);
	}
	func_04824C(a0);
	return d7;
}

void func_052D46(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052D52_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_052D62(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t zero = 0;
	uint16_t d7_2 = 0;
	uint32_t a6 = 0, d7 = 0;

	mem_write8(a0, mem_read8(a0) & ~2u);
	a6 = animations_05B032_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B03Cu;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0x100u);
	mem_write8(a0 + 0x48u, 0x20u);
	*p_a5 = 0x52D5Au;
	func_047C30(a0, *p_a5, &d7, &a6, &zero);
	mem_write8(a6 + 8u, mem_read8(a0 + 8u));
	d7_2 = (uint16_t)((d7 & ~0xFFu) | 0x3Du);
	func_0091A4((uint8_t)d7_2, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_2;
}

void func_052DB2(uint32_t a0)
{
	uint8_t t1 = 0;

	mem_write8(a0, mem_read8(a0) ^ 0x80u);
	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0, mem_read8(a0) | 0x82u);
		mem_write8(a0 + 0x22u, 0u);
	}
	func_04826A(a0);
}

void func_052DD0(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052DDC_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_052DE4(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0, mem_read8(a0) | 0x80u);
	a6 = animations_05B032_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B03Cu;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write16(a0 + 0x1Cu, 0u);
	mem_write16(a0 + 0x1Au, 0xFF00u);
	mem_write8(a0 + 0x22u, 0x20u);
}

uint32_t func_052E1A(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a0, mem_read8(a0) ^ 0x80u);
	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
	{
		func_04826A(a0);
		return d7;
	}
	mem_write8(a0, mem_read8(a0) | 0x82u);
	mem_write16(a0 + 4u, 0x200u);
	a6 = 0x547A6u;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x547B6u;
	d7 = func_0485AE(d7, a0, a6);
	func_04826A(a0);
	return d7;
}

void func_052E54(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052E60_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_052E84(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		*p_a5 = 0x52E7Cu;
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_052EAE(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		*p_a5 = 0x52E7Cu;
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) < 0x40u || (int8_t)(d0 - 0x40u - mem_read8(a0 + 0x45u)) < 0)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0x180u);
		if ((int8_t)mem_read8(a0 + 0x45u) < 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, 0x180u);
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	if (mem_read16(a0 + 0x2Eu) < 3u)
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_052F20(uint32_t a0)
{
	uint32_t a6 = 0;

	if ((unk_0600A4 & 0x700u) != 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 2u);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5B9B2u;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B9BEu;
	set_animation(0u, a0, a6);
}

void func_052F52(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d6 = *p_d6;
	uint8_t d0 = 0;
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		d0 = mem_read8(a0 + 0x2Bu);
		a6 = mem_read32(a1);
		*p_a5 = animations_052E74_ADDRESS;
		if ((int8_t)mem_read8(a0 + 8u) >= 0)
			*p_a5 = 0x52E7Cu;
		func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_052F80(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		*p_a5 = 0x52E7Cu;
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) >= 0x10u)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0x180u);
		if ((int8_t)(d0 - 0x40u) >= 0)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	else
	{
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0u);
	}
	if (mem_read16(a0 + 0x2Eu) < 3u)
	{
		func_04826A(a0);
		*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
		return;
	}
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) - 3u);
	func_04826A(a0);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_052FD8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_052FE4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_052FEC(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x22u, 1u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		*p_a5 = 0x52E7Cu;
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_053016(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d1 = 0;
	uint32_t a5 = 0, a6 = 0, d0 = 0, ignored = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 == 1u)
	{
		a6 = mem_read32(a1);
		d0 = func_047D90(0u, a0, a6);
		a5 = animations_052E74_ADDRESS;
		if ((int8_t)mem_read8(a0 + 8u) >= 0)
			a5 = 0x52E7Cu;
		func_0484E2((uint8_t)d0, a0, a6, &ignored, p_d7, &a5);
		d1 = 0x180u;
		func_047CCC((uint8_t)d0, d1, p_d6, p_d7, p_a5);
		mem_write16(a0 + 0x1Au, *p_d6);
		mem_write16(a0 + 0x1Cu, *p_d7);
		mem_write8(a0 + 0x22u, 8u);
	}
	if (mem_read16(a0 + 0x2Cu) >= 0x3Cu || mem_read16(a0 + 0x2Eu) >= 0x20u)
		func_04826A(a0);
}

void func_053070(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05307C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_053084(uint32_t a0)
{
	uint32_t a6 = 0;

	a6 = animations_05B6EE_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B6F8u;
	set_animation(0u, a0, a6);
	mem_write8(a0, mem_read8(a0) & ~0xEu);
	mem_write8(a0 + 0x22u, 0x1Eu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

uint32_t func_0530B0(uint32_t d6, uint32_t a0)
{
	uint16_t d1 = 0;
	uint32_t a6 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(a0 + 0x22u);
	mem_write8(a0 + 0x22u, t1 - 1u);
	if (t1 != 1u)
		return d6;
	mem_write8(a0 + 0x2Au, 0u);
	a6 = record_052ACE_ADDRESS;
	d1 = mem_read16(a0 + 0x2Cu);
	d6 = 2u;
	do
	{
		if (d1 < DATA16(a6))
			break;
		t2 = d6 - 1u;
		d6 = t2;
		a6 += 2u;
	} while (t2 != 0xFFFFu);
	mem_write16(a0 + 0x28u, DATA16(a6 + 8u));
	mem_write16(a0 + 4u, 0x300u);
	mem_write8(a0, mem_read8(a0) & ~8u);
	return d6;
}

void func_0530EA(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0530F6_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_053102(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint16_t d1 = 0;
	uint32_t a6 = 0, ignored = 0;

	mem_write8(a0 + 0x22u, 0x40u);
	mem_write8(a0 + 0x48u, 0x28u);
	d0 = mem_read8(a0 + 0x2Bu);
	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		*p_a5 = 0x52E7Cu;
	a6 = mem_read32(a1);
	func_0484B2(d0, a0, a6, &ignored, p_d7, p_a5);
	d0 -= 0x80u;
	d1 = 0x100u;
	func_047CCC(d0, d1, p_d6, p_d7, p_a5);
	mem_write16(a0 + 0x1Au, *p_d6);
	mem_write16(a0 + 0x1Cu, *p_d7);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
}

void func_05314C(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	*p_a5 = animations_052E74_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		*p_a5 = 0x52E7Cu;
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 != 1u)
		func_053198(a0, a1);
	else
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = animations_05B032_ADDRESS;
		if ((int8_t)mem_read8(a0 + 8u) >= 0)
			a6 = 0x5B03Cu;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_053198(uint32_t a0, uint32_t a1)
{
	if (mem_read8(mem_read32(a1) + 4u) != 4u)
	{
		mem_write8(a0 + 0x2Au, 0u);
		mem_write8(a0 + 0x22u, 0u);
	}
}

void func_0531AE(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0531BA_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0531C8(uint32_t a0)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x42u, 0xBu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x48u, 0xCu);
	a6 = 0x5B572u;
	set_animation(0u, a0, a6);
}

void func_0531E4(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t d7 = *p_d7;
	uint32_t zero = 0;
	uint32_t a6 = 0, ignored = 0;
	uint8_t t1 = 0;

	func_05322C(a0);
	if (mem_read8(a0 + 0x33u) != 0u)
	{
		t1 = mem_read8(a0 + 0x48u);
		mem_write8(a0 + 0x48u, t1 - 1u);
		if (t1 == 1u)
		{
			*p_a5 = 0x531C2u;
			func_047C5A(a0, *p_a5, &d7, &ignored, &zero);
		}
	}
	else
	{
		mem_write8(a0 + 0x42u, 0xFFu);
		a6 = 0x54796u;
		if ((int8_t)mem_read8(a0 + 3u) < 0)
			a6 = 0x547B6u;
		d7 = func_0485AE(d7, a0, a6);
		func_048608(a0);
	}
	*p_d7 = (*p_d7 & 0xFFFF0000u) | (d7 & 0xFFFFu);
}

void func_05322C(uint32_t a0)
{
	uint8_t d0 = 0;

	d0 = 0xBu;
	if ((unk_0600A4 & 2u) != 0u)
		d0 = 0xFFu;
	mem_write8(a0 + 0x42u, d0);
}

void func_053242(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05324E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_053256(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x42u, 0xBu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x48u, 0u);
	t1 = mem_read8(a0 + 0x24u);
	mem_write8(a0 + 0x24u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x24u, 3u);
		mem_write8(a0 + 0x48u, 0x10u);
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0x200u);
		if ((mem_read8(a0) & 0x40u) != 0u)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	a6 = animations_05B4F2_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B512u;
	set_animation(0u, a0, a6);
}

void func_0532AA(uint32_t a0)
{
	func_05322C(a0);
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x42u, 0xFFu);
		func_048608(a0);
		return;
	}
	if (mem_read8(a0 + 0x48u) == 0u)
		return;
	mem_write8(a0 + 0x48u, mem_read8(a0 + 0x48u) - 1u);
	func_04826A(a0);
}

void func_0532D4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0532E0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_0532E8(uint32_t a0)
{
	uint32_t a6 = 0;
	uint8_t t1 = 0;

	mem_write8(a0 + 0x42u, 0xBu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	mem_write8(a0 + 0x48u, 0u);
	t1 = mem_read8(a0 + 0x24u);
	mem_write8(a0 + 0x24u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 0x24u, 3u);
		mem_write8(a0 + 0x48u, 0x10u);
		mem_write16(a0 + 0x1Cu, 0u);
		mem_write16(a0 + 0x1Au, 0x200u);
		if ((mem_read8(a0) & 0x40u) == 0u)
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
	}
	a6 = 0x5B532u;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B552u;
	set_animation(0u, a0, a6);
}

void func_05333C(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_053348_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_053368(uint32_t d7, uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x42u, 0xBu);
	func_04F9A0(a0, a1);
	a6 = 0x5335Cu;
	d7 = func_04863E(d7, a0, a6);
	a6 = 0x5B592u;
	set_animation(0u, a0, a6);
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) | 0x80u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7;
}

uint32_t func_053398(uint32_t d7, uint32_t a0)
{
	uint32_t zero = 0;
	uint32_t a6 = 0;

	mem_write8(a0 + 0x42u, 0xFFu);
	func_048262(a0);
	a6 = 0x5335Cu;
	func_048696(a0, a6);
	func_04861A(a0, &d7, &zero);
	if (zero == 0u)
		return d7;
	mem_write8(a0 + 1u, mem_read8(a0 + 1u) & 0x7Fu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5B5A8u;
	set_animation(0u, a0, a6);
	return d7;
}

uint32_t func_0533D2(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read16(a0 + 0x1Au) != 0u)
	{
		func_04826A(a0);
		a6 = 0x5335Cu;
		func_048696(a0, a6);
	}
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		d7 &= ~0xFFFFu;
		unk_060080 = d7;
		func_0091A4((uint8_t)d7, a6);
		d7 |= 0x81u;
		func_0091A4((uint8_t)d7, a6);
		mem_write8(a0 + 0x48u, 0x78u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		unk_06123A = 0xFFu;
	}
	return d7;
}

void func_053422(uint32_t a0)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		t2 = unk_06120C - 1u;
		unk_06120C = t2;
		if ((int8_t)t2 < 0)
		{
			unk_06120C = 0u;
			func_05343E();
			return;
		}
	}
	func_05343E();
}

void func_05343E(void)
{
}

void func_053440(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05344C_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_053458(uint32_t a0, uint32_t a1)
{
	uint32_t a6 = 0;

	mem_write8(a0 + 0x42u, 0xAu);
	func_0486CC(a0, a1);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = animations_05B4F2_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B512u;
	set_animation(0u, a0, a6);
}

void func_053482(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) == 0u)
	{
		mem_write8(a0 + 0x48u, 0x78u);
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	}
}

void func_053496(uint32_t a0)
{
	uint8_t t1 = 0, t2 = 0;

	if ((mem_read8(a0 + 0x48u) & 0x10u) == 0u)
		mem_write8(a0, mem_read8(a0) ^ 0x80u);
	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(a0, 0u);
		t2 = unk_06120C - 1u;
		unk_06120C = t2;
		if ((int8_t)t2 < 0)
			unk_06120C = 0u;
	}
}

void func_0534C4(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0534D0_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0534D8(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = animations_05B91E_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B968u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x301u);
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_05350E(uint32_t a0)
{
	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0, mem_read8(a0) | 2u);
	func_0485F6(a0);
}

void func_053524(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_053530_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_053538(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = animations_05BB0A_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5BB54u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x301u);
	d7_2 = (d7 & ~0xFFu) | 2u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_05356E(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05357A_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_053582(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = animations_05B73A_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5B784u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x103u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_0535B8(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_0535C4_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

uint32_t func_0535CC(uint32_t d7, uint32_t a0)
{
	uint32_t a6 = 0, d7_2 = 0;

	a6 = animations_05BD3E_ADDRESS;
	if ((int8_t)mem_read8(a0 + 8u) >= 0)
		a6 = 0x5BD88u;
	set_animation(0u, a0, a6);
	mem_write16(a0 + 0xAu, 0x203u);
	d7_2 = (d7 & ~0xFFu) | 7u;
	d7_2 = func_0485D6(d7_2, a0);
	mem_write8(a0, mem_read8(a0) | 4u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	return d7_2;
}

void func_053602(uint32_t a0, uint32_t a1, uint32_t *p_d5, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint32_t a6 = 0;

	a6 = indexed_table_of_32_bit_values_05360E_ADDRESS;
	func_048236(a0, a1, a6, p_d5, p_d6, p_d7, p_a5);
}

void func_053628(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;

	mem_write8(a0 + 0x48u, 0xF0u);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	func_0484B2(d0, a0, a6, &d6, p_d7, p_a5);
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_053644(uint32_t a0, uint32_t a1, uint32_t *p_d6, uint32_t *p_d7, uint32_t *p_a5)
{
	uint8_t d0 = 0;
	uint32_t a6 = 0, d6 = 0;
	uint8_t t1 = 0;

	d0 = mem_read8(a0 + 0x2Bu);
	a6 = mem_read32(a1);
	*p_a5 = animations_052E74_ADDRESS;
	func_0484E2(d0, a0, a6, &d6, p_d7, p_a5);
	if (mem_read16(a0 + 0x2Cu) < 0x50u)
	{
		mem_write16(a0 + 0x1Cu, 0u);
		d0 = 8u;
		mem_write16(a0 + 0x1Au, 0x280u);
		if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		{
			d0 = 0x10u;
			mem_write16(a0 + 0x1Au, 0u - mem_read16(a0 + 0x1Au));
		}
		if ((d0 & mem_read8(a0 + 1u)) != 0u)
		{
			mem_write16(a0 + 0x1Au, 0u);
			mem_write16(a0 + 0x1Cu, 0x280u);
			if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
				mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
		}
	}
	else
	{
		mem_write16(a0 + 0x1Au, 0u);
		mem_write16(a0 + 0x1Cu, 0x280u);
		if ((int8_t)mem_read8(a0 + 0x2Bu) >= 0)
			mem_write16(a0 + 0x1Cu, 0u - mem_read16(a0 + 0x1Cu));
	}
	func_04826A(a0);
	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 == 1u || mem_read16(a0 + 0x2Eu) < 3u)
	{
		mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
		a6 = 0x5BF4Cu;
		set_animation(0u, a0, a6);
	}
	*p_d6 = (*p_d6 & 0xFFFF0000u) | (d6 & 0xFFFFu);
}

void func_0536CA(uint32_t a0)
{
	uint32_t a6 = 0;

	if (mem_read8(a0 + 0x33u) != 0u)
		return;
	mem_write8(a0 + 0x48u, 0xCu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5BF8Au;
	set_animation(0u, a0, a6);
}

void func_0536EA(uint32_t a0, uint32_t *p_d7, uint32_t *p_a5)
{
	uint16_t d7 = (uint16_t)*p_d7;
	uint32_t zero = 0;
	uint16_t d7_3 = 0;
	uint32_t a6 = 0, d7_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(a0, mem_read8(a0) & 0xBFu);
	if ((int8_t)(mem_read8(a0 + 0x2Bu) - 0x40u) < 0)
		mem_write8(a0, mem_read8(a0) | 0x40u);
	*p_a5 = 0x53622u;
	func_047C5A(a0, *p_a5, &d7_2, &a6, &zero);
	mem_write32(a6 + 0x24u, a0);
	d7_3 = (uint16_t)((d7_2 & ~0xFFu) | 0x1Cu);
	func_0091A4((uint8_t)d7_3, a6);
	mem_write8(a0 + 0x48u, 0x3Cu);
	mem_write8(a0 + 5u, mem_read8(a0 + 5u) + 1u);
	a6 = 0x5BFAEu;
	set_animation(0u, a0, a6);
	*p_d7 = (*p_d7 & 0xFFFF0000u) | d7_3;
}

void func_05373A(uint32_t a0)
{
	uint8_t t1 = 0;

	t1 = mem_read8(a0 + 0x48u);
	mem_write8(a0 + 0x48u, t1 - 1u);
	if (t1 == 1u)
	{
		unk_06123B = 0u;
		mem_write8(a0 + 0x45u, mem_read8(a0 + 0x45u) & ~1u);
		func_0485F6(a0);
	}
}
