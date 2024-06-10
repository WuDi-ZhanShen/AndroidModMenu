//
// Created by 19119 on 2022/9/2.
//

#ifndef PVZ_FREE_MENU_GAMEHOOK_H
#define PVZ_FREE_MENU_GAMEHOOK_H
#define targetLibName OBFUSCATE("libpvz.so")
#include "Includes/Macros.h"
#include "GamePatch/GamePatch.h"


bool RandomBulletAButt = false;//A全随机
bool RandomBulletBButt = false;//B无炮随机

bool RandomZombieAButt = false;
bool ZombieKingButt = false;
bool RandomPlantZombieButt = false;
bool RandomIronZombieButt = false;
bool BulletPenetrationButt = false;
bool FireTreeBulletButt = false;
bool BulletRetentionButt = false;//子弹滞留


void Bullet(int CkNumInput){
    int CkNum = CkNumInput;
    Call_BulletSwitch(CkNum);

}


void (*old_PlantState)(void *instance);
void PlantStateMod(void *instance) {

    if (instance != NULL) {
//***********************************************************
        //int NowPlantID =  *(int *)((uint64_t)instance + 0x30);//当前植物ID

        //------------------------------


            if (RandomBulletAButt != 0 && RandomBulletBButt == 0) {

                int CkNumOutputA;

                labelRandomBulletA:
                CkNumOutputA = (int) ((random() / (1.0 + RAND_MAX)) * (11 - 0 + 1) + 0);
                if (CkNumOutputA == 3 || CkNumOutputA == 5 || CkNumOutputA == 11 || CkNumOutputA == 10){
                    //设为1/2
                    int CkA = (int) ((random() / (1.0 + RAND_MAX)) * (2 - 0 + 1) + 0);
                    if (CkA == 1){
                        CkNumOutputA = CkNumOutputA;
                    }else{
                        goto labelRandomBulletA;
                    }
                }

                Bullet(CkNumOutputA);

            } else if (RandomBulletBButt != 0 && RandomBulletAButt == 0) {
                int CkNumOutputB;
                labelRandomBulletB:
                CkNumOutputB = (int) ((random() / (1.0 + RAND_MAX)) * (10 - 0 + 1) + 0);
                if (CkNumOutputB == 3 || CkNumOutputB == 5 || CkNumOutputB == 10) {
                    //设为1/2
                    int CkB = (int) ((random() / (1.0 + RAND_MAX)) * (2 - 0 + 1) + 0);
                    if (CkB == 1) {
                        CkNumOutputB = CkNumOutputB;
                    } else {
                        goto labelRandomBulletB;
                    }
                }
                Bullet(CkNumOutputB);
            }

        if (isSelectedBullet != 0 && RandomBulletAButt == 0 && RandomBulletBButt == 0){
            Bullet(SelectBulletID);
        }
        if (isSelectedBullet == 0 && RandomBulletAButt == 0 && RandomBulletBButt == 0){
            Bullet(1314);
        }
        //判断子弹
//***********************************************************

//火炬树随机子弹
        if (FireTreeBulletButt != 0){
           labelA: int FireRandomOutNum = (int) ((random() / (1.0 + RAND_MAX)) * (11 - 0 + 1) + 0);
            if (FireRandomOutNum == 3 || FireRandomOutNum == 5 || FireRandomOutNum == 11){
                int ThisRandomOutNum = (int) ((random() / (1.0 + RAND_MAX)) * (3 - 0 + 1) + 0);
                if (ThisRandomOutNum == 1){
                    FireTreeRandomBulletSwitch(FireRandomOutNum);
                }else{
                    goto labelA;
                }
            }
            FireTreeRandomBulletSwitch(FireRandomOutNum);
        }

//子弹滞留
        if (BulletRetentionButt != 0){
            int TheRandomReRetentionNum = (int) ((random() / (1.0 + RAND_MAX)) * (3 - 0 + 1) + 0);
            if (TheRandomReRetentionNum == 3){
                PatchHomura.BulletRetention.Restore();
            }else{
                PatchHomura.BulletRetention.Modify();
            }
        }else{
            PatchHomura.BulletRetention.Restore();
        }


    }
    return old_PlantState(instance);
}

//--------------------------------------------
bool CoinModButt;
int (*old_CoinNum)(void *instance);
int  CoinMod(void *instance) {
    if (instance != NULL) {
        if (CoinModButt) {
            return (int) 131452;//游戏中该值被x10,即1314520
        }
    }
    return old_CoinNum(instance);
}//金币设置-----无控制---强制


//--------------------------------------------
//--------------------------------------------

int (*old_ZombieType)(void *instance);
int  ZombieTypeMod(void *instance) {
    if (instance != NULL) {

//-------------------------------------------------
        if (RandomZombieAButt != 0 && RandomIronZombieButt == 0 && RandomPlantZombieButt == 0){
            int RandomZombieNumA;
            RandomZombieNumA = (int)((random()/(1.0+RAND_MAX))*(32-0)+0+1);
            if (RandomZombieNumA != 25) {
                ZombieTypePatchSwitch(RandomZombieNumA);
            }
            if (RandomZombieNumA == 25){

                ZombieTypePatchSwitch(7);

            }

        }
        //全僵尸随机
        //----------------------------------------------
        if (ZombieKingButt != 0){

            ZombieTypePatchSwitch(25);

        }
        //僵王召唤
        //----------------------------------------------------
        if (RandomPlantZombieButt != 0 && RandomZombieAButt == 0 && RandomIronZombieButt == 0){
            int  PlantZombieID[8] = {26,27,28,29,30,31,29,29};
            int  UsedPlantZombieID = (int)((random()/(1.0+RAND_MAX))*(7-0+1)+0);
            ZombieTypePatchSwitch(PlantZombieID[UsedPlantZombieID]);

        }

        //植物僵尸
//_______________________________
        if (RandomIronZombieButt != 0 && RandomPlantZombieButt == 0 && RandomZombieAButt == 0){
            int  IronZombieID[6] = {4,6,7,12,32,23};
            int  UsedIronZombieID = (int)((random()/(1.0+RAND_MAX))*(5-0+1)+0);
            ZombieTypePatchSwitch(IronZombieID[UsedIronZombieID]);
        }


        //铁铁僵尸
//----------------------------
        if (isSelectZombie != 0 && RandomZombieAButt == 0 && RandomPlantZombieButt == 0 && RandomIronZombieButt == 0 && ZombieKingButt == 0){
            ZombieTypePatchSwitch(SelectZombieID);
        }


//------------------------------

        if (isSelectZombie == 0 && RandomZombieAButt == 0 && RandomPlantZombieButt == 0 && RandomIronZombieButt == 0 && ZombieKingButt == 0){
            ZombieTypePatchSwitch(0);

        }

    }
    return old_ZombieType(instance);
}//僵尸类型

//----------------------------------------------------------------
void (*old_IsSplashDamage)(void *instance);
void  IsSplashDamageMod(void *instance) {
    if (instance != NULL) {

        if (BulletPenetrationButt != 0) {
            PatchHomura.BulletPenetration.Modify();
        }

        int  RandomClose = (int)((random()/(1.0+RAND_MAX))*(30-0+1)+0);
        if (RandomClose == 10){
            PatchHomura.BulletPenetration.Restore();//  1/30概率消失子弹，以正常运行
        }


    } else{
        PatchHomura.BulletPenetration.Restore();
    }
    return old_IsSplashDamage(instance);
}//子弹是否溅射方法(改子弹穿帧)

//------------------------------------------
void (*old_GraveWar)(void *instance);
void  GraveWarMod(void *instance) {
    if (instance != NULL) {
        if (GraveWarButt != 0){

            int  RandomZombieNum = (int)((random()/(1.0+RAND_MAX))*(32-1+1)+1);
            GraveZombieWarSwitch(RandomZombieNum);
        }
        if (UpGraveCountButt != 0){
            int  RandomZombieCountNum = (int)((random()/(1.0+RAND_MAX))*(3-1+1)+1);
            GraveWarZobiesCount(RandomZombieCountNum);
        }





    }
    return old_GraveWar(instance);
}//墓碑闪击




//---------------------------------------------


void CallHookItem(){

    HOOK_LIB("libpvz.so", "0x5EE7C0", PlantStateMod, old_PlantState);//NotOnGround
    //HOOK_LIB("libpvz.so", "0x5EE924", PlantStateMod, old_PlantState);// GetDamageRangeFlags
    //HOOK_LIB("libpvz.so", "0x5F8644", PlantStateMod, old_PlantState);//UpdateShooting
    //HOOK_LIB("libpvz.so", "0x5F1960", PlantStateMod, old_PlantState);//植物状态----舍弃
    //HOOK_LIB("libpvz.so", "0x847950", ZombieTypeMod, old_ZombieType);//僵尸类型------舍弃
    HOOK_LIB("libpvz.so", "0x5091F8", ZombieTypeMod, old_ZombieType);//GetRake
    //HOOK_LIB("libpvz.so", "0x51616C", ZombieTypeMod, old_ZombieType);//PickRowForNewZombie
    HOOK_LIB("libpvz.so", "0x61227C", CoinMod, old_CoinNum);//金币数量
    HOOK_LIB("libpvz.so", "0x630928", IsSplashDamageMod, old_IsSplashDamage);//子弹是否溅射
    HOOK_LIB("libpvz.so", "0x54C444", GraveWarMod, old_GraveWar);//墓碑闪击战




}
#endif //PVZ_FREE_MENU_GAMEHOOK_H
