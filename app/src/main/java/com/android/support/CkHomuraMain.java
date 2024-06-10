package com.android.support;

import android.app.Activity;

public class CkHomuraMain {

    //Load lib
    static {
        // When you change the lib name, change also on Android.mk file
        // Both must have same name
        System.loadLibrary("Homura");
    }

    public static boolean hasStarted = false;

    public static void Start(Activity context) {
        if (!hasStarted) {
            hasStarted = true;
            if (context.getSharedPreferences("data", 0).getBoolean("useMenu", true)) {
                //Check if context is an Activity.
                CkHomuraMenu menu = new CkHomuraMenu(context);
                menu.SetWindowManagerActivity();
                menu.ShowMenu();
            }
        }
    }


}
