//
// Created by 19119 on 2022/9/1.
//

#ifndef PVZ_FREE_MENU_ZOMBIE_TYPE_H
#define PVZ_FREE_MENU_ZOMBIE_TYPE_H
#include <list>
#include <vector>
#include <cstring>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>

#include "KittyMemory/MemoryPatch.h"
#include <cstring>
#define targetLibName OBFUSCATE("libpvz.so")
#include <string>





struct PlantDoSpecial_Patches{

    MemoryPatch SuperBlover,SuperCherrybomb,IceJalapeno,SuperPotatomine,AngryUmbrella;

} PlantDoSpecialPatches;

void Call_SuperPlant(){


            PlantDoSpecialPatches.SuperBlover = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5FE2B4")),OBFUSCATE("05 00 00 EA"));
            PlantDoSpecialPatches.SuperCherrybomb = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5F29C0")),OBFUSCATE("5A 00 00 EA"));
            PlantDoSpecialPatches.IceJalapeno = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5F2BE8")),OBFUSCATE("20 00 00 EA"));
            PlantDoSpecialPatches.SuperPotatomine = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5F2E7C")),OBFUSCATE("00 F0 20 E3"));
            PlantDoSpecialPatches.AngryUmbrella = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5F2C5C")),OBFUSCATE("B3 FF FF EA"));

}

void SuperPlant(int GetedNumWWWWW){
    switch (GetedNumWWWWW) {


        case 1:
            PlantDoSpecialPatches.SuperBlover.Modify();
            break;
        case 2:
            PlantDoSpecialPatches.SuperCherrybomb.Modify();
            break;
        case 3:
            PlantDoSpecialPatches.IceJalapeno.Modify();
            break;
        case 4:
            PlantDoSpecialPatches.SuperPotatomine.Modify();
            break;
        case 5:
            PlantDoSpecialPatches.AngryUmbrella.Modify();
            break;
        default:
            PlantDoSpecialPatches.SuperBlover.Restore();
            PlantDoSpecialPatches.SuperCherrybomb.Restore();
            PlantDoSpecialPatches.IceJalapeno.Restore();
            PlantDoSpecialPatches.SuperPotatomine.Restore();
            PlantDoSpecialPatches.AngryUmbrella.Restore();
            break;

    }

}



















bool isSelectZombie = false;
int SelectZombieID = 1314;



struct Zombie_Patches{

    MemoryPatch Flag,Cone,Struct,Bucket,Paper,Iron,Rugby,DanceKing,DancePartner,PoolNormal,Dive,IceWagon,Sled,Dolphin,Clown;
    MemoryPatch Balloon,Miner,Bungee,Snowman,Snitch,Ladder,Basketball,Giant,Kid,ZombieKing,Pea,Nut,Pepper,MachineGun,Fool;
    MemoryPatch TallNut,AngryGiant;
    MemoryPatch Nothing;
} ZombiePatches;





void ZombieSelectSwitch(int Madoka){
    switch (Madoka) {
        case 0:
            isSelectZombie = false;
            SelectZombieID = 1314;
            break;
        case 1:
            isSelectZombie = true;
            SelectZombieID = 1;
            break;
        case 2:
            isSelectZombie = true;
            SelectZombieID = 2;
            break;
        case 3:
            isSelectZombie = true;
            SelectZombieID = 3;
            break;
        case 4:
            isSelectZombie = true;
            SelectZombieID = 4;
            break;
        case 5:
            isSelectZombie = true;
            SelectZombieID = 5;
            break;
        case 6:
            isSelectZombie = true;
            SelectZombieID = 6;
            break;
        case 7:
            isSelectZombie = true;
            SelectZombieID = 7;
            break;
        case 8:
            isSelectZombie = true;
            SelectZombieID = 8;
            break;
        case 9:
            isSelectZombie = true;
            SelectZombieID = 9;
            break;
        case 10:
            isSelectZombie = true;
            SelectZombieID = 10;
            break;
        case 11:
            isSelectZombie = true;
            SelectZombieID = 11;
            break;
        case 12:
            isSelectZombie = true;
            SelectZombieID = 12;
            break;
        case 13:
            isSelectZombie = false;
            SelectZombieID = 1314;

            break;
        case 14:
            isSelectZombie = true;
            SelectZombieID = 14;
            break;
        case 15:
            isSelectZombie = true;
            SelectZombieID = 15;
            break;
        case 16:
            isSelectZombie = true;
            SelectZombieID = 16;
            break;
        case 17:
            isSelectZombie = true;
            SelectZombieID = 17;
            break;
        case 18:
            isSelectZombie = true;
            SelectZombieID = 18;
            break;
        case 19:
            isSelectZombie = true;
            SelectZombieID = 19;
            break;
        case 20:
            isSelectZombie = true;
            SelectZombieID = 20;
            break;
        case 21:
            isSelectZombie = true;
            SelectZombieID = 21;
            break;
        case 22:
            isSelectZombie = true;
            SelectZombieID = 22;
            break;
        case 23:
            isSelectZombie = true;
            SelectZombieID = 23;
            break;
        case 24:
            isSelectZombie = true;
            SelectZombieID = 24;

        case 25:
            isSelectZombie = false;
            SelectZombieID = 1314;
            break;
        case 26:
            isSelectZombie = true;
            SelectZombieID = 26;
            break;
        case 27:
            isSelectZombie = true;
            SelectZombieID = 27;
            break;
        case 28:
            isSelectZombie = true;
            SelectZombieID = 28;
            break;
        case 29:
            isSelectZombie = true;
            SelectZombieID = 29;
            break;
        case 30:
            isSelectZombie = true;
            SelectZombieID = 30;
            break;
        case 31:
            isSelectZombie = true;
            SelectZombieID = 31;
            break;
        case 32:
            isSelectZombie = true;
            SelectZombieID = 32;
            break;
        default:
            isSelectZombie = false;
            SelectZombieID = 1314;
            break;


    }

}


//关卡难度

struct LevelDifficulty{


    //僵尸数量
    MemoryPatch ZombieCountAMin,ZombieCountBMin,ZombieCountCMin;
    MemoryPatch ZombieCountAMax,ZombieCountBMax,ZombieCountCMax;

    //锤僵尸僵尸数A为小波,B为大波
    MemoryPatch ZombiesCountGraveA,ZombiesCountGraveB;
    MemoryPatch GraveWarMustDoA,GraveWarMustDoB,GraveWarMustDoC,GraveWarMustDoD;
    MemoryPatch GraveWarZombiesCountSmallA,GraveWarZombiesCountSmallB,GraveWarZombiesCountSmallC,GraveWarZombiesCountBig;


    //波数
    //仅仅对挑战模式生效
    MemoryPatch ZombieWaveA,ZombieWaveB,ZombieWaveC,ZombieWaveD;



} LevelDifficultyPatches;

void Call_LevelDifficulty(){
//-----------------------每波数量-----------------------------------------------
//冒险模式第一次与第二次
    LevelDifficultyPatches.ZombieCountAMin = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A404")),OBFUSCATE("14 00 80 E2"));//20
    LevelDifficultyPatches.ZombieCountBMin = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A3EC")),OBFUSCATE("28 00 80 E2"));//40
    LevelDifficultyPatches.ZombieCountAMax = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A404")),OBFUSCATE("28 00 80 E2"));//40
    LevelDifficultyPatches.ZombieCountBMax = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A3EC")),OBFUSCATE("50 00 80 E2"));//80

    //排山倒海
    LevelDifficultyPatches.ZombieCountCMin = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A5B4")),OBFUSCATE("0A 00 00 E3"));
    LevelDifficultyPatches.ZombieCountCMax = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A5B4")),OBFUSCATE("50 00 00 E3"));

    //锤僵尸数目
    LevelDifficultyPatches.ZombiesCountGraveA = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D4")),OBFUSCATE("1E 30 00 E3"));
    LevelDifficultyPatches.ZombiesCountGraveB = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C744")),OBFUSCATE("3C 00 00 E3"));

    //墓碑闪击
    LevelDifficultyPatches.GraveWarZombiesCountSmallA = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D4")),OBFUSCATE("05 00 00 E3"));
    LevelDifficultyPatches.GraveWarZombiesCountSmallB = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D4")),OBFUSCATE("0A 30 00 E3"));
    LevelDifficultyPatches.GraveWarZombiesCountSmallC = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D4")),OBFUSCATE("14 30 00 E3"));
    LevelDifficultyPatches.GraveWarZombiesCountBig = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C744")),OBFUSCATE("50 00 00 E3"));



//--------------波数------------------------------------------------------------
    //锤僵尸
    LevelDifficultyPatches.ZombieWaveA = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x509F4C")),OBFUSCATE("50 00 00 E3"));
    //坚果保龄球,空袭,传送门,植物僵尸,隐形食脑者
    LevelDifficultyPatches.ZombieWaveB = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x509FC8")),OBFUSCATE("50 00 00 E3"));
    //其余常见挑战模式
    LevelDifficultyPatches.ZombieWaveC = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A080")),OBFUSCATE("50 00 00 E3"));
    LevelDifficultyPatches.ZombieWaveD = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50A098")),OBFUSCATE("50 00 00 E3"));



//-----------------墓碑闪击---------------------
    LevelDifficultyPatches.GraveWarMustDoA = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x509764")),OBFUSCATE("05 00 50 E3"));
    LevelDifficultyPatches.GraveWarMustDoB = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50C1C8")),OBFUSCATE("A6 00 00 EA"));
    LevelDifficultyPatches.GraveWarMustDoC = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x50C598")),OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
    LevelDifficultyPatches.GraveWarMustDoD = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54CC60")),OBFUSCATE("00 F0 20 E3"));


}

struct Grave_Zombie_Patches{

    MemoryPatch Flag,Cone,Struct,Bucket,Paper,Iron,Rugby,DanceKing,DancePartner,PoolNormal,Dive,IceWagon,Sled,Dolphin,Clown;
    MemoryPatch Balloon,Miner,Bungee,Snowman,Snitch,Ladder,Basketball,Giant,Kid,ZombieKing,Pea,Nut,Pepper,MachineGun,Fool;
    MemoryPatch TallNut,AngryGiant;
    MemoryPatch Nothing;
} GraveWarZombiesTypePatches;







bool IsBeatZombieMod = false;
bool ZombieWaveButt = false;
void LevelDifficultyModifyAndRestore(int GetedNumG){
    switch (GetedNumG) {

        case 1://冒险出怪量(少量)
            LevelDifficultyPatches.ZombieCountAMin.Modify();
            LevelDifficultyPatches.ZombieCountBMin.Modify();
            break;
        case 2://冒险出怪量(大量)
            LevelDifficultyPatches.ZombieCountAMax.Modify();
            LevelDifficultyPatches.ZombieCountBMax.Modify();
            break;

    //-------------------------
        case 3:////排山倒海出怪量(少量)
            LevelDifficultyPatches.ZombieCountCMin.Modify();
            break;
        case 4:////排山倒海出怪量(大量)
            LevelDifficultyPatches.ZombieCountCMax.Modify();
            break;

        case 5://锤僵尸大量

            LevelDifficultyPatches.ZombiesCountGraveA.Modify();
            LevelDifficultyPatches.ZombiesCountGraveB.Modify();
            break;
        case 6:

            break;






        default:
            ////冒险出怪量(少量)关闭
            LevelDifficultyPatches.ZombieCountAMin.Restore();
            LevelDifficultyPatches.ZombieCountBMin.Restore();
            ////冒险出怪量(大量)关闭
            LevelDifficultyPatches.ZombieCountAMax.Restore();
            LevelDifficultyPatches.ZombieCountBMax.Restore();

            ////排山倒海出怪量(少量)关闭
            LevelDifficultyPatches.ZombieCountCMin.Restore();
            ////排山倒海出怪量(大量)关闭
            LevelDifficultyPatches.ZombieCountCMax.Restore();
            //锤僵尸大量关闭
            LevelDifficultyPatches.ZombiesCountGraveA.Restore();
            LevelDifficultyPatches.ZombiesCountGraveB.Restore();
            break;





//波数
        case 9://波数
            LevelDifficultyPatches.ZombieWaveA.Modify();
            LevelDifficultyPatches.ZombieWaveB.Modify();
            LevelDifficultyPatches.ZombieWaveC.Modify();
            LevelDifficultyPatches.ZombieWaveD.Modify();
            break;
        case 10:
            LevelDifficultyPatches.ZombieWaveA.Restore();
            LevelDifficultyPatches.ZombieWaveB.Restore();
            LevelDifficultyPatches.ZombieWaveC.Restore();
            LevelDifficultyPatches.ZombieWaveD.Restore();
            break;




    }

}




bool UpGraveCountButt = false;
void GraveWarZobiesCount(int GetedNumXVJI){

    switch (GetedNumXVJI) {

        case 1:
            LevelDifficultyPatches.GraveWarZombiesCountSmallA.Modify();
            break;
        case 2:
            LevelDifficultyPatches.GraveWarZombiesCountSmallB.Modify();
            break;

        case 3:
            LevelDifficultyPatches.GraveWarZombiesCountSmallC.Modify();
            break;




        default:
            LevelDifficultyPatches.GraveWarZombiesCountSmallA.Restore();
            LevelDifficultyPatches.GraveWarZombiesCountSmallB.Restore();
            LevelDifficultyPatches.GraveWarZombiesCountSmallC.Restore();
            break;

    }


}

bool GraveWarButt = false;
void GraveZombieWarSwitch(int GetNumXXXX){
    switch (GetNumXXXX) {

        case 1:
            GraveWarZombiesTypePatches.Flag.Modify();
            break;
        case 2:
            GraveWarZombiesTypePatches.Cone.Modify();
            break;
        case 3:
            GraveWarZombiesTypePatches.Struct.Modify();
            break;
        case 4:
            GraveWarZombiesTypePatches.Bucket.Modify();
            break;
        case 5:
            GraveWarZombiesTypePatches.Paper.Modify();
            break;
        case 6:
            GraveWarZombiesTypePatches.Iron.Modify();
            break;
        case 7:
            GraveWarZombiesTypePatches.Rugby.Modify();
            break;
        case 8:
            GraveWarZombiesTypePatches.DanceKing.Modify();
            break;
        case 9:
            GraveWarZombiesTypePatches.DancePartner.Modify();
            break;
        case 10:
            GraveWarZombiesTypePatches.PoolNormal.Modify();
            break;
        case 11:
            GraveWarZombiesTypePatches.Dive.Modify();
            break;

        case 12:
            GraveWarZombiesTypePatches.IceWagon.Modify();
            break;
        case 13:
            GraveWarZombiesTypePatches.Sled.Modify();
            break;
        case 14:
            GraveWarZombiesTypePatches.Dolphin.Modify();
            break;
        case 15:
            GraveWarZombiesTypePatches.Clown.Modify();
            break;
        case 16:
            GraveWarZombiesTypePatches.Flag.Modify();
            break;
        case 17:
            GraveWarZombiesTypePatches.Flag.Modify();
            break;
        case 18:
            GraveWarZombiesTypePatches.Flag.Modify();
            break;
        case 19:
            GraveWarZombiesTypePatches.Snowman.Modify();
            break;
        case 20:
            GraveWarZombiesTypePatches.Flag.Modify();
            break;
        case 21:
            GraveWarZombiesTypePatches.Ladder.Modify();
            break;
        case 22:
            GraveWarZombiesTypePatches.Basketball.Modify();
            break;
        case 23:
            GraveWarZombiesTypePatches.Giant.Modify();
            break;
        case 24:
            GraveWarZombiesTypePatches.Kid.Modify();
            break;
        case 25:
            GraveWarZombiesTypePatches.Flag.Modify();
            break;
        case 26:
            GraveWarZombiesTypePatches.Pea.Modify();
            break;
        case 27:
            GraveWarZombiesTypePatches.Nut.Modify();
            break;
        case 28:
            GraveWarZombiesTypePatches.Pepper.Modify();
            break;
        case 29:
            GraveWarZombiesTypePatches.MachineGun.Modify();
            break;
        case 30:
            GraveWarZombiesTypePatches.Fool.Modify();
            break;
        case 31:
            GraveWarZombiesTypePatches.TallNut.Modify();
            break;
        case 32:
            GraveWarZombiesTypePatches.AngryGiant.Modify();
            break;

        case 1314:
            GraveWarZombiesTypePatches.Nothing.Modify();
            LevelDifficultyPatches.GraveWarMustDoA.Restore();
            LevelDifficultyPatches.GraveWarMustDoB.Restore();
            LevelDifficultyPatches.GraveWarMustDoC.Restore();
            LevelDifficultyPatches.GraveWarMustDoD.Restore();
            break;
        default:
            GraveWarZombiesTypePatches.Nothing.Modify();
            LevelDifficultyPatches.GraveWarMustDoA.Restore();
            LevelDifficultyPatches.GraveWarMustDoB.Restore();
            LevelDifficultyPatches.GraveWarMustDoC.Restore();
            LevelDifficultyPatches.GraveWarMustDoD.Restore();
            break;



    }


}


void Call_GraveWarZombieType(){



    GraveWarZombiesTypePatches.Flag = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("01 20 00 E3"));
    GraveWarZombiesTypePatches.Cone = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("02 20 00 E3"));
    GraveWarZombiesTypePatches.Struct = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("03 20 00 E3"));
    GraveWarZombiesTypePatches.Bucket = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("04 20 00 E3"));
    GraveWarZombiesTypePatches.Paper = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("05 20 00 E3"));
    GraveWarZombiesTypePatches.Iron = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("06 20 00 E3"));
    GraveWarZombiesTypePatches.Rugby = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("07 20 00 E3"));
    GraveWarZombiesTypePatches.DanceKing = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("08 20 00 E3"));
    GraveWarZombiesTypePatches.DancePartner = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("09 20 00 E3"));
    GraveWarZombiesTypePatches.PoolNormal = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("0A 20 00 E3"));
    GraveWarZombiesTypePatches.Dive = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("0B 20 00 E3"));
    GraveWarZombiesTypePatches.IceWagon = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("0C 20 00 E3"));
    GraveWarZombiesTypePatches.Sled = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("0D 20 00 E3"));
    GraveWarZombiesTypePatches.Dolphin = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("0E 20 00 E3"));
    GraveWarZombiesTypePatches.Clown = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("0F 20 00 E3"));
    GraveWarZombiesTypePatches.Snowman = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("13 20 00 E3"));
    GraveWarZombiesTypePatches.Ladder = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("15 20 00 E3"));
    GraveWarZombiesTypePatches.Basketball = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("16 20 00 E3"));
    GraveWarZombiesTypePatches.Giant = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("17 20 00 E3"));
    GraveWarZombiesTypePatches.Kid = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("18 20 00 E3"));
    GraveWarZombiesTypePatches.Pea = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("1A 20 00 E3"));
    GraveWarZombiesTypePatches.Nut = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("1B 20 00 E3"));
    GraveWarZombiesTypePatches.Pepper = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("1C 20 00 E3"));
    GraveWarZombiesTypePatches.MachineGun = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("1D 20 00 E3"));
    GraveWarZombiesTypePatches.Fool = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("1E 20 00 E3"));
    GraveWarZombiesTypePatches.TallNut = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("1F 20 00 E3"));
    GraveWarZombiesTypePatches.AngryGiant = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("20 20 00 E3"));


    GraveWarZombiesTypePatches.Nothing = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x54C6D0")),OBFUSCATE("00 20 00 E3"));

}









void ZombieTypePatchSwitch(int GetedTypeNum){


    switch (GetedTypeNum) {
        case 0:
            ZombiePatches.Nothing = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("03 20 A0 E1"));
            ZombiePatches.Nothing.Modify();

             break;

        case 1:
            ZombiePatches.Flag = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("01 20 A0 E3"));
            ZombiePatches.Flag.Modify();
             break;

        case 2:
            ZombiePatches.Cone = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("02 20 A0 E3"));
            ZombiePatches.Cone.Modify();
             break;

        case 3:
            ZombiePatches.Struct = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("03 20 A0 E3"));
            ZombiePatches.Struct.Modify();
             break;     
        
        case 4:
            ZombiePatches.Bucket = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("04 20 A0 E3"));
            ZombiePatches.Bucket.Modify();
           
             break;

        case 5:
            ZombiePatches.Paper = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("05 20 A0 E3"));           
            ZombiePatches.Paper.Modify();
           
             break;

        case 6:
            ZombiePatches.Iron = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("06 20 A0 E3"));          
            ZombiePatches.Iron.Modify();
            
             break;

        case 7:
            ZombiePatches.Rugby = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("07 20 A0 E3"));           
            ZombiePatches.Rugby.Modify();
            
             break;
        
        case 8:
            ZombiePatches.DanceKing = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("08 20 A0 E3"));
            ZombiePatches.DanceKing.Modify();
            
             break;

        case 9:
            ZombiePatches.DancePartner = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("09 20 A0 E3"));                
            ZombiePatches.DancePartner.Modify();
             break;

        case 10:
            ZombiePatches.PoolNormal = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("0A 20 A0 E3"));    
            ZombiePatches.PoolNormal.Modify();
           
             break;

        case 11:
            ZombiePatches.Dive = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("0B 20 A0 E3"));         
            ZombiePatches.Dive.Modify();
        
             break;     
        
        case 12:
            ZombiePatches.IceWagon = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("0C 20 A0 E3"));         
            ZombiePatches.IceWagon.Modify();
           
             break;

        case 13:
            /*
            ZombiePatches.Sled = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("0D 20 A0 E3"));
            ZombiePatches.Sled.Modify();
*/
     
             break;

        case 14:

            ZombiePatches.Dolphin = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("0E 20 A0 E3"));
            ZombiePatches.Dolphin.Modify();

             break;

        case 15:
            ZombiePatches.Clown = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("0F 20 A0 E3"));
            ZombiePatches.Clown.Modify();

             break;

        case 16:

            ZombiePatches.Balloon = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("10 20 A0 E3"));
            ZombiePatches.Balloon.Modify();


             break;

        case 17:
            ZombiePatches.Miner = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("11 20 A0 E3"));
            ZombiePatches.Miner.Modify();

             break;

        case 18:

            ZombiePatches.Bungee = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("12 20 A0 E3"));
            ZombiePatches.Bungee.Modify();


             break;

        case 19:
            ZombiePatches.Snowman = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("13 20 A0 E3"));
            ZombiePatches.Snowman.Modify();

             break;

        case 20:

            ZombiePatches.Snitch = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("14 20 A0 E3"));
            ZombiePatches.Snitch.Modify();

             break;

        case 21:
            ZombiePatches.Ladder = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("15 20 A0 E3"));
            ZombiePatches.Ladder.Modify();
             break;

        case 22:
            ZombiePatches.Basketball = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("16 20 A0 E3"));
            ZombiePatches.Basketball.Modify();
             break;

        case 23:
            ZombiePatches.Giant = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("17 20 A0 E3"));
            ZombiePatches.Giant.Modify();
             break;

        case 24:
            ZombiePatches.Kid = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("18 20 A0 E3"));
            ZombiePatches.Kid.Modify();
             break;

        case 25:
            ZombiePatches.ZombieKing = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("19 20 A0 E3"));
            ZombiePatches.ZombieKing.Modify();
             break;

        case 26:
            ZombiePatches.Pea = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("1A 20 A0 E3"));
            ZombiePatches.Pea.Modify();
             break;

        case 27:
            ZombiePatches.Nut = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("1B 20 A0 E3"));
            ZombiePatches.Nut.Modify();
             break;

        case 28:
            ZombiePatches.Pepper = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("1C 20 A0 E3"));
            ZombiePatches.Pepper.Modify();
             break;

        case 29:
            ZombiePatches.MachineGun = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("1D 20 A0 E3"));
            ZombiePatches.MachineGun.Modify();
             break;

        case 30:
            ZombiePatches.Fool = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("1E 20 A0 E3"));
            ZombiePatches.Fool.Modify();
             break;

        case 31:
            ZombiePatches.TallNut = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("1F 20 A0 E3"));
            ZombiePatches.TallNut.Modify();
             break;
        case 32:
            ZombiePatches.AngryGiant = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("20 20 A0 E3"));
            ZombiePatches.AngryGiant.Modify();
             break;

        default:
            ZombiePatches.Nothing = MemoryPatch::createWithHex(targetLibName, string2Offset(OBFUSCATE("0x5165E8")),OBFUSCATE("03 20 A0 E1"));
            ZombiePatches.Nothing.Modify();

            break;




    }



}







#endif //PVZ_FREE_MENU_ZOMBIE_TYPE_H
