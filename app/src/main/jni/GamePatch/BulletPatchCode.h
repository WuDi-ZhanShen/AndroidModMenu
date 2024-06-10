//
// Created by 19119 on 2022/9/1.
//

#ifndef PVZ_FREE_MENU_BULLETPATCHCODE_H
#define PVZ_FREE_MENU_BULLETPATCHCODE_H
#include "KittyMemory/MemoryPatch.h"



 bool isSelectedBullet = false;//是否固定子弹
 int  SelectBulletID = 1314;//选定的子弹ID

struct Bullet_Patches {
    MemoryPatch Pea,IcePea,Cabbage,Watermelon,Bubble,IceWatermelon,Homura,Star,Thorn,Core,Bomb,Butter,Nothing;

} BulletPatches;
struct FireTreeRandomBullet_Patches {
    MemoryPatch Pea,IcePea,Cabbage,Watermelon,Bubble,IceWatermelon,Homura,Star,Thorn,Core,Bomb,Butter,Nothing;
    MemoryPatch MustDoA,MustDoB;

} FireTreeBulletPatches;



void BulletSwitch(int Value){
    switch (Value) {
        case 1:
            isSelectedBullet = false;
            SelectBulletID = 1314;

            break;
        case 2:
            isSelectedBullet = true;
            SelectBulletID = 0;

            break;
        case 3:
            isSelectedBullet = true;
            SelectBulletID = 1;

            break;
        case 4:
            isSelectedBullet = true;
            SelectBulletID = 2;

            break;
        case 5:
            isSelectedBullet = true;
            SelectBulletID = 3;

            break;
        case 6:
            isSelectedBullet = true;
            SelectBulletID = 4;

            break;
        case 7:
            isSelectedBullet = true;
            SelectBulletID = 5;

            break;
        case 8:
            isSelectedBullet = true;
            SelectBulletID = 6;

            break;
        case 9:
            isSelectedBullet = true;
            SelectBulletID = 7;

            break;
        case 10:
            isSelectedBullet = true;
            SelectBulletID = 8;

            break;
        case 11:
            isSelectedBullet = true;
            SelectBulletID = 9;

            break;
        case 12:
            isSelectedBullet = true;
            SelectBulletID = 10;

            break;
        case 13:
            isSelectedBullet = true;
            SelectBulletID = 11;

            break;
        default:
            SelectBulletID = 1314;

            break;

    }


}


void RandomBulletTypeCode(){

        BulletPatches.Pea = MemoryPatch::createWithHex(targetLibName,
                                                       string2Offset(OBFUSCATE("0x5F0BD4")),
                                                       OBFUSCATE("00 40 A0 E3"));

        BulletPatches.IcePea = MemoryPatch::createWithHex(targetLibName,
                                                          string2Offset(OBFUSCATE("0x5F0BD4")),
                                                          OBFUSCATE("01 40 A0 E3"));

        BulletPatches.Cabbage = MemoryPatch::createWithHex(targetLibName,
                                                           string2Offset(OBFUSCATE("0x5F0BD4")),
                                                           OBFUSCATE("02 40 A0 E3"));

        BulletPatches.Watermelon = MemoryPatch::createWithHex(targetLibName,
                                                              string2Offset(OBFUSCATE("0x5F0BD4")),
                                                              OBFUSCATE("03 40 A0 E3"));

        BulletPatches.Bubble = MemoryPatch::createWithHex(targetLibName,
                                                          string2Offset(OBFUSCATE("0x5F0BD4")),
                                                          OBFUSCATE("04 40 A0 E3"));

        BulletPatches.IceWatermelon = MemoryPatch::createWithHex(targetLibName,
                                                                 string2Offset(OBFUSCATE("0x5F0BD4")),
                                                                 OBFUSCATE("05 40 A0 E3"));

        BulletPatches.Homura = MemoryPatch::createWithHex(targetLibName,
                                                          string2Offset(OBFUSCATE("0x5F0BD4")),
                                                          OBFUSCATE("06 40 A0 E3"));

        BulletPatches.Star = MemoryPatch::createWithHex(targetLibName,
                                                        string2Offset(OBFUSCATE("0x5F0BD4")),
                                                        OBFUSCATE("07 40 A0 E3"));

        BulletPatches.Thorn = MemoryPatch::createWithHex(targetLibName,
                                                         string2Offset(OBFUSCATE("0x5F0BD4")),
                                                         OBFUSCATE("08 40 A0 E3"));

        BulletPatches.Core = MemoryPatch::createWithHex(targetLibName,
                                                        string2Offset(OBFUSCATE("0x5F0BD4")),
                                                        OBFUSCATE("0A 40 A0 E3"));

        BulletPatches.Butter = MemoryPatch::createWithHex(targetLibName,
                                                          string2Offset(OBFUSCATE("0x5F0BD4")),
                                                          OBFUSCATE("0C 40 A0 E3"));

        BulletPatches.Bomb = MemoryPatch::createWithHex(targetLibName,
                                                        string2Offset(OBFUSCATE("0x5F0BD4")),
                                                        OBFUSCATE("0B 40 A0 E3"));


        BulletPatches.Nothing = MemoryPatch::createWithHex(targetLibName,
                                                           string2Offset(OBFUSCATE("0x5F0BD4")),
                                                           OBFUSCATE("1C 40 1B E5"));

}



void Call_BulletSwitch(int Geted_Num) {
    switch (Geted_Num) {

        case 0:

            BulletPatches.Pea.Modify();
            break;
        case 1:

            BulletPatches.IcePea.Modify();
            break;
        case 2:

            BulletPatches.Cabbage.Modify();
            break;
        case 3:

            BulletPatches.Watermelon.Modify();
            break;
        case 4:

            BulletPatches.Bubble.Modify();
            break;
        case 5:

            BulletPatches.IceWatermelon.Modify();
            break;
        case 6:

            BulletPatches.Homura.Modify();
            break;
        case 7:

            BulletPatches.Star.Modify();
            break;
        case 8:

            BulletPatches.Thorn.Modify();
            break;
        case 9:

            BulletPatches.Core.Modify();
            break;
        case 10:

            BulletPatches.Butter.Modify();
            break;
        case 11:

            BulletPatches.Bomb.Modify();
            break;


        default:

            BulletPatches.Nothing.Modify();
            break;


    };

}

//--------------------------------------------
void Call_FireTreeBulletPatchCode(){

        FireTreeBulletPatches.MustDoA = MemoryPatch::createWithHex(targetLibName,
                                                           string2Offset(OBFUSCATE("0x5F3A3C")),
                                                           OBFUSCATE("04 00 00 EA"));
        FireTreeBulletPatches.MustDoB = MemoryPatch::createWithHex(targetLibName,
                                                               string2Offset(OBFUSCATE("0x5F3A60")),
                                                               OBFUSCATE("00 F0 20 E3"));


        FireTreeBulletPatches.Pea = MemoryPatch::createWithHex(targetLibName,
                                                               string2Offset(OBFUSCATE("0x6331B8")),
                                                               OBFUSCATE("00 00 00 E3"));

        FireTreeBulletPatches.IcePea = MemoryPatch::createWithHex(targetLibName,
                                                                  string2Offset(OBFUSCATE("0x6331B8")),
                                                                  OBFUSCATE("01 00 00 E3"));

        FireTreeBulletPatches.Cabbage = MemoryPatch::createWithHex(targetLibName,
                                                                   string2Offset(OBFUSCATE("0x6331B8")),
                                                                   OBFUSCATE("02 00 00 E3"));

        FireTreeBulletPatches.Watermelon = MemoryPatch::createWithHex(targetLibName,
                                                                      string2Offset(OBFUSCATE("0x6331B8")),
                                                                      OBFUSCATE("03 00 00 E3"));

        FireTreeBulletPatches.Bubble = MemoryPatch::createWithHex(targetLibName,
                                                                  string2Offset(OBFUSCATE("0x6331B8")),
                                                                  OBFUSCATE("04 00 00 E3"));

        FireTreeBulletPatches.IceWatermelon = MemoryPatch::createWithHex(targetLibName,
                                                                         string2Offset(OBFUSCATE("0x6331B8")),
                                                                         OBFUSCATE("05 00 00 E3"));

        FireTreeBulletPatches.Homura = MemoryPatch::createWithHex(targetLibName,
                                                                  string2Offset(OBFUSCATE("0x6331B8")),
                                                                  OBFUSCATE("06 00 00 E3"));

        FireTreeBulletPatches.Star = MemoryPatch::createWithHex(targetLibName,
                                                                string2Offset(OBFUSCATE("0x6331B8")),
                                                                OBFUSCATE("07 00 00 E3"));

        FireTreeBulletPatches.Thorn = MemoryPatch::createWithHex(targetLibName,
                                                                 string2Offset(OBFUSCATE("0x6331B8")),
                                                                 OBFUSCATE("08 00 00 E3"));

        FireTreeBulletPatches.Core = MemoryPatch::createWithHex(targetLibName,
                                                                string2Offset(OBFUSCATE("0x6331B8")),
                                                                OBFUSCATE("0A 00 00 E3"));

        FireTreeBulletPatches.Butter = MemoryPatch::createWithHex(targetLibName,
                                                                  string2Offset(OBFUSCATE("0x6331B8")),
                                                                  OBFUSCATE("0C 00 00 E3"));

        FireTreeBulletPatches.Bomb = MemoryPatch::createWithHex(targetLibName,
                                                                string2Offset(OBFUSCATE("0x6331B8")),
                                                                OBFUSCATE("0B 00 00 E3"));


        FireTreeBulletPatches.Nothing = MemoryPatch::createWithHex(targetLibName,
                                                                   string2Offset(OBFUSCATE("0x6331B8")),
                                                                   OBFUSCATE("00 00 00 E3"));

}
void FireTreeRandomBulletSwitch(int RandomNum) {
    switch (RandomNum) {

        case 0:

            FireTreeBulletPatches.Pea.Modify();
            break;
        case 1:

            FireTreeBulletPatches.IcePea.Modify();
            break;
        case 2:

            FireTreeBulletPatches.Cabbage.Modify();
            break;
        case 3:

            FireTreeBulletPatches.Watermelon.Modify();
            break;
        case 4:

            FireTreeBulletPatches.Bubble.Modify();
            break;
        case 5:

            FireTreeBulletPatches.IceWatermelon.Modify();
            break;
        case 6:

            FireTreeBulletPatches.Homura.Modify();
            break;
        case 7:

            FireTreeBulletPatches.Star.Modify();
            break;
        case 8:

            FireTreeBulletPatches.Thorn.Modify();
            break;
        case 9:

            FireTreeBulletPatches.Core.Modify();
            break;
        case 10:

            FireTreeBulletPatches.Butter.Modify();
            break;
        case 11:

            FireTreeBulletPatches.Bomb.Modify();
            break;


        default:
            FireTreeBulletPatches.Nothing.Modify();
            break;


    };

}


#endif //PVZ_FREE_MENU_BULLETPATCHCODE_H