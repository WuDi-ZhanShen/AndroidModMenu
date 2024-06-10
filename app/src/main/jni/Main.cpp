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
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
//随机数
#include <ctime>
#include <cstdlib>
#include <random>


#define targetLibName OBFUSCATE("libpvz.so")

#include "Includes/Macros.h"

#include "GamePatch/GamePatch.h"
#include "KittyMemory/MemoryPatch.h"
#include "HookGame.h"
#include "ChangeFormation.h"


typedef unsigned long int DWORD;

//---------------------------------------------
void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    while (!isLibraryLoaded(targetLibName));


    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);

#if defined(__aarch64__)
    StepOnePatchGame();
    CallHookGame();


#else

#endif


    return NULL;
}


extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_android_support_CkHomuraMenu_GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_By-波奇酱"),

//----------------------------------------------------------------
            OBFUSCATE("Collapse_常用功能"),
            OBFUSCATE("1_CollapseAdd_Toggle_阳光反加"),
            OBFUSCATE("710_CollapseAdd_Toggle_去除阳光上限"),
            OBFUSCATE("4_CollapseAdd_Toggle_阳光自动收集"),
            OBFUSCATE("2_CollapseAdd_Toggle_无冷却"),
            OBFUSCATE("3_CollapseAdd_Toggle_自由种植"),
            OBFUSCATE("46_CollapseAdd_Toggle_紫卡不限(配合自由种植)"),
            OBFUSCATE("27_CollapseAdd_Toggle_无视僵尸进家"),
            OBFUSCATE("700_CollapseAdd_Toggle_蘑菇免唤醒"),
            OBFUSCATE("23_CollapseAdd_OnceCheckBox_过了这关"),



            //OBFUSCATE("666_Toggle_测试2"),


            OBFUSCATE("Collapse_快速布阵"),
            OBFUSCATE("52_CollapseAdd_OnceCheckBox_清空当前植物"),
            OBFUSCATE(
                    "53_CollapseAdd_Spinner_<font color='green'>泳池PE：_关闭,[0]电波钟无炮,[1]最简无炮,[2]伪无伤无炮,[3]自然控丑无炮,[4]火焰无炮,[5]分裂火焰无炮,[6]后退无炮,[7]超前置无炮,[8]王子无炮,[9]机械钟无炮,[10]神之无炮,[11]石英钟无炮,[12]靠天无炮,[13]方块无神无炮,[14]56加速无神无炮,[15]压制一炮,[16]小二炮,[17]火焰二炮,[18]核武二炮,[19]分裂二炮,[20]方正二炮,[21]经典二炮,[22]冲关三炮,[23]太极四炮,[24]全金属四炮,[25]方块四炮,[26]青四炮,[27]水路无植物四炮,[28]方四炮,[29]神之四炮,[30]双核底线四炮,[31]经典四炮,[32]火焰四炮,[33]底线四炮,[34]传统四炮,[35]半场无植物五炮,[36]散炸五炮,[37]心五炮,[38]陆路无植物六炮,[39]水路无植物六炮,[40]青苔六炮,[41]禅房花木深,[42]神之六炮,[43]玉米六炮,[44]空炸六炮,[45]超后置六炮,[46]方六炮,[47]蝶韵,[48]一勺汤圆,[49]间隔无植物七炮,[50]玉兔茕茕,[51]无保护八炮,[52]树八炮,[53]全对称树八炮,[54]矩形八炮,[55]神之八炮,[56]阴阳八炮,[57]浮萍八炮,[58]后置八炮,[59]饲养海豚,[60]玉米八炮,[61]经典八炮,[62]花海八炮,[63]C2八炮,[64]分离八炮,[65]全对称八炮,[66]3C八炮,[67]灯台八炮,[68]⑨炮,[69]方块九炮,[70]C6i九炮,[71]心九炮,[72]轮炸九炮,[73]②炮,[74]六芒星十炮,[75]六边形十炮,[76]方块十炮,[77]斜方十炮,[78]简化十炮,[79]后置十炮,[80]经典十炮,[81]六线囚尸,[82]斜十炮,[83]魔方十炮,[84]戴夫的小汉堡,[85]鸡尾酒,[86]一勺汤圆十二炮,[87]玉壶春十二炮,[88]半场十二炮,[89]简化十二炮,[90]经典十二炮,[91]火焰十二炮,[92]冰雨十二炮·改,[93]冰雨十二炮•改改,[94]单紫卡十二炮,[95]神柱十二炮,[96神之十二炮],[97]水路无植物十二炮,[98]纯白悬空十二炮,[99]后花园十二炮,[100]玉米十二炮,[101]两路暴狂,[102]九列十二炮,[103]梯曾十二炮,[104]君海十二炮,[105]箜篌引,[106]梅花十三,[107]最后之作,[108]冰心灯,[109]太极十四炮,[110]真·四炮,[111]神棍十四炮,[112]神之十四炮,[113]穿越十四炮,[114]钻石十五炮,[115]神之十五炮,[116]真·二炮,[117]冰箱灯,[118]炮环十二花,[119]单冰十六炮,[120]对称十六炮,[121]神之十六炮,[122]裸奔十六炮,[123]双冰十六炮,[124]超前置十六炮,[125]火焰十六炮,[126]经典十六炮,[127]折线十六炮,[128]肺十八炮(极限),[129]纯十八炮,[130]真·十八炮,[131]冰魄十八炮,[132]尾炸十八炮,[133]经典十八炮,[134]纯二十炮,[135]空炸二十炮,[136]钉耙二十炮,[137]新二十炮,[138]无冰瓜二十炮,[139]绝望之路,[140]二十一炮,[141]新二十二炮,[142]二十二炮,[143]无冰瓜二十二炮,[144]九列二十二炮,[145]二十四炮,[146]垫材二十四炮,[147]胆守(极限)"),
            OBFUSCATE("54_CollapseAdd_OnceCheckBox_布阵"),
            OBFUSCATE("CollapseAdd_RichTextView_<font color='yellow'>#别瞎点或多点此按钮"),
            OBFUSCATE("CollapseAdd_RichTextView_<font color='yellow'>#其他地图后来更新"),


            OBFUSCATE("Collapse_快速搭梯"),
            OBFUSCATE("61_CollapseAdd_Toggle_梯子南瓜"),
            OBFUSCATE("62_CollapseAdd_InputValue_X坐标"),
            OBFUSCATE("63_CollapseAdd_InputValue_Y坐标"),
            OBFUSCATE("64_CollapseAdd_OnceCheckBox_搭建"),

            OBFUSCATE("Collapse_植物&僵尸建造(测压)"),
            OBFUSCATE("CollapseAdd_RichTextView_<font color='yellow'>植物:--->"),
            OBFUSCATE(
                    "65_CollapseAdd_Spinner_<font color='green'>选择建造植物：_关闭,豌豆射手,向日葵,樱桃炸弹,坚果,土豆地雷,寒冰射手,食人花,双发射手,小喷菇,阳光菇,大喷菇,咬咬碑,迷惑菇,胆小菇,冰冻菇,毁灭菇,睡莲,窝瓜,三线射手,海藻,火爆辣椒,地刺,火炬树桩,高坚果,海蘑菇,灯笼草,仙人掌,三叶草,双向射手,杨桃,南瓜套,磁力菇,卷心菜,花盆,玉米投手,咖啡豆,大蒜,叶子保护伞,金盏花,西瓜投手,机枪射手,双子向日葵,忧郁蘑菇,猫尾草,冰冻西瓜,吸金瓷,地刺王,玉米加农炮,模仿者,爆炸坚果,巨型坚果,数苗,反向双发射手"),
            OBFUSCATE("66_CollapseAdd_InputValue_自定义种植ID"),
            OBFUSCATE("68_CollapseAdd_InputValue_X坐标"),
            OBFUSCATE("69_CollapseAdd_InputValue_Y坐标"),
            OBFUSCATE("67_CollapseAdd_OnceCheckBox_种植"),
            OBFUSCATE("CollapseAdd_RichTextView_<font color='yellow'>僵尸:--->"),
            OBFUSCATE(
                    "73_CollapseAdd_Spinner_<font color='green'>选择出现僵尸：_关闭,普通,旗帜,路障,撑杆,铁桶,读报,铁门,橄榄球,舞王,舞伴,游池普僵,潜水,冰车,雪橇,海豚,小丑,气球,矿工,蹦蹦,雪人,飞贼,梯子,篮球,巨人,小鬼,僵王,豌豆,坚果,辣椒,机枪,倭瓜,高坚果,红眼巨人"),
            OBFUSCATE("70_CollapseAdd_InputValue_出现数量"),
            OBFUSCATE("71_CollapseAdd_InputValue_出现行数"),
            OBFUSCATE("74_CollapseAdd_CheckBox_均匀放置"),
            OBFUSCATE("75_CollapseAdd_CheckBox_均匀放置(泳池)"),
            OBFUSCATE("72_CollapseAdd_OnceCheckBox_种植"),
            OBFUSCATE("CollapseAdd_RichTextView_<font color='yellow'>#可以暂停游戏多次使用"),
            OBFUSCATE("CollapseAdd_RichTextView_<font color='yellow'>#可用于针对测压"),

            OBFUSCATE("Collapse_子弹功能"),
            OBFUSCATE("50_CollapseAdd_Toggle_随机子弹"),
            OBFUSCATE(
                    "51_CollapseAdd_Spinner_<font color='green'>固定某种子弹：_关闭,豌豆,冰豌豆,卷心菜,西瓜,泡泡,冰西瓜,焰,星星,尖刺,只因球,玉米粒,玉米炮,黄油,自残子弹,僵尸子弹"),
            OBFUSCATE("55_CollapseAdd_CheckBox_仅对豌豆生效"),
            "84_CollapseAdd_CheckBox_禁加农炮子弹",
            "85_CollapseAdd_CheckBox_禁止杨桃生效",

            OBFUSCATE("1314_CheckBox_够用的金币"),


//----------------------------------------------------------------
    };

    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_android_support_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                             jint featNum, jstring featName, jint value,
                                             jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");

    //不要漏掉case下的break
//
    switch (featNum) {

        case 1:
            TakeSunButt = boolean;
            break;//阳光反加
        case 2:
            CoolDownSeedPacketButt = boolean;
            break;//冷却
        case 3:
            FreePlantAt = boolean;
            break;//自由种植
        case 4:
            AutoCollect = boolean;
            break;//自动收集
        case 27:
            ZombieCanNotWon = boolean;
            break;//无视僵尸进家
        case 46:
            PurpleCardNoLimit = boolean;
            break;
        case 700:
            FungusNoSleeping = boolean;
            break;
        case 710:
            NoSunLimit = boolean;
            break;//去除阳光上限
        case 23:
            PassNowLevel = boolean;
            break;//过了这关

        case 50:
            RandomBulletBUTT = boolean;
            break;//随机子弹
        case 51:
            BulletSpinnerChosenNum = value - 1;
            break;

        case 52:
            ClearAllPlant = boolean;
            break;
        case 53:
            GetedChangeFormationID(value - 1);
            break;
        case 54:
            FormationDecideButt = boolean;
            break;
        case 55:
            IsOnlyPeaUseableButt = boolean;
            break;

        case 61:
            PumpkinWithLadder = boolean;
            break;

        case 62:
            LadderX = value;
            break;
        case 63:
            LadderY = value;
            break;

        case 64:
            DoneLadderBuild = boolean;
            break;
        case 65:
            ThePlantID = value - 1;
            break;
        case 66:
            ThePlantID = value;
            break;
        case 67:
            DonePlantBuild = boolean;
            break;
        case 68:
            BuildPlantX = value;
            break;
        case 69:
            BuildPlantY = value;
            break;
        case 70:
            BuildZombieCount = value - 1;
            break;
        case 71:
            TheZombieBuildRow = value;
            break;
        case 72:
            DoneZombieBuild = boolean;
            Buildi = 0;
            break;
        case 73:
            TheZombieID = value - 1;
            break;
        case 74:
            UniformPlace = boolean;
            if (UniformPlace) {
                UniformPlacePool = 0;
            }
            break;
        case 75:
            UniformPlacePool = boolean;
            if (UniformPlacePool) {
                UniformPlace = 0;
            }
            break;
        case 84:
            BanCobCannonBullet = boolean;
            break;
        case 85:
            BanStar = boolean;
            break;

        case 1314:
            CoinModButt = boolean;
            break;

        default:;
            break;
    }
}



//Hook程序入口，会在加载Lib时自动开始运行
__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);

}


extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_android_support_CkHomuraMenu_SettingsList(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {

            OBFUSCATE("Category_设置"),
            OBFUSCATE("-1_Toggle_保存功能首选项"), //-1 is checked on Preferences.java
            OBFUSCATE("-6_Button_<font color='red'>退出设置</font>"),
    };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_android_support_CkHomuraMenu_Icon(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(
            OBFUSCATE(
                    "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"));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_android_support_CkHomuraMenu_Title(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("<b>PvZ-FREE</b>");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_android_support_CkHomuraMenu_SubTitle(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(R"(<b><marquee><p style="font-size:30"><p style="color:green;">PvZ</p> | PvZ-Mod</p> </marquee></b>)");
}