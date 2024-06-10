//
// Created by Homura on 2023/5/18.
//

#ifndef PVZ_TV_TOUCH_STEPONE_PATCH_H
#define PVZ_TV_TOUCH_STEPONE_PATCH_H

#define targetLibName "libpvz.so"

struct Game_Patches {
    MemoryPatch RemoveForce_Update;

} GamePatches;

bool IsPatched = false;
void StepOnePatchGame(){
    if (!IsPatched) {
        GamePatches.RemoveForce_Update = MemoryPatch::createWithHex(targetLibName,string2Offset("0x17283C6"),"00 00 00 00 00 00 00 00 00 00 00 00");
        GamePatches.RemoveForce_Update.Modify();

        IsPatched = true;
    }

}




#endif //PVZ_TV_TOUCH_STEPONE_PATCH_H
