package com.android.support;

import android.app.Activity;
import android.os.Bundle;


// 这是关于如何添加菜单悬浮窗的样例Activity
public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // 如果遇到菜单内的开关按钮样式非常古老，那么在OnCreate()函数的第一行加入下方的setTheme()语句，即可解决问题。
        setTheme(android.R.style.Theme_DeviceDefault_NoActionBar_Fullscreen);
        super.onCreate(savedInstanceState);


        // 也可以不改动OnCreate()函数，而是在AndroidManifest.xml中为Activity指定Theme。在Activity标签下方加入这样一行代码也能解决菜单按钮样式古老：
        // android:theme="@android:style/Theme.DeviceDefault.NoActionBar.Fullscreen"


        // 如果菜单按钮样式正常，则不需要改动OnCreate()函数或者AndroidManifest.xml。
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        CkHomuraMain.Start(this);        //在onWindowFocusChanged()函数中加入这一行代码，即可启动菜单Hook框架和菜单悬浮窗。
        super.onWindowFocusChanged(hasFocus);
    }
}
