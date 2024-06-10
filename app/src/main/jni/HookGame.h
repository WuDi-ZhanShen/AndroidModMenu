//
// Created by 19119 on 2023/2/17.
//
#pragma once
#ifndef PVZ_FREE_MENU_SIMPLE_HOOKGAME_H
#define PVZ_FREE_MENU_SIMPLE_HOOKGAME_H
//#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>

#include "ChangeFormation.h"


#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

#define targetLibName OBFUSCATE("libpvz.so")
typedef unsigned int _DWORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef long long __int64;
#define randomInt(a, b) (rand()%(b-a+1)+a)//指定范围随机数产生

//-----------------------------------------------
//游戏函数
unsigned int (*AddALadder)(void *instance, int x, int y);

int (*AddPlant)(void *instance, int x, int y, int SeedType, int theImitaterType);

int (*AddZombieInRow)(void *instance, int theZombieType, int theRow, int theFromWave);

int (*Plant_Die)(void *instance);

int (*AddSunMoneyInvolvedFunction)(__int64 a1, unsigned int a2, char a3);

void (*DieWithLoot)(__int64 Zombie_this);


//void (*ConvertToFireball)(void *instance, int aGridX);

//void (*PlayFoley)(void *instance, int theFoleyType);
//-----------------------------------------------

bool FormationButt;
int FormationBuild_x = 0;
int FormationBuild_y = 0;
bool IsRoofButt;
bool ClearAllPlant;
bool FormationDecideButt;
int ChangeFormationArr[30][9] = {{1314}};//布阵植物数组
//布阵建造普通植物韩束
void FormationBuildPlant(void *FormationBtn, int PlantArr[30][9]) {

    if (PlantArr[FormationBuild_y + 12][FormationBuild_x] != -1) {
        AddPlant(FormationBtn, FormationBuild_x, FormationBuild_y,
                 PlantArr[FormationBuild_y + 12][FormationBuild_x], 0);//荷叶建造
    }//建荷叶
    if (IsRoofButt && FormationBuild_y != 5) {
        AddPlant(FormationBtn, FormationBuild_x, FormationBuild_y, 33, 0);//花盆建造
    }//建造花盆
    if (PlantArr[FormationBuild_y][FormationBuild_x] != -1) {
        AddPlant(FormationBtn, FormationBuild_x, FormationBuild_y,
                 PlantArr[FormationBuild_y][FormationBuild_x], 0);//植物建造
    }//建普通植物
    if (PlantArr[FormationBuild_y + 6][FormationBuild_x] != -1) {
        AddPlant(FormationBtn, FormationBuild_x, FormationBuild_y,
                 PlantArr[FormationBuild_y + 6][FormationBuild_x], 0);//南瓜建造
    }//建南瓜

    if (PlantArr[FormationBuild_y + 18][FormationBuild_x] != -1) {
        AddPlant(FormationBtn, FormationBuild_x, FormationBuild_y, 35, 0);//咖啡豆建造
    }//建咖啡豆
    if (PlantArr[FormationBuild_y + 24][FormationBuild_x] != -1) {
        AddALadder(FormationBtn, FormationBuild_x, FormationBuild_y);//咖啡豆建造
    }//建梯子




    FormationBuild_x++;
    if (FormationBuild_x >= 9) {
        FormationBuild_y++;
        FormationBuild_x = 0;
    }
    if (FormationBuild_y > 5) {
        FormationButt = 0;
        IsRoofButt = 0;
        FormationDecideButt = 0;
        ChangeFormationArr[0][0] = 1314;
        FormationBuild_x = 0;
        FormationBuild_y = 0;

    }


}//



//-----------

//Board_类
int LadderX = 0;
int BuildPlantX = 0;
int BuildZombieX = 0;
int LadderY = 0;
int BuildPlantY = 0;
int BuildZombieY = 0;
bool DoneLadderBuild;
bool DonePlantBuild;
bool DoneZombieBuild;
void *Board_instanceBtn;
int ThePlantID = 0;
int TheZombieID = 0;
int BuildZombieCount = 1;
int TheZombieBuildRow = 0;
int Buildi = 0;
bool UniformPlace;
bool UniformPlacePool;
int UniformRow = 0;
int NowPlantCount = 0;//Board植物数
bool PassNowLevel;

void *FormationBtn;

int (*old_Board_Update)(void *instance);

int Board_Update(void *instance) {
    Board_instanceBtn = instance;
    if (instance != NULL) {
        NowPlantCount = *(int *) ((uint64_t)  instance + 0x15C);
        if (ClearAllPlant && NowPlantCount == 0) {
            ClearAllPlant = false;
        }

        if (PassNowLevel) {
            *(int *) ((uint64_t) instance + 0x5988) = 1;
            PassNowLevel = false;
        }


        //植物建造----------------
        if (FormationButt && FormationDecideButt) {
            if (ChangeFormationArr[0][0] != 1314) {
                FormationBuildPlant(instance, ChangeFormationArr);
            }
        }
        //-------------------------
        if (DoneLadderBuild) {
            AddALadder(instance, LadderX, LadderY);
            DoneLadderBuild = 0;
        }

        if (DonePlantBuild && ThePlantID != -1) {
            AddPlant(instance, BuildPlantX, BuildPlantY, ThePlantID, 0);
            DonePlantBuild = 0;
        }

        if (DoneZombieBuild && TheZombieID != -1) {
            if (Buildi > BuildZombieCount) {
                DoneZombieBuild = 0;
                return old_Board_Update(instance);
            }
            if (UniformPlace) {
                AddZombieInRow(instance, TheZombieID, UniformRow, 0);
                UniformRow++;
                Buildi++;
                if (UniformRow > 4) {
                    UniformRow = 0;
                }
            } else if (UniformPlacePool) {
                AddZombieInRow(instance, TheZombieID, UniformRow, 0);
                UniformRow++;
                Buildi++;
                if (UniformRow > 5) {
                    UniformRow = 0;
                }
            } else {
                AddZombieInRow(instance, TheZombieID, TheZombieBuildRow, 0);
                Buildi++;
            }

        }



        //-----------------------------------------

    }


    return old_Board_Update(instance);
}


//-------------------------------
/*
//Zombie类
void *Zombie_instanceBtn;

int (*old_Zombie_Update)(void *instance);

int Zombie_Update(void *instance) {
    Zombie_instanceBtn = instance;
    if (instance != NULL) { ;
    }
    return old_Zombie_Update(instance);
}
*/
//------------------------------------------------
//Plant_类
void *Plant_instanceBtn;

int (*old_Plant_Update)(void *instance);

int Plant_Update(void *instance) {
    Plant_instanceBtn = instance;
    if (instance != NULL) {
        if (ClearAllPlant) {
            Plant_Die(instance);
        }
    }
    return old_Plant_Update(instance);
}

//---------------------------------------------------

//--------------------------------------------------------------------------------------------------
//子弹分析,随机子弹实现
bool RandomBulletBUTT;
int BulletSpinnerChosenNum = -1;
bool IsOnlyPeaUseableButt;
bool BanCobCannonBullet,BanStar;

float (*old_ProjectileInitialize)(void *instance, int theX, int theY, int theRenderOrder, int theRow,
                            int theProjectileType);

float ProjectileInitialize(void *instance, int theX, int theY, int theRenderOrder, int theRow,
                           int theProjectileType) {

    if (instance != NULL) {
        if (theProjectileType == 11 || theProjectileType == 13 || theProjectileType == 9){
            return old_ProjectileInitialize(instance, theX, theY, theRenderOrder, theRow,
                                            theProjectileType);
        }
        if (theProjectileType == 7 && BanStar){
            return old_ProjectileInitialize(instance, theX, theY, theRenderOrder, theRow,
                                            theProjectileType);
        }
        if (IsOnlyPeaUseableButt && theProjectileType != 0) {
            return old_ProjectileInitialize(instance, theX, theY, theRenderOrder, theRow,
                                            theProjectileType);
        }
        if (BulletSpinnerChosenNum != -1) {
            theProjectileType = BulletSpinnerChosenNum;
        }
        if (RandomBulletBUTT) {
            theProjectileType = randomInt(1, 12);
        }
        if (theProjectileType == 11 && BanCobCannonBullet){
            theProjectileType = randomInt(1, 10);//同时降低好友玉米黄油的概率!!
        }
    }
    return old_ProjectileInitialize(instance, theX, theY, theRenderOrder, theRow,
                                    theProjectileType);
}

//---------------------------------------------------------------------------------------

//Board_AddPlant
bool PumpkinWithLadder;

int (*old_Board_AddPlant)(void *instance, int x, int y, int SeedType, int theImitaterType);

int Board_AddPlant(void *instance, int x, int y, int SeedType, int theImitaterType) {

    if (instance != NULL) {
        if (PumpkinWithLadder && SeedType == 30) {
            AddALadder(instance, x, y);
        }

    }
    return old_Board_AddPlant(instance, x, y, SeedType, theImitaterType);
}
//----------------------------------

bool CoinModButt;


int (*old_CoinNum)(void *instance);

int CoinMod(void *instance) {
    if (instance != NULL) {
        if (CoinModButt) {
            return (int) 131452;//游戏中该值被x10,即1314520
        }
    }
    return old_CoinNum(instance);
}


bool TakeSunButt;//阳光反加开关
int (*old_Board_TakeSunMoney)(void *instance, int theAmount);

int Board_TakeSunMoney(void *instance, int theAmount) {

    if (instance != NULL) {
        if (TakeSunButt) {
            theAmount = -theAmount;
        }
    }
    return old_Board_TakeSunMoney(instance, theAmount);
}

bool NoSunLimit = false;
int AddSunMoney(__int64 result, int a2) {

    if (result != NULL) {

        *(_DWORD *) (result + 22732) += a2;
        if (*(int *) (result + 22732) > 9990 && !NoSunLimit)
            *(_DWORD *) (result + 22732) = 9990;
        if (*(int *) (result + 22732) >= 8000
            && *(_QWORD *) (result + 280)
            && *(_DWORD *) (*(_QWORD *) (result + 280) + 3132LL) != 23) {
            result = AddSunMoneyInvolvedFunction(result, 9LL, 1LL);
        }
        return result;

    }
}

bool CoolDownSeedPacketButt;
__int64 Deactivate(__int64 result)
    {
        if (result != NULL) {
            *(_BYTE *) (result + 92) = 0;
            if (CoolDownSeedPacketButt){
                *(_BYTE *) (result + 92) = 1;
            }
            *(_DWORD *) (result + 56) = 0;
            *(_DWORD *) (result + 60) = 0;
            *(_BYTE *) (result + 93) = 0;
            return result;
        }
    }


bool AutoCollect;
int (*old_UpdateFall)(void *instance);
int UpdateFall(void *instance) {

    if (instance != NULL) {
        if (AutoCollect) {
            *(_BYTE *) ((uint64_t) instance + 108) = 1;
        }
    }
    return old_UpdateFall(instance);
}

bool FreePlantAt;
int (*old_CanPlantAt)(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4, char a5);

int CanPlantAt(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4, char a5) {

    if (a1 != NULL) {
        if (FreePlantAt) {
            return 0; // 0<==>PLANTING_OK
        }
    }
    return old_CanPlantAt(a1, a2, a3, a4, a5);
}

bool PurpleCardNoLimit;
int (*old_PlantingRequirementsMet)(__int64 a1, int a2);
int PlantingRequirementsMet(__int64 a1, int a2) {

    if (a1 != NULL) {
        if (PurpleCardNoLimit){
            return 1;
        }
    }
    return old_PlantingRequirementsMet(a1, a2);
}


bool ZombieCanNotWon = false;
void (*old_BoardZombiesWon)(__int64 _this, __int64 Zombie_this);

void BoardZombiesWon(__int64 _this, __int64 Zombie_this) {

    if (_this != NULL && Zombie_this != NULL) {
        if (ZombieCanNotWon) {
            DieWithLoot(Zombie_this);
            return;
        }
    }
    return old_BoardZombiesWon(_this, Zombie_this);
}

bool FungusNoSleeping = false;
void (*old_SetSleeping)(_QWORD *a1, char a2);

void SetSleeping(_QWORD *a1, char a2) {

    if (a1 != NULL) {
        if (FungusNoSleeping) {
            a2 = 0LL;
        }
    }
    return old_SetSleeping(a1, a2);
}

bool FreeBonusGame(__int64 a1) {
    if (a1 != NULL) {
        return true;
    }
}


//--------------------------------------------------------------------------------------------------------------------

void CallHookGame() {
    //HOOK

    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x740754),
                   (void *) ProjectileInitialize, (void **) &old_ProjectileInitialize);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x631878), (void *) Board_AddPlant,
                   (void **) &old_Board_AddPlant);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x6366E4), (void *) Board_TakeSunMoney,
                   (void **) &old_Board_TakeSunMoney);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x64D634), (void *) AddSunMoney, NULL);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x7D8BFC), (void *) Deactivate, NULL);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x671218),
                    (void *) UpdateFall, (void **) &old_UpdateFall);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x63280C),
                    (void *) CanPlantAt, (void **) &old_CanPlantAt);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x64FEBC),
                    (void *) PlantingRequirementsMet, (void **) &old_PlantingRequirementsMet);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x63D77C),
                    (void *) BoardZombiesWon, (void **) &old_BoardZombiesWon);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x6FDD74),
                    (void *) SetSleeping, (void **) &old_SetSleeping);
    A64HookFunction((void *) getAbsoluteAddress(targetLibName, 0x6AB718), (void *) FreeBonusGame, NULL);

    HOOK_LIB("libpvz.so", "0x640DB4", Board_Update, old_Board_Update);

    HOOK_LIB("libpvz.so", "0x709060", Plant_Update, old_Plant_Update);
    //HOOK_LIB("libpvz.so", "", Zombie_Update, old_Zombie_Update);
    HOOK_LIB("libpvz.so", "0x71FD5C", CoinMod, old_CoinNum);
    //游戏函数
    AddALadder = (unsigned int (*)(void *, int, int)) getAbsoluteAddress(targetLibName, 0x627DDC);
    AddPlant = (int (*)(void *, int, int, int, int)) getAbsoluteAddress(targetLibName, 0x631878);
    AddZombieInRow = (int (*)(void *, int, int, int)) getAbsoluteAddress(targetLibName, 0x633E20);
    Plant_Die = (int (*)(void *)) getAbsoluteAddress(targetLibName, 0x6FEBB8);
    AddSunMoneyInvolvedFunction = (int (*)(__int64, unsigned int, char)) getAbsoluteAddress(targetLibName, 0x62F098);//非真正函数名
    DieWithLoot = (void (*)(__int64 )) getAbsoluteAddress(targetLibName, 0x7FAECC);


}


void GetedChangeFormationID(int Madoka) {

    switch (Madoka) {
        case -1:
            ChangeFormationArr[0][0] = 1314;
            IsRoofButt = 0;
            FormationButt = 0;

            break;
        case 0:
            memcpy(ChangeFormationArr, PE电波钟无炮, sizeof(PE电波钟无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 1:
            memcpy(ChangeFormationArr, PE最简无炮, sizeof(PE最简无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 2:
            memcpy(ChangeFormationArr, PE伪无伤无炮, sizeof(PE伪无伤无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 3:
            memcpy(ChangeFormationArr, PE自然控丑无炮, sizeof(PE自然控丑无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;


        case 4:
            memcpy(ChangeFormationArr, PE火焰无炮, sizeof(PE火焰无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 5:
            memcpy(ChangeFormationArr, PE分裂火焰无炮, sizeof(PE分裂火焰无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 6:
            memcpy(ChangeFormationArr, PE后退无炮, sizeof(PE后退无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 7:
            memcpy(ChangeFormationArr, PE超前置无炮, sizeof(PE超前置无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 8:
            memcpy(ChangeFormationArr, PE王子无炮, sizeof(PE王子无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 9:
            memcpy(ChangeFormationArr, PE机械钟无炮, sizeof(PE机械钟无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 10:
            memcpy(ChangeFormationArr, PE神之无炮, sizeof(PE神之无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 11:
            memcpy(ChangeFormationArr, PE石英钟无炮, sizeof(PE石英钟无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;


        case 12:
            memcpy(ChangeFormationArr, PE靠天无炮, sizeof(PE靠天无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 13:
            memcpy(ChangeFormationArr, PE方块无神无炮, sizeof(PE方块无神无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 14:
            memcpy(ChangeFormationArr, PE56加速无神无炮, sizeof(PE56加速无神无炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 15:
            memcpy(ChangeFormationArr, PE压制一炮, sizeof(PE压制一炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 16:
            memcpy(ChangeFormationArr, PE小二炮, sizeof(PE小二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 17:
            memcpy(ChangeFormationArr, PE火焰二炮, sizeof(PE火焰二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 18:
            memcpy(ChangeFormationArr, PE核武二炮, sizeof(PE核武二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 19:
            memcpy(ChangeFormationArr, PE分裂二炮, sizeof(PE分裂二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 20:
            memcpy(ChangeFormationArr, PE方正二炮, sizeof(PE方正二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;


        case 21:
            memcpy(ChangeFormationArr, PE经典二炮, sizeof(PE经典二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 22:
            memcpy(ChangeFormationArr, PE冲关三炮, sizeof(PE冲关三炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 23:
            memcpy(ChangeFormationArr, PE太极四炮, sizeof(PE太极四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 24:
            memcpy(ChangeFormationArr, PE全金属四炮, sizeof(PE全金属四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 25:
            memcpy(ChangeFormationArr, PE方块四炮, sizeof(PE方块四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 26:
            memcpy(ChangeFormationArr, PE青四炮, sizeof(PE青四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 27:
            memcpy(ChangeFormationArr, PE水路无植物四炮, sizeof(PE水路无植物四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 28:
            memcpy(ChangeFormationArr, PE方四炮, sizeof(PE方四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;


        case 29:
            memcpy(ChangeFormationArr, PE神之四炮, sizeof(PE神之四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 30:
            memcpy(ChangeFormationArr, PE双核底线四炮, sizeof(PE双核底线四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 31:
            memcpy(ChangeFormationArr, PE经典四炮, sizeof(PE经典四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 32:
            memcpy(ChangeFormationArr, PE火焰四炮, sizeof(PE火焰四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 33:
            memcpy(ChangeFormationArr, PE底线四炮, sizeof(PE底线四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 34:
            memcpy(ChangeFormationArr, PE传统四炮, sizeof(PE传统四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 35:
            memcpy(ChangeFormationArr, PE半场无植物五炮, sizeof(PE半场无植物五炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 36:
            memcpy(ChangeFormationArr, PE散炸五炮, sizeof(PE散炸五炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 37:
            memcpy(ChangeFormationArr, PE心五炮, sizeof(PE心五炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 38:
            memcpy(ChangeFormationArr, PE陆路无植物六炮, sizeof(PE陆路无植物六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 39:
            memcpy(ChangeFormationArr, PE水路无植物六炮, sizeof(PE水路无植物六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 40:
            memcpy(ChangeFormationArr, PE青苔六炮, sizeof(PE青苔六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 41:
            memcpy(ChangeFormationArr, PE禅房花木深, sizeof(PE禅房花木深));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 42:
            memcpy(ChangeFormationArr, PE神之六炮, sizeof(PE神之六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 43:
            memcpy(ChangeFormationArr, PE玉米六炮, sizeof(PE玉米六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 44:
            memcpy(ChangeFormationArr, PE空炸六炮, sizeof(PE空炸六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 45:
            memcpy(ChangeFormationArr, PE超后置六炮, sizeof(PE超后置六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 46:
            memcpy(ChangeFormationArr, PE方六炮, sizeof(PE方六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 47:
            memcpy(ChangeFormationArr, PE蝶韵, sizeof(PE蝶韵));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 48:
            memcpy(ChangeFormationArr, PE一勺汤圆, sizeof(PE一勺汤圆));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 49:
            memcpy(ChangeFormationArr, PE间隔无植物七炮, sizeof(PE间隔无植物七炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 50:
            memcpy(ChangeFormationArr, PE玉兔茕茕, sizeof(PE玉兔茕茕));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 51:
            memcpy(ChangeFormationArr, PE无保护八炮, sizeof(PE无保护八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 52:
            memcpy(ChangeFormationArr, PE树八炮, sizeof(PE树八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 53:
            memcpy(ChangeFormationArr, PE全对称树八炮, sizeof(PE全对称树八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 54:
            memcpy(ChangeFormationArr, PE矩形八炮, sizeof(PE矩形八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 55:
            memcpy(ChangeFormationArr, PE神之八炮, sizeof(PE神之八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;

        case 56:
            memcpy(ChangeFormationArr, PE阴阳八炮, sizeof(PE阴阳八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 57:
            memcpy(ChangeFormationArr, PE浮萍八炮, sizeof(PE浮萍八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 58:
            memcpy(ChangeFormationArr, PE后置八炮, sizeof(PE后置八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 59:
            memcpy(ChangeFormationArr, PE饲养海豚, sizeof(PE饲养海豚));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 60:
            memcpy(ChangeFormationArr, PE玉米八炮, sizeof(PE玉米八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 61:
            memcpy(ChangeFormationArr, PE经典八炮, sizeof(PE经典八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 62:
            memcpy(ChangeFormationArr, PE花海八炮, sizeof(PE花海八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 63:
            memcpy(ChangeFormationArr, PEC2八炮, sizeof(PEC2八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 64:
            memcpy(ChangeFormationArr, PE分离八炮, sizeof(PE分离八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 65:
            memcpy(ChangeFormationArr, PE全对称八炮, sizeof(PE全对称八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 66:
            memcpy(ChangeFormationArr, PE3C八炮, sizeof(PE3C八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 67:
            memcpy(ChangeFormationArr, PE灯台八炮, sizeof(PE灯台八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 68:
            memcpy(ChangeFormationArr, PE9炮, sizeof(PE9炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 69:
            memcpy(ChangeFormationArr, PE方块九炮, sizeof(PE方块九炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 70:
            memcpy(ChangeFormationArr, PEC6i九炮, sizeof(PEC6i九炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 71:
            memcpy(ChangeFormationArr, PE心九炮, sizeof(PE心九炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 72:
            memcpy(ChangeFormationArr, PE轮炸九炮, sizeof(PE轮炸九炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 73:
            memcpy(ChangeFormationArr, PE2炮, sizeof(PE2炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 74:
            memcpy(ChangeFormationArr, PE六芒星十炮, sizeof(PE六芒星十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 75:
            memcpy(ChangeFormationArr, PE六边形十炮, sizeof(PE六边形十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 76:
            memcpy(ChangeFormationArr, PE方块十炮, sizeof(PE方块十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 77:
            memcpy(ChangeFormationArr, PE斜方十炮, sizeof(PE斜方十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 78:
            memcpy(ChangeFormationArr, PE简化十炮, sizeof(PE简化十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 79:
            memcpy(ChangeFormationArr, PE后置十炮, sizeof(PE后置十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 80:
            memcpy(ChangeFormationArr, PE经典十炮, sizeof(PE经典十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 81:
            memcpy(ChangeFormationArr, PE六线囚尸, sizeof(PE六线囚尸));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 82:
            memcpy(ChangeFormationArr, PE斜十炮, sizeof(PE斜十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 83:
            memcpy(ChangeFormationArr, PE魔方十炮, sizeof(PE魔方十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 84:
            memcpy(ChangeFormationArr, PE戴夫的小汉堡, sizeof(PE戴夫的小汉堡));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 85:
            memcpy(ChangeFormationArr, PE鸡尾酒, sizeof(PE鸡尾酒));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 86:
            memcpy(ChangeFormationArr, PE一勺汤圆十二炮, sizeof(PE一勺汤圆十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 87:
            memcpy(ChangeFormationArr, PE玉壶春十二炮, sizeof(PE玉壶春十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 88:
            memcpy(ChangeFormationArr, PE半场十二炮, sizeof(PE半场十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 89:
            memcpy(ChangeFormationArr, PE简化十二炮, sizeof(PE简化十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 90:
            memcpy(ChangeFormationArr, PE经典十二炮, sizeof(PE经典十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 91:
            memcpy(ChangeFormationArr, PE火焰十二炮, sizeof(PE火焰十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 92:
            memcpy(ChangeFormationArr, PE冰雨十二炮·改, sizeof(PE冰雨十二炮·改));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 93:
            memcpy(ChangeFormationArr, PE冰雨十二炮·改改, sizeof(PE冰雨十二炮·改改));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 94:
            memcpy(ChangeFormationArr, PE单紫卡十二炮, sizeof(PE单紫卡十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 95:
            memcpy(ChangeFormationArr, PE神柱十二炮, sizeof(PE神柱十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 96:
            memcpy(ChangeFormationArr, PE神之十二炮, sizeof(PE神之十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 97:
            memcpy(ChangeFormationArr, PE水路无植物十二炮, sizeof(PE水路无植物十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 98:
            memcpy(ChangeFormationArr, PE纯白悬空十二炮, sizeof(PE纯白悬空十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 99:
            memcpy(ChangeFormationArr, PE后花园十二炮, sizeof(PE后花园十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 100:
            memcpy(ChangeFormationArr, PE玉米十二炮, sizeof(PE玉米十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 101:
            memcpy(ChangeFormationArr, PE两路狂暴, sizeof(PE两路狂暴));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 102:
            memcpy(ChangeFormationArr, PE九列十二炮, sizeof(PE九列十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 103:
            memcpy(ChangeFormationArr, PE梯曾十二炮, sizeof(PE梯曾十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 104:
            memcpy(ChangeFormationArr, PE君海十二炮, sizeof(PE君海十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 105:
            memcpy(ChangeFormationArr, PE箜篌引, sizeof(PE箜篌引));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 106:
            memcpy(ChangeFormationArr, PE梅花十三, sizeof(PE梅花十三));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 107:
            memcpy(ChangeFormationArr, PE最后之作, sizeof(PE最后之作));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 108:
            memcpy(ChangeFormationArr, PE冰心灯, sizeof(PE冰心灯));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 109:
            memcpy(ChangeFormationArr, PE太极十四炮, sizeof(PE太极十四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 110:
            memcpy(ChangeFormationArr, PE真·四炮, sizeof(PE真·四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 111:
            memcpy(ChangeFormationArr, PE神棍十四炮, sizeof(PE神棍十四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 112:
            memcpy(ChangeFormationArr, PE神之十四炮, sizeof(PE神之十四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 113:
            memcpy(ChangeFormationArr, PE穿越十四炮, sizeof(PE穿越十四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 114:
            memcpy(ChangeFormationArr, PE钻石十五炮, sizeof(PE钻石十五炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 115:
            memcpy(ChangeFormationArr, PE神之十五炮, sizeof(PE神之十五炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 116:
            memcpy(ChangeFormationArr, PE真·二炮, sizeof(PE真·二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 117:
            memcpy(ChangeFormationArr, PE冰箱灯, sizeof(PE冰箱灯));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 118:
            memcpy(ChangeFormationArr, PE炮环十二花, sizeof(PE炮环十二花));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 119:
            memcpy(ChangeFormationArr, PE单冰十六炮, sizeof(PE单冰十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 120:
            memcpy(ChangeFormationArr, PE对称十六炮, sizeof(PE对称十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 121:
            memcpy(ChangeFormationArr, PE神之十六炮, sizeof(PE神之十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 122:
            memcpy(ChangeFormationArr, PE裸奔十六炮, sizeof(PE裸奔十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 123:
            memcpy(ChangeFormationArr, PE双冰十六炮, sizeof(PE双冰十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 124:
            memcpy(ChangeFormationArr, PE超前置十六炮, sizeof(PE超前置十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 125:
            memcpy(ChangeFormationArr, PE火焰十六炮, sizeof(PE火焰十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 126:
            memcpy(ChangeFormationArr, PE经典十六炮, sizeof(PE经典十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 127:
            memcpy(ChangeFormationArr, PE折线十六炮, sizeof(PE折线十六炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 128:
            memcpy(ChangeFormationArr, PE肺十八炮_极限, sizeof(PE肺十八炮_极限));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 129:
            memcpy(ChangeFormationArr, PE纯十八炮, sizeof(PE纯十八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 130:
            memcpy(ChangeFormationArr, PE真·十八炮, sizeof(PE真·十八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 131:
            memcpy(ChangeFormationArr, PE冰魄十八炮, sizeof(PE冰魄十八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 132:
            memcpy(ChangeFormationArr, PE尾炸十八炮, sizeof(PE尾炸十八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 133:
            memcpy(ChangeFormationArr, PE经典十八炮, sizeof(PE经典十八炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 134:
            memcpy(ChangeFormationArr, PE纯二十炮, sizeof(PE空炸二十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 135:
            memcpy(ChangeFormationArr, PE空炸二十炮, sizeof(PE空炸二十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 136:
            memcpy(ChangeFormationArr, PE钉耙二十炮, sizeof(PE钉耙二十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 137:
            memcpy(ChangeFormationArr, PE新二十炮, sizeof(PE新二十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 138:
            memcpy(ChangeFormationArr, PE无冰瓜二十炮, sizeof(PE无冰瓜二十炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 139:
            memcpy(ChangeFormationArr, PE绝望之路, sizeof(PE绝望之路));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 140:
            memcpy(ChangeFormationArr, PE二十一炮, sizeof(PE二十一炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 141:
            memcpy(ChangeFormationArr, PE新二十二炮, sizeof(PE新二十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 142:
            memcpy(ChangeFormationArr, PE二十二炮, sizeof(PE二十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 143:
            memcpy(ChangeFormationArr, PE无冰瓜二十二炮, sizeof(PE无冰瓜二十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 144:
            memcpy(ChangeFormationArr, PE九列二十二炮, sizeof(PE九列二十二炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 145:
            memcpy(ChangeFormationArr, PE二十四炮, sizeof(PE二十四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 146:
            memcpy(ChangeFormationArr, PE垫材二十四炮, sizeof(PE垫材二十四炮));
            IsRoofButt = 0;
            FormationButt = 1;
            break;
        case 147:
            memcpy(ChangeFormationArr, PE胆守_极限, sizeof(PE胆守_极限));
            IsRoofButt = 0;
            FormationButt = 1;
            break;


    }


}



#endif //PVZ_FREE_MENU_SIMPLE_HOOKGAME_H
